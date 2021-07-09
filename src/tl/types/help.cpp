#include "tl/types/help.h"

AppUpdate::AppUpdate(int id_, std::string version_, std::string text_, std::vector<TLObject> entities_, std::optional<bool> can_not_skip_, std::optional<TLObject> document_, std::optional<std::string> url_, std::optional<TLObject> sticker_) {}

AppUpdate AppUpdate::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_not_skip_;

    if (1 << 0)
        can_not_skip_ = true;
    else
        can_not_skip_ = std::nullopt;
    int id_ = Int::read(reader);
    std::string version_ = String::read(reader);
    std::string text_ = String::read(reader);
    std::vector<TLObject> entities_ = Vector<TLObject>::read(reader);
    std::optional<TLObject> document_;

    if (1 << 1)
        document_ = TLObject::read(reader);
    else
        document_ = std::nullopt;
    std::optional<std::string> url_;

    if (1 << 2)
        url_ = String::read(reader);
    else
        url_ = std::nullopt;
    std::optional<TLObject> sticker_;

    if (1 << 3)
        sticker_ = TLObject::read(reader);
    else
        sticker_ = std::nullopt;
    return AppUpdate(id_, version_, text_, entities_, can_not_skip_, document_, url_, sticker_);
}

std::string AppUpdate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_not_skip ? 1 << 0 : 0;
    flags |= document ? 1 << 1 : 0;
    flags |= url ? 1 << 2 : 0;
    flags |= sticker ? 1 << 3 : 0;
    buffer += Int::write(id);
    buffer += String::write(version);
    buffer += String::write(text);
    buffer += Vector<TLObject>::write(entities);

    if (document)
        buffer += document.value().write();

    if (url)
        buffer += String::write(url.value());

    if (sticker)
        buffer += sticker.value().write();
    return buffer;
}
NoAppUpdate NoAppUpdate::read(Reader reader)
{
    return NoAppUpdate();
}

std::string NoAppUpdate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InviteText::InviteText(std::string message_) {}

InviteText InviteText::read(Reader reader)
{
    std::string message_ = String::read(reader);
    return InviteText(message_);
}

std::string InviteText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(message);
    return buffer;
}

Support::Support(std::string phone_number_, TLObject user_) {}

Support Support::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    TLObject user_ = TLObject::read(reader);
    return Support(phone_number_, user_);
}

std::string Support::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += user.write();
    return buffer;
}

TermsOfService::TermsOfService(TLObject id_, std::string text_, std::vector<TLObject> entities_, std::optional<bool> popup_, std::optional<int> min_age_confirm_) {}

TermsOfService TermsOfService::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> popup_;

    if (1 << 0)
        popup_ = true;
    else
        popup_ = std::nullopt;
    TLObject id_ = TLObject::read(reader);
    std::string text_ = String::read(reader);
    std::vector<TLObject> entities_ = Vector<TLObject>::read(reader);
    std::optional<int> min_age_confirm_;

    if (1 << 1)
        min_age_confirm_ = Int::read(reader);
    else
        min_age_confirm_ = std::nullopt;
    return TermsOfService(id_, text_, entities_, popup_, min_age_confirm_);
}

std::string TermsOfService::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= popup ? 1 << 0 : 0;
    flags |= min_age_confirm ? 1 << 1 : 0;
    buffer += id.write();
    buffer += String::write(text);
    buffer += Vector<TLObject>::write(entities);

    if (min_age_confirm)
        buffer += Int::write(min_age_confirm.value());
    return buffer;
}

RecentMeUrls::RecentMeUrls(std::vector<TLObject> urls_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

RecentMeUrls RecentMeUrls::read(Reader reader)
{
    std::vector<TLObject> urls_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return RecentMeUrls(urls_, chats_, users_);
}

std::string RecentMeUrls::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(urls);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

TermsOfServiceUpdateEmpty::TermsOfServiceUpdateEmpty(int expires_) {}

TermsOfServiceUpdateEmpty TermsOfServiceUpdateEmpty::read(Reader reader)
{
    int expires_ = Int::read(reader);
    return TermsOfServiceUpdateEmpty(expires_);
}

std::string TermsOfServiceUpdateEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    return buffer;
}

TermsOfServiceUpdate::TermsOfServiceUpdate(int expires_, TLObject terms_of_service_) {}

TermsOfServiceUpdate TermsOfServiceUpdate::read(Reader reader)
{
    int expires_ = Int::read(reader);
    TLObject terms_of_service_ = TLObject::read(reader);
    return TermsOfServiceUpdate(expires_, terms_of_service_);
}

std::string TermsOfServiceUpdate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    buffer += terms_of_service.write();
    return buffer;
}
DeepLinkInfoEmpty DeepLinkInfoEmpty::read(Reader reader)
{
    return DeepLinkInfoEmpty();
}

std::string DeepLinkInfoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

DeepLinkInfo::DeepLinkInfo(std::string message_, std::optional<bool> update_app_, std::optional<std::vector<TLObject>> entities_) {}

DeepLinkInfo DeepLinkInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> update_app_;

    if (1 << 0)
        update_app_ = true;
    else
        update_app_ = std::nullopt;
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 1)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    return DeepLinkInfo(message_, update_app_, entities_);
}

std::string DeepLinkInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= update_app ? 1 << 0 : 0;
    flags |= entities ? 1 << 1 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    return buffer;
}
PassportConfigNotModified PassportConfigNotModified::read(Reader reader)
{
    return PassportConfigNotModified();
}

std::string PassportConfigNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

PassportConfig::PassportConfig(int hash_, TLObject countries_langs_) {}

PassportConfig PassportConfig::read(Reader reader)
{
    int hash_ = Int::read(reader);
    TLObject countries_langs_ = TLObject::read(reader);
    return PassportConfig(hash_, countries_langs_);
}

std::string PassportConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += countries_langs.write();
    return buffer;
}

SupportName::SupportName(std::string name_) {}

SupportName SupportName::read(Reader reader)
{
    std::string name_ = String::read(reader);
    return SupportName(name_);
}

std::string SupportName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(name);
    return buffer;
}
UserInfoEmpty UserInfoEmpty::read(Reader reader)
{
    return UserInfoEmpty();
}

std::string UserInfoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UserInfo::UserInfo(std::string message_, std::vector<TLObject> entities_, std::string author_, int date_) {}

UserInfo UserInfo::read(Reader reader)
{
    std::string message_ = String::read(reader);
    std::vector<TLObject> entities_ = Vector<TLObject>::read(reader);
    std::string author_ = String::read(reader);
    int date_ = Int::read(reader);
    return UserInfo(message_, entities_, author_, date_);
}

std::string UserInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(message);
    buffer += Vector<TLObject>::write(entities);
    buffer += String::write(author);
    buffer += Int::write(date);
    return buffer;
}

PromoDataEmpty::PromoDataEmpty(int expires_) {}

PromoDataEmpty PromoDataEmpty::read(Reader reader)
{
    int expires_ = Int::read(reader);
    return PromoDataEmpty(expires_);
}

std::string PromoDataEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    return buffer;
}

PromoData::PromoData(int expires_, TLObject peer_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> proxy_, std::optional<std::string> psa_type_, std::optional<std::string> psa_message_) {}

PromoData PromoData::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> proxy_;

    if (1 << 0)
        proxy_ = true;
    else
        proxy_ = std::nullopt;
    int expires_ = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    std::optional<std::string> psa_type_;

    if (1 << 1)
        psa_type_ = String::read(reader);
    else
        psa_type_ = std::nullopt;
    std::optional<std::string> psa_message_;

    if (1 << 2)
        psa_message_ = String::read(reader);
    else
        psa_message_ = std::nullopt;
    return PromoData(expires_, peer_, chats_, users_, proxy_, psa_type_, psa_message_);
}

std::string PromoData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= proxy ? 1 << 0 : 0;
    flags |= psa_type ? 1 << 1 : 0;
    flags |= psa_message ? 1 << 2 : 0;
    buffer += Int::write(expires);
    buffer += peer.write();
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);

    if (psa_type)
        buffer += String::write(psa_type.value());

    if (psa_message)
        buffer += String::write(psa_message.value());
    return buffer;
}

CountryCode::CountryCode(std::string country_code_, std::optional<std::vector<std::string>> prefixes_, std::optional<std::vector<std::string>> patterns_) {}

CountryCode CountryCode::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string country_code_ = String::read(reader);
    std::optional<std::vector<std::string>> prefixes_;

    if (1 << 0)
        prefixes_ = Vector<std::string>::read(reader);
    else
        prefixes_ = std::nullopt;
    std::optional<std::vector<std::string>> patterns_;

    if (1 << 1)
        patterns_ = Vector<std::string>::read(reader);
    else
        patterns_ = std::nullopt;
    return CountryCode(country_code_, prefixes_, patterns_);
}

std::string CountryCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= prefixes ? 1 << 0 : 0;
    flags |= patterns ? 1 << 1 : 0;
    buffer += String::write(country_code);

    if (prefixes)
        buffer += Vector<std::string>::write(prefixes.value());

    if (patterns)
        buffer += Vector<std::string>::write(patterns.value());
    return buffer;
}

Country::Country(std::string iso2_, std::string default_name_, TLObject country_codes_, std::optional<bool> hidden_, std::optional<std::string> name_) {}

Country Country::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> hidden_;

    if (1 << 0)
        hidden_ = true;
    else
        hidden_ = std::nullopt;
    std::string iso2_ = String::read(reader);
    std::string default_name_ = String::read(reader);
    std::optional<std::string> name_;

    if (1 << 1)
        name_ = String::read(reader);
    else
        name_ = std::nullopt;
    TLObject country_codes_ = TLObject::read(reader);
    return Country(iso2_, default_name_, country_codes_, hidden_, name_);
}

std::string Country::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= hidden ? 1 << 0 : 0;
    flags |= name ? 1 << 1 : 0;
    buffer += String::write(iso2);
    buffer += String::write(default_name);

    if (name)
        buffer += String::write(name.value());
    buffer += country_codes.write();
    return buffer;
}
CountriesListNotModified CountriesListNotModified::read(Reader reader)
{
    return CountriesListNotModified();
}

std::string CountriesListNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

CountriesList::CountriesList(TLObject countries_, int hash_) {}

CountriesList CountriesList::read(Reader reader)
{
    TLObject countries_ = TLObject::read(reader);
    int hash_ = Int::read(reader);
    return CountriesList(countries_, hash_);
}

std::string CountriesList::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += countries.write();
    buffer += Int::write(hash);
    return buffer;
}
