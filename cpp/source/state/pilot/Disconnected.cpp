#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;
using namespace fm::state::pilot;

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
