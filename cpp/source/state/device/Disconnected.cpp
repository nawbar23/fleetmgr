#include "state/device/Disconnected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::device;

Disconnected::Disconnected(IState& state) :
    IState(state)
{
}

Disconnected::Disconnected(IClient& client) :
    IState(client)
{
}

std::unique_ptr<IState> Disconnected::start()
{
    return nullptr;
}

std::unique_ptr<IState> Disconnected::handleEvent(std::shared_ptr<const event::input::UserEvent>)
{
    return nullptr;
}

std::string Disconnected::toString() const
{
    return "Disconnected";
}
