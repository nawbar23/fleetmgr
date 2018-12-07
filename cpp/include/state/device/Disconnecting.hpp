#ifndef FM_STATE_DEVICE_DISCONNECTING_HPP
#define FM_STATE_DEVICE_DISCONNECTING_HPP

#include "state/IState.hpp"

namespace fm
{

namespace state
{

namespace device
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Disconnecting: public IState
{
public:
    Disconnecting(IState&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

protected:
    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;
};

} // device

} // state

} // fm

#endif // FM_STATE_DEVICE_DISCONNECTING_HPP
