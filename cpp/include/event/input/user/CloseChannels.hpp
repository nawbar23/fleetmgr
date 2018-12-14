#ifndef FM_EVENT_INPUT_USER_CLOSECHANNELS_HPP
#define FM_EVENT_INPUT_USER_CLOSECHANNELS_HPP

#include "event/input/user/UserEvent.hpp"

#include <vector>

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
class CloseChannels : public UserEvent
{
public:
    CloseChannels();

    CloseChannels(const std::vector<long>&);

    std::string toString() const override;

    std::vector<long>& getChannels();

    const std::vector<long>& getChannels() const;

private:
    std::vector<long> channels;
};

} // user

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USER_CLOSECHANNELS_HPP
