#ifndef FM_STATE_DEVICE_CONNECTED_FLYING_HPP
#define FM_STATE_DEVICE_CONNECTED_FLYING_HPP

#include "state/IState.hpp"

#include "common/channel.pb.h"
#include "facade/control/facade_service.pb.h"

#include <vector>

namespace fm
{

namespace state
{

namespace device
{

namespace connected
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-09
 * Description:
 */
class Flying : public IState
{
public:
    Flying(IState&, const std::vector<com::fleetmgr::interfaces::Channel>&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

private:
    const std::vector<com::fleetmgr::interfaces::Channel> initialChannels;

    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);

    void attachChannels(const std::vector<com::fleetmgr::interfaces::Channel>&);

    void releaseChannels(const std::vector<long>&, com::fleetmgr::interfaces::facade::control::Command);
};

} // connected

} // device

} // state

} // fm

#endif // FM_STATE_DEVICE_CONNECTED_FLYING_HPP
