#ifndef PILOTSIMULATOR_HPP
#define PILOTSIMULATOR_HPP

#include "ISimulator.hpp"

#include "Pilot.hpp"

class PilotSimulator : public ISimulator
{
public:
    PilotSimulator(boost::asio::io_service&);

    void start(AsioHttpsClient&, const std::string&);

private:
    std::unique_ptr<fm::Pilot> pilot;

    void handleEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;
};

#endif // PILOTSIMULATOR_HPP
