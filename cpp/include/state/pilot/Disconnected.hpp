#ifndef FM_STATE_PILOT_DISCONNECTED_HPP
#define FM_STATE_PILOT_DISCONNECTED_HPP

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
class Disconnected : public IState
{
public:
    Disconnected(IState&);

    Disconnected(IClient&, IClient::Listener&, backend::ClientBackend&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

protected:
    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;
};

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_DISCONNECTED_HPP
