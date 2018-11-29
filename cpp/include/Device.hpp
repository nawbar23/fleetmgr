#ifndef FM_DEVICE_HPP
#define FM_DEVICE_HPP

#include "IClient.hpp"

namespace fm
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Device : public IClient
{
public:
    Device(Listener&, https::IHttpsClient&);

    std::string toString() const override;
};

} // fm

#endif // FM_DEVICE_HPP
