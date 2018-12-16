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
    doRead();
}

void AsioUdpSocket::disconnect()
{
    //std::cout << "AsioUdpSocket::disconnect" << std::endl;
    listener.load()->onClosed();
}

void AsioUdpSocket::send(const DataPacket dataPacket)
{
    //std::cout << "AsioUdpSocket::send" << std::endl;
    socket.async_send_to(buffer(dataPacket.first, dataPacket.second), remoteEndpoint,
                         [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (ec)
        {
            std::cout << "AsioUdpSocket::send error: " + ec.message() << std::endl;
        }
    });
}

size_t AsioUdpSocket::readBlocking(uint8_t* _buffer, size_t _size)
{
    return socket.receive_from(buffer(_buffer, _size), remoteEndpoint);
}

void AsioUdpSocket::doRead()
{
    //std::cout << "AsioUdpSocket::doRead" << std::endl;
    socket.async_receive_from(buffer(readBuffer.data(), READ_BUFFER_SIZE), remoteEndpoint,
                              [this](boost::system::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            listener.load()->onReceived(DataPacket(readBuffer.data(), length));
            doRead();
        }
        else
        {
            std::cout << "AsioUdpSocket::doRead error: " + ec.message() << std::endl;
        }
    });
}
