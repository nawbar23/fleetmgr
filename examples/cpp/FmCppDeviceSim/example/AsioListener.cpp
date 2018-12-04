#include "AsioListener.hpp"

#include "Timer.hpp"
#include "AsioTcpClient.hpp"
#include "AsioUdpClient.hpp"

#include <iostream>

using namespace fm;
using namespace fm::event;

AsioListener::AsioListener()
{
}

AsioListener::~AsioListener()
{
    timerThread.clear();
}

void AsioListener::onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event)
{
    trace("Emmited: " + event->toString());
}

void AsioListener::execute(std::function<void(void)> task)
{
    trace("Execution request");
    // TODO Bartek replace with approperiate executor, for example asio::io_service
    // TODO Bartek or something more proffesional like Shaen Parent style tasking system
    std::thread t([&task] () { task(); });
    t.detach();
}

void AsioListener::trace(const std::string& message)
{
    std::cout << "Client trace: [" << message << "]" << std::endl;
}

std::shared_ptr<fm::timer::ITimer> AsioListener::createTimer()
{
    std::cout << "AsioListener::createTimer" << std::endl;
    return std::make_shared<Timer>(timerThread);
}

std::shared_ptr<fm::traffic::socket::ISocket> AsioListener::createSocket(const fm::traffic::socket::ISocket::Protocol protocol)
{
    using fm::traffic::socket::ISocket;
    std::cout << "AsioListener::createSocket" << std::endl;
    switch (protocol)
    {
    case ISocket::TCP:
        return std::make_shared<AsioTcpClient>();

    case ISocket::UDP:
        return std::make_shared<AsioUdpClient>();
    }
}
