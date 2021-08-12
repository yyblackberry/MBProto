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

#include "tl/types/channels.h"

ChannelParticipants::ChannelParticipants(int count_, std::vector<TLObject> participants_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ChannelParticipants ChannelParticipants::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> participants_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelParticipants(count_, participants_, chats_, users_);
}

std::string ChannelParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(participants);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
ChannelParticipantsNotModified ChannelParticipantsNotModified::read(Reader reader)
{
    return ChannelParticipantsNotModified();
}

std::string ChannelParticipantsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelParticipant::ChannelParticipant(TLObject participant_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ChannelParticipant ChannelParticipant::read(Reader reader)
{
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelParticipant(participant_, chats_, users_);
}

std::string ChannelParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

AdminLogResults::AdminLogResults(std::vector<TLObject> events_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

AdminLogResults AdminLogResults::read(Reader reader)
{
    std::vector<TLObject> events_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return AdminLogResults(events_, chats_, users_);
}

std::string AdminLogResults::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(events);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
