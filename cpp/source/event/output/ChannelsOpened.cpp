#include "event/output/ChannelsOpened.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::output;

ChannelsOpened::ChannelsOpened(std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>> _channels) :
    FacadeEvent(CHANNELS_OPENED),
    channels(_channels)
{
}

const std::vector<std::shared_ptr<traffic::Channel>>& ChannelsOpened::getChannels() const
{
    return *channels;
}

std::string ChannelsOpened::toString() const
{
    std::ostringstream oss;
    oss << "[";
    for (std::shared_ptr<traffic::Channel> c : *channels)
    {
        oss << c->getId() << ",";
    }
    oss << "]";
    return "CHANNELS_OPENED: " + oss.str();
}
