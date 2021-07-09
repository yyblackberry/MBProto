#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class ChannelParticipants
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

class ChannelParticipantsNotModified
{
private:
    int __id = 0xf0173fe9;

public:
    ChannelParticipantsNotModified() = default;
    static ChannelParticipantsNotModified read(Reader reader);
    std::string write();
};

class ChannelParticipant
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

class AdminLogResults
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
