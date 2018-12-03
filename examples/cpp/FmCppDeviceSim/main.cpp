#include <iostream>

#include "example/AsioListener.hpp"
#include "example/AsioHttpsClient.hpp"

#include "Device.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

int main(int argc, char** argv)
{
    const std::string coreAddress = "https://localhost:1234";
    const std::string apiKey = "ApiKey asdasdasdasd";
    const std::string certPath = "c:/asd/asd/asd.ca";

    boost::asio::io_service io_service;

    AsioListener listener;
    AsioHttpsClient coreClient(coreAddress, apiKey, certPath);

    fm::Device device(listener, coreClient);

    device.start();

    using fm::event::input::UserEvent;
    device.notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));

    return 0;
}
