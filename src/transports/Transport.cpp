#include "transports/Transport.h"

void Transport::setConnection(std::string dc[2], int port, bool useIPv6)
{
    _connection = Connection(dc, port, useIPv6);
}

void Transport::stop()
{
    _connection.stop();
}
