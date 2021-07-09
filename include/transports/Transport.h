#pragma once
#include "Connection.h"

class Transport
{
protected:
    Connection _connection;

public:
    Transport() = default;
    void setConnection(std::string dc[2] = DC4, int port = 80, bool useIPv6 = false);
    virtual void start() = 0;
    virtual std::string recv() = 0;
    virtual void send(std::string buffer) = 0;
    void stop();
};
