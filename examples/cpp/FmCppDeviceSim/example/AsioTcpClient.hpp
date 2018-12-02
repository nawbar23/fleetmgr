#ifndef ASIOTCPCLIENT_HPP
#define ASIOTCPCLIENT_HPP

#include "traffic/socket/ISocket.hpp"

#include <array>

class AsioTcpClient : public fm::traffic::socket::ISocket
{
public:
    AsioTcpClient();

    void connect(const std::string& host, const int port) override;

    void disconnect() override;

    void send(const DataPacket dataPacket) override;

private:
    static constexpr size_t READ_BUFFER_SIZE = 1024;
    std::array<uint8_t, READ_BUFFER_SIZE> readBuffer;

    void doRead();
};

#endif // ASIOTCPCLIENT_HPP
