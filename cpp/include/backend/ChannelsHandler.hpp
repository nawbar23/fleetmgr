#ifndef FM_BACKEND_CHANNELSHANDLER_HPP
#define FM_BACKEND_CHANNELSHANDLER_HPP

#include "traffic/Channel.hpp"

#include "common/channel_management.pb.h"

#include <memory>
#include <vector>
#include <unordered_map>

namespace fm
{

namespace backend
{

class ClientBackend;

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-16
 * Description:
 */
class ChannelsHandler
{
public:
    ChannelsHandler(ClientBackend&);

    std::shared_ptr<std::vector<long>> getChannelIds() const;

    std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>> validateChannels(const std::vector<com::fleetmgr::interfaces::ChannelResponse>&);

    void closeChannels(const std::vector<long>&);

    void closeAllChannels();

private:
    ClientBackend& backend;

    std::unordered_map<long, std::shared_ptr<traffic::Channel>> channels;

    void trace(const std::string& message);
};

} // backend

} // fm

#endif // FM_BACKEND_CHANNELSHANDLER_HPP
