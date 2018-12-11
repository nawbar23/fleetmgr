#include "state/device/connected/Flying.hpp"

#include "event/input/connection/Received.hpp"

#include "event/output/ChannelsOpened.hpp"
#include "event/output/ChannelsClosed.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;
using namespace fm::state::device::connected;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;
using event::output::ChannelsOpened;
using event::output::ChannelsClosed;

using com::fleetmgr::interfaces::Channel;

Flying::Flying(IState& state, const std::vector<Channel>& _initialChannels) :
    IState(state),
    initialChannels(_initialChannels)
{
}

std::unique_ptr<IState> Flying::start()
{
    attachChannels(initialChannels);
    return nullptr;
}

std::string Flying::toString() const
{
    return "Flying";
}

std::unique_ptr<IState> Flying::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Flying::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Flying::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::ATTACH_CHANNELS:
    {
        std::vector<Channel> openedeChannels(message.attachchannels().channels_size());
        for (int i = 0; i < message.attachchannels().channels_size(); ++i)
        {
            openedeChannels.push_back(message.attachchannels().channels(i));
        }
        attachChannels(openedeChannels);
        return nullptr;
    }

    case Command::RELEASE_CHANNELS:
    {
        std::vector<long> releasedChannels(message.channels().attachedchannels_size());
        for (int i = 0; i < message.channels().attachedchannels_size(); ++i)
        {
            releasedChannels.push_back(message.channels().attachedchannels(i));
        }
        releaseChannels(releasedChannels, message.command());
        return nullptr;
    }

    case Command::OPERATION_ENDED:
    {
        // TODO releaseChannles(backed.getChannelIdsCopy(), message.command());
        listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::OPERATION_ENDED));
        return nullptr;
    }

    default:
        return defaultMessageHandle(message);
    }
}

void Flying::attachChannels(const std::vector<Channel>& channels)
{
    // TODO backend->validateChannels(channels);
    listener.onEvent(std::make_shared<ChannelsOpened>());
    ClientMessage response;
    response.set_command(Command::ATTACH_CHANNELS);
    response.set_response(Response::ACCEPTED);
    // TODO response.mutable_attachchannels()->...
    send(response);
}

void Flying::releaseChannels(const std::vector<long>& channels, Command command)
{
    // TODO backend->closeChannels(channels);
    listener.onEvent(std::make_shared<ChannelsOpened>());
    ClientMessage response;
    response.set_command(command);
    response.set_response(Response::ACCEPTED);
    // TODO response.mutable_attachchannels()->...
    send(response);
}
