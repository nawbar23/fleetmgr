#include "state/device/connected/Flying.hpp"

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

Flying::Flying(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Flying::start()
{
    return nullptr;
}

std::string Flying::toString() const
{
    return "Flying";
}

std::unique_ptr<IState> Flying::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Flying::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Flying::handleMessage(const ControlMessage& message)
{
    return defaultMessageHandle(message);
}
