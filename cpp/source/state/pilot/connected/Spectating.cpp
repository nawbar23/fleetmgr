#include "state/pilot/connected/Spectating.hpp"

#include "event/input/connection/Received.hpp"
#include "event/input/user/OpenChannels.hpp"
#include "event/input/user/CloseChannels.hpp"

#include "event/output/ChannelsClosing.hpp"

#include "state/pilot/connected/RequestingControl.hpp"
#include "state/pilot/connected/ValidatingChannels.hpp"
#include "state/pilot/connected/Recovering.hpp"
#include "state/pilot/connected/Released.hpp"
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
using event::output::ChannelsClosing;

Spectating::Spectating(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Spectating::start()
{
    return nullptr;
}

std::string Spectating::toString() const
{
    return "Spectating";
}

std::unique_ptr<IState> Spectating::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    case UserEvent::OPEN_CHANNELS:
    {
        const OpenChannels& openChannels = reinterpret_cast<const OpenChannels&>(event);
        ClientMessage message;
        message.set_command(Command::ADD_CHANNELS);
        for (const ChannelRequest& c : *openChannels.getChannels())
        {
            message.mutable_channelsrequest()->add_channels()->CopyFrom(c);
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
            message.mutable_channelsindication()->add_ids(c);
        }
        send(message);
        return nullptr;
    }

    case UserEvent::REQUEST_CONTROL:
        return std::make_unique<RequestingControl>(*this);

    case UserEvent::RELEASE:
        return std::make_unique<Releasing>(*this);

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Spectating::handleConnectionEvent(const ConnectionEvent& event)
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

std::unique_ptr<IState> Spectating::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::ADD_CHANNELS:
        if (message.response() == Response::ACCEPTED)
        {
            std::shared_ptr<std::vector<ChannelResponse>> toOpen =
                    std::make_shared<std::vector<ChannelResponse>>();
            toOpen->reserve(message.channelsresponse().channels_size());
            for (int i = 0; i < message.channelsresponse().channels_size(); ++i)
            {
                toOpen->push_back(message.channelsresponse().channels(i));
            }
            return std::make_unique<ValidatingChannels>(*this, Role::LEADER, toOpen);
        }
        else
        {
            return defaultMessageHandle(message);
        }


    case Command::REMOVE_CHANNELS:
        if (message.response() == Response::ACCEPTED)
        {
            listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::CHANNELS_CLOSED));
            return nullptr;
        }
        else
        {
            return defaultMessageHandle(message);
        }

    case Command::LEADER_UNREACHABLE:
        listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::LEADER_UNREACHABLE));
        return nullptr;

    case Command::OPERATION_ENDED:
    {
        std::shared_ptr<std::vector<traffic::IChannel*>> channels = backend.getChannelsHandler().getChannels();
        listener.onEvent(std::make_shared<ChannelsClosing>(channels));
        backend.getChannelsHandler().closeAllChannels();
        ClientMessage message;
        message.set_command(Command::OPERATION_ENDED);
        message.set_response(Response::ACCEPTED);
        return std::make_unique<Released>(*this);
    }

    default:
        return defaultMessageHandle(message);
    }
}
