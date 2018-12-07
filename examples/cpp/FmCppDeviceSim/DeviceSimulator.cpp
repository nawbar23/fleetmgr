#include "DeviceSimulator.hpp"

#include "event/input/user/UserEvent.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::output::FacadeEvent;

DeviceSimulator::DeviceSimulator() :
    device(nullptr),
    done(false)
{
}

void DeviceSimulator::start(AsioHttpsClient& core, const std::string& facadeCertPath)
{
    device = std::make_unique<fm::Device>(*this, core, facadeCertPath);
    device->notifyEvent(std::make_shared<const UserEvent>(UserEvent::ATTACH));

    while (not done.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lock(queueLock);
        while (not eventQueue.empty())
        {
            handleEvent(eventQueue.front());
            eventQueue.pop_front();
        }
    }
}

bool DeviceSimulator::isDone()
{
    return done.load();
}

void DeviceSimulator::onEvent(const std::shared_ptr<const FacadeEvent> event)
{
    trace("DeviceSimulator::onEvent Emmited: " + event->toString());
    std::lock_guard<std::mutex> lock(queueLock);
    eventQueue.push_back(event);
}

void DeviceSimulator::handleEvent(const std::shared_ptr<const FacadeEvent> event)
{
    switch (event->getType())
    {
    case FacadeEvent::ATTACHED:
        device->notifyEvent(std::make_shared<UserEvent>(UserEvent::RELEASE));
        break;

    case FacadeEvent::ERROR:
    case FacadeEvent::RELEASED:
        done.store(true);
        break;
    }
}
