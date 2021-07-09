#include "tl/functions/bots.h"

template <class X>
SendCustomRequest<X>::SendCustomRequest(std::string custom_method_, TLObject params_) {}

template <class X>
SendCustomRequest<X> SendCustomRequest<X>::read(Reader reader)
{
    std::string custom_method_ = String::read(reader);
    TLObject params_ = TLObject::read(reader);
    return SendCustomRequest<X>(custom_method_, params_);
}

template <class X>
std::string SendCustomRequest<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(custom_method);
    buffer += params.write();
    return buffer;
}

template <class X>
AnswerWebhookJSONQuery<X>::AnswerWebhookJSONQuery(long query_id_, TLObject data_) {}

template <class X>
AnswerWebhookJSONQuery<X> AnswerWebhookJSONQuery<X>::read(Reader reader)
{
    long query_id_ = Long::read(reader);
    TLObject data_ = TLObject::read(reader);
    return AnswerWebhookJSONQuery<X>(query_id_, data_);
}

template <class X>
std::string AnswerWebhookJSONQuery<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(query_id);
    buffer += data.write();
    return buffer;
}

template <class X>
SetBotCommands<X>::SetBotCommands(TLObject scope_, std::string lang_code_, std::vector<TLObject> commands_) {}

template <class X>
SetBotCommands<X> SetBotCommands<X>::read(Reader reader)
{
    TLObject scope_ = TLObject::read(reader);
    std::string lang_code_ = String::read(reader);
    std::vector<TLObject> commands_ = Vector<TLObject>::read(reader);
    return SetBotCommands<X>(scope_, lang_code_, commands_);
}

template <class X>
std::string SetBotCommands<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    buffer += Vector<TLObject>::write(commands);
    return buffer;
}

template <class X>
ResetBotCommands<X>::ResetBotCommands(TLObject scope_, std::string lang_code_) {}

template <class X>
ResetBotCommands<X> ResetBotCommands<X>::read(Reader reader)
{
    TLObject scope_ = TLObject::read(reader);
    std::string lang_code_ = String::read(reader);
    return ResetBotCommands<X>(scope_, lang_code_);
}

template <class X>
std::string ResetBotCommands<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    return buffer;
}

template <class X>
GetBotCommands<X>::GetBotCommands(TLObject scope_, std::string lang_code_) {}

template <class X>
GetBotCommands<X> GetBotCommands<X>::read(Reader reader)
{
    TLObject scope_ = TLObject::read(reader);
    std::string lang_code_ = String::read(reader);
    return GetBotCommands<X>(scope_, lang_code_);
}

template <class X>
std::string GetBotCommands<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    return buffer;
}
