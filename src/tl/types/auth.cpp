#include "tl/types/auth.h"

SentCode::SentCode(TLObject type_, std::string phone_code_hash_, std::optional<TLObject> next_type_, std::optional<int> timeout_) {}

SentCode SentCode::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject type_ = TLObject::read(reader);
    std::string phone_code_hash_ = String::read(reader);
    std::optional<TLObject> next_type_;

    if (1 << 1)
        next_type_ = TLObject::read(reader);
    else
        next_type_ = std::nullopt;
    std::optional<int> timeout_;

    if (1 << 2)
        timeout_ = Int::read(reader);
    else
        timeout_ = std::nullopt;
    return SentCode(type_, phone_code_hash_, next_type_, timeout_);
}

std::string SentCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= next_type ? 1 << 1 : 0;
    flags |= timeout ? 1 << 2 : 0;
    buffer += type.write();
    buffer += String::write(phone_code_hash);

    if (next_type)
        buffer += next_type.value().write();

    if (timeout)
        buffer += Int::write(timeout.value());
    return buffer;
}

Authorization::Authorization(TLObject user_, std::optional<int> tmp_sessions_) {}

Authorization Authorization::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> tmp_sessions_;

    if (1 << 0)
        tmp_sessions_ = Int::read(reader);
    else
        tmp_sessions_ = std::nullopt;
    TLObject user_ = TLObject::read(reader);
    return Authorization(user_, tmp_sessions_);
}

std::string Authorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= tmp_sessions ? 1 << 0 : 0;

    if (tmp_sessions)
        buffer += Int::write(tmp_sessions.value());
    buffer += user.write();
    return buffer;
}

AuthorizationSignUpRequired::AuthorizationSignUpRequired(std::optional<TLObject> terms_of_service_) {}

AuthorizationSignUpRequired AuthorizationSignUpRequired::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> terms_of_service_;

    if (1 << 0)
        terms_of_service_ = TLObject::read(reader);
    else
        terms_of_service_ = std::nullopt;
    return AuthorizationSignUpRequired(terms_of_service_);
}

std::string AuthorizationSignUpRequired::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= terms_of_service ? 1 << 0 : 0;

    if (terms_of_service)
        buffer += terms_of_service.value().write();
    return buffer;
}

ExportedAuthorization::ExportedAuthorization(int id_, std::string bytes_) {}

ExportedAuthorization ExportedAuthorization::read(Reader reader)
{
    int id_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return ExportedAuthorization(id_, bytes_);
}

std::string ExportedAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Bytes::write(bytes);
    return buffer;
}

PasswordRecovery::PasswordRecovery(std::string email_pattern_) {}

PasswordRecovery PasswordRecovery::read(Reader reader)
{
    std::string email_pattern_ = String::read(reader);
    return PasswordRecovery(email_pattern_);
}

std::string PasswordRecovery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email_pattern);
    return buffer;
}
CodeTypeSms CodeTypeSms::read(Reader reader)
{
    return CodeTypeSms();
}

std::string CodeTypeSms::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
CodeTypeCall CodeTypeCall::read(Reader reader)
{
    return CodeTypeCall();
}

std::string CodeTypeCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
CodeTypeFlashCall CodeTypeFlashCall::read(Reader reader)
{
    return CodeTypeFlashCall();
}

std::string CodeTypeFlashCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SentCodeTypeApp::SentCodeTypeApp(int length_) {}

SentCodeTypeApp SentCodeTypeApp::read(Reader reader)
{
    int length_ = Int::read(reader);
    return SentCodeTypeApp(length_);
}

std::string SentCodeTypeApp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(length);
    return buffer;
}

SentCodeTypeSms::SentCodeTypeSms(int length_) {}

SentCodeTypeSms SentCodeTypeSms::read(Reader reader)
{
    int length_ = Int::read(reader);
    return SentCodeTypeSms(length_);
}

std::string SentCodeTypeSms::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(length);
    return buffer;
}

SentCodeTypeCall::SentCodeTypeCall(int length_) {}

SentCodeTypeCall SentCodeTypeCall::read(Reader reader)
{
    int length_ = Int::read(reader);
    return SentCodeTypeCall(length_);
}

std::string SentCodeTypeCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(length);
    return buffer;
}

SentCodeTypeFlashCall::SentCodeTypeFlashCall(std::string pattern_) {}

SentCodeTypeFlashCall SentCodeTypeFlashCall::read(Reader reader)
{
    std::string pattern_ = String::read(reader);
    return SentCodeTypeFlashCall(pattern_);
}

std::string SentCodeTypeFlashCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(pattern);
    return buffer;
}

LoginToken::LoginToken(int expires_, std::string token_) {}

LoginToken LoginToken::read(Reader reader)
{
    int expires_ = Int::read(reader);
    std::string token_ = Bytes::read(reader);
    return LoginToken(expires_, token_);
}

std::string LoginToken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    buffer += Bytes::write(token);
    return buffer;
}

LoginTokenMigrateTo::LoginTokenMigrateTo(int dc_id_, std::string token_) {}

LoginTokenMigrateTo LoginTokenMigrateTo::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    std::string token_ = Bytes::read(reader);
    return LoginTokenMigrateTo(dc_id_, token_);
}

std::string LoginTokenMigrateTo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    buffer += Bytes::write(token);
    return buffer;
}

LoginTokenSuccess::LoginTokenSuccess(TLObject authorization_) {}

LoginTokenSuccess LoginTokenSuccess::read(Reader reader)
{
    TLObject authorization_ = TLObject::read(reader);
    return LoginTokenSuccess(authorization_);
}

std::string LoginTokenSuccess::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += authorization.write();
    return buffer;
}
