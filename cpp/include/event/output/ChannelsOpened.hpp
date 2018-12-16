#ifndef FM_EVENT_OUTPUT_CHANNELSOPENED_HPP
#define FM_EVENT_OUTPUT_CHANNELSOPENED_HPP

#include "event/output/FacadeEvent.hpp"

#include "traffic/Channel.hpp"

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
    ChannelsOpened(std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>>);

    const std::vector<std::shared_ptr<traffic::Channel>>& getChannels() const;

    std::string toString() const;

private:
    std::shared_ptr<std::vector<std::shared_ptr<traffic::Channel>>> channels;
};

} // output

} // event

} // fm

#endif // FM_EVENT_OUTPUT_CHANNELSOPENED_HPP
