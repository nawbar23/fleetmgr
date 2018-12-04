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

    std::unique_ptr<IState> handleEvent(const std::shared_ptr<const event::input::UserEvent>) override;

    std::string toString() const override;
};

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTING_HPP
