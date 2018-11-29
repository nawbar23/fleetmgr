#include "state/IState.hpp"

using namespace fm;
using namespace fm::state;

IState::~IState()
{
}

IState::IState(IState& state) :
    client(state.client)
{
}

IState::IState(IClient& client) :
    client(client)
{
}
