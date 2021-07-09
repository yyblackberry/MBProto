#pragma once
#include "transports/Transport.h"
#include "util.h"

class Abridged : public Transport
{
public:
    Abridged() = default;
    void start() override;
    std::string recv() override;
    void send(std::string buffer) override;
};

class Intermediate : public Transport
{
public:
    Intermediate() = default;
    void start();
    std::string recv();
    void send(std::string buffer);
};

class PaddedIntermediate : public Transport
{
public:
    PaddedIntermediate() = default;
    void start();
    std::string recv();
    void send(std::string buffer);
};

class Full : public Transport
{
public:
    Full() = default;
    void start();
    std::string recv();
    void send(std::string buffer);
};
