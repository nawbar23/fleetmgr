#include "event/input/user/Operate.hpp"

using namespace fm;
using namespace fm::event::input::user;

Operate::Operate() :
    UserEvent(OPERATE)
{
}

std::string Operate::toString() const
{
    return "OPERATE: ";
}
