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

class SendCode : public TLObject
{
private:
    int __id = 0xa677244f;

public:
    std::string phone_number;
    int api_id;
    std::string api_hash;
    TLObject settings;
    SendCode(std::string phone_number_, int api_id_, std::string api_hash_, TLObject settings_);
    static SendCode read(Reader reader);
    std::string write();
};

class SignUp : public TLObject
{
private:
    int __id = 0x80eee427;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string first_name;
    std::string last_name;
    SignUp(std::string phone_number_, std::string phone_code_hash_, std::string first_name_, std::string last_name_);
    static SignUp read(Reader reader);
    std::string write();
};

class SignIn : public TLObject
{
private:
    int __id = 0xbcd51581;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string phone_code;
    SignIn(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_);
    static SignIn read(Reader reader);
    std::string write();
};

class LogOut : public TLObject
{
private:
    int __id = 0x5717da40;

public:
    LogOut() = default;
    static LogOut read(Reader reader);
    std::string write();
};

class ResetAuthorizations : public TLObject
{
private:
    int __id = 0x9fab0d1a;

public:
    ResetAuthorizations() = default;
    static ResetAuthorizations read(Reader reader);
    std::string write();
};

class ExportAuthorization : public TLObject
{
private:
    int __id = 0xe5bfffcd;

public:
    int dc_id;
    ExportAuthorization(int dc_id_);
    static ExportAuthorization read(Reader reader);
    std::string write();
};

class ImportAuthorization : public TLObject
{
private:
    int __id = 0xe3ef9613;

public:
    int id;
    std::string bytes;
    ImportAuthorization(int id_, std::string bytes_);
    static ImportAuthorization read(Reader reader);
    std::string write();
};

class BindTempAuthKey : public TLObject
{
private:
    int __id = 0xcdd42a05;

public:
    long perm_auth_key_id;
    long nonce;
    int expires_at;
    std::string encrypted_message;
    BindTempAuthKey(long perm_auth_key_id_, long nonce_, int expires_at_, std::string encrypted_message_);
    static BindTempAuthKey read(Reader reader);
    std::string write();
};

class ImportBotAuthorization : public TLObject
{
private:
    int __id = 0x67a3ff2c;

public:
    int api_id;
    std::string api_hash;
    std::string bot_auth_token;
    ImportBotAuthorization(int api_id_, std::string api_hash_, std::string bot_auth_token_);
    static ImportBotAuthorization read(Reader reader);
    std::string write();
};

class CheckPassword : public TLObject
{
private:
    int __id = 0xd18b4d16;

public:
    TLObject password;
    CheckPassword(TLObject password_);
    static CheckPassword read(Reader reader);
    std::string write();
};

class RequestPasswordRecovery : public TLObject
{
private:
    int __id = 0xd897bc66;

public:
    RequestPasswordRecovery() = default;
    static RequestPasswordRecovery read(Reader reader);
    std::string write();
};

class RecoverPassword : public TLObject
{
private:
    int __id = 0x4ea56e92;

public:
    std::string code;
    RecoverPassword(std::string code_);
    static RecoverPassword read(Reader reader);
    std::string write();
};

class ResendCode : public TLObject
{
private:
    int __id = 0x3ef1a9bf;

public:
    std::string phone_number;
    std::string phone_code_hash;
    ResendCode(std::string phone_number_, std::string phone_code_hash_);
    static ResendCode read(Reader reader);
    std::string write();
};

class CancelCode : public TLObject
{
private:
    int __id = 0x1f040578;

public:
    std::string phone_number;
    std::string phone_code_hash;
    CancelCode(std::string phone_number_, std::string phone_code_hash_);
    static CancelCode read(Reader reader);
    std::string write();
};

class DropTempAuthKeys : public TLObject
{
private:
    int __id = 0x8e48a188;

public:
    std::vector<long> except_auth_keys;
    DropTempAuthKeys(std::vector<long> except_auth_keys_);
    static DropTempAuthKeys read(Reader reader);
    std::string write();
};

class ExportLoginToken : public TLObject
{
private:
    int __id = 0xb1b41517;

public:
    int api_id;
    std::string api_hash;
    std::vector<int> except_ids;
    ExportLoginToken(int api_id_, std::string api_hash_, std::vector<int> except_ids_);
    static ExportLoginToken read(Reader reader);
    std::string write();
};

class ImportLoginToken : public TLObject
{
private:
    int __id = 0x95ac5ce4;

public:
    std::string token;
    ImportLoginToken(std::string token_);
    static ImportLoginToken read(Reader reader);
    std::string write();
};

class AcceptLoginToken : public TLObject
{
private:
    int __id = 0xe894ad4d;

public:
    std::string token;
    AcceptLoginToken(std::string token_);
    static AcceptLoginToken read(Reader reader);
    std::string write();
};
