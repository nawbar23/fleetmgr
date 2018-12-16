#include "event/input/user/Operate.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

Operate::Operate(long _deviceId, std::shared_ptr<std::vector<long>> _channels) :
    UserEvent(OPERATE),
    deviceId(_deviceId),
    channels(_channels)
{
}

long Operate::getDeviceId() const
{
    return deviceId;
}

const std::vector<long>& Operate::getChannels() const
{
    return *channels;
}

std::string Operate::toString() const
{
    std::ostringstream oss;
    if (!channels->empty())
    {
        std::copy(channels->begin(), channels->end()-1,
                  std::ostream_iterator<long>(oss, ","));
        oss << channels->back();
    }
    return "OPERATE: " + std::to_string(deviceId) + " channels: " + oss.str();
}
