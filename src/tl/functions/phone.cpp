#include "tl/functions/phone.h"
template <class X>
GetCallConfig<X> GetCallConfig<X>::read(Reader reader)
{
    return GetCallConfig<X>();
}

template <class X>
std::string GetCallConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
RequestCall<X>::RequestCall(TLObject user_id_, int random_id_, std::string g_a_hash_, TLObject protocol_, std::optional<bool> video_) {}

template <class X>
RequestCall<X> RequestCall<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;

    if (1 << 0)
        video_ = true;
    else
        video_ = std::nullopt;
    TLObject user_id_ = TLObject::read(reader);
    int random_id_ = Int::read(reader);
    std::string g_a_hash_ = Bytes::read(reader);
    TLObject protocol_ = TLObject::read(reader);
    return RequestCall<X>(user_id_, random_id_, g_a_hash_, protocol_, video_);
}

template <class X>
std::string RequestCall<X>::write()
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

template <class X>
AcceptCall<X>::AcceptCall(TLObject peer_, std::string g_b_, TLObject protocol_) {}

template <class X>
AcceptCall<X> AcceptCall<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string g_b_ = Bytes::read(reader);
    TLObject protocol_ = TLObject::read(reader);
    return AcceptCall<X>(peer_, g_b_, protocol_);
}

template <class X>
std::string AcceptCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_b);
    buffer += protocol.write();
    return buffer;
}

template <class X>
ConfirmCall<X>::ConfirmCall(TLObject peer_, std::string g_a_, long key_fingerprint_, TLObject protocol_) {}

template <class X>
ConfirmCall<X> ConfirmCall<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string g_a_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    TLObject protocol_ = TLObject::read(reader);
    return ConfirmCall<X>(peer_, g_a_, key_fingerprint_, protocol_);
}

template <class X>
std::string ConfirmCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_a);
    buffer += Long::write(key_fingerprint);
    buffer += protocol.write();
    return buffer;
}

template <class X>
ReceivedCall<X>::ReceivedCall(TLObject peer_) {}

template <class X>
ReceivedCall<X> ReceivedCall<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return ReceivedCall<X>(peer_);
}

template <class X>
std::string ReceivedCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
DiscardCall<X>::DiscardCall(TLObject peer_, int duration_, TLObject reason_, long connection_id_, std::optional<bool> video_) {}

template <class X>
DiscardCall<X> DiscardCall<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;

    if (1 << 0)
        video_ = true;
    else
        video_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int duration_ = Int::read(reader);
    TLObject reason_ = TLObject::read(reader);
    long connection_id_ = Long::read(reader);
    return DiscardCall<X>(peer_, duration_, reason_, connection_id_, video_);
}

template <class X>
std::string DiscardCall<X>::write()
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

template <class X>
SetCallRating<X>::SetCallRating(TLObject peer_, int rating_, std::string comment_, std::optional<bool> user_initiative_) {}

template <class X>
SetCallRating<X> SetCallRating<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> user_initiative_;

    if (1 << 0)
        user_initiative_ = true;
    else
        user_initiative_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int rating_ = Int::read(reader);
    std::string comment_ = String::read(reader);
    return SetCallRating<X>(peer_, rating_, comment_, user_initiative_);
}

template <class X>
std::string SetCallRating<X>::write()
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

template <class X>
SaveCallDebug<X>::SaveCallDebug(TLObject peer_, TLObject debug_) {}

template <class X>
SaveCallDebug<X> SaveCallDebug<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject debug_ = TLObject::read(reader);
    return SaveCallDebug<X>(peer_, debug_);
}

template <class X>
std::string SaveCallDebug<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += debug.write();
    return buffer;
}

template <class X>
SendSignalingData<X>::SendSignalingData(TLObject peer_, std::string data_) {}

template <class X>
SendSignalingData<X> SendSignalingData<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string data_ = Bytes::read(reader);
    return SendSignalingData<X>(peer_, data_);
}

template <class X>
std::string SendSignalingData<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(data);
    return buffer;
}

template <class X>
CreateGroupCall<X>::CreateGroupCall(TLObject peer_, int random_id_, std::optional<std::string> title_, std::optional<int> schedule_date_) {}

template <class X>
CreateGroupCall<X> CreateGroupCall<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    int random_id_ = Int::read(reader);
    std::optional<std::string> title_;

    if (1 << 0)
        title_ = String::read(reader);
    else
        title_ = std::nullopt;
    std::optional<int> schedule_date_;

    if (1 << 1)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return CreateGroupCall<X>(peer_, random_id_, title_, schedule_date_);
}

template <class X>
std::string CreateGroupCall<X>::write()
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

template <class X>
JoinGroupCall<X>::JoinGroupCall(TLObject call_, TLObject join_as_, TLObject params_, std::optional<bool> muted_, std::optional<bool> video_stopped_, std::optional<std::string> invite_hash_) {}

template <class X>
JoinGroupCall<X> JoinGroupCall<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> muted_;

    if (1 << 0)
        muted_ = true;
    else
        muted_ = std::nullopt;
    std::optional<bool> video_stopped_;

    if (1 << 2)
        video_stopped_ = true;
    else
        video_stopped_ = std::nullopt;
    TLObject call_ = TLObject::read(reader);
    TLObject join_as_ = TLObject::read(reader);
    std::optional<std::string> invite_hash_;

    if (1 << 1)
        invite_hash_ = String::read(reader);
    else
        invite_hash_ = std::nullopt;
    TLObject params_ = TLObject::read(reader);
    return JoinGroupCall<X>(call_, join_as_, params_, muted_, video_stopped_, invite_hash_);
}

template <class X>
std::string JoinGroupCall<X>::write()
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

template <class X>
LeaveGroupCall<X>::LeaveGroupCall(TLObject call_, int source_) {}

template <class X>
LeaveGroupCall<X> LeaveGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    int source_ = Int::read(reader);
    return LeaveGroupCall<X>(call_, source_);
}

template <class X>
std::string LeaveGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Int::write(source);
    return buffer;
}

template <class X>
InviteToGroupCall<X>::InviteToGroupCall(TLObject call_, std::vector<TLObject> users_) {}

template <class X>
InviteToGroupCall<X> InviteToGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return InviteToGroupCall<X>(call_, users_);
}

template <class X>
std::string InviteToGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

template <class X>
DiscardGroupCall<X>::DiscardGroupCall(TLObject call_) {}

template <class X>
DiscardGroupCall<X> DiscardGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    return DiscardGroupCall<X>(call_);
}

template <class X>
std::string DiscardGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

template <class X>
ToggleGroupCallSettings<X>::ToggleGroupCallSettings(TLObject call_, std::optional<bool> reset_invite_hash_, std::optional<bool> join_muted_) {}

template <class X>
ToggleGroupCallSettings<X> ToggleGroupCallSettings<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> reset_invite_hash_;

    if (1 << 1)
        reset_invite_hash_ = true;
    else
        reset_invite_hash_ = std::nullopt;
    TLObject call_ = TLObject::read(reader);
    std::optional<bool> join_muted_;

    if (1 << 0)
        join_muted_ = true;
    else
        join_muted_ = std::nullopt;
    return ToggleGroupCallSettings<X>(call_, reset_invite_hash_, join_muted_);
}

template <class X>
std::string ToggleGroupCallSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reset_invite_hash ? 1 << 1 : 0;
    flags |= join_muted ? 1 << 0 : 0;
    buffer += call.write();
    return buffer;
}

template <class X>
GetGroupCall<X>::GetGroupCall(TLObject call_) {}

template <class X>
GetGroupCall<X> GetGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    return GetGroupCall<X>(call_);
}

template <class X>
std::string GetGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

template <class X>
GetGroupParticipants<X>::GetGroupParticipants(TLObject call_, std::vector<TLObject> ids_, std::vector<int> sources_, std::string offset_, int limit_) {}

template <class X>
GetGroupParticipants<X> GetGroupParticipants<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    std::vector<TLObject> ids_ = Vector<TLObject>::read(reader);
    std::vector<int> sources_ = Vector<int>::read(reader);
    std::string offset_ = String::read(reader);
    int limit_ = Int::read(reader);
    return GetGroupParticipants<X>(call_, ids_, sources_, offset_, limit_);
}

template <class X>
std::string GetGroupParticipants<X>::write()
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

template <class X>
CheckGroupCall<X>::CheckGroupCall(TLObject call_, std::vector<int> sources_) {}

template <class X>
CheckGroupCall<X> CheckGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    std::vector<int> sources_ = Vector<int>::read(reader);
    return CheckGroupCall<X>(call_, sources_);
}

template <class X>
std::string CheckGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<int>::write(sources);
    return buffer;
}

template <class X>
ToggleGroupCallRecord<X>::ToggleGroupCallRecord(TLObject call_, std::optional<bool> start_, std::optional<std::string> title_) {}

template <class X>
ToggleGroupCallRecord<X> ToggleGroupCallRecord<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> start_;

    if (1 << 0)
        start_ = true;
    else
        start_ = std::nullopt;
    TLObject call_ = TLObject::read(reader);
    std::optional<std::string> title_;

    if (1 << 1)
        title_ = String::read(reader);
    else
        title_ = std::nullopt;
    return ToggleGroupCallRecord<X>(call_, start_, title_);
}

template <class X>
std::string ToggleGroupCallRecord<X>::write()
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

template <class X>
EditGroupCallParticipant<X>::EditGroupCallParticipant(TLObject call_, TLObject participant_, std::optional<bool> muted_, std::optional<int> volume_, std::optional<bool> raise_hand_, std::optional<bool> video_stopped_, std::optional<bool> video_paused_, std::optional<bool> presentation_paused_) {}

template <class X>
EditGroupCallParticipant<X> EditGroupCallParticipant<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject call_ = TLObject::read(reader);
    TLObject participant_ = TLObject::read(reader);
    std::optional<bool> muted_;

    if (1 << 0)
        muted_ = true;
    else
        muted_ = std::nullopt;
    std::optional<int> volume_;

    if (1 << 1)
        volume_ = Int::read(reader);
    else
        volume_ = std::nullopt;
    std::optional<bool> raise_hand_;

    if (1 << 2)
        raise_hand_ = true;
    else
        raise_hand_ = std::nullopt;
    std::optional<bool> video_stopped_;

    if (1 << 3)
        video_stopped_ = true;
    else
        video_stopped_ = std::nullopt;
    std::optional<bool> video_paused_;

    if (1 << 4)
        video_paused_ = true;
    else
        video_paused_ = std::nullopt;
    std::optional<bool> presentation_paused_;

    if (1 << 5)
        presentation_paused_ = true;
    else
        presentation_paused_ = std::nullopt;
    return EditGroupCallParticipant<X>(call_, participant_, muted_, volume_, raise_hand_, video_stopped_, video_paused_, presentation_paused_);
}

template <class X>
std::string EditGroupCallParticipant<X>::write()
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

template <class X>
EditGroupCallTitle<X>::EditGroupCallTitle(TLObject call_, std::string title_) {}

template <class X>
EditGroupCallTitle<X> EditGroupCallTitle<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    std::string title_ = String::read(reader);
    return EditGroupCallTitle<X>(call_, title_);
}

template <class X>
std::string EditGroupCallTitle<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += String::write(title);
    return buffer;
}

template <class X>
GetGroupCallJoinAs<X>::GetGroupCallJoinAs(TLObject peer_) {}

template <class X>
GetGroupCallJoinAs<X> GetGroupCallJoinAs<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return GetGroupCallJoinAs<X>(peer_);
}

template <class X>
std::string GetGroupCallJoinAs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
ExportGroupCallInvite<X>::ExportGroupCallInvite(TLObject call_, std::optional<bool> can_self_unmute_) {}

template <class X>
ExportGroupCallInvite<X> ExportGroupCallInvite<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_self_unmute_;

    if (1 << 0)
        can_self_unmute_ = true;
    else
        can_self_unmute_ = std::nullopt;
    TLObject call_ = TLObject::read(reader);
    return ExportGroupCallInvite<X>(call_, can_self_unmute_);
}

template <class X>
std::string ExportGroupCallInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_self_unmute ? 1 << 0 : 0;
    buffer += call.write();
    return buffer;
}

template <class X>
ToggleGroupCallStartSubscription<X>::ToggleGroupCallStartSubscription(TLObject call_, bool subscribed_) {}

template <class X>
ToggleGroupCallStartSubscription<X> ToggleGroupCallStartSubscription<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    bool subscribed_ = Bool::read(reader);
    return ToggleGroupCallStartSubscription<X>(call_, subscribed_);
}

template <class X>
std::string ToggleGroupCallStartSubscription<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Bool::write(subscribed);
    return buffer;
}

template <class X>
StartScheduledGroupCall<X>::StartScheduledGroupCall(TLObject call_) {}

template <class X>
StartScheduledGroupCall<X> StartScheduledGroupCall<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    return StartScheduledGroupCall<X>(call_);
}

template <class X>
std::string StartScheduledGroupCall<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

template <class X>
SaveDefaultGroupCallJoinAs<X>::SaveDefaultGroupCallJoinAs(TLObject peer_, TLObject join_as_) {}

template <class X>
SaveDefaultGroupCallJoinAs<X> SaveDefaultGroupCallJoinAs<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject join_as_ = TLObject::read(reader);
    return SaveDefaultGroupCallJoinAs<X>(peer_, join_as_);
}

template <class X>
std::string SaveDefaultGroupCallJoinAs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += join_as.write();
    return buffer;
}

template <class X>
JoinGroupCallPresentation<X>::JoinGroupCallPresentation(TLObject call_, TLObject params_) {}

template <class X>
JoinGroupCallPresentation<X> JoinGroupCallPresentation<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    TLObject params_ = TLObject::read(reader);
    return JoinGroupCallPresentation<X>(call_, params_);
}

template <class X>
std::string JoinGroupCallPresentation<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += params.write();
    return buffer;
}

template <class X>
LeaveGroupCallPresentation<X>::LeaveGroupCallPresentation(TLObject call_) {}

template <class X>
LeaveGroupCallPresentation<X> LeaveGroupCallPresentation<X>::read(Reader reader)
{
    TLObject call_ = TLObject::read(reader);
    return LeaveGroupCallPresentation<X>(call_);
}

template <class X>
std::string LeaveGroupCallPresentation<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}
