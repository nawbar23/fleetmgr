#include "state/pilot/Connected.hpp"

#include "state/pilot/connected/ValidatingChannels.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

Connected::Connected(IState& state, const std::vector<ChannelResponse>& openedChannels) :
    IState(state),
    internalState(std::make_unique<connected::ValidatingChannels>(*this, openedChannels))
{
}

std::unique_ptr<IState> Connected::start()
{
    backend.getHeartbeatHandler().start();
    internalState->start();
    listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::OPERATION_STARTED));
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
