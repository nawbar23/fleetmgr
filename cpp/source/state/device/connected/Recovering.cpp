#include "state/device/connected/Recovering.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;
using namespace fm::state::device::connected;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

Recovering::Recovering(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Recovering::start()
{
    return nullptr;
}

std::string Recovering::toString() const
{
    return "Recovering";
}

std::unique_ptr<IState> Recovering::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Recovering::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Recovering::handleMessage(const ControlMessage& message)
{
    return defaultMessageHandle(message);
}
