#include "Device.hpp"
#include "AsioListener.hpp"
#include "AsioHttpsClient.hpp"

#include "event/input/user/UserEvent.hpp"

int main(int, char**)
{
    const std::string host = "192.168.56.1";
    const int port = 14010;

    const std::string apiKey = "";

    const std::string certPath = "../../../cpp/grpc_facade.crt";

    AsioListener listener;
    AsioHttpsClient core(host, port, apiKey);

    fm::Device device(listener, core, certPath);

    using fm::event::input::user::UserEvent;
    device.notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "DONE" << std::endl;
    return 0;
}
