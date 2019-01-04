#include "IClient.hpp"

#include "event/input/connection/Received.hpp"

#include "state/IState.hpp"
#include "backend/ClientBackend.hpp"

#include <memory>
#include <fstream>
#include <sstream>

using namespace fm;

IClient::Listener::~Listener()
{
}

IClient::~IClient()
{
}

void IClient::trace(const std::string& message)
{
    listener.trace(message);
}

IClient::IClient(Listener& _listener, core::https::IHttpsClient& coreClient, const std::string& _certPath) :
    IStateMachine([&_listener] (const std::string& msg)
{
    _listener.trace(msg);
}),
    backend(std::make_unique<backend::ClientBackend>(*this, _listener, coreClient, _certPath)),
    listener(_listener)
{
}

void IClient::execute(Task task)
{
    listener.execute(task);
}
