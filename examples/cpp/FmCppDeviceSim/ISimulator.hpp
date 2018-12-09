#ifndef ISIMULATOR_HPP
#define ISIMULATOR_HPP

#include "AsioHttpsClient.hpp"
#include "AsioListener.hpp"

#include "Device.hpp"

#include <deque>
#include <mutex>

class ISimulator : public AsioListener
{
public:
    ISimulator();

    void start(AsioHttpsClient&, const std::string&);

    bool isDone();

    void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;

protected:
    std::atomic<bool> done;

    virtual void startImpl(AsioHttpsClient&, const std::string&) = 0;

    virtual void handleEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) = 0;

private:
    std::mutex queueLock;
    std::deque<std::shared_ptr<const fm::event::output::FacadeEvent>> eventQueue;
};

#endif // ISIMULATOR_HPP
