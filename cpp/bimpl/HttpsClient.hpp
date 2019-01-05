#ifndef FM_BIMPL_HTTPSCLIENT_HPP
#define FM_BIMPL_HTTPSCLIENT_HPP

#include "core/https/IHttpsClient.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

namespace fm
{

namespace bimpl
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-01-05
 * Description:
 */
class HttpsClient : public fm::core::https::IHttpsClient
{
public:
    HttpsClient(const std::string&, const int, const std::string&);

    std::string execute(const std::string&, Method, const std::string&) override;
};

} // bimpl

} // fm

#endif // FM_BIMPL_HTTPSCLIENT_HPP
