#include "Device.hpp"

#include "state/device/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Device::Device(Listener& listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    IClient(listener, coreClient, _certPath)
{
    setState(std::make_unique<device::Disconnected>(*this, listener, *backend.get()));
}

std::string Device::toString() const
{
    return "Device";
}
