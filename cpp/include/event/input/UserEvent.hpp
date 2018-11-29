#ifndef FM_EVENT_INPUT_USEREVENT_HPP
#define FM_EVENT_INPUT_USEREVENT_HPP

#include <string>

namespace fm
{

namespace event
{

namespace input
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class UserEvent
{
public:
    enum Type
    {
        ATTACH,
        RELEASE,
        OPERATE,
        REQUEST_CONTROL,
        RELEASE_ACCEPTED,
        REJECT_HANDOVER,
        CONTROL_READY,
        OPEN_CHANNELS,
        CLOSE_CHANNELS,
    };

    UserEvent(Type);

    virtual ~UserEvent();

    Type getType() const;

    virtual std::string toString() const;

private:
    Type type;
};

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USEREVENT_HPP
