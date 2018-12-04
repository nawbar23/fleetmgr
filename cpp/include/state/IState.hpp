#ifndef FM_STATE_ISTATE_HPP
#define FM_STATE_ISTATE_HPP

#include "core/CoreClient.hpp"
#include "IClient.hpp"

#include "event/input/UserEvent.hpp"

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

    virtual std::unique_ptr<IState> handleEvent(const std::shared_ptr<const event::input::UserEvent>) = 0;

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
