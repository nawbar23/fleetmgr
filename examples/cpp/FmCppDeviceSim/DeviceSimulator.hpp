#ifndef DEVICESIMULATOR_HPP
#define DEVICESIMULATOR_HPP

#include "AsioHttpsClient.hpp"
#include "AsioListener.hpp"

#include "Device.hpp"

class DeviceSimulator : public AsioListener
{
public:
    DeviceSimulator();

    void start(AsioHttpsClient&, const std::string&);

    bool isDone();

    void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;

private:
    std::unique_ptr<fm::Device> device;

    std::atomic<bool> done;
};

#endif // DEVICESIMULATOR_HPP
