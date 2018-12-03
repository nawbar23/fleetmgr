#ifndef ASIOHTTPSCLIENT_HPP
#define ASIOHTTPSCLIENT_HPP

#include "core/https/IHttpsClient.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class AsioHttpsClient : public fm::core::https::IHttpsClient
{
public:
    AsioHttpsClient(std::string _coreAddress, std::string _apiKey, std::string _certPath);

    std::string execute(std::string path, Method method, std::string body) override;

private:
};

#endif // ASIOHTTPSCLIENT_HPP
