#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class SendCode
{
private:
    int __id = 0xa677244f;

public:
    std::string phone_number;
    int api_id;
    std::string api_hash;
    TLObject settings;
    SendCode(std::string phone_number_, int api_id_, std::string api_hash_, TLObject settings_);
    static SendCode<X> read(Reader reader);
    std::string write();
};

template <class X>
class SignUp
{
private:
    int __id = 0x80eee427;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string first_name;
    std::string last_name;
    SignUp(std::string phone_number_, std::string phone_code_hash_, std::string first_name_, std::string last_name_);
    static SignUp<X> read(Reader reader);
    std::string write();
};

template <class X>
class SignIn
{
private:
    int __id = 0xbcd51581;

public:
    std::string phone_number;
    std::string phone_code_hash;
    std::string phone_code;
    SignIn(std::string phone_number_, std::string phone_code_hash_, std::string phone_code_);
    static SignIn<X> read(Reader reader);
    std::string write();
};

template <class X>
class LogOut
{
private:
    int __id = 0x5717da40;

public:
    LogOut() = default;
    static LogOut<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResetAuthorizations
{
private:
    int __id = 0x9fab0d1a;

public:
    ResetAuthorizations() = default;
    static ResetAuthorizations<X> read(Reader reader);
    std::string write();
};

template <class X>
class ExportAuthorization
{
private:
    int __id = 0xe5bfffcd;

public:
    int dc_id;
    ExportAuthorization(int dc_id_);
    static ExportAuthorization<X> read(Reader reader);
    std::string write();
};

template <class X>
class ImportAuthorization
{
private:
    int __id = 0xe3ef9613;

public:
    int id;
    std::string bytes;
    ImportAuthorization(int id_, std::string bytes_);
    static ImportAuthorization<X> read(Reader reader);
    std::string write();
};

template <class X>
class BindTempAuthKey
{
private:
    int __id = 0xcdd42a05;

public:
    long perm_auth_key_id;
    long nonce;
    int expires_at;
    std::string encrypted_message;
    BindTempAuthKey(long perm_auth_key_id_, long nonce_, int expires_at_, std::string encrypted_message_);
    static BindTempAuthKey<X> read(Reader reader);
    std::string write();
};

template <class X>
class ImportBotAuthorization
{
private:
    int __id = 0x67a3ff2c;

public:
    int api_id;
    std::string api_hash;
    std::string bot_auth_token;
    ImportBotAuthorization(int api_id_, std::string api_hash_, std::string bot_auth_token_);
    static ImportBotAuthorization<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckPassword
{
private:
    int __id = 0xd18b4d16;

public:
    TLObject password;
    CheckPassword(TLObject password_);
    static CheckPassword<X> read(Reader reader);
    std::string write();
};

template <class X>
class RequestPasswordRecovery
{
private:
    int __id = 0xd897bc66;

public:
    RequestPasswordRecovery() = default;
    static RequestPasswordRecovery<X> read(Reader reader);
    std::string write();
};

template <class X>
class RecoverPassword
{
private:
    int __id = 0x4ea56e92;

public:
    std::string code;
    RecoverPassword(std::string code_);
    static RecoverPassword<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResendCode
{
private:
    int __id = 0x3ef1a9bf;

public:
    std::string phone_number;
    std::string phone_code_hash;
    ResendCode(std::string phone_number_, std::string phone_code_hash_);
    static ResendCode<X> read(Reader reader);
    std::string write();
};

template <class X>
class CancelCode
{
private:
    int __id = 0x1f040578;

public:
    std::string phone_number;
    std::string phone_code_hash;
    CancelCode(std::string phone_number_, std::string phone_code_hash_);
    static CancelCode<X> read(Reader reader);
    std::string write();
};

template <class X>
class DropTempAuthKeys
{
private:
    int __id = 0x8e48a188;

public:
    std::vector<long> except_auth_keys;
    DropTempAuthKeys(std::vector<long> except_auth_keys_);
    static DropTempAuthKeys<X> read(Reader reader);
    std::string write();
};

template <class X>
class ExportLoginToken
{
private:
    int __id = 0xb1b41517;

public:
    int api_id;
    std::string api_hash;
    std::vector<int> except_ids;
    ExportLoginToken(int api_id_, std::string api_hash_, std::vector<int> except_ids_);
    static ExportLoginToken<X> read(Reader reader);
    std::string write();
};

template <class X>
class ImportLoginToken
{
private:
    int __id = 0x95ac5ce4;

public:
    std::string token;
    ImportLoginToken(std::string token_);
    static ImportLoginToken<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptLoginToken
{
private:
    int __id = 0xe894ad4d;

public:
    std::string token;
    AcceptLoginToken(std::string token_);
    static AcceptLoginToken<X> read(Reader reader);
    std::string write();
};
