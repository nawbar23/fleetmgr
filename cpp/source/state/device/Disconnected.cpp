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

Disconnected::Disconnected(IClient& client, IClient::Listener& listener, core::https::IHttpsClient& coreClient) :
    IState(client, listener, coreClient)
{
}

std::unique_ptr<IState> Disconnected::start()
{
    return nullptr;
}

std::string Disconnected::toString() const
{
    return "Disconnected";
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
