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

#include "tl/functions/help.h"

ConfigSimple::ConfigSimple(int date_, int expires_, std::vector<TLObject> rules_) {}

ConfigSimple ConfigSimple::read(Reader reader)
{
    int date_ = Int::read(reader);
    int expires_ = Int::read(reader);
    std::vector<TLObject> rules_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ConfigSimple(date_, expires_, rules_);
}

std::string ConfigSimple::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(date);
    buffer += Int::write(expires);
    buffer += Vector<TLObject>::write(rules);
    return buffer;
}
GetConfig GetConfig::read(Reader reader)
{
    return GetConfig();
}

std::string GetConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetNearestDc GetNearestDc::read(Reader reader)
{
    return GetNearestDc();
}

std::string GetNearestDc::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetAppUpdate::GetAppUpdate(std::string source_) {}

GetAppUpdate GetAppUpdate::read(Reader reader)
{
    std::string source_ = String::read(reader);
    return GetAppUpdate(source_);
}

std::string GetAppUpdate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(source);
    return buffer;
}
GetInviteText GetInviteText::read(Reader reader)
{
    return GetInviteText();
}

std::string GetInviteText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetSupport GetSupport::read(Reader reader)
{
    return GetSupport();
}

std::string GetSupport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetAppChangelog::GetAppChangelog(std::string prev_app_version_) {}

GetAppChangelog GetAppChangelog::read(Reader reader)
{
    std::string prev_app_version_ = String::read(reader);
    return GetAppChangelog(prev_app_version_);
}

std::string GetAppChangelog::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(prev_app_version);
    return buffer;
}

SetBotUpdatesStatus::SetBotUpdatesStatus(int pending_updates_count_, std::string message_) {}

SetBotUpdatesStatus SetBotUpdatesStatus::read(Reader reader)
{
    int pending_updates_count_ = Int::read(reader);
    std::string message_ = String::read(reader);
    return SetBotUpdatesStatus(pending_updates_count_, message_);
}

std::string SetBotUpdatesStatus::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pending_updates_count);
    buffer += String::write(message);
    return buffer;
}
GetCdnConfig GetCdnConfig::read(Reader reader)
{
    return GetCdnConfig();
}

std::string GetCdnConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetRecentMeUrls::GetRecentMeUrls(std::string referer_) {}

GetRecentMeUrls GetRecentMeUrls::read(Reader reader)
{
    std::string referer_ = String::read(reader);
    return GetRecentMeUrls(referer_);
}

std::string GetRecentMeUrls::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(referer);
    return buffer;
}
GetTermsOfServiceUpdate GetTermsOfServiceUpdate::read(Reader reader)
{
    return GetTermsOfServiceUpdate();
}

std::string GetTermsOfServiceUpdate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

AcceptTermsOfService::AcceptTermsOfService(TLObject id_) {}

AcceptTermsOfService AcceptTermsOfService::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return AcceptTermsOfService(id_);
}

std::string AcceptTermsOfService::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

GetDeepLinkInfo::GetDeepLinkInfo(std::string path_) {}

GetDeepLinkInfo GetDeepLinkInfo::read(Reader reader)
{
    std::string path_ = String::read(reader);
    return GetDeepLinkInfo(path_);
}

std::string GetDeepLinkInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(path);
    return buffer;
}
GetAppConfig GetAppConfig::read(Reader reader)
{
    return GetAppConfig();
}

std::string GetAppConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SaveAppLog::SaveAppLog(std::vector<TLObject> events_) {}

SaveAppLog SaveAppLog::read(Reader reader)
{
    std::vector<TLObject> events_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SaveAppLog(events_);
}

std::string SaveAppLog::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(events);
    return buffer;
}

GetPassportConfig::GetPassportConfig(int hash_) {}

GetPassportConfig GetPassportConfig::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetPassportConfig(hash_);
}

std::string GetPassportConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}
GetSupportName GetSupportName::read(Reader reader)
{
    return GetSupportName();
}

std::string GetSupportName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetUserInfo::GetUserInfo(TLObject user_id_) {}

GetUserInfo GetUserInfo::read(Reader reader)
{
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return GetUserInfo(user_id_);
}

std::string GetUserInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    return buffer;
}

EditUserInfo::EditUserInfo(TLObject user_id_, std::string message_, std::vector<TLObject> entities_) {}

EditUserInfo EditUserInfo::read(Reader reader)
{
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    std::vector<TLObject> entities_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return EditUserInfo(user_id_, message_, entities_);
}

std::string EditUserInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += String::write(message);
    buffer += Vector<TLObject>::write(entities);
    return buffer;
}
GetPromoData GetPromoData::read(Reader reader)
{
    return GetPromoData();
}

std::string GetPromoData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

HidePromoData::HidePromoData(TLObject peer_) {}

HidePromoData HidePromoData::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return HidePromoData(peer_);
}

std::string HidePromoData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

DismissSuggestion::DismissSuggestion(TLObject peer_, std::string suggestion_) {}

DismissSuggestion DismissSuggestion::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string suggestion_ = String::read(reader);
    return DismissSuggestion(peer_, suggestion_);
}

std::string DismissSuggestion::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(suggestion);
    return buffer;
}

GetCountriesList::GetCountriesList(std::string lang_code_, int hash_) {}

GetCountriesList GetCountriesList::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetCountriesList(lang_code_, hash_);
}

std::string GetCountriesList::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(hash);
    return buffer;
}
