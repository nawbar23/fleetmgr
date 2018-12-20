#ifndef FM_EVENT_INPUT_USER_OPERATE_HPP
#define FM_EVENT_INPUT_USER_OPERATE_HPP

#include "event/input/user/UserEvent.hpp"

#include "common/channel_management.pb.h"

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
class Operate : public UserEvent
{
public:
    Operate(long, std::shared_ptr<std::vector<std::shared_ptr<com::fleetmgr::interfaces::ChannelRequest>>>);

    long getDeviceId() const;

    const std::vector<std::shared_ptr<com::fleetmgr::interfaces::ChannelRequest>>& getChannels() const;

    std::string toString() const override;

private:
    long deviceId;

    std::shared_ptr<std::vector<std::shared_ptr<com::fleetmgr::interfaces::ChannelRequest>>> channels;
};

} // user

} // input

} // event

} // fm

#endif // FM_EVENT_INPUT_USER_OPERATE_HPP
