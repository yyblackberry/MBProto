#include "tl/functions/messages.h"

template <class X>
GetMessages<X>::GetMessages(std::vector<TLObject> id_) {}

template <class X>
GetMessages<X> GetMessages<X>::read(Reader reader)
{
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return GetMessages<X>(id_);
}

template <class X>
std::string GetMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
GetDialogs<X>::GetDialogs(int offset_date_, int offset_id_, TLObject offset_peer_, int limit_, int hash_, std::optional<bool> exclude_pinned_, std::optional<int> folder_id_) {}

template <class X>
GetDialogs<X> GetDialogs<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> exclude_pinned_;

    if (1 << 0)
        exclude_pinned_ = true;
    else
        exclude_pinned_ = std::nullopt;
    std::optional<int> folder_id_;

    if (1 << 1)
        folder_id_ = Int::read(reader);
    else
        folder_id_ = std::nullopt;
    int offset_date_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    TLObject offset_peer_ = TLObject::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetDialogs<X>(offset_date_, offset_id_, offset_peer_, limit_, hash_, exclude_pinned_, folder_id_);
}

template <class X>
std::string GetDialogs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= exclude_pinned ? 1 << 0 : 0;
    flags |= folder_id ? 1 << 1 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += Int::write(offset_date);
    buffer += Int::write(offset_id);
    buffer += offset_peer.write();
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetHistory<X>::GetHistory(TLObject peer_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_) {}

template <class X>
GetHistory<X> GetHistory<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int offset_id_ = Int::read(reader);
    int offset_date_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetHistory<X>(peer_, offset_id_, offset_date_, add_offset_, limit_, max_id_, min_id_, hash_);
}

template <class X>
std::string GetHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(offset_id);
    buffer += Int::write(offset_date);
    buffer += Int::write(add_offset);
    buffer += Int::write(limit);
    buffer += Int::write(max_id);
    buffer += Int::write(min_id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
Search<X>::Search(TLObject peer_, std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_, std::optional<TLObject> from_id_, std::optional<int> top_msg_id_) {}

template <class X>
Search<X> Search<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    std::string q_ = String::read(reader);
    std::optional<TLObject> from_id_;

    if (1 << 0)
        from_id_ = TLObject::read(reader);
    else
        from_id_ = std::nullopt;
    std::optional<int> top_msg_id_;

    if (1 << 1)
        top_msg_id_ = Int::read(reader);
    else
        top_msg_id_ = std::nullopt;
    TLObject filter_ = TLObject::read(reader);
    int min_date_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return Search<X>(peer_, q_, filter_, min_date_, max_date_, offset_id_, add_offset_, limit_, max_id_, min_id_, hash_, from_id_, top_msg_id_);
}

template <class X>
std::string Search<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= from_id ? 1 << 0 : 0;
    flags |= top_msg_id ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += String::write(q);

    if (from_id)
        buffer += from_id.value().write();

    if (top_msg_id)
        buffer += Int::write(top_msg_id.value());
    buffer += filter.write();
    buffer += Int::write(min_date);
    buffer += Int::write(max_date);
    buffer += Int::write(offset_id);
    buffer += Int::write(add_offset);
    buffer += Int::write(limit);
    buffer += Int::write(max_id);
    buffer += Int::write(min_id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ReadHistory<X>::ReadHistory(TLObject peer_, int max_id_) {}

template <class X>
ReadHistory<X> ReadHistory<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int max_id_ = Int::read(reader);
    return ReadHistory<X>(peer_, max_id_);
}

template <class X>
std::string ReadHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(max_id);
    return buffer;
}

template <class X>
DeleteHistory<X>::DeleteHistory(TLObject peer_, int max_id_, std::optional<bool> just_clear_, std::optional<bool> revoke_) {}

template <class X>
DeleteHistory<X> DeleteHistory<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> just_clear_;

    if (1 << 0)
        just_clear_ = true;
    else
        just_clear_ = std::nullopt;
    std::optional<bool> revoke_;

    if (1 << 1)
        revoke_ = true;
    else
        revoke_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int max_id_ = Int::read(reader);
    return DeleteHistory<X>(peer_, max_id_, just_clear_, revoke_);
}

template <class X>
std::string DeleteHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= just_clear ? 1 << 0 : 0;
    flags |= revoke ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += Int::write(max_id);
    return buffer;
}

template <class X>
DeleteMessages<X>::DeleteMessages(std::vector<int> id_, std::optional<bool> revoke_) {}

template <class X>
DeleteMessages<X> DeleteMessages<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_;

    if (1 << 0)
        revoke_ = true;
    else
        revoke_ = std::nullopt;
    std::vector<int> id_ = Vector<int>::read(reader);
    return DeleteMessages<X>(id_, revoke_);
}

template <class X>
std::string DeleteMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke ? 1 << 0 : 0;
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
ReceivedMessages<X>::ReceivedMessages(int max_id_) {}

template <class X>
ReceivedMessages<X> ReceivedMessages<X>::read(Reader reader)
{
    int max_id_ = Int::read(reader);
    return ReceivedMessages<X>(max_id_);
}

template <class X>
std::string ReceivedMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(max_id);
    return buffer;
}

template <class X>
SetTyping<X>::SetTyping(TLObject peer_, TLObject action_, std::optional<int> top_msg_id_) {}

template <class X>
SetTyping<X> SetTyping<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> top_msg_id_;

    if (1 << 0)
        top_msg_id_ = Int::read(reader);
    else
        top_msg_id_ = std::nullopt;
    TLObject action_ = TLObject::read(reader);
    return SetTyping<X>(peer_, action_, top_msg_id_);
}

template <class X>
std::string SetTyping<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= top_msg_id ? 1 << 0 : 0;
    buffer += peer.write();

    if (top_msg_id)
        buffer += Int::write(top_msg_id.value());
    buffer += action.write();
    return buffer;
}

template <class X>
SendMessage<X>::SendMessage(TLObject peer_, std::string message_, long random_id_, std::optional<bool> no_webpage_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

template <class X>
SendMessage<X> SendMessage<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;

    if (1 << 1)
        no_webpage_ = true;
    else
        no_webpage_ = std::nullopt;
    std::optional<bool> silent_;

    if (1 << 5)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> background_;

    if (1 << 6)
        background_ = true;
    else
        background_ = std::nullopt;
    std::optional<bool> clear_draft_;

    if (1 << 7)
        clear_draft_ = true;
    else
        clear_draft_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> reply_to_msg_id_;

    if (1 << 0)
        reply_to_msg_id_ = Int::read(reader);
    else
        reply_to_msg_id_ = std::nullopt;
    std::string message_ = String::read(reader);
    long random_id_ = Long::read(reader);
    std::optional<TLObject> reply_markup_;

    if (1 << 2)
        reply_markup_ = TLObject::read(reader);
    else
        reply_markup_ = std::nullopt;
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    std::optional<int> schedule_date_;

    if (1 << 10)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return SendMessage<X>(peer_, message_, random_id_, no_webpage_, silent_, background_, clear_draft_, reply_to_msg_id_, reply_markup_, entities_, schedule_date_);
}

template <class X>
std::string SendMessage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 1 : 0;
    flags |= silent ? 1 << 5 : 0;
    flags |= background ? 1 << 6 : 0;
    flags |= clear_draft ? 1 << 7 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    flags |= entities ? 1 << 3 : 0;
    flags |= schedule_date ? 1 << 10 : 0;
    buffer += peer.write();

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += String::write(message);
    buffer += Long::write(random_id);

    if (reply_markup)
        buffer += reply_markup.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
SendMedia<X>::SendMedia(TLObject peer_, TLObject media_, std::string message_, long random_id_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

template <class X>
SendMedia<X> SendMedia<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 5)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> background_;

    if (1 << 6)
        background_ = true;
    else
        background_ = std::nullopt;
    std::optional<bool> clear_draft_;

    if (1 << 7)
        clear_draft_ = true;
    else
        clear_draft_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> reply_to_msg_id_;

    if (1 << 0)
        reply_to_msg_id_ = Int::read(reader);
    else
        reply_to_msg_id_ = std::nullopt;
    TLObject media_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    long random_id_ = Long::read(reader);
    std::optional<TLObject> reply_markup_;

    if (1 << 2)
        reply_markup_ = TLObject::read(reader);
    else
        reply_markup_ = std::nullopt;
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    std::optional<int> schedule_date_;

    if (1 << 10)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return SendMedia<X>(peer_, media_, message_, random_id_, silent_, background_, clear_draft_, reply_to_msg_id_, reply_markup_, entities_, schedule_date_);
}

template <class X>
std::string SendMedia<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 5 : 0;
    flags |= background ? 1 << 6 : 0;
    flags |= clear_draft ? 1 << 7 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    flags |= entities ? 1 << 3 : 0;
    flags |= schedule_date ? 1 << 10 : 0;
    buffer += peer.write();

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += media.write();
    buffer += String::write(message);
    buffer += Long::write(random_id);

    if (reply_markup)
        buffer += reply_markup.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
ForwardMessages<X>::ForwardMessages(TLObject from_peer_, std::vector<int> id_, std::vector<long> random_id_, TLObject to_peer_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> with_my_score_, std::optional<int> schedule_date_) {}

template <class X>
ForwardMessages<X> ForwardMessages<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 5)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> background_;

    if (1 << 6)
        background_ = true;
    else
        background_ = std::nullopt;
    std::optional<bool> with_my_score_;

    if (1 << 8)
        with_my_score_ = true;
    else
        with_my_score_ = std::nullopt;
    TLObject from_peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    std::vector<long> random_id_ = Vector<long>::read(reader);
    TLObject to_peer_ = TLObject::read(reader);
    std::optional<int> schedule_date_;

    if (1 << 10)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return ForwardMessages<X>(from_peer_, id_, random_id_, to_peer_, silent_, background_, with_my_score_, schedule_date_);
}

template <class X>
std::string ForwardMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 5 : 0;
    flags |= background ? 1 << 6 : 0;
    flags |= with_my_score ? 1 << 8 : 0;
    flags |= schedule_date ? 1 << 10 : 0;
    buffer += from_peer.write();
    buffer += Vector<int>::write(id);
    buffer += Vector<long>::write(random_id);
    buffer += to_peer.write();

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
ReportSpam<X>::ReportSpam(TLObject peer_) {}

template <class X>
ReportSpam<X> ReportSpam<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return ReportSpam<X>(peer_);
}

template <class X>
std::string ReportSpam<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
GetPeerSettings<X>::GetPeerSettings(TLObject peer_) {}

template <class X>
GetPeerSettings<X> GetPeerSettings<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return GetPeerSettings<X>(peer_);
}

template <class X>
std::string GetPeerSettings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
Report<X>::Report(TLObject peer_, std::vector<int> id_, TLObject reason_, std::string message_) {}

template <class X>
Report<X> Report<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    TLObject reason_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    return Report<X>(peer_, id_, reason_, message_);
}

template <class X>
std::string Report<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}

template <class X>
GetChats<X>::GetChats(std::vector<int> id_) {}

template <class X>
GetChats<X> GetChats<X>::read(Reader reader)
{
    std::vector<int> id_ = Vector<int>::read(reader);
    return GetChats<X>(id_);
}

template <class X>
std::string GetChats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
GetFullChat<X>::GetFullChat(int chat_id_) {}

template <class X>
GetFullChat<X> GetFullChat<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return GetFullChat<X>(chat_id_);
}

template <class X>
std::string GetFullChat<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

template <class X>
EditChatTitle<X>::EditChatTitle(int chat_id_, std::string title_) {}

template <class X>
EditChatTitle<X> EditChatTitle<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    return EditChatTitle<X>(chat_id_, title_);
}

template <class X>
std::string EditChatTitle<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += String::write(title);
    return buffer;
}

template <class X>
EditChatPhoto<X>::EditChatPhoto(int chat_id_, TLObject photo_) {}

template <class X>
EditChatPhoto<X> EditChatPhoto<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject photo_ = TLObject::read(reader);
    return EditChatPhoto<X>(chat_id_, photo_);
}

template <class X>
std::string EditChatPhoto<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += photo.write();
    return buffer;
}

template <class X>
AddChatUser<X>::AddChatUser(int chat_id_, TLObject user_id_, int fwd_limit_) {}

template <class X>
AddChatUser<X> AddChatUser<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    int fwd_limit_ = Int::read(reader);
    return AddChatUser<X>(chat_id_, user_id_, fwd_limit_);
}

template <class X>
std::string AddChatUser<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    buffer += Int::write(fwd_limit);
    return buffer;
}

template <class X>
DeleteChatUser<X>::DeleteChatUser(int chat_id_, TLObject user_id_, std::optional<bool> revoke_history_) {}

template <class X>
DeleteChatUser<X> DeleteChatUser<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_history_;

    if (1 << 0)
        revoke_history_ = true;
    else
        revoke_history_ = std::nullopt;
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    return DeleteChatUser<X>(chat_id_, user_id_, revoke_history_);
}

template <class X>
std::string DeleteChatUser<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke_history ? 1 << 0 : 0;
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    return buffer;
}

template <class X>
CreateChat<X>::CreateChat(std::vector<TLObject> users_, std::string title_) {}

template <class X>
CreateChat<X> CreateChat<X>::read(Reader reader)
{
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    std::string title_ = String::read(reader);
    return CreateChat<X>(users_, title_);
}

template <class X>
std::string CreateChat<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(users);
    buffer += String::write(title);
    return buffer;
}

template <class X>
GetDhConfig<X>::GetDhConfig(int version_, int random_length_) {}

template <class X>
GetDhConfig<X> GetDhConfig<X>::read(Reader reader)
{
    int version_ = Int::read(reader);
    int random_length_ = Int::read(reader);
    return GetDhConfig<X>(version_, random_length_);
}

template <class X>
std::string GetDhConfig<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(version);
    buffer += Int::write(random_length);
    return buffer;
}

template <class X>
RequestEncryption<X>::RequestEncryption(TLObject user_id_, int random_id_, std::string g_a_) {}

template <class X>
RequestEncryption<X> RequestEncryption<X>::read(Reader reader)
{
    TLObject user_id_ = TLObject::read(reader);
    int random_id_ = Int::read(reader);
    std::string g_a_ = Bytes::read(reader);
    return RequestEncryption<X>(user_id_, random_id_, g_a_);
}

template <class X>
std::string RequestEncryption<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(random_id);
    buffer += Bytes::write(g_a);
    return buffer;
}

template <class X>
AcceptEncryption<X>::AcceptEncryption(TLObject peer_, std::string g_b_, long key_fingerprint_) {}

template <class X>
AcceptEncryption<X> AcceptEncryption<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string g_b_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    return AcceptEncryption<X>(peer_, g_b_, key_fingerprint_);
}

template <class X>
std::string AcceptEncryption<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_b);
    buffer += Long::write(key_fingerprint);
    return buffer;
}

template <class X>
DiscardEncryption<X>::DiscardEncryption(int chat_id_, std::optional<bool> delete_history_) {}

template <class X>
DiscardEncryption<X> DiscardEncryption<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> delete_history_;

    if (1 << 0)
        delete_history_ = true;
    else
        delete_history_ = std::nullopt;
    int chat_id_ = Int::read(reader);
    return DiscardEncryption<X>(chat_id_, delete_history_);
}

template <class X>
std::string DiscardEncryption<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= delete_history ? 1 << 0 : 0;
    buffer += Int::write(chat_id);
    return buffer;
}

template <class X>
SetEncryptedTyping<X>::SetEncryptedTyping(TLObject peer_, bool typing_) {}

template <class X>
SetEncryptedTyping<X> SetEncryptedTyping<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    bool typing_ = Bool::read(reader);
    return SetEncryptedTyping<X>(peer_, typing_);
}

template <class X>
std::string SetEncryptedTyping<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bool::write(typing);
    return buffer;
}

template <class X>
ReadEncryptedHistory<X>::ReadEncryptedHistory(TLObject peer_, int max_date_) {}

template <class X>
ReadEncryptedHistory<X> ReadEncryptedHistory<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int max_date_ = Int::read(reader);
    return ReadEncryptedHistory<X>(peer_, max_date_);
}

template <class X>
std::string ReadEncryptedHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(max_date);
    return buffer;
}

template <class X>
SendEncrypted<X>::SendEncrypted(TLObject peer_, long random_id_, std::string data_, std::optional<bool> silent_) {}

template <class X>
SendEncrypted<X> SendEncrypted<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 0)
        silent_ = true;
    else
        silent_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    return SendEncrypted<X>(peer_, random_id_, data_, silent_);
}

template <class X>
std::string SendEncrypted<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += Bytes::write(data);
    return buffer;
}

template <class X>
SendEncryptedFile<X>::SendEncryptedFile(TLObject peer_, long random_id_, std::string data_, TLObject file_, std::optional<bool> silent_) {}

template <class X>
SendEncryptedFile<X> SendEncryptedFile<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 0)
        silent_ = true;
    else
        silent_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    TLObject file_ = TLObject::read(reader);
    return SendEncryptedFile<X>(peer_, random_id_, data_, file_, silent_);
}

template <class X>
std::string SendEncryptedFile<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += Bytes::write(data);
    buffer += file.write();
    return buffer;
}

template <class X>
SendEncryptedService<X>::SendEncryptedService(TLObject peer_, long random_id_, std::string data_) {}

template <class X>
SendEncryptedService<X> SendEncryptedService<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    return SendEncryptedService<X>(peer_, random_id_, data_);
}

template <class X>
std::string SendEncryptedService<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += Bytes::write(data);
    return buffer;
}

template <class X>
ReceivedQueue<X>::ReceivedQueue(int max_qts_) {}

template <class X>
ReceivedQueue<X> ReceivedQueue<X>::read(Reader reader)
{
    int max_qts_ = Int::read(reader);
    return ReceivedQueue<X>(max_qts_);
}

template <class X>
std::string ReceivedQueue<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(max_qts);
    return buffer;
}

template <class X>
ReportEncryptedSpam<X>::ReportEncryptedSpam(TLObject peer_) {}

template <class X>
ReportEncryptedSpam<X> ReportEncryptedSpam<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return ReportEncryptedSpam<X>(peer_);
}

template <class X>
std::string ReportEncryptedSpam<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
ReadMessageContents<X>::ReadMessageContents(std::vector<int> id_) {}

template <class X>
ReadMessageContents<X> ReadMessageContents<X>::read(Reader reader)
{
    std::vector<int> id_ = Vector<int>::read(reader);
    return ReadMessageContents<X>(id_);
}

template <class X>
std::string ReadMessageContents<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
GetStickers<X>::GetStickers(std::string emoticon_, int hash_) {}

template <class X>
GetStickers<X> GetStickers<X>::read(Reader reader)
{
    std::string emoticon_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetStickers<X>(emoticon_, hash_);
}

template <class X>
std::string GetStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(emoticon);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetAllStickers<X>::GetAllStickers(int hash_) {}

template <class X>
GetAllStickers<X> GetAllStickers<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetAllStickers<X>(hash_);
}

template <class X>
std::string GetAllStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetWebPagePreview<X>::GetWebPagePreview(std::string message_, std::optional<std::vector<TLObject>> entities_) {}

template <class X>
GetWebPagePreview<X> GetWebPagePreview<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    return GetWebPagePreview<X>(message_, entities_);
}

template <class X>
std::string GetWebPagePreview<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= entities ? 1 << 3 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    return buffer;
}

template <class X>
ExportChatInvite<X>::ExportChatInvite(TLObject peer_, std::optional<bool> legacy_revoke_permanent_, std::optional<int> expire_date_, std::optional<int> usage_limit_) {}

template <class X>
ExportChatInvite<X> ExportChatInvite<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> legacy_revoke_permanent_;

    if (1 << 2)
        legacy_revoke_permanent_ = true;
    else
        legacy_revoke_permanent_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> expire_date_;

    if (1 << 0)
        expire_date_ = Int::read(reader);
    else
        expire_date_ = std::nullopt;
    std::optional<int> usage_limit_;

    if (1 << 1)
        usage_limit_ = Int::read(reader);
    else
        usage_limit_ = std::nullopt;
    return ExportChatInvite<X>(peer_, legacy_revoke_permanent_, expire_date_, usage_limit_);
}

template <class X>
std::string ExportChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= legacy_revoke_permanent ? 1 << 2 : 0;
    flags |= expire_date ? 1 << 0 : 0;
    flags |= usage_limit ? 1 << 1 : 0;
    buffer += peer.write();

    if (expire_date)
        buffer += Int::write(expire_date.value());

    if (usage_limit)
        buffer += Int::write(usage_limit.value());
    return buffer;
}

template <class X>
CheckChatInvite<X>::CheckChatInvite(std::string hash_) {}

template <class X>
CheckChatInvite<X> CheckChatInvite<X>::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    return CheckChatInvite<X>(hash_);
}

template <class X>
std::string CheckChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    return buffer;
}

template <class X>
ImportChatInvite<X>::ImportChatInvite(std::string hash_) {}

template <class X>
ImportChatInvite<X> ImportChatInvite<X>::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    return ImportChatInvite<X>(hash_);
}

template <class X>
std::string ImportChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    return buffer;
}

template <class X>
GetStickerSet<X>::GetStickerSet(TLObject stickerset_) {}

template <class X>
GetStickerSet<X> GetStickerSet<X>::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    return GetStickerSet<X>(stickerset_);
}

template <class X>
std::string GetStickerSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    return buffer;
}

template <class X>
InstallStickerSet<X>::InstallStickerSet(TLObject stickerset_, bool archived_) {}

template <class X>
InstallStickerSet<X> InstallStickerSet<X>::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    bool archived_ = Bool::read(reader);
    return InstallStickerSet<X>(stickerset_, archived_);
}

template <class X>
std::string InstallStickerSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += Bool::write(archived);
    return buffer;
}

template <class X>
UninstallStickerSet<X>::UninstallStickerSet(TLObject stickerset_) {}

template <class X>
UninstallStickerSet<X> UninstallStickerSet<X>::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    return UninstallStickerSet<X>(stickerset_);
}

template <class X>
std::string UninstallStickerSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    return buffer;
}

template <class X>
StartBot<X>::StartBot(TLObject bot_, TLObject peer_, long random_id_, std::string start_param_) {}

template <class X>
StartBot<X> StartBot<X>::read(Reader reader)
{
    TLObject bot_ = TLObject::read(reader);
    TLObject peer_ = TLObject::read(reader);
    long random_id_ = Long::read(reader);
    std::string start_param_ = String::read(reader);
    return StartBot<X>(bot_, peer_, random_id_, start_param_);
}

template <class X>
std::string StartBot<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += bot.write();
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += String::write(start_param);
    return buffer;
}

template <class X>
GetMessagesViews<X>::GetMessagesViews(TLObject peer_, std::vector<int> id_, bool increment_) {}

template <class X>
GetMessagesViews<X> GetMessagesViews<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    bool increment_ = Bool::read(reader);
    return GetMessagesViews<X>(peer_, id_, increment_);
}

template <class X>
std::string GetMessagesViews<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    buffer += Bool::write(increment);
    return buffer;
}

template <class X>
EditChatAdmin<X>::EditChatAdmin(int chat_id_, TLObject user_id_, bool is_admin_) {}

template <class X>
EditChatAdmin<X> EditChatAdmin<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    bool is_admin_ = Bool::read(reader);
    return EditChatAdmin<X>(chat_id_, user_id_, is_admin_);
}

template <class X>
std::string EditChatAdmin<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    buffer += Bool::write(is_admin);
    return buffer;
}

template <class X>
MigrateChat<X>::MigrateChat(int chat_id_) {}

template <class X>
MigrateChat<X> MigrateChat<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return MigrateChat<X>(chat_id_);
}

template <class X>
std::string MigrateChat<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

template <class X>
SearchGlobal<X>::SearchGlobal(std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_, std::optional<int> folder_id_) {}

template <class X>
SearchGlobal<X> SearchGlobal<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;

    if (1 << 0)
        folder_id_ = Int::read(reader);
    else
        folder_id_ = std::nullopt;
    std::string q_ = String::read(reader);
    TLObject filter_ = TLObject::read(reader);
    int min_date_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    int offset_rate_ = Int::read(reader);
    TLObject offset_peer_ = TLObject::read(reader);
    int offset_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return SearchGlobal<X>(q_, filter_, min_date_, max_date_, offset_rate_, offset_peer_, offset_id_, limit_, folder_id_);
}

template <class X>
std::string SearchGlobal<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= folder_id ? 1 << 0 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += String::write(q);
    buffer += filter.write();
    buffer += Int::write(min_date);
    buffer += Int::write(max_date);
    buffer += Int::write(offset_rate);
    buffer += offset_peer.write();
    buffer += Int::write(offset_id);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
ReorderStickerSets<X>::ReorderStickerSets(std::vector<long> order_, std::optional<bool> masks_) {}

template <class X>
ReorderStickerSets<X> ReorderStickerSets<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;

    if (1 << 0)
        masks_ = true;
    else
        masks_ = std::nullopt;
    std::vector<long> order_ = Vector<long>::read(reader);
    return ReorderStickerSets<X>(order_, masks_);
}

template <class X>
std::string ReorderStickerSets<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    buffer += Vector<long>::write(order);
    return buffer;
}

template <class X>
GetDocumentByHash<X>::GetDocumentByHash(std::string sha256_, int size_, std::string mime_type_) {}

template <class X>
GetDocumentByHash<X> GetDocumentByHash<X>::read(Reader reader)
{
    std::string sha256_ = Bytes::read(reader);
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    return GetDocumentByHash<X>(sha256_, size_, mime_type_);
}

template <class X>
std::string GetDocumentByHash<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(sha256);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    return buffer;
}

template <class X>
GetSavedGifs<X>::GetSavedGifs(int hash_) {}

template <class X>
GetSavedGifs<X> GetSavedGifs<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetSavedGifs<X>(hash_);
}

template <class X>
std::string GetSavedGifs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
SaveGif<X>::SaveGif(TLObject id_, bool unsave_) {}

template <class X>
SaveGif<X> SaveGif<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    bool unsave_ = Bool::read(reader);
    return SaveGif<X>(id_, unsave_);
}

template <class X>
std::string SaveGif<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Bool::write(unsave);
    return buffer;
}

template <class X>
GetInlineBotResults<X>::GetInlineBotResults(TLObject bot_, TLObject peer_, std::string query_, std::string offset_, std::optional<TLObject> geo_point_) {}

template <class X>
GetInlineBotResults<X> GetInlineBotResults<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject bot_ = TLObject::read(reader);
    TLObject peer_ = TLObject::read(reader);
    std::optional<TLObject> geo_point_;

    if (1 << 0)
        geo_point_ = TLObject::read(reader);
    else
        geo_point_ = std::nullopt;
    std::string query_ = String::read(reader);
    std::string offset_ = String::read(reader);
    return GetInlineBotResults<X>(bot_, peer_, query_, offset_, geo_point_);
}

template <class X>
std::string GetInlineBotResults<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= geo_point ? 1 << 0 : 0;
    buffer += bot.write();
    buffer += peer.write();

    if (geo_point)
        buffer += geo_point.value().write();
    buffer += String::write(query);
    buffer += String::write(offset);
    return buffer;
}

template <class X>
SetInlineBotResults<X>::SetInlineBotResults(long query_id_, std::vector<TLObject> results_, int cache_time_, std::optional<bool> gallery_, std::optional<bool> private_, std::optional<std::string> next_offset_, std::optional<TLObject> switch_pm_) {}

template <class X>
SetInlineBotResults<X> SetInlineBotResults<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> gallery_;

    if (1 << 0)
        gallery_ = true;
    else
        gallery_ = std::nullopt;
    std::optional<bool> private_;

    if (1 << 1)
        private_ = true;
    else
        private_ = std::nullopt;
    long query_id_ = Long::read(reader);
    std::vector<TLObject> results_ = Vector<TLObject>::read(reader);
    int cache_time_ = Int::read(reader);
    std::optional<std::string> next_offset_;

    if (1 << 2)
        next_offset_ = String::read(reader);
    else
        next_offset_ = std::nullopt;
    std::optional<TLObject> switch_pm_;

    if (1 << 3)
        switch_pm_ = TLObject::read(reader);
    else
        switch_pm_ = std::nullopt;
    return SetInlineBotResults<X>(query_id_, results_, cache_time_, gallery_, private_, next_offset_, switch_pm_);
}

template <class X>
std::string SetInlineBotResults<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= gallery ? 1 << 0 : 0;
    flags |= private ? 1 << 1 : 0;
    flags |= next_offset ? 1 << 2 : 0;
    flags |= switch_pm ? 1 << 3 : 0;
    buffer += Long::write(query_id);
    buffer += Vector<TLObject>::write(results);
    buffer += Int::write(cache_time);

    if (next_offset)
        buffer += String::write(next_offset.value());

    if (switch_pm)
        buffer += switch_pm.value().write();
    return buffer;
}

template <class X>
SendInlineBotResult<X>::SendInlineBotResult(TLObject peer_, long random_id_, long query_id_, std::string id_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<bool> hide_via_, std::optional<int> reply_to_msg_id_, std::optional<int> schedule_date_) {}

template <class X>
SendInlineBotResult<X> SendInlineBotResult<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 5)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> background_;

    if (1 << 6)
        background_ = true;
    else
        background_ = std::nullopt;
    std::optional<bool> clear_draft_;

    if (1 << 7)
        clear_draft_ = true;
    else
        clear_draft_ = std::nullopt;
    std::optional<bool> hide_via_;

    if (1 << 11)
        hide_via_ = true;
    else
        hide_via_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> reply_to_msg_id_;

    if (1 << 0)
        reply_to_msg_id_ = Int::read(reader);
    else
        reply_to_msg_id_ = std::nullopt;
    long random_id_ = Long::read(reader);
    long query_id_ = Long::read(reader);
    std::string id_ = String::read(reader);
    std::optional<int> schedule_date_;

    if (1 << 10)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return SendInlineBotResult<X>(peer_, random_id_, query_id_, id_, silent_, background_, clear_draft_, hide_via_, reply_to_msg_id_, schedule_date_);
}

template <class X>
std::string SendInlineBotResult<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 5 : 0;
    flags |= background ? 1 << 6 : 0;
    flags |= clear_draft ? 1 << 7 : 0;
    flags |= hide_via ? 1 << 11 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= schedule_date ? 1 << 10 : 0;
    buffer += peer.write();

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += Long::write(random_id);
    buffer += Long::write(query_id);
    buffer += String::write(id);

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
GetMessageEditData<X>::GetMessageEditData(TLObject peer_, int id_) {}

template <class X>
GetMessageEditData<X> GetMessageEditData<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    return GetMessageEditData<X>(peer_, id_);
}

template <class X>
std::string GetMessageEditData<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(id);
    return buffer;
}

template <class X>
EditMessage<X>::EditMessage(TLObject peer_, int id_, std::optional<bool> no_webpage_, std::optional<std::string> message_, std::optional<TLObject> media_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

template <class X>
EditMessage<X> EditMessage<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;

    if (1 << 1)
        no_webpage_ = true;
    else
        no_webpage_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    std::optional<std::string> message_;

    if (1 << 11)
        message_ = String::read(reader);
    else
        message_ = std::nullopt;
    std::optional<TLObject> media_;

    if (1 << 14)
        media_ = TLObject::read(reader);
    else
        media_ = std::nullopt;
    std::optional<TLObject> reply_markup_;

    if (1 << 2)
        reply_markup_ = TLObject::read(reader);
    else
        reply_markup_ = std::nullopt;
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    std::optional<int> schedule_date_;

    if (1 << 15)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return EditMessage<X>(peer_, id_, no_webpage_, message_, media_, reply_markup_, entities_, schedule_date_);
}

template <class X>
std::string EditMessage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 1 : 0;
    flags |= message ? 1 << 11 : 0;
    flags |= media ? 1 << 14 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    flags |= entities ? 1 << 3 : 0;
    flags |= schedule_date ? 1 << 15 : 0;
    buffer += peer.write();
    buffer += Int::write(id);

    if (message)
        buffer += String::write(message.value());

    if (media)
        buffer += media.value().write();

    if (reply_markup)
        buffer += reply_markup.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
EditInlineBotMessage<X>::EditInlineBotMessage(TLObject id_, std::optional<bool> no_webpage_, std::optional<std::string> message_, std::optional<TLObject> media_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_) {}

template <class X>
EditInlineBotMessage<X> EditInlineBotMessage<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;

    if (1 << 1)
        no_webpage_ = true;
    else
        no_webpage_ = std::nullopt;
    TLObject id_ = TLObject::read(reader);
    std::optional<std::string> message_;

    if (1 << 11)
        message_ = String::read(reader);
    else
        message_ = std::nullopt;
    std::optional<TLObject> media_;

    if (1 << 14)
        media_ = TLObject::read(reader);
    else
        media_ = std::nullopt;
    std::optional<TLObject> reply_markup_;

    if (1 << 2)
        reply_markup_ = TLObject::read(reader);
    else
        reply_markup_ = std::nullopt;
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    return EditInlineBotMessage<X>(id_, no_webpage_, message_, media_, reply_markup_, entities_);
}

template <class X>
std::string EditInlineBotMessage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 1 : 0;
    flags |= message ? 1 << 11 : 0;
    flags |= media ? 1 << 14 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    flags |= entities ? 1 << 3 : 0;
    buffer += id.write();

    if (message)
        buffer += String::write(message.value());

    if (media)
        buffer += media.value().write();

    if (reply_markup)
        buffer += reply_markup.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    return buffer;
}

template <class X>
GetBotCallbackAnswer<X>::GetBotCallbackAnswer(TLObject peer_, int msg_id_, std::optional<bool> game_, std::optional<std::string> data_, std::optional<TLObject> password_) {}

template <class X>
GetBotCallbackAnswer<X> GetBotCallbackAnswer<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> game_;

    if (1 << 1)
        game_ = true;
    else
        game_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    std::optional<std::string> data_;

    if (1 << 0)
        data_ = Bytes::read(reader);
    else
        data_ = std::nullopt;
    std::optional<TLObject> password_;

    if (1 << 2)
        password_ = TLObject::read(reader);
    else
        password_ = std::nullopt;
    return GetBotCallbackAnswer<X>(peer_, msg_id_, game_, data_, password_);
}

template <class X>
std::string GetBotCallbackAnswer<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= game ? 1 << 1 : 0;
    flags |= data ? 1 << 0 : 0;
    flags |= password ? 1 << 2 : 0;
    buffer += peer.write();
    buffer += Int::write(msg_id);

    if (data)
        buffer += Bytes::write(data.value());

    if (password)
        buffer += password.value().write();
    return buffer;
}

template <class X>
SetBotCallbackAnswer<X>::SetBotCallbackAnswer(long query_id_, int cache_time_, std::optional<bool> alert_, std::optional<std::string> message_, std::optional<std::string> url_) {}

template <class X>
SetBotCallbackAnswer<X> SetBotCallbackAnswer<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> alert_;

    if (1 << 1)
        alert_ = true;
    else
        alert_ = std::nullopt;
    long query_id_ = Long::read(reader);
    std::optional<std::string> message_;

    if (1 << 0)
        message_ = String::read(reader);
    else
        message_ = std::nullopt;
    std::optional<std::string> url_;

    if (1 << 2)
        url_ = String::read(reader);
    else
        url_ = std::nullopt;
    int cache_time_ = Int::read(reader);
    return SetBotCallbackAnswer<X>(query_id_, cache_time_, alert_, message_, url_);
}

template <class X>
std::string SetBotCallbackAnswer<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= alert ? 1 << 1 : 0;
    flags |= message ? 1 << 0 : 0;
    flags |= url ? 1 << 2 : 0;
    buffer += Long::write(query_id);

    if (message)
        buffer += String::write(message.value());

    if (url)
        buffer += String::write(url.value());
    buffer += Int::write(cache_time);
    return buffer;
}

template <class X>
GetPeerDialogs<X>::GetPeerDialogs(std::vector<TLObject> peers_) {}

template <class X>
GetPeerDialogs<X> GetPeerDialogs<X>::read(Reader reader)
{
    std::vector<TLObject> peers_ = Vector<TLObject>::read(reader);
    return GetPeerDialogs<X>(peers_);
}

template <class X>
std::string GetPeerDialogs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(peers);
    return buffer;
}

template <class X>
SaveDraft<X>::SaveDraft(TLObject peer_, std::string message_, std::optional<bool> no_webpage_, std::optional<int> reply_to_msg_id_, std::optional<std::vector<TLObject>> entities_) {}

template <class X>
SaveDraft<X> SaveDraft<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;

    if (1 << 1)
        no_webpage_ = true;
    else
        no_webpage_ = std::nullopt;
    std::optional<int> reply_to_msg_id_;

    if (1 << 0)
        reply_to_msg_id_ = Int::read(reader);
    else
        reply_to_msg_id_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;

    if (1 << 3)
        entities_ = Vector<TLObject>::read(reader);
    else
        entities_ = std::nullopt;
    return SaveDraft<X>(peer_, message_, no_webpage_, reply_to_msg_id_, entities_);
}

template <class X>
std::string SaveDraft<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 1 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= entities ? 1 << 3 : 0;

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += peer.write();
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    return buffer;
}
template <class X>
GetAllDrafts<X> GetAllDrafts<X>::read(Reader reader)
{
    return GetAllDrafts<X>();
}

template <class X>
std::string GetAllDrafts<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetFeaturedStickers<X>::GetFeaturedStickers(int hash_) {}

template <class X>
GetFeaturedStickers<X> GetFeaturedStickers<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetFeaturedStickers<X>(hash_);
}

template <class X>
std::string GetFeaturedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ReadFeaturedStickers<X>::ReadFeaturedStickers(std::vector<long> id_) {}

template <class X>
ReadFeaturedStickers<X> ReadFeaturedStickers<X>::read(Reader reader)
{
    std::vector<long> id_ = Vector<long>::read(reader);
    return ReadFeaturedStickers<X>(id_);
}

template <class X>
std::string ReadFeaturedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(id);
    return buffer;
}

template <class X>
GetRecentStickers<X>::GetRecentStickers(int hash_, std::optional<bool> attached_) {}

template <class X>
GetRecentStickers<X> GetRecentStickers<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;

    if (1 << 0)
        attached_ = true;
    else
        attached_ = std::nullopt;
    int hash_ = Int::read(reader);
    return GetRecentStickers<X>(hash_, attached_);
}

template <class X>
std::string GetRecentStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
SaveRecentSticker<X>::SaveRecentSticker(TLObject id_, bool unsave_, std::optional<bool> attached_) {}

template <class X>
SaveRecentSticker<X> SaveRecentSticker<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;

    if (1 << 0)
        attached_ = true;
    else
        attached_ = std::nullopt;
    TLObject id_ = TLObject::read(reader);
    bool unsave_ = Bool::read(reader);
    return SaveRecentSticker<X>(id_, unsave_, attached_);
}

template <class X>
std::string SaveRecentSticker<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    buffer += id.write();
    buffer += Bool::write(unsave);
    return buffer;
}

template <class X>
ClearRecentStickers<X>::ClearRecentStickers(std::optional<bool> attached_) {}

template <class X>
ClearRecentStickers<X> ClearRecentStickers<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;

    if (1 << 0)
        attached_ = true;
    else
        attached_ = std::nullopt;
    return ClearRecentStickers<X>(attached_);
}

template <class X>
std::string ClearRecentStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    return buffer;
}

template <class X>
GetArchivedStickers<X>::GetArchivedStickers(long offset_id_, int limit_, std::optional<bool> masks_) {}

template <class X>
GetArchivedStickers<X> GetArchivedStickers<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;

    if (1 << 0)
        masks_ = true;
    else
        masks_ = std::nullopt;
    long offset_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetArchivedStickers<X>(offset_id_, limit_, masks_);
}

template <class X>
std::string GetArchivedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    buffer += Long::write(offset_id);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
GetMaskStickers<X>::GetMaskStickers(int hash_) {}

template <class X>
GetMaskStickers<X> GetMaskStickers<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetMaskStickers<X>(hash_);
}

template <class X>
std::string GetMaskStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetAttachedStickers<X>::GetAttachedStickers(TLObject media_) {}

template <class X>
GetAttachedStickers<X> GetAttachedStickers<X>::read(Reader reader)
{
    TLObject media_ = TLObject::read(reader);
    return GetAttachedStickers<X>(media_);
}

template <class X>
std::string GetAttachedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += media.write();
    return buffer;
}

template <class X>
SetGameScore<X>::SetGameScore(TLObject peer_, int id_, TLObject user_id_, int score_, std::optional<bool> edit_message_, std::optional<bool> force_) {}

template <class X>
SetGameScore<X> SetGameScore<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> edit_message_;

    if (1 << 0)
        edit_message_ = true;
    else
        edit_message_ = std::nullopt;
    std::optional<bool> force_;

    if (1 << 1)
        force_ = true;
    else
        force_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    int score_ = Int::read(reader);
    return SetGameScore<X>(peer_, id_, user_id_, score_, edit_message_, force_);
}

template <class X>
std::string SetGameScore<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= edit_message ? 1 << 0 : 0;
    flags |= force ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += Int::write(id);
    buffer += user_id.write();
    buffer += Int::write(score);
    return buffer;
}

template <class X>
SetInlineGameScore<X>::SetInlineGameScore(TLObject id_, TLObject user_id_, int score_, std::optional<bool> edit_message_, std::optional<bool> force_) {}

template <class X>
SetInlineGameScore<X> SetInlineGameScore<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> edit_message_;

    if (1 << 0)
        edit_message_ = true;
    else
        edit_message_ = std::nullopt;
    std::optional<bool> force_;

    if (1 << 1)
        force_ = true;
    else
        force_ = std::nullopt;
    TLObject id_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    int score_ = Int::read(reader);
    return SetInlineGameScore<X>(id_, user_id_, score_, edit_message_, force_);
}

template <class X>
std::string SetInlineGameScore<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= edit_message ? 1 << 0 : 0;
    flags |= force ? 1 << 1 : 0;
    buffer += id.write();
    buffer += user_id.write();
    buffer += Int::write(score);
    return buffer;
}

template <class X>
GetGameHighScores<X>::GetGameHighScores(TLObject peer_, int id_, TLObject user_id_) {}

template <class X>
GetGameHighScores<X> GetGameHighScores<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    return GetGameHighScores<X>(peer_, id_, user_id_);
}

template <class X>
std::string GetGameHighScores<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(id);
    buffer += user_id.write();
    return buffer;
}

template <class X>
GetInlineGameHighScores<X>::GetInlineGameHighScores(TLObject id_, TLObject user_id_) {}

template <class X>
GetInlineGameHighScores<X> GetInlineGameHighScores<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    TLObject user_id_ = TLObject::read(reader);
    return GetInlineGameHighScores<X>(id_, user_id_);
}

template <class X>
std::string GetInlineGameHighScores<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += user_id.write();
    return buffer;
}

template <class X>
GetCommonChats<X>::GetCommonChats(TLObject user_id_, int max_id_, int limit_) {}

template <class X>
GetCommonChats<X> GetCommonChats<X>::read(Reader reader)
{
    TLObject user_id_ = TLObject::read(reader);
    int max_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetCommonChats<X>(user_id_, max_id_, limit_);
}

template <class X>
std::string GetCommonChats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(max_id);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
GetAllChats<X>::GetAllChats(std::vector<int> except_ids_) {}

template <class X>
GetAllChats<X> GetAllChats<X>::read(Reader reader)
{
    std::vector<int> except_ids_ = Vector<int>::read(reader);
    return GetAllChats<X>(except_ids_);
}

template <class X>
std::string GetAllChats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(except_ids);
    return buffer;
}

template <class X>
GetWebPage<X>::GetWebPage(std::string url_, int hash_) {}

template <class X>
GetWebPage<X> GetWebPage<X>::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetWebPage<X>(url_, hash_);
}

template <class X>
std::string GetWebPage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ToggleDialogPin<X>::ToggleDialogPin(TLObject peer_, std::optional<bool> pinned_) {}

template <class X>
ToggleDialogPin<X> ToggleDialogPin<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;

    if (1 << 0)
        pinned_ = true;
    else
        pinned_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    return ToggleDialogPin<X>(peer_, pinned_);
}

template <class X>
std::string ToggleDialogPin<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 0 : 0;
    buffer += peer.write();
    return buffer;
}

template <class X>
ReorderPinnedDialogs<X>::ReorderPinnedDialogs(int folder_id_, std::vector<TLObject> order_, std::optional<bool> force_) {}

template <class X>
ReorderPinnedDialogs<X> ReorderPinnedDialogs<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> force_;

    if (1 << 0)
        force_ = true;
    else
        force_ = std::nullopt;
    int folder_id_ = Int::read(reader);
    std::vector<TLObject> order_ = Vector<TLObject>::read(reader);
    return ReorderPinnedDialogs<X>(folder_id_, order_, force_);
}

template <class X>
std::string ReorderPinnedDialogs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= force ? 1 << 0 : 0;
    buffer += Int::write(folder_id);
    buffer += Vector<TLObject>::write(order);
    return buffer;
}

template <class X>
GetPinnedDialogs<X>::GetPinnedDialogs(int folder_id_) {}

template <class X>
GetPinnedDialogs<X> GetPinnedDialogs<X>::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return GetPinnedDialogs<X>(folder_id_);
}

template <class X>
std::string GetPinnedDialogs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}

template <class X>
SetBotShippingResults<X>::SetBotShippingResults(long query_id_, std::optional<std::string> error_, std::optional<std::vector<TLObject>> shipping_options_) {}

template <class X>
SetBotShippingResults<X> SetBotShippingResults<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    std::optional<std::string> error_;

    if (1 << 0)
        error_ = String::read(reader);
    else
        error_ = std::nullopt;
    std::optional<std::vector<TLObject>> shipping_options_;

    if (1 << 1)
        shipping_options_ = Vector<TLObject>::read(reader);
    else
        shipping_options_ = std::nullopt;
    return SetBotShippingResults<X>(query_id_, error_, shipping_options_);
}

template <class X>
std::string SetBotShippingResults<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= error ? 1 << 0 : 0;
    flags |= shipping_options ? 1 << 1 : 0;
    buffer += Long::write(query_id);

    if (error)
        buffer += String::write(error.value());

    if (shipping_options)
        buffer += Vector<TLObject>::write(shipping_options.value());
    return buffer;
}

template <class X>
SetBotPrecheckoutResults<X>::SetBotPrecheckoutResults(long query_id_, std::optional<bool> success_, std::optional<std::string> error_) {}

template <class X>
SetBotPrecheckoutResults<X> SetBotPrecheckoutResults<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> success_;

    if (1 << 1)
        success_ = true;
    else
        success_ = std::nullopt;
    long query_id_ = Long::read(reader);
    std::optional<std::string> error_;

    if (1 << 0)
        error_ = String::read(reader);
    else
        error_ = std::nullopt;
    return SetBotPrecheckoutResults<X>(query_id_, success_, error_);
}

template <class X>
std::string SetBotPrecheckoutResults<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= success ? 1 << 1 : 0;
    flags |= error ? 1 << 0 : 0;
    buffer += Long::write(query_id);

    if (error)
        buffer += String::write(error.value());
    return buffer;
}

template <class X>
UploadMedia<X>::UploadMedia(TLObject peer_, TLObject media_) {}

template <class X>
UploadMedia<X> UploadMedia<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject media_ = TLObject::read(reader);
    return UploadMedia<X>(peer_, media_);
}

template <class X>
std::string UploadMedia<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += media.write();
    return buffer;
}

template <class X>
SendScreenshotNotification<X>::SendScreenshotNotification(TLObject peer_, int reply_to_msg_id_, long random_id_) {}

template <class X>
SendScreenshotNotification<X> SendScreenshotNotification<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int reply_to_msg_id_ = Int::read(reader);
    long random_id_ = Long::read(reader);
    return SendScreenshotNotification<X>(peer_, reply_to_msg_id_, random_id_);
}

template <class X>
std::string SendScreenshotNotification<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(reply_to_msg_id);
    buffer += Long::write(random_id);
    return buffer;
}

template <class X>
GetFavedStickers<X>::GetFavedStickers(int hash_) {}

template <class X>
GetFavedStickers<X> GetFavedStickers<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetFavedStickers<X>(hash_);
}

template <class X>
std::string GetFavedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
FaveSticker<X>::FaveSticker(TLObject id_, bool unfave_) {}

template <class X>
FaveSticker<X> FaveSticker<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    bool unfave_ = Bool::read(reader);
    return FaveSticker<X>(id_, unfave_);
}

template <class X>
std::string FaveSticker<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Bool::write(unfave);
    return buffer;
}

template <class X>
GetUnreadMentions<X>::GetUnreadMentions(TLObject peer_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_) {}

template <class X>
GetUnreadMentions<X> GetUnreadMentions<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int offset_id_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    return GetUnreadMentions<X>(peer_, offset_id_, add_offset_, limit_, max_id_, min_id_);
}

template <class X>
std::string GetUnreadMentions<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(offset_id);
    buffer += Int::write(add_offset);
    buffer += Int::write(limit);
    buffer += Int::write(max_id);
    buffer += Int::write(min_id);
    return buffer;
}

template <class X>
ReadMentions<X>::ReadMentions(TLObject peer_) {}

template <class X>
ReadMentions<X> ReadMentions<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return ReadMentions<X>(peer_);
}

template <class X>
std::string ReadMentions<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
GetRecentLocations<X>::GetRecentLocations(TLObject peer_, int limit_, int hash_) {}

template <class X>
GetRecentLocations<X> GetRecentLocations<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetRecentLocations<X>(peer_, limit_, hash_);
}

template <class X>
std::string GetRecentLocations<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
SendMultiMedia<X>::SendMultiMedia(TLObject peer_, std::vector<TLObject> multi_media_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<int> schedule_date_) {}

template <class X>
SendMultiMedia<X> SendMultiMedia<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 5)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> background_;

    if (1 << 6)
        background_ = true;
    else
        background_ = std::nullopt;
    std::optional<bool> clear_draft_;

    if (1 << 7)
        clear_draft_ = true;
    else
        clear_draft_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::optional<int> reply_to_msg_id_;

    if (1 << 0)
        reply_to_msg_id_ = Int::read(reader);
    else
        reply_to_msg_id_ = std::nullopt;
    std::vector<TLObject> multi_media_ = Vector<TLObject>::read(reader);
    std::optional<int> schedule_date_;

    if (1 << 10)
        schedule_date_ = Int::read(reader);
    else
        schedule_date_ = std::nullopt;
    return SendMultiMedia<X>(peer_, multi_media_, silent_, background_, clear_draft_, reply_to_msg_id_, schedule_date_);
}

template <class X>
std::string SendMultiMedia<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 5 : 0;
    flags |= background ? 1 << 6 : 0;
    flags |= clear_draft ? 1 << 7 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= schedule_date ? 1 << 10 : 0;
    buffer += peer.write();

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += Vector<TLObject>::write(multi_media);

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    return buffer;
}

template <class X>
UploadEncryptedFile<X>::UploadEncryptedFile(TLObject peer_, TLObject file_) {}

template <class X>
UploadEncryptedFile<X> UploadEncryptedFile<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject file_ = TLObject::read(reader);
    return UploadEncryptedFile<X>(peer_, file_);
}

template <class X>
std::string UploadEncryptedFile<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += file.write();
    return buffer;
}

template <class X>
SearchStickerSets<X>::SearchStickerSets(std::string q_, int hash_, std::optional<bool> exclude_featured_) {}

template <class X>
SearchStickerSets<X> SearchStickerSets<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> exclude_featured_;

    if (1 << 0)
        exclude_featured_ = true;
    else
        exclude_featured_ = std::nullopt;
    std::string q_ = String::read(reader);
    int hash_ = Int::read(reader);
    return SearchStickerSets<X>(q_, hash_, exclude_featured_);
}

template <class X>
std::string SearchStickerSets<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= exclude_featured ? 1 << 0 : 0;
    buffer += String::write(q);
    buffer += Int::write(hash);
    return buffer;
}
template <class X>
GetSplitRanges<X> GetSplitRanges<X>::read(Reader reader)
{
    return GetSplitRanges<X>();
}

template <class X>
std::string GetSplitRanges<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
MarkDialogUnread<X>::MarkDialogUnread(TLObject peer_, std::optional<bool> unread_) {}

template <class X>
MarkDialogUnread<X> MarkDialogUnread<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> unread_;

    if (1 << 0)
        unread_ = true;
    else
        unread_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    return MarkDialogUnread<X>(peer_, unread_);
}

template <class X>
std::string MarkDialogUnread<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= unread ? 1 << 0 : 0;
    buffer += peer.write();
    return buffer;
}
template <class X>
GetDialogUnreadMarks<X> GetDialogUnreadMarks<X>::read(Reader reader)
{
    return GetDialogUnreadMarks<X>();
}

template <class X>
std::string GetDialogUnreadMarks<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
ClearAllDrafts<X> ClearAllDrafts<X>::read(Reader reader)
{
    return ClearAllDrafts<X>();
}

template <class X>
std::string ClearAllDrafts<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
UpdatePinnedMessage<X>::UpdatePinnedMessage(TLObject peer_, int id_, std::optional<bool> silent_, std::optional<bool> unpin_, std::optional<bool> pm_oneside_) {}

template <class X>
UpdatePinnedMessage<X> UpdatePinnedMessage<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;

    if (1 << 0)
        silent_ = true;
    else
        silent_ = std::nullopt;
    std::optional<bool> unpin_;

    if (1 << 1)
        unpin_ = true;
    else
        unpin_ = std::nullopt;
    std::optional<bool> pm_oneside_;

    if (1 << 2)
        pm_oneside_ = true;
    else
        pm_oneside_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    return UpdatePinnedMessage<X>(peer_, id_, silent_, unpin_, pm_oneside_);
}

template <class X>
std::string UpdatePinnedMessage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= silent ? 1 << 0 : 0;
    flags |= unpin ? 1 << 1 : 0;
    flags |= pm_oneside ? 1 << 2 : 0;
    buffer += peer.write();
    buffer += Int::write(id);
    return buffer;
}

template <class X>
SendVote<X>::SendVote(TLObject peer_, int msg_id_, std::vector<std::string> options_) {}

template <class X>
SendVote<X> SendVote<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    std::vector<std::string> options_ = Vector<std::string>::read(reader);
    return SendVote<X>(peer_, msg_id_, options_);
}

template <class X>
std::string SendVote<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Vector<std::string>::write(options);
    return buffer;
}

template <class X>
GetPollResults<X>::GetPollResults(TLObject peer_, int msg_id_) {}

template <class X>
GetPollResults<X> GetPollResults<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    return GetPollResults<X>(peer_, msg_id_);
}

template <class X>
std::string GetPollResults<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

template <class X>
GetOnlines<X>::GetOnlines(TLObject peer_) {}

template <class X>
GetOnlines<X> GetOnlines<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return GetOnlines<X>(peer_);
}

template <class X>
std::string GetOnlines<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
GetStatsURL<X>::GetStatsURL(TLObject peer_, std::string params_, std::optional<bool> dark_) {}

template <class X>
GetStatsURL<X> GetStatsURL<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;

    if (1 << 0)
        dark_ = true;
    else
        dark_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::string params_ = String::read(reader);
    return GetStatsURL<X>(peer_, params_, dark_);
}

template <class X>
std::string GetStatsURL<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += String::write(params);
    return buffer;
}

template <class X>
EditChatAbout<X>::EditChatAbout(TLObject peer_, std::string about_) {}

template <class X>
EditChatAbout<X> EditChatAbout<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string about_ = String::read(reader);
    return EditChatAbout<X>(peer_, about_);
}

template <class X>
std::string EditChatAbout<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(about);
    return buffer;
}

template <class X>
EditChatDefaultBannedRights<X>::EditChatDefaultBannedRights(TLObject peer_, TLObject banned_rights_) {}

template <class X>
EditChatDefaultBannedRights<X> EditChatDefaultBannedRights<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject banned_rights_ = TLObject::read(reader);
    return EditChatDefaultBannedRights<X>(peer_, banned_rights_);
}

template <class X>
std::string EditChatDefaultBannedRights<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += banned_rights.write();
    return buffer;
}

template <class X>
GetEmojiKeywords<X>::GetEmojiKeywords(std::string lang_code_) {}

template <class X>
GetEmojiKeywords<X> GetEmojiKeywords<X>::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return GetEmojiKeywords<X>(lang_code_);
}

template <class X>
std::string GetEmojiKeywords<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

template <class X>
GetEmojiKeywordsDifference<X>::GetEmojiKeywordsDifference(std::string lang_code_, int from_version_) {}

template <class X>
GetEmojiKeywordsDifference<X> GetEmojiKeywordsDifference<X>::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    return GetEmojiKeywordsDifference<X>(lang_code_, from_version_);
}

template <class X>
std::string GetEmojiKeywordsDifference<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    return buffer;
}

template <class X>
GetEmojiKeywordsLanguages<X>::GetEmojiKeywordsLanguages(std::vector<std::string> lang_codes_) {}

template <class X>
GetEmojiKeywordsLanguages<X> GetEmojiKeywordsLanguages<X>::read(Reader reader)
{
    std::vector<std::string> lang_codes_ = Vector<std::string>::read(reader);
    return GetEmojiKeywordsLanguages<X>(lang_codes_);
}

template <class X>
std::string GetEmojiKeywordsLanguages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<std::string>::write(lang_codes);
    return buffer;
}

template <class X>
GetEmojiURL<X>::GetEmojiURL(std::string lang_code_) {}

template <class X>
GetEmojiURL<X> GetEmojiURL<X>::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return GetEmojiURL<X>(lang_code_);
}

template <class X>
std::string GetEmojiURL<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

template <class X>
GetSearchCounters<X>::GetSearchCounters(TLObject peer_, std::vector<TLObject> filters_) {}

template <class X>
GetSearchCounters<X> GetSearchCounters<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<TLObject> filters_ = Vector<TLObject>::read(reader);
    return GetSearchCounters<X>(peer_, filters_);
}

template <class X>
std::string GetSearchCounters<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<TLObject>::write(filters);
    return buffer;
}

template <class X>
RequestUrlAuth<X>::RequestUrlAuth(std::optional<TLObject> peer_, std::optional<int> msg_id_, std::optional<int> button_id_, std::optional<std::string> url_) {}

template <class X>
RequestUrlAuth<X> RequestUrlAuth<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> peer_;

    if (1 << 1)
        peer_ = TLObject::read(reader);
    else
        peer_ = std::nullopt;
    std::optional<int> msg_id_;

    if (1 << 1)
        msg_id_ = Int::read(reader);
    else
        msg_id_ = std::nullopt;
    std::optional<int> button_id_;

    if (1 << 1)
        button_id_ = Int::read(reader);
    else
        button_id_ = std::nullopt;
    std::optional<std::string> url_;

    if (1 << 2)
        url_ = String::read(reader);
    else
        url_ = std::nullopt;
    return RequestUrlAuth<X>(peer_, msg_id_, button_id_, url_);
}

template <class X>
std::string RequestUrlAuth<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= peer ? 1 << 1 : 0;
    flags |= msg_id ? 1 << 1 : 0;
    flags |= button_id ? 1 << 1 : 0;
    flags |= url ? 1 << 2 : 0;

    if (peer)
        buffer += peer.value().write();

    if (msg_id)
        buffer += Int::write(msg_id.value());

    if (button_id)
        buffer += Int::write(button_id.value());

    if (url)
        buffer += String::write(url.value());
    return buffer;
}

template <class X>
AcceptUrlAuth<X>::AcceptUrlAuth(std::optional<bool> write_allowed_, std::optional<TLObject> peer_, std::optional<int> msg_id_, std::optional<int> button_id_, std::optional<std::string> url_) {}

template <class X>
AcceptUrlAuth<X> AcceptUrlAuth<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> write_allowed_;

    if (1 << 0)
        write_allowed_ = true;
    else
        write_allowed_ = std::nullopt;
    std::optional<TLObject> peer_;

    if (1 << 1)
        peer_ = TLObject::read(reader);
    else
        peer_ = std::nullopt;
    std::optional<int> msg_id_;

    if (1 << 1)
        msg_id_ = Int::read(reader);
    else
        msg_id_ = std::nullopt;
    std::optional<int> button_id_;

    if (1 << 1)
        button_id_ = Int::read(reader);
    else
        button_id_ = std::nullopt;
    std::optional<std::string> url_;

    if (1 << 2)
        url_ = String::read(reader);
    else
        url_ = std::nullopt;
    return AcceptUrlAuth<X>(write_allowed_, peer_, msg_id_, button_id_, url_);
}

template <class X>
std::string AcceptUrlAuth<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= write_allowed ? 1 << 0 : 0;
    flags |= peer ? 1 << 1 : 0;
    flags |= msg_id ? 1 << 1 : 0;
    flags |= button_id ? 1 << 1 : 0;
    flags |= url ? 1 << 2 : 0;

    if (peer)
        buffer += peer.value().write();

    if (msg_id)
        buffer += Int::write(msg_id.value());

    if (button_id)
        buffer += Int::write(button_id.value());

    if (url)
        buffer += String::write(url.value());
    return buffer;
}

template <class X>
HidePeerSettingsBar<X>::HidePeerSettingsBar(TLObject peer_) {}

template <class X>
HidePeerSettingsBar<X> HidePeerSettingsBar<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return HidePeerSettingsBar<X>(peer_);
}

template <class X>
std::string HidePeerSettingsBar<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
GetScheduledHistory<X>::GetScheduledHistory(TLObject peer_, int hash_) {}

template <class X>
GetScheduledHistory<X> GetScheduledHistory<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int hash_ = Int::read(reader);
    return GetScheduledHistory<X>(peer_, hash_);
}

template <class X>
std::string GetScheduledHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetScheduledMessages<X>::GetScheduledMessages(TLObject peer_, std::vector<int> id_) {}

template <class X>
GetScheduledMessages<X> GetScheduledMessages<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return GetScheduledMessages<X>(peer_, id_);
}

template <class X>
std::string GetScheduledMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
SendScheduledMessages<X>::SendScheduledMessages(TLObject peer_, std::vector<int> id_) {}

template <class X>
SendScheduledMessages<X> SendScheduledMessages<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return SendScheduledMessages<X>(peer_, id_);
}

template <class X>
std::string SendScheduledMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
DeleteScheduledMessages<X>::DeleteScheduledMessages(TLObject peer_, std::vector<int> id_) {}

template <class X>
DeleteScheduledMessages<X> DeleteScheduledMessages<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<int> id_ = Vector<int>::read(reader);
    return DeleteScheduledMessages<X>(peer_, id_);
}

template <class X>
std::string DeleteScheduledMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

template <class X>
GetPollVotes<X>::GetPollVotes(TLObject peer_, int id_, int limit_, std::optional<std::string> option_, std::optional<std::string> offset_) {}

template <class X>
GetPollVotes<X> GetPollVotes<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    int id_ = Int::read(reader);
    std::optional<std::string> option_;

    if (1 << 0)
        option_ = Bytes::read(reader);
    else
        option_ = std::nullopt;
    std::optional<std::string> offset_;

    if (1 << 1)
        offset_ = String::read(reader);
    else
        offset_ = std::nullopt;
    int limit_ = Int::read(reader);
    return GetPollVotes<X>(peer_, id_, limit_, option_, offset_);
}

template <class X>
std::string GetPollVotes<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= option ? 1 << 0 : 0;
    flags |= offset ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += Int::write(id);

    if (option)
        buffer += Bytes::write(option.value());

    if (offset)
        buffer += String::write(offset.value());
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
ToggleStickerSets<X>::ToggleStickerSets(std::vector<TLObject> stickersets_, std::optional<bool> uninstall_, std::optional<bool> archive_, std::optional<bool> unarchive_) {}

template <class X>
ToggleStickerSets<X> ToggleStickerSets<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> uninstall_;

    if (1 << 0)
        uninstall_ = true;
    else
        uninstall_ = std::nullopt;
    std::optional<bool> archive_;

    if (1 << 1)
        archive_ = true;
    else
        archive_ = std::nullopt;
    std::optional<bool> unarchive_;

    if (1 << 2)
        unarchive_ = true;
    else
        unarchive_ = std::nullopt;
    std::vector<TLObject> stickersets_ = Vector<TLObject>::read(reader);
    return ToggleStickerSets<X>(stickersets_, uninstall_, archive_, unarchive_);
}

template <class X>
std::string ToggleStickerSets<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= uninstall ? 1 << 0 : 0;
    flags |= archive ? 1 << 1 : 0;
    flags |= unarchive ? 1 << 2 : 0;
    buffer += Vector<TLObject>::write(stickersets);
    return buffer;
}
template <class X>
GetDialogFilters<X> GetDialogFilters<X>::read(Reader reader)
{
    return GetDialogFilters<X>();
}

template <class X>
std::string GetDialogFilters<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetSuggestedDialogFilters<X> GetSuggestedDialogFilters<X>::read(Reader reader)
{
    return GetSuggestedDialogFilters<X>();
}

template <class X>
std::string GetSuggestedDialogFilters<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
UpdateDialogFilter<X>::UpdateDialogFilter(int id_, std::optional<TLObject> filter_) {}

template <class X>
UpdateDialogFilter<X> UpdateDialogFilter<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    int id_ = Int::read(reader);
    std::optional<TLObject> filter_;

    if (1 << 0)
        filter_ = TLObject::read(reader);
    else
        filter_ = std::nullopt;
    return UpdateDialogFilter<X>(id_, filter_);
}

template <class X>
std::string UpdateDialogFilter<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= filter ? 1 << 0 : 0;
    buffer += Int::write(id);

    if (filter)
        buffer += filter.value().write();
    return buffer;
}

template <class X>
UpdateDialogFiltersOrder<X>::UpdateDialogFiltersOrder(std::vector<int> order_) {}

template <class X>
UpdateDialogFiltersOrder<X> UpdateDialogFiltersOrder<X>::read(Reader reader)
{
    std::vector<int> order_ = Vector<int>::read(reader);
    return UpdateDialogFiltersOrder<X>(order_);
}

template <class X>
std::string UpdateDialogFiltersOrder<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(order);
    return buffer;
}

template <class X>
GetOldFeaturedStickers<X>::GetOldFeaturedStickers(int offset_, int limit_, int hash_) {}

template <class X>
GetOldFeaturedStickers<X> GetOldFeaturedStickers<X>::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetOldFeaturedStickers<X>(offset_, limit_, hash_);
}

template <class X>
std::string GetOldFeaturedStickers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetReplies<X>::GetReplies(TLObject peer_, int msg_id_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_) {}

template <class X>
GetReplies<X> GetReplies<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    int offset_date_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetReplies<X>(peer_, msg_id_, offset_id_, offset_date_, add_offset_, limit_, max_id_, min_id_, hash_);
}

template <class X>
std::string GetReplies<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(offset_id);
    buffer += Int::write(offset_date);
    buffer += Int::write(add_offset);
    buffer += Int::write(limit);
    buffer += Int::write(max_id);
    buffer += Int::write(min_id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
GetDiscussionMessage<X>::GetDiscussionMessage(TLObject peer_, int msg_id_) {}

template <class X>
GetDiscussionMessage<X> GetDiscussionMessage<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    return GetDiscussionMessage<X>(peer_, msg_id_);
}

template <class X>
std::string GetDiscussionMessage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

template <class X>
ReadDiscussion<X>::ReadDiscussion(TLObject peer_, int msg_id_, int read_max_id_) {}

template <class X>
ReadDiscussion<X> ReadDiscussion<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    int read_max_id_ = Int::read(reader);
    return ReadDiscussion<X>(peer_, msg_id_, read_max_id_);
}

template <class X>
std::string ReadDiscussion<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(read_max_id);
    return buffer;
}

template <class X>
UnpinAllMessages<X>::UnpinAllMessages(TLObject peer_) {}

template <class X>
UnpinAllMessages<X> UnpinAllMessages<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return UnpinAllMessages<X>(peer_);
}

template <class X>
std::string UnpinAllMessages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
DeleteChat<X>::DeleteChat(int chat_id_) {}

template <class X>
DeleteChat<X> DeleteChat<X>::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return DeleteChat<X>(chat_id_);
}

template <class X>
std::string DeleteChat<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

template <class X>
DeletePhoneCallHistory<X>::DeletePhoneCallHistory(std::optional<bool> revoke_) {}

template <class X>
DeletePhoneCallHistory<X> DeletePhoneCallHistory<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_;

    if (1 << 0)
        revoke_ = true;
    else
        revoke_ = std::nullopt;
    return DeletePhoneCallHistory<X>(revoke_);
}

template <class X>
std::string DeletePhoneCallHistory<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke ? 1 << 0 : 0;
    return buffer;
}

template <class X>
CheckHistoryImport<X>::CheckHistoryImport(std::string import_head_) {}

template <class X>
CheckHistoryImport<X> CheckHistoryImport<X>::read(Reader reader)
{
    std::string import_head_ = String::read(reader);
    return CheckHistoryImport<X>(import_head_);
}

template <class X>
std::string CheckHistoryImport<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(import_head);
    return buffer;
}

template <class X>
InitHistoryImport<X>::InitHistoryImport(TLObject peer_, TLObject file_, int media_count_) {}

template <class X>
InitHistoryImport<X> InitHistoryImport<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject file_ = TLObject::read(reader);
    int media_count_ = Int::read(reader);
    return InitHistoryImport<X>(peer_, file_, media_count_);
}

template <class X>
std::string InitHistoryImport<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += file.write();
    buffer += Int::write(media_count);
    return buffer;
}

template <class X>
UploadImportedMedia<X>::UploadImportedMedia(TLObject peer_, long import_id_, std::string file_name_, TLObject media_) {}

template <class X>
UploadImportedMedia<X> UploadImportedMedia<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    long import_id_ = Long::read(reader);
    std::string file_name_ = String::read(reader);
    TLObject media_ = TLObject::read(reader);
    return UploadImportedMedia<X>(peer_, import_id_, file_name_, media_);
}

template <class X>
std::string UploadImportedMedia<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(import_id);
    buffer += String::write(file_name);
    buffer += media.write();
    return buffer;
}

template <class X>
StartHistoryImport<X>::StartHistoryImport(TLObject peer_, long import_id_) {}

template <class X>
StartHistoryImport<X> StartHistoryImport<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    long import_id_ = Long::read(reader);
    return StartHistoryImport<X>(peer_, import_id_);
}

template <class X>
std::string StartHistoryImport<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(import_id);
    return buffer;
}

template <class X>
GetExportedChatInvites<X>::GetExportedChatInvites(TLObject peer_, TLObject admin_id_, int limit_, std::optional<bool> revoked_, std::optional<int> offset_date_, std::optional<std::string> offset_link_) {}

template <class X>
GetExportedChatInvites<X> GetExportedChatInvites<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoked_;

    if (1 << 3)
        revoked_ = true;
    else
        revoked_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    TLObject admin_id_ = TLObject::read(reader);
    std::optional<int> offset_date_;

    if (1 << 2)
        offset_date_ = Int::read(reader);
    else
        offset_date_ = std::nullopt;
    std::optional<std::string> offset_link_;

    if (1 << 2)
        offset_link_ = String::read(reader);
    else
        offset_link_ = std::nullopt;
    int limit_ = Int::read(reader);
    return GetExportedChatInvites<X>(peer_, admin_id_, limit_, revoked_, offset_date_, offset_link_);
}

template <class X>
std::string GetExportedChatInvites<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoked ? 1 << 3 : 0;
    flags |= offset_date ? 1 << 2 : 0;
    flags |= offset_link ? 1 << 2 : 0;
    buffer += peer.write();
    buffer += admin_id.write();

    if (offset_date)
        buffer += Int::write(offset_date.value());

    if (offset_link)
        buffer += String::write(offset_link.value());
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
GetExportedChatInvite<X>::GetExportedChatInvite(TLObject peer_, std::string link_) {}

template <class X>
GetExportedChatInvite<X> GetExportedChatInvite<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string link_ = String::read(reader);
    return GetExportedChatInvite<X>(peer_, link_);
}

template <class X>
std::string GetExportedChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(link);
    return buffer;
}

template <class X>
EditExportedChatInvite<X>::EditExportedChatInvite(TLObject peer_, std::string link_, std::optional<bool> revoked_, std::optional<int> expire_date_, std::optional<int> usage_limit_) {}

template <class X>
EditExportedChatInvite<X> EditExportedChatInvite<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoked_;

    if (1 << 2)
        revoked_ = true;
    else
        revoked_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    std::string link_ = String::read(reader);
    std::optional<int> expire_date_;

    if (1 << 0)
        expire_date_ = Int::read(reader);
    else
        expire_date_ = std::nullopt;
    std::optional<int> usage_limit_;

    if (1 << 1)
        usage_limit_ = Int::read(reader);
    else
        usage_limit_ = std::nullopt;
    return EditExportedChatInvite<X>(peer_, link_, revoked_, expire_date_, usage_limit_);
}

template <class X>
std::string EditExportedChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoked ? 1 << 2 : 0;
    flags |= expire_date ? 1 << 0 : 0;
    flags |= usage_limit ? 1 << 1 : 0;
    buffer += peer.write();
    buffer += String::write(link);

    if (expire_date)
        buffer += Int::write(expire_date.value());

    if (usage_limit)
        buffer += Int::write(usage_limit.value());
    return buffer;
}

template <class X>
DeleteRevokedExportedChatInvites<X>::DeleteRevokedExportedChatInvites(TLObject peer_, TLObject admin_id_) {}

template <class X>
DeleteRevokedExportedChatInvites<X> DeleteRevokedExportedChatInvites<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    TLObject admin_id_ = TLObject::read(reader);
    return DeleteRevokedExportedChatInvites<X>(peer_, admin_id_);
}

template <class X>
std::string DeleteRevokedExportedChatInvites<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += admin_id.write();
    return buffer;
}

template <class X>
DeleteExportedChatInvite<X>::DeleteExportedChatInvite(TLObject peer_, std::string link_) {}

template <class X>
DeleteExportedChatInvite<X> DeleteExportedChatInvite<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string link_ = String::read(reader);
    return DeleteExportedChatInvite<X>(peer_, link_);
}

template <class X>
std::string DeleteExportedChatInvite<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(link);
    return buffer;
}

template <class X>
GetAdminsWithInvites<X>::GetAdminsWithInvites(TLObject peer_) {}

template <class X>
GetAdminsWithInvites<X> GetAdminsWithInvites<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return GetAdminsWithInvites<X>(peer_);
}

template <class X>
std::string GetAdminsWithInvites<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

template <class X>
GetChatInviteImporters<X>::GetChatInviteImporters(TLObject peer_, std::string link_, int offset_date_, TLObject offset_user_, int limit_) {}

template <class X>
GetChatInviteImporters<X> GetChatInviteImporters<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::string link_ = String::read(reader);
    int offset_date_ = Int::read(reader);
    TLObject offset_user_ = TLObject::read(reader);
    int limit_ = Int::read(reader);
    return GetChatInviteImporters<X>(peer_, link_, offset_date_, offset_user_, limit_);
}

template <class X>
std::string GetChatInviteImporters<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(link);
    buffer += Int::write(offset_date);
    buffer += offset_user.write();
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
SetHistoryTTL<X>::SetHistoryTTL(TLObject peer_, int period_) {}

template <class X>
SetHistoryTTL<X> SetHistoryTTL<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int period_ = Int::read(reader);
    return SetHistoryTTL<X>(peer_, period_);
}

template <class X>
std::string SetHistoryTTL<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(period);
    return buffer;
}

template <class X>
CheckHistoryImportPeer<X>::CheckHistoryImportPeer(TLObject peer_) {}

template <class X>
CheckHistoryImportPeer<X> CheckHistoryImportPeer<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    return CheckHistoryImportPeer<X>(peer_);
}

template <class X>
std::string CheckHistoryImportPeer<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
