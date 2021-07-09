#include "tl/functions/auth.h"

template <class X>
SendCode<X>::SendCode(std::string phone_number_, int api_id_, std::string api_hash_, TLObject settings_) {}

template <class X>
SendCode<X> SendCode<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    TLObject settings_ = TLObject::read(reader);
    return SendCode<X>(phone_number_, api_id_, api_hash_, settings_);
}

template <class X>
std::string SendCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += settings.write();
    return buffer;
}

template <class X>
SignUp<X>::SignUp(std::string phone_number_, std::string phone_code_hash_, std::string first_name_, std::string last_name_) {}

template <class X>
SignUp<X> SignUp<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    return SignUp<X>(phone_number_, phone_code_hash_, first_name_, last_name_);
}

template <class X>
std::string SignUp<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    return buffer;
}

template <class X>
SignIn<X>::SignIn(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

template <class X>
SignIn<X> SignIn<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return SignIn<X>(phone_number_, phone_code_hash_, phone_code_);
}

template <class X>
std::string SignIn<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}
template <class X>
LogOut<X> LogOut<X>::read(Reader reader)
{
    return LogOut<X>();
}

template <class X>
std::string LogOut<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
ResetAuthorizations<X> ResetAuthorizations<X>::read(Reader reader)
{
    return ResetAuthorizations<X>();
}

template <class X>
std::string ResetAuthorizations<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ExportAuthorization<X>::ExportAuthorization(int dc_id_) {}

template <class X>
ExportAuthorization<X> ExportAuthorization<X>::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    return ExportAuthorization<X>(dc_id_);
}

template <class X>
std::string ExportAuthorization<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    return buffer;
}

template <class X>
ImportAuthorization<X>::ImportAuthorization(int id_, std::string bytes_) {}

template <class X>
ImportAuthorization<X> ImportAuthorization<X>::read(Reader reader)
{
    int id_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return ImportAuthorization<X>(id_, bytes_);
}

template <class X>
std::string ImportAuthorization<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Bytes::write(bytes);
    return buffer;
}

template <class X>
BindTempAuthKey<X>::BindTempAuthKey(long perm_auth_key_id_, long nonce_, int expires_at_, std::string encrypted_message_) {}

template <class X>
BindTempAuthKey<X> BindTempAuthKey<X>::read(Reader reader)
{
    long perm_auth_key_id_ = Long::read(reader);
    long nonce_ = Long::read(reader);
    int expires_at_ = Int::read(reader);
    std::string encrypted_message_ = Bytes::read(reader);
    return BindTempAuthKey<X>(perm_auth_key_id_, nonce_, expires_at_, encrypted_message_);
}

template <class X>
std::string BindTempAuthKey<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(perm_auth_key_id);
    buffer += Long::write(nonce);
    buffer += Int::write(expires_at);
    buffer += Bytes::write(encrypted_message);
    return buffer;
}

template <class X>
ImportBotAuthorization<X>::ImportBotAuthorization(int api_id_, std::string api_hash_, std::string bot_auth_token_) {}

template <class X>
ImportBotAuthorization<X> ImportBotAuthorization<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    std::string bot_auth_token_ = String::read(reader);
    return ImportBotAuthorization<X>(api_id_, api_hash_, bot_auth_token_);
}

template <class X>
std::string ImportBotAuthorization<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += String::write(bot_auth_token);
    return buffer;
}

template <class X>
CheckPassword<X>::CheckPassword(TLObject password_) {}

template <class X>
CheckPassword<X> CheckPassword<X>::read(Reader reader)
{
    TLObject password_ = TLObject::read(reader);
    return CheckPassword<X>(password_);
}

template <class X>
std::string CheckPassword<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    return buffer;
}
template <class X>
RequestPasswordRecovery<X> RequestPasswordRecovery<X>::read(Reader reader)
{
    return RequestPasswordRecovery<X>();
}

template <class X>
std::string RequestPasswordRecovery<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
RecoverPassword<X>::RecoverPassword(std::string code_) {}

template <class X>
RecoverPassword<X> RecoverPassword<X>::read(Reader reader)
{
    std::string code_ = String::read(reader);
    return RecoverPassword<X>(code_);
}

template <class X>
std::string RecoverPassword<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(code);
    return buffer;
}

template <class X>
ResendCode<X>::ResendCode(std::string phone_number_, std::string phone_code_hash_) {}

template <class X>
ResendCode<X> ResendCode<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    return ResendCode<X>(phone_number_, phone_code_hash_);
}

template <class X>
std::string ResendCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    return buffer;
}

template <class X>
CancelCode<X>::CancelCode(std::string phone_number_, std::string phone_code_hash_) {}

template <class X>
CancelCode<X> CancelCode<X>::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    return CancelCode<X>(phone_number_, phone_code_hash_);
}

template <class X>
std::string CancelCode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    return buffer;
}

template <class X>
DropTempAuthKeys<X>::DropTempAuthKeys(std::vector<long> except_auth_keys_) {}

template <class X>
DropTempAuthKeys<X> DropTempAuthKeys<X>::read(Reader reader)
{
    std::vector<long> except_auth_keys_ = Vector<long>::read(reader);
    return DropTempAuthKeys<X>(except_auth_keys_);
}

template <class X>
std::string DropTempAuthKeys<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(except_auth_keys);
    return buffer;
}

template <class X>
ExportLoginToken<X>::ExportLoginToken(int api_id_, std::string api_hash_, std::vector<int> except_ids_) {}

template <class X>
ExportLoginToken<X> ExportLoginToken<X>::read(Reader reader)
{
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    std::vector<int> except_ids_ = Vector<int>::read(reader);
    return ExportLoginToken<X>(api_id_, api_hash_, except_ids_);
}

template <class X>
std::string ExportLoginToken<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += Vector<int>::write(except_ids);
    return buffer;
}

template <class X>
ImportLoginToken<X>::ImportLoginToken(std::string token_) {}

template <class X>
ImportLoginToken<X> ImportLoginToken<X>::read(Reader reader)
{
    std::string token_ = Bytes::read(reader);
    return ImportLoginToken<X>(token_);
}

template <class X>
std::string ImportLoginToken<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(token);
    return buffer;
}

template <class X>
AcceptLoginToken<X>::AcceptLoginToken(std::string token_) {}

template <class X>
AcceptLoginToken<X> AcceptLoginToken<X>::read(Reader reader)
{
    std::string token_ = Bytes::read(reader);
    return AcceptLoginToken<X>(token_);
}

template <class X>
std::string AcceptLoginToken<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(token);
    return buffer;
}
