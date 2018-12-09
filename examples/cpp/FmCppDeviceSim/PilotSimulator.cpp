#include "PilotSimulator.hpp"

#include "event/input/user/UserEvent.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::output::FacadeEvent;

PilotSimulator::PilotSimulator() :
    pilot(nullptr)
{
}

void PilotSimulator::startImpl(AsioHttpsClient& core, const std::string& facadeCertPath)
{
    pilot = std::make_unique<fm::Pilot>(*this, core, facadeCertPath);
    pilot->notifyEvent(std::make_shared<const UserEvent>(UserEvent::OPERATE));
}

void PilotSimulator::handleEvent(const std::shared_ptr<const FacadeEvent> event)
{
    switch (event->getType())
    {
    case FacadeEvent::OPERATION_STARTED:
        pilot->notifyEvent(std::make_shared<UserEvent>(UserEvent::RELEASE));
        break;

    case FacadeEvent::ERROR:
    case FacadeEvent::RELEASED:
        done.store(true);
        break;
    }
}
