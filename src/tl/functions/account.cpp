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

#include "tl/functions/account.h"

RegisterDevice::RegisterDevice(int token_type_, std::string token_, bool app_sandbox_, std::string secret_, std::vector<int> other_uids_, std::optional<bool> no_muted_) {}

RegisterDevice RegisterDevice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_muted_;
    no_muted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int token_type_ = Int::read(reader);
    std::string token_ = String::read(reader);
    bool app_sandbox_ = Bool::read(reader);
    std::string secret_ = Bytes::read(reader);
    std::vector<int> other_uids_ = std::get<std::vector<int>>(TLObject::read(reader));
    return RegisterDevice(token_type_, token_, app_sandbox_, secret_, other_uids_, no_muted_);
}

std::string RegisterDevice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_muted ? 1 << 0 : 0;
    buffer += Int::write(token_type);
    buffer += String::write(token);
    buffer += Bool::write(app_sandbox);
    buffer += Bytes::write(secret);
    buffer += Vector<int>::write(other_uids);
    return buffer;
}

UnregisterDevice::UnregisterDevice(int token_type_, std::string token_, std::vector<int> other_uids_) {}

UnregisterDevice UnregisterDevice::read(Reader reader)
{
    int token_type_ = Int::read(reader);
    std::string token_ = String::read(reader);
    std::vector<int> other_uids_ = std::get<std::vector<int>>(TLObject::read(reader));
    return UnregisterDevice(token_type_, token_, other_uids_);
}

std::string UnregisterDevice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(token_type);
    buffer += String::write(token);
    buffer += Vector<int>::write(other_uids);
    return buffer;
}

UpdateNotifySettings::UpdateNotifySettings(TLObject peer_, TLObject settings_) {}

UpdateNotifySettings UpdateNotifySettings::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateNotifySettings(peer_, settings_);
}

std::string UpdateNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += settings.write();
    return buffer;
}

GetNotifySettings::GetNotifySettings(TLObject peer_) {}

GetNotifySettings GetNotifySettings::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return GetNotifySettings(peer_);
}

std::string GetNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
ResetNotifySettings ResetNotifySettings::read(Reader reader)
{
    return ResetNotifySettings();
}

std::string ResetNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateProfile::UpdateProfile(std::optional<std::string> first_name_, std::optional<std::string> last_name_, std::optional<std::string> about_) {}

UpdateProfile UpdateProfile::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> first_name_;
    first_name_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> last_name_;
    last_name_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> about_;
    about_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return UpdateProfile(first_name_, last_name_, about_);
}

std::string UpdateProfile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= first_name ? 1 << 0 : 0;
    flags |= last_name ? 1 << 1 : 0;
    flags |= about ? 1 << 2 : 0;

    if (first_name)
        buffer += String::write(first_name.value());

    if (last_name)
        buffer += String::write(last_name.value());

    if (about)
        buffer += String::write(about.value());
    return buffer;
}

UpdateStatus::UpdateStatus(bool offline_) {}

UpdateStatus UpdateStatus::read(Reader reader)
{
    bool offline_ = Bool::read(reader);
    return UpdateStatus(offline_);
}

std::string UpdateStatus::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(offline);
    return buffer;
}

GetWallPapers::GetWallPapers(int hash_) {}

GetWallPapers GetWallPapers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetWallPapers(hash_);
}

std::string GetWallPapers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

ReportPeer::ReportPeer(TLObject peer_, TLObject reason_, std::string message_) {}

ReportPeer ReportPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject reason_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    return ReportPeer(peer_, reason_, message_);
}

std::string ReportPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}

CheckUsername::CheckUsername(std::string username_) {}

CheckUsername CheckUsername::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return CheckUsername(username_);
}

std::string CheckUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

UpdateUsername::UpdateUsername(std::string username_) {}

UpdateUsername UpdateUsername::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return UpdateUsername(username_);
}

std::string UpdateUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

GetPrivacy::GetPrivacy(TLObject key_) {}

GetPrivacy GetPrivacy::read(Reader reader)
{
    TLObject key_ = std::get<TLObject>(TLObject::read(reader));
    return GetPrivacy(key_);
}

std::string GetPrivacy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += key.write();
    return buffer;
}

SetPrivacy::SetPrivacy(TLObject key_, std::vector<TLObject> rules_) {}

SetPrivacy SetPrivacy::read(Reader reader)
{
    TLObject key_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> rules_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SetPrivacy(key_, rules_);
}

std::string SetPrivacy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += key.write();
    buffer += Vector<TLObject>::write(rules);
    return buffer;
}

DeleteAccount::DeleteAccount(std::string reason_) {}

DeleteAccount DeleteAccount::read(Reader reader)
{
    std::string reason_ = String::read(reader);
    return DeleteAccount(reason_);
}

std::string DeleteAccount::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(reason);
    return buffer;
}
GetAccountTTL GetAccountTTL::read(Reader reader)
{
    return GetAccountTTL();
}

std::string GetAccountTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SetAccountTTL::SetAccountTTL(TLObject ttl_) {}

SetAccountTTL SetAccountTTL::read(Reader reader)
{
    TLObject ttl_ = std::get<TLObject>(TLObject::read(reader));
    return SetAccountTTL(ttl_);
}

std::string SetAccountTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += ttl.write();
    return buffer;
}

SendChangePhoneCode::SendChangePhoneCode(std::string phone_number_, TLObject settings_) {}

SendChangePhoneCode SendChangePhoneCode::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SendChangePhoneCode(phone_number_, settings_);
}

std::string SendChangePhoneCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += settings.write();
    return buffer;
}

ChangePhone::ChangePhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

ChangePhone ChangePhone::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return ChangePhone(phone_number_, phone_code_hash_, phone_code_);
}

std::string ChangePhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

UpdateDeviceLocked::UpdateDeviceLocked(int period_) {}

UpdateDeviceLocked UpdateDeviceLocked::read(Reader reader)
{
    int period_ = Int::read(reader);
    return UpdateDeviceLocked(period_);
}

std::string UpdateDeviceLocked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(period);
    return buffer;
}
GetAuthorizations GetAuthorizations::read(Reader reader)
{
    return GetAuthorizations();
}

std::string GetAuthorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ResetAuthorization::ResetAuthorization(long hash_) {}

ResetAuthorization ResetAuthorization::read(Reader reader)
{
    long hash_ = Long::read(reader);
    return ResetAuthorization(hash_);
}

std::string ResetAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(hash);
    return buffer;
}
GetPassword GetPassword::read(Reader reader)
{
    return GetPassword();
}

std::string GetPassword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetPasswordSettings::GetPasswordSettings(TLObject password_) {}

GetPasswordSettings GetPasswordSettings::read(Reader reader)
{
    TLObject password_ = std::get<TLObject>(TLObject::read(reader));
    return GetPasswordSettings(password_);
}

std::string GetPasswordSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    return buffer;
}

UpdatePasswordSettings::UpdatePasswordSettings(TLObject password_, TLObject new_settings_) {}

UpdatePasswordSettings UpdatePasswordSettings::read(Reader reader)
{
    TLObject password_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_settings_ = std::get<TLObject>(TLObject::read(reader));
    return UpdatePasswordSettings(password_, new_settings_);
}

std::string UpdatePasswordSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    buffer += new_settings.write();
    return buffer;
}

SendConfirmPhoneCode::SendConfirmPhoneCode(std::string hash_, TLObject settings_) {}

SendConfirmPhoneCode SendConfirmPhoneCode::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SendConfirmPhoneCode(hash_, settings_);
}

std::string SendConfirmPhoneCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    buffer += settings.write();
    return buffer;
}

ConfirmPhone::ConfirmPhone(std::string phone_code_hash_, std::string phone_code_) {}

ConfirmPhone ConfirmPhone::read(Reader reader)
{
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return ConfirmPhone(phone_code_hash_, phone_code_);
}

std::string ConfirmPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

GetTmpPassword::GetTmpPassword(TLObject password_, int period_) {}

GetTmpPassword GetTmpPassword::read(Reader reader)
{
    TLObject password_ = std::get<TLObject>(TLObject::read(reader));
    int period_ = Int::read(reader);
    return GetTmpPassword(password_, period_);
}

std::string GetTmpPassword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    buffer += Int::write(period);
    return buffer;
}
GetWebAuthorizations GetWebAuthorizations::read(Reader reader)
{
    return GetWebAuthorizations();
}

std::string GetWebAuthorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ResetWebAuthorization::ResetWebAuthorization(long hash_) {}

ResetWebAuthorization ResetWebAuthorization::read(Reader reader)
{
    long hash_ = Long::read(reader);
    return ResetWebAuthorization(hash_);
}

std::string ResetWebAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(hash);
    return buffer;
}
ResetWebAuthorizations ResetWebAuthorizations::read(Reader reader)
{
    return ResetWebAuthorizations();
}

std::string ResetWebAuthorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetAllSecureValues GetAllSecureValues::read(Reader reader)
{
    return GetAllSecureValues();
}

std::string GetAllSecureValues::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetSecureValue::GetSecureValue(std::vector<TLObject> types_) {}

GetSecureValue GetSecureValue::read(Reader reader)
{
    std::vector<TLObject> types_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetSecureValue(types_);
}

std::string GetSecureValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}

SaveSecureValue::SaveSecureValue(TLObject value_, long secure_secret_id_) {}

SaveSecureValue SaveSecureValue::read(Reader reader)
{
    TLObject value_ = std::get<TLObject>(TLObject::read(reader));
    long secure_secret_id_ = Long::read(reader);
    return SaveSecureValue(value_, secure_secret_id_);
}

std::string SaveSecureValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += value.write();
    buffer += Long::write(secure_secret_id);
    return buffer;
}

DeleteSecureValue::DeleteSecureValue(std::vector<TLObject> types_) {}

DeleteSecureValue DeleteSecureValue::read(Reader reader)
{
    std::vector<TLObject> types_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DeleteSecureValue(types_);
}

std::string DeleteSecureValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}

GetAuthorizationForm::GetAuthorizationForm(int bot_id_, std::string scope_, std::string public_key_) {}

GetAuthorizationForm GetAuthorizationForm::read(Reader reader)
{
    int bot_id_ = Int::read(reader);
    std::string scope_ = String::read(reader);
    std::string public_key_ = String::read(reader);
    return GetAuthorizationForm(bot_id_, scope_, public_key_);
}

std::string GetAuthorizationForm::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(bot_id);
    buffer += String::write(scope);
    buffer += String::write(public_key);
    return buffer;
}

AcceptAuthorization::AcceptAuthorization(int bot_id_, std::string scope_, std::string public_key_, std::vector<TLObject> value_hashes_, TLObject credentials_) {}

AcceptAuthorization AcceptAuthorization::read(Reader reader)
{
    int bot_id_ = Int::read(reader);
    std::string scope_ = String::read(reader);
    std::string public_key_ = String::read(reader);
    std::vector<TLObject> value_hashes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject credentials_ = std::get<TLObject>(TLObject::read(reader));
    return AcceptAuthorization(bot_id_, scope_, public_key_, value_hashes_, credentials_);
}

std::string AcceptAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(bot_id);
    buffer += String::write(scope);
    buffer += String::write(public_key);
    buffer += Vector<TLObject>::write(value_hashes);
    buffer += credentials.write();
    return buffer;
}

SendVerifyPhoneCode::SendVerifyPhoneCode(std::string phone_number_, TLObject settings_) {}

SendVerifyPhoneCode SendVerifyPhoneCode::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SendVerifyPhoneCode(phone_number_, settings_);
}

std::string SendVerifyPhoneCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += settings.write();
    return buffer;
}

VerifyPhone::VerifyPhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

VerifyPhone VerifyPhone::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return VerifyPhone(phone_number_, phone_code_hash_, phone_code_);
}

std::string VerifyPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

SendVerifyEmailCode::SendVerifyEmailCode(std::string email_) {}

SendVerifyEmailCode SendVerifyEmailCode::read(Reader reader)
{
    std::string email_ = String::read(reader);
    return SendVerifyEmailCode(email_);
}

std::string SendVerifyEmailCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email);
    return buffer;
}

VerifyEmail::VerifyEmail(std::string email_, std::string code_) {}

VerifyEmail VerifyEmail::read(Reader reader)
{
    std::string email_ = String::read(reader);
    std::string code_ = String::read(reader);
    return VerifyEmail(email_, code_);
}

std::string VerifyEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email);
    buffer += String::write(code);
    return buffer;
}

InitTakeoutSession::InitTakeoutSession(std::optional<bool> contacts_, std::optional<bool> message_users_, std::optional<bool> message_chats_, std::optional<bool> message_megagroups_, std::optional<bool> message_channels_, std::optional<bool> files_, std::optional<int> file_max_size_) {}

InitTakeoutSession InitTakeoutSession::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> contacts_;
    contacts_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> message_users_;
    message_users_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> message_chats_;
    message_chats_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> message_megagroups_;
    message_megagroups_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> message_channels_;
    message_channels_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> files_;
    files_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<int> file_max_size_;
    file_max_size_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    return InitTakeoutSession(contacts_, message_users_, message_chats_, message_megagroups_, message_channels_, files_, file_max_size_);
}

std::string InitTakeoutSession::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= contacts ? 1 << 0 : 0;
    flags |= message_users ? 1 << 1 : 0;
    flags |= message_chats ? 1 << 2 : 0;
    flags |= message_megagroups ? 1 << 3 : 0;
    flags |= message_channels ? 1 << 4 : 0;
    flags |= files ? 1 << 5 : 0;
    flags |= file_max_size ? 1 << 5 : 0;

    if (file_max_size)
        buffer += Int::write(file_max_size.value());
    return buffer;
}

FinishTakeoutSession::FinishTakeoutSession(std::optional<bool> success_) {}

FinishTakeoutSession FinishTakeoutSession::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> success_;
    success_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return FinishTakeoutSession(success_);
}

std::string FinishTakeoutSession::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= success ? 1 << 0 : 0;
    return buffer;
}

ConfirmPasswordEmail::ConfirmPasswordEmail(std::string code_) {}

ConfirmPasswordEmail ConfirmPasswordEmail::read(Reader reader)
{
    std::string code_ = String::read(reader);
    return ConfirmPasswordEmail(code_);
}

std::string ConfirmPasswordEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(code);
    return buffer;
}
ResendPasswordEmail ResendPasswordEmail::read(Reader reader)
{
    return ResendPasswordEmail();
}

std::string ResendPasswordEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
CancelPasswordEmail CancelPasswordEmail::read(Reader reader)
{
    return CancelPasswordEmail();
}

std::string CancelPasswordEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetContactSignUpNotification GetContactSignUpNotification::read(Reader reader)
{
    return GetContactSignUpNotification();
}

std::string GetContactSignUpNotification::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SetContactSignUpNotification::SetContactSignUpNotification(bool silent_) {}

SetContactSignUpNotification SetContactSignUpNotification::read(Reader reader)
{
    bool silent_ = Bool::read(reader);
    return SetContactSignUpNotification(silent_);
}

std::string SetContactSignUpNotification::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(silent);
    return buffer;
}

GetNotifyExceptions::GetNotifyExceptions(std::optional<bool> compare_sound_, std::optional<TLObject> peer_) {}

GetNotifyExceptions GetNotifyExceptions::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> compare_sound_;
    compare_sound_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> peer_;
    peer_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return GetNotifyExceptions(compare_sound_, peer_);
}

std::string GetNotifyExceptions::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= compare_sound ? 1 << 1 : 0;
    flags |= peer ? 1 << 0 : 0;

    if (peer)
        buffer += peer.value().write();
    return buffer;
}

GetWallPaper::GetWallPaper(TLObject wallpaper_) {}

GetWallPaper GetWallPaper::read(Reader reader)
{
    TLObject wallpaper_ = std::get<TLObject>(TLObject::read(reader));
    return GetWallPaper(wallpaper_);
}

std::string GetWallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    return buffer;
}

UploadWallPaper::UploadWallPaper(TLObject file_, std::string mime_type_, TLObject settings_) {}

UploadWallPaper UploadWallPaper::read(Reader reader)
{
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    std::string mime_type_ = String::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return UploadWallPaper(file_, mime_type_, settings_);
}

std::string UploadWallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += file.write();
    buffer += String::write(mime_type);
    buffer += settings.write();
    return buffer;
}

SaveWallPaper::SaveWallPaper(TLObject wallpaper_, bool unsave_, TLObject settings_) {}

SaveWallPaper SaveWallPaper::read(Reader reader)
{
    TLObject wallpaper_ = std::get<TLObject>(TLObject::read(reader));
    bool unsave_ = Bool::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SaveWallPaper(wallpaper_, unsave_, settings_);
}

std::string SaveWallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    buffer += Bool::write(unsave);
    buffer += settings.write();
    return buffer;
}

InstallWallPaper::InstallWallPaper(TLObject wallpaper_, TLObject settings_) {}

InstallWallPaper InstallWallPaper::read(Reader reader)
{
    TLObject wallpaper_ = std::get<TLObject>(TLObject::read(reader));
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return InstallWallPaper(wallpaper_, settings_);
}

std::string InstallWallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    buffer += settings.write();
    return buffer;
}
ResetWallPapers ResetWallPapers::read(Reader reader)
{
    return ResetWallPapers();
}

std::string ResetWallPapers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetAutoDownloadSettings GetAutoDownloadSettings::read(Reader reader)
{
    return GetAutoDownloadSettings();
}

std::string GetAutoDownloadSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SaveAutoDownloadSettings::SaveAutoDownloadSettings(TLObject settings_, std::optional<bool> low_, std::optional<bool> high_) {}

SaveAutoDownloadSettings SaveAutoDownloadSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> low_;
    low_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> high_;
    high_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SaveAutoDownloadSettings(settings_, low_, high_);
}

std::string SaveAutoDownloadSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= low ? 1 << 0 : 0;
    flags |= high ? 1 << 1 : 0;
    buffer += settings.write();
    return buffer;
}

UploadTheme::UploadTheme(TLObject file_, std::string file_name_, std::string mime_type_, std::optional<TLObject> thumb_) {}

UploadTheme UploadTheme::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> thumb_;
    thumb_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string file_name_ = String::read(reader);
    std::string mime_type_ = String::read(reader);
    return UploadTheme(file_, file_name_, mime_type_, thumb_);
}

std::string UploadTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= thumb ? 1 << 0 : 0;
    buffer += file.write();

    if (thumb)
        buffer += thumb.value().write();
    buffer += String::write(file_name);
    buffer += String::write(mime_type);
    return buffer;
}

CreateTheme::CreateTheme(std::string slug_, std::string title_, std::optional<TLObject> document_, std::optional<TLObject> settings_) {}

CreateTheme CreateTheme::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string slug_ = String::read(reader);
    std::string title_ = String::read(reader);
    std::optional<TLObject> document_;
    document_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> settings_;
    settings_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return CreateTheme(slug_, title_, document_, settings_);
}

std::string CreateTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= document ? 1 << 2 : 0;
    flags |= settings ? 1 << 3 : 0;
    buffer += String::write(slug);
    buffer += String::write(title);

    if (document)
        buffer += document.value().write();

    if (settings)
        buffer += settings.value().write();
    return buffer;
}

UpdateTheme::UpdateTheme(std::string format_, TLObject theme_, std::optional<std::string> slug_, std::optional<std::string> title_, std::optional<TLObject> document_, std::optional<TLObject> settings_) {}

UpdateTheme UpdateTheme::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string format_ = String::read(reader);
    TLObject theme_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> slug_;
    slug_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> title_;
    title_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> document_;
    document_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> settings_;
    settings_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return UpdateTheme(format_, theme_, slug_, title_, document_, settings_);
}

std::string UpdateTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= slug ? 1 << 0 : 0;
    flags |= title ? 1 << 1 : 0;
    flags |= document ? 1 << 2 : 0;
    flags |= settings ? 1 << 3 : 0;
    buffer += String::write(format);
    buffer += theme.write();

    if (slug)
        buffer += String::write(slug.value());

    if (title)
        buffer += String::write(title.value());

    if (document)
        buffer += document.value().write();

    if (settings)
        buffer += settings.value().write();
    return buffer;
}

SaveTheme::SaveTheme(TLObject theme_, bool unsave_) {}

SaveTheme SaveTheme::read(Reader reader)
{
    TLObject theme_ = std::get<TLObject>(TLObject::read(reader));
    bool unsave_ = Bool::read(reader);
    return SaveTheme(theme_, unsave_);
}

std::string SaveTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += theme.write();
    buffer += Bool::write(unsave);
    return buffer;
}

InstallTheme::InstallTheme(std::optional<bool> dark_, std::optional<std::string> format_, std::optional<TLObject> theme_) {}

InstallTheme InstallTheme::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;
    dark_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<std::string> format_;
    format_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> theme_;
    theme_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InstallTheme(dark_, format_, theme_);
}

std::string InstallTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    flags |= format ? 1 << 1 : 0;
    flags |= theme ? 1 << 1 : 0;

    if (format)
        buffer += String::write(format.value());

    if (theme)
        buffer += theme.value().write();
    return buffer;
}

GetTheme::GetTheme(std::string format_, TLObject theme_, long document_id_) {}

GetTheme GetTheme::read(Reader reader)
{
    std::string format_ = String::read(reader);
    TLObject theme_ = std::get<TLObject>(TLObject::read(reader));
    long document_id_ = Long::read(reader);
    return GetTheme(format_, theme_, document_id_);
}

std::string GetTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(format);
    buffer += theme.write();
    buffer += Long::write(document_id);
    return buffer;
}

GetThemes::GetThemes(std::string format_, int hash_) {}

GetThemes GetThemes::read(Reader reader)
{
    std::string format_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetThemes(format_, hash_);
}

std::string GetThemes::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(format);
    buffer += Int::write(hash);
    return buffer;
}

SetContentSettings::SetContentSettings(std::optional<bool> sensitive_enabled_) {}

SetContentSettings SetContentSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> sensitive_enabled_;
    sensitive_enabled_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return SetContentSettings(sensitive_enabled_);
}

std::string SetContentSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= sensitive_enabled ? 1 << 0 : 0;
    return buffer;
}
GetContentSettings GetContentSettings::read(Reader reader)
{
    return GetContentSettings();
}

std::string GetContentSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetMultiWallPapers::GetMultiWallPapers(std::vector<TLObject> wallpapers_) {}

GetMultiWallPapers GetMultiWallPapers::read(Reader reader)
{
    std::vector<TLObject> wallpapers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetMultiWallPapers(wallpapers_);
}

std::string GetMultiWallPapers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(wallpapers);
    return buffer;
}
GetGlobalPrivacySettings GetGlobalPrivacySettings::read(Reader reader)
{
    return GetGlobalPrivacySettings();
}

std::string GetGlobalPrivacySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SetGlobalPrivacySettings::SetGlobalPrivacySettings(TLObject settings_) {}

SetGlobalPrivacySettings SetGlobalPrivacySettings::read(Reader reader)
{
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SetGlobalPrivacySettings(settings_);
}

std::string SetGlobalPrivacySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += settings.write();
    return buffer;
}

ReportProfilePhoto::ReportProfilePhoto(TLObject peer_, TLObject photo_id_, TLObject reason_, std::string message_) {}

ReportProfilePhoto ReportProfilePhoto::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject photo_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject reason_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    return ReportProfilePhoto(peer_, photo_id_, reason_, message_);
}

std::string ReportProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += photo_id.write();
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}
