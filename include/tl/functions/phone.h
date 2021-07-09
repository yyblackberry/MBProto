#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetCallConfig
{
private:
    int __id = 0x55451fa9;

public:
    GetCallConfig() = default;
    static GetCallConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class RequestCall
{
private:
    int __id = 0x42ff96ed;

public:
    std::optional<bool> video;
    TLObject user_id;
    int random_id;
    std::string g_a_hash;
    TLObject protocol;
    RequestCall(TLObject user_id_, int random_id_, std::string g_a_hash_, TLObject protocol_, std::optional<bool> video_ = std::nullopt);
    static RequestCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptCall
{
private:
    int __id = 0x3bd2b4a0;

public:
    TLObject peer;
    std::string g_b;
    TLObject protocol;
    AcceptCall(TLObject peer_, std::string g_b_, TLObject protocol_);
    static AcceptCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class ConfirmCall
{
private:
    int __id = 0x2efe1722;

public:
    TLObject peer;
    std::string g_a;
    long key_fingerprint;
    TLObject protocol;
    ConfirmCall(TLObject peer_, std::string g_a_, long key_fingerprint_, TLObject protocol_);
    static ConfirmCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReceivedCall
{
private:
    int __id = 0x17d54f61;

public:
    TLObject peer;
    ReceivedCall(TLObject peer_);
    static ReceivedCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class DiscardCall
{
private:
    int __id = 0xb2cbc1c0;

public:
    std::optional<bool> video;
    TLObject peer;
    int duration;
    TLObject reason;
    long connection_id;
    DiscardCall(TLObject peer_, int duration_, TLObject reason_, long connection_id_, std::optional<bool> video_ = std::nullopt);
    static DiscardCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetCallRating
{
private:
    int __id = 0x59ead627;

public:
    std::optional<bool> user_initiative;
    TLObject peer;
    int rating;
    std::string comment;
    SetCallRating(TLObject peer_, int rating_, std::string comment_, std::optional<bool> user_initiative_ = std::nullopt);
    static SetCallRating<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveCallDebug
{
private:
    int __id = 0x277add7e;

public:
    TLObject peer;
    TLObject debug;
    SaveCallDebug(TLObject peer_, TLObject debug_);
    static SaveCallDebug<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendSignalingData
{
private:
    int __id = 0xff7a9383;

public:
    TLObject peer;
    std::string data;
    SendSignalingData(TLObject peer_, std::string data_);
    static SendSignalingData<X> read(Reader reader);
    std::string write();
};

template <class X>
class CreateGroupCall
{
private:
    int __id = 0x48cdc6d8;

public:
    TLObject peer;
    int random_id;
    std::optional<std::string> title;
    std::optional<int> schedule_date;
    CreateGroupCall(TLObject peer_, int random_id_, std::optional<std::string> title_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static CreateGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class JoinGroupCall
{
private:
    int __id = 0xb132ff7b;

public:
    std::optional<bool> muted;
    std::optional<bool> video_stopped;
    TLObject call;
    TLObject join_as;
    std::optional<std::string> invite_hash;
    TLObject params;
    JoinGroupCall(TLObject call_, TLObject join_as_, TLObject params_, std::optional<bool> muted_ = std::nullopt, std::optional<bool> video_stopped_ = std::nullopt, std::optional<std::string> invite_hash_ = std::nullopt);
    static JoinGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class LeaveGroupCall
{
private:
    int __id = 0x500377f9;

public:
    TLObject call;
    int source;
    LeaveGroupCall(TLObject call_, int source_);
    static LeaveGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class InviteToGroupCall
{
private:
    int __id = 0x7b393160;

public:
    TLObject call;
    std::vector<TLObject> users;
    InviteToGroupCall(TLObject call_, std::vector<TLObject> users_);
    static InviteToGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class DiscardGroupCall
{
private:
    int __id = 0x7a777135;

public:
    TLObject call;
    DiscardGroupCall(TLObject call_);
    static DiscardGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleGroupCallSettings
{
private:
    int __id = 0x74bbb43d;

public:
    std::optional<bool> reset_invite_hash;
    TLObject call;
    std::optional<bool> join_muted;
    ToggleGroupCallSettings(TLObject call_, std::optional<bool> reset_invite_hash_ = std::nullopt, std::optional<bool> join_muted_ = std::nullopt);
    static ToggleGroupCallSettings<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetGroupCall
{
private:
    int __id = 0xc7cb017;

public:
    TLObject call;
    GetGroupCall(TLObject call_);
    static GetGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetGroupParticipants
{
private:
    int __id = 0xc558d8ab;

public:
    TLObject call;
    std::vector<TLObject> ids;
    std::vector<int> sources;
    std::string offset;
    int limit;
    GetGroupParticipants(TLObject call_, std::vector<TLObject> ids_, std::vector<int> sources_, std::string offset_, int limit_);
    static GetGroupParticipants<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckGroupCall
{
private:
    int __id = 0xb59cf977;

public:
    TLObject call;
    std::vector<int> sources;
    CheckGroupCall(TLObject call_, std::vector<int> sources_);
    static CheckGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleGroupCallRecord
{
private:
    int __id = 0xc02a66d7;

public:
    std::optional<bool> start;
    TLObject call;
    std::optional<std::string> title;
    ToggleGroupCallRecord(TLObject call_, std::optional<bool> start_ = std::nullopt, std::optional<std::string> title_ = std::nullopt);
    static ToggleGroupCallRecord<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditGroupCallParticipant
{
private:
    int __id = 0xa5273abf;

public:
    TLObject call;
    TLObject participant;
    std::optional<bool> muted;
    std::optional<int> volume;
    std::optional<bool> raise_hand;
    std::optional<bool> video_stopped;
    std::optional<bool> video_paused;
    std::optional<bool> presentation_paused;
    EditGroupCallParticipant(TLObject call_, TLObject participant_, std::optional<bool> muted_ = std::nullopt, std::optional<int> volume_ = std::nullopt, std::optional<bool> raise_hand_ = std::nullopt, std::optional<bool> video_stopped_ = std::nullopt, std::optional<bool> video_paused_ = std::nullopt, std::optional<bool> presentation_paused_ = std::nullopt);
    static EditGroupCallParticipant<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditGroupCallTitle
{
private:
    int __id = 0x1ca6ac0a;

public:
    TLObject call;
    std::string title;
    EditGroupCallTitle(TLObject call_, std::string title_);
    static EditGroupCallTitle<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetGroupCallJoinAs
{
private:
    int __id = 0xef7c213a;

public:
    TLObject peer;
    GetGroupCallJoinAs(TLObject peer_);
    static GetGroupCallJoinAs<X> read(Reader reader);
    std::string write();
};

template <class X>
class ExportGroupCallInvite
{
private:
    int __id = 0xe6aa647f;

public:
    std::optional<bool> can_self_unmute;
    TLObject call;
    ExportGroupCallInvite(TLObject call_, std::optional<bool> can_self_unmute_ = std::nullopt);
    static ExportGroupCallInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleGroupCallStartSubscription
{
private:
    int __id = 0x219c34e6;

public:
    TLObject call;
    bool subscribed;
    ToggleGroupCallStartSubscription(TLObject call_, bool subscribed_);
    static ToggleGroupCallStartSubscription<X> read(Reader reader);
    std::string write();
};

template <class X>
class StartScheduledGroupCall
{
private:
    int __id = 0x5680e342;

public:
    TLObject call;
    StartScheduledGroupCall(TLObject call_);
    static StartScheduledGroupCall<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveDefaultGroupCallJoinAs
{
private:
    int __id = 0x575e1f8c;

public:
    TLObject peer;
    TLObject join_as;
    SaveDefaultGroupCallJoinAs(TLObject peer_, TLObject join_as_);
    static SaveDefaultGroupCallJoinAs<X> read(Reader reader);
    std::string write();
};

template <class X>
class JoinGroupCallPresentation
{
private:
    int __id = 0xcbea6bc4;

public:
    TLObject call;
    TLObject params;
    JoinGroupCallPresentation(TLObject call_, TLObject params_);
    static JoinGroupCallPresentation<X> read(Reader reader);
    std::string write();
};

template <class X>
class LeaveGroupCallPresentation
{
private:
    int __id = 0x1c50d144;

public:
    TLObject call;
    LeaveGroupCallPresentation(TLObject call_);
    static LeaveGroupCallPresentation<X> read(Reader reader);
    std::string write();
};
