#include "Device.hpp"
#include "AsioListener.hpp"
#include "AsioHttpsClient.hpp"

int main(int, char**)
{
    AsioListener listener;
    AsioHttpsClient core("", "", "");

    fm::Device device(listener, core);

    device.start();

    core.execute("", fm::core::https::IHttpsClient::GET, "");

    return 0;
}
