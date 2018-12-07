#ifndef FM_BACKEND_HEARTBEATHANDLER_HPP
#define FM_BACKEND_HEARTBEATHANDLER_HPP

#include "IClient.hpp"

#include "facade/control/facade_service.pb.h"

namespace fm
{

namespace backend
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-07
 * Description:
 */
class HeartbeatHandler
{
public:
    HeartbeatHandler(IClient&);

    void start();

    void end();

    void handleHeartbeat(const com::fleetmgr::interfaces::facade::control::ControlMessage&);

private:
    IClient& client;

    void onTimeout();
};

} // backend

} // fm

#endif // FM_BACKEND_HEARTBEATHANDLER_HPP
