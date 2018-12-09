#ifndef FM_PILOT_HPP
#define FM_PILOT_HPP

#include "IClient.hpp"

#include "core/list_devices.pb.h"

namespace fm
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Pilot : public IClient
{
public:
    Pilot(Listener&, core::https::IHttpsClient&, const std::string&);

    std::string toString() const override;

    com::fleetmgr::interfaces::ListDevicesResponse listDevices();

    com::fleetmgr::interfaces::ListDevicesResponse listConnectedDevices();
};

} // fm

#endif // FM_PILOT_HPP
