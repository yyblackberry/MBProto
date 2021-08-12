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

class SendCustomRequest : public TLObject
{
private:
    int __id = 0xaa2769ed;

public:
    std::string custom_method;
    TLObject params;
    SendCustomRequest(std::string custom_method_, TLObject params_);
    static SendCustomRequest read(Reader reader);
    std::string write();
};

class AnswerWebhookJSONQuery : public TLObject
{
private:
    int __id = 0xe6213f4d;

public:
    long query_id;
    TLObject data;
    AnswerWebhookJSONQuery(long query_id_, TLObject data_);
    static AnswerWebhookJSONQuery read(Reader reader);
    std::string write();
};

class SetBotCommands : public TLObject
{
private:
    int __id = 0x517165a;

public:
    TLObject scope;
    std::string lang_code;
    std::vector<TLObject> commands;
    SetBotCommands(TLObject scope_, std::string lang_code_, std::vector<TLObject> commands_);
    static SetBotCommands read(Reader reader);
    std::string write();
};

class ResetBotCommands : public TLObject
{
private:
    int __id = 0x3d8de0f9;

public:
    TLObject scope;
    std::string lang_code;
    ResetBotCommands(TLObject scope_, std::string lang_code_);
    static ResetBotCommands read(Reader reader);
    std::string write();
};

class GetBotCommands : public TLObject
{
private:
    int __id = 0xe34c0dd6;

public:
    TLObject scope;
    std::string lang_code;
    GetBotCommands(TLObject scope_, std::string lang_code_);
    static GetBotCommands read(Reader reader);
    std::string write();
};
