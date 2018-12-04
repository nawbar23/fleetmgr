#ifndef ASIOHTTPSCLIENT_HPP
#define ASIOHTTPSCLIENT_HPP

#include "core/https/IHttpsClient.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class AsioHttpsClient : public fm::core::https::IHttpsClient
{
public:
    AsioHttpsClient(const std::string&, const int, const std::string&);

    std::string execute(const std::string&, Method, const std::string&) override;
};

#endif // ASIOHTTPSCLIENT_HPP
