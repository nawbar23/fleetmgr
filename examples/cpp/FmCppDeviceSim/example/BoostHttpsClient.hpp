#ifndef BOOSTHTTPSCLIENT_HPP
#define BOOSTHTTPSCLIENT_HPP

#include "core/https/IHttpsClient.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class BoostHttpsClient : public fm::core::https::IHttpsClient
{
public:
    BoostHttpsClient(const std::string&, const int, const std::string&);

    std::string execute(const std::string&, Method, const std::string&) override;
};

#endif // BOOSTHTTPSCLIENT_HPP
