#include "state/device/connected/Released.hpp"

#include "state/device/Disconnecting.hpp"

#include "event/input/connection/Received.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;
using namespace fm::state::device::connected;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using namespace event::input::user;
using namespace event::input::connection;
using namespace event::output;

Released::Released(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Released::start()
{
    return nullptr;
}

std::string Released::toString() const
{
    return "Released";
}

std::unique_ptr<IState> Released::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Released::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Released::createOuterState()
{
    return std::make_unique<Disconnecting>(*this);
}

std::unique_ptr<IState> Released::handleMessage(const ControlMessage& message)
{
    return defaultMessageHandle(message);
}
