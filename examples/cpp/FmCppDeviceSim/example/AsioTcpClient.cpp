#include "AsioTcpClient.hpp"

#include <iostream>

AsioTcpClient::AsioTcpClient()
{
}

void AsioTcpClient::connect(const std::string& host, const int port)
{
    std::cout << "TcpCommInterface::connect" << std::endl;

}

void AsioTcpClient::disconnect()
{
    std::cout << "AsioTcpClient::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioTcpClient::send(const DataPacket dataPacket)
{
    std::cout << "AsioTcpClient::send" << std::endl;

}

void AsioTcpClient::doRead()
{
    std::cout << "AsioTcpClient::doRead" << std::endl;

}
