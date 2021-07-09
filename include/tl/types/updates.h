#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class State
{
private:
    int __id = 0xa56c2a3e;

public:
    int pts;
    int qts;
    int date;
    int seq;
    int unread_count;
    State(int pts_, int qts_, int date_, int seq_, int unread_count_);
    static State read(Reader reader);
    std::string write();
};

class DifferenceEmpty
{
private:
    int __id = 0x5d75a138;

public:
    int date;
    int seq;
    DifferenceEmpty(int date_, int seq_);
    static DifferenceEmpty read(Reader reader);
    std::string write();
};

class Difference
{
private:
    int __id = 0xf49ca0;

public:
    std::vector<TLObject> new_messages;
    std::vector<TLObject> new_encrypted_messages;
    std::vector<TLObject> other_updates;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    TLObject state;
    Difference(std::vector<TLObject> new_messages_, std::vector<TLObject> new_encrypted_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject state_);
    static Difference read(Reader reader);
    std::string write();
};

class DifferenceSlice
{
private:
    int __id = 0xa8fb1981;

public:
    std::vector<TLObject> new_messages;
    std::vector<TLObject> new_encrypted_messages;
    std::vector<TLObject> other_updates;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    TLObject intermediate_state;
    DifferenceSlice(std::vector<TLObject> new_messages_, std::vector<TLObject> new_encrypted_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject intermediate_state_);
    static DifferenceSlice read(Reader reader);
    std::string write();
};

class DifferenceTooLong
{
private:
    int __id = 0x4afe8f6d;

public:
    int pts;
    DifferenceTooLong(int pts_);
    static DifferenceTooLong read(Reader reader);
    std::string write();
};

class ChannelDifferenceEmpty
{
private:
    int __id = 0x3e11affb;

public:
    std::optional<bool> final;
    int pts;
    std::optional<int> timeout;
    ChannelDifferenceEmpty(int pts_, std::optional<bool> final_ = std::nullopt, std::optional<int> timeout_ = std::nullopt);
    static ChannelDifferenceEmpty read(Reader reader);
    std::string write();
};

class ChannelDifferenceTooLong
{
private:
    int __id = 0xa4bcc6fe;

public:
    std::optional<bool> final;
    std::optional<int> timeout;
    TLObject dialog;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChannelDifferenceTooLong(TLObject dialog_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> final_ = std::nullopt, std::optional<int> timeout_ = std::nullopt);
    static ChannelDifferenceTooLong read(Reader reader);
    std::string write();
};

class ChannelDifference
{
private:
    int __id = 0x2064674e;

public:
    std::optional<bool> final;
    int pts;
    std::optional<int> timeout;
    std::vector<TLObject> new_messages;
    std::vector<TLObject> other_updates;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChannelDifference(int pts_, std::vector<TLObject> new_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> final_ = std::nullopt, std::optional<int> timeout_ = std::nullopt);
    static ChannelDifference read(Reader reader);
    std::string write();
};
