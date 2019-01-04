#include "event/output/HandoverAccepted.hpp"

using namespace fm;
using namespace fm::event::output;

HandoverAccepted::HandoverAccepted(const std::string& _data) :
    FacadeEvent(HANDOVER_ACCEPTED),
    data()
{
}

const std::vector<uint8_t>& HandoverAccepted::getData() const
{
    return data;
}

std::string HandoverAccepted::toString() const
{
    return "HANDOVER_ACCEPTED: data size: " + data.size();
}
