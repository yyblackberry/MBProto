#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class PrivacyRules
{
private:
    int __id = 0x50a04e45;

public:
    std::vector<TLObject> rules;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    PrivacyRules(std::vector<TLObject> rules_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static PrivacyRules read(Reader reader);
    std::string write();
};

class Authorizations
{
private:
    int __id = 0x1250abde;

public:
    std::vector<TLObject> authorizations;
    Authorizations(std::vector<TLObject> authorizations_);
    static Authorizations read(Reader reader);
    std::string write();
};

class Password
{
private:
    int __id = 0xad2641f8;

public:
    std::optional<bool> has_recovery;
    std::optional<bool> has_secure_values;
    std::optional<bool> has_password;
    std::optional<TLObject> current_algo;
    std::optional<std::string> srp_B;
    std::optional<long> srp_id;
    std::optional<std::string> hint;
    std::optional<std::string> email_unconfirmed_pattern;
    TLObject new_algo;
    TLObject new_secure_algo;
    std::string secure_random;
    Password(TLObject new_algo_, TLObject new_secure_algo_, std::string secure_random_, std::optional<bool> has_recovery_ = std::nullopt, std::optional<bool> has_secure_values_ = std::nullopt, std::optional<bool> has_password_ = std::nullopt, std::optional<TLObject> current_algo_ = std::nullopt, std::optional<std::string> srp_B_ = std::nullopt, std::optional<long> srp_id_ = std::nullopt, std::optional<std::string> hint_ = std::nullopt, std::optional<std::string> email_unconfirmed_pattern_ = std::nullopt);
    static Password read(Reader reader);
    std::string write();
};

class PasswordSettings
{
private:
    int __id = 0x9a5c33e5;

public:
    std::optional<std::string> email;
    std::optional<TLObject> secure_settings;
    PasswordSettings(std::optional<std::string> email_ = std::nullopt, std::optional<TLObject> secure_settings_ = std::nullopt);
    static PasswordSettings read(Reader reader);
    std::string write();
};

class PasswordInputSettings
{
private:
    int __id = 0xc23727c9;

public:
    std::optional<TLObject> new_algo;
    std::optional<std::string> new_password_hash;
    std::optional<std::string> hint;
    std::optional<std::string> email;
    std::optional<TLObject> new_secure_settings;
    PasswordInputSettings(std::optional<TLObject> new_algo_ = std::nullopt, std::optional<std::string> new_password_hash_ = std::nullopt, std::optional<std::string> hint_ = std::nullopt, std::optional<std::string> email_ = std::nullopt, std::optional<TLObject> new_secure_settings_ = std::nullopt);
    static PasswordInputSettings read(Reader reader);
    std::string write();
};

class TmpPassword
{
private:
    int __id = 0xdb64fd34;

public:
    std::string tmp_password;
    int valid_until;
    TmpPassword(std::string tmp_password_, int valid_until_);
    static TmpPassword read(Reader reader);
    std::string write();
};

class WebAuthorizations
{
private:
    int __id = 0xed56c9fc;

public:
    std::vector<TLObject> authorizations;
    std::vector<TLObject> users;
    WebAuthorizations(std::vector<TLObject> authorizations_, std::vector<TLObject> users_);
    static WebAuthorizations read(Reader reader);
    std::string write();
};

class AuthorizationForm
{
private:
    int __id = 0xad2e1cd8;

public:
    std::vector<TLObject> required_types;
    std::vector<TLObject> values;
    std::vector<TLObject> errors;
    std::vector<TLObject> users;
    std::optional<std::string> privacy_policy_url;
    AuthorizationForm(std::vector<TLObject> required_types_, std::vector<TLObject> values_, std::vector<TLObject> errors_, std::vector<TLObject> users_, std::optional<std::string> privacy_policy_url_ = std::nullopt);
    static AuthorizationForm read(Reader reader);
    std::string write();
};

class SentEmailCode
{
private:
    int __id = 0x811f854f;

public:
    std::string email_pattern;
    int length;
    SentEmailCode(std::string email_pattern_, int length_);
    static SentEmailCode read(Reader reader);
    std::string write();
};

class Takeout
{
private:
    int __id = 0x4dba4501;

public:
    long id;
    Takeout(long id_);
    static Takeout read(Reader reader);
    std::string write();
};

class WallPapersNotModified
{
private:
    int __id = 0x1c199183;

public:
    WallPapersNotModified() = default;
    static WallPapersNotModified read(Reader reader);
    std::string write();
};

class WallPapers
{
private:
    int __id = 0x702b65a9;

public:
    int hash;
    std::vector<TLObject> wallpapers;
    WallPapers(int hash_, std::vector<TLObject> wallpapers_);
    static WallPapers read(Reader reader);
    std::string write();
};

class AutoDownloadSettings
{
private:
    int __id = 0x63cacf26;

public:
    TLObject low;
    TLObject medium;
    TLObject high;
    AutoDownloadSettings(TLObject low_, TLObject medium_, TLObject high_);
    static AutoDownloadSettings read(Reader reader);
    std::string write();
};

class ThemesNotModified
{
private:
    int __id = 0xf41eb622;

public:
    ThemesNotModified() = default;
    static ThemesNotModified read(Reader reader);
    std::string write();
};

class Themes
{
private:
    int __id = 0x7f676421;

public:
    int hash;
    std::vector<TLObject> themes;
    Themes(int hash_, std::vector<TLObject> themes_);
    static Themes read(Reader reader);
    std::string write();
};

class ContentSettings
{
private:
    int __id = 0x57e28221;

public:
    std::optional<bool> sensitive_enabled;
    std::optional<bool> sensitive_can_change;
    ContentSettings(std::optional<bool> sensitive_enabled_ = std::nullopt, std::optional<bool> sensitive_can_change_ = std::nullopt);
    static ContentSettings read(Reader reader);
    std::string write();
};
