#include "event/output/OperationEnded.hpp"

using namespace fm;
using namespace fm::event::output;

OperationEnded::OperationEnded() :
    FacadeEvent(OPERATION_ENDED)
{
}

std::string OperationEnded::toString() const
{
    return "OPERATION_ENDED: ";
}
