#ifndef FM_STATE_DEVICE_CONNECTED_READY_HPP
#define FM_STATE_DEVICE_CONNECTED_READY_HPP

#include "state/IState.hpp"

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
 * Date: 2018-12-07
 * Description:
 */
class Ready : public IState
{
public:
    Ready(IState&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

protected:
    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);
};

} // connected

} // device

} // state

} // fm

#endif // FM_STATE_DEVICE_CONNECTED_READY_HPP
