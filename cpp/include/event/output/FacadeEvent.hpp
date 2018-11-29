#ifndef FM_EVENT_OUTPUT_FACADEEVENT_HPP
#define FM_EVENT_OUTPUT_FACADEEVENT_HPP

#include <string>

namespace fm
{

namespace event
{

namespace output
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class FacadeEvent
{
public:
    enum Type
    {
        ATTACHED,
        RELEASED,
        ERROR,
        MESSAGE,
        CHANNELS_OPENED,
        OPERATION_STARTED,
        HANDOVER_ACCEPTED,
        REQUEST_CONTROL,
        RELEASE_CONTROL,
        HANDOVER_REJECTED,
        HANDOVER_DONE,
        CONTROL_RELEASED,
        CHANNELS_CLOSED,
        OPERATION_ENDED,
        CONNECTION_LOST,
        CONNECTION_RECOVERED,
        DEVICE_UNREACHABLE,
        LEADER_UNREACHABLE,
        DEVICE_RECOVERED,
    };

    FacadeEvent(Type);

    virtual ~FacadeEvent();

    Type getType() const;

    virtual std::string toString() const;

private:
    Type type;
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_FACADEEVENT_HPP
