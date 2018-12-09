#include "Pilot.hpp"

#include "state/pilot/Disconnected.hpp"

#include "backend/ClientBackend.hpp"

#include "core/CoreClient.hpp"

using namespace fm;
using namespace fm::state;

using namespace com::fleetmgr::interfaces;

Pilot::Pilot(Listener& listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    IClient(listener, coreClient, _certPath)
{
    setState(std::make_unique<pilot::Disconnected>(*this, listener, *backend.get()));
}

std::string Pilot::toString() const
{
    return "Pilot";
}

ListDevicesResponse Pilot::listDevices()
{
    return backend->getCore().listDevices();
}

ListDevicesResponse Pilot::listConnectedDevices()
{
    ListDevicesResponse response = listDevices();
    ListDevicesResponse result;
    for (int i = 0; i < response.devices_size(); ++i)
    {
        const Device& d = response.devices(i);
        if (d.connectionstate() == CONNECTED)
        {
            Device* e = result.mutable_devices()->Add();
            e->CopyFrom(d);
        }
    }
    return result;
}
