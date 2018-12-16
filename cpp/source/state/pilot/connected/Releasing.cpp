#include "state/pilot/connected/Releasing.hpp"

#include <state/pilot/connected/Released.hpp>

#include "event/input/connection/Received.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

Releasing::Releasing(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Releasing::start()
{
    backend.getChannelsHandler().closeAllChannels();
    ClientMessage message;
    message.set_command(Command::RELEASE);
    send(message);
    return nullptr;
}

std::string Releasing::toString() const
{
    return "Releasing";
}

std::unique_ptr<IState> Releasing::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Releasing::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Releasing::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::RELEASE:
        if (message.response() == Response::ACCEPTED)
        {
            return std::make_unique<Released>(*this);
        }
        else
        {
            return defaultMessageHandle(message);
        }
        break;

    default:
        return defaultMessageHandle(message);
    }
}
