#include "IClient.hpp"

#include "event/input/connection/Received.hpp"

#include "state/IState.hpp"

#include <memory>
#include <fstream>
#include <sstream>

using namespace fm;

using namespace com::fleetmgr::interfaces::facade::control;

IClient::Listener::~Listener()
{
}

IClient::~IClient()
{
}

void IClient::notifyEvent(const std::shared_ptr<const event::input::IInputEvent> event)
{
    std::lock_guard<std::mutex> lockGuard(stateLock);
    listener.trace("Handling: " + event->toString() + " @ " + state->toString());
    std::unique_ptr<state::IState> newState = state->handleEvent(event);
    while (nullptr != newState.get())
    {
        listener.trace("Transition: " + state->toString() + " -> " + newState->toString());
        state.swap(newState);
        newState.reset(state->start().release());
    }
}

void IClient::openFacadeConnection(const std::string& host, const int port)
{
    trace("Opening facade channel at: " + host + ":" + std::to_string(port));

    std::string address = host + ":" + std::to_string(port);

    std::string cert;
    readCert(certPath, cert);

    grpc::SslCredentialsOptions sslOpts;
    sslOpts.pem_root_certs = cert;

    grpc::ChannelArguments args;
    args.SetSslTargetNameOverride("localhost");

    std::shared_ptr<grpc::ChannelCredentials> creds = grpc::SslCredentials(sslOpts);

    channel = grpc::CreateCustomChannel(address, creds, args);
    stub = FacadeService::NewStub(channel);

    // TODO Bartek maybe it should be done with ClientAsyncReaderWriter
    stream = stub->control(&context);

    keepReader.store(true);
    reader = std::thread([this] ()
    {
        while (keepReader.load())
        {
            std::shared_ptr<ControlMessage> controlMessage = std::make_shared<ControlMessage>();
            while (stream->Read(controlMessage.get()))
            {
                using event::input::connection::Received;
                notifyEvent(std::make_shared<Received>(controlMessage));
            }
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    });
}

void IClient::closeFacadeConnection()
{
    keepReader.store(false);
    grpc::Status status = stream->Finish();
    if (not status.ok())
    {
        throw std::runtime_error("Error!, could not close stream");
    }
    reader.join();
}

void IClient::send(const ClientMessage& message)
{
    trace("Sending:\n" + message.DebugString() + " @ " + state->toString());
    if (not stream->Write(message))
    {
        throw std::runtime_error("Error!, could not send message");
    }
}

void IClient::trace(const std::string& message)
{
    listener.trace(message);
}

IClient::IClient(std::unique_ptr<state::IState> initialState, Listener& _listener, const std::string& _certPath) :
    listener(_listener),
    state(initialState.release()),
    channel(nullptr),
    stub(nullptr),
    stream(nullptr),
    keepReader(false),
    certPath(_certPath)
{
}

void IClient::readCert(const std::string& filename, std::string& data)
{
    std::ifstream file (filename.c_str(), std::ios::in);
    if (file.is_open())
    {
        std::stringstream ss;
        ss << file.rdbuf();
        file.close();
        data = ss.str();
    }
}
