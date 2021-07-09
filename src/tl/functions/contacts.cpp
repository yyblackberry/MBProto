#include "tl/functions/contacts.h"

template <class X>
GetContactIDs<X>::GetContactIDs(int hash_) {}

template <class X>
GetContactIDs<X> GetContactIDs<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetContactIDs<X>(hash_);
}

template <class X>
std::string GetContactIDs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}
template <class X>
GetStatuses<X> GetStatuses<X>::read(Reader reader)
{
    return GetStatuses<X>();
}

template <class X>
std::string GetStatuses<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetContacts<X>::GetContacts(int hash_) {}

template <class X>
GetContacts<X> GetContacts<X>::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetContacts<X>(hash_);
}

template <class X>
std::string GetContacts<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ImportContacts<X>::ImportContacts(std::vector<TLObject> contacts_) {}

template <class X>
ImportContacts<X> ImportContacts<X>::read(Reader reader)
{
    std::vector<TLObject> contacts_ = Vector<TLObject>::read(reader);
    return ImportContacts<X>(contacts_);
}

template <class X>
std::string ImportContacts<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(contacts);
    return buffer;
}

template <class X>
DeleteContacts<X>::DeleteContacts(std::vector<TLObject> id_) {}

template <class X>
DeleteContacts<X> DeleteContacts<X>::read(Reader reader)
{
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return DeleteContacts<X>(id_);
}

template <class X>
std::string DeleteContacts<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
DeleteByPhones<X>::DeleteByPhones(std::vector<std::string> phones_) {}

template <class X>
DeleteByPhones<X> DeleteByPhones<X>::read(Reader reader)
{
    std::vector<std::string> phones_ = Vector<std::string>::read(reader);
    return DeleteByPhones<X>(phones_);
}

template <class X>
std::string DeleteByPhones<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<std::string>::write(phones);
    return buffer;
}

template <class X>
Block<X>::Block(TLObject id_) {}

template <class X>
Block<X> Block<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return Block<X>(id_);
}

template <class X>
std::string Block<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
Unblock<X>::Unblock(TLObject id_) {}

template <class X>
Unblock<X> Unblock<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return Unblock<X>(id_);
}

template <class X>
std::string Unblock<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
GetBlocked<X>::GetBlocked(int offset_, int limit_) {}

template <class X>
GetBlocked<X> GetBlocked<X>::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetBlocked<X>(offset_, limit_);
}

template <class X>
std::string GetBlocked<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
Search<X>::Search(std::string q_, int limit_) {}

template <class X>
Search<X> Search<X>::read(Reader reader)
{
    std::string q_ = String::read(reader);
    int limit_ = Int::read(reader);
    return Search<X>(q_, limit_);
}

template <class X>
std::string Search<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
ResolveUsername<X>::ResolveUsername(std::string username_) {}

template <class X>
ResolveUsername<X> ResolveUsername<X>::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return ResolveUsername<X>(username_);
}

template <class X>
std::string ResolveUsername<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

template <class X>
GetTopPeers<X>::GetTopPeers(int offset_, int limit_, int hash_, std::optional<bool> correspondents_, std::optional<bool> bots_pm_, std::optional<bool> bots_inline_, std::optional<bool> phone_calls_, std::optional<bool> forward_users_, std::optional<bool> forward_chats_, std::optional<bool> groups_, std::optional<bool> channels_) {}

template <class X>
GetTopPeers<X> GetTopPeers<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> correspondents_;

    if (1 << 0)
        correspondents_ = true;
    else
        correspondents_ = std::nullopt;
    std::optional<bool> bots_pm_;

    if (1 << 1)
        bots_pm_ = true;
    else
        bots_pm_ = std::nullopt;
    std::optional<bool> bots_inline_;

    if (1 << 2)
        bots_inline_ = true;
    else
        bots_inline_ = std::nullopt;
    std::optional<bool> phone_calls_;

    if (1 << 3)
        phone_calls_ = true;
    else
        phone_calls_ = std::nullopt;
    std::optional<bool> forward_users_;

    if (1 << 4)
        forward_users_ = true;
    else
        forward_users_ = std::nullopt;
    std::optional<bool> forward_chats_;

    if (1 << 5)
        forward_chats_ = true;
    else
        forward_chats_ = std::nullopt;
    std::optional<bool> groups_;

    if (1 << 10)
        groups_ = true;
    else
        groups_ = std::nullopt;
    std::optional<bool> channels_;

    if (1 << 15)
        channels_ = true;
    else
        channels_ = std::nullopt;
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetTopPeers<X>(offset_, limit_, hash_, correspondents_, bots_pm_, bots_inline_, phone_calls_, forward_users_, forward_chats_, groups_, channels_);
}

template <class X>
std::string GetTopPeers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= correspondents ? 1 << 0 : 0;
    flags |= bots_pm ? 1 << 1 : 0;
    flags |= bots_inline ? 1 << 2 : 0;
    flags |= phone_calls ? 1 << 3 : 0;
    flags |= forward_users ? 1 << 4 : 0;
    flags |= forward_chats ? 1 << 5 : 0;
    flags |= groups ? 1 << 10 : 0;
    flags |= channels ? 1 << 15 : 0;
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

template <class X>
ResetTopPeerRating<X>::ResetTopPeerRating(TLObject category_, TLObject peer_) {}

template <class X>
ResetTopPeerRating<X> ResetTopPeerRating<X>::read(Reader reader)
{
    TLObject category_ = TLObject::read(reader);
    TLObject peer_ = TLObject::read(reader);
    return ResetTopPeerRating<X>(category_, peer_);
}

template <class X>
std::string ResetTopPeerRating<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += category.write();
    buffer += peer.write();
    return buffer;
}
template <class X>
ResetSaved<X> ResetSaved<X>::read(Reader reader)
{
    return ResetSaved<X>();
}

template <class X>
std::string ResetSaved<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
template <class X>
GetSaved<X> GetSaved<X>::read(Reader reader)
{
    return GetSaved<X>();
}

template <class X>
std::string GetSaved<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ToggleTopPeers<X>::ToggleTopPeers(bool enabled_) {}

template <class X>
ToggleTopPeers<X> ToggleTopPeers<X>::read(Reader reader)
{
    bool enabled_ = Bool::read(reader);
    return ToggleTopPeers<X>(enabled_);
}

template <class X>
std::string ToggleTopPeers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(enabled);
    return buffer;
}

template <class X>
AddContact<X>::AddContact(TLObject id_, std::string first_name_, std::string last_name_, std::string phone_, std::optional<bool> add_phone_privacy_exception_) {}

template <class X>
AddContact<X> AddContact<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> add_phone_privacy_exception_;

    if (1 << 0)
        add_phone_privacy_exception_ = true;
    else
        add_phone_privacy_exception_ = std::nullopt;
    TLObject id_ = TLObject::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string phone_ = String::read(reader);
    return AddContact<X>(id_, first_name_, last_name_, phone_, add_phone_privacy_exception_);
}

template <class X>
std::string AddContact<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= add_phone_privacy_exception ? 1 << 0 : 0;
    buffer += id.write();
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(phone);
    return buffer;
}

template <class X>
AcceptContact<X>::AcceptContact(TLObject id_) {}

template <class X>
AcceptContact<X> AcceptContact<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return AcceptContact<X>(id_);
}

template <class X>
std::string AcceptContact<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
GetLocated<X>::GetLocated(TLObject geo_point_, std::optional<bool> background_, std::optional<int> self_expires_) {}

template <class X>
GetLocated<X> GetLocated<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> background_;

    if (1 << 1)
        background_ = true;
    else
        background_ = std::nullopt;
    TLObject geo_point_ = TLObject::read(reader);
    std::optional<int> self_expires_;

    if (1 << 0)
        self_expires_ = Int::read(reader);
    else
        self_expires_ = std::nullopt;
    return GetLocated<X>(geo_point_, background_, self_expires_);
}

template <class X>
std::string GetLocated<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= background ? 1 << 1 : 0;
    flags |= self_expires ? 1 << 0 : 0;
    buffer += geo_point.write();

    if (self_expires)
        buffer += Int::write(self_expires.value());
    return buffer;
}

template <class X>
BlockFromReplies<X>::BlockFromReplies(int msg_id_, std::optional<bool> delete_message_, std::optional<bool> delete_history_, std::optional<bool> report_spam_) {}

template <class X>
BlockFromReplies<X> BlockFromReplies<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> delete_message_;

    if (1 << 0)
        delete_message_ = true;
    else
        delete_message_ = std::nullopt;
    std::optional<bool> delete_history_;

    if (1 << 1)
        delete_history_ = true;
    else
        delete_history_ = std::nullopt;
    std::optional<bool> report_spam_;

    if (1 << 2)
        report_spam_ = true;
    else
        report_spam_ = std::nullopt;
    int msg_id_ = Int::read(reader);
    return BlockFromReplies<X>(msg_id_, delete_message_, delete_history_, report_spam_);
}

template <class X>
std::string BlockFromReplies<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= delete_message ? 1 << 0 : 0;
    flags |= delete_history ? 1 << 1 : 0;
    flags |= report_spam ? 1 << 2 : 0;
    buffer += Int::write(msg_id);
    return buffer;
}
