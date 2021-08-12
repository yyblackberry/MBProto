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

#include "tl/functions/contacts.h"

GetContactIDs::GetContactIDs(int hash_) {}

GetContactIDs GetContactIDs::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetContactIDs(hash_);
}

std::string GetContactIDs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}
GetStatuses GetStatuses::read(Reader reader)
{
    return GetStatuses();
}

std::string GetStatuses::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetContacts::GetContacts(int hash_) {}

GetContacts GetContacts::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetContacts(hash_);
}

std::string GetContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

ImportContacts::ImportContacts(std::vector<TLObject> contacts_) {}

ImportContacts ImportContacts::read(Reader reader)
{
    std::vector<TLObject> contacts_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ImportContacts(contacts_);
}

std::string ImportContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(contacts);
    return buffer;
}

DeleteContacts::DeleteContacts(std::vector<TLObject> id_) {}

DeleteContacts DeleteContacts::read(Reader reader)
{
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DeleteContacts(id_);
}

std::string DeleteContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

DeleteByPhones::DeleteByPhones(std::vector<std::string> phones_) {}

DeleteByPhones DeleteByPhones::read(Reader reader)
{
    std::vector<std::string> phones_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return DeleteByPhones(phones_);
}

std::string DeleteByPhones::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<std::string>::write(phones);
    return buffer;
}

Block::Block(TLObject id_) {}

Block Block::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return Block(id_);
}

std::string Block::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

Unblock::Unblock(TLObject id_) {}

Unblock Unblock::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return Unblock(id_);
}

std::string Unblock::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

GetBlocked::GetBlocked(int offset_, int limit_) {}

GetBlocked GetBlocked::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetBlocked(offset_, limit_);
}

std::string GetBlocked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

Search::Search(std::string q_, int limit_) {}

Search Search::read(Reader reader)
{
    std::string q_ = String::read(reader);
    int limit_ = Int::read(reader);
    return Search(q_, limit_);
}

std::string Search::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    buffer += Int::write(limit);
    return buffer;
}

ResolveUsername::ResolveUsername(std::string username_) {}

ResolveUsername ResolveUsername::read(Reader reader)
{
    std::string username_ = String::read(reader);
    return ResolveUsername(username_);
}

std::string ResolveUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(username);
    return buffer;
}

GetTopPeers::GetTopPeers(int offset_, int limit_, int hash_, std::optional<bool> correspondents_, std::optional<bool> bots_pm_, std::optional<bool> bots_inline_, std::optional<bool> phone_calls_, std::optional<bool> forward_users_, std::optional<bool> forward_chats_, std::optional<bool> groups_, std::optional<bool> channels_) {}

GetTopPeers GetTopPeers::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> correspondents_;
    correspondents_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> bots_pm_;
    bots_pm_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> bots_inline_;
    bots_inline_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> phone_calls_;
    phone_calls_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> forward_users_;
    forward_users_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> forward_chats_;
    forward_chats_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> groups_;
    groups_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> channels_;
    channels_ = (1 << 15) ? std::optional{true} : std::nullopt;
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetTopPeers(offset_, limit_, hash_, correspondents_, bots_pm_, bots_inline_, phone_calls_, forward_users_, forward_chats_, groups_, channels_);
}

std::string GetTopPeers::write()
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

ResetTopPeerRating::ResetTopPeerRating(TLObject category_, TLObject peer_) {}

ResetTopPeerRating ResetTopPeerRating::read(Reader reader)
{
    TLObject category_ = std::get<TLObject>(TLObject::read(reader));
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ResetTopPeerRating(category_, peer_);
}

std::string ResetTopPeerRating::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += category.write();
    buffer += peer.write();
    return buffer;
}
ResetSaved ResetSaved::read(Reader reader)
{
    return ResetSaved();
}

std::string ResetSaved::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetSaved GetSaved::read(Reader reader)
{
    return GetSaved();
}

std::string GetSaved::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ToggleTopPeers::ToggleTopPeers(bool enabled_) {}

ToggleTopPeers ToggleTopPeers::read(Reader reader)
{
    bool enabled_ = Bool::read(reader);
    return ToggleTopPeers(enabled_);
}

std::string ToggleTopPeers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(enabled);
    return buffer;
}

AddContact::AddContact(TLObject id_, std::string first_name_, std::string last_name_, std::string phone_, std::optional<bool> add_phone_privacy_exception_) {}

AddContact AddContact::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> add_phone_privacy_exception_;
    add_phone_privacy_exception_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string phone_ = String::read(reader);
    return AddContact(id_, first_name_, last_name_, phone_, add_phone_privacy_exception_);
}

std::string AddContact::write()
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

AcceptContact::AcceptContact(TLObject id_) {}

AcceptContact AcceptContact::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return AcceptContact(id_);
}

std::string AcceptContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

GetLocated::GetLocated(TLObject geo_point_, std::optional<bool> background_, std::optional<int> self_expires_) {}

GetLocated GetLocated::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> background_;
    background_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> self_expires_;
    self_expires_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return GetLocated(geo_point_, background_, self_expires_);
}

std::string GetLocated::write()
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

BlockFromReplies::BlockFromReplies(int msg_id_, std::optional<bool> delete_message_, std::optional<bool> delete_history_, std::optional<bool> report_spam_) {}

BlockFromReplies BlockFromReplies::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> delete_message_;
    delete_message_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> delete_history_;
    delete_history_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> report_spam_;
    report_spam_ = (1 << 2) ? std::optional{true} : std::nullopt;
    int msg_id_ = Int::read(reader);
    return BlockFromReplies(msg_id_, delete_message_, delete_history_, report_spam_);
}

std::string BlockFromReplies::write()
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
