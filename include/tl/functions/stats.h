#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetBroadcastStats
{
private:
    int __id = 0xab42441a;

public:
    std::optional<bool> dark;
    TLObject channel;
    GetBroadcastStats(TLObject channel_, std::optional<bool> dark_ = std::nullopt);
    static GetBroadcastStats<X> read(Reader reader);
    std::string write();
};

template <class X>
class LoadAsyncGraph
{
private:
    int __id = 0x621d5fa0;

public:
    std::string token;
    std::optional<long> x;
    LoadAsyncGraph(std::string token_, std::optional<long> x_ = std::nullopt);
    static LoadAsyncGraph<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMegagroupStats
{
private:
    int __id = 0xdcdf8607;

public:
    std::optional<bool> dark;
    TLObject channel;
    GetMegagroupStats(TLObject channel_, std::optional<bool> dark_ = std::nullopt);
    static GetMegagroupStats<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMessagePublicForwards
{
private:
    int __id = 0x5630281b;

public:
    TLObject channel;
    int msg_id;
    int offset_rate;
    TLObject offset_peer;
    int offset_id;
    int limit;
    GetMessagePublicForwards(TLObject channel_, int msg_id_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_);
    static GetMessagePublicForwards<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMessageStats
{
private:
    int __id = 0xb6e0a3f5;

public:
    std::optional<bool> dark;
    TLObject channel;
    int msg_id;
    GetMessageStats(TLObject channel_, int msg_id_, std::optional<bool> dark_ = std::nullopt);
    static GetMessageStats<X> read(Reader reader);
    std::string write();
};
