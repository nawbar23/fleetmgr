#ifndef FM_BACKEND_CLIENTBACKEND_HPP
#define FM_BACKEND_CLIENTBACKEND_HPP

#include "IClient.hpp"

#include "traffic/Channel.hpp"

#include "core/CoreClient.hpp"

#include "backend/HeartbeatHandler.hpp"

#include "facade/control/facade_service.grpc.pb.h"
#include <grpc++/grpc++.h>

#include <memory>
#include <thread>

namespace fm
{

namespace backend
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-07
 * Description:
 */
class ClientBackend
{
public:
    ClientBackend(IClient&, IClient::Listener&, core::https::IHttpsClient&, const std::string&);

    core::CoreClient& getCore();

    HeartbeatHandler& getHeartbeatHandler();

    std::unique_ptr<com::fleetmgr::interfaces::Location> getLocation();

    void openFacadeConnection(const std::string&, const int);

    void closeFacadeConnection();

    void send(const com::fleetmgr::interfaces::facade::control::ClientMessage& message);

    std::unordered_map<long, traffic::Channel> validateChannels(const std::vector<com::fleetmgr::interfaces::Channel>&);

    void closeChannels(const std::vector<long>&);

    void closeAllChannels();

    // TODO Bartek argument should be changed to recursive template for optimization
    void trace(const std::string& message);

private:
    IClient& client;
    IClient::Listener& listener;
    
    core::CoreClient core;

    HeartbeatHandler heartbeatHandler;
    
    const std::string certPath;

    std::shared_ptr<grpc::Channel> channel;

    std::unique_ptr<
    com::fleetmgr::interfaces::facade::control::FacadeService::Stub> stub;

    grpc::ClientContext context;
    grpc::CompletionQueue completionQueue;

    void* readTag;
    std::shared_ptr<com::fleetmgr::interfaces::facade::control::ControlMessage> toRead;

    std::unique_ptr<grpc::ClientAsyncReaderWriter<
    com::fleetmgr::interfaces::facade::control::ClientMessage,
    com::fleetmgr::interfaces::facade::control::ControlMessage>> stream;

    std::atomic<bool> keepReader;

    void proceeReader();

    void readCert(const std::string&, std::string&);
};

} // backend

} // fm

#endif // FM_BACKEND_CLIENTBACKEND_HPP
