#include "event/input/user/CloseChannels.hpp"

using namespace fm;
using namespace fm::event::input::user;

CloseChannels::CloseChannels() :
    UserEvent(CLOSE_CHANNELS)
{
}

std::string CloseChannels::toString() const
{
    return "CLOSE_CHANNELS: ";
}
