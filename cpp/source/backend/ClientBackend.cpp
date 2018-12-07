#include "backend/ClientBackend.hpp"

#include "IClient.hpp"

using namespace fm;
using namespace fm::backend;


ClientBackend::ClientBackend(IClient& _client) :
    client(_client)
{
}
