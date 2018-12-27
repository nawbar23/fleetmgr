#ifndef FM_STATE_PILOT_CONNECTED_OPENINGCHANNELS_HPP
#define FM_STATE_PILOT_CONNECTED_OPENINGCHANNELS_HPP

#include "state/IState.hpp"

#include <vector>

namespace fm
{

namespace state
{

namespace pilot
{

namespace connected
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-27
 * Description:
 */
class OpeningChannels : public IState
{
public:
    OpeningChannels(IState&, const std::vector<com::fleetmgr::interfaces::ChannelRequest>&);

    std::unique_ptr<IState> start() override;

    std::string toString() const override;

    std::unique_ptr<IState> handleUserEvent(const event::input::user::UserEvent&) override;

    std::unique_ptr<IState> handleConnectionEvent(const event::input::connection::ConnectionEvent&) override;

private:
    std::unique_ptr<IState> handleMessage(const com::fleetmgr::interfaces::facade::control::ControlMessage&);

    std::vector<com::fleetmgr::interfaces::ChannelRequest> channelsToOpen;
};

} // connected

} // pilot

} // state

} // fm

#endif // FM_STATE_PILOT_CONNECTED_OPENINGCHANNELS_HPP