#ifndef FM_STATE_ISTATE_HPP
#define FM_STATE_ISTATE_HPP

#include "core/CoreClient.hpp"
#include "IClient.hpp"

#include "event/input/user/UserEvent.hpp"
#include "event/input/connection/ConnectionEvent.hpp"

#include "facade/control/facade_service.pb.h"

#include <memory>

namespace fm
{

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

    std::unique_ptr<IState> handleEvent(const std::shared_ptr<const event::input::IInputEvent>);

    virtual std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) = 0;

    virtual std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) = 0;

    virtual std::string toString() const = 0;

protected:
    IState(IState&);

    IState(IClient&, IClient::Listener&, core::https::IHttpsClient&);

    IClient& client;
    IClient::Listener& listener;

    core::CoreClient core;

    void send(const com::fleetmgr::interfaces::facade::control::ClientMessage&);

    std::unique_ptr<IState> defaultEventHandle(const std::string& eventName);

    std::unique_ptr<IState> defaultMessageHandle();

    void trace(const std::string& message);
};

} // state

} // fm

#endif // FM_STATE_STATE_HPP
