#include "ISimulator.hpp"

#include "event/input/user/UserEvent.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::output::FacadeEvent;

ISimulator::ISimulator(boost::asio::io_service& ioService) :
    AsioListener(ioService),
    done(false)
{
}

bool ISimulator::isDone()
{
    return done.load();
}

void ISimulator::onEvent(const std::shared_ptr<const FacadeEvent> event)
{
    trace("Handling FacadeEvent: " + event->toString());
    handleEvent(event);
}
