/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class ConfigSimple : public TLObject
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

class GetConfig : public TLObject
{
private:
    int __id = 0xc4f9186b;

public:
    GetConfig() = default;
    static GetConfig read(Reader reader);
    std::string write();
};

class GetNearestDc : public TLObject
{
private:
    int __id = 0x1fb33026;

public:
    GetNearestDc() = default;
    static GetNearestDc read(Reader reader);
    std::string write();
};

class GetAppUpdate : public TLObject
{
private:
    int __id = 0x522d5a7d;

public:
    std::string source;
    GetAppUpdate(std::string source_);
    static GetAppUpdate read(Reader reader);
    std::string write();
};

class GetInviteText : public TLObject
{
private:
    int __id = 0x4d392343;

public:
    GetInviteText() = default;
    static GetInviteText read(Reader reader);
    std::string write();
};

class GetSupport : public TLObject
{
private:
    int __id = 0x9cdf08cd;

public:
    GetSupport() = default;
    static GetSupport read(Reader reader);
    std::string write();
};

class GetAppChangelog : public TLObject
{
private:
    int __id = 0x9010ef6f;

public:
    std::string prev_app_version;
    GetAppChangelog(std::string prev_app_version_);
    static GetAppChangelog read(Reader reader);
    std::string write();
};

class SetBotUpdatesStatus : public TLObject
{
private:
    int __id = 0xec22cfcd;

public:
    int pending_updates_count;
    std::string message;
    SetBotUpdatesStatus(int pending_updates_count_, std::string message_);
    static SetBotUpdatesStatus read(Reader reader);
    std::string write();
};

class GetCdnConfig : public TLObject
{
private:
    int __id = 0x52029342;

public:
    GetCdnConfig() = default;
    static GetCdnConfig read(Reader reader);
    std::string write();
};

class GetRecentMeUrls : public TLObject
{
private:
    int __id = 0x3dc0f114;

public:
    std::string referer;
    GetRecentMeUrls(std::string referer_);
    static GetRecentMeUrls read(Reader reader);
    std::string write();
};

class GetTermsOfServiceUpdate : public TLObject
{
private:
    int __id = 0x2ca51fd1;

public:
    GetTermsOfServiceUpdate() = default;
    static GetTermsOfServiceUpdate read(Reader reader);
    std::string write();
};

class AcceptTermsOfService : public TLObject
{
private:
    int __id = 0xee72f79a;

public:
    TLObject id;
    AcceptTermsOfService(TLObject id_);
    static AcceptTermsOfService read(Reader reader);
    std::string write();
};

class GetDeepLinkInfo : public TLObject
{
private:
    int __id = 0x3fedc75f;

public:
    std::string path;
    GetDeepLinkInfo(std::string path_);
    static GetDeepLinkInfo read(Reader reader);
    std::string write();
};

class GetAppConfig : public TLObject
{
private:
    int __id = 0x98914110;

public:
    GetAppConfig() = default;
    static GetAppConfig read(Reader reader);
    std::string write();
};

class SaveAppLog : public TLObject
{
private:
    int __id = 0x6f02f748;

public:
    std::vector<TLObject> events;
    SaveAppLog(std::vector<TLObject> events_);
    static SaveAppLog read(Reader reader);
    std::string write();
};

class GetPassportConfig : public TLObject
{
private:
    int __id = 0xc661ad08;

public:
    int hash;
    GetPassportConfig(int hash_);
    static GetPassportConfig read(Reader reader);
    std::string write();
};

class GetSupportName : public TLObject
{
private:
    int __id = 0xd360e72c;

public:
    GetSupportName() = default;
    static GetSupportName read(Reader reader);
    std::string write();
};

class GetUserInfo : public TLObject
{
private:
    int __id = 0x38a08d3;

public:
    TLObject user_id;
    GetUserInfo(TLObject user_id_);
    static GetUserInfo read(Reader reader);
    std::string write();
};

class EditUserInfo : public TLObject
{
private:
    int __id = 0x66b91b70;

public:
    TLObject user_id;
    std::string message;
    std::vector<TLObject> entities;
    EditUserInfo(TLObject user_id_, std::string message_, std::vector<TLObject> entities_);
    static EditUserInfo read(Reader reader);
    std::string write();
};

class GetPromoData : public TLObject
{
private:
    int __id = 0xc0977421;

public:
    GetPromoData() = default;
    static GetPromoData read(Reader reader);
    std::string write();
};

class HidePromoData : public TLObject
{
private:
    int __id = 0x1e251c95;

public:
    TLObject peer;
    HidePromoData(TLObject peer_);
    static HidePromoData read(Reader reader);
    std::string write();
};

class DismissSuggestion : public TLObject
{
private:
    int __id = 0xf50dbaa1;

public:
    TLObject peer;
    std::string suggestion;
    DismissSuggestion(TLObject peer_, std::string suggestion_);
    static DismissSuggestion read(Reader reader);
    std::string write();
};

class GetCountriesList : public TLObject
{
private:
    int __id = 0x735787a8;

public:
    std::string lang_code;
    int hash;
    GetCountriesList(std::string lang_code_, int hash_);
    static GetCountriesList read(Reader reader);
    std::string write();
};
