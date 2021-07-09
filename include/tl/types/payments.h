#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class PaymentForm
{
private:
    int __id = 0x8d0b2415;

public:
    std::optional<bool> can_save_credentials;
    std::optional<bool> password_missing;
    long form_id;
    int bot_id;
    TLObject invoice;
    int provider_id;
    std::string url;
    std::optional<std::string> native_provider;
    std::optional<TLObject> native_params;
    std::optional<TLObject> saved_info;
    std::optional<TLObject> saved_credentials;
    std::vector<TLObject> users;
    PaymentForm(long form_id_, int bot_id_, TLObject invoice_, int provider_id_, std::string url_, std::vector<TLObject> users_, std::optional<bool> can_save_credentials_ = std::nullopt, std::optional<bool> password_missing_ = std::nullopt, std::optional<std::string> native_provider_ = std::nullopt, std::optional<TLObject> native_params_ = std::nullopt, std::optional<TLObject> saved_info_ = std::nullopt, std::optional<TLObject> saved_credentials_ = std::nullopt);
    static PaymentForm read(Reader reader);
    std::string write();
};

class ValidatedRequestedInfo
{
private:
    int __id = 0xd1451883;

public:
    std::optional<std::string> id;
    std::optional<std::vector<TLObject>> shipping_options;
    ValidatedRequestedInfo(std::optional<std::string> id_ = std::nullopt, std::optional<std::vector<TLObject>> shipping_options_ = std::nullopt);
    static ValidatedRequestedInfo read(Reader reader);
    std::string write();
};

class PaymentResult
{
private:
    int __id = 0x4e5f810d;

public:
    TLObject updates;
    PaymentResult(TLObject updates_);
    static PaymentResult read(Reader reader);
    std::string write();
};

class PaymentVerificationNeeded
{
private:
    int __id = 0xd8411139;

public:
    std::string url;
    PaymentVerificationNeeded(std::string url_);
    static PaymentVerificationNeeded read(Reader reader);
    std::string write();
};

class PaymentReceipt
{
private:
    int __id = 0x10b555d0;

public:
    int date;
    int bot_id;
    int provider_id;
    std::string title;
    std::string description;
    std::optional<TLObject> photo;
    TLObject invoice;
    std::optional<TLObject> info;
    std::optional<TLObject> shipping;
    std::optional<long> tip_amount;
    std::string currency;
    long total_amount;
    std::string credentials_title;
    std::vector<TLObject> users;
    PaymentReceipt(int date_, int bot_id_, int provider_id_, std::string title_, std::string description_, TLObject invoice_, std::string currency_, long total_amount_, std::string credentials_title_, std::vector<TLObject> users_, std::optional<TLObject> photo_ = std::nullopt, std::optional<TLObject> info_ = std::nullopt, std::optional<TLObject> shipping_ = std::nullopt, std::optional<long> tip_amount_ = std::nullopt);
    static PaymentReceipt read(Reader reader);
    std::string write();
};

class SavedInfo
{
private:
    int __id = 0xfb8fe43c;

public:
    std::optional<bool> has_saved_credentials;
    std::optional<TLObject> saved_info;
    SavedInfo(std::optional<bool> has_saved_credentials_ = std::nullopt, std::optional<TLObject> saved_info_ = std::nullopt);
    static SavedInfo read(Reader reader);
    std::string write();
};

class BankCardData
{
private:
    int __id = 0x3e24e573;

public:
    std::string title;
    std::vector<TLObject> open_urls;
    BankCardData(std::string title_, std::vector<TLObject> open_urls_);
    static BankCardData read(Reader reader);
    std::string write();
};
