#include "Listener.hpp"

#include "Timer.hpp"
#include "TcpSocket.hpp"
#include "UdpSocket.hpp"

#include <iostream>

using namespace fm;
using namespace fm::bimpl;
using namespace fm::event;

using com::fleetmgr::interfaces::Protocol;
using com::fleetmgr::interfaces::Location;

Listener::Listener(boost::asio::io_service& _ioService) :
    ioService(_ioService)
{
}

Listener::~Listener()
{
    timerThread.clear();
}

void Listener::onEvent(const std::shared_ptr<const output::FacadeEvent> event)
{
    trace("AsioListener::onEvent Emmited: " + event->toString());
}

void Listener::execute(std::function<void(void)> task)
{
    ioService.post(task);
}

void Listener::trace(const std::string& message)
{
    std::cout << "Client trace: [" << message << "]" << std::endl;
}

std::unique_ptr<Location> Listener::getLocation()
{
    std::unique_ptr<Location> location = std::make_unique<Location>();
    location->set_latitude(50.0);
    location->set_longitude(20.0);
    location->set_altitude(400.0);
    return location;
}

std::shared_ptr<fm::system::ITimer> Listener::createTimer()
{
    //std::cout << "AsioListener::createTimer" << std::endl;
    return std::make_shared<Timer>(timerThread);
}

std::shared_ptr<fm::traffic::socket::ISocket> Listener::createSocket(const Protocol protocol)
{
    //std::cout << "AsioListener::createSocket" << std::endl;
    using traffic::socket::ISocket;
    switch (protocol)
    {
    case Protocol::TCP:
        return std::make_unique<TcpSocket>(ioService);

    case Protocol::UDP:
        return std::make_unique<UdpSocket>(ioService);

    default:
        throw std::runtime_error("Unexpected Protocol type");
    }
}
