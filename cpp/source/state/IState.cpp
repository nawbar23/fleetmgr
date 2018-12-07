#include "state/IState.hpp"

#include "IClient.hpp"

using namespace fm;
using namespace fm::state;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

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
    core(state.core),
    heartbeatHandler(state.heartbeatHandler)
{
}

IState::IState(IClient& _client, IClient::Listener& _listener, core::https::IHttpsClient& coreClient) :
    client(_client),
    listener(_listener),
    core(coreClient),
    heartbeatHandler(_client)
{
}

std::unique_ptr<IState> IState::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> IState::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
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

std::unique_ptr<IState> IState::defaultMessageHandle(const ControlMessage& message)
{
    if (message.command() == Command::HEARTBEAT && message.has_heartbeat())
    {
        heartbeatHandler.handleHeartbeat(message);
    }
    else
    {
        trace("Unexpected ControlMessage received:\n" + message + " @ " + toString());
    }
    return nullptr;
}

void IState::trace(const std::string& message)
{
    client.trace(message);
}
