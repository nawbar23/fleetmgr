#ifndef FM_STATE_PILOT_CONNECTED_REQUESTINGCONTROL_HPP
#define FM_STATE_PILOT_CONNECTED_REQUESTINGCONTROL_HPP

#include "state/IState.hpp"

namespace fm
{

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
class RequestingControl : public IState
{
public:
    RequestingControl(IState&, long);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

private:
    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);

    long channelId;
};

} // connected

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTED_REQUESTINGCONTROL_HPP
