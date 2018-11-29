#ifndef FM_TRAFFIC_SOCKET_ISOCKET_HPP
#define FM_TRAFFIC_SOCKET_ISOCKET_HPP

#include <atomic>
#include <string>

namespace fm
{

namespace traffic
{

namespace socket
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class ISocket
{
public:
    typedef std::pair<const uint8_t* const, const size_t> DataPacket;

    enum Protocol
    {
        UDP,
        TCP,
    };

    class Listener
    {
    public:
        virtual void onConnected() = 0;

        virtual void onDisconnected() = 0;

        virtual void onReceived(const DataPacket) = 0;
    };

    virtual ~ISocket();

    void setListener(Listener*);

    virtual void connect(const std::string&, const int) = 0;

    virtual void disconnect() = 0;

    virtual void send(const DataPacket) = 0;

protected:
    std::atomic<Listener*> listener;
};

} // socket

} // traffic

} // fm

#endif // FM_TRAFFIC_SOCKET_ISOCKET_HPP
