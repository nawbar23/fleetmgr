#ifndef FM_EVENT_OUTPUT_CHANNELSOPENED_HPP
#define FM_EVENT_OUTPUT_CHANNELSOPENED_HPP

#include "event/output/FacadeEvent.hpp"

#include "traffic/IChannel.hpp"

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
class ChannelsOpened : public FacadeEvent
{
public:
    ChannelsOpened(std::shared_ptr<std::vector<std::shared_ptr<traffic::IChannel>>>);

    const std::vector<std::shared_ptr<traffic::IChannel>>& getChannels() const;

    std::string toString() const;

private:
    std::shared_ptr<std::vector<std::shared_ptr<traffic::IChannel>>> channels;
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_CHANNELSOPENED_HPP
