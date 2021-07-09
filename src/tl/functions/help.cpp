#include "tl/functions/help.h"

ConfigSimple::ConfigSimple(int date_, int expires_, std::vector<TLObject> rules_) {}

ConfigSimple ConfigSimple::read(Reader reader)
{
    int date_ = Int::read(reader);
    int expires_ = Int::read(reader);
    std::vector<TLObject> rules_ = Vector<TLObject>::read(reader);
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
template <class X>
GetConfig<X> GetConfig<X>::read(Reader reader)
{
    return GetConfig<X>();
}

template <class X>
std::string GetConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetNearestDc<X> GetNearestDc<X>::read(Reader reader)
{
    return GetNearestDc<X>();
}

template <class X>
std::string GetNearestDc<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetAppUpdate<X>::GetAppUpdate(std::string source_) {}

template <class X>
GetAppUpdate<X> GetAppUpdate<X>::read(Reader reader)
{
    std::string source_ = String::read(reader);
    return GetAppUpdate<X>(source_);
}

template <class X>
std::string GetAppUpdate<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(source);
    return buffer;
}
template <class X>
GetInviteText<X> GetInviteText<X>::read(Reader reader)
{
    return GetInviteText<X>();
}

template <class X>
std::string GetInviteText<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetSupport<X> GetSupport<X>::read(Reader reader)
{
    return GetSupport<X>();
}

template <class X>
std::string GetSupport<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetAppChangelog<X>::GetAppChangelog(std::string prev_app_version_) {}

template <class X>
GetAppChangelog<X> GetAppChangelog<X>::read(Reader reader)
{
    std::string prev_app_version_ = String::read(reader);
    return GetAppChangelog<X>(prev_app_version_);
}

template <class X>
std::string GetAppChangelog<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(prev_app_version);
    return buffer;
}

template <class X>
SetBotUpdatesStatus<X>::SetBotUpdatesStatus(int pending_updates_count_, std::string message_) {}

template <class X>
SetBotUpdatesStatus<X> SetBotUpdatesStatus<X>::read(Reader reader)
{
    int pending_updates_count_ = Int::read(reader);
    std::string message_ = String::read(reader);
    return SetBotUpdatesStatus<X>(pending_updates_count_, message_);
}

template <class X>
std::string SetBotUpdatesStatus<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pending_updates_count);
    buffer += String::write(message);
    return buffer;
}
template <class X>
GetCdnConfig<X> GetCdnConfig<X>::read(Reader reader)
{
    return GetCdnConfig<X>();
}

template <class X>
std::string GetCdnConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetRecentMeUrls<X>::GetRecentMeUrls(std::string referer_) {}

template <class X>
GetRecentMeUrls<X> GetRecentMeUrls<X>::read(Reader reader)
{
    std::string referer_ = String::read(reader);
    return GetRecentMeUrls<X>(referer_);
}

template <class X>
std::string GetRecentMeUrls<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(referer);
    return buffer;
}
template <class X>
GetTermsOfServiceUpdate<X> GetTermsOfServiceUpdate<X>::read(Reader reader)
{
    return GetTermsOfServiceUpdate<X>();
}

template <class X>
std::string GetTermsOfServiceUpdate<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
AcceptTermsOfService<X>::AcceptTermsOfService(TLObject id_) {}

template <class X>
AcceptTermsOfService<X> AcceptTermsOfService<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return AcceptTermsOfService<X>(id_);
}

template <class X>
std::string AcceptTermsOfService<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
GetDeepLinkInfo<X>::GetDeepLinkInfo(std::string path_) {}

template <class X>
GetDeepLinkInfo<X> GetDeepLinkInfo<X>::read(Reader reader)
{
    std::string path_ = String::read(reader);
    return GetDeepLinkInfo<X>(path_);
}

template <class X>
std::string GetDeepLinkInfo<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(path);
    return buffer;
}
template <class X>
GetAppConfig<X> GetAppConfig<X>::read(Reader reader)
{
    return GetAppConfig<X>();
}

template <class X>
std::string GetAppConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SaveAppLog<X>::SaveAppLog(std::vector<TLObject> events_) {}

template <class X>
SaveAppLog<X> SaveAppLog<X>::read(Reader reader)
{
    std::vector<TLObject> events_ = Vector<TLObject>::read(reader);
    return SaveAppLog<X>(events_);
}

template <class X>
std::string SaveAppLog<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(events);
    return buffer;
}

template <class X>
GetPassportConfig<X>::GetPassportConfig(int hash_) {}

template <class X>
GetPassportConfig<X> GetPassportConfig<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetPassportConfig<X>(hash_);
}

template <class X>
std::string GetPassportConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}
template <class X>
GetSupportName<X> GetSupportName<X>::read(Reader reader)
{
    return GetSupportName<X>();
}

template <class X>
std::string GetSupportName<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetUserInfo<X>::GetUserInfo(TLObject user_id_) {}

template <class X>
GetUserInfo<X> GetUserInfo<X>::read(Reader reader)
{
    TLObject user_id_ = TLObject::read(reader);
    return GetUserInfo<X>(user_id_);
}

template <class X>
std::string GetUserInfo<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    return buffer;
}

template <class X>
EditUserInfo<X>::EditUserInfo(TLObject user_id_, std::string message_, std::vector<TLObject> entities_) {}

template <class X>
EditUserInfo<X> EditUserInfo<X>::read(Reader reader)
{
    TLObject user_id_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    std::vector<TLObject> entities_ = Vector<TLObject>::read(reader);
    return EditUserInfo<X>(user_id_, message_, entities_);
}

template <class X>
std::string EditUserInfo<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += String::write(message);
    buffer += Vector<TLObject>::write(entities);
    return buffer;
}
template <class X>
GetPromoData<X> GetPromoData<X>::read(Reader reader)
{
    return GetPromoData<X>();
}

template <class X>
std::string GetPromoData<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
HidePromoData<X>::HidePromoData(TLObject peer_) {}

template <class X>
HidePromoData<X> HidePromoData<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return HidePromoData<X>(peer_);
}

template <class X>
std::string HidePromoData<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
DismissSuggestion<X>::DismissSuggestion(TLObject peer_, std::string suggestion_) {}

template <class X>
DismissSuggestion<X> DismissSuggestion<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string suggestion_ = String::read(reader);
    return DismissSuggestion<X>(peer_, suggestion_);
}

template <class X>
std::string DismissSuggestion<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(suggestion);
    return buffer;
}

template <class X>
GetCountriesList<X>::GetCountriesList(std::string lang_code_, int hash_) {}

template <class X>
GetCountriesList<X> GetCountriesList<X>::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetCountriesList<X>(lang_code_, hash_);
}

template <class X>
std::string GetCountriesList<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(hash);
    return buffer;
}
