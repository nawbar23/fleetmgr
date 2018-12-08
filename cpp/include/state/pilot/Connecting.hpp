#ifndef FM_STATE_PILOT_CONNECTING_HPP
#define FM_STATE_PILOT_CONNECTING_HPP

#include "state/IState.hpp"

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
    Connecting(IState&);

    std::unique_ptr<IState> start() override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

    std::string toString() const override;

    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);
};

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTING_HPP
