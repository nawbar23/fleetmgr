#include "state/device/Connected.hpp"

#include "state/device/connected/Ready.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

using event::output::FacadeEvent;

Connected::Connected(IState& state) :
    IState(state),
    internalState(std::make_unique<connected::Ready>(*this))
{
}

std::unique_ptr<IState> Connected::start()
{
    heartbeatHandler.start();
    internalState->start();
    listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::ATTACHED));
    return nullptr;
}

std::string Connected::toString() const
{
    return "Connected::" + internalState->toString();
}

std::unique_ptr<IState> Connected::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Connected::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
}
