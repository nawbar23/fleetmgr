#include "state/pilot/Connecting.hpp"

#include "state/pilot/Disconnected.hpp"
#include "state/pilot/Connected.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

Connecting::Connecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connecting::start()
{
    return nullptr;
}

std::string Connecting::toString() const
{
    return "Connecting";
}

std::unique_ptr<IState> Connecting::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Connecting::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Connecting::handleMessage(const ControlMessage& message)
{
    if (message.command() == Command::SETUP &&
            message.response() == Response::ACCEPTED)
    {
        return std::make_unique<Connected>(*this);
    }
    else
    {
        client.closeFacadeConnection();
        listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::ERROR));
        return std::make_unique<Disconnected>(*this);
    }
}
