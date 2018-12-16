#include "AsioTcpSocket.hpp"

#include <iostream>

using namespace boost::asio;

AsioTcpSocket::AsioTcpSocket(boost::asio::io_service& _ioService) :
    ioService(_ioService),
    socket(ioService)
{
}

void AsioTcpSocket::connect(const std::string& host, const int port)
{
    std::cout << "AsioTcpSocket::connect" << std::endl;
    ip::tcp::resolver resolver(ioService);
    auto endpoint = resolver.resolve(host, std::to_string(port));
    async_connect(socket, endpoint, [this] (std::error_code ec, ip::tcp::endpoint)
    {
        if (!ec)
        {
            doRead();
            listener.load()->onConnected();
        }
        else
        {
            std::cout << "ERROR!!!!!!!!" << std::endl;
        }
    });
}

void AsioTcpSocket::disconnect()
{
    std::cout << "AsioTcpSocket::disconnect" << std::endl;
    listener.load()->onDisconnected();
}

void AsioTcpSocket::send(const DataPacket dataPacket)
{
    std::cout << "AsioTcpSocket::send" << std::endl;
    async_write(socket, buffer(dataPacket.first, dataPacket.second),
                [this](std::error_code ec, std::size_t /*length*/)
    {
        if (ec)
        {
            socket.close();
        }
    });
}

void AsioTcpSocket::doRead()
{
    std::cout << "AsioTcpSocket::doRead" << std::endl;
    socket.async_read_some(buffer(readBuffer.data(), READ_BUFFER_SIZE),
                           [this](std::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            listener.load()->onReceived(DataPacket(readBuffer.data(), length));
            doRead();
        }
        else
        {
            socket.close();
        }
    });
}
