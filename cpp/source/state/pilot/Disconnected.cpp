#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

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

std::unique_ptr<IState> Disconnected::handleUserEvent(const UserEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::unique_ptr<IState> Disconnected::handleConnectionEvent(const ConnectionEvent& event)
{
    return defaultEventHandle(event.toString());
}

std::string Disconnected::toString() const
{
    return "Disconnected";
}
