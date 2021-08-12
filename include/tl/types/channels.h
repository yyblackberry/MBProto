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

class ChannelParticipants : public TLObject
{
private:
    int __id = 0x9ab0feaf;

public:
    int count;
    std::vector<TLObject> participants;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChannelParticipants(int count_, std::vector<TLObject> participants_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static ChannelParticipants read(Reader reader);
    std::string write();
};

class ChannelParticipantsNotModified : public TLObject
{
private:
    int __id = 0xf0173fe9;

public:
    ChannelParticipantsNotModified() = default;
    static ChannelParticipantsNotModified read(Reader reader);
    std::string write();
};

class ChannelParticipant : public TLObject
{
private:
    int __id = 0xdfb80317;

public:
    TLObject participant;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChannelParticipant(TLObject participant_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static ChannelParticipant read(Reader reader);
    std::string write();
};

class AdminLogResults : public TLObject
{
private:
    int __id = 0xed8af74d;

public:
    std::vector<TLObject> events;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    AdminLogResults(std::vector<TLObject> events_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static AdminLogResults read(Reader reader);
    std::string write();
};
