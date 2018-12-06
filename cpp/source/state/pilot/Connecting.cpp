#include "state/pilot/Connecting.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

using event::output::FacadeEvent;

Connecting::Connecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connecting::start()
{
    return nullptr;
}

std::unique_ptr<IState> Connecting::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Connecting::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::string Connecting::toString() const
{
    return "Connecting";
}
