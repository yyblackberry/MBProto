#include "tl/functions/account.h"

template <class X>
RegisterDevice<X>::RegisterDevice(int token_type_, std::string token_, bool app_sandbox_, std::string secret_, std::vector<int> other_uids_, std::optional<bool> no_muted_) {}

template <class X>
RegisterDevice<X> RegisterDevice<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_muted_;

    if (1 << 0)
        no_muted_ = true;
    else
        no_muted_ = std::nullopt;
    int token_type_ = Int::read(reader);
    std::string token_ = String::read(reader);
    bool app_sandbox_ = Bool::read(reader);
    std::string secret_ = Bytes::read(reader);
    std::vector<int> other_uids_ = Vector<int>::read(reader);
    return RegisterDevice<X>(token_type_, token_, app_sandbox_, secret_, other_uids_, no_muted_);
}

template <class X>
std::string RegisterDevice<X>::write()
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

template <class X>
UnregisterDevice<X>::UnregisterDevice(int token_type_, std::string token_, std::vector<int> other_uids_) {}

template <class X>
UnregisterDevice<X> UnregisterDevice<X>::read(Reader reader)
{
    int token_type_ = Int::read(reader);
    std::string token_ = String::read(reader);
    std::vector<int> other_uids_ = Vector<int>::read(reader);
    return UnregisterDevice<X>(token_type_, token_, other_uids_);
}

template <class X>
std::string UnregisterDevice<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(token_type);
    buffer += String::write(token);
    buffer += Vector<int>::write(other_uids);
    return buffer;
}

template <class X>
UpdateNotifySettings<X>::UpdateNotifySettings(TLObject peer_, TLObject settings_) {}

template <class X>
UpdateNotifySettings<X> UpdateNotifySettings<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return UpdateNotifySettings<X>(peer_, settings_);
}

template <class X>
std::string UpdateNotifySettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += settings.write();
    return buffer;
}

template <class X>
GetNotifySettings<X>::GetNotifySettings(TLObject peer_) {}

template <class X>
GetNotifySettings<X> GetNotifySettings<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return GetNotifySettings<X>(peer_);
}

template <class X>
std::string GetNotifySettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
template <class X>
ResetNotifySettings<X> ResetNotifySettings<X>::read(Reader reader)
{
    return ResetNotifySettings<X>();
}

template <class X>
std::string ResetNotifySettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
UpdateProfile<X>::UpdateProfile(std::optional<std::string> first_name_, std::optional<std::string> last_name_, std::optional<std::string> about_) {}

template <class X>
UpdateProfile<X> UpdateProfile<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> first_name_;

    if (1 << 0)
        first_name_ = String::read(reader);
    else
        first_name_ = std::nullopt;
    std::optional<std::string> last_name_;

    if (1 << 1)
        last_name_ = String::read(reader);
    else
        last_name_ = std::nullopt;
    std::optional<std::string> about_;

    if (1 << 2)
        about_ = String::read(reader);
    else
        about_ = std::nullopt;
    return UpdateProfile<X>(first_name_, last_name_, about_);
}

template <class X>
std::string UpdateProfile<X>::write()
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

template <class X>
UpdateStatus<X>::UpdateStatus(bool offline_) {}

template <class X>
UpdateStatus<X> UpdateStatus<X>::read(Reader reader)
{
    bool offline_ = Bool::read(reader);
    return UpdateStatus<X>(offline_);
}

template <class X>
std::string UpdateStatus<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(offline);
    return buffer;
}

template <class X>
GetWallPapers<X>::GetWallPapers(int hash_) {}

template <class X>
GetWallPapers<X> GetWallPapers<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetWallPapers<X>(hash_);
}

template <class X>
std::string GetWallPapers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ReportPeer<X>::ReportPeer(TLObject peer_, TLObject reason_, std::string message_) {}

template <class X>
ReportPeer<X> ReportPeer<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject reason_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    return ReportPeer<X>(peer_, reason_, message_);
}

template <class X>
std::string ReportPeer<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}

template <class X>
CheckUsername<X>::CheckUsername(std::string username_) {}

template <class X>
CheckUsername<X> CheckUsername<X>::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return CheckUsername<X>(username_);
}

template <class X>
std::string CheckUsername<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

template <class X>
UpdateUsername<X>::UpdateUsername(std::string username_) {}

template <class X>
UpdateUsername<X> UpdateUsername<X>::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return UpdateUsername<X>(username_);
}

template <class X>
std::string UpdateUsername<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

template <class X>
GetPrivacy<X>::GetPrivacy(TLObject key_) {}

template <class X>
GetPrivacy<X> GetPrivacy<X>::read(Reader reader)
{
    TLObject key_ = TLObject::read(reader);
    return GetPrivacy<X>(key_);
}

template <class X>
std::string GetPrivacy<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += key.write();
    return buffer;
}

template <class X>
SetPrivacy<X>::SetPrivacy(TLObject key_, std::vector<TLObject> rules_) {}

template <class X>
SetPrivacy<X> SetPrivacy<X>::read(Reader reader)
{
    TLObject key_ = TLObject::read(reader);
    std::vector<TLObject> rules_ = Vector<TLObject>::read(reader);
    return SetPrivacy<X>(key_, rules_);
}

template <class X>
std::string SetPrivacy<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += key.write();
    buffer += Vector<TLObject>::write(rules);
    return buffer;
}

template <class X>
DeleteAccount<X>::DeleteAccount(std::string reason_) {}

template <class X>
DeleteAccount<X> DeleteAccount<X>::read(Reader reader)
{
    std::string reason_ = String::read(reader);
    return DeleteAccount<X>(reason_);
}

template <class X>
std::string DeleteAccount<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(reason);
    return buffer;
}
template <class X>
GetAccountTTL<X> GetAccountTTL<X>::read(Reader reader)
{
    return GetAccountTTL<X>();
}

template <class X>
std::string GetAccountTTL<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SetAccountTTL<X>::SetAccountTTL(TLObject ttl_) {}

template <class X>
SetAccountTTL<X> SetAccountTTL<X>::read(Reader reader)
{
    TLObject ttl_ = TLObject::read(reader);
    return SetAccountTTL<X>(ttl_);
}

template <class X>
std::string SetAccountTTL<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += ttl.write();
    return buffer;
}

template <class X>
SendChangePhoneCode<X>::SendChangePhoneCode(std::string phone_number_, TLObject settings_) {}

template <class X>
SendChangePhoneCode<X> SendChangePhoneCode<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return SendChangePhoneCode<X>(phone_number_, settings_);
}

template <class X>
std::string SendChangePhoneCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += settings.write();
    return buffer;
}

template <class X>
ChangePhone<X>::ChangePhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

template <class X>
ChangePhone<X> ChangePhone<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return ChangePhone<X>(phone_number_, phone_code_hash_, phone_code_);
}

template <class X>
std::string ChangePhone<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

template <class X>
UpdateDeviceLocked<X>::UpdateDeviceLocked(int period_) {}

template <class X>
UpdateDeviceLocked<X> UpdateDeviceLocked<X>::read(Reader reader)
{
    int period_ = Int::read(reader);
    return UpdateDeviceLocked<X>(period_);
}

template <class X>
std::string UpdateDeviceLocked<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(period);
    return buffer;
}
template <class X>
GetAuthorizations<X> GetAuthorizations<X>::read(Reader reader)
{
    return GetAuthorizations<X>();
}

template <class X>
std::string GetAuthorizations<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ResetAuthorization<X>::ResetAuthorization(long hash_) {}

template <class X>
ResetAuthorization<X> ResetAuthorization<X>::read(Reader reader)
{
    long hash_ = Long::read(reader);
    return ResetAuthorization<X>(hash_);
}

template <class X>
std::string ResetAuthorization<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(hash);
    return buffer;
}
template <class X>
GetPassword<X> GetPassword<X>::read(Reader reader)
{
    return GetPassword<X>();
}

template <class X>
std::string GetPassword<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetPasswordSettings<X>::GetPasswordSettings(TLObject password_) {}

template <class X>
GetPasswordSettings<X> GetPasswordSettings<X>::read(Reader reader)
{
    TLObject password_ = TLObject::read(reader);
    return GetPasswordSettings<X>(password_);
}

template <class X>
std::string GetPasswordSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    return buffer;
}

template <class X>
UpdatePasswordSettings<X>::UpdatePasswordSettings(TLObject password_, TLObject new_settings_) {}

template <class X>
UpdatePasswordSettings<X> UpdatePasswordSettings<X>::read(Reader reader)
{
    TLObject password_ = TLObject::read(reader);
    TLObject new_settings_ = TLObject::read(reader);
    return UpdatePasswordSettings<X>(password_, new_settings_);
}

template <class X>
std::string UpdatePasswordSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    buffer += new_settings.write();
    return buffer;
}

template <class X>
SendConfirmPhoneCode<X>::SendConfirmPhoneCode(std::string hash_, TLObject settings_) {}

template <class X>
SendConfirmPhoneCode<X> SendConfirmPhoneCode<X>::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return SendConfirmPhoneCode<X>(hash_, settings_);
}

template <class X>
std::string SendConfirmPhoneCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    buffer += settings.write();
    return buffer;
}

template <class X>
ConfirmPhone<X>::ConfirmPhone(std::string phone_code_hash_, std::string phone_code_) {}

template <class X>
ConfirmPhone<X> ConfirmPhone<X>::read(Reader reader)
{
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return ConfirmPhone<X>(phone_code_hash_, phone_code_);
}

template <class X>
std::string ConfirmPhone<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

template <class X>
GetTmpPassword<X>::GetTmpPassword(TLObject password_, int period_) {}

template <class X>
GetTmpPassword<X> GetTmpPassword<X>::read(Reader reader)
{
    TLObject password_ = TLObject::read(reader);
    int period_ = Int::read(reader);
    return GetTmpPassword<X>(password_, period_);
}

template <class X>
std::string GetTmpPassword<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    buffer += Int::write(period);
    return buffer;
}
template <class X>
GetWebAuthorizations<X> GetWebAuthorizations<X>::read(Reader reader)
{
    return GetWebAuthorizations<X>();
}

template <class X>
std::string GetWebAuthorizations<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ResetWebAuthorization<X>::ResetWebAuthorization(long hash_) {}

template <class X>
ResetWebAuthorization<X> ResetWebAuthorization<X>::read(Reader reader)
{
    long hash_ = Long::read(reader);
    return ResetWebAuthorization<X>(hash_);
}

template <class X>
std::string ResetWebAuthorization<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(hash);
    return buffer;
}
template <class X>
ResetWebAuthorizations<X> ResetWebAuthorizations<X>::read(Reader reader)
{
    return ResetWebAuthorizations<X>();
}

template <class X>
std::string ResetWebAuthorizations<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetAllSecureValues<X> GetAllSecureValues<X>::read(Reader reader)
{
    return GetAllSecureValues<X>();
}

template <class X>
std::string GetAllSecureValues<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetSecureValue<X>::GetSecureValue(std::vector<TLObject> types_) {}

template <class X>
GetSecureValue<X> GetSecureValue<X>::read(Reader reader)
{
    std::vector<TLObject> types_ = Vector<TLObject>::read(reader);
    return GetSecureValue<X>(types_);
}

template <class X>
std::string GetSecureValue<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}

template <class X>
SaveSecureValue<X>::SaveSecureValue(TLObject value_, long secure_secret_id_) {}

template <class X>
SaveSecureValue<X> SaveSecureValue<X>::read(Reader reader)
{
    TLObject value_ = TLObject::read(reader);
    long secure_secret_id_ = Long::read(reader);
    return SaveSecureValue<X>(value_, secure_secret_id_);
}

template <class X>
std::string SaveSecureValue<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += value.write();
    buffer += Long::write(secure_secret_id);
    return buffer;
}

template <class X>
DeleteSecureValue<X>::DeleteSecureValue(std::vector<TLObject> types_) {}

template <class X>
DeleteSecureValue<X> DeleteSecureValue<X>::read(Reader reader)
{
    std::vector<TLObject> types_ = Vector<TLObject>::read(reader);
    return DeleteSecureValue<X>(types_);
}

template <class X>
std::string DeleteSecureValue<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}

template <class X>
GetAuthorizationForm<X>::GetAuthorizationForm(int bot_id_, std::string scope_, std::string public_key_) {}

template <class X>
GetAuthorizationForm<X> GetAuthorizationForm<X>::read(Reader reader)
{
    int bot_id_ = Int::read(reader);
    std::string scope_ = String::read(reader);
    std::string public_key_ = String::read(reader);
    return GetAuthorizationForm<X>(bot_id_, scope_, public_key_);
}

template <class X>
std::string GetAuthorizationForm<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(bot_id);
    buffer += String::write(scope);
    buffer += String::write(public_key);
    return buffer;
}

template <class X>
AcceptAuthorization<X>::AcceptAuthorization(int bot_id_, std::string scope_, std::string public_key_, std::vector<TLObject> value_hashes_, TLObject credentials_) {}

template <class X>
AcceptAuthorization<X> AcceptAuthorization<X>::read(Reader reader)
{
    int bot_id_ = Int::read(reader);
    std::string scope_ = String::read(reader);
    std::string public_key_ = String::read(reader);
    std::vector<TLObject> value_hashes_ = Vector<TLObject>::read(reader);
    TLObject credentials_ = TLObject::read(reader);
    return AcceptAuthorization<X>(bot_id_, scope_, public_key_, value_hashes_, credentials_);
}

template <class X>
std::string AcceptAuthorization<X>::write()
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

template <class X>
SendVerifyPhoneCode<X>::SendVerifyPhoneCode(std::string phone_number_, TLObject settings_) {}

template <class X>
SendVerifyPhoneCode<X> SendVerifyPhoneCode<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return SendVerifyPhoneCode<X>(phone_number_, settings_);
}

template <class X>
std::string SendVerifyPhoneCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += settings.write();
    return buffer;
}

template <class X>
VerifyPhone<X>::VerifyPhone(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

template <class X>
VerifyPhone<X> VerifyPhone<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return VerifyPhone<X>(phone_number_, phone_code_hash_, phone_code_);
}

template <class X>
std::string VerifyPhone<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}

template <class X>
SendVerifyEmailCode<X>::SendVerifyEmailCode(std::string email_) {}

template <class X>
SendVerifyEmailCode<X> SendVerifyEmailCode<X>::read(Reader reader)
{
    std::string email_ = String::read(reader);
    return SendVerifyEmailCode<X>(email_);
}

template <class X>
std::string SendVerifyEmailCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email);
    return buffer;
}

template <class X>
VerifyEmail<X>::VerifyEmail(std::string email_, std::string code_) {}

template <class X>
VerifyEmail<X> VerifyEmail<X>::read(Reader reader)
{
    std::string email_ = String::read(reader);
    std::string code_ = String::read(reader);
    return VerifyEmail<X>(email_, code_);
}

template <class X>
std::string VerifyEmail<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email);
    buffer += String::write(code);
    return buffer;
}

template <class X>
InitTakeoutSession<X>::InitTakeoutSession(std::optional<bool> contacts_, std::optional<bool> message_users_, std::optional<bool> message_chats_, std::optional<bool> message_megagroups_, std::optional<bool> message_channels_, std::optional<bool> files_, std::optional<int> file_max_size_) {}

template <class X>
InitTakeoutSession<X> InitTakeoutSession<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> contacts_;

    if (1 << 0)
        contacts_ = true;
    else
        contacts_ = std::nullopt;
    std::optional<bool> message_users_;

    if (1 << 1)
        message_users_ = true;
    else
        message_users_ = std::nullopt;
    std::optional<bool> message_chats_;

    if (1 << 2)
        message_chats_ = true;
    else
        message_chats_ = std::nullopt;
    std::optional<bool> message_megagroups_;

    if (1 << 3)
        message_megagroups_ = true;
    else
        message_megagroups_ = std::nullopt;
    std::optional<bool> message_channels_;

    if (1 << 4)
        message_channels_ = true;
    else
        message_channels_ = std::nullopt;
    std::optional<bool> files_;

    if (1 << 5)
        files_ = true;
    else
        files_ = std::nullopt;
    std::optional<int> file_max_size_;

    if (1 << 5)
        file_max_size_ = Int::read(reader);
    else
        file_max_size_ = std::nullopt;
    return InitTakeoutSession<X>(contacts_, message_users_, message_chats_, message_megagroups_, message_channels_, files_, file_max_size_);
}

template <class X>
std::string InitTakeoutSession<X>::write()
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

template <class X>
FinishTakeoutSession<X>::FinishTakeoutSession(std::optional<bool> success_) {}

template <class X>
FinishTakeoutSession<X> FinishTakeoutSession<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> success_;

    if (1 << 0)
        success_ = true;
    else
        success_ = std::nullopt;
    return FinishTakeoutSession<X>(success_);
}

template <class X>
std::string FinishTakeoutSession<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= success ? 1 << 0 : 0;
    return buffer;
}

template <class X>
ConfirmPasswordEmail<X>::ConfirmPasswordEmail(std::string code_) {}

template <class X>
ConfirmPasswordEmail<X> ConfirmPasswordEmail<X>::read(Reader reader)
{
    std::string code_ = String::read(reader);
    return ConfirmPasswordEmail<X>(code_);
}

template <class X>
std::string ConfirmPasswordEmail<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(code);
    return buffer;
}
template <class X>
ResendPasswordEmail<X> ResendPasswordEmail<X>::read(Reader reader)
{
    return ResendPasswordEmail<X>();
}

template <class X>
std::string ResendPasswordEmail<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
CancelPasswordEmail<X> CancelPasswordEmail<X>::read(Reader reader)
{
    return CancelPasswordEmail<X>();
}

template <class X>
std::string CancelPasswordEmail<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetContactSignUpNotification<X> GetContactSignUpNotification<X>::read(Reader reader)
{
    return GetContactSignUpNotification<X>();
}

template <class X>
std::string GetContactSignUpNotification<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SetContactSignUpNotification<X>::SetContactSignUpNotification(bool silent_) {}

template <class X>
SetContactSignUpNotification<X> SetContactSignUpNotification<X>::read(Reader reader)
{
    bool silent_ = Bool::read(reader);
    return SetContactSignUpNotification<X>(silent_);
}

template <class X>
std::string SetContactSignUpNotification<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(silent);
    return buffer;
}

template <class X>
GetNotifyExceptions<X>::GetNotifyExceptions(std::optional<bool> compare_sound_, std::optional<TLObject> peer_) {}

template <class X>
GetNotifyExceptions<X> GetNotifyExceptions<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> compare_sound_;

    if (1 << 1)
        compare_sound_ = true;
    else
        compare_sound_ = std::nullopt;
    std::optional<TLObject> peer_;

    if (1 << 0)
        peer_ = TLObject::read(reader);
    else
        peer_ = std::nullopt;
    return GetNotifyExceptions<X>(compare_sound_, peer_);
}

template <class X>
std::string GetNotifyExceptions<X>::write()
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

template <class X>
GetWallPaper<X>::GetWallPaper(TLObject wallpaper_) {}

template <class X>
GetWallPaper<X> GetWallPaper<X>::read(Reader reader)
{
    TLObject wallpaper_ = TLObject::read(reader);
    return GetWallPaper<X>(wallpaper_);
}

template <class X>
std::string GetWallPaper<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    return buffer;
}

template <class X>
UploadWallPaper<X>::UploadWallPaper(TLObject file_, std::string mime_type_, TLObject settings_) {}

template <class X>
UploadWallPaper<X> UploadWallPaper<X>::read(Reader reader)
{
    TLObject file_ = TLObject::read(reader);
    std::string mime_type_ = String::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return UploadWallPaper<X>(file_, mime_type_, settings_);
}

template <class X>
std::string UploadWallPaper<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += file.write();
    buffer += String::write(mime_type);
    buffer += settings.write();
    return buffer;
}

template <class X>
SaveWallPaper<X>::SaveWallPaper(TLObject wallpaper_, bool unsave_, TLObject settings_) {}

template <class X>
SaveWallPaper<X> SaveWallPaper<X>::read(Reader reader)
{
    TLObject wallpaper_ = TLObject::read(reader);
    bool unsave_ = Bool::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return SaveWallPaper<X>(wallpaper_, unsave_, settings_);
}

template <class X>
std::string SaveWallPaper<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    buffer += Bool::write(unsave);
    buffer += settings.write();
    return buffer;
}

template <class X>
InstallWallPaper<X>::InstallWallPaper(TLObject wallpaper_, TLObject settings_) {}

template <class X>
InstallWallPaper<X> InstallWallPaper<X>::read(Reader reader)
{
    TLObject wallpaper_ = TLObject::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return InstallWallPaper<X>(wallpaper_, settings_);
}

template <class X>
std::string InstallWallPaper<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += wallpaper.write();
    buffer += settings.write();
    return buffer;
}
template <class X>
ResetWallPapers<X> ResetWallPapers<X>::read(Reader reader)
{
    return ResetWallPapers<X>();
}

template <class X>
std::string ResetWallPapers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetAutoDownloadSettings<X> GetAutoDownloadSettings<X>::read(Reader reader)
{
    return GetAutoDownloadSettings<X>();
}

template <class X>
std::string GetAutoDownloadSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SaveAutoDownloadSettings<X>::SaveAutoDownloadSettings(TLObject settings_, std::optional<bool> low_, std::optional<bool> high_) {}

template <class X>
SaveAutoDownloadSettings<X> SaveAutoDownloadSettings<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> low_;

    if (1 << 0)
        low_ = true;
    else
        low_ = std::nullopt;
    std::optional<bool> high_;

    if (1 << 1)
        high_ = true;
    else
        high_ = std::nullopt;
    TLObject settings_ = TLObject::read(reader);
    return SaveAutoDownloadSettings<X>(settings_, low_, high_);
}

template <class X>
std::string SaveAutoDownloadSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= low ? 1 << 0 : 0;
    flags |= high ? 1 << 1 : 0;
    buffer += settings.write();
    return buffer;
}

template <class X>
UploadTheme<X>::UploadTheme(TLObject file_, std::string file_name_, std::string mime_type_, std::optional<TLObject> thumb_) {}

template <class X>
UploadTheme<X> UploadTheme<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject file_ = TLObject::read(reader);
    std::optional<TLObject> thumb_;

    if (1 << 0)
        thumb_ = TLObject::read(reader);
    else
        thumb_ = std::nullopt;
    std::string file_name_ = String::read(reader);
    std::string mime_type_ = String::read(reader);
    return UploadTheme<X>(file_, file_name_, mime_type_, thumb_);
}

template <class X>
std::string UploadTheme<X>::write()
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

template <class X>
CreateTheme<X>::CreateTheme(std::string slug_, std::string title_, std::optional<TLObject> document_, std::optional<TLObject> settings_) {}

template <class X>
CreateTheme<X> CreateTheme<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string slug_ = String::read(reader);
    std::string title_ = String::read(reader);
    std::optional<TLObject> document_;

    if (1 << 2)
        document_ = TLObject::read(reader);
    else
        document_ = std::nullopt;
    std::optional<TLObject> settings_;

    if (1 << 3)
        settings_ = TLObject::read(reader);
    else
        settings_ = std::nullopt;
    return CreateTheme<X>(slug_, title_, document_, settings_);
}

template <class X>
std::string CreateTheme<X>::write()
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

template <class X>
UpdateTheme<X>::UpdateTheme(std::string format_, TLObject theme_, std::optional<std::string> slug_, std::optional<std::string> title_, std::optional<TLObject> document_, std::optional<TLObject> settings_) {}

template <class X>
UpdateTheme<X> UpdateTheme<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string format_ = String::read(reader);
    TLObject theme_ = TLObject::read(reader);
    std::optional<std::string> slug_;

    if (1 << 0)
        slug_ = String::read(reader);
    else
        slug_ = std::nullopt;
    std::optional<std::string> title_;

    if (1 << 1)
        title_ = String::read(reader);
    else
        title_ = std::nullopt;
    std::optional<TLObject> document_;

    if (1 << 2)
        document_ = TLObject::read(reader);
    else
        document_ = std::nullopt;
    std::optional<TLObject> settings_;

    if (1 << 3)
        settings_ = TLObject::read(reader);
    else
        settings_ = std::nullopt;
    return UpdateTheme<X>(format_, theme_, slug_, title_, document_, settings_);
}

template <class X>
std::string UpdateTheme<X>::write()
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

template <class X>
SaveTheme<X>::SaveTheme(TLObject theme_, bool unsave_) {}

template <class X>
SaveTheme<X> SaveTheme<X>::read(Reader reader)
{
    TLObject theme_ = TLObject::read(reader);
    bool unsave_ = Bool::read(reader);
    return SaveTheme<X>(theme_, unsave_);
}

template <class X>
std::string SaveTheme<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += theme.write();
    buffer += Bool::write(unsave);
    return buffer;
}

template <class X>
InstallTheme<X>::InstallTheme(std::optional<bool> dark_, std::optional<std::string> format_, std::optional<TLObject> theme_) {}

template <class X>
InstallTheme<X> InstallTheme<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;

    if (1 << 0)
        dark_ = true;
    else
        dark_ = std::nullopt;
    std::optional<std::string> format_;

    if (1 << 1)
        format_ = String::read(reader);
    else
        format_ = std::nullopt;
    std::optional<TLObject> theme_;

    if (1 << 1)
        theme_ = TLObject::read(reader);
    else
        theme_ = std::nullopt;
    return InstallTheme<X>(dark_, format_, theme_);
}

template <class X>
std::string InstallTheme<X>::write()
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

template <class X>
GetTheme<X>::GetTheme(std::string format_, TLObject theme_, long document_id_) {}

template <class X>
GetTheme<X> GetTheme<X>::read(Reader reader)
{
    std::string format_ = String::read(reader);
    TLObject theme_ = TLObject::read(reader);
    long document_id_ = Long::read(reader);
    return GetTheme<X>(format_, theme_, document_id_);
}

template <class X>
std::string GetTheme<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(format);
    buffer += theme.write();
    buffer += Long::write(document_id);
    return buffer;
}

template <class X>
GetThemes<X>::GetThemes(std::string format_, int hash_) {}

template <class X>
GetThemes<X> GetThemes<X>::read(Reader reader)
{
    std::string format_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetThemes<X>(format_, hash_);
}

template <class X>
std::string GetThemes<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(format);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
SetContentSettings<X>::SetContentSettings(std::optional<bool> sensitive_enabled_) {}

template <class X>
SetContentSettings<X> SetContentSettings<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> sensitive_enabled_;

    if (1 << 0)
        sensitive_enabled_ = true;
    else
        sensitive_enabled_ = std::nullopt;
    return SetContentSettings<X>(sensitive_enabled_);
}

template <class X>
std::string SetContentSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= sensitive_enabled ? 1 << 0 : 0;
    return buffer;
}
template <class X>
GetContentSettings<X> GetContentSettings<X>::read(Reader reader)
{
    return GetContentSettings<X>();
}

template <class X>
std::string GetContentSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetMultiWallPapers<X>::GetMultiWallPapers(std::vector<TLObject> wallpapers_) {}

template <class X>
GetMultiWallPapers<X> GetMultiWallPapers<X>::read(Reader reader)
{
    std::vector<TLObject> wallpapers_ = Vector<TLObject>::read(reader);
    return GetMultiWallPapers<X>(wallpapers_);
}

template <class X>
std::string GetMultiWallPapers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(wallpapers);
    return buffer;
}
template <class X>
GetGlobalPrivacySettings<X> GetGlobalPrivacySettings<X>::read(Reader reader)
{
    return GetGlobalPrivacySettings<X>();
}

template <class X>
std::string GetGlobalPrivacySettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SetGlobalPrivacySettings<X>::SetGlobalPrivacySettings(TLObject settings_) {}

template <class X>
SetGlobalPrivacySettings<X> SetGlobalPrivacySettings<X>::read(Reader reader)
{
    TLObject settings_ = TLObject::read(reader);
    return SetGlobalPrivacySettings<X>(settings_);
}

template <class X>
std::string SetGlobalPrivacySettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += settings.write();
    return buffer;
}

template <class X>
ReportProfilePhoto<X>::ReportProfilePhoto(TLObject peer_, TLObject photo_id_, TLObject reason_, std::string message_) {}

template <class X>
ReportProfilePhoto<X> ReportProfilePhoto<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject photo_id_ = TLObject::read(reader);
    TLObject reason_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    return ReportProfilePhoto<X>(peer_, photo_id_, reason_, message_);
}

template <class X>
std::string ReportProfilePhoto<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += photo_id.write();
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}
