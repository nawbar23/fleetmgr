#include "event/output/HandoverRejected.hpp"

using namespace fm;
using namespace fm::event::output;

HandoverRejected::HandoverRejected(const std::string& _message) :
    FacadeEvent(HANDOVER_REJECTED),
    message(_message)
{
}

const std::string& HandoverRejected::getMessage() const
{
    return message;
}

std::string HandoverRejected::toString() const
{
    return "HANDOVER_REJECTED: " + message;
}
