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

#include "tl/functions/auth.h"

SendCode::SendCode(std::string phone_number_, int api_id_, std::string api_hash_, TLObject settings_) {}

SendCode SendCode::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return SendCode(phone_number_, api_id_, api_hash_, settings_);
}

std::string SendCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += settings.write();
    return buffer;
}

SignUp::SignUp(std::string phone_number_, std::string phone_code_hash_, std::string first_name_, std::string last_name_) {}

SignUp SignUp::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    return SignUp(phone_number_, phone_code_hash_, first_name_, last_name_);
}

std::string SignUp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    return buffer;
}

SignIn::SignIn(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_) {}

SignIn SignIn::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::string phone_code_ = String::read(reader);
    return SignIn(phone_number_, phone_code_hash_, phone_code_);
}

std::string SignIn::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    buffer += String::write(phone_code);
    return buffer;
}
LogOut LogOut::read(Reader reader)
{
    return LogOut();
}

std::string LogOut::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
ResetAuthorizations ResetAuthorizations::read(Reader reader)
{
    return ResetAuthorizations();
}

std::string ResetAuthorizations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ExportAuthorization::ExportAuthorization(int dc_id_) {}

ExportAuthorization ExportAuthorization::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    return ExportAuthorization(dc_id_);
}

std::string ExportAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    return buffer;
}

ImportAuthorization::ImportAuthorization(int id_, std::string bytes_) {}

ImportAuthorization ImportAuthorization::read(Reader reader)
{
    int id_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return ImportAuthorization(id_, bytes_);
}

std::string ImportAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Bytes::write(bytes);
    return buffer;
}

BindTempAuthKey::BindTempAuthKey(long perm_auth_key_id_, long nonce_, int expires_at_, std::string encrypted_message_) {}

BindTempAuthKey BindTempAuthKey::read(Reader reader)
{
    long perm_auth_key_id_ = Long::read(reader);
    long nonce_ = Long::read(reader);
    int expires_at_ = Int::read(reader);
    std::string encrypted_message_ = Bytes::read(reader);
    return BindTempAuthKey(perm_auth_key_id_, nonce_, expires_at_, encrypted_message_);
}

std::string BindTempAuthKey::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(perm_auth_key_id);
    buffer += Long::write(nonce);
    buffer += Int::write(expires_at);
    buffer += Bytes::write(encrypted_message);
    return buffer;
}

ImportBotAuthorization::ImportBotAuthorization(int api_id_, std::string api_hash_, std::string bot_auth_token_) {}

ImportBotAuthorization ImportBotAuthorization::read(Reader reader)
{
    int flags = Int::read(reader);
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    std::string bot_auth_token_ = String::read(reader);
    return ImportBotAuthorization(api_id_, api_hash_, bot_auth_token_);
}

std::string ImportBotAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += String::write(bot_auth_token);
    return buffer;
}

CheckPassword::CheckPassword(TLObject password_) {}

CheckPassword CheckPassword::read(Reader reader)
{
    TLObject password_ = std::get<TLObject>(TLObject::read(reader));
    return CheckPassword(password_);
}

std::string CheckPassword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += password.write();
    return buffer;
}
RequestPasswordRecovery RequestPasswordRecovery::read(Reader reader)
{
    return RequestPasswordRecovery();
}

std::string RequestPasswordRecovery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

RecoverPassword::RecoverPassword(std::string code_) {}

RecoverPassword RecoverPassword::read(Reader reader)
{
    std::string code_ = String::read(reader);
    return RecoverPassword(code_);
}

std::string RecoverPassword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(code);
    return buffer;
}

ResendCode::ResendCode(std::string phone_number_, std::string phone_code_hash_) {}

ResendCode ResendCode::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    return ResendCode(phone_number_, phone_code_hash_);
}

std::string ResendCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    return buffer;
}

CancelCode::CancelCode(std::string phone_number_, std::string phone_code_hash_) {}

CancelCode CancelCode::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    return CancelCode(phone_number_, phone_code_hash_);
}

std::string CancelCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(phone_code_hash);
    return buffer;
}

DropTempAuthKeys::DropTempAuthKeys(std::vector<long> except_auth_keys_) {}

DropTempAuthKeys DropTempAuthKeys::read(Reader reader)
{
    std::vector<long> except_auth_keys_ = std::get<std::vector<long>>(TLObject::read(reader));
    return DropTempAuthKeys(except_auth_keys_);
}

std::string DropTempAuthKeys::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(except_auth_keys);
    return buffer;
}

ExportLoginToken::ExportLoginToken(int api_id_, std::string api_hash_, std::vector<int> except_ids_) {}

ExportLoginToken ExportLoginToken::read(Reader reader)
{
    int api_id_ = Int::read(reader);
    std::string api_hash_ = String::read(reader);
    std::vector<int> except_ids_ = std::get<std::vector<int>>(TLObject::read(reader));
    return ExportLoginToken(api_id_, api_hash_, except_ids_);
}

std::string ExportLoginToken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(api_id);
    buffer += String::write(api_hash);
    buffer += Vector<int>::write(except_ids);
    return buffer;
}

ImportLoginToken::ImportLoginToken(std::string token_) {}

ImportLoginToken ImportLoginToken::read(Reader reader)
{
    std::string token_ = Bytes::read(reader);
    return ImportLoginToken(token_);
}

std::string ImportLoginToken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(token);
    return buffer;
}

AcceptLoginToken::AcceptLoginToken(std::string token_) {}

AcceptLoginToken AcceptLoginToken::read(Reader reader)
{
    std::string token_ = Bytes::read(reader);
    return AcceptLoginToken(token_);
}

std::string AcceptLoginToken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(token);
    return buffer;
}
