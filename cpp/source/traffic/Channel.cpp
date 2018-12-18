#include "traffic/Channel.hpp"

#include "common/channel_validation.pb.h"

using namespace fm;
using namespace fm::traffic;
using namespace fm::traffic::socket;

using com::fleetmgr::interfaces::ValidateChannelRequest;
using com::fleetmgr::interfaces::ValidateChannelResponse;
using com::fleetmgr::interfaces::Result;

Channel::Listener::~Listener()
{
}

Channel::Channel(long _id, std::shared_ptr<ISocket> _socket) :
    id(_id),
    socket(_socket),
    listener(nullptr)
{
}

void Channel::setListener(std::shared_ptr<Listener> _listener)
{
    listener.swap(_listener);
}

bool Channel::open(const std::string& ip, const int port, const std::string& key)
{
    socket->setListener(this);

    socket->connect(ip, port);

    ValidateChannelRequest request;
    request.set_key(key);

    std::vector<uint8_t> packet(request.ByteSize());
    if (!request.SerializeToArray(packet.data(), packet.size()))
    {
        std::cout << "Could not serialize validation request" << std::endl;
        return false;
    }

    socket->send(ISocket::DataPacket(packet.data(), packet.size()));

    std::vector<uint8_t> responseBuffer(256);
    size_t received;

    try
    {
        received = socket->readBlocking(responseBuffer.data(), responseBuffer.size());
    }
    catch (std::exception& e)
    {
        std::cout << "Error during receiving reposnes from remote: " << e.what() << std::endl;
        return false;
    }

    ValidateChannelResponse response;
    if (!response.ParseFromArray(responseBuffer.data(), received))
    {
        std::cout << "Could not parse response" << std::endl;
    }

    socket->startReading();

    return response.result() == Result::VALIDATION_ACCEPTED;
}

void Channel::close()
{
    socket->disconnect();
}

void Channel::send(const socket::ISocket::DataPacket dataPacket)
{
    socket->send(dataPacket);
}

long Channel::getId() const
{
    return id;
}

void Channel::onReceived(const ISocket::DataPacket data)
{
    if (nullptr != listener.get())
    {
        listener->onReceived(*this, data);
    }
}

void Channel::onClosed()
{
    if (nullptr != listener.get())
    {
        listener->onClosed(*this);
    }
}
