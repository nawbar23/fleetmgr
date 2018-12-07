#ifndef FM_BACKEND_CLIENTBACKEND_HPP
#define FM_BACKEND_CLIENTBACKEND_HPP

#include "IClient.hpp"

namespace fm
{

namespace backend
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-12-07
 * Description:
 */
class ClientBackend
{
public:
    ClientBackend(IClient&);

private:
    IClient& client;
};

} // backend

} // fm

#endif // FM_BACKEND_CLIENTBACKEND_HPP
