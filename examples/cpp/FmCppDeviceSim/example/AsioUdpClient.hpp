#ifndef ASIOUDPCLIENT_HPP
#define ASIOUDPCLIENT_HPP

#include "traffic/socket/ISocket.hpp"

#include <array>

class AsioUdpClient : public fm::traffic::socket::ISocket
{
public:
    AsioUdpClient();

    void connect(const std::string&, const int) override;

    void disconnect() override;

    void send(const DataPacket dataPacket) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    void doRead();
};

#endif // ASIOUDPCLIENT_HPP
