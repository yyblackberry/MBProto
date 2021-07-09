#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class AppUpdate
{
private:
    int __id = 0xccbbce30;

public:
    std::optional<bool> can_not_skip;
    int id;
    std::string version;
    std::string text;
    std::vector<TLObject> entities;
    std::optional<TLObject> document;
    std::optional<std::string> url;
    std::optional<TLObject> sticker;
    AppUpdate(int id_, std::string version_, std::string text_, std::vector<TLObject> entities_, std::optional<bool> can_not_skip_ = std::nullopt, std::optional<TLObject> document_ = std::nullopt, std::optional<std::string> url_ = std::nullopt, std::optional<TLObject> sticker_ = std::nullopt);
    static AppUpdate read(Reader reader);
    std::string write();
};

class NoAppUpdate
{
private:
    int __id = 0xc45a6536;

public:
    NoAppUpdate() = default;
    static NoAppUpdate read(Reader reader);
    std::string write();
};

class InviteText
{
private:
    int __id = 0x18cb9f78;

public:
    std::string message;
    InviteText(std::string message_);
    static InviteText read(Reader reader);
    std::string write();
};

class Support
{
private:
    int __id = 0x17c6b5f6;

public:
    std::string phone_number;
    TLObject user;
    Support(std::string phone_number_, TLObject user_);
    static Support read(Reader reader);
    std::string write();
};

class TermsOfService
{
private:
    int __id = 0x780a0310;

public:
    std::optional<bool> popup;
    TLObject id;
    std::string text;
    std::vector<TLObject> entities;
    std::optional<int> min_age_confirm;
    TermsOfService(TLObject id_, std::string text_, std::vector<TLObject> entities_, std::optional<bool> popup_ = std::nullopt, std::optional<int> min_age_confirm_ = std::nullopt);
    static TermsOfService read(Reader reader);
    std::string write();
};

class RecentMeUrls
{
private:
    int __id = 0xe0310d7;

public:
    std::vector<TLObject> urls;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    RecentMeUrls(std::vector<TLObject> urls_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static RecentMeUrls read(Reader reader);
    std::string write();
};

class TermsOfServiceUpdateEmpty
{
private:
    int __id = 0xe3309f7f;

public:
    int expires;
    TermsOfServiceUpdateEmpty(int expires_);
    static TermsOfServiceUpdateEmpty read(Reader reader);
    std::string write();
};

class TermsOfServiceUpdate
{
private:
    int __id = 0x28ecf961;

public:
    int expires;
    TLObject terms_of_service;
    TermsOfServiceUpdate(int expires_, TLObject terms_of_service_);
    static TermsOfServiceUpdate read(Reader reader);
    std::string write();
};

class DeepLinkInfoEmpty
{
private:
    int __id = 0x66afa166;

public:
    DeepLinkInfoEmpty() = default;
    static DeepLinkInfoEmpty read(Reader reader);
    std::string write();
};

class DeepLinkInfo
{
private:
    int __id = 0x6a4ee832;

public:
    std::optional<bool> update_app;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    DeepLinkInfo(std::string message_, std::optional<bool> update_app_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static DeepLinkInfo read(Reader reader);
    std::string write();
};

class PassportConfigNotModified
{
private:
    int __id = 0xbfb9f457;

public:
    PassportConfigNotModified() = default;
    static PassportConfigNotModified read(Reader reader);
    std::string write();
};

class PassportConfig
{
private:
    int __id = 0xa098d6af;

public:
    int hash;
    TLObject countries_langs;
    PassportConfig(int hash_, TLObject countries_langs_);
    static PassportConfig read(Reader reader);
    std::string write();
};

class SupportName
{
private:
    int __id = 0x8c05f1c9;

public:
    std::string name;
    SupportName(std::string name_);
    static SupportName read(Reader reader);
    std::string write();
};

class UserInfoEmpty
{
private:
    int __id = 0xf3ae2eed;

public:
    UserInfoEmpty() = default;
    static UserInfoEmpty read(Reader reader);
    std::string write();
};

class UserInfo
{
private:
    int __id = 0x1eb3758;

public:
    std::string message;
    std::vector<TLObject> entities;
    std::string author;
    int date;
    UserInfo(std::string message_, std::vector<TLObject> entities_, std::string author_, int date_);
    static UserInfo read(Reader reader);
    std::string write();
};

class PromoDataEmpty
{
private:
    int __id = 0x98f6ac75;

public:
    int expires;
    PromoDataEmpty(int expires_);
    static PromoDataEmpty read(Reader reader);
    std::string write();
};

class PromoData
{
private:
    int __id = 0x8c39793f;

public:
    std::optional<bool> proxy;
    int expires;
    TLObject peer;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    std::optional<std::string> psa_type;
    std::optional<std::string> psa_message;
    PromoData(int expires_, TLObject peer_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> proxy_ = std::nullopt, std::optional<std::string> psa_type_ = std::nullopt, std::optional<std::string> psa_message_ = std::nullopt);
    static PromoData read(Reader reader);
    std::string write();
};

class CountryCode
{
private:
    int __id = 0x4203c5ef;

public:
    std::string country_code;
    std::optional<std::vector<std::string>> prefixes;
    std::optional<std::vector<std::string>> patterns;
    CountryCode(std::string country_code_, std::optional<std::vector<std::string>> prefixes_ = std::nullopt, std::optional<std::vector<std::string>> patterns_ = std::nullopt);
    static CountryCode read(Reader reader);
    std::string write();
};

class Country
{
private:
    int __id = 0xc3878e23;

public:
    std::optional<bool> hidden;
    std::string iso2;
    std::string default_name;
    std::optional<std::string> name;
    TLObject country_codes;
    Country(std::string iso2_, std::string default_name_, TLObject country_codes_, std::optional<bool> hidden_ = std::nullopt, std::optional<std::string> name_ = std::nullopt);
    static Country read(Reader reader);
    std::string write();
};

class CountriesListNotModified
{
private:
    int __id = 0x93cc1f32;

public:
    CountriesListNotModified() = default;
    static CountriesListNotModified read(Reader reader);
    std::string write();
};

class CountriesList
{
private:
    int __id = 0x87d0759e;

public:
    TLObject countries;
    int hash;
    CountriesList(TLObject countries_, int hash_);
    static CountriesList read(Reader reader);
    std::string write();
};
