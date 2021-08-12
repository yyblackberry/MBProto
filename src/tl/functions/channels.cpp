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

#include "tl/functions/channels.h"

ReadHistory::ReadHistory(TLObject channel_, int max_id_) {}

ReadHistory ReadHistory::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    return ReadHistory(channel_, max_id_);
}

std::string ReadHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(max_id);
    return buffer;
}

DeleteMessages::DeleteMessages(TLObject channel_, std::vector<int> id_) {}

DeleteMessages DeleteMessages::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return DeleteMessages(channel_, id_);
}

std::string DeleteMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

DeleteUserHistory::DeleteUserHistory(TLObject channel_, TLObject user_id_) {}

DeleteUserHistory DeleteUserHistory::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return DeleteUserHistory(channel_, user_id_);
}

std::string DeleteUserHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    return buffer;
}

ReportSpam::ReportSpam(TLObject channel_, TLObject user_id_, std::vector<int> id_) {}

ReportSpam ReportSpam::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return ReportSpam(channel_, user_id_, id_);
}

std::string ReportSpam::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

GetMessages::GetMessages(TLObject channel_, std::vector<TLObject> id_) {}

GetMessages GetMessages::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetMessages(channel_, id_);
}

std::string GetMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

GetParticipants::GetParticipants(TLObject channel_, TLObject filter_, int offset_, int limit_, int hash_) {}

GetParticipants GetParticipants::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetParticipants(channel_, filter_, offset_, limit_, hash_);
}

std::string GetParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += filter.write();
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

GetParticipant::GetParticipant(TLObject channel_, TLObject participant_) {}

GetParticipant GetParticipant::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    return GetParticipant(channel_, participant_);
}

std::string GetParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += participant.write();
    return buffer;
}

GetChannels::GetChannels(std::vector<TLObject> id_) {}

GetChannels GetChannels::read(Reader reader)
{
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetChannels(id_);
}

std::string GetChannels::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

GetFullChannel::GetFullChannel(TLObject channel_) {}

GetFullChannel GetFullChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return GetFullChannel(channel_);
}

std::string GetFullChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

CreateChannel::CreateChannel(std::string title_, std::string about_, std::optional<bool> broadcast_, std::optional<bool> megagroup_, std::optional<bool> for_import_, std::optional<TLObject> geo_point_, std::optional<std::string> address_) {}

CreateChannel CreateChannel::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> broadcast_;
    broadcast_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> megagroup_;
    megagroup_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> for_import_;
    for_import_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string title_ = String::read(reader);
    std::string about_ = String::read(reader);
    std::optional<TLObject> geo_point_;
    geo_point_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> address_;
    address_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return CreateChannel(title_, about_, broadcast_, megagroup_, for_import_, geo_point_, address_);
}

std::string CreateChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= broadcast ? 1 << 0 : 0;
    flags |= megagroup ? 1 << 1 : 0;
    flags |= for_import ? 1 << 3 : 0;
    flags |= geo_point ? 1 << 2 : 0;
    flags |= address ? 1 << 2 : 0;
    buffer += String::write(title);
    buffer += String::write(about);

    if (geo_point)
        buffer += geo_point.value().write();

    if (address)
        buffer += String::write(address.value());
    return buffer;
}

EditAdmin::EditAdmin(TLObject channel_, TLObject user_id_, TLObject admin_rights_, std::string rank_) {}

EditAdmin EditAdmin::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject admin_rights_ = std::get<TLObject>(TLObject::read(reader));
    std::string rank_ = String::read(reader);
    return EditAdmin(channel_, user_id_, admin_rights_, rank_);
}

std::string EditAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += admin_rights.write();
    buffer += String::write(rank);
    return buffer;
}

EditTitle::EditTitle(TLObject channel_, std::string title_) {}

EditTitle EditTitle::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    return EditTitle(channel_, title_);
}

std::string EditTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(title);
    return buffer;
}

EditPhoto::EditPhoto(TLObject channel_, TLObject photo_) {}

EditPhoto EditPhoto::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    return EditPhoto(channel_, photo_);
}

std::string EditPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += photo.write();
    return buffer;
}

CheckUsername::CheckUsername(TLObject channel_, std::string username_) {}

CheckUsername CheckUsername::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::string username_ = String::read(reader);
    return CheckUsername(channel_, username_);
}

std::string CheckUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(username);
    return buffer;
}

UpdateUsername::UpdateUsername(TLObject channel_, std::string username_) {}

UpdateUsername UpdateUsername::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::string username_ = String::read(reader);
    return UpdateUsername(channel_, username_);
}

std::string UpdateUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(username);
    return buffer;
}

JoinChannel::JoinChannel(TLObject channel_) {}

JoinChannel JoinChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return JoinChannel(channel_);
}

std::string JoinChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

LeaveChannel::LeaveChannel(TLObject channel_) {}

LeaveChannel LeaveChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return LeaveChannel(channel_);
}

std::string LeaveChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

InviteToChannel::InviteToChannel(TLObject channel_, std::vector<TLObject> users_) {}

InviteToChannel InviteToChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InviteToChannel(channel_, users_);
}

std::string InviteToChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

DeleteChannel::DeleteChannel(TLObject channel_) {}

DeleteChannel DeleteChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return DeleteChannel(channel_);
}

std::string DeleteChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

ExportMessageLink::ExportMessageLink(TLObject channel_, int id_, std::optional<bool> grouped_, std::optional<bool> thread_) {}

ExportMessageLink ExportMessageLink::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> grouped_;
    grouped_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> thread_;
    thread_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    return ExportMessageLink(channel_, id_, grouped_, thread_);
}

std::string ExportMessageLink::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= grouped ? 1 << 0 : 0;
    flags |= thread ? 1 << 1 : 0;
    buffer += channel.write();
    buffer += Int::write(id);
    return buffer;
}

ToggleSignatures::ToggleSignatures(TLObject channel_, bool enabled_) {}

ToggleSignatures ToggleSignatures::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    bool enabled_ = Bool::read(reader);
    return ToggleSignatures(channel_, enabled_);
}

std::string ToggleSignatures::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Bool::write(enabled);
    return buffer;
}

GetAdminedPublicChannels::GetAdminedPublicChannels(std::optional<bool> by_location_, std::optional<bool> check_limit_) {}

GetAdminedPublicChannels GetAdminedPublicChannels::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> by_location_;
    by_location_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> check_limit_;
    check_limit_ = (1 << 1) ? std::optional{true} : std::nullopt;
    return GetAdminedPublicChannels(by_location_, check_limit_);
}

std::string GetAdminedPublicChannels::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= by_location ? 1 << 0 : 0;
    flags |= check_limit ? 1 << 1 : 0;
    return buffer;
}

EditBanned::EditBanned(TLObject channel_, TLObject participant_, TLObject banned_rights_) {}

EditBanned EditBanned::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    TLObject banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    return EditBanned(channel_, participant_, banned_rights_);
}

std::string EditBanned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += participant.write();
    buffer += banned_rights.write();
    return buffer;
}

GetAdminLog::GetAdminLog(TLObject channel_, std::string q_, long max_id_, long min_id_, int limit_, std::optional<TLObject> events_filter_, std::optional<std::vector<TLObject>> admins_) {}

GetAdminLog GetAdminLog::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::string q_ = String::read(reader);
    std::optional<TLObject> events_filter_;
    events_filter_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> admins_;
    admins_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    long max_id_ = Long::read(reader);
    long min_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetAdminLog(channel_, q_, max_id_, min_id_, limit_, events_filter_, admins_);
}

std::string GetAdminLog::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= events_filter ? 1 << 0 : 0;
    flags |= admins ? 1 << 1 : 0;
    buffer += channel.write();
    buffer += String::write(q);

    if (events_filter)
        buffer += events_filter.value().write();

    if (admins)
        buffer += Vector<TLObject>::write(admins.value());
    buffer += Long::write(max_id);
    buffer += Long::write(min_id);
    buffer += Int::write(limit);
    return buffer;
}

SetStickers::SetStickers(TLObject channel_, TLObject stickerset_) {}

SetStickers SetStickers::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    return SetStickers(channel_, stickerset_);
}

std::string SetStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += stickerset.write();
    return buffer;
}

ReadMessageContents::ReadMessageContents(TLObject channel_, std::vector<int> id_) {}

ReadMessageContents ReadMessageContents::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return ReadMessageContents(channel_, id_);
}

std::string ReadMessageContents::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

DeleteHistory::DeleteHistory(TLObject channel_, int max_id_) {}

DeleteHistory DeleteHistory::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    return DeleteHistory(channel_, max_id_);
}

std::string DeleteHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(max_id);
    return buffer;
}

TogglePreHistoryHidden::TogglePreHistoryHidden(TLObject channel_, bool enabled_) {}

TogglePreHistoryHidden TogglePreHistoryHidden::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    bool enabled_ = Bool::read(reader);
    return TogglePreHistoryHidden(channel_, enabled_);
}

std::string TogglePreHistoryHidden::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Bool::write(enabled);
    return buffer;
}

GetLeftChannels::GetLeftChannels(int offset_) {}

GetLeftChannels GetLeftChannels::read(Reader reader)
{
    int offset_ = Int::read(reader);
    return GetLeftChannels(offset_);
}

std::string GetLeftChannels::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    return buffer;
}
GetGroupsForDiscussion GetGroupsForDiscussion::read(Reader reader)
{
    return GetGroupsForDiscussion();
}

std::string GetGroupsForDiscussion::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SetDiscussionGroup::SetDiscussionGroup(TLObject broadcast_, TLObject group_) {}

SetDiscussionGroup SetDiscussionGroup::read(Reader reader)
{
    TLObject broadcast_ = std::get<TLObject>(TLObject::read(reader));
    TLObject group_ = std::get<TLObject>(TLObject::read(reader));
    return SetDiscussionGroup(broadcast_, group_);
}

std::string SetDiscussionGroup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += broadcast.write();
    buffer += group.write();
    return buffer;
}

EditCreator::EditCreator(TLObject channel_, TLObject user_id_, TLObject password_) {}

EditCreator EditCreator::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject password_ = std::get<TLObject>(TLObject::read(reader));
    return EditCreator(channel_, user_id_, password_);
}

std::string EditCreator::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += password.write();
    return buffer;
}

EditLocation::EditLocation(TLObject channel_, TLObject geo_point_, std::string address_) {}

EditLocation EditLocation::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::string address_ = String::read(reader);
    return EditLocation(channel_, geo_point_, address_);
}

std::string EditLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += geo_point.write();
    buffer += String::write(address);
    return buffer;
}

ToggleSlowMode::ToggleSlowMode(TLObject channel_, int seconds_) {}

ToggleSlowMode ToggleSlowMode::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int seconds_ = Int::read(reader);
    return ToggleSlowMode(channel_, seconds_);
}

std::string ToggleSlowMode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(seconds);
    return buffer;
}
GetInactiveChannels GetInactiveChannels::read(Reader reader)
{
    return GetInactiveChannels();
}

std::string GetInactiveChannels::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ConvertToGigagroup::ConvertToGigagroup(TLObject channel_) {}

ConvertToGigagroup ConvertToGigagroup::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return ConvertToGigagroup(channel_);
}

std::string ConvertToGigagroup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}
