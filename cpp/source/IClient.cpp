#include "IClient.hpp"

#include "state/IState.hpp"

#include <memory>

using namespace fm;

using namespace com::fleetmgr::interfaces::facade::control;

IClient::Listener::~Listener()
{
}

IClient::~IClient()
{
}

void IClient::notifyEvent(const std::shared_ptr<const event::input::UserEvent> event)
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

}

//void IClient::start()
//{
//    using grpc::Channel;
//    using com::fleetmgr::interfaces::facade::control::FacadeService;
//    std::shared_ptr<Channel> channel(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
//    std::unique_ptr<FacadeService::Stub> stub(FacadeService::NewStub(channel));
//}

void IClient::send(const ClientMessage& message)
{
    trace("Sending: " + message.DebugString() + " @ " + state->toString());
    // TODO send message to Facade over gRPC
}

void IClient::trace(const std::string& message)
{
    listener.trace(message);
}

IClient::IClient(std::unique_ptr<state::IState> initialState, Listener& _listener) :
    listener(_listener),
    state(initialState.release())
{
}
