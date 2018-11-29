#include "https/IHttpsClient.hpp"

using namespace fm;
using namespace fm::https;

IHttpsClient::IHttpsClient(std::string _coreAddress, std::string _apiKey) :
    coreAddress(_coreAddress), apiKey(_apiKey)
{
}

IHttpsClient::~IHttpsClient()
{
}
