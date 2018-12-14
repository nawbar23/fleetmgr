#include "event/input/user/OpenChannels.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

OpenChannels::OpenChannels() :
    UserEvent(OPEN_CHANNELS)
{
}

OpenChannels::OpenChannels(const std::vector<long>& _channels) :
    UserEvent(OPEN_CHANNELS),
    channels(_channels)
{
}

std::string OpenChannels::toString() const
{
    std::ostringstream oss;
    if (!channels.empty())
    {
        std::copy(channels.begin(), channels.end()-1,
                  std::ostream_iterator<long>(oss, ","));
        oss << channels.back();
    }
    return "OPEN_CHANNELS: channels: " + oss.str();
}

std::vector<long>& OpenChannels::getChannels()
{
    return channels;
}

const std::vector<long>& OpenChannels::getChannels() const
{
    return channels;
}
