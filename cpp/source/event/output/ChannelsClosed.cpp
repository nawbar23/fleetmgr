#include "event/output/ChannelsClosed.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::output;

ChannelsClosed::ChannelsClosed(std::shared_ptr<std::vector<long>> _channels) :
    FacadeEvent(CHANNELS_CLOSED),
    channels(_channels)
{
}

const std::vector<long>& ChannelsClosed::getChannels() const
{
    return *channels;
}

std::string ChannelsClosed::toString() const
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
    return "CHANNELS_CLOSED: " + oss.str();
}
