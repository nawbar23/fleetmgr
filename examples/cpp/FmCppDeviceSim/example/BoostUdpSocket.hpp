#ifndef BOOSTUDPSOCKET_HPP
#define BOOSTUDPSOCKET_HPP

#include "traffic/socket/ISocket.hpp"

#include <boost/asio.hpp>
#include <boost/circular_buffer.hpp>

#include <deque>
#include <vector>

class BoostUdpSocket : public fm::traffic::socket::ISocket
{
public:
    BoostUdpSocket(boost::asio::io_service&);

    void connect(const std::string&, const int) override;

    size_t readBlocking(uint8_t*, size_t) override;

    void startReading() override;

    void send(const DataPacket) override;

    void disconnect() override;

private:
    // TODO Bartek change buffers to more memory efficnient structures
    // TODO Bartek for example boost::circular_buffer
    std::deque<std::vector<uint8_t>> sendBuffer;
    std::deque<std::vector<uint8_t>> readBuffer;

    boost::asio::io_service& ioService;
    boost::asio::ip::udp::socket socket;
    boost::asio::ip::udp::endpoint remoteEndpoint;

    void doRead();
};

#endif // BOOSTUDPSOCKET_HPP
