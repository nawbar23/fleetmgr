#include "event/input/user/Operate.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

using namespace com::fleetmgr::interfaces;

Operate::Operate(long _deviceId, std::shared_ptr<std::vector<std::shared_ptr<ChannelRequest>>> _channels) :
    UserEvent(OPERATE),
    deviceId(_deviceId),
    channels(_channels)
{
}

long Operate::getDeviceId() const
{
    return deviceId;
}

const std::vector<std::shared_ptr<ChannelRequest>>& Operate::getChannels() const
{
    return *channels;
}

std::string Operate::toString() const
{
    std::ostringstream oss;
    for (std::shared_ptr<ChannelRequest> c : *channels)
    {
        oss << c->id() << ",";
    }
    return "OPERATE: " + std::to_string(deviceId) + " channels: " + oss.str();
}
