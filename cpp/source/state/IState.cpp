#include "state/IState.hpp"

#include "IClient.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::event::input::user;
using namespace fm::event::input::connection;

using namespace com::fleetmgr::interfaces::facade::control;

IState::~IState()
{
}

std::unique_ptr<IState> IState::handleEvent(const std::shared_ptr<const event::input::IInputEvent> event)
{
    switch (event->getInputEventType())
    {
    case event::input::IInputEvent::USER_EVENT:
        return handleUserEvent(reinterpret_cast<const UserEvent&>(*(event.get())));

    case event::input::IInputEvent::CONNECTION_EVENT:
        return handleConnectionEvent(reinterpret_cast<const ConnectionEvent&>(*(event.get())));
    }
}

IState::IState(IState& state) :
    client(state.client),
    listener(state.listener),
    core(state.core)
{
}

IState::IState(IClient& _client, IClient::Listener& _listener, core::https::IHttpsClient& coreClient) :
    client(_client),
    listener(_listener),
    core(coreClient)
{
}

void IState::send(const ClientMessage& message)
{
    client.send(message);
}

std::unique_ptr<IState> IState::defaultEventHandle(const std::string& eventName)
{
    trace("Unexpected: " + eventName + " @ " + toString());
    return nullptr;
}

std::unique_ptr<IState> IState::defaultMessageHandle()
{
    trace("Unexpected ClientMessage: @ " + toString());
    return nullptr;
}

void IState::trace(const std::string& message)
{
    client.trace(message);
}
