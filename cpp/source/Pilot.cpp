#include "Pilot.hpp"

#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Pilot::Pilot(Listener& listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    IClient(listener, coreClient, _certPath)
{
    setState(std::make_unique<pilot::Disconnected>(*this, listener, *backend.get()));
}

std::string Pilot::toString() const
{
    return "Pilot";
}
