#ifndef ASIOTCPSOCKET_HPP
#define ASIOTCPSOCKET_HPP

#include "traffic/socket/ISocket.hpp"

#include <boost/asio.hpp>

#include <array>

class AsioTcpSocket : public fm::traffic::socket::ISocket
{
public:
    AsioTcpSocket(boost::asio::io_service&);

    void connect(const std::string&, const int) override;

    void disconnect() override;

    void send(const DataPacket) override;

    size_t readBlocking(uint8_t*, size_t) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    boost::asio::io_service& ioService;
    boost::asio::ip::tcp::socket socket;

    void doRead();
};

#endif // ASIOTCPSOCKET_HPP
