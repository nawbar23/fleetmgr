#include "backend/HeartbeatHandler.hpp"

#include "IClient.hpp"

using namespace fm;
using namespace fm::backend;

using namespace com::fleetmgr::interfaces::facade::control;


HeartbeatHandler::HeartbeatHandler(IClient& _client) :
    client(_client)
{
}

void HeartbeatHandler::start()
{

}

void HeartbeatHandler::end()
{

}

void HeartbeatHandler::handleHeartbeat(const com::fleetmgr::interfaces::facade::control::ControlMessage& message)
{

}

void HeartbeatHandler::onTimeout()
{

}
