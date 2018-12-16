#ifndef FM_STATE_PILOT_CONNECTED_RELEASED_HPP
#define FM_STATE_PILOT_CONNECTED_RELEASED_HPP

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
class Released : public IState
{
public:
    Released(IState&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

    std::unique_ptr<IState> createOuterState() override;

private:
    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);
};

} // connected

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTED_RELEASED_HPP
