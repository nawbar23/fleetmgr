#include "core/CoreClient.hpp"

using namespace fm;
using namespace fm::core;

using namespace com::fleetmgr::interfaces;

CoreClient::CoreClient(https::IHttpsClient& _client) :
    client(_client)
{
}

AttachResponse CoreClient::attach()
{
    std::string responseString = client.execute("/gateway/devices/attach", https::IHttpsClient::POST, "");
    AttachResponse response;
    return response;
}

OperateResponse CoreClient::operate(const OperateRequest& operateRequest)
{
    std::string responseString = client.execute("/gateway/pilots/operate", https::IHttpsClient::POST, "");
    OperateResponse response;
    return response;
}

ListDevicesResponse CoreClient::listDevices()
{
    std::string responseString = client.execute("/pilots", https::IHttpsClient::GET, "");
    ListDevicesResponse response;
    return response;
}
