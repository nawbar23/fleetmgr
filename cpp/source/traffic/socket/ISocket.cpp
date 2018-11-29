#include "traffic/socket/ISocket.hpp"

using namespace fm::traffic::socket;

ISocket::~ISocket()
{
}

void ISocket::setListener(Listener* _listener)
{
    listener = _listener;
}
