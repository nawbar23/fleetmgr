#include "ISimulator.hpp"

#include "event/input/user/UserEvent.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::output::FacadeEvent;

ISimulator::ISimulator() :
    done(false)
{
}

void ISimulator::start(AsioHttpsClient& core, const std::string& facadeCertPath)
{
    startImpl(core, facadeCertPath);

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

bool ISimulator::isDone()
{
    return done.load();
}

void ISimulator::onEvent(const std::shared_ptr<const FacadeEvent> event)
{
    trace("DeviceSimulator::onEvent Emmited: " + event->toString());
    std::lock_guard<std::mutex> lock(queueLock);
    eventQueue.push_back(event);
}
