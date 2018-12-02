#include "IClient.hpp"

#include "facade/control/facade_service.grpc.pb.h"

#include <grpc++/grpc++.h>

#include <memory>

using namespace fm;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

IClient::Listener::~Listener()
{
}

IClient::~IClient()
{
}

void IClient::notifyEvent(std::shared_ptr<const event::input::UserEvent> event)
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

void IClient::start()
{
    using grpc::Channel;
    using com::fleetmgr::interfaces::facade::control::FacadeService;
    std::shared_ptr<Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<FacadeService::Stub> stub(FacadeService::NewStub(channel));
}

IClient::IClient(std::unique_ptr<state::IState> initialState, Listener& _listener, core::https::IHttpsClient& coreClient) :
    listener(_listener),
    coreClient(coreClient),
    state(initialState.release())
{
}
