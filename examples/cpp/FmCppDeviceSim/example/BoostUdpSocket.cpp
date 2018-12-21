#include "BoostUdpSocket.hpp"

#include <iostream>

using namespace boost::asio;

BoostUdpSocket::BoostUdpSocket(boost::asio::io_service& _ioService) :
    ioService(_ioService),
    socket(ioService, ip::udp::endpoint(ip::udp::v4(), 0))
{
}

void BoostUdpSocket::connect(const std::string& host, const int port)
{
    //std::cout << "BoostUdpSocket::connect(" << host << ":" << port << ")" << std::endl;
    ip::udp::resolver resolver(ioService);
    remoteEndpoint = *resolver.resolve(host, std::to_string(port));
}

size_t BoostUdpSocket::readBlocking(uint8_t* _buffer, size_t _size)
{
    return socket.receive_from(buffer(_buffer, _size), remoteEndpoint);
}

void BoostUdpSocket::startReading()
{
    doRead();
}

void BoostUdpSocket::send(const DataPacket dataPacket)
{
    //std::cout << "BoostUdpSocket::send" << std::endl;
    sendBuffer.emplace_back(dataPacket.first, dataPacket.first + dataPacket.second);
    socket.async_send_to(buffer(sendBuffer.back().data(), sendBuffer.back().size()), remoteEndpoint,
                         [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        sendBuffer.pop_front();
        if (ec)
        {
            std::cout << "BoostUdpSocket::send error: " + ec.message() << std::endl;
        }
    });
}

void BoostUdpSocket::disconnect()
{
    //std::cout << "BoostUdpSocket::disconnect" << std::endl;
    listener.load()->onClosed();
}

void BoostUdpSocket::doRead()
{
    //std::cout << "BoostUdpSocket::doRead" << std::endl;
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
            std::cout << "BoostUdpSocket::doRead error: " + ec.message() << std::endl;
        }
    });
}
