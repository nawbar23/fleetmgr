#include "Device.hpp"

#include "state/device/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Device::Device(Listener& _listener, https::IHttpsClient& _coreClient) :
    // TODO Bartek: replace new with std::make_unique when supported
    IClient(std::unique_ptr<IState>(new ::device::Disconnected(*this)), _listener, _coreClient)
{
}

std::string Device::toString() const
{
    return "Device";
}
