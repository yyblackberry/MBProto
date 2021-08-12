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

class PhoneCall : public TLObject
{
private:
    int __id = 0xec82e140;

public:
    TLObject phone_call;
    std::vector<TLObject> users;
    PhoneCall(TLObject phone_call_, std::vector<TLObject> users_);
    static PhoneCall read(Reader reader);
    std::string write();
};

class GroupCall : public TLObject
{
private:
    int __id = 0x9e727aad;

public:
    TLObject call;
    std::vector<TLObject> participants;
    std::string participants_next_offset;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    GroupCall(TLObject call_, std::vector<TLObject> participants_, std::string participants_next_offset_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static GroupCall read(Reader reader);
    std::string write();
};

class GroupParticipants : public TLObject
{
private:
    int __id = 0xf47751b6;

public:
    int count;
    std::vector<TLObject> participants;
    std::string next_offset;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    int version;
    GroupParticipants(int count_, std::vector<TLObject> participants_, std::string next_offset_, std::vector<TLObject> chats_, std::vector<TLObject> users_, int version_);
    static GroupParticipants read(Reader reader);
    std::string write();
};

class JoinAsPeers : public TLObject
{
private:
    int __id = 0xafe5623f;

public:
    std::vector<TLObject> peers;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    JoinAsPeers(std::vector<TLObject> peers_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static JoinAsPeers read(Reader reader);
    std::string write();
};

class ExportedGroupCallInvite : public TLObject
{
private:
    int __id = 0x204bd158;

public:
    std::string link;
    ExportedGroupCallInvite(std::string link_);
    static ExportedGroupCallInvite read(Reader reader);
    std::string write();
};
