#include "event/input/user/ReleaseAccepted.hpp"

using namespace fm;
using namespace fm::event::input::user;

ReleaseAccepted::ReleaseAccepted() :
    UserEvent(RELEASE_ACCEPTED)
{
}

std::string ReleaseAccepted::toString() const
{
    return "RELEASE_ACCEPTED: ";
}
