#ifndef FM_ICLIENT_HPP
#define FM_ICLIENT_HPP

#include "event/input/IInputEvent.hpp"

#include "event/output/FacadeEvent.hpp"

#include "core/CoreClient.hpp"

#include "traffic/socket/ISocket.hpp"

#include "timer/ITimer.hpp"

#include "facade/control/facade_service.grpc.pb.h"
#include <grpc++/grpc++.h>

#include <memory>
#include <mutex>
#include <thread>
#include <atomic>

namespace fm
{

namespace state
{
    class IState;
}

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class IClient
{
public:
    class Listener
    {
    public:
        virtual ~Listener();

        virtual void onEvent(const std::shared_ptr<const event::output::FacadeEvent>) = 0;

        virtual void execute(std::function<void(void)>) = 0;

        virtual void trace(const std::string&) = 0;

        virtual std::shared_ptr<timer::ITimer> createTimer() = 0;

        virtual std::shared_ptr<traffic::socket::ISocket> createSocket(const traffic::socket::ISocket::Protocol) = 0;
    };

    virtual ~IClient();

    void notifyEvent(const std::shared_ptr<const event::input::IInputEvent>);

    void openFacadeConnection(const std::string&, const int);

    void closeFacadeConnection();

    void send(const com::fleetmgr::interfaces::facade::control::ClientMessage& message);

    // TODO Bartek argument should be changed to recursive template for optimization
    void trace(const std::string& message);

    virtual std::string toString() const = 0;

protected:
    IClient(std::unique_ptr<state::IState>, Listener&, const std::string&);

private:
    IClient() = delete;
    IClient(IClient&) = delete;

    Listener& listener;

    std::mutex stateLock;
    std::unique_ptr<state::IState> state;

    const std::string certPath;

    std::shared_ptr<grpc::Channel> channel;

    std::unique_ptr<
    com::fleetmgr::interfaces::facade::control::FacadeService::Stub> stub;

    grpc::ClientContext context;

    std::unique_ptr<grpc::ClientReaderWriter<
    com::fleetmgr::interfaces::facade::control::ClientMessage,
    com::fleetmgr::interfaces::facade::control::ControlMessage>> stream;

    std::atomic<bool> keepReader;
    std::thread reader;

    void readCert(const std::string&, std::string&);
};

} // fm

#endif // FM_IDEVICE_HPP
