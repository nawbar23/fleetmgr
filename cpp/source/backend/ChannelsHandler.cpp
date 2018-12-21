#include "backend/ChannelsHandler.hpp"

#include "backend/ClientBackend.hpp"

using namespace fm;
using namespace fm::backend;

using namespace com::fleetmgr::interfaces;

ChannelsHandler::ChannelsHandler(ClientBackend& _backend) :
    backend(_backend)
{
}

std::shared_ptr<std::vector<traffic::IChannel*>> ChannelsHandler::getChannels()
{
    std::shared_ptr<std::vector<traffic::IChannel*>> result =
            std::make_shared<std::vector<traffic::IChannel*>>();
    result->reserve(channels.size());
    for (auto& pair : channels)
    {
        result->push_back(&(pair.second));
    }
    return result;
}

std::shared_ptr<std::vector<traffic::IChannel*>> ChannelsHandler::getChannels(const std::vector<long>& ids)
{
    std::shared_ptr<std::vector<traffic::IChannel*>> result =
            std::make_shared<std::vector<traffic::IChannel*>>();
    result->reserve(ids.size());
    for (long id : ids)
    {
        result->push_back(&channels.find(id)->second);
    }
    return result;
}

std::shared_ptr<std::vector<traffic::IChannel*>> ChannelsHandler::validateChannels(const std::vector<ChannelResponse>& toValidate)
{
    std::shared_ptr<std::vector<traffic::IChannel*>> result =
            std::make_shared<std::vector<traffic::IChannel*>>();
    for (const ChannelResponse& c : toValidate)
    {
        trace("Opening channel id: " + std::to_string(c.id()));
        std::shared_ptr<traffic::socket::ISocket> socket = backend.createSocket(Protocol::UDP);
        auto pair = channels.emplace(std::piecewise_construct,
                                     std::forward_as_tuple(c.id()),
                                     std::forward_as_tuple(c.id(), socket));
        traffic::ChannelImpl* channel = &pair.first->second;
        if (channel->open(c.host(), c.port(), c.key()))
        {
            trace("Channel id: " + std::to_string(c.id()) + " validated");
            result->push_back(channel);
        }
        else
        {
            channels.erase(c.id());
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
            c->second.close();
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
        pair.second.close();
    }
    channels.clear();
}

void ChannelsHandler::trace(const std::string& message)
{
    backend.trace(message);
}
