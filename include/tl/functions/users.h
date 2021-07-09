#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetUsers
{
private:
    int __id = 0xd91a548;

public:
    std::vector<TLObject> id;
    GetUsers(std::vector<TLObject> id_);
    static GetUsers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFullUser
{
private:
    int __id = 0xca30a5b1;

public:
    TLObject id;
    GetFullUser(TLObject id_);
    static GetFullUser<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetSecureValueErrors
{
private:
    int __id = 0x90c894b5;

public:
    TLObject id;
    std::vector<TLObject> errors;
    SetSecureValueErrors(TLObject id_, std::vector<TLObject> errors_);
    static SetSecureValueErrors<X> read(Reader reader);
    std::string write();
};
