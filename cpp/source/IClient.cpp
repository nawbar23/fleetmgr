#include "IClient.hpp"

using namespace fm;

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
}

IClient::IClient(std::unique_ptr<state::IState> initialState, Listener& _listener, core::https::IHttpsClient& coreClient) :
    listener(_listener),
    coreClient(coreClient),
    state(initialState.release())
{
}
