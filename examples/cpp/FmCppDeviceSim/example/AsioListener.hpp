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

    void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;

    void execute(std::function<void(void)> task) override;

    void trace(const std::string& message) override;

    std::shared_ptr<fm::timer::ITimer> createTimer() override;

    std::shared_ptr<fm::traffic::socket::ISocket> createSocket(const fm::traffic::socket::ISocket::Protocol protocol) override;

private:
    TimerThread timerThread;
};

#endif // ASIOLISTENER_HPP
