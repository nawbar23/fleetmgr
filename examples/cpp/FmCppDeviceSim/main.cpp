#include "Device.hpp"
#include "AsioListener.hpp"
#include "AsioHttpsClient.hpp"

int main(int, char**)
{
    const std::string host = "192.168.56.1";
    const int port = 14010;

    const std::string apiKey = "";

    AsioListener listener;
    AsioHttpsClient core(host, port, apiKey);

    fm::Device device(listener, core);

    using fm::event::input::UserEvent;
    device.notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));

    return 0;
}
