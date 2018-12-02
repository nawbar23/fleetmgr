#include "AsioUdpClient.hpp"

#include <iostream>

AsioUdpClient::AsioUdpClient()
{
}

void AsioUdpClient::connect(const std::string&, const int)
{
    std::cout << "AsioUdpClient::connect" << std::endl;
    listener.load()->onConnected();
    doRead();
}

void AsioUdpClient::disconnect()
{
    std::cout << "AsioUdpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioUdpClient::send(const DataPacket)
{
    std::cout << "AsioUdpClient::send - MISSING IMPLEMENTATION" << std::endl;
}

void AsioUdpClient::doRead()
{
    std::cout << "AsioUdpClient::doRead - MISSING IMPLEMENTATION" << std::endl;
}
