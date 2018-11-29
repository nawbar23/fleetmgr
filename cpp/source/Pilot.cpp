#include "Pilot.hpp"

#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Pilot::Pilot(Listener& _listener, https::IHttpsClient& _coreClient) :
    // TODO Bartek: replace new with std::make_unique when supported
    IClient(std::unique_ptr<IState>(new ::pilot::Disconnected(*this)), _listener, _coreClient)
{
}

std::string Pilot::toString() const
{
    return "Pilot";
}
