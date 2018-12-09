#include "event/output/OperationStarted.hpp"

using namespace fm;
using namespace fm::event::output;

OperationStarted::OperationStarted() :
    FacadeEvent(OPERATION_STARTED)
{
}

std::string OperationStarted::toString() const
{
    return "OPERATION_STARTED: ";
}
