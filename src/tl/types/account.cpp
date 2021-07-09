#include "tl/types/account.h"

PrivacyRules::PrivacyRules(std::vector<TLObject> rules_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

PrivacyRules PrivacyRules::read(Reader reader)
{
    std::vector<TLObject> rules_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return PrivacyRules(rules_, chats_, users_);
}

std::string PrivacyRules::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(rules);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

Authorizations::Authorizations(std::vector<TLObject> authorizations_) {}

Authorizations Authorizations::read(Reader reader)
{
    std::vector<TLObject> authorizations_ = Vector<TLObject>::read(reader);
    return Authorizations(authorizations_);
}

std::string Authorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(authorizations);
    return buffer;
}

Password::Password(TLObject new_algo_, TLObject new_secure_algo_, std::string secure_random_, std::optional<bool> has_recovery_, std::optional<bool> has_secure_values_, std::optional<bool> has_password_, std::optional<TLObject> current_algo_, std::optional<std::string> srp_B_, std::optional<long> srp_id_, std::optional<std::string> hint_, std::optional<std::string> email_unconfirmed_pattern_) {}

Password Password::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> has_recovery_;

    if (1 << 0)
        has_recovery_ = true;
    else
        has_recovery_ = std::nullopt;
    std::optional<bool> has_secure_values_;

    if (1 << 1)
        has_secure_values_ = true;
    else
        has_secure_values_ = std::nullopt;
    std::optional<bool> has_password_;

    if (1 << 2)
        has_password_ = true;
    else
        has_password_ = std::nullopt;
    std::optional<TLObject> current_algo_;

    if (1 << 2)
        current_algo_ = TLObject::read(reader);
    else
        current_algo_ = std::nullopt;
    std::optional<std::string> srp_B_;

    if (1 << 2)
        srp_B_ = Bytes::read(reader);
    else
        srp_B_ = std::nullopt;
    std::optional<long> srp_id_;

    if (1 << 2)
        srp_id_ = Long::read(reader);
    else
        srp_id_ = std::nullopt;
    std::optional<std::string> hint_;

    if (1 << 3)
        hint_ = String::read(reader);
    else
        hint_ = std::nullopt;
    std::optional<std::string> email_unconfirmed_pattern_;

    if (1 << 4)
        email_unconfirmed_pattern_ = String::read(reader);
    else
        email_unconfirmed_pattern_ = std::nullopt;
    TLObject new_algo_ = TLObject::read(reader);
    TLObject new_secure_algo_ = TLObject::read(reader);
    std::string secure_random_ = Bytes::read(reader);
    return Password(new_algo_, new_secure_algo_, secure_random_, has_recovery_, has_secure_values_, has_password_, current_algo_, srp_B_, srp_id_, hint_, email_unconfirmed_pattern_);
}

std::string Password::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= has_recovery ? 1 << 0 : 0;
    flags |= has_secure_values ? 1 << 1 : 0;
    flags |= has_password ? 1 << 2 : 0;
    flags |= current_algo ? 1 << 2 : 0;
    flags |= srp_B ? 1 << 2 : 0;
    flags |= srp_id ? 1 << 2 : 0;
    flags |= hint ? 1 << 3 : 0;
    flags |= email_unconfirmed_pattern ? 1 << 4 : 0;

    if (current_algo)
        buffer += current_algo.value().write();

    if (srp_B)
        buffer += Bytes::write(srp_B.value());

    if (srp_id)
        buffer += Long::write(srp_id.value());

    if (hint)
        buffer += String::write(hint.value());

    if (email_unconfirmed_pattern)
        buffer += String::write(email_unconfirmed_pattern.value());
    buffer += new_algo.write();
    buffer += new_secure_algo.write();
    buffer += Bytes::write(secure_random);
    return buffer;
}

PasswordSettings::PasswordSettings(std::optional<std::string> email_, std::optional<TLObject> secure_settings_) {}

PasswordSettings PasswordSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> email_;

    if (1 << 0)
        email_ = String::read(reader);
    else
        email_ = std::nullopt;
    std::optional<TLObject> secure_settings_;

    if (1 << 1)
        secure_settings_ = TLObject::read(reader);
    else
        secure_settings_ = std::nullopt;
    return PasswordSettings(email_, secure_settings_);
}

std::string PasswordSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= email ? 1 << 0 : 0;
    flags |= secure_settings ? 1 << 1 : 0;

    if (email)
        buffer += String::write(email.value());

    if (secure_settings)
        buffer += secure_settings.value().write();
    return buffer;
}

PasswordInputSettings::PasswordInputSettings(std::optional<TLObject> new_algo_, std::optional<std::string> new_password_hash_, std::optional<std::string> hint_, std::optional<std::string> email_, std::optional<TLObject> new_secure_settings_) {}

PasswordInputSettings PasswordInputSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> new_algo_;

    if (1 << 0)
        new_algo_ = TLObject::read(reader);
    else
        new_algo_ = std::nullopt;
    std::optional<std::string> new_password_hash_;

    if (1 << 0)
        new_password_hash_ = Bytes::read(reader);
    else
        new_password_hash_ = std::nullopt;
    std::optional<std::string> hint_;

    if (1 << 0)
        hint_ = String::read(reader);
    else
        hint_ = std::nullopt;
    std::optional<std::string> email_;

    if (1 << 1)
        email_ = String::read(reader);
    else
        email_ = std::nullopt;
    std::optional<TLObject> new_secure_settings_;

    if (1 << 2)
        new_secure_settings_ = TLObject::read(reader);
    else
        new_secure_settings_ = std::nullopt;
    return PasswordInputSettings(new_algo_, new_password_hash_, hint_, email_, new_secure_settings_);
}

std::string PasswordInputSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= new_algo ? 1 << 0 : 0;
    flags |= new_password_hash ? 1 << 0 : 0;
    flags |= hint ? 1 << 0 : 0;
    flags |= email ? 1 << 1 : 0;
    flags |= new_secure_settings ? 1 << 2 : 0;

    if (new_algo)
        buffer += new_algo.value().write();

    if (new_password_hash)
        buffer += Bytes::write(new_password_hash.value());

    if (hint)
        buffer += String::write(hint.value());

    if (email)
        buffer += String::write(email.value());

    if (new_secure_settings)
        buffer += new_secure_settings.value().write();
    return buffer;
}

TmpPassword::TmpPassword(std::string tmp_password_, int valid_until_) {}

TmpPassword TmpPassword::read(Reader reader)
{
    std::string tmp_password_ = Bytes::read(reader);
    int valid_until_ = Int::read(reader);
    return TmpPassword(tmp_password_, valid_until_);
}

std::string TmpPassword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(tmp_password);
    buffer += Int::write(valid_until);
    return buffer;
}

WebAuthorizations::WebAuthorizations(std::vector<TLObject> authorizations_, std::vector<TLObject> users_) {}

WebAuthorizations WebAuthorizations::read(Reader reader)
{
    std::vector<TLObject> authorizations_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return WebAuthorizations(authorizations_, users_);
}

std::string WebAuthorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(authorizations);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

AuthorizationForm::AuthorizationForm(std::vector<TLObject> required_types_, std::vector<TLObject> values_, std::vector<TLObject> errors_, std::vector<TLObject> users_, std::optional<std::string> privacy_policy_url_) {}

AuthorizationForm AuthorizationForm::read(Reader reader)
{
    int flags = Int::read(reader);
    std::vector<TLObject> required_types_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> values_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> errors_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    std::optional<std::string> privacy_policy_url_;

    if (1 << 0)
        privacy_policy_url_ = String::read(reader);
    else
        privacy_policy_url_ = std::nullopt;
    return AuthorizationForm(required_types_, values_, errors_, users_, privacy_policy_url_);
}

std::string AuthorizationForm::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= privacy_policy_url ? 1 << 0 : 0;
    buffer += Vector<TLObject>::write(required_types);
    buffer += Vector<TLObject>::write(values);
    buffer += Vector<TLObject>::write(errors);
    buffer += Vector<TLObject>::write(users);

    if (privacy_policy_url)
        buffer += String::write(privacy_policy_url.value());
    return buffer;
}

SentEmailCode::SentEmailCode(std::string email_pattern_, int length_) {}

SentEmailCode SentEmailCode::read(Reader reader)
{
    std::string email_pattern_ = String::read(reader);
    int length_ = Int::read(reader);
    return SentEmailCode(email_pattern_, length_);
}

std::string SentEmailCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email_pattern);
    buffer += Int::write(length);
    return buffer;
}

Takeout::Takeout(long id_) {}

Takeout Takeout::read(Reader reader)
{
    long id_ = Long::read(reader);
    return Takeout(id_);
}

std::string Takeout::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}
WallPapersNotModified WallPapersNotModified::read(Reader reader)
{
    return WallPapersNotModified();
}

std::string WallPapersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

WallPapers::WallPapers(int hash_, std::vector<TLObject> wallpapers_) {}

WallPapers WallPapers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> wallpapers_ = Vector<TLObject>::read(reader);
    return WallPapers(hash_, wallpapers_);
}

std::string WallPapers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(wallpapers);
    return buffer;
}

AutoDownloadSettings::AutoDownloadSettings(TLObject low_, TLObject medium_, TLObject high_) {}

AutoDownloadSettings AutoDownloadSettings::read(Reader reader)
{
    TLObject low_ = TLObject::read(reader);
    TLObject medium_ = TLObject::read(reader);
    TLObject high_ = TLObject::read(reader);
    return AutoDownloadSettings(low_, medium_, high_);
}

std::string AutoDownloadSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += low.write();
    buffer += medium.write();
    buffer += high.write();
    return buffer;
}
ThemesNotModified ThemesNotModified::read(Reader reader)
{
    return ThemesNotModified();
}

std::string ThemesNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

Themes::Themes(int hash_, std::vector<TLObject> themes_) {}

Themes Themes::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> themes_ = Vector<TLObject>::read(reader);
    return Themes(hash_, themes_);
}

std::string Themes::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(themes);
    return buffer;
}

ContentSettings::ContentSettings(std::optional<bool> sensitive_enabled_, std::optional<bool> sensitive_can_change_) {}

ContentSettings ContentSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> sensitive_enabled_;

    if (1 << 0)
        sensitive_enabled_ = true;
    else
        sensitive_enabled_ = std::nullopt;
    std::optional<bool> sensitive_can_change_;

    if (1 << 1)
        sensitive_can_change_ = true;
    else
        sensitive_can_change_ = std::nullopt;
    return ContentSettings(sensitive_enabled_, sensitive_can_change_);
}

std::string ContentSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= sensitive_enabled ? 1 << 0 : 0;
    flags |= sensitive_can_change ? 1 << 1 : 0;
    return buffer;
}
