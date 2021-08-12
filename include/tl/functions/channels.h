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

class ReadHistory : public TLObject
{
private:
    int __id = 0xcc104937;

public:
    TLObject channel;
    int max_id;
    ReadHistory(TLObject channel_, int max_id_);
    static ReadHistory read(Reader reader);
    std::string write();
};

class DeleteMessages : public TLObject
{
private:
    int __id = 0x84c1fd4e;

public:
    TLObject channel;
    std::vector<int> id;
    DeleteMessages(TLObject channel_, std::vector<int> id_);
    static DeleteMessages read(Reader reader);
    std::string write();
};

class DeleteUserHistory : public TLObject
{
private:
    int __id = 0xd10dd71b;

public:
    TLObject channel;
    TLObject user_id;
    DeleteUserHistory(TLObject channel_, TLObject user_id_);
    static DeleteUserHistory read(Reader reader);
    std::string write();
};

class ReportSpam : public TLObject
{
private:
    int __id = 0xfe087810;

public:
    TLObject channel;
    TLObject user_id;
    std::vector<int> id;
    ReportSpam(TLObject channel_, TLObject user_id_, std::vector<int> id_);
    static ReportSpam read(Reader reader);
    std::string write();
};

class GetMessages : public TLObject
{
private:
    int __id = 0xad8c9a23;

public:
    TLObject channel;
    std::vector<TLObject> id;
    GetMessages(TLObject channel_, std::vector<TLObject> id_);
    static GetMessages read(Reader reader);
    std::string write();
};

class GetParticipants : public TLObject
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
    static GetParticipants read(Reader reader);
    std::string write();
};

class GetParticipant : public TLObject
{
private:
    int __id = 0xa0ab6cc6;

public:
    TLObject channel;
    TLObject participant;
    GetParticipant(TLObject channel_, TLObject participant_);
    static GetParticipant read(Reader reader);
    std::string write();
};

class GetChannels : public TLObject
{
private:
    int __id = 0xa7f6bbb;

public:
    std::vector<TLObject> id;
    GetChannels(std::vector<TLObject> id_);
    static GetChannels read(Reader reader);
    std::string write();
};

class GetFullChannel : public TLObject
{
private:
    int __id = 0x8736a09;

public:
    TLObject channel;
    GetFullChannel(TLObject channel_);
    static GetFullChannel read(Reader reader);
    std::string write();
};

class CreateChannel : public TLObject
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
    static CreateChannel read(Reader reader);
    std::string write();
};

class EditAdmin : public TLObject
{
private:
    int __id = 0xd33c8902;

public:
    TLObject channel;
    TLObject user_id;
    TLObject admin_rights;
    std::string rank;
    EditAdmin(TLObject channel_, TLObject user_id_, TLObject admin_rights_, std::string rank_);
    static EditAdmin read(Reader reader);
    std::string write();
};

class EditTitle : public TLObject
{
private:
    int __id = 0x566decd0;

public:
    TLObject channel;
    std::string title;
    EditTitle(TLObject channel_, std::string title_);
    static EditTitle read(Reader reader);
    std::string write();
};

class EditPhoto : public TLObject
{
private:
    int __id = 0xf12e57c9;

public:
    TLObject channel;
    TLObject photo;
    EditPhoto(TLObject channel_, TLObject photo_);
    static EditPhoto read(Reader reader);
    std::string write();
};

class CheckUsername : public TLObject
{
private:
    int __id = 0x10e6bd2c;

public:
    TLObject channel;
    std::string username;
    CheckUsername(TLObject channel_, std::string username_);
    static CheckUsername read(Reader reader);
    std::string write();
};

class UpdateUsername : public TLObject
{
private:
    int __id = 0x3514b3de;

public:
    TLObject channel;
    std::string username;
    UpdateUsername(TLObject channel_, std::string username_);
    static UpdateUsername read(Reader reader);
    std::string write();
};

class JoinChannel : public TLObject
{
private:
    int __id = 0x24b524c5;

public:
    TLObject channel;
    JoinChannel(TLObject channel_);
    static JoinChannel read(Reader reader);
    std::string write();
};

class LeaveChannel : public TLObject
{
private:
    int __id = 0xf836aa95;

public:
    TLObject channel;
    LeaveChannel(TLObject channel_);
    static LeaveChannel read(Reader reader);
    std::string write();
};

class InviteToChannel : public TLObject
{
private:
    int __id = 0x199f3a6c;

public:
    TLObject channel;
    std::vector<TLObject> users;
    InviteToChannel(TLObject channel_, std::vector<TLObject> users_);
    static InviteToChannel read(Reader reader);
    std::string write();
};

class DeleteChannel : public TLObject
{
private:
    int __id = 0xc0111fe3;

public:
    TLObject channel;
    DeleteChannel(TLObject channel_);
    static DeleteChannel read(Reader reader);
    std::string write();
};

class ExportMessageLink : public TLObject
{
private:
    int __id = 0xe63fadeb;

public:
    std::optional<bool> grouped;
    std::optional<bool> thread;
    TLObject channel;
    int id;
    ExportMessageLink(TLObject channel_, int id_, std::optional<bool> grouped_ = std::nullopt, std::optional<bool> thread_ = std::nullopt);
    static ExportMessageLink read(Reader reader);
    std::string write();
};

class ToggleSignatures : public TLObject
{
private:
    int __id = 0x1f69b606;

public:
    TLObject channel;
    bool enabled;
    ToggleSignatures(TLObject channel_, bool enabled_);
    static ToggleSignatures read(Reader reader);
    std::string write();
};

class GetAdminedPublicChannels : public TLObject
{
private:
    int __id = 0xf8b036af;

public:
    std::optional<bool> by_location;
    std::optional<bool> check_limit;
    GetAdminedPublicChannels(std::optional<bool> by_location_ = std::nullopt, std::optional<bool> check_limit_ = std::nullopt);
    static GetAdminedPublicChannels read(Reader reader);
    std::string write();
};

class EditBanned : public TLObject
{
private:
    int __id = 0x96e6cd81;

public:
    TLObject channel;
    TLObject participant;
    TLObject banned_rights;
    EditBanned(TLObject channel_, TLObject participant_, TLObject banned_rights_);
    static EditBanned read(Reader reader);
    std::string write();
};

class GetAdminLog : public TLObject
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
    static GetAdminLog read(Reader reader);
    std::string write();
};

class SetStickers : public TLObject
{
private:
    int __id = 0xea8ca4f9;

public:
    TLObject channel;
    TLObject stickerset;
    SetStickers(TLObject channel_, TLObject stickerset_);
    static SetStickers read(Reader reader);
    std::string write();
};

class ReadMessageContents : public TLObject
{
private:
    int __id = 0xeab5dc38;

public:
    TLObject channel;
    std::vector<int> id;
    ReadMessageContents(TLObject channel_, std::vector<int> id_);
    static ReadMessageContents read(Reader reader);
    std::string write();
};

class DeleteHistory : public TLObject
{
private:
    int __id = 0xaf369d42;

public:
    TLObject channel;
    int max_id;
    DeleteHistory(TLObject channel_, int max_id_);
    static DeleteHistory read(Reader reader);
    std::string write();
};

class TogglePreHistoryHidden : public TLObject
{
private:
    int __id = 0xeabbb94c;

public:
    TLObject channel;
    bool enabled;
    TogglePreHistoryHidden(TLObject channel_, bool enabled_);
    static TogglePreHistoryHidden read(Reader reader);
    std::string write();
};

class GetLeftChannels : public TLObject
{
private:
    int __id = 0x8341ecc0;

public:
    int offset;
    GetLeftChannels(int offset_);
    static GetLeftChannels read(Reader reader);
    std::string write();
};

class GetGroupsForDiscussion : public TLObject
{
private:
    int __id = 0xf5dad378;

public:
    GetGroupsForDiscussion() = default;
    static GetGroupsForDiscussion read(Reader reader);
    std::string write();
};

class SetDiscussionGroup : public TLObject
{
private:
    int __id = 0x40582bb2;

public:
    TLObject broadcast;
    TLObject group;
    SetDiscussionGroup(TLObject broadcast_, TLObject group_);
    static SetDiscussionGroup read(Reader reader);
    std::string write();
};

class EditCreator : public TLObject
{
private:
    int __id = 0x8f38cd1f;

public:
    TLObject channel;
    TLObject user_id;
    TLObject password;
    EditCreator(TLObject channel_, TLObject user_id_, TLObject password_);
    static EditCreator read(Reader reader);
    std::string write();
};

class EditLocation : public TLObject
{
private:
    int __id = 0x58e63f6d;

public:
    TLObject channel;
    TLObject geo_point;
    std::string address;
    EditLocation(TLObject channel_, TLObject geo_point_, std::string address_);
    static EditLocation read(Reader reader);
    std::string write();
};

class ToggleSlowMode : public TLObject
{
private:
    int __id = 0xedd49ef0;

public:
    TLObject channel;
    int seconds;
    ToggleSlowMode(TLObject channel_, int seconds_);
    static ToggleSlowMode read(Reader reader);
    std::string write();
};

class GetInactiveChannels : public TLObject
{
private:
    int __id = 0x11e831ee;

public:
    GetInactiveChannels() = default;
    static GetInactiveChannels read(Reader reader);
    std::string write();
};

class ConvertToGigagroup : public TLObject
{
private:
    int __id = 0xb290c69;

public:
    TLObject channel;
    ConvertToGigagroup(TLObject channel_);
    static ConvertToGigagroup read(Reader reader);
    std::string write();
};
