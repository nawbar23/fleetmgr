#ifndef FM_TRAFFIC_CHANNEL_HPP
#define FM_TRAFFIC_CHANNEL_HPP

#include "traffic/socket/ISocket.hpp"

#include <memory>
#include <string>

namespace fm
{

namespace traffic
{

/**
 * Created by: Bartosz Nawrot
 * Date: 2018-11-25
 * Description:
 */
class Channel
{
public:
    Channel(long, std::shared_ptr<socket::ISocket>);

    bool open(const std::string&, const int, const std::string&);

    void close();

    long getId() const;

private:
    const long id;
    std::shared_ptr<socket::ISocket> socket;
};

} // traffic

} // fm

#endif // FM_TRAFFIC_CHANNEL_HPP
