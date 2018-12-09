#include "event/output/Error.hpp"

using namespace fm;
using namespace fm::event::output;

Error::Error() :
    FacadeEvent(ERROR)
{
}

std::string Error::toString() const
{
    return "ERROR: ";
}
