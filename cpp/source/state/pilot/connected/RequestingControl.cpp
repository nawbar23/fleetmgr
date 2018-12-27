#include "state/pilot/connected/RequestingControl.hpp"

#include "event/input/connection/Received.hpp"

#include "event/output/ProcedureRejected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

RequestingControl::RequestingControl(IState& state, long _channelId) :
    IState(state),
    channelId(_channelId)
{
}

std::unique_ptr<IState> RequestingControl::start()
{
    return nullptr;
}

std::string RequestingControl::toString() const
{
    return "RequestingControl";
}

std::unique_ptr<IState> RequestingControl::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> RequestingControl::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> RequestingControl::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    default:
        return defaultMessageHandle(message);
    }
}
