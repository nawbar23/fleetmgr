#ifndef FM_STATE_PILOT_CONNECTED_VALIDATINGCHANNELS_HPP
#define FM_STATE_PILOT_CONNECTED_VALIDATINGCHANNELS_HPP

#include "state/IState.hpp"

#include "common/role.pb.h"
#include "common/channel_management.pb.h"

#include <vector>

namespace fm
{

namespace traffic {
class IChannel;
}

namespace state
{

namespace pilot
{

namespace connected
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-09
 * Description:
 */
class ValidatingChannels : public IState
{
public:
    ValidatingChannels(IState&, com::fleetmgr::interfaces::Role, std::shared_ptr<std::vector<com::fleetmgr::interfaces::ChannelResponse>>);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

private:
    com::fleetmgr::interfaces::Role role;

    std::shared_ptr<std::vector<com::fleetmgr::interfaces::ChannelResponse>> toValidate;
    std::shared_ptr<std::vector<traffic::IChannel*>> validated;

    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);
};

} // connected

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTED_RELEASEING_HPP
