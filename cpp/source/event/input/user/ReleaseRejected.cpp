#include "event/input/user/ReleaseRejected.hpp"

using namespace fm;
using namespace fm::event::input::user;

ReleaseRejected::ReleaseRejected() :
    UserEvent(RELEASE_REJECTED)
{
}

std::string ReleaseRejected::toString() const
{
    return "RELEASE_REJECTED: ";
}
