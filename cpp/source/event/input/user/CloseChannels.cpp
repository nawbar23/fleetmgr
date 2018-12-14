#include "event/input/user/CloseChannels.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

CloseChannels::CloseChannels() :
    UserEvent(CLOSE_CHANNELS)
{
}

CloseChannels::CloseChannels(const std::vector<long>& _channels) :
    UserEvent(CLOSE_CHANNELS),
    channels(_channels)
{
}

std::string CloseChannels::toString() const
{
    std::ostringstream oss;
    if (!channels.empty())
    {
        std::copy(channels.begin(), channels.end()-1,
                  std::ostream_iterator<long>(oss, ","));
        oss << channels.back();
    }
    return "CLOSE_CHANNELS: channels: " + oss.str();
}

std::vector<long>& CloseChannels::getChannels()
{
    return channels;
}

const std::vector<long>& CloseChannels::getChannels() const
{
    return channels;
}
