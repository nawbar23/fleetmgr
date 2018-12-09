#ifndef FM_EVENT_INPUT_USER_OPERATE_HPP
#define FM_EVENT_INPUT_USER_OPERATE_HPP

#include "event/input/user/UserEvent.hpp"

namespace fm
{

namespace event
{

namespace input
{

namespace user
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-09
 * Description:
 */
class Operate : public UserEvent
{
public:
    Operate(long deviceId);

    std::string toString() const override;

    long getDeviceId() const;

private:
    long deviceId;

};

} // user

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USER_OPERATE_HPP
