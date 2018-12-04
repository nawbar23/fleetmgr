#ifndef FM_CORE_CORECLIENT_HPP
#define FM_CORE_CORECLIENT_HPP

#include "https/IHttpsClient.hpp"

#include "core/attach.pb.h"
#include "core/operate.pb.h"
#include "core/list_devices.pb.h"

namespace fm
{

namespace core
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-29
 * Description:
 */
class CoreClient
{
public:
    CoreClient(https::IHttpsClient& _client);

    com::fleetmgr::interfaces::AttachResponse attach();

    com::fleetmgr::interfaces::OperateResponse operate(const com::fleetmgr::interfaces::OperateRequest&);

    com::fleetmgr::interfaces::ListDevicesResponse listDevices();

private:
   https::IHttpsClient& client;
};

} // core

} // fm

#endif // FM_CORE_CORECLIENT_HPP
