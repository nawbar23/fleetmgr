#ifndef FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP
#define FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP

#include "event/output/FacadeEvent.hpp"

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
    OperationStarted();

    std::string toString() const;

private:
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_OPERATIONSTARTED_HPP
