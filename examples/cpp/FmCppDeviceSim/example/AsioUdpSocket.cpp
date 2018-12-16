#include "AsioUdpSocket.hpp"

#include <iostream>

using namespace boost::asio;

AsioUdpSocket::AsioUdpSocket(boost::asio::io_service& _ioService) :
    ioService(_ioService),
    socket(ioService, ip::udp::endpoint(ip::udp::v4(), 0))
{
}

void AsioUdpSocket::connect(const std::string& host, const int port)
{
    //std::cout << "AsioUdpSocket::connect" << std::endl;
    remoteEndpoint = ip::udp::endpoint(ip::address::from_string(host), port);
}

size_t AsioUdpSocket::readBlocking(uint8_t* _buffer, size_t _size)
{
    return socket.receive_from(buffer(_buffer, _size), remoteEndpoint);
}

void AsioUdpSocket::startReading()
{
    doRead();
}

void AsioUdpSocket::send(const DataPacket dataPacket)
{
    //std::cout << "AsioUdpSocket::send" << std::endl;
    sendBuffer.emplace_back(dataPacket.first, dataPacket.first + dataPacket.second);
    socket.async_send_to(buffer(sendBuffer.back().data(), sendBuffer.back().size()), remoteEndpoint,
                         [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        sendBuffer.pop_front();
        if (ec)
        {
            std::cout << "AsioUdpSocket::send error: " + ec.message() << std::endl;
        }
    });
}

void AsioUdpSocket::disconnect()
{
    //std::cout << "AsioUdpSocket::disconnect" << std::endl;
    listener.load()->onClosed();
}

void AsioUdpSocket::doRead()
{
    //std::cout << "AsioUdpSocket::doRead" << std::endl;
    readBuffer.emplace_back(1024);
    socket.async_receive_from(buffer(readBuffer.back(), 1024), remoteEndpoint,
                              [this](boost::system::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            listener.load()->onReceived(DataPacket(readBuffer.front().data(), length));
            readBuffer.pop_front();
            doRead();
        }
        else
        {
            std::cout << "AsioUdpSocket::doRead error: " + ec.message() << std::endl;
        }
    });
}
