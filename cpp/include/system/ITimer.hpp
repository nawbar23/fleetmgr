#ifndef FM_SYSTEM_ITIMER_HPP
#define FM_SYSTEM_ITIMER_HPP

#include <functional>

namespace fm
{

namespace system
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class ITimer
{
public:
    typedef std::function<void(void)> Task;
    typedef size_t Milisec;

    virtual ~ITimer();

    virtual void callEvery(const Milisec, Task) = 0;
    virtual void callAfter(const Milisec, Task) = 0;

    virtual void kill() = 0;
};

} // system

} // fm

#endif // FM_SYSTEM_ITIMER_HPP
