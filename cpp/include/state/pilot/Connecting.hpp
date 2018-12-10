#ifndef FM_STATE_PILOT_CONNECTING_HPP
#define FM_STATE_PILOT_CONNECTING_HPP

#include "state/IState.hpp"

#include "common/role.pb.h"

#include <vector>

namespace fm
{

namespace state
{

namespace pilot
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Connecting : public IState
{
public:
    Connecting(IState&, long, const std::vector<long>&);

    std::unique_ptr<IState> start() override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

    std::string toString() const override;

    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);

private:
    long deviceId;
    std::vector<long> channels;

    com::fleetmgr::interfaces::Role initialRole;
};

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTING_HPP
