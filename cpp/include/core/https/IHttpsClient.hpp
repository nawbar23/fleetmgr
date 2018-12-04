#ifndef FM_CORE_HTTPS_IHTTPSCLIENT_HPP
#define FM_CORE_HTTPS_IHTTPSCLIENT_HPP

#include <string>
#include <exception>

namespace fm
{

namespace core
{

namespace https {

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-27
 * Description:
 */
class IHttpsClient
{
public:
    enum Method
    {
        POST,
        PUT,
        GET,
        DELETE,
    };

    IHttpsClient(const std::string&, const int, const std::string&);

    virtual ~IHttpsClient();

    virtual std::string execute(const std::string&, const Method, const std::string&) = 0;

protected:
    const std::string host;
    const int port;

    const std::string apiKey;
};

} // https

} // core

} // fm

#endif // FM_CORE_HTTPS_IHTTPSCLIENT_HPP
