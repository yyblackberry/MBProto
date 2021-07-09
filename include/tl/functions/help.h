#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class ConfigSimple
{
private:
    int __id = 0x5a592a6c;

public:
    int date;
    int expires;
    std::vector<TLObject> rules;
    ConfigSimple(int date_, int expires_, std::vector<TLObject> rules_);
    static ConfigSimple read(Reader reader);
    std::string write();
};

template <class X>
class GetConfig
{
private:
    int __id = 0xc4f9186b;

public:
    GetConfig() = default;
    static GetConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetNearestDc
{
private:
    int __id = 0x1fb33026;

public:
    GetNearestDc() = default;
    static GetNearestDc<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAppUpdate
{
private:
    int __id = 0x522d5a7d;

public:
    std::string source;
    GetAppUpdate(std::string source_);
    static GetAppUpdate<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetInviteText
{
private:
    int __id = 0x4d392343;

public:
    GetInviteText() = default;
    static GetInviteText<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSupport
{
private:
    int __id = 0x9cdf08cd;

public:
    GetSupport() = default;
    static GetSupport<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAppChangelog
{
private:
    int __id = 0x9010ef6f;

public:
    std::string prev_app_version;
    GetAppChangelog(std::string prev_app_version_);
    static GetAppChangelog<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetBotUpdatesStatus
{
private:
    int __id = 0xec22cfcd;

public:
    int pending_updates_count;
    std::string message;
    SetBotUpdatesStatus(int pending_updates_count_, std::string message_);
    static SetBotUpdatesStatus<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetCdnConfig
{
private:
    int __id = 0x52029342;

public:
    GetCdnConfig() = default;
    static GetCdnConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetRecentMeUrls
{
private:
    int __id = 0x3dc0f114;

public:
    std::string referer;
    GetRecentMeUrls(std::string referer_);
    static GetRecentMeUrls<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetTermsOfServiceUpdate
{
private:
    int __id = 0x2ca51fd1;

public:
    GetTermsOfServiceUpdate() = default;
    static GetTermsOfServiceUpdate<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptTermsOfService
{
private:
    int __id = 0xee72f79a;

public:
    TLObject id;
    AcceptTermsOfService(TLObject id_);
    static AcceptTermsOfService<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDeepLinkInfo
{
private:
    int __id = 0x3fedc75f;

public:
    std::string path;
    GetDeepLinkInfo(std::string path_);
    static GetDeepLinkInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAppConfig
{
private:
    int __id = 0x98914110;

public:
    GetAppConfig() = default;
    static GetAppConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveAppLog
{
private:
    int __id = 0x6f02f748;

public:
    std::vector<TLObject> events;
    SaveAppLog(std::vector<TLObject> events_);
    static SaveAppLog<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPassportConfig
{
private:
    int __id = 0xc661ad08;

public:
    int hash;
    GetPassportConfig(int hash_);
    static GetPassportConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSupportName
{
private:
    int __id = 0xd360e72c;

public:
    GetSupportName() = default;
    static GetSupportName<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetUserInfo
{
private:
    int __id = 0x38a08d3;

public:
    TLObject user_id;
    GetUserInfo(TLObject user_id_);
    static GetUserInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditUserInfo
{
private:
    int __id = 0x66b91b70;

public:
    TLObject user_id;
    std::string message;
    std::vector<TLObject> entities;
    EditUserInfo(TLObject user_id_, std::string message_, std::vector<TLObject> entities_);
    static EditUserInfo<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPromoData
{
private:
    int __id = 0xc0977421;

public:
    GetPromoData() = default;
    static GetPromoData<X> read(Reader reader);
    std::string write();
};

template <class X>
class HidePromoData
{
private:
    int __id = 0x1e251c95;

public:
    TLObject peer;
    HidePromoData(TLObject peer_);
    static HidePromoData<X> read(Reader reader);
    std::string write();
};

template <class X>
class DismissSuggestion
{
private:
    int __id = 0xf50dbaa1;

public:
    TLObject peer;
    std::string suggestion;
    DismissSuggestion(TLObject peer_, std::string suggestion_);
    static DismissSuggestion<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetCountriesList
{
private:
    int __id = 0x735787a8;

public:
    std::string lang_code;
    int hash;
    GetCountriesList(std::string lang_code_, int hash_);
    static GetCountriesList<X> read(Reader reader);
    std::string write();
};
