#include "state/device/Disconnecting.hpp"

#include "state/device/Disconnected.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

Disconnecting::Disconnecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Disconnecting::start()
{
    backend.getHeartbeatHandler().end();
    backend.closeFacadeConnection();
    listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::RELEASED));
    return std::make_unique<Disconnected>(*this);
}

std::unique_ptr<IState> Disconnecting::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Disconnecting::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::string Disconnecting::toString() const
{
    return "Disconnecting";
}
