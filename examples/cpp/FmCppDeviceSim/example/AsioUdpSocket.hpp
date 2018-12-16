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

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    boost::asio::io_service& ioService;
    boost::asio::ip::udp::endpoint endpoint;

    void doRead();
};

#endif // ASIOUDPSOCKET_HPP
