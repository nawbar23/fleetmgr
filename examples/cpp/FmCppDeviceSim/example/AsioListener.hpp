#ifndef ASIOLISTENER_HPP
#define ASIOLISTENER_HPP

#include "IClient.hpp"

#include "event/output/FacadeEvent.hpp"

#include "AsioTcpClient.hpp"
#include "AsioUdpClient.hpp"

#include "TimerThread.hpp"

#include <memory>

class AsioListener : public fm::IClient::Listener
{
public:
    AsioListener();

    ~AsioListener() override;

    bool isDone();

    virtual void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;

    void trace(const std::string& message) override;

    std::unique_ptr<com::fleetmgr::interfaces::Location> getLocation() override;

    std::shared_ptr<fm::timer::ITimer> createTimer() override;

    std::shared_ptr<fm::traffic::socket::ISocket> createSocket(const fm::traffic::socket::ISocket::Protocol protocol) override;

private:
    TimerThread timerThread;

    std::atomic<bool> done;
};

#endif // ASIOLISTENER_HPP
