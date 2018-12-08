#ifndef FM_ICLIENT_HPP
#define FM_ICLIENT_HPP

#include "event/input/IInputEvent.hpp"

#include "event/output/FacadeEvent.hpp"

#include "core/CoreClient.hpp"

#include "traffic/socket/ISocket.hpp"

#include "timer/ITimer.hpp"

#include "common/location.pb.h"

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

namespace backend
{
    class ClientBackend;
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

        virtual void trace(const std::string&) = 0;

        virtual std::unique_ptr<com::fleetmgr::interfaces::Location> getLocation() = 0;

        virtual std::shared_ptr<timer::ITimer> createTimer() = 0;

        virtual std::shared_ptr<traffic::socket::ISocket> createSocket(const traffic::socket::ISocket::Protocol) = 0;
    };

    virtual ~IClient();

    void notifyEvent(const std::shared_ptr<const event::input::IInputEvent>);

    std::string getStateName() const;

    virtual std::string toString() const = 0;

protected:
    std::unique_ptr<backend::ClientBackend> backend;

    IClient(Listener&, core::https::IHttpsClient&, const std::string&);

    void setState(std::unique_ptr<state::IState>);

private:
    IClient() = delete;
    IClient(IClient&) = delete;

    Listener& listener;

    std::mutex stateLock;
    std::unique_ptr<state::IState> state;
};

} // fm

#endif // FM_IDEVICE_HPP
