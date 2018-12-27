#include "PilotSimulator.hpp"

#include "core/list_devices.pb.h"

#include "event/input/user/Operate.hpp"

using namespace fm;
using namespace fm::event;

using namespace com::fleetmgr::interfaces;

using fm::event::input::user::UserEvent;
using fm::event::input::user::Operate;
using fm::event::output::FacadeEvent;

PilotSimulator::PilotSimulator(boost::asio::io_service& ioService) :
    ISimulator(ioService),
    pilot(nullptr)
{
}

void PilotSimulator::start(BoostHttpsClient& core, const std::string& facadeCertPath)
{
    pilot = std::make_unique<fm::Pilot>(*this, core, facadeCertPath);
    ListDevicesResponse response = pilot->listConnectedDevices();
    if (response.devices_size() > 0)
    {
        long deviceId = response.devices(0).id();
        std::vector<ChannelRequest> channels;
        ChannelRequest channelsReq;
        channelsReq.set_id(1);
        channelsReq.set_protocol(Protocol::UDP);
        channelsReq.set_priority(Priority::NEAR_REAL_TIME);
        channels.push_back(channelsReq);
        channelsReq.set_id(8);
        channels.push_back(channelsReq);
        channelsReq.set_id(11);
        channels.push_back(channelsReq);
        std::shared_ptr<const Operate> o = std::make_shared<const Operate>(deviceId, channels);
        execute([this, o] ()
        {
            pilot->notifyEvent(o);
        });
    }
    else
    {
        throw std::runtime_error("No device to connect");
    }
}

void PilotSimulator::handleEvent(const std::shared_ptr<const FacadeEvent> event)
{
    switch (event->getType())
    {
    case FacadeEvent::CHANNELS_OPENED:
    {
        std::thread t([this] ()
        {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            execute([this] ()
            {
                pilot->notifyEvent(std::make_shared<UserEvent>(UserEvent::RELEASE));
            });
        });
        t.detach();
        break;
    }

    case FacadeEvent::ERROR:
    case FacadeEvent::RELEASED:
        done.store(true);
        break;
    }
}
