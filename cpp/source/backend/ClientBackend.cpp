#include "backend/ClientBackend.hpp"

#include "IClient.hpp"

#include "event/input/connection/Received.hpp"

#include <fstream>
#include <sstream>

using namespace fm;
using namespace fm::backend;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

ClientBackend::ClientBackend(IClient& _client, IClient::Listener& _listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    client(_client),
    listener(_listener),
    core(coreClient),
    heartbeatHandler(*this),
    channel(nullptr),
    stub(nullptr),
    stream(nullptr),
    keepReader(false),
    certPath(_certPath)
{
}

core::CoreClient& ClientBackend::getCore()
{
    return core;
}

HeartbeatHandler& ClientBackend::getHeartbeatHandler()
{
   return heartbeatHandler;
}

std::unique_ptr<Location> ClientBackend::getLocation()
{
    return listener.getLocation();
}

void ClientBackend::openFacadeConnection(const std::string& host, const int port)
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
                client.notifyEvent(std::make_shared<Received>(controlMessage));
            }
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    });
}

void ClientBackend::closeFacadeConnection()
{
    keepReader.store(false);
    grpc::Status status = stream->Finish();
    if (not status.ok())
    {
        throw std::runtime_error("Error!, could not close stream");
    }
    reader.join();
}

void ClientBackend::send(const ClientMessage& message)
{
    trace("Sending:\n" + message.DebugString() + " @ " + client.getStateName());
    if (not stream->Write(message))
    {
        throw std::runtime_error("Error!, could not send message");
    }
}

void ClientBackend::trace(const std::string& message)
{
    listener.trace(message);
}

void ClientBackend::readCert(const std::string& filename, std::string& data)
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
