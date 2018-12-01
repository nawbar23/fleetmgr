#ifndef FM_ICLIENT_HPP
#define FM_ICLIENT_HPP

#include "event/input/UserEvent.hpp"
#include "event/output/FacadeEvent.hpp"

#include "state/IState.hpp"

#include "core/CoreClient.hpp"

#include "traffic/socket/ISocket.hpp"

#include "timer/ITimer.hpp"

#include <memory>
#include <mutex>

namespace fm
{

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

        virtual void onEvent(std::shared_ptr<const event::output::FacadeEvent>) = 0;

        virtual void execute(std::function<void(void)>) = 0;

        virtual void trace(const std::string&) = 0;

        virtual std::shared_ptr<timer::ITimer> createTimer() = 0;

        virtual std::shared_ptr<traffic::socket::ISocket> createSocket(const traffic::socket::ISocket::Protocol) = 0;
    };

    virtual ~IClient();

    void notifyEvent(std::shared_ptr<const event::input::UserEvent> );

    void start();

    virtual std::string toString() const = 0;

protected:
    IClient(std::unique_ptr<state::IState>, Listener&, core::https::IHttpsClient&);

private:
    IClient() = delete;
    IClient(IClient&) = delete;

    Listener& listener;

    core::CoreClient coreClient;

    std::mutex stateLock;
    std::unique_ptr<state::IState> state;
};

} // fm

#endif // FM_IDEVICE_HPP
