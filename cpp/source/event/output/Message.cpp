#include "event/output/Message.hpp"

using namespace fm;
using namespace fm::event::output;

Message::Message() :
    FacadeEvent(MESSAGE)
{
}

std::string Message::toString() const
{
    return "MESSAGE: ";
}
