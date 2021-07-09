#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class PhoneCall
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

class GroupCall
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

class GroupParticipants
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

class JoinAsPeers
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

class ExportedGroupCallInvite
{
private:
    int __id = 0x204bd158;

public:
    std::string link;
    ExportedGroupCallInvite(std::string link_);
    static ExportedGroupCallInvite read(Reader reader);
    std::string write();
};
