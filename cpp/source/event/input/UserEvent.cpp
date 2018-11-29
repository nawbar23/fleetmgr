#include "event/input/UserEvent.hpp"

using namespace fm;
using namespace fm::event::input;

UserEvent::UserEvent(Type _type) :
    type(_type)
{
}

UserEvent::~UserEvent()
{
}

UserEvent::Type UserEvent::getType() const
{
    return type;
}

std::string UserEvent::toString() const
{
    switch (type)
    {
    case ATTACH: return "ATTACH";
    case RELEASE: return "RELEASE";
    case OPERATE: return "OPERATE";
    case REQUEST_CONTROL: return "REQUEST_CONTROL";
    case RELEASE_ACCEPTED: return "RELEASE_ACCEPTED";
    case REJECT_HANDOVER: return "REJECT_HANDOVER";
    case CONTROL_READY: return "CONTROL_READY";
    case OPEN_CHANNELS: return "OPEN_CHANNELS";
    case CLOSE_CHANNELS: return "CLOSE_CHANNELS";

    default:
        return "Unexpected UserEvent::Type";
    }
}
