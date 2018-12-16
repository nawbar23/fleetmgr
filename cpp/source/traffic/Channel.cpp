#include "traffic/Channel.hpp"

using namespace fm;
using namespace fm::traffic;

Channel::Channel(long _id, std::shared_ptr<socket::ISocket> _socket) :
    id(_id),
    socket(_socket)
{
}

bool Channel::open(const std::string& ip, const int port, const std::string& key)
{

    return true;
}

void Channel::close()
{

}

long Channel::getId() const
{
    return id;
}
