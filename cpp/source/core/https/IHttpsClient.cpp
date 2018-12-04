#include "core/https/IHttpsClient.hpp"

using namespace fm;
using namespace fm::core::https;

IHttpsClient::IHttpsClient(const std::string& _host, const int _port, const std::string& _apiKey) :
    host(_host),
    port(_port),
    apiKey(_apiKey)
{
}

IHttpsClient::~IHttpsClient()
{
}
