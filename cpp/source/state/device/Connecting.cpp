#include "state/device/Connecting.hpp"

#include "state/device/Disconnected.hpp"
#include "state/device/Disconnecting.hpp"
#include "state/device/Connected.hpp"

#include "event/input/connection/Received.hpp"

#include "event/output/Error.hpp"

#include "backend/ClientBackend.hpp"

#include "core/attach.pb.h"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;
using event::input::connection::Received;

using event::output::FacadeEvent;
using event::output::Error;

using com::fleetmgr::interfaces::AttachResponse;

Connecting::Connecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connecting::start()
{
    try
    {
        AttachResponse attachResponse = backend.getCore().attach();

        backend.openFacadeConnection(
                    attachResponse.host(),
                    attachResponse.port());

        ClientMessage message;
        message.set_command(Command::SETUP);
        message.mutable_attach()->set_key(attachResponse.key());
        send(message);

        return nullptr;
    }
    catch(std::exception const& e)
    {
        trace("Attach error: " + std::string(e.what()));
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

std::string Connecting::toString() const
{
    return "Connecting";
}

std::unique_ptr<IState> Connecting::handleMessage(const ControlMessage& message)
{
    switch (message.command())
    {
    case Command::SETUP:
        if (message.response() == Response::ACCEPTED)
        {
            return std::make_unique<Connected>(*this);
        }
        else
        {
            listener.onEvent(std::make_shared<Error>());
            return std::make_unique<Disconnecting>(*this);
        }

    default:
        return defaultMessageHandle(message);
    }
}
