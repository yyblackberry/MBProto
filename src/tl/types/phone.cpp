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

#include "tl/types/phone.h"

PhoneCall::PhoneCall(TLObject phone_call_, std::vector<TLObject> users_) {}

PhoneCall PhoneCall::read(Reader reader)
{
    TLObject phone_call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PhoneCall(phone_call_, users_);
}

std::string PhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += phone_call.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

GroupCall::GroupCall(TLObject call_, std::vector<TLObject> participants_, std::string participants_next_offset_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

GroupCall GroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> participants_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::string participants_next_offset_ = String::read(reader);
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GroupCall(call_, participants_, participants_next_offset_, chats_, users_);
}

std::string GroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<TLObject>::write(participants);
    buffer += String::write(participants_next_offset);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

GroupParticipants::GroupParticipants(int count_, std::vector<TLObject> participants_, std::string next_offset_, std::vector<TLObject> chats_, std::vector<TLObject> users_, int version_) {}

GroupParticipants GroupParticipants::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> participants_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::string next_offset_ = String::read(reader);
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int version_ = Int::read(reader);
    return GroupParticipants(count_, participants_, next_offset_, chats_, users_, version_);
}

std::string GroupParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(participants);
    buffer += String::write(next_offset);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    buffer += Int::write(version);
    return buffer;
}

JoinAsPeers::JoinAsPeers(std::vector<TLObject> peers_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

JoinAsPeers JoinAsPeers::read(Reader reader)
{
    std::vector<TLObject> peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return JoinAsPeers(peers_, chats_, users_);
}

std::string JoinAsPeers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(peers);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ExportedGroupCallInvite::ExportedGroupCallInvite(std::string link_) {}

ExportedGroupCallInvite ExportedGroupCallInvite::read(Reader reader)
{
    std::string link_ = String::read(reader);
    return ExportedGroupCallInvite(link_);
}

std::string ExportedGroupCallInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(link);
    return buffer;
}
