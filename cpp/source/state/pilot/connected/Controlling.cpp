#include "state/pilot/connected/Controlling.hpp"

#include "event/input/connection/Received.hpp"
#include "event/input/user/OpenChannels.hpp"
#include "event/input/user/CloseChannels.hpp"

#include "state/pilot/connected/ReleasingControl.hpp"
#include "state/pilot/connected/ValidatingChannels.hpp"
#include "state/pilot/connected/Recovering.hpp"
#include "state/pilot/connected/Releasing.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces;
using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::user::OpenChannels;
using event::input::user::CloseChannels;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

Controlling::Controlling(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Controlling::start()
{
    return nullptr;
}

std::string Controlling::toString() const
{
    return "Controlling";
}

std::unique_ptr<IState> Controlling::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    case UserEvent::OPEN_CHANNELS:
    {
        const OpenChannels& openChannels = reinterpret_cast<const OpenChannels&>(event);
        ClientMessage message;
        message.set_command(Command::ADD_CHANNELS);
        for (long c : openChannels.getChannels())
        {
            message.mutable_requestchannels()->add_channelid(c);
        }
        send(message);
        return nullptr;
    }

    case UserEvent::CLOSE_CHANNELS:
    {
        const CloseChannels& closeChannels = reinterpret_cast<const CloseChannels&>(event);
        backend.getChannelsHandler().closeChannels(closeChannels.getChannels());
        ClientMessage message;
        message.set_command(Command::REMOVE_CHANNELS);
        for (long c : closeChannels.getChannels())
        {
            message.mutable_requestchannels()->add_channelid(c);
        }
        send(message);
        return nullptr;
    }

    case UserEvent::RELEASE:
        return std::make_unique<Releasing>(*this);

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Controlling::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    case ConnectionEvent::LOST:
        return std::make_unique<Recovering>(*this);

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Controlling::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::ADD_CHANNELS:
        if (message.response() == Response::ACCEPTED)
        {
            std::shared_ptr<std::vector<Channel>> toOpen = std::make_shared<std::vector<Channel>>();
            return std::make_unique<ValidatingChannels>(*this, Role::LEADER, toOpen);
        }
        else
        {
            return defaultMessageHandle(message);
        }


    case Command::REMOVE_CHANNELS:
        if (message.response() == Response::ACCEPTED)
        {
            return nullptr;
        }
        else
        {
            return defaultMessageHandle(message);
        }

    case Command::DEVICE_UNREACHABLE:
        listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::DEVICE_UNREACHABLE));
        return nullptr;

    case Command::RELEASE_CONTROL:
        return std::make_unique<ReleasingControl>(*this);

    default:
        return defaultMessageHandle(message);
    }
}
