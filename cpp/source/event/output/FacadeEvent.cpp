#include "event/output/FacadeEvent.hpp"

using namespace fm;
using namespace fm::event::output;

FacadeEvent::FacadeEvent(Type _type) :
    type(_type)
{
}

FacadeEvent::~FacadeEvent()
{
}

FacadeEvent::Type FacadeEvent::getType() const
{
    return type;
}

std::string FacadeEvent::toString() const
{
    switch (type)
    {
    case ATTACHED: return "ATTACHED";
    case RELEASED: return "RELEASED";
    case ERROR: return "ERROR";
    case MESSAGE: return "MESSAGE";
    case CHANNELS_OPENED: return "CHANNELS_OPENED";
    case OPERATION_STARTED: return "OPERATION_STARTED";
    case HANDOVER_ACCEPTED: return "HANDOVER_ACCEPTED";
    case REQUEST_CONTROL: return "REQUEST_CONTROL";
    case RELEASE_CONTROL: return "RELEASE_CONTROL";
    case HANDOVER_REJECTED: return "HANDOVER_REJECTED";
    case HANDOVER_DONE: return "HANDOVER_DONE";
    case CONTROL_RELEASED: return "CONTROL_RELEASED";
    case CHANNELS_CLOSED: return "CHANNELS_CLOSED";
    case OPERATION_ENDED: return "OPERATION_ENDED";
    case CONNECTION_LOST: return "CONNECTION_LOST";
    case CONNECTION_RECOVERED: return "CONNECTION_RECOVERED";
    case DEVICE_UNREACHABLE: return "DEVICE_UNREACHABLE";
    case LEADER_UNREACHABLE: return "LEADER_UNREACHABLE";
    case DEVICE_RECOVERED: return "DEVICE_RECOVERED";

    default:
        return "Unexpected UserEvent::Type";
    }
}
