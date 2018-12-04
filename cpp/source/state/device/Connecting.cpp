#include "state/device/Connecting.hpp"

#include "state/device/Disconnected.hpp"

#include "core/attach.pb.h"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using namespace com::fleetmgr::interfaces::facade::control;

using event::input::UserEvent;
using event::output::FacadeEvent;

using com::fleetmgr::interfaces::AttachResponse;

Connecting::Connecting(IState& state) :
    IState(state)
{
}

std::unique_ptr<IState> Connecting::start()
{
    try
    {
        AttachResponse attachResponse = core.attach();

        client.openFacadeConnection(
                    attachResponse.host(),
                    attachResponse.port());

//        SetupRequest setup;
//        setup.set_key(attachResponse.key());
//        ClientMessage message;
//        message.set_command(Command::SETUP);
//        message.set_allocated_attach(&setup);
//        send(message);

        return nullptr;
    }
    catch(std::exception const& e)
    {
        trace("Attach error: " + std::string(e.what()));
        listener.onEvent(std::make_shared<const FacadeEvent>(FacadeEvent::ERROR));
        return std::unique_ptr<IState>(new Disconnected(*this));
    }
}

std::unique_ptr<IState> Connecting::handleEvent(const std::shared_ptr<const UserEvent> event)
{
    return defaultEventHandle(event->toString());
}

std::string Connecting::toString() const
{
    return "Connecting";
}
