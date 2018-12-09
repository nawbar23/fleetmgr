#include "event/input/user/Operate.hpp"

using namespace fm;
using namespace fm::event::input::user;

Operate::Operate(long _deviceId) :
    UserEvent(OPERATE),
    deviceId(_deviceId)
{
}

std::string Operate::toString() const
{
    return "OPERATE: " + std::to_string(deviceId);
}

long Operate::getDeviceId() const
{
    return deviceId;
}
