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

#include "tl/functions/bots.h"

SendCustomRequest::SendCustomRequest(std::string custom_method_, TLObject params_) {}

SendCustomRequest SendCustomRequest::read(Reader reader)
{
    std::string custom_method_ = String::read(reader);
    TLObject params_ = std::get<TLObject>(TLObject::read(reader));
    return SendCustomRequest(custom_method_, params_);
}

std::string SendCustomRequest::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(custom_method);
    buffer += params.write();
    return buffer;
}

AnswerWebhookJSONQuery::AnswerWebhookJSONQuery(long query_id_, TLObject data_) {}

AnswerWebhookJSONQuery AnswerWebhookJSONQuery::read(Reader reader)
{
    long query_id_ = Long::read(reader);
    TLObject data_ = std::get<TLObject>(TLObject::read(reader));
    return AnswerWebhookJSONQuery(query_id_, data_);
}

std::string AnswerWebhookJSONQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(query_id);
    buffer += data.write();
    return buffer;
}

SetBotCommands::SetBotCommands(TLObject scope_, std::string lang_code_, std::vector<TLObject> commands_) {}

SetBotCommands SetBotCommands::read(Reader reader)
{
    TLObject scope_ = std::get<TLObject>(TLObject::read(reader));
    std::string lang_code_ = String::read(reader);
    std::vector<TLObject> commands_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SetBotCommands(scope_, lang_code_, commands_);
}

std::string SetBotCommands::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    buffer += Vector<TLObject>::write(commands);
    return buffer;
}

ResetBotCommands::ResetBotCommands(TLObject scope_, std::string lang_code_) {}

ResetBotCommands ResetBotCommands::read(Reader reader)
{
    TLObject scope_ = std::get<TLObject>(TLObject::read(reader));
    std::string lang_code_ = String::read(reader);
    return ResetBotCommands(scope_, lang_code_);
}

std::string ResetBotCommands::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    return buffer;
}

GetBotCommands::GetBotCommands(TLObject scope_, std::string lang_code_) {}

GetBotCommands GetBotCommands::read(Reader reader)
{
    TLObject scope_ = std::get<TLObject>(TLObject::read(reader));
    std::string lang_code_ = String::read(reader);
    return GetBotCommands(scope_, lang_code_);
}

std::string GetBotCommands::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += scope.write();
    buffer += String::write(lang_code);
    return buffer;
}
