#include "event/output/HandoverRejected.hpp"

using namespace fm;
using namespace fm::event::output;

HandoverRejected::HandoverRejected() :
    FacadeEvent(HANDOVER_REJECTED)
{
}

std::string HandoverRejected::toString() const
{
    return "HANDOVER_REJECTED: ";
}
