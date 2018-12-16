#include "AsioUdpSocket.hpp"

#include <iostream>

AsioUdpSocket::AsioUdpSocket(boost::asio::io_service& _ioService) :
    ioService(_ioService)
{
}

void AsioUdpSocket::connect(const std::string&, const int)
{
    std::cout << "AsioUdpSocket::connect" << std::endl;
    listener.load()->onConnected();
    doRead();
}

void AsioUdpSocket::disconnect()
{
    std::cout << "AsioUdpSocket::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioUdpSocket::send(const DataPacket)
{
    std::cout << "AsioUdpSocket::send - MISSING IMPLEMENTATION" << std::endl;
}

void AsioUdpSocket::doRead()
{
    std::cout << "AsioUdpSocket::doRead - MISSING IMPLEMENTATION" << std::endl;
}
