#include "IClient.hpp"

#include "event/input/connection/Received.hpp"

#include "state/IState.hpp"
#include "backend/ClientBackend.hpp"

#include <memory>
#include <fstream>
#include <sstream>

using namespace fm;

IClient::Listener::~Listener()
{
}

IClient::~IClient()
{
}

void IClient::notifyEvent(const std::shared_ptr<const event::input::IInputEvent> event)
{
    listener.execute([this, event] ()
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
    });
}

std::string IClient::getStateName() const
{
    return state->toString();
}

IClient::IClient(Listener& _listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    backend(std::make_unique<backend::ClientBackend>(*this, _listener, coreClient, _certPath)),
    listener(_listener)
{
}

void IClient::setState(std::unique_ptr<state::IState> _state)
{
    state.swap(_state);
    state->start();
}
