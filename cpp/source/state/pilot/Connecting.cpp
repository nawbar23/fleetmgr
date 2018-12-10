#include "state/pilot/Connecting.hpp"

#include "state/pilot/Disconnected.hpp"
#include "state/pilot/Connected.hpp"

#include "event/input/connection/Received.hpp"

#include "backend/ClientBackend.hpp"

#include "core/attach.pb.h"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;

using com::fleetmgr::interfaces::OperateRequest;
using com::fleetmgr::interfaces::OperateResponse;

Connecting::Connecting(IState& state, long _deviceId, const std::vector<long>& _channels) :
    IState(state),
    deviceId(_deviceId),
    channels(_channels)
{
}

std::unique_ptr<IState> Connecting::start()
{
    try
    {
        OperateRequest request;
        request.set_requesteddeviceid(deviceId);
        OperateResponse operateResponse = backend.getCore().operate(request);

        backend.openFacadeConnection(
                    operateResponse.host(),
                    operateResponse.port());
        initialRole = operateResponse.role();

        ClientMessage message;
        message.set_command(Command::SETUP);
        message.mutable_attach()->set_key(operateResponse.key());
        for (long c : channels)
        {
            message.mutable_requestchannels()->add_channelid(c);
        }
        send(message);

        return nullptr;
    }
    catch(std::exception const& e)
    {
        trace("Operate error: " + std::string(e.what()));
        listener.onEvent(std::make_shared<const FacadeEvent>(FacadeEvent::ERROR));
        return std::make_unique<Disconnected>(*this);
    }
}

std::unique_ptr<IState> Connecting::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Connecting::handleConnectionEvent(const ConnectionEvent& event)
{
    switch (event.getType())
    {
    case ConnectionEvent::RECEIVED:
        return handleMessage(reinterpret_cast<const Received&>(event).getMessage());

    default:
        return defaultEventHandle(event.toString());
    }
}

std::unique_ptr<IState> Connecting::handleMessage(const ControlMessage& message)
{
    if (message.command() == Command::SETUP &&
            message.response() == Response::ACCEPTED)
    {
        return std::make_unique<Connected>(*this);
    }
    else
    {
        backend.closeFacadeConnection();
        listener.onEvent(std::make_shared<FacadeEvent>(FacadeEvent::ERROR));
        return std::make_unique<Disconnected>(*this);
    }
}


std::string Connecting::toString() const
{
    return "Connecting";
}
