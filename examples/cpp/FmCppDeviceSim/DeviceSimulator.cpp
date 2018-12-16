#include "DeviceSimulator.hpp"

#include "event/input/user/UserEvent.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::output::FacadeEvent;

DeviceSimulator::DeviceSimulator(boost::asio::io_service& ioService) :
    ISimulator(ioService),
    device(nullptr)
{
}

void DeviceSimulator::start(AsioHttpsClient& core, const std::string& facadeCertPath)
{
    device = std::make_unique<fm::Device>(*this, core, facadeCertPath);
    execute([this] ()
    {
        device->notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));
    });
}

void DeviceSimulator::handleEvent(const std::shared_ptr<const FacadeEvent> event)
{
    switch (event->getType())
    {
    case FacadeEvent::OPERATION_ENDED:
        execute([this] ()
        {
            device->notifyEvent(std::make_shared<UserEvent>(UserEvent::RELEASE));
        });
        break;

    case FacadeEvent::ERROR:
    case FacadeEvent::RELEASED:
        done.store(true);
        break;
    }
}
