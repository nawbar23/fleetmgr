#include "backend/ChannelsHandler.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::backend;

using namespace com::fleetmgr::interfaces;

ChannelsHandler::ChannelsHandler(ClientBackend& _backend) :
    backend(_backend)
{
}

std::shared_ptr<std::vector<std::shared_ptr<traffic::ChannelImpl>>> ChannelsHandler::validateChannels(const std::vector<ChannelResponse>& toValidate)
{
    std::shared_ptr<std::vector<std::shared_ptr<traffic::ChannelImpl>>> result =
            std::make_shared<std::vector<std::shared_ptr<traffic::ChannelImpl>>>();
    for (const ChannelResponse& c : toValidate)
    {
        trace("Opening channel id: " + std::to_string(c.id()));
        std::shared_ptr<traffic::socket::ISocket> socket = backend.createSocket(Protocol::UDP);
        std::shared_ptr<traffic::ChannelImpl> channel = std::make_shared<traffic::ChannelImpl>(c.id(), socket);
        if (channel->open(c.host(), c.port(), c.key()))
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
