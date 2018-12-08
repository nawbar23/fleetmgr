#ifndef FM_STATE_PILOT_CONNECTED_HPP
#define FM_STATE_PILOT_CONNECTED_HPP

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
class Connected : public IState
{
public:
    Connected(IState&);

    std::unique_ptr<IState> start() override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

    std::string toString() const override;

private:
    std::unique_ptr<state::IState> internalState;

    std::unique_ptr<IState> onNewState(std::unique_ptr<IState>);
};

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTED_HPP
