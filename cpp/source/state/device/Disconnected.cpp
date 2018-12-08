#include "state/device/Disconnected.hpp"

#include "state/device/Connecting.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

using event::input::user::UserEvent;
using event::input::connection::ConnectionEvent;

using event::output::FacadeEvent;

Disconnected::Disconnected(IState& state) :
    IState(state)
{
}

Disconnected::Disconnected(IClient& client, IClient::Listener& listener, backend::ClientBackend& backend) :
    IState(client, listener, backend)
{
}

std::unique_ptr<IState> Disconnected::start()
{
    return nullptr;
}

std::unique_ptr<IState> Disconnected::handleUserEvent(const UserEvent& event)
{
    switch (event.getType())
    {
    case UserEvent::ATTACH:
        return std::make_unique<Connecting>(*this);

    default:
        return defaultEventHandle(event.toString());
    }
}

std::string Disconnected::toString() const
{
    return "Disconnected";
}
