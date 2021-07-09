#pragma once
#include "Storage.h"
#include "transports/TCP.h"

class Session
{
private:
    Storage __storage;
    Transport &__transport;

public:
    Session(
        std::string storage_name,
        int api_id,
        std::string api_key,
        std::string dc[2] = DC4,
        int port = 80,
        bool use_ipv6 = false,
        Transport transport = Abridged());
    void start();
    void stop();
};
