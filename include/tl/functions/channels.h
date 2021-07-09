#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class ReadHistory
{
private:
    int __id = 0xcc104937;

public:
    TLObject channel;
    int max_id;
    ReadHistory(TLObject channel_, int max_id_);
    static ReadHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteMessages
{
private:
    int __id = 0x84c1fd4e;

public:
    TLObject channel;
    std::vector<int> id;
    DeleteMessages(TLObject channel_, std::vector<int> id_);
    static DeleteMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteUserHistory
{
private:
    int __id = 0xd10dd71b;

public:
    TLObject channel;
    TLObject user_id;
    DeleteUserHistory(TLObject channel_, TLObject user_id_);
    static DeleteUserHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReportSpam
{
private:
    int __id = 0xfe087810;

public:
    TLObject channel;
    TLObject user_id;
    std::vector<int> id;
    ReportSpam(TLObject channel_, TLObject user_id_, std::vector<int> id_);
    static ReportSpam<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMessages
{
private:
    int __id = 0xad8c9a23;

public:
    TLObject channel;
    std::vector<TLObject> id;
    GetMessages(TLObject channel_, std::vector<TLObject> id_);
    static GetMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetParticipants
{
private:
    int __id = 0x123e05e9;

public:
    TLObject channel;
    TLObject filter;
    int offset;
    int limit;
    int hash;
    GetParticipants(TLObject channel_, TLObject filter_, int offset_, int limit_, int hash_);
    static GetParticipants<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetParticipant
{
private:
    int __id = 0xa0ab6cc6;

public:
    TLObject channel;
    TLObject participant;
    GetParticipant(TLObject channel_, TLObject participant_);
    static GetParticipant<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetChannels
{
private:
    int __id = 0xa7f6bbb;

public:
    std::vector<TLObject> id;
    GetChannels(std::vector<TLObject> id_);
    static GetChannels<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFullChannel
{
private:
    int __id = 0x8736a09;

public:
    TLObject channel;
    GetFullChannel(TLObject channel_);
    static GetFullChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class CreateChannel
{
private:
    int __id = 0x3d5fb10f;

public:
    std::optional<bool> broadcast;
    std::optional<bool> megagroup;
    std::optional<bool> for_import;
    std::string title;
    std::string about;
    std::optional<TLObject> geo_point;
    std::optional<std::string> address;
    CreateChannel(std::string title_, std::string about_, std::optional<bool> broadcast_ = std::nullopt, std::optional<bool> megagroup_ = std::nullopt, std::optional<bool> for_import_ = std::nullopt, std::optional<TLObject> geo_point_ = std::nullopt, std::optional<std::string> address_ = std::nullopt);
    static CreateChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditAdmin
{
private:
    int __id = 0xd33c8902;

public:
    TLObject channel;
    TLObject user_id;
    TLObject admin_rights;
    std::string rank;
    EditAdmin(TLObject channel_, TLObject user_id_, TLObject admin_rights_, std::string rank_);
    static EditAdmin<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditTitle
{
private:
    int __id = 0x566decd0;

public:
    TLObject channel;
    std::string title;
    EditTitle(TLObject channel_, std::string title_);
    static EditTitle<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditPhoto
{
private:
    int __id = 0xf12e57c9;

public:
    TLObject channel;
    TLObject photo;
    EditPhoto(TLObject channel_, TLObject photo_);
    static EditPhoto<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckUsername
{
private:
    int __id = 0x10e6bd2c;

public:
    TLObject channel;
    std::string username;
    CheckUsername(TLObject channel_, std::string username_);
    static CheckUsername<X> read(Reader reader);
    std::string write();
};

template <class X>
class UpdateUsername
{
private:
    int __id = 0x3514b3de;

public:
    TLObject channel;
    std::string username;
    UpdateUsername(TLObject channel_, std::string username_);
    static UpdateUsername<X> read(Reader reader);
    std::string write();
};

template <class X>
class JoinChannel
{
private:
    int __id = 0x24b524c5;

public:
    TLObject channel;
    JoinChannel(TLObject channel_);
    static JoinChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class LeaveChannel
{
private:
    int __id = 0xf836aa95;

public:
    TLObject channel;
    LeaveChannel(TLObject channel_);
    static LeaveChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class InviteToChannel
{
private:
    int __id = 0x199f3a6c;

public:
    TLObject channel;
    std::vector<TLObject> users;
    InviteToChannel(TLObject channel_, std::vector<TLObject> users_);
    static InviteToChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteChannel
{
private:
    int __id = 0xc0111fe3;

public:
    TLObject channel;
    DeleteChannel(TLObject channel_);
    static DeleteChannel<X> read(Reader reader);
    std::string write();
};

template <class X>
class ExportMessageLink
{
private:
    int __id = 0xe63fadeb;

public:
    std::optional<bool> grouped;
    std::optional<bool> thread;
    TLObject channel;
    int id;
    ExportMessageLink(TLObject channel_, int id_, std::optional<bool> grouped_ = std::nullopt, std::optional<bool> thread_ = std::nullopt);
    static ExportMessageLink<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleSignatures
{
private:
    int __id = 0x1f69b606;

public:
    TLObject channel;
    bool enabled;
    ToggleSignatures(TLObject channel_, bool enabled_);
    static ToggleSignatures<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAdminedPublicChannels
{
private:
    int __id = 0xf8b036af;

public:
    std::optional<bool> by_location;
    std::optional<bool> check_limit;
    GetAdminedPublicChannels(std::optional<bool> by_location_ = std::nullopt, std::optional<bool> check_limit_ = std::nullopt);
    static GetAdminedPublicChannels<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditBanned
{
private:
    int __id = 0x96e6cd81;

public:
    TLObject channel;
    TLObject participant;
    TLObject banned_rights;
    EditBanned(TLObject channel_, TLObject participant_, TLObject banned_rights_);
    static EditBanned<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAdminLog
{
private:
    int __id = 0x33ddf480;

public:
    TLObject channel;
    std::string q;
    std::optional<TLObject> events_filter;
    std::optional<std::vector<TLObject>> admins;
    long max_id;
    long min_id;
    int limit;
    GetAdminLog(TLObject channel_, std::string q_, long max_id_, long min_id_, int limit_, std::optional<TLObject> events_filter_ = std::nullopt, std::optional<std::vector<TLObject>> admins_ = std::nullopt);
    static GetAdminLog<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetStickers
{
private:
    int __id = 0xea8ca4f9;

public:
    TLObject channel;
    TLObject stickerset;
    SetStickers(TLObject channel_, TLObject stickerset_);
    static SetStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadMessageContents
{
private:
    int __id = 0xeab5dc38;

public:
    TLObject channel;
    std::vector<int> id;
    ReadMessageContents(TLObject channel_, std::vector<int> id_);
    static ReadMessageContents<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteHistory
{
private:
    int __id = 0xaf369d42;

public:
    TLObject channel;
    int max_id;
    DeleteHistory(TLObject channel_, int max_id_);
    static DeleteHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class TogglePreHistoryHidden
{
private:
    int __id = 0xeabbb94c;

public:
    TLObject channel;
    bool enabled;
    TogglePreHistoryHidden(TLObject channel_, bool enabled_);
    static TogglePreHistoryHidden<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetLeftChannels
{
private:
    int __id = 0x8341ecc0;

public:
    int offset;
    GetLeftChannels(int offset_);
    static GetLeftChannels<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetGroupsForDiscussion
{
private:
    int __id = 0xf5dad378;

public:
    GetGroupsForDiscussion() = default;
    static GetGroupsForDiscussion<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetDiscussionGroup
{
private:
    int __id = 0x40582bb2;

public:
    TLObject broadcast;
    TLObject group;
    SetDiscussionGroup(TLObject broadcast_, TLObject group_);
    static SetDiscussionGroup<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditCreator
{
private:
    int __id = 0x8f38cd1f;

public:
    TLObject channel;
    TLObject user_id;
    TLObject password;
    EditCreator(TLObject channel_, TLObject user_id_, TLObject password_);
    static EditCreator<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditLocation
{
private:
    int __id = 0x58e63f6d;

public:
    TLObject channel;
    TLObject geo_point;
    std::string address;
    EditLocation(TLObject channel_, TLObject geo_point_, std::string address_);
    static EditLocation<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleSlowMode
{
private:
    int __id = 0xedd49ef0;

public:
    TLObject channel;
    int seconds;
    ToggleSlowMode(TLObject channel_, int seconds_);
    static ToggleSlowMode<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetInactiveChannels
{
private:
    int __id = 0x11e831ee;

public:
    GetInactiveChannels() = default;
    static GetInactiveChannels<X> read(Reader reader);
    std::string write();
};

template <class X>
class ConvertToGigagroup
{
private:
    int __id = 0xb290c69;

public:
    TLObject channel;
    ConvertToGigagroup(TLObject channel_);
    static ConvertToGigagroup<X> read(Reader reader);
    std::string write();
};
