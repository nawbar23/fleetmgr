#include "event/input/user/OpenChannels.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::input::user;

using namespace com::fleetmgr::interfaces;

OpenChannels::OpenChannels(std::shared_ptr<std::vector<std::shared_ptr<ChannelRequest>>> _channels) :
    UserEvent(OPEN_CHANNELS),
    channels(_channels)
{
}

const std::vector<std::shared_ptr<ChannelRequest>>& OpenChannels::getChannels() const
{
    return *channels;
}

std::string OpenChannels::toString() const
{
    std::ostringstream oss;
    oss << "[";
    for (std::shared_ptr<ChannelRequest> c : *channels)
    {
        oss << c->id() << ",";
    }
    oss << "]";
    return "OPEN_CHANNELS: channels: " + oss.str();
}
