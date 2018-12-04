#include "Device.hpp"

#include "state/device/Disconnected.hpp"

using namespace fm;
using namespace fm::state;

Device::Device(Listener& listener, core::https::IHttpsClient& coreClient) :
    // TODO Bartek: replace new with std::make_unique when supported
    IClient(std::unique_ptr<IState>(new ::device::Disconnected(*this, listener, coreClient)), listener)
{
}

std::string Device::toString() const
{
    return "Device";
}
