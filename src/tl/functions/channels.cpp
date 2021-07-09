#include "tl/functions/channels.h"

template <class X>
ReadHistory<X>::ReadHistory(TLObject channel_, int max_id_) {}

template <class X>
ReadHistory<X> ReadHistory<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    int max_id_ = Int::read(reader);
    return ReadHistory<X>(channel_, max_id_);
}

template <class X>
std::string ReadHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(max_id);
    return buffer;
}

template <class X>
DeleteMessages<X>::DeleteMessages(TLObject channel_, std::vector<int> id_) {}

template <class X>
DeleteMessages<X> DeleteMessages<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return DeleteMessages<X>(channel_, id_);
}

template <class X>
std::string DeleteMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
DeleteUserHistory<X>::DeleteUserHistory(TLObject channel_, TLObject user_id_) {}

template <class X>
DeleteUserHistory<X> DeleteUserHistory<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    return DeleteUserHistory<X>(channel_, user_id_);
}

template <class X>
std::string DeleteUserHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    return buffer;
}

template <class X>
ReportSpam<X>::ReportSpam(TLObject channel_, TLObject user_id_, std::vector<int> id_) {}

template <class X>
ReportSpam<X> ReportSpam<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return ReportSpam<X>(channel_, user_id_, id_);
}

template <class X>
std::string ReportSpam<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
GetMessages<X>::GetMessages(TLObject channel_, std::vector<TLObject> id_) {}

template <class X>
GetMessages<X> GetMessages<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return GetMessages<X>(channel_, id_);
}

template <class X>
std::string GetMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
GetParticipants<X>::GetParticipants(TLObject channel_, TLObject filter_, int offset_, int limit_, int hash_) {}

template <class X>
GetParticipants<X> GetParticipants<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject filter_ = TLObject::read(reader);
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetParticipants<X>(channel_, filter_, offset_, limit_, hash_);
}

template <class X>
std::string GetParticipants<X>::write()
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

template <class X>
GetParticipant<X>::GetParticipant(TLObject channel_, TLObject participant_) {}

template <class X>
GetParticipant<X> GetParticipant<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject participant_ = TLObject::read(reader);
    return GetParticipant<X>(channel_, participant_);
}

template <class X>
std::string GetParticipant<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += participant.write();
    return buffer;
}

template <class X>
GetChannels<X>::GetChannels(std::vector<TLObject> id_) {}

template <class X>
GetChannels<X> GetChannels<X>::read(Reader reader)
{
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return GetChannels<X>(id_);
}

template <class X>
std::string GetChannels<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
GetFullChannel<X>::GetFullChannel(TLObject channel_) {}

template <class X>
GetFullChannel<X> GetFullChannel<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    return GetFullChannel<X>(channel_);
}

template <class X>
std::string GetFullChannel<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

template <class X>
CreateChannel<X>::CreateChannel(std::string title_, std::string about_, std::optional<bool> broadcast_, std::optional<bool> megagroup_, std::optional<bool> for_import_, std::optional<TLObject> geo_point_, std::optional<std::string> address_) {}

template <class X>
CreateChannel<X> CreateChannel<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> broadcast_;

    if (1 << 0)
        broadcast_ = true;
    else
        broadcast_ = std::nullopt;
    std::optional<bool> megagroup_;

    if (1 << 1)
        megagroup_ = true;
    else
        megagroup_ = std::nullopt;
    std::optional<bool> for_import_;

    if (1 << 3)
        for_import_ = true;
    else
        for_import_ = std::nullopt;
    std::string title_ = String::read(reader);
    std::string about_ = String::read(reader);
    std::optional<TLObject> geo_point_;

    if (1 << 2)
        geo_point_ = TLObject::read(reader);
    else
        geo_point_ = std::nullopt;
    std::optional<std::string> address_;

    if (1 << 2)
        address_ = String::read(reader);
    else
        address_ = std::nullopt;
    return CreateChannel<X>(title_, about_, broadcast_, megagroup_, for_import_, geo_point_, address_);
}

template <class X>
std::string CreateChannel<X>::write()
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

template <class X>
EditAdmin<X>::EditAdmin(TLObject channel_, TLObject user_id_, TLObject admin_rights_, std::string rank_) {}

template <class X>
EditAdmin<X> EditAdmin<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    TLObject admin_rights_ = TLObject::read(reader);
    std::string rank_ = String::read(reader);
    return EditAdmin<X>(channel_, user_id_, admin_rights_, rank_);
}

template <class X>
std::string EditAdmin<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += admin_rights.write();
    buffer += String::write(rank);
    return buffer;
}

template <class X>
EditTitle<X>::EditTitle(TLObject channel_, std::string title_) {}

template <class X>
EditTitle<X> EditTitle<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::string title_ = String::read(reader);
    return EditTitle<X>(channel_, title_);
}

template <class X>
std::string EditTitle<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(title);
    return buffer;
}

template <class X>
EditPhoto<X>::EditPhoto(TLObject channel_, TLObject photo_) {}

template <class X>
EditPhoto<X> EditPhoto<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject photo_ = TLObject::read(reader);
    return EditPhoto<X>(channel_, photo_);
}

template <class X>
std::string EditPhoto<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += photo.write();
    return buffer;
}

template <class X>
CheckUsername<X>::CheckUsername(TLObject channel_, std::string username_) {}

template <class X>
CheckUsername<X> CheckUsername<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::string username_ = String::read(reader);
    return CheckUsername<X>(channel_, username_);
}

template <class X>
std::string CheckUsername<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(username);
    return buffer;
}

template <class X>
UpdateUsername<X>::UpdateUsername(TLObject channel_, std::string username_) {}

template <class X>
UpdateUsername<X> UpdateUsername<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::string username_ = String::read(reader);
    return UpdateUsername<X>(channel_, username_);
}

template <class X>
std::string UpdateUsername<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += String::write(username);
    return buffer;
}

template <class X>
JoinChannel<X>::JoinChannel(TLObject channel_) {}

template <class X>
JoinChannel<X> JoinChannel<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    return JoinChannel<X>(channel_);
}

template <class X>
std::string JoinChannel<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

template <class X>
LeaveChannel<X>::LeaveChannel(TLObject channel_) {}

template <class X>
LeaveChannel<X> LeaveChannel<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    return LeaveChannel<X>(channel_);
}

template <class X>
std::string LeaveChannel<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

template <class X>
InviteToChannel<X>::InviteToChannel(TLObject channel_, std::vector<TLObject> users_) {}

template <class X>
InviteToChannel<X> InviteToChannel<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return InviteToChannel<X>(channel_, users_);
}

template <class X>
std::string InviteToChannel<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

template <class X>
DeleteChannel<X>::DeleteChannel(TLObject channel_) {}

template <class X>
DeleteChannel<X> DeleteChannel<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    return DeleteChannel<X>(channel_);
}

template <class X>
std::string DeleteChannel<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

template <class X>
ExportMessageLink<X>::ExportMessageLink(TLObject channel_, int id_, std::optional<bool> grouped_, std::optional<bool> thread_) {}

template <class X>
ExportMessageLink<X> ExportMessageLink<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> grouped_;

    if (1 << 0)
        grouped_ = true;
    else
        grouped_ = std::nullopt;
    std::optional<bool> thread_;

    if (1 << 1)
        thread_ = true;
    else
        thread_ = std::nullopt;
    TLObject channel_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    return ExportMessageLink<X>(channel_, id_, grouped_, thread_);
}

template <class X>
std::string ExportMessageLink<X>::write()
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

template <class X>
ToggleSignatures<X>::ToggleSignatures(TLObject channel_, bool enabled_) {}

template <class X>
ToggleSignatures<X> ToggleSignatures<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    bool enabled_ = Bool::read(reader);
    return ToggleSignatures<X>(channel_, enabled_);
}

template <class X>
std::string ToggleSignatures<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Bool::write(enabled);
    return buffer;
}

template <class X>
GetAdminedPublicChannels<X>::GetAdminedPublicChannels(std::optional<bool> by_location_, std::optional<bool> check_limit_) {}

template <class X>
GetAdminedPublicChannels<X> GetAdminedPublicChannels<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> by_location_;

    if (1 << 0)
        by_location_ = true;
    else
        by_location_ = std::nullopt;
    std::optional<bool> check_limit_;

    if (1 << 1)
        check_limit_ = true;
    else
        check_limit_ = std::nullopt;
    return GetAdminedPublicChannels<X>(by_location_, check_limit_);
}

template <class X>
std::string GetAdminedPublicChannels<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= by_location ? 1 << 0 : 0;
    flags |= check_limit ? 1 << 1 : 0;
    return buffer;
}

template <class X>
EditBanned<X>::EditBanned(TLObject channel_, TLObject participant_, TLObject banned_rights_) {}

template <class X>
EditBanned<X> EditBanned<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject participant_ = TLObject::read(reader);
    TLObject banned_rights_ = TLObject::read(reader);
    return EditBanned<X>(channel_, participant_, banned_rights_);
}

template <class X>
std::string EditBanned<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += participant.write();
    buffer += banned_rights.write();
    return buffer;
}

template <class X>
GetAdminLog<X>::GetAdminLog(TLObject channel_, std::string q_, long max_id_, long min_id_, int limit_, std::optional<TLObject> events_filter_, std::optional<std::vector<TLObject>> admins_) {}

template <class X>
GetAdminLog<X> GetAdminLog<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject channel_ = TLObject::read(reader);
    std::string q_ = String::read(reader);
    std::optional<TLObject> events_filter_;

    if (1 << 0)
        events_filter_ = TLObject::read(reader);
    else
        events_filter_ = std::nullopt;
    std::optional<std::vector<TLObject>> admins_;

    if (1 << 1)
        admins_ = Vector<TLObject>::read(reader);
    else
        admins_ = std::nullopt;
    long max_id_ = Long::read(reader);
    long min_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetAdminLog<X>(channel_, q_, max_id_, min_id_, limit_, events_filter_, admins_);
}

template <class X>
std::string GetAdminLog<X>::write()
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

template <class X>
SetStickers<X>::SetStickers(TLObject channel_, TLObject stickerset_) {}

template <class X>
SetStickers<X> SetStickers<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject stickerset_ = TLObject::read(reader);
    return SetStickers<X>(channel_, stickerset_);
}

template <class X>
std::string SetStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += stickerset.write();
    return buffer;
}

template <class X>
ReadMessageContents<X>::ReadMessageContents(TLObject channel_, std::vector<int> id_) {}

template <class X>
ReadMessageContents<X> ReadMessageContents<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return ReadMessageContents<X>(channel_, id_);
}

template <class X>
std::string ReadMessageContents<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
DeleteHistory<X>::DeleteHistory(TLObject channel_, int max_id_) {}

template <class X>
DeleteHistory<X> DeleteHistory<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    int max_id_ = Int::read(reader);
    return DeleteHistory<X>(channel_, max_id_);
}

template <class X>
std::string DeleteHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(max_id);
    return buffer;
}

template <class X>
TogglePreHistoryHidden<X>::TogglePreHistoryHidden(TLObject channel_, bool enabled_) {}

template <class X>
TogglePreHistoryHidden<X> TogglePreHistoryHidden<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    bool enabled_ = Bool::read(reader);
    return TogglePreHistoryHidden<X>(channel_, enabled_);
}

template <class X>
std::string TogglePreHistoryHidden<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Bool::write(enabled);
    return buffer;
}

template <class X>
GetLeftChannels<X>::GetLeftChannels(int offset_) {}

template <class X>
GetLeftChannels<X> GetLeftChannels<X>::read(Reader reader)
{
    int offset_ = Int::read(reader);
    return GetLeftChannels<X>(offset_);
}

template <class X>
std::string GetLeftChannels<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    return buffer;
}
template <class X>
GetGroupsForDiscussion<X> GetGroupsForDiscussion<X>::read(Reader reader)
{
    return GetGroupsForDiscussion<X>();
}

template <class X>
std::string GetGroupsForDiscussion<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
SetDiscussionGroup<X>::SetDiscussionGroup(TLObject broadcast_, TLObject group_) {}

template <class X>
SetDiscussionGroup<X> SetDiscussionGroup<X>::read(Reader reader)
{
    TLObject broadcast_ = TLObject::read(reader);
    TLObject group_ = TLObject::read(reader);
    return SetDiscussionGroup<X>(broadcast_, group_);
}

template <class X>
std::string SetDiscussionGroup<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += broadcast.write();
    buffer += group.write();
    return buffer;
}

template <class X>
EditCreator<X>::EditCreator(TLObject channel_, TLObject user_id_, TLObject password_) {}

template <class X>
EditCreator<X> EditCreator<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    TLObject password_ = TLObject::read(reader);
    return EditCreator<X>(channel_, user_id_, password_);
}

template <class X>
std::string EditCreator<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += user_id.write();
    buffer += password.write();
    return buffer;
}

template <class X>
EditLocation<X>::EditLocation(TLObject channel_, TLObject geo_point_, std::string address_) {}

template <class X>
EditLocation<X> EditLocation<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    TLObject geo_point_ = TLObject::read(reader);
    std::string address_ = String::read(reader);
    return EditLocation<X>(channel_, geo_point_, address_);
}

template <class X>
std::string EditLocation<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += geo_point.write();
    buffer += String::write(address);
    return buffer;
}

template <class X>
ToggleSlowMode<X>::ToggleSlowMode(TLObject channel_, int seconds_) {}

template <class X>
ToggleSlowMode<X> ToggleSlowMode<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    int seconds_ = Int::read(reader);
    return ToggleSlowMode<X>(channel_, seconds_);
}

template <class X>
std::string ToggleSlowMode<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(seconds);
    return buffer;
}
template <class X>
GetInactiveChannels<X> GetInactiveChannels<X>::read(Reader reader)
{
    return GetInactiveChannels<X>();
}

template <class X>
std::string GetInactiveChannels<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ConvertToGigagroup<X>::ConvertToGigagroup(TLObject channel_) {}

template <class X>
ConvertToGigagroup<X> ConvertToGigagroup<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    return ConvertToGigagroup<X>(channel_);
}

template <class X>
std::string ConvertToGigagroup<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}
