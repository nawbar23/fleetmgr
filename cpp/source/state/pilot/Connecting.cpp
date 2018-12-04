#include "state/pilot/Connecting.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::UserEvent;

Connecting::Connecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connecting::start()
{
    return nullptr;
}

std::unique_ptr<IState> Connecting::handleEvent(const std::shared_ptr<const UserEvent> event)
{
    return defaultEventHandle(event->toString());
}

std::string Connecting::toString() const
{
    return "Connecting";
}
