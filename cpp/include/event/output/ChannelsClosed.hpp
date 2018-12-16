#ifndef FM_EVENT_OUTPUT_CHANNELSCLOSED_HPP
#define FM_EVENT_OUTPUT_CHANNELSCLOSED_HPP

#include "event/output/FacadeEvent.hpp"

#include <vector>
#include <memory>

namespace fm
{

namespace event
{

namespace output
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-09
 * Description:
 */
class ChannelsClosed : public FacadeEvent
{
public:
    ChannelsClosed(std::shared_ptr<std::vector<long>>);

    const std::vector<long>& getChannels() const;

    std::string toString() const;

private:
    std::shared_ptr<std::vector<long>> channels;
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_CHANNELSCLOSED_HPP
