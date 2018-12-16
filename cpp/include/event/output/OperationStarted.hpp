#ifndef FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP
#define FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP

#include "event/output/FacadeEvent.hpp"

#include "common/role.pb.h"

namespace fm
{

namespace event
{

namespace output
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-09
 * Description:
 */
class OperationStarted : public FacadeEvent
{
public:
    OperationStarted(com::fleetmgr::interfaces::Role);

    com::fleetmgr::interfaces::Role getRole() const;

    std::string toString() const;

private:
    com::fleetmgr::interfaces::Role role;
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP
