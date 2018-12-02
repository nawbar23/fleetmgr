#include "AsioHttpsClient.hpp"

#include <iostream>

AsioHttpsClient::AsioHttpsClient(std::string _coreAddress, std::string _apiKey, std::string _certPath) :
    fm::core::https::IHttpsClient(_coreAddress, _apiKey)
{

}

std::string AsioHttpsClient::execute(std::string, Method, std::string)
{

    return "";
}
