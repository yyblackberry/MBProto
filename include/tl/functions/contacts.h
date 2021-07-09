#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetContactIDs
{
private:
    int __id = 0x2caa4a42;

public:
    int hash;
    GetContactIDs(int hash_);
    static GetContactIDs<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetStatuses
{
private:
    int __id = 0xc4a353ee;

public:
    GetStatuses() = default;
    static GetStatuses<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetContacts
{
private:
    int __id = 0xc023849f;

public:
    int hash;
    GetContacts(int hash_);
    static GetContacts<X> read(Reader reader);
    std::string write();
};

template <class X>
class ImportContacts
{
private:
    int __id = 0x2c800be5;

public:
    std::vector<TLObject> contacts;
    ImportContacts(std::vector<TLObject> contacts_);
    static ImportContacts<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteContacts
{
private:
    int __id = 0x96a0e00;

public:
    std::vector<TLObject> id;
    DeleteContacts(std::vector<TLObject> id_);
    static DeleteContacts<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteByPhones
{
private:
    int __id = 0x1013fd9e;

public:
    std::vector<std::string> phones;
    DeleteByPhones(std::vector<std::string> phones_);
    static DeleteByPhones<X> read(Reader reader);
    std::string write();
};

template <class X>
class Block
{
private:
    int __id = 0x68cc1411;

public:
    TLObject id;
    Block(TLObject id_);
    static Block<X> read(Reader reader);
    std::string write();
};

template <class X>
class Unblock
{
private:
    int __id = 0xbea65d50;

public:
    TLObject id;
    Unblock(TLObject id_);
    static Unblock<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetBlocked
{
private:
    int __id = 0xf57c350f;

public:
    int offset;
    int limit;
    GetBlocked(int offset_, int limit_);
    static GetBlocked<X> read(Reader reader);
    std::string write();
};

template <class X>
class Search
{
private:
    int __id = 0x11f812d8;

public:
    std::string q;
    int limit;
    Search(std::string q_, int limit_);
    static Search<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResolveUsername
{
private:
    int __id = 0xf93ccba3;

public:
    std::string username;
    ResolveUsername(std::string username_);
    static ResolveUsername<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetTopPeers
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
    static GetTopPeers<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResetTopPeerRating
{
private:
    int __id = 0x1ae373ac;

public:
    TLObject category;
    TLObject peer;
    ResetTopPeerRating(TLObject category_, TLObject peer_);
    static ResetTopPeerRating<X> read(Reader reader);
    std::string write();
};

template <class X>
class ResetSaved
{
private:
    int __id = 0x879537f1;

public:
    ResetSaved() = default;
    static ResetSaved<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSaved
{
private:
    int __id = 0x82f1e39f;

public:
    GetSaved() = default;
    static GetSaved<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleTopPeers
{
private:
    int __id = 0x8514bdda;

public:
    bool enabled;
    ToggleTopPeers(bool enabled_);
    static ToggleTopPeers<X> read(Reader reader);
    std::string write();
};

template <class X>
class AddContact
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
    static AddContact<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptContact
{
private:
    int __id = 0xf831a20f;

public:
    TLObject id;
    AcceptContact(TLObject id_);
    static AcceptContact<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetLocated
{
private:
    int __id = 0xd348bc44;

public:
    std::optional<bool> background;
    TLObject geo_point;
    std::optional<int> self_expires;
    GetLocated(TLObject geo_point_, std::optional<bool> background_ = std::nullopt, std::optional<int> self_expires_ = std::nullopt);
    static GetLocated<X> read(Reader reader);
    std::string write();
};

template <class X>
class BlockFromReplies
{
private:
    int __id = 0x29a8962c;

public:
    std::optional<bool> delete_message;
    std::optional<bool> delete_history;
    std::optional<bool> report_spam;
    int msg_id;
    BlockFromReplies(int msg_id_, std::optional<bool> delete_message_ = std::nullopt, std::optional<bool> delete_history_ = std::nullopt, std::optional<bool> report_spam_ = std::nullopt);
    static BlockFromReplies<X> read(Reader reader);
    std::string write();
};
