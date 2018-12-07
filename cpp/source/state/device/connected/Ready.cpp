#include "state/device/connected/Ready.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;
using namespace fm::state::device::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

Ready::Ready(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Ready::start()
{
    return nullptr;
}

std::string Ready::toString() const
{
    return "Ready";
}

std::unique_ptr<IState> Ready::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Ready::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Ready::handleMessage(const ControlMessage& message)
{
    return defaultMessageHandle(message);
}
