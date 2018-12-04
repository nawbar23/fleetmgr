#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

using event::input::UserEvent;

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

std::unique_ptr<IState> Disconnected::handleEvent(const std::shared_ptr<const event::input::UserEvent> event)
{
    return defaultEventHandle(event->toString());
}

std::string Disconnected::toString() const
{
    return "Disconnected";
}
