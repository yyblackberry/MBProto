#include "Client.h"

Client::Client(
    std::string storage_name,
    int api_id,
    std::string api_key,
    std::string dc[2],
    int port,
    bool use_ipv6,
    Transport transport) : __session(storage_name, api_id, api_key, dc, port, use_ipv6, transport) {}

void Client::start()
{
    __session.start();
}

void Client::stop()
{
    __session.stop();
}
