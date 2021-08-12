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

class GetContactIDs : public TLObject
{
private:
    int __id = 0x2caa4a42;

public:
    int hash;
    GetContactIDs(int hash_);
    static GetContactIDs read(Reader reader);
    std::string write();
};

class GetStatuses : public TLObject
{
private:
    int __id = 0xc4a353ee;

public:
    GetStatuses() = default;
    static GetStatuses read(Reader reader);
    std::string write();
};

class GetContacts : public TLObject
{
private:
    int __id = 0xc023849f;

public:
    int hash;
    GetContacts(int hash_);
    static GetContacts read(Reader reader);
    std::string write();
};

class ImportContacts : public TLObject
{
private:
    int __id = 0x2c800be5;

public:
    std::vector<TLObject> contacts;
    ImportContacts(std::vector<TLObject> contacts_);
    static ImportContacts read(Reader reader);
    std::string write();
};

class DeleteContacts : public TLObject
{
private:
    int __id = 0x96a0e00;

public:
    std::vector<TLObject> id;
    DeleteContacts(std::vector<TLObject> id_);
    static DeleteContacts read(Reader reader);
    std::string write();
};

class DeleteByPhones : public TLObject
{
private:
    int __id = 0x1013fd9e;

public:
    std::vector<std::string> phones;
    DeleteByPhones(std::vector<std::string> phones_);
    static DeleteByPhones read(Reader reader);
    std::string write();
};

class Block : public TLObject
{
private:
    int __id = 0x68cc1411;

public:
    TLObject id;
    Block(TLObject id_);
    static Block read(Reader reader);
    std::string write();
};

class Unblock : public TLObject
{
private:
    int __id = 0xbea65d50;

public:
    TLObject id;
    Unblock(TLObject id_);
    static Unblock read(Reader reader);
    std::string write();
};

class GetBlocked : public TLObject
{
private:
    int __id = 0xf57c350f;

public:
    int offset;
    int limit;
    GetBlocked(int offset_, int limit_);
    static GetBlocked read(Reader reader);
    std::string write();
};

class Search : public TLObject
{
private:
    int __id = 0x11f812d8;

public:
    std::string q;
    int limit;
    Search(std::string q_, int limit_);
    static Search read(Reader reader);
    std::string write();
};

class ResolveUsername : public TLObject
{
private:
    int __id = 0xf93ccba3;

public:
    std::string username;
    ResolveUsername(std::string username_);
    static ResolveUsername read(Reader reader);
    std::string write();
};

class GetTopPeers : public TLObject
{
private:
    int __id = 0xd4982db5;

public:
    std::optional<bool> correspondents;
    std::optional<bool> bots_pm;
    std::optional<bool> bots_inline;
    std::optional<bool> phone_calls;
    std::optional<bool> forward_users;
    std::optional<bool> forward_chats;
    std::optional<bool> groups;
    std::optional<bool> channels;
    int offset;
    int limit;
    int hash;
    GetTopPeers(int offset_, int limit_, int hash_, std::optional<bool> correspondents_ = std::nullopt, std::optional<bool> bots_pm_ = std::nullopt, std::optional<bool> bots_inline_ = std::nullopt, std::optional<bool> phone_calls_ = std::nullopt, std::optional<bool> forward_users_ = std::nullopt, std::optional<bool> forward_chats_ = std::nullopt, std::optional<bool> groups_ = std::nullopt, std::optional<bool> channels_ = std::nullopt);
    static GetTopPeers read(Reader reader);
    std::string write();
};

class ResetTopPeerRating : public TLObject
{
private:
    int __id = 0x1ae373ac;

public:
    TLObject category;
    TLObject peer;
    ResetTopPeerRating(TLObject category_, TLObject peer_);
    static ResetTopPeerRating read(Reader reader);
    std::string write();
};

class ResetSaved : public TLObject
{
private:
    int __id = 0x879537f1;

public:
    ResetSaved() = default;
    static ResetSaved read(Reader reader);
    std::string write();
};

class GetSaved : public TLObject
{
private:
    int __id = 0x82f1e39f;

public:
    GetSaved() = default;
    static GetSaved read(Reader reader);
    std::string write();
};

class ToggleTopPeers : public TLObject
{
private:
    int __id = 0x8514bdda;

public:
    bool enabled;
    ToggleTopPeers(bool enabled_);
    static ToggleTopPeers read(Reader reader);
    std::string write();
};

class AddContact : public TLObject
{
private:
    int __id = 0xe8f463d0;

public:
    std::optional<bool> add_phone_privacy_exception;
    TLObject id;
    std::string first_name;
    std::string last_name;
    std::string phone;
    AddContact(TLObject id_, std::string first_name_, std::string last_name_, std::string phone_, std::optional<bool> add_phone_privacy_exception_ = std::nullopt);
    static AddContact read(Reader reader);
    std::string write();
};

class AcceptContact : public TLObject
{
private:
    int __id = 0xf831a20f;

public:
    TLObject id;
    AcceptContact(TLObject id_);
    static AcceptContact read(Reader reader);
    std::string write();
};

class GetLocated : public TLObject
{
private:
    int __id = 0xd348bc44;

public:
    std::optional<bool> background;
    TLObject geo_point;
    std::optional<int> self_expires;
    GetLocated(TLObject geo_point_, std::optional<bool> background_ = std::nullopt, std::optional<int> self_expires_ = std::nullopt);
    static GetLocated read(Reader reader);
    std::string write();
};

class BlockFromReplies : public TLObject
{
private:
    int __id = 0x29a8962c;

public:
    std::optional<bool> delete_message;
    std::optional<bool> delete_history;
    std::optional<bool> report_spam;
    int msg_id;
    BlockFromReplies(int msg_id_, std::optional<bool> delete_message_ = std::nullopt, std::optional<bool> delete_history_ = std::nullopt, std::optional<bool> report_spam_ = std::nullopt);
    static BlockFromReplies read(Reader reader);
    std::string write();
};
