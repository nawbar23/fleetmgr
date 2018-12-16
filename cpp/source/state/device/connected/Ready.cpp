#include "state/device/connected/Ready.hpp"

#include "state/device/connected/Releasing.hpp"
#include "state/device/connected/Flying.hpp"

#include "event/input/connection/Received.hpp"

#include "core/attach.pb.h"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;
using namespace fm::state::device::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

using com::fleetmgr::interfaces::Channel;

Ready::Ready(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Ready::start()
{
    return nullptr;
}

std::string Ready::toString() const
{
    return "Ready";
}

std::unique_ptr<IState> Ready::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    case UserEvent::RELEASE:
        return std::make_unique<Releasing>(*this);

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Ready::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Ready::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::ATTACH_CHANNELS:
    {
        std::shared_ptr<std::vector<Channel>> openedChannels =
                std::make_shared<std::vector<Channel>>(message.attachchannels().channels_size());
        for (int i = 0; i < message.attachchannels().channels_size(); ++i)
        {
            openedChannels->at(i) = message.attachchannels().channels(i);
        }
        return std::make_unique<Flying>(*this, openedChannels);
    }

    default:
        return defaultMessageHandle(message);
    }
}
