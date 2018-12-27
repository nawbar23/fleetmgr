#include "event/output/OperationStarted.hpp"

using namespace fm;
using namespace fm::event::output;

OperationStarted::OperationStarted(com::fleetmgr::interfaces::Role _role) :
    FacadeEvent(OPERATION_STARTED),
    role(_role)
{
}

com::fleetmgr::interfaces::Role OperationStarted::getRole() const
{
    return role;
}

std::string OperationStarted::toString() const
{
    return "OPERATION_STARTED: " + com::fleetmgr::interfaces::Role_Name(role);
}
