#ifndef FM_HTTPS_IHTTPSCLIENT_HPP
#define FM_HTTPS_IHTTPSCLIENT_HPP

#include <string>
#include <exception>

namespace fm
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

    IHttpsClient(std::string, std::string);

    virtual ~IHttpsClient();

    virtual std::string execute(std::string, Method, std::string) = 0;

protected:
    const std::string coreAddress;
    const std::string apiKey;
};

} // https

} // fm

#endif // FM_HTTPS_IHTTPSCLIENT_HPP
