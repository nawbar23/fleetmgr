#ifndef FM_STATE_DEVICE_DISCONNECTED_HPP
#define FM_STATE_DEVICE_DISCONNECTED_HPP

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
class Disconnected : public IState
{
public:
    Disconnected(IState&);

    Disconnected(IClient&, IClient::Listener&, core::https::IHttpsClient&);

    std::unique_ptr<IState> start() override;

    std::unique_ptr<IState> handleEvent(const std::shared_ptr<const event::input::UserEvent>) override;

    std::string toString() const override;
};

} // device

} // state

} // fm

#endif // FM_STATE_DEVICE_DISCONNECTED_HPP
