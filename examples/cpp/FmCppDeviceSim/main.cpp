#include <iostream>

#include "Device.hpp"

#include "example/AsioListener.hpp"
#include "example/AsioHttpsClient.hpp"

int main(int argc, char** argv)
{
    const std::string coreAddress = "https://localhost:1234";
    const std::string apiKey = "ApiKey asdasdasdasd";
    const std::string certPath = "c:/asd/asd/asd.ca";

    AsioListener listener;
    AsioHttpsClient coreClient(coreAddress, apiKey, certPath);

    fm::Device device(listener, coreClient);

    device.start();

    using fm::event::input::UserEvent;
    device.notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));

    return 0;
}
