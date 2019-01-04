#ifndef TIMER_HPP
#define TIMER_HPP

#include "system/ITimer.hpp"

#include "TimerThread.hpp"

class Timer : public fm::system::ITimer
{
public:
    Timer(TimerThread& _timerThread);

    ~Timer() override;

    void callEvery(const Milisec interval, Task task) override;
    void callAfter(const Milisec timeout, Task task) override;

    void kill() override;

private:
    TimerThread& timerThread;

    TimerThread::timer_id id;
    bool running;
};

#endif // TIMER_HPP
