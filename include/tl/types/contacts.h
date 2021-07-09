#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class ContactsNotModified
{
private:
    int __id = 0xb74ba9d2;

public:
    ContactsNotModified() = default;
    static ContactsNotModified read(Reader reader);
    std::string write();
};

class Contacts
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

class ImportedContacts
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

class Blocked
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

class BlockedSlice
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

class Found
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

class ResolvedPeer
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

class TopPeersNotModified
{
private:
    int __id = 0xde266ef5;

public:
    TopPeersNotModified() = default;
    static TopPeersNotModified read(Reader reader);
    std::string write();
};

class TopPeers
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

class TopPeersDisabled
{
private:
    int __id = 0xb52c939d;

public:
    TopPeersDisabled() = default;
    static TopPeersDisabled read(Reader reader);
    std::string write();
};
