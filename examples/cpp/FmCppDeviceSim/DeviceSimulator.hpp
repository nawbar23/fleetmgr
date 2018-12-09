#ifndef DEVICESIMULATOR_HPP
#define DEVICESIMULATOR_HPP

#include "ISimulator.hpp"

#include "Device.hpp"

class DeviceSimulator : public ISimulator
{
public:
    DeviceSimulator(boost::asio::io_service&);

private:
    std::unique_ptr<fm::Device> device;

    void startImpl(AsioHttpsClient&, const std::string&) override;

    void handleEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;
};

#endif // DEVICESIMULATOR_HPP
