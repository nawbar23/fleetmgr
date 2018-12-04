#include "state/pilot/Disconnecting.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::UserEvent;

Disconnecting::Disconnecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Disconnecting::start()
{
    return nullptr;
}

std::unique_ptr<IState> Disconnecting::handleEvent(const std::shared_ptr<const UserEvent> event)
{
    return defaultEventHandle(event->toString());
}

std::string Disconnecting::toString() const
{
    return "Disconnecting";
}
