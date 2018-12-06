#include "state/device/Connected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

using event::output::FacadeEvent;

Connected::Connected(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connected::start()
{
    return nullptr;
}

std::unique_ptr<IState> Connected::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Connected::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::string Connected::toString() const
{
    return "Connected";
}
