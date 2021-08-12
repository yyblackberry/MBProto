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

#include "tl/functions/phone.h"
GetCallConfig GetCallConfig::read(Reader reader)
{
    return GetCallConfig();
}

std::string GetCallConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

RequestCall::RequestCall(TLObject user_id_, int random_id_, std::string g_a_hash_, TLObject protocol_, std::optional<bool> video_) {}

RequestCall RequestCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int random_id_ = Int::read(reader);
    std::string g_a_hash_ = Bytes::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    return RequestCall(user_id_, random_id_, g_a_hash_, protocol_, video_);
}

std::string RequestCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 0 : 0;
    buffer += user_id.write();
    buffer += Int::write(random_id);
    buffer += Bytes::write(g_a_hash);
    buffer += protocol.write();
    return buffer;
}

AcceptCall::AcceptCall(TLObject peer_, std::string g_b_, TLObject protocol_) {}

AcceptCall AcceptCall::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string g_b_ = Bytes::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    return AcceptCall(peer_, g_b_, protocol_);
}

std::string AcceptCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_b);
    buffer += protocol.write();
    return buffer;
}

ConfirmCall::ConfirmCall(TLObject peer_, std::string g_a_, long key_fingerprint_, TLObject protocol_) {}

ConfirmCall ConfirmCall::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string g_a_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    return ConfirmCall(peer_, g_a_, key_fingerprint_, protocol_);
}

std::string ConfirmCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_a);
    buffer += Long::write(key_fingerprint);
    buffer += protocol.write();
    return buffer;
}

ReceivedCall::ReceivedCall(TLObject peer_) {}

ReceivedCall ReceivedCall::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ReceivedCall(peer_);
}

std::string ReceivedCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

DiscardCall::DiscardCall(TLObject peer_, int duration_, TLObject reason_, long connection_id_, std::optional<bool> video_) {}

DiscardCall DiscardCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int duration_ = Int::read(reader);
    TLObject reason_ = std::get<TLObject>(TLObject::read(reader));
    long connection_id_ = Long::read(reader);
    return DiscardCall(peer_, duration_, reason_, connection_id_, video_);
}

std::string DiscardCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Int::write(duration);
    buffer += reason.write();
    buffer += Long::write(connection_id);
    return buffer;
}

SetCallRating::SetCallRating(TLObject peer_, int rating_, std::string comment_, std::optional<bool> user_initiative_) {}

SetCallRating SetCallRating::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> user_initiative_;
    user_initiative_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int rating_ = Int::read(reader);
    std::string comment_ = String::read(reader);
    return SetCallRating(peer_, rating_, comment_, user_initiative_);
}

std::string SetCallRating::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= user_initiative ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Int::write(rating);
    buffer += String::write(comment);
    return buffer;
}

SaveCallDebug::SaveCallDebug(TLObject peer_, TLObject debug_) {}

SaveCallDebug SaveCallDebug::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject debug_ = std::get<TLObject>(TLObject::read(reader));
    return SaveCallDebug(peer_, debug_);
}

std::string SaveCallDebug::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += debug.write();
    return buffer;
}

SendSignalingData::SendSignalingData(TLObject peer_, std::string data_) {}

SendSignalingData SendSignalingData::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string data_ = Bytes::read(reader);
    return SendSignalingData(peer_, data_);
}

std::string SendSignalingData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(data);
    return buffer;
}

CreateGroupCall::CreateGroupCall(TLObject peer_, int random_id_, std::optional<std::string> title_, std::optional<int> schedule_date_) {}

CreateGroupCall CreateGroupCall::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int random_id_ = Int::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return CreateGroupCall(peer_, random_id_, title_, schedule_date_);
}

std::string CreateGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= title ? 1 << 0 : 0;
    flags |= schedule_date ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += Int::write(random_id);

    if (title)
        buffer += String::write(title.value());

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

JoinGroupCall::JoinGroupCall(TLObject call_, TLObject join_as_, TLObject params_, std::optional<bool> muted_, std::optional<bool> video_stopped_, std::optional<std::string> invite_hash_) {}

JoinGroupCall JoinGroupCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> muted_;
    muted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_stopped_;
    video_stopped_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    TLObject join_as_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> invite_hash_;
    invite_hash_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject params_ = std::get<TLObject>(TLObject::read(reader));
    return JoinGroupCall(call_, join_as_, params_, muted_, video_stopped_, invite_hash_);
}

std::string JoinGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= muted ? 1 << 0 : 0;
    flags |= video_stopped ? 1 << 2 : 0;
    flags |= invite_hash ? 1 << 1 : 0;
    buffer += call.write();
    buffer += join_as.write();

    if (invite_hash)
        buffer += String::write(invite_hash.value());
    buffer += params.write();
    return buffer;
}

LeaveGroupCall::LeaveGroupCall(TLObject call_, int source_) {}

LeaveGroupCall LeaveGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    int source_ = Int::read(reader);
    return LeaveGroupCall(call_, source_);
}

std::string LeaveGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Int::write(source);
    return buffer;
}

InviteToGroupCall::InviteToGroupCall(TLObject call_, std::vector<TLObject> users_) {}

InviteToGroupCall InviteToGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InviteToGroupCall(call_, users_);
}

std::string InviteToGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

DiscardGroupCall::DiscardGroupCall(TLObject call_) {}

DiscardGroupCall DiscardGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return DiscardGroupCall(call_);
}

std::string DiscardGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

ToggleGroupCallSettings::ToggleGroupCallSettings(TLObject call_, std::optional<bool> reset_invite_hash_, std::optional<bool> join_muted_) {}

ToggleGroupCallSettings ToggleGroupCallSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> reset_invite_hash_;
    reset_invite_hash_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<bool> join_muted_;
    join_muted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return ToggleGroupCallSettings(call_, reset_invite_hash_, join_muted_);
}

std::string ToggleGroupCallSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reset_invite_hash ? 1 << 1 : 0;
    flags |= join_muted ? 1 << 0 : 0;
    buffer += call.write();
    return buffer;
}

GetGroupCall::GetGroupCall(TLObject call_) {}

GetGroupCall GetGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return GetGroupCall(call_);
}

std::string GetGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

GetGroupParticipants::GetGroupParticipants(TLObject call_, std::vector<TLObject> ids_, std::vector<int> sources_, std::string offset_, int limit_) {}

GetGroupParticipants GetGroupParticipants::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> ids_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<int> sources_ = std::get<std::vector<int>>(TLObject::read(reader));
    std::string offset_ = String::read(reader);
    int limit_ = Int::read(reader);
    return GetGroupParticipants(call_, ids_, sources_, offset_, limit_);
}

std::string GetGroupParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<TLObject>::write(ids);
    buffer += Vector<int>::write(sources);
    buffer += String::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

CheckGroupCall::CheckGroupCall(TLObject call_, std::vector<int> sources_) {}

CheckGroupCall CheckGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> sources_ = std::get<std::vector<int>>(TLObject::read(reader));
    return CheckGroupCall(call_, sources_);
}

std::string CheckGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<int>::write(sources);
    return buffer;
}

ToggleGroupCallRecord::ToggleGroupCallRecord(TLObject call_, std::optional<bool> start_, std::optional<std::string> title_) {}

ToggleGroupCallRecord ToggleGroupCallRecord::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> start_;
    start_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> title_;
    title_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    return ToggleGroupCallRecord(call_, start_, title_);
}

std::string ToggleGroupCallRecord::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= start ? 1 << 0 : 0;
    flags |= title ? 1 << 1 : 0;
    buffer += call.write();

    if (title)
        buffer += String::write(title.value());
    return buffer;
}

EditGroupCallParticipant::EditGroupCallParticipant(TLObject call_, TLObject participant_, std::optional<bool> muted_, std::optional<int> volume_, std::optional<bool> raise_hand_, std::optional<bool> video_stopped_, std::optional<bool> video_paused_, std::optional<bool> presentation_paused_) {}

EditGroupCallParticipant EditGroupCallParticipant::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<bool> muted_;
    muted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<int> volume_;
    volume_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<bool> raise_hand_;
    raise_hand_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_stopped_;
    video_stopped_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_paused_;
    video_paused_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> presentation_paused_;
    presentation_paused_ = (1 << 5) ? std::optional{true} : std::nullopt;
    return EditGroupCallParticipant(call_, participant_, muted_, volume_, raise_hand_, video_stopped_, video_paused_, presentation_paused_);
}

std::string EditGroupCallParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= muted ? 1 << 0 : 0;
    flags |= volume ? 1 << 1 : 0;
    flags |= raise_hand ? 1 << 2 : 0;
    flags |= video_stopped ? 1 << 3 : 0;
    flags |= video_paused ? 1 << 4 : 0;
    flags |= presentation_paused ? 1 << 5 : 0;
    buffer += call.write();
    buffer += participant.write();

    if (volume)
        buffer += Int::write(volume.value());
    return buffer;
}

EditGroupCallTitle::EditGroupCallTitle(TLObject call_, std::string title_) {}

EditGroupCallTitle EditGroupCallTitle::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    return EditGroupCallTitle(call_, title_);
}

std::string EditGroupCallTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += String::write(title);
    return buffer;
}

GetGroupCallJoinAs::GetGroupCallJoinAs(TLObject peer_) {}

GetGroupCallJoinAs GetGroupCallJoinAs::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return GetGroupCallJoinAs(peer_);
}

std::string GetGroupCallJoinAs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

ExportGroupCallInvite::ExportGroupCallInvite(TLObject call_, std::optional<bool> can_self_unmute_) {}

ExportGroupCallInvite ExportGroupCallInvite::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_self_unmute_;
    can_self_unmute_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return ExportGroupCallInvite(call_, can_self_unmute_);
}

std::string ExportGroupCallInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_self_unmute ? 1 << 0 : 0;
    buffer += call.write();
    return buffer;
}

ToggleGroupCallStartSubscription::ToggleGroupCallStartSubscription(TLObject call_, bool subscribed_) {}

ToggleGroupCallStartSubscription ToggleGroupCallStartSubscription::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    bool subscribed_ = Bool::read(reader);
    return ToggleGroupCallStartSubscription(call_, subscribed_);
}

std::string ToggleGroupCallStartSubscription::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Bool::write(subscribed);
    return buffer;
}

StartScheduledGroupCall::StartScheduledGroupCall(TLObject call_) {}

StartScheduledGroupCall StartScheduledGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return StartScheduledGroupCall(call_);
}

std::string StartScheduledGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

SaveDefaultGroupCallJoinAs::SaveDefaultGroupCallJoinAs(TLObject peer_, TLObject join_as_) {}

SaveDefaultGroupCallJoinAs SaveDefaultGroupCallJoinAs::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject join_as_ = std::get<TLObject>(TLObject::read(reader));
    return SaveDefaultGroupCallJoinAs(peer_, join_as_);
}

std::string SaveDefaultGroupCallJoinAs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += join_as.write();
    return buffer;
}

JoinGroupCallPresentation::JoinGroupCallPresentation(TLObject call_, TLObject params_) {}

JoinGroupCallPresentation JoinGroupCallPresentation::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    TLObject params_ = std::get<TLObject>(TLObject::read(reader));
    return JoinGroupCallPresentation(call_, params_);
}

std::string JoinGroupCallPresentation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += params.write();
    return buffer;
}

LeaveGroupCallPresentation::LeaveGroupCallPresentation(TLObject call_) {}

LeaveGroupCallPresentation LeaveGroupCallPresentation::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return LeaveGroupCallPresentation(call_);
}

std::string LeaveGroupCallPresentation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}
