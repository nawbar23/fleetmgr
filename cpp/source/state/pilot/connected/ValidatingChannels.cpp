#include "state/pilot/connected/ValidatingChannels.hpp"

#include "state/pilot/connected/Controlling.hpp"
#include "state/pilot/connected/Spectating.hpp"

#include "event/input/connection/Received.hpp"

#include "event/output/ChannelsOpened.hpp"
#include "event/output/Error.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;
using namespace fm::state::pilot::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;
using event::output::ChannelsOpened;
using event::output::Error;

using com::fleetmgr::interfaces::Role;
using com::fleetmgr::interfaces::Channel;

ValidatingChannels::ValidatingChannels(IState& state, Role _role, const std::vector<Channel>& openedChannels) :
    IState(state),
    role(_role),
    toValidate(openedChannels)
{
}

std::unique_ptr<IState> ValidatingChannels::start()
{
    auto result = backend.validateChannels(toValidate);
    ClientMessage response;
    response.set_command(Command::CHANNELS_READY);
    for (auto& pair : result)
    {
        response.mutable_attachchannels()->add_attachedchannels(pair.first);
    }
    send(response);
    return nullptr;
}

std::string ValidatingChannels::toString() const
{
    return "ValidatingChannels";
}

std::unique_ptr<IState> ValidatingChannels::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> ValidatingChannels::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> ValidatingChannels::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::CHANNELS_READY:
        if (message.response() == Response::ACCEPTED)
        {
            listener.onEvent(std::make_shared<ChannelsOpened>());
            switch (role)
            {
            case Role::LEADER:
                return std::make_unique<Controlling>(*this);

            case Role::PILOT:
                return std::make_unique<Spectating>(*this);
            }
        }
        else
        {
            listener.onEvent(std::make_shared<Error>());
            return defaultMessageHandle(message);
        }

    default:
        return defaultMessageHandle(message);
    }
}
