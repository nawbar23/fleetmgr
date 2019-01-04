#include "state/pilot/connected/ReleasingControl.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

ReleasingControl::ReleasingControl(IState& state, long _channelId) :
    IState(state),
    channelId(_channelId)
{
}

IState::State ReleasingControl::start()
{
    return nullptr;
}

IState::State ReleasingControl::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

IState::State ReleasingControl::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::string ReleasingControl::toString() const
{
    return "ReleasingControl";
}

IState::State ReleasingControl::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    default:
        return defaultMessageHandle(message);
    }
}
