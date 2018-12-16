#ifndef FM_TRAFFIC_CHANNEL_HPP
#define FM_TRAFFIC_CHANNEL_HPP

#include "traffic/socket/ISocket.hpp"

#include <memory>
#include <string>

namespace fm
{

namespace traffic
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Channel : public traffic::socket::ISocket::Listener
{
public:
    class Listener
    {
    public:
        virtual ~Listener();

        virtual void onReceived(Channel&, const socket::ISocket::DataPacket) = 0;

        virtual void onClosed(Channel&) = 0;
    };

    Channel(long, std::shared_ptr<socket::ISocket>);

    void setListener(std::shared_ptr<Listener>);

    bool open(const std::string&, const int, const std::string&);

    void close();

    void send(const socket::ISocket::DataPacket);

    long getId() const;

private:
    const long id;
    std::shared_ptr<socket::ISocket> socket;

    std::shared_ptr<Listener> listener;

    void onReceived(const socket::ISocket::DataPacket) override;

    void onClosed() override;
};

} // traffic

} // fm

#endif // FM_TRAFFIC_CHANNEL_HPP
