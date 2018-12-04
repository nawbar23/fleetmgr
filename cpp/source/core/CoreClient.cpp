#include "core/CoreClient.hpp"

using namespace fm;
using namespace fm::core;

using namespace com::fleetmgr::interfaces;

using namespace google::protobuf::util;

CoreClient::CoreClient(https::IHttpsClient& _client) :
    client(_client)
{
    options.ignore_unknown_fields = true;
}

AttachResponse CoreClient::attach()
{
    std::string responseString =
            client.execute("/gateway/devices/attach", https::IHttpsClient::POST, "");
    std::cout << "Attach response: " << responseString << std::endl;
    AttachResponse response;
    Status status = JsonStringToMessage(responseString, &response, options);
    if (Status::OK == status)
    {
        return response;
    }
    else
    {
        throw std::runtime_error("Could not parse response: " + responseString);
    }
}

OperateResponse CoreClient::operate(const OperateRequest& operateRequest)
{
    std::string body;
    MessageToJsonString(operateRequest, &body);
    std::string responseString =
            client.execute("/gateway/pilots/operate", https::IHttpsClient::POST, body);
    std::cout << "Operate response (" << body << "): " << responseString << std::endl;
    OperateResponse response;
    Status status = JsonStringToMessage(responseString, &response, options);
    if (Status::OK == status)
    {
        return response;
    }
    else
    {
        throw std::runtime_error("Could not parse response: " + responseString);
    }
}

ListDevicesResponse CoreClient::listDevices()
{
    std::string responseString =
            client.execute("/pilots", https::IHttpsClient::GET, "");
    std::cout << "List devices response: " << responseString << std::endl;
    ListDevicesResponse response;
    Status status = JsonStringToMessage(responseString, &response, options);
    if (Status::OK == status)
    {
        return response;
    }
    else
    {
        throw std::runtime_error("Could not parse response: " + responseString);
    }
}
