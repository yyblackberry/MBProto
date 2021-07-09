#include "Session.h"

Session::Session(
    std::string storage_name,
    int api_id,
    std::string api_key,
    std::string dc[2],
    int port,
    bool use_ipv6,
    Transport transport) : __storage(storage_name), __transport(transport)
{
    __transport.setConnection(dc, port, use_ipv6);
}

void Session::start()
{
    __storage.start();
    __transport.start();
}

void Session::stop()
{
    __storage.stop();
    __transport.stop();
}
