#include "event/output/ChannelsOpened.hpp"

using namespace fm;
using namespace fm::event::output;

ChannelsOpened::ChannelsOpened() :
    FacadeEvent(CHANNELS_OPENED)
{
}

std::string ChannelsOpened::toString() const
{
    return "CHANNELS_OPENED: ";
}
