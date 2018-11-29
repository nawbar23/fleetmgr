#ifndef FM_STATE_ISTATE_HPP
#define FM_STATE_ISTATE_HPP

#include "event/input/UserEvent.hpp"

#include <memory>

namespace fm
{

class IClient;

namespace state
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class IState
{
public:
    virtual ~IState();

    virtual std::unique_ptr<IState> start() = 0;

    virtual std::unique_ptr<IState> handleEvent(std::shared_ptr<const event::input::UserEvent>) = 0;

    virtual std::string toString() const = 0;

protected:
    IState(IState&);

    IState(IClient&);

    IClient& client;
};

} // state

} // fm

#endif // FM_STATE_STATE_HPP
