#include "state/device/Disconnected.hpp"

#include "state/device/Connecting.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

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

std::unique_ptr<IState> Disconnected::handleEvent(const std::shared_ptr<const UserEvent> event)
{
    switch (event->getType())
    {
    case UserEvent::ATTACH:
        return std::unique_ptr<IState>(new Connecting(*this));

    default:
        return defaultEventHandle(event->toString());
    }
}

std::string Disconnected::toString() const
{
    return "Disconnected";
}
