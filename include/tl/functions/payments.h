#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetPaymentForm
{
private:
    int __id = 0x8a333c8d;

public:
    TLObject peer;
    int msg_id;
    std::optional<TLObject> theme_params;
    GetPaymentForm(TLObject peer_, int msg_id_, std::optional<TLObject> theme_params_ = std::nullopt);
    static GetPaymentForm<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPaymentReceipt
{
private:
    int __id = 0x2478d1cc;

public:
    TLObject peer;
    int msg_id;
    GetPaymentReceipt(TLObject peer_, int msg_id_);
    static GetPaymentReceipt<X> read(Reader reader);
    std::string write();
};

template <class X>
class ValidateRequestedInfo
{
private:
    int __id = 0xdb103170;

public:
    std::optional<bool> save;
    TLObject peer;
    int msg_id;
    TLObject info;
    ValidateRequestedInfo(TLObject peer_, int msg_id_, TLObject info_, std::optional<bool> save_ = std::nullopt);
    static ValidateRequestedInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendPaymentForm
{
private:
    int __id = 0x30c3bc9d;

public:
    long form_id;
    TLObject peer;
    int msg_id;
    std::optional<std::string> requested_info_id;
    std::optional<std::string> shipping_option_id;
    TLObject credentials;
    std::optional<long> tip_amount;
    SendPaymentForm(long form_id_, TLObject peer_, int msg_id_, TLObject credentials_, std::optional<std::string> requested_info_id_ = std::nullopt, std::optional<std::string> shipping_option_id_ = std::nullopt, std::optional<long> tip_amount_ = std::nullopt);
    static SendPaymentForm<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSavedInfo
{
private:
    int __id = 0x227d824b;

public:
    GetSavedInfo() = default;
    static GetSavedInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class ClearSavedInfo
{
private:
    int __id = 0xd83d70c1;

public:
    std::optional<bool> credentials;
    std::optional<bool> info;
    ClearSavedInfo(std::optional<bool> credentials_ = std::nullopt, std::optional<bool> info_ = std::nullopt);
    static ClearSavedInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetBankCardData
{
private:
    int __id = 0x2e79d779;

public:
    std::string number;
    GetBankCardData(std::string number_);
    static GetBankCardData<X> read(Reader reader);
    std::string write();
};
