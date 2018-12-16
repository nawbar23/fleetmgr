#include "event/input/user/OpenChannels.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

OpenChannels::OpenChannels(std::shared_ptr<std::vector<long>> _channels) :
    UserEvent(OPEN_CHANNELS),
    channels(_channels)
{
}

const std::vector<long>& OpenChannels::getChannels() const
{
    return *channels;
}

std::string OpenChannels::toString() const
{
    std::ostringstream oss;
    oss << "[";
    if (!channels->empty())
    {
        std::copy(channels->begin(), channels->end()-1,
                  std::ostream_iterator<long>(oss, ","));
        oss << channels->back();
    }
    oss << "]";
    return "OPEN_CHANNELS: channels: " + oss.str();
}
