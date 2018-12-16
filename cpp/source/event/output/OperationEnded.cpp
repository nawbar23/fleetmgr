#include "event/output/OperationEnded.hpp"

#include <sstream>
#include <iterator>

using namespace fm;
using namespace fm::event::output;

OperationEnded::OperationEnded(std::shared_ptr<std::vector<long>> _channels) :
    FacadeEvent(OPERATION_ENDED),
    channels(_channels)
{
}

const std::vector<long>& OperationEnded::getChannels() const
{
    return *channels;
}

std::string OperationEnded::toString() const
{
    std::ostringstream oss;
    oss << "[";
    if (!channels->empty())
    {
        std::copy(channels->begin(), channels->end()-1,
                  std::ostream_iterator<long>(oss, ","));
        oss << channels->back();
    }
    oss << "]";
    return "OPERATION_ENDED: ";
}
