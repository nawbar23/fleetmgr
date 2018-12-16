#include "backend/ChannelsHandler.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::backend;

using namespace com::fleetmgr::interfaces;

ChannelsHandler::ChannelsHandler(ClientBackend& _backend) :
    backend(_backend)
{
}

std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>> ChannelsHandler::validateChannels(const std::vector<Channel>& toValidate)
{
    std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>> result =
            std::make_shared<std::vector<std::shared_ptr<traffic::Channel>>>();
    for (const Channel& c : toValidate)
    {
        trace("Opening channel id: " + std::to_string(c.id()));
        std::shared_ptr<traffic::socket::ISocket> socket = backend.createSocket(traffic::socket::ISocket::UDP);
        std::shared_ptr<traffic::Channel> channel = std::make_shared<traffic::Channel>(c.id(), socket);
        if (channel->open(c.ip(), c.port(), c.routekey()))
        {
            trace("Channel id: " + std::to_string(c.id()) + " validated");
            channels.insert({c.id(), channel});
            result->push_back(channel);
        }
    }
    return result;
}

void ChannelsHandler::closeChannels(const std::vector<long>& toClose)
{
    for (long id : toClose)
    {
        auto c = channels.find(id);
        if (c != channels.end())
        {
            trace("Closing channel, id: " + std::to_string(id));
            c->second->close();
            channels.erase(c);
        }
        else
        {
            trace("Warning, trying to close not existing channel, id: " + std::to_string(id));
        }
    }
}

void ChannelsHandler::closeAllChannels()
{
    for (auto& pair : channels)
    {
        trace("Closing channel, id: " + std::to_string(pair.first));
        pair.second->close();
    }
    channels.clear();
}

std::shared_ptr<std::vector<long>> ChannelsHandler::getChannelIds() const
{
    std::shared_ptr<std::vector<long>> result = std::make_shared<std::vector<long>>();
    result->reserve(channels.size());
    for (auto& pair : channels)
    {
        result->push_back(pair.first);
    }
    return result;
}

void ChannelsHandler::trace(const std::string& message)
{
    backend.trace(message);
}
