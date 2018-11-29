#ifndef FM_PILOT_HPP
#define FM_PILOT_HPP

#include "IClient.hpp"

namespace fm
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Pilot : public IClient
{
public:
    Pilot(Listener&, https::IHttpsClient&);

    std::string toString() const override;
};

} // fm

#endif // FM_PILOT_HPP
