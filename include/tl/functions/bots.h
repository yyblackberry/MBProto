#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class SendCustomRequest
{
private:
    int __id = 0xaa2769ed;

public:
    std::string custom_method;
    TLObject params;
    SendCustomRequest(std::string custom_method_, TLObject params_);
    static SendCustomRequest<X> read(Reader reader);
    std::string write();
};

template <class X>
class AnswerWebhookJSONQuery
{
private:
    int __id = 0xe6213f4d;

public:
    long query_id;
    TLObject data;
    AnswerWebhookJSONQuery(long query_id_, TLObject data_);
    static AnswerWebhookJSONQuery<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetBotCommands
{
private:
    int __id = 0x517165a;

public:
    TLObject scope;
    std::string lang_code;
    std::vector<TLObject> commands;
    SetBotCommands(TLObject scope_, std::string lang_code_, std::vector<TLObject> commands_);
    static SetBotCommands<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResetBotCommands
{
private:
    int __id = 0x3d8de0f9;

public:
    TLObject scope;
    std::string lang_code;
    ResetBotCommands(TLObject scope_, std::string lang_code_);
    static ResetBotCommands<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetBotCommands
{
private:
    int __id = 0xe34c0dd6;

public:
    TLObject scope;
    std::string lang_code;
    GetBotCommands(TLObject scope_, std::string lang_code_);
    static GetBotCommands<X> read(Reader reader);
    std::string write();
};
