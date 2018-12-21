#include "BoostTcpSocket.hpp"

#include <iostream>

using namespace boost::asio;

BoostTcpSocket::BoostTcpSocket(boost::asio::io_service& _ioService) :
    ioService(_ioService),
    socket(ioService)
{
}

void BoostTcpSocket::connect(const std::string& host, const int port)
{
    //std::cout << "BoostTcpSocket::connect" << std::endl;
    ip::tcp::resolver resolver(ioService);
    auto endpoint = resolver.resolve(host, std::to_string(port));
    async_connect(socket, endpoint, [this] (std::error_code ec, ip::tcp::endpoint)
    {
        if (!ec)
        {
        }
    });
}

size_t BoostTcpSocket::readBlocking(uint8_t* _buffer, size_t _size)
{
    return socket.read_some(buffer(_buffer, _size));
}

void BoostTcpSocket::startReading()
{
    doRead();
}

void BoostTcpSocket::send(const DataPacket dataPacket)
{
    //std::cout << "BoostTcpSocket::send" << std::endl;
    async_write(socket, buffer(dataPacket.first, dataPacket.second),
                [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (ec)
        {
            std::cout << "BoostTcpSocket::send error: " + ec.message() << std::endl;
        }
    });
}

void BoostTcpSocket::disconnect()
{
    //std::cout << "BoostTcpSocket::disconnect" << std::endl;
    listener.load()->onClosed();
}

void BoostTcpSocket::doRead()
{
    //std::cout << "BoostTcpSocket::doRead" << std::endl;
    socket.async_read_some(buffer(readBuffer.data(), READ_BUFFER_SIZE),
                           [this](boost::system::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            listener.load()->onReceived(DataPacket(readBuffer.data(), length));
            doRead();
        }
        else
        {
            std::cout << "BoostTcpSocket::doRead error: " + ec.message() << std::endl;
        }
    });
}
