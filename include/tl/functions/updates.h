#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetState
{
private:
    int __id = 0xedd4882a;

public:
    GetState() = default;
    static GetState<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDifference
{
private:
    int __id = 0x25939651;

public:
    int pts;
    std::optional<int> pts_total_limit;
    int date;
    int qts;
    GetDifference(int pts_, int date_, int qts_, std::optional<int> pts_total_limit_ = std::nullopt);
    static GetDifference<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetChannelDifference
{
private:
    int __id = 0x3173d78;

public:
    std::optional<bool> force;
    TLObject channel;
    TLObject filter;
    int pts;
    int limit;
    GetChannelDifference(TLObject channel_, TLObject filter_, int pts_, int limit_, std::optional<bool> force_ = std::nullopt);
    static GetChannelDifference<X> read(Reader reader);
    std::string write();
};
