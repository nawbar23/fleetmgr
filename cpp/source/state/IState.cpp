#include "state/IState.hpp"

#include "IClient.hpp"

using namespace fm;
using namespace fm::state;

IState::~IState()
{
}

IState::IState(IState& state) :
    client(state.client),
    listener(state.listener),
    core(state.core)
{
}

IState::IState(IClient& _client, IClient::Listener& _listener, core::https::IHttpsClient& coreClient) :
    client(_client),
    listener(_listener),
    core(coreClient)
{
}

std::unique_ptr<IState> IState::defaultEventHandle(const std::string& eventName)
{
    trace("Unexpected: " + eventName + " @ " + toString());
    return nullptr;
}

std::unique_ptr<IState> IState::defaultMessageHandle()
{
    trace("Unexpected ClientMessage: @ " + toString());
    return nullptr;
}

void IState::trace(const std::string& message)
{
    client.trace(message);
}
