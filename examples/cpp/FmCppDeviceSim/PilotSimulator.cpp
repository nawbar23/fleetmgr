#include "PilotSimulator.hpp"

#include "core/list_devices.pb.h"

#include "event/input/user/Operate.hpp"

using namespace fm;
using namespace fm::event;

using fm::event::input::user::UserEvent;
using fm::event::input::user::Operate;
using fm::event::output::FacadeEvent;

using com::fleetmgr::interfaces::ListDevicesResponse;

PilotSimulator::PilotSimulator(boost::asio::io_service& ioService) :
    ISimulator(ioService),
    pilot(nullptr)
{
}

void PilotSimulator::start(AsioHttpsClient& core, const std::string& facadeCertPath)
{
    pilot = std::make_unique<fm::Pilot>(*this, core, facadeCertPath);
    ListDevicesResponse response = pilot->listConnectedDevices();
    if (response.devices_size() > 0)
    {
        long deviceId = response.devices(0).id();
        std::shared_ptr<std::vector<long>> channels = std::make_shared<std::vector<long>>(std::initializer_list<long>({1, 3, 8}));
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
        std::shared_ptr<UserEvent> e = std::make_shared<UserEvent>(UserEvent::RELEASE);
        execute([this, e] ()
        {
            pilot->notifyEvent(e);
        });
        break;
    }

    case FacadeEvent::ERROR:
    case FacadeEvent::RELEASED:
        done.store(true);
        break;
    }
}
