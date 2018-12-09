#include "state/pilot/connected/ValidatingChannels.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

ValidatingChannels::ValidatingChannels(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> ValidatingChannels::start()
{
    return nullptr;
}

std::string ValidatingChannels::toString() const
{
    return "ValidatingChannels";
}

std::unique_ptr<IState> ValidatingChannels::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> ValidatingChannels::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> ValidatingChannels::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    default:
        return defaultMessageHandle(message);
    }
}
