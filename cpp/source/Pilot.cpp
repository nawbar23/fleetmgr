#include "Pilot.hpp"

#include "state/pilot/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Pilot::Pilot(Listener& listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    IClient(std::make_unique<pilot::Disconnected>(*this, listener, coreClient), listener, _certPath)
{
}

std::string Pilot::toString() const
{
    return "Pilot";
}
