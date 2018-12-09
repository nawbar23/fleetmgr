#include "event/output/ChannelsClosed.hpp"

using namespace fm;
using namespace fm::event::output;

ChannelsClosed::ChannelsClosed() :
    FacadeEvent(CHANNELS_CLOSED)
{
}

std::string ChannelsClosed::toString() const
{
    return "CHANNELS_CLOSED: ";
}
