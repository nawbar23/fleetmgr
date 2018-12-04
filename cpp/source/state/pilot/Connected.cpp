#include "state/pilot/Connected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::UserEvent;

Connected::Connected(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connected::start()
{
    return nullptr;
}

std::unique_ptr<IState> Connected::handleEvent(const std::shared_ptr<const UserEvent> event)
{
    return defaultEventHandle(event->toString());
}

std::string Connected::toString() const
{
    return "Connected";
}
