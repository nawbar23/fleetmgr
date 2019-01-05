#ifndef FM_BIMPL_TIMER_HPP
#define FM_BIMPL_TIMER_HPP

#include "system/ITimer.hpp"

#include "TimerThread.hpp"

namespace fm
{

namespace bimpl
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-01-05
 * Description:
 */
class Timer : public system::ITimer
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

} // bimpl

} // fm

#endif // FM_BIMPL_TIMER_HPP
