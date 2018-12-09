#ifndef FM_EVENT_INPUT_USER_OPENCHANNELS_HPP
#define FM_EVENT_INPUT_USER_OPENCHANNELS_HPP

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
class OpenChannels : public UserEvent
{
public:
    OpenChannels();

    std::string toString() const override;

private:
};

} // user

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USER_OPENCHANNELS_HPP
