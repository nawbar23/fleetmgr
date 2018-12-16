#include "state/pilot/Connected.hpp"

#include "state/pilot/connected/ValidatingChannels.hpp"

#include "event/output/OperationStarted.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

using event::output::FacadeEvent;
using event::output::OperationStarted;

using com::fleetmgr::interfaces::Role;
using com::fleetmgr::interfaces::Channel;

Connected::Connected(IState& state, Role _initialRole, std::shared_ptr<std::vector<Channel>> openedChannels) :
    IState(state),
    internalState(std::make_unique<connected::ValidatingChannels>(*this, _initialRole, openedChannels)),
    initialRole(_initialRole)
{
}

std::unique_ptr<IState> Connected::start()
{
    backend.getHeartbeatHandler().start();
    internalState->start();
    listener.onEvent(std::make_shared<OperationStarted>(initialRole));
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
