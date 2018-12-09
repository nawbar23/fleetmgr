#ifndef PILOTSIMULATOR_HPP
#define PILOTSIMULATOR_HPP

#include "ISimulator.hpp"

#include "Pilot.hpp"

class PilotSimulator : public ISimulator
{
public:
    PilotSimulator();

private:
    std::unique_ptr<fm::Pilot> pilot;

    void startImpl(AsioHttpsClient&, const std::string&) override;

    void handleEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;
};

#endif // PILOTSIMULATOR_HPP
