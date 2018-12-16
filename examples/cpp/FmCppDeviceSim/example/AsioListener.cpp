#include "AsioListener.hpp"

#include "Timer.hpp"
#include "AsioTcpClient.hpp"
#include "AsioUdpClient.hpp"

#include <iostream>

using namespace fm;
using namespace fm::event;

using com::fleetmgr::interfaces::Location;

AsioListener::AsioListener(boost::asio::io_service& _ioService) :
    ioService(_ioService)
{
}

AsioListener::~AsioListener()
{
    timerThread.clear();
}

void AsioListener::onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event)
{
    trace("AsioListener::onEvent Emmited: " + event->toString());
}

void AsioListener::execute(std::function<void(void)> task)
{
    ioService.post(task);
}

void AsioListener::trace(const std::string& message)
{
    std::cout << "Client trace: [" << message << "]" << std::endl;
}

std::unique_ptr<Location> AsioListener::getLocation()
{
    std::unique_ptr<Location> location = std::make_unique<Location>();
    location->set_latitude(50.0);
    location->set_longitude(20.0);
    location->set_altitude(400.0);
    return location;
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
        return std::unique_ptr<AsioTcpClient>();

    case ISocket::UDP:
        return std::unique_ptr<AsioUdpClient>();
    }
}
