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

class ContactsNotModified : public TLObject
{
private:
    int __id = 0xb74ba9d2;

public:
    ContactsNotModified() = default;
    static ContactsNotModified read(Reader reader);
    std::string write();
};

class Contacts : public TLObject
{
private:
    int __id = 0xeae87e42;

public:
    std::vector<TLObject> contacts;
    int saved_count;
    std::vector<TLObject> users;
    Contacts(std::vector<TLObject> contacts_, int saved_count_, std::vector<TLObject> users_);
    static Contacts read(Reader reader);
    std::string write();
};

class ImportedContacts : public TLObject
{
private:
    int __id = 0x77d01c3b;

public:
    std::vector<TLObject> imported;
    std::vector<TLObject> popular_invites;
    std::vector<long> retry_contacts;
    std::vector<TLObject> users;
    ImportedContacts(std::vector<TLObject> imported_, std::vector<TLObject> popular_invites_, std::vector<long> retry_contacts_, std::vector<TLObject> users_);
    static ImportedContacts read(Reader reader);
    std::string write();
};

class Blocked : public TLObject
{
private:
    int __id = 0xade1591;

public:
    std::vector<TLObject> blocked;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    Blocked(std::vector<TLObject> blocked_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static Blocked read(Reader reader);
    std::string write();
};

class BlockedSlice : public TLObject
{
private:
    int __id = 0xe1664194;

public:
    int count;
    std::vector<TLObject> blocked;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    BlockedSlice(int count_, std::vector<TLObject> blocked_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static BlockedSlice read(Reader reader);
    std::string write();
};

class Found : public TLObject
{
private:
    int __id = 0xb3134d9d;

public:
    std::vector<TLObject> my_results;
    std::vector<TLObject> results;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    Found(std::vector<TLObject> my_results_, std::vector<TLObject> results_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static Found read(Reader reader);
    std::string write();
};

class ResolvedPeer : public TLObject
{
private:
    int __id = 0x7f077ad9;

public:
    TLObject peer;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ResolvedPeer(TLObject peer_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static ResolvedPeer read(Reader reader);
    std::string write();
};

class TopPeersNotModified : public TLObject
{
private:
    int __id = 0xde266ef5;

public:
    TopPeersNotModified() = default;
    static TopPeersNotModified read(Reader reader);
    std::string write();
};

class TopPeers : public TLObject
{
private:
    int __id = 0x70b772a8;

public:
    std::vector<TLObject> categories;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    TopPeers(std::vector<TLObject> categories_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static TopPeers read(Reader reader);
    std::string write();
};

class TopPeersDisabled : public TLObject
{
private:
    int __id = 0xb52c939d;

public:
    TopPeersDisabled() = default;
    static TopPeersDisabled read(Reader reader);
    std::string write();
};
