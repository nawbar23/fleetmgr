#ifndef ASIOLISTENER_HPP
#define ASIOLISTENER_HPP

#include "IClient.hpp"

#include "event/output/FacadeEvent.hpp"

#include "TimerThread.hpp"

#include <boost/asio.hpp>

#include <memory>

class AsioListener : public fm::IClient::Listener
{
public:
    AsioListener(boost::asio::io_service&);

    ~AsioListener() override;

    bool isDone();

    virtual void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent>) override;

    void execute(std::function<void(void)>) override;

    void trace(const std::string&) override;

    std::unique_ptr<com::fleetmgr::interfaces::Location> getLocation() override;

    std::shared_ptr<fm::timer::ITimer> createTimer() override;

    std::shared_ptr<fm::traffic::socket::ISocket> createSocket(const fm::traffic::socket::ISocket::Protocol) override;

private:
    boost::asio::io_service& ioService;

    TimerThread timerThread;

    std::atomic<bool> done;
};

#endif // ASIOLISTENER_HPP
