#ifndef FM_EVENT_OUTPUT_HANDOVERREJECTED_HPP
#define FM_EVENT_OUTPUT_HANDOVERREJECTED_HPP

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
class HandoverRejected : public FacadeEvent
{
public:
    HandoverRejected();

    std::string toString() const;

private:
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_HANDOVERREJECTED_HPP
