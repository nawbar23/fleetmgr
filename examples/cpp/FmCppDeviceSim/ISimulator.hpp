#ifndef ISIMULATOR_HPP
#define ISIMULATOR_HPP

#include "AsioHttpsClient.hpp"
#include "AsioListener.hpp"

#include "traffic/Channel.hpp"

#include "Device.hpp"

#include "event/output/ChannelsOpened.hpp"

#include <deque>
#include <mutex>

class ISimulator : public AsioListener
{
public:
    class ChannelListener : public fm::traffic::Channel::Listener
    {
    public:
        ChannelListener(std::unordered_map<long, std::shared_ptr<fm::traffic::Channel>>&, std::mutex&);

        void onReceived(fm::traffic::Channel&, const fm::traffic::socket::ISocket::DataPacket) override;

        void onClosed(fm::traffic::Channel&) override;

    private:
        std::unordered_map<long, std::shared_ptr<fm::traffic::Channel>>& channels;
        std::mutex& channelsLock;
    };

    ISimulator(boost::asio::io_service&);

    virtual ~ISimulator();

    bool isDone();

    void onEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) override;

protected:
    std::atomic<bool> done;

    virtual void handleEvent(const std::shared_ptr<const fm::event::output::FacadeEvent> event) = 0;

private:
    std::unordered_map<long, std::shared_ptr<fm::traffic::Channel>> channels;
    std::mutex channelsLock;

    std::thread trafficThread;

    void addChannels(const fm::event::output::ChannelsOpened&);

    void trafficSimulator();
};

#endif // ISIMULATOR_HPP
