#include "state/pilot/Connected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

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
    return onNewState(internalState->handleUserEvent(event));
}

std::unique_ptr<IState> Connected::handleConnectionEvent(const ConnectionEvent& event)
{
    return onNewState(internalState->handleConnectionEvent(event));
}

std::unique_ptr<IState> Connected::onNewState(std::unique_ptr<IState> newState)
{
    while (nullptr != newState.get())
    {
        listener.trace("Connected transition: " + internalState->toString() + " -> " + newState->toString());
        internalState.swap(newState);
        newState.reset(internalState->start().release());
    }
    return internalState->createOuterState();
}

std::string Connected::toString() const
{
    return "Connected::" + internalState->toString();
}
