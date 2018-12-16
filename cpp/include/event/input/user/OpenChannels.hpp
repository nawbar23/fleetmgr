#ifndef FM_EVENT_INPUT_USER_OPENCHANNELS_HPP
#define FM_EVENT_INPUT_USER_OPENCHANNELS_HPP

#include "event/input/user/UserEvent.hpp"

#include <vector>
#include <memory>

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
    OpenChannels(std::shared_ptr<std::vector<long>>);

    const std::vector<long>& getChannels() const;

    std::string toString() const override;

private:
    std::shared_ptr<std::vector<long>> channels;
};

} // user

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USER_OPENCHANNELS_HPP
