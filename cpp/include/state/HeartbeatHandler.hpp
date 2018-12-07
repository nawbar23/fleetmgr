#ifndef FM_STATE_HEARTBEATHANDLER_HPP
#define FM_STATE_HEARTBEATHANDLER_HPP

#include "IClient.hpp"

#include "facade/control/facade_service.pb.h"

namespace fm
{

namespace state
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

} // state

} // fm

#endif // FM_STATE_HEARTBEATHANDLER_HPP
