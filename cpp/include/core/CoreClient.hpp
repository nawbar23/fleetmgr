#ifndef FM_CORE_CORECLIENT_HPP
#define FM_CORE_CORECLIENT_HPP

#include "../https/IHttpsClient.hpp"

namespace fm
{

namespace core {

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-29
 * Description:
 */
class CoreClient
{
public:
    CoreClient(https::IHttpsClient& _client);

    void attach();

    void operate();

    void listDevices();

private:
   https::IHttpsClient& client;
};

} // core

} // fm

#endif // FM_CORE_CORECLIENT_HPP
