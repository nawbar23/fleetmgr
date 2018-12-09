#include "event/output/HandoverAccepted.hpp"

using namespace fm;
using namespace fm::event::output;

HandoverAccepted::HandoverAccepted() :
    FacadeEvent(HANDOVER_ACCEPTED)
{
}

std::string HandoverAccepted::toString() const
{
    return "HANDOVER_ACCEPTED: ";
}
