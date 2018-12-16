#ifndef ASIOUDPSOCKET_HPP
#define ASIOUDPSOCKET_HPP

#include "traffic/socket/ISocket.hpp"

#include <boost/asio.hpp>

#include <array>

class AsioUdpSocket : public fm::traffic::socket::ISocket
{
public:
    AsioUdpSocket(boost::asio::io_service&);

    void connect(const std::string&, const int) override;

    void disconnect() override;

    void send(const DataPacket) override;

    size_t readBlocking(uint8_t*, size_t) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    boost::asio::io_service& ioService;
    boost::asio::ip::udp::socket socket;
    boost::asio::ip::udp::endpoint remoteEndpoint;

    void doRead();
};

#endif // ASIOUDPSOCKET_HPP
