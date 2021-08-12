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

class RegisterDevice : public TLObject
{
private:
    int __id = 0x68976c6f;

public:
    std::optional<bool> no_muted;
    int token_type;
    std::string token;
    bool app_sandbox;
    std::string secret;
    std::vector<int> other_uids;
    RegisterDevice(int token_type_, std::string token_, bool app_sandbox_, std::string secret_, std::vector<int> other_uids_, std::optional<bool> no_muted_ = std::nullopt);
    static RegisterDevice read(Reader reader);
    std::string write();
};

class UnregisterDevice : public TLObject
{
private:
    int __id = 0x3076c4bf;

public:
    int token_type;
    std::string token;
    std::vector<int> other_uids;
    UnregisterDevice(int token_type_, std::string token_, std::vector<int> other_uids_);
    static UnregisterDevice read(Reader reader);
    std::string write();
};

class UpdateNotifySettings : public TLObject
{
private:
    int __id = 0x84be5b93;

public:
    TLObject peer;
    TLObject settings;
    UpdateNotifySettings(TLObject peer_, TLObject settings_);
    static UpdateNotifySettings read(Reader reader);
    std::string write();
};

class GetNotifySettings : public TLObject
{
private:
    int __id = 0x12b3ad31;

public:
    TLObject peer;
    GetNotifySettings(TLObject peer_);
    static GetNotifySettings read(Reader reader);
    std::string write();
};

class ResetNotifySettings : public TLObject
{
private:
    int __id = 0xdb7e1747;

public:
    ResetNotifySettings() = default;
    static ResetNotifySettings read(Reader reader);
    std::string write();
};

class UpdateProfile : public TLObject
{
private:
    int __id = 0x78515775;

public:
    std::optional<std::string> first_name;
    std::optional<std::string> last_name;
    std::optional<std::string> about;
    UpdateProfile(std::optional<std::string> first_name_ = std::nullopt, std::optional<std::string> last_name_ = std::nullopt, std::optional<std::string> about_ = std::nullopt);
    static UpdateProfile read(Reader reader);
    std::string write();
};

class UpdateStatus : public TLObject
{
private:
    int __id = 0x6628562c;

public:
    bool offline;
    UpdateStatus(bool offline_);
    static UpdateStatus read(Reader reader);
    std::string write();
};

class GetWallPapers : public TLObject
{
private:
    int __id = 0xaabb1763;

public:
    int hash;
    GetWallPapers(int hash_);
    static GetWallPapers read(Reader reader);
    std::string write();
};

class ReportPeer : public TLObject
{
private:
    int __id = 0xc5ba3d86;

public:
    TLObject peer;
    TLObject reason;
    std::string message;
    ReportPeer(TLObject peer_, TLObject reason_, std::string message_);
    static ReportPeer read(Reader reader);
    std::string write();
};

class CheckUsername : public TLObject
{
private:
    int __id = 0x2714d86c;

public:
    std::string username;
    CheckUsername(std::string username_);
    static CheckUsername read(Reader reader);
    std::string write();
};

class UpdateUsername : public TLObject
{
private:
    int __id = 0x3e0bdd7c;

public:
    std::string username;
    UpdateUsername(std::string username_);
    static UpdateUsername read(Reader reader);
    std::string write();
};

class GetPrivacy : public TLObject
{
private:
    int __id = 0xdadbc950;

public:
    TLObject key;
    GetPrivacy(TLObject key_);
    static GetPrivacy read(Reader reader);
    std::string write();
};

class SetPrivacy : public TLObject
{
private:
    int __id = 0xc9f81ce8;

public:
    TLObject key;
    std::vector<TLObject> rules;
    SetPrivacy(TLObject key_, std::vector<TLObject> rules_);
    static SetPrivacy read(Reader reader);
    std::string write();
};

class DeleteAccount : public TLObject
{
private:
    int __id = 0x418d4e0b;

public:
    std::string reason;
    DeleteAccount(std::string reason_);
    static DeleteAccount read(Reader reader);
    std::string write();
};

class GetAccountTTL : public TLObject
{
private:
    int __id = 0x8fc711d;

public:
    GetAccountTTL() = default;
    static GetAccountTTL read(Reader reader);
    std::string write();
};

class SetAccountTTL : public TLObject
{
private:
    int __id = 0x2442485e;

public:
    TLObject ttl;
    SetAccountTTL(TLObject ttl_);
    static SetAccountTTL read(Reader reader);
    std::string write();
};

class SendChangePhoneCode : public TLObject
{
private:
    int __id = 0x82574ae5;

public:
    std::string phone_number;
    TLObject settings;
    SendChangePhoneCode(std::string phone_number_, TLObject settings_);
    static SendChangePhoneCode read(Reader reader);
    std::string write();
};

class ChangePhone : public TLObject
{
private:
    int __id = 0x70c32edb;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string phone_code;
    ChangePhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_);
    static ChangePhone read(Reader reader);
    std::string write();
};

class UpdateDeviceLocked : public TLObject
{
private:
    int __id = 0x38df3532;

public:
    int period;
    UpdateDeviceLocked(int period_);
    static UpdateDeviceLocked read(Reader reader);
    std::string write();
};

class GetAuthorizations : public TLObject
{
private:
    int __id = 0xe320c158;

public:
    GetAuthorizations() = default;
    static GetAuthorizations read(Reader reader);
    std::string write();
};

class ResetAuthorization : public TLObject
{
private:
    int __id = 0xdf77f3bc;

public:
    long hash;
    ResetAuthorization(long hash_);
    static ResetAuthorization read(Reader reader);
    std::string write();
};

class GetPassword : public TLObject
{
private:
    int __id = 0x548a30f5;

public:
    GetPassword() = default;
    static GetPassword read(Reader reader);
    std::string write();
};

class GetPasswordSettings : public TLObject
{
private:
    int __id = 0x9cd4eaf9;

public:
    TLObject password;
    GetPasswordSettings(TLObject password_);
    static GetPasswordSettings read(Reader reader);
    std::string write();
};

class UpdatePasswordSettings : public TLObject
{
private:
    int __id = 0xa59b102f;

public:
    TLObject password;
    TLObject new_settings;
    UpdatePasswordSettings(TLObject password_, TLObject new_settings_);
    static UpdatePasswordSettings read(Reader reader);
    std::string write();
};

class SendConfirmPhoneCode : public TLObject
{
private:
    int __id = 0x1b3faa88;

public:
    std::string hash;
    TLObject settings;
    SendConfirmPhoneCode(std::string hash_, TLObject settings_);
    static SendConfirmPhoneCode read(Reader reader);
    std::string write();
};

class ConfirmPhone : public TLObject
{
private:
    int __id = 0x5f2178c3;

public:
    std::string phone_code_hash;
    std::string phone_code;
    ConfirmPhone(std::string phone_code_hash_, std::string phone_code_);
    static ConfirmPhone read(Reader reader);
    std::string write();
};

class GetTmpPassword : public TLObject
{
private:
    int __id = 0x449e0b51;

public:
    TLObject password;
    int period;
    GetTmpPassword(TLObject password_, int period_);
    static GetTmpPassword read(Reader reader);
    std::string write();
};

class GetWebAuthorizations : public TLObject
{
private:
    int __id = 0x182e6d6f;

public:
    GetWebAuthorizations() = default;
    static GetWebAuthorizations read(Reader reader);
    std::string write();
};

class ResetWebAuthorization : public TLObject
{
private:
    int __id = 0x2d01b9ef;

public:
    long hash;
    ResetWebAuthorization(long hash_);
    static ResetWebAuthorization read(Reader reader);
    std::string write();
};

class ResetWebAuthorizations : public TLObject
{
private:
    int __id = 0x682d2594;

public:
    ResetWebAuthorizations() = default;
    static ResetWebAuthorizations read(Reader reader);
    std::string write();
};

class GetAllSecureValues : public TLObject
{
private:
    int __id = 0xb288bc7d;

public:
    GetAllSecureValues() = default;
    static GetAllSecureValues read(Reader reader);
    std::string write();
};

class GetSecureValue : public TLObject
{
private:
    int __id = 0x73665bc2;

public:
    std::vector<TLObject> types;
    GetSecureValue(std::vector<TLObject> types_);
    static GetSecureValue read(Reader reader);
    std::string write();
};

class SaveSecureValue : public TLObject
{
private:
    int __id = 0x899fe31d;

public:
    TLObject value;
    long secure_secret_id;
    SaveSecureValue(TLObject value_, long secure_secret_id_);
    static SaveSecureValue read(Reader reader);
    std::string write();
};

class DeleteSecureValue : public TLObject
{
private:
    int __id = 0xb880bc4b;

public:
    std::vector<TLObject> types;
    DeleteSecureValue(std::vector<TLObject> types_);
    static DeleteSecureValue read(Reader reader);
    std::string write();
};

class GetAuthorizationForm : public TLObject
{
private:
    int __id = 0xb86ba8e1;

public:
    int bot_id;
    std::string scope;
    std::string public_key;
    GetAuthorizationForm(int bot_id_, std::string scope_, std::string public_key_);
    static GetAuthorizationForm read(Reader reader);
    std::string write();
};

class AcceptAuthorization : public TLObject
{
private:
    int __id = 0xe7027c94;

public:
    int bot_id;
    std::string scope;
    std::string public_key;
    std::vector<TLObject> value_hashes;
    TLObject credentials;
    AcceptAuthorization(int bot_id_, std::string scope_, std::string public_key_, std::vector<TLObject> value_hashes_, TLObject credentials_);
    static AcceptAuthorization read(Reader reader);
    std::string write();
};

class SendVerifyPhoneCode : public TLObject
{
private:
    int __id = 0xa5a356f9;

public:
    std::string phone_number;
    TLObject settings;
    SendVerifyPhoneCode(std::string phone_number_, TLObject settings_);
    static SendVerifyPhoneCode read(Reader reader);
    std::string write();
};

class VerifyPhone : public TLObject
{
private:
    int __id = 0x4dd3a7f6;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string phone_code;
    VerifyPhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_);
    static VerifyPhone read(Reader reader);
    std::string write();
};

class SendVerifyEmailCode : public TLObject
{
private:
    int __id = 0x7011509f;

public:
    std::string email;
    SendVerifyEmailCode(std::string email_);
    static SendVerifyEmailCode read(Reader reader);
    std::string write();
};

class VerifyEmail : public TLObject
{
private:
    int __id = 0xecba39db;

public:
    std::string email;
    std::string code;
    VerifyEmail(std::string email_, std::string code_);
    static VerifyEmail read(Reader reader);
    std::string write();
};

class InitTakeoutSession : public TLObject
{
private:
    int __id = 0xf05b4804;

public:
    std::optional<bool> contacts;
    std::optional<bool> message_users;
    std::optional<bool> message_chats;
    std::optional<bool> message_megagroups;
    std::optional<bool> message_channels;
    std::optional<bool> files;
    std::optional<int> file_max_size;
    InitTakeoutSession(std::optional<bool> contacts_ = std::nullopt, std::optional<bool> message_users_ = std::nullopt, std::optional<bool> message_chats_ = std::nullopt, std::optional<bool> message_megagroups_ = std::nullopt, std::optional<bool> message_channels_ = std::nullopt, std::optional<bool> files_ = std::nullopt, std::optional<int> file_max_size_ = std::nullopt);
    static InitTakeoutSession read(Reader reader);
    std::string write();
};

class FinishTakeoutSession : public TLObject
{
private:
    int __id = 0x1d2652ee;

public:
    std::optional<bool> success;
    FinishTakeoutSession(std::optional<bool> success_ = std::nullopt);
    static FinishTakeoutSession read(Reader reader);
    std::string write();
};

class ConfirmPasswordEmail : public TLObject
{
private:
    int __id = 0x8fdf1920;

public:
    std::string code;
    ConfirmPasswordEmail(std::string code_);
    static ConfirmPasswordEmail read(Reader reader);
    std::string write();
};

class ResendPasswordEmail : public TLObject
{
private:
    int __id = 0x7a7f2a15;

public:
    ResendPasswordEmail() = default;
    static ResendPasswordEmail read(Reader reader);
    std::string write();
};

class CancelPasswordEmail : public TLObject
{
private:
    int __id = 0xc1cbd5b6;

public:
    CancelPasswordEmail() = default;
    static CancelPasswordEmail read(Reader reader);
    std::string write();
};

class GetContactSignUpNotification : public TLObject
{
private:
    int __id = 0x9f07c728;

public:
    GetContactSignUpNotification() = default;
    static GetContactSignUpNotification read(Reader reader);
    std::string write();
};

class SetContactSignUpNotification : public TLObject
{
private:
    int __id = 0xcff43f61;

public:
    bool silent;
    SetContactSignUpNotification(bool silent_);
    static SetContactSignUpNotification read(Reader reader);
    std::string write();
};

class GetNotifyExceptions : public TLObject
{
private:
    int __id = 0x53577479;

public:
    std::optional<bool> compare_sound;
    std::optional<TLObject> peer;
    GetNotifyExceptions(std::optional<bool> compare_sound_ = std::nullopt, std::optional<TLObject> peer_ = std::nullopt);
    static GetNotifyExceptions read(Reader reader);
    std::string write();
};

class GetWallPaper : public TLObject
{
private:
    int __id = 0xfc8ddbea;

public:
    TLObject wallpaper;
    GetWallPaper(TLObject wallpaper_);
    static GetWallPaper read(Reader reader);
    std::string write();
};

class UploadWallPaper : public TLObject
{
private:
    int __id = 0xdd853661;

public:
    TLObject file;
    std::string mime_type;
    TLObject settings;
    UploadWallPaper(TLObject file_, std::string mime_type_, TLObject settings_);
    static UploadWallPaper read(Reader reader);
    std::string write();
};

class SaveWallPaper : public TLObject
{
private:
    int __id = 0x6c5a5b37;

public:
    TLObject wallpaper;
    bool unsave;
    TLObject settings;
    SaveWallPaper(TLObject wallpaper_, bool unsave_, TLObject settings_);
    static SaveWallPaper read(Reader reader);
    std::string write();
};

class InstallWallPaper : public TLObject
{
private:
    int __id = 0xfeed5769;

public:
    TLObject wallpaper;
    TLObject settings;
    InstallWallPaper(TLObject wallpaper_, TLObject settings_);
    static InstallWallPaper read(Reader reader);
    std::string write();
};

class ResetWallPapers : public TLObject
{
private:
    int __id = 0xbb3b9804;

public:
    ResetWallPapers() = default;
    static ResetWallPapers read(Reader reader);
    std::string write();
};

class GetAutoDownloadSettings : public TLObject
{
private:
    int __id = 0x56da0b3f;

public:
    GetAutoDownloadSettings() = default;
    static GetAutoDownloadSettings read(Reader reader);
    std::string write();
};

class SaveAutoDownloadSettings : public TLObject
{
private:
    int __id = 0x76f36233;

public:
    std::optional<bool> low;
    std::optional<bool> high;
    TLObject settings;
    SaveAutoDownloadSettings(TLObject settings_, std::optional<bool> low_ = std::nullopt, std::optional<bool> high_ = std::nullopt);
    static SaveAutoDownloadSettings read(Reader reader);
    std::string write();
};

class UploadTheme : public TLObject
{
private:
    int __id = 0x1c3db333;

public:
    TLObject file;
    std::optional<TLObject> thumb;
    std::string file_name;
    std::string mime_type;
    UploadTheme(TLObject file_, std::string file_name_, std::string mime_type_, std::optional<TLObject> thumb_ = std::nullopt);
    static UploadTheme read(Reader reader);
    std::string write();
};

class CreateTheme : public TLObject
{
private:
    int __id = 0x8432c21f;

public:
    std::string slug;
    std::string title;
    std::optional<TLObject> document;
    std::optional<TLObject> settings;
    CreateTheme(std::string slug_, std::string title_, std::optional<TLObject> document_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static CreateTheme read(Reader reader);
    std::string write();
};

class UpdateTheme : public TLObject
{
private:
    int __id = 0x5cb367d5;

public:
    std::string format;
    TLObject theme;
    std::optional<std::string> slug;
    std::optional<std::string> title;
    std::optional<TLObject> document;
    std::optional<TLObject> settings;
    UpdateTheme(std::string format_, TLObject theme_, std::optional<std::string> slug_ = std::nullopt, std::optional<std::string> title_ = std::nullopt, std::optional<TLObject> document_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static UpdateTheme read(Reader reader);
    std::string write();
};

class SaveTheme : public TLObject
{
private:
    int __id = 0xf257106c;

public:
    TLObject theme;
    bool unsave;
    SaveTheme(TLObject theme_, bool unsave_);
    static SaveTheme read(Reader reader);
    std::string write();
};

class InstallTheme : public TLObject
{
private:
    int __id = 0x7ae43737;

public:
    std::optional<bool> dark;
    std::optional<std::string> format;
    std::optional<TLObject> theme;
    InstallTheme(std::optional<bool> dark_ = std::nullopt, std::optional<std::string> format_ = std::nullopt, std::optional<TLObject> theme_ = std::nullopt);
    static InstallTheme read(Reader reader);
    std::string write();
};

class GetTheme : public TLObject
{
private:
    int __id = 0x8d9d742b;

public:
    std::string format;
    TLObject theme;
    long document_id;
    GetTheme(std::string format_, TLObject theme_, long document_id_);
    static GetTheme read(Reader reader);
    std::string write();
};

class GetThemes : public TLObject
{
private:
    int __id = 0x285946f8;

public:
    std::string format;
    int hash;
    GetThemes(std::string format_, int hash_);
    static GetThemes read(Reader reader);
    std::string write();
};

class SetContentSettings : public TLObject
{
private:
    int __id = 0xb574b16b;

public:
    std::optional<bool> sensitive_enabled;
    SetContentSettings(std::optional<bool> sensitive_enabled_ = std::nullopt);
    static SetContentSettings read(Reader reader);
    std::string write();
};

class GetContentSettings : public TLObject
{
private:
    int __id = 0x8b9b4dae;

public:
    GetContentSettings() = default;
    static GetContentSettings read(Reader reader);
    std::string write();
};

class GetMultiWallPapers : public TLObject
{
private:
    int __id = 0x65ad71dc;

public:
    std::vector<TLObject> wallpapers;
    GetMultiWallPapers(std::vector<TLObject> wallpapers_);
    static GetMultiWallPapers read(Reader reader);
    std::string write();
};

class GetGlobalPrivacySettings : public TLObject
{
private:
    int __id = 0xeb2b4cf6;

public:
    GetGlobalPrivacySettings() = default;
    static GetGlobalPrivacySettings read(Reader reader);
    std::string write();
};

class SetGlobalPrivacySettings : public TLObject
{
private:
    int __id = 0x1edaaac2;

public:
    TLObject settings;
    SetGlobalPrivacySettings(TLObject settings_);
    static SetGlobalPrivacySettings read(Reader reader);
    std::string write();
};

class ReportProfilePhoto : public TLObject
{
private:
    int __id = 0xfa8cc6f5;

public:
    TLObject peer;
    TLObject photo_id;
    TLObject reason;
    std::string message;
    ReportProfilePhoto(TLObject peer_, TLObject photo_id_, TLObject reason_, std::string message_);
    static ReportProfilePhoto read(Reader reader);
    std::string write();
};
