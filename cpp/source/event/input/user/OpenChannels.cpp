#include "event/input/user/OpenChannels.hpp"

using namespace fm;
using namespace fm::event::input::user;

OpenChannels::OpenChannels() :
    UserEvent(OPEN_CHANNELS)
{
}

std::string OpenChannels::toString() const
{
    return "OPEN_CHANNELS: ";
}
