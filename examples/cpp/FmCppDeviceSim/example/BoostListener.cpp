#include "BoostListener.hpp"

#include "Timer.hpp"
#include "BoostTcpSocket.hpp"
#include "BoostUdpSocket.hpp"

#include <iostream>

using namespace fm;
using namespace fm::event;

using com::fleetmgr::interfaces::Protocol;
using com::fleetmgr::interfaces::Location;

BoostListener::BoostListener(boost::asio::io_service& _ioService) :
    ioService(_ioService)
{
}

BoostListener::~BoostListener()
{
    timerThread.clear();
}

void BoostListener::onEvent(const std::shared_ptr<const output::FacadeEvent> event)
{
    trace("AsioListener::onEvent Emmited: " + event->toString());
}

void BoostListener::execute(std::function<void(void)> task)
{
    ioService.post(task);
}

void BoostListener::trace(const std::string& message)
{
    std::cout << "Client trace: [" << message << "]" << std::endl;
}

std::unique_ptr<Location> BoostListener::getLocation()
{
    std::unique_ptr<Location> location = std::make_unique<Location>();
    location->set_latitude(50.0);
    location->set_longitude(20.0);
    location->set_altitude(400.0);
    return location;
}

std::shared_ptr<fm::timer::ITimer> BoostListener::createTimer()
{
    //std::cout << "AsioListener::createTimer" << std::endl;
    return std::make_shared<Timer>(timerThread);
}

std::shared_ptr<fm::traffic::socket::ISocket> BoostListener::createSocket(const Protocol protocol)
{
    //std::cout << "AsioListener::createSocket" << std::endl;
    using traffic::socket::ISocket;
    switch (protocol)
    {
    case Protocol::TCP:
        return std::make_unique<BoostTcpSocket>(ioService);

    case Protocol::UDP:
        return std::make_unique<BoostUdpSocket>(ioService);

    default:
        throw std::runtime_error("Unexpected Protocol type");
    }
}
