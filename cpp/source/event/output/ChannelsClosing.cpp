#include "event/output/ChannelsClosing.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::output;

ChannelsClosing::ChannelsClosing(std::shared_ptr<std::vector<traffic::IChannel*>> _channels) :
    FacadeEvent(CHANNELS_CLOSING),
    channels(_channels)
{
}

std::shared_ptr<std::vector<traffic::IChannel*>> ChannelsClosing::getChannels() const
{
    return channels;
}

std::string ChannelsClosing::toString() const
{
    std::ostringstream oss;
    oss << "[";
    for (auto c : *channels)
    {
        oss << c->getId() << ",";
    }
    oss << "]";
    return "CHANNELS_CLOSING: " + oss.str();
}
