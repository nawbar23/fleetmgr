#ifndef FM_BIMPL_LISTENER_HPP
#define FM_BIMPL_LISTENER_HPP

#include "IClient.hpp"

#include "event/output/FacadeEvent.hpp"

#include "TimerThread.hpp"

#include <boost/asio.hpp>

#include <memory>

namespace fm
{

namespace bimpl
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-01-05
 * Description:
 */
class Listener : public IClient::Listener
{
public:
    Listener(boost::asio::io_service&);

    ~Listener() override;

    bool isDone();

    virtual void onEvent(const std::shared_ptr<const event::output::FacadeEvent>) override;

    void execute(std::function<void(void)>) override;

    void trace(const std::string&) override;

    std::unique_ptr<com::fleetmgr::interfaces::Location> getLocation() override;

    std::shared_ptr<system::ITimer> createTimer() override;

    std::shared_ptr<traffic::socket::ISocket> createSocket(const com::fleetmgr::interfaces::Protocol) override;

private:
    boost::asio::io_service& ioService;

    TimerThread timerThread;

    std::atomic<bool> done;
};

} // bimpl

} // fm

#endif // FM_BIMPL_LISTENER_HPP
