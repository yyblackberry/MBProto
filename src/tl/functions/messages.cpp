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

#include "tl/functions/messages.h"

GetMessages::GetMessages(std::vector<TLObject> id_) {}

GetMessages GetMessages::read(Reader reader)
{
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetMessages(id_);
}

std::string GetMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

GetDialogs::GetDialogs(int offset_date_, int offset_id_, TLObject offset_peer_, int limit_, int hash_, std::optional<bool> exclude_pinned_, std::optional<int> folder_id_) {}

GetDialogs GetDialogs::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> exclude_pinned_;
    exclude_pinned_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<int> folder_id_;
    folder_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    int offset_date_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    TLObject offset_peer_ = std::get<TLObject>(TLObject::read(reader));
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetDialogs(offset_date_, offset_id_, offset_peer_, limit_, hash_, exclude_pinned_, folder_id_);
}

std::string GetDialogs::write()
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

GetHistory::GetHistory(TLObject peer_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_) {}

GetHistory GetHistory::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int offset_id_ = Int::read(reader);
    int offset_date_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetHistory(peer_, offset_id_, offset_date_, add_offset_, limit_, max_id_, min_id_, hash_);
}

std::string GetHistory::write()
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

Search::Search(TLObject peer_, std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_, std::optional<TLObject> from_id_, std::optional<int> top_msg_id_) {}

Search Search::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string q_ = String::read(reader);
    std::optional<TLObject> from_id_;
    from_id_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> top_msg_id_;
    top_msg_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    int min_date_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return Search(peer_, q_, filter_, min_date_, max_date_, offset_id_, add_offset_, limit_, max_id_, min_id_, hash_, from_id_, top_msg_id_);
}

std::string Search::write()
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

ReadHistory::ReadHistory(TLObject peer_, int max_id_) {}

ReadHistory ReadHistory::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    return ReadHistory(peer_, max_id_);
}

std::string ReadHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(max_id);
    return buffer;
}

DeleteHistory::DeleteHistory(TLObject peer_, int max_id_, std::optional<bool> just_clear_, std::optional<bool> revoke_) {}

DeleteHistory DeleteHistory::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> just_clear_;
    just_clear_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> revoke_;
    revoke_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    return DeleteHistory(peer_, max_id_, just_clear_, revoke_);
}

std::string DeleteHistory::write()
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

DeleteMessages::DeleteMessages(std::vector<int> id_, std::optional<bool> revoke_) {}

DeleteMessages DeleteMessages::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_;
    revoke_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return DeleteMessages(id_, revoke_);
}

std::string DeleteMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke ? 1 << 0 : 0;
    buffer += Vector<int>::write(id);
    return buffer;
}

ReceivedMessages::ReceivedMessages(int max_id_) {}

ReceivedMessages ReceivedMessages::read(Reader reader)
{
    int max_id_ = Int::read(reader);
    return ReceivedMessages(max_id_);
}

std::string ReceivedMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(max_id);
    return buffer;
}

SetTyping::SetTyping(TLObject peer_, TLObject action_, std::optional<int> top_msg_id_) {}

SetTyping SetTyping::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> top_msg_id_;
    top_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    return SetTyping(peer_, action_, top_msg_id_);
}

std::string SetTyping::write()
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

SendMessage::SendMessage(TLObject peer_, std::string message_, long random_id_, std::optional<bool> no_webpage_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

SendMessage SendMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> background_;
    background_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> clear_draft_;
    clear_draft_ = (1 << 7) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::string message_ = String::read(reader);
    long random_id_ = Long::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    return SendMessage(peer_, message_, random_id_, no_webpage_, silent_, background_, clear_draft_, reply_to_msg_id_, reply_markup_, entities_, schedule_date_);
}

std::string SendMessage::write()
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

SendMedia::SendMedia(TLObject peer_, TLObject media_, std::string message_, long random_id_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

SendMedia SendMedia::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> background_;
    background_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> clear_draft_;
    clear_draft_ = (1 << 7) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    long random_id_ = Long::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    return SendMedia(peer_, media_, message_, random_id_, silent_, background_, clear_draft_, reply_to_msg_id_, reply_markup_, entities_, schedule_date_);
}

std::string SendMedia::write()
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

ForwardMessages::ForwardMessages(TLObject from_peer_, std::vector<int> id_, std::vector<long> random_id_, TLObject to_peer_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> with_my_score_, std::optional<int> schedule_date_) {}

ForwardMessages ForwardMessages::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> background_;
    background_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> with_my_score_;
    with_my_score_ = (1 << 8) ? std::optional{true} : std::nullopt;
    TLObject from_peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    std::vector<long> random_id_ = std::get<std::vector<long>>(TLObject::read(reader));
    TLObject to_peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    return ForwardMessages(from_peer_, id_, random_id_, to_peer_, silent_, background_, with_my_score_, schedule_date_);
}

std::string ForwardMessages::write()
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

ReportSpam::ReportSpam(TLObject peer_) {}

ReportSpam ReportSpam::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ReportSpam(peer_);
}

std::string ReportSpam::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

GetPeerSettings::GetPeerSettings(TLObject peer_) {}

GetPeerSettings GetPeerSettings::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return GetPeerSettings(peer_);
}

std::string GetPeerSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

Report::Report(TLObject peer_, std::vector<int> id_, TLObject reason_, std::string message_) {}

Report Report::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    TLObject reason_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    return Report(peer_, id_, reason_, message_);
}

std::string Report::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    buffer += reason.write();
    buffer += String::write(message);
    return buffer;
}

GetChats::GetChats(std::vector<int> id_) {}

GetChats GetChats::read(Reader reader)
{
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return GetChats(id_);
}

std::string GetChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(id);
    return buffer;
}

GetFullChat::GetFullChat(int chat_id_) {}

GetFullChat GetFullChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return GetFullChat(chat_id_);
}

std::string GetFullChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

EditChatTitle::EditChatTitle(int chat_id_, std::string title_) {}

EditChatTitle EditChatTitle::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    return EditChatTitle(chat_id_, title_);
}

std::string EditChatTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += String::write(title);
    return buffer;
}

EditChatPhoto::EditChatPhoto(int chat_id_, TLObject photo_) {}

EditChatPhoto EditChatPhoto::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    return EditChatPhoto(chat_id_, photo_);
}

std::string EditChatPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += photo.write();
    return buffer;
}

AddChatUser::AddChatUser(int chat_id_, TLObject user_id_, int fwd_limit_) {}

AddChatUser AddChatUser::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int fwd_limit_ = Int::read(reader);
    return AddChatUser(chat_id_, user_id_, fwd_limit_);
}

std::string AddChatUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    buffer += Int::write(fwd_limit);
    return buffer;
}

DeleteChatUser::DeleteChatUser(int chat_id_, TLObject user_id_, std::optional<bool> revoke_history_) {}

DeleteChatUser DeleteChatUser::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_history_;
    revoke_history_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return DeleteChatUser(chat_id_, user_id_, revoke_history_);
}

std::string DeleteChatUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke_history ? 1 << 0 : 0;
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    return buffer;
}

CreateChat::CreateChat(std::vector<TLObject> users_, std::string title_) {}

CreateChat CreateChat::read(Reader reader)
{
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    return CreateChat(users_, title_);
}

std::string CreateChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(users);
    buffer += String::write(title);
    return buffer;
}

GetDhConfig::GetDhConfig(int version_, int random_length_) {}

GetDhConfig GetDhConfig::read(Reader reader)
{
    int version_ = Int::read(reader);
    int random_length_ = Int::read(reader);
    return GetDhConfig(version_, random_length_);
}

std::string GetDhConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(version);
    buffer += Int::write(random_length);
    return buffer;
}

RequestEncryption::RequestEncryption(TLObject user_id_, int random_id_, std::string g_a_) {}

RequestEncryption RequestEncryption::read(Reader reader)
{
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int random_id_ = Int::read(reader);
    std::string g_a_ = Bytes::read(reader);
    return RequestEncryption(user_id_, random_id_, g_a_);
}

std::string RequestEncryption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(random_id);
    buffer += Bytes::write(g_a);
    return buffer;
}

AcceptEncryption::AcceptEncryption(TLObject peer_, std::string g_b_, long key_fingerprint_) {}

AcceptEncryption AcceptEncryption::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string g_b_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    return AcceptEncryption(peer_, g_b_, key_fingerprint_);
}

std::string AcceptEncryption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bytes::write(g_b);
    buffer += Long::write(key_fingerprint);
    return buffer;
}

DiscardEncryption::DiscardEncryption(int chat_id_, std::optional<bool> delete_history_) {}

DiscardEncryption DiscardEncryption::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> delete_history_;
    delete_history_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int chat_id_ = Int::read(reader);
    return DiscardEncryption(chat_id_, delete_history_);
}

std::string DiscardEncryption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= delete_history ? 1 << 0 : 0;
    buffer += Int::write(chat_id);
    return buffer;
}

SetEncryptedTyping::SetEncryptedTyping(TLObject peer_, bool typing_) {}

SetEncryptedTyping SetEncryptedTyping::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    bool typing_ = Bool::read(reader);
    return SetEncryptedTyping(peer_, typing_);
}

std::string SetEncryptedTyping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Bool::write(typing);
    return buffer;
}

ReadEncryptedHistory::ReadEncryptedHistory(TLObject peer_, int max_date_) {}

ReadEncryptedHistory ReadEncryptedHistory::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int max_date_ = Int::read(reader);
    return ReadEncryptedHistory(peer_, max_date_);
}

std::string ReadEncryptedHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(max_date);
    return buffer;
}

SendEncrypted::SendEncrypted(TLObject peer_, long random_id_, std::string data_, std::optional<bool> silent_) {}

SendEncrypted SendEncrypted::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    return SendEncrypted(peer_, random_id_, data_, silent_);
}

std::string SendEncrypted::write()
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

SendEncryptedFile::SendEncryptedFile(TLObject peer_, long random_id_, std::string data_, TLObject file_, std::optional<bool> silent_) {}

SendEncryptedFile SendEncryptedFile::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    return SendEncryptedFile(peer_, random_id_, data_, file_, silent_);
}

std::string SendEncryptedFile::write()
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

SendEncryptedService::SendEncryptedService(TLObject peer_, long random_id_, std::string data_) {}

SendEncryptedService SendEncryptedService::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long random_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    return SendEncryptedService(peer_, random_id_, data_);
}

std::string SendEncryptedService::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += Bytes::write(data);
    return buffer;
}

ReceivedQueue::ReceivedQueue(int max_qts_) {}

ReceivedQueue ReceivedQueue::read(Reader reader)
{
    int max_qts_ = Int::read(reader);
    return ReceivedQueue(max_qts_);
}

std::string ReceivedQueue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(max_qts);
    return buffer;
}

ReportEncryptedSpam::ReportEncryptedSpam(TLObject peer_) {}

ReportEncryptedSpam ReportEncryptedSpam::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ReportEncryptedSpam(peer_);
}

std::string ReportEncryptedSpam::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

ReadMessageContents::ReadMessageContents(std::vector<int> id_) {}

ReadMessageContents ReadMessageContents::read(Reader reader)
{
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return ReadMessageContents(id_);
}

std::string ReadMessageContents::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(id);
    return buffer;
}

GetStickers::GetStickers(std::string emoticon_, int hash_) {}

GetStickers GetStickers::read(Reader reader)
{
    std::string emoticon_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetStickers(emoticon_, hash_);
}

std::string GetStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(emoticon);
    buffer += Int::write(hash);
    return buffer;
}

GetAllStickers::GetAllStickers(int hash_) {}

GetAllStickers GetAllStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetAllStickers(hash_);
}

std::string GetAllStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

GetWebPagePreview::GetWebPagePreview(std::string message_, std::optional<std::vector<TLObject>> entities_) {}

GetWebPagePreview GetWebPagePreview::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return GetWebPagePreview(message_, entities_);
}

std::string GetWebPagePreview::write()
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

ExportChatInvite::ExportChatInvite(TLObject peer_, std::optional<bool> legacy_revoke_permanent_, std::optional<int> expire_date_, std::optional<int> usage_limit_) {}

ExportChatInvite ExportChatInvite::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> legacy_revoke_permanent_;
    legacy_revoke_permanent_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> expire_date_;
    expire_date_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> usage_limit_;
    usage_limit_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return ExportChatInvite(peer_, legacy_revoke_permanent_, expire_date_, usage_limit_);
}

std::string ExportChatInvite::write()
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

CheckChatInvite::CheckChatInvite(std::string hash_) {}

CheckChatInvite CheckChatInvite::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    return CheckChatInvite(hash_);
}

std::string CheckChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    return buffer;
}

ImportChatInvite::ImportChatInvite(std::string hash_) {}

ImportChatInvite ImportChatInvite::read(Reader reader)
{
    std::string hash_ = String::read(reader);
    return ImportChatInvite(hash_);
}

std::string ImportChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(hash);
    return buffer;
}

GetStickerSet::GetStickerSet(TLObject stickerset_) {}

GetStickerSet GetStickerSet::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    return GetStickerSet(stickerset_);
}

std::string GetStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    return buffer;
}

InstallStickerSet::InstallStickerSet(TLObject stickerset_, bool archived_) {}

InstallStickerSet InstallStickerSet::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    bool archived_ = Bool::read(reader);
    return InstallStickerSet(stickerset_, archived_);
}

std::string InstallStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += Bool::write(archived);
    return buffer;
}

UninstallStickerSet::UninstallStickerSet(TLObject stickerset_) {}

UninstallStickerSet UninstallStickerSet::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    return UninstallStickerSet(stickerset_);
}

std::string UninstallStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    return buffer;
}

StartBot::StartBot(TLObject bot_, TLObject peer_, long random_id_, std::string start_param_) {}

StartBot StartBot::read(Reader reader)
{
    TLObject bot_ = std::get<TLObject>(TLObject::read(reader));
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long random_id_ = Long::read(reader);
    std::string start_param_ = String::read(reader);
    return StartBot(bot_, peer_, random_id_, start_param_);
}

std::string StartBot::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += bot.write();
    buffer += peer.write();
    buffer += Long::write(random_id);
    buffer += String::write(start_param);
    return buffer;
}

GetMessagesViews::GetMessagesViews(TLObject peer_, std::vector<int> id_, bool increment_) {}

GetMessagesViews GetMessagesViews::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    bool increment_ = Bool::read(reader);
    return GetMessagesViews(peer_, id_, increment_);
}

std::string GetMessagesViews::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    buffer += Bool::write(increment);
    return buffer;
}

EditChatAdmin::EditChatAdmin(int chat_id_, TLObject user_id_, bool is_admin_) {}

EditChatAdmin EditChatAdmin::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    bool is_admin_ = Bool::read(reader);
    return EditChatAdmin(chat_id_, user_id_, is_admin_);
}

std::string EditChatAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += user_id.write();
    buffer += Bool::write(is_admin);
    return buffer;
}

MigrateChat::MigrateChat(int chat_id_) {}

MigrateChat MigrateChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return MigrateChat(chat_id_);
}

std::string MigrateChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

SearchGlobal::SearchGlobal(std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_, std::optional<int> folder_id_) {}

SearchGlobal SearchGlobal::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::string q_ = String::read(reader);
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    int min_date_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    int offset_rate_ = Int::read(reader);
    TLObject offset_peer_ = std::get<TLObject>(TLObject::read(reader));
    int offset_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return SearchGlobal(q_, filter_, min_date_, max_date_, offset_rate_, offset_peer_, offset_id_, limit_, folder_id_);
}

std::string SearchGlobal::write()
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

ReorderStickerSets::ReorderStickerSets(std::vector<long> order_, std::optional<bool> masks_) {}

ReorderStickerSets ReorderStickerSets::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;
    masks_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::vector<long> order_ = std::get<std::vector<long>>(TLObject::read(reader));
    return ReorderStickerSets(order_, masks_);
}

std::string ReorderStickerSets::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    buffer += Vector<long>::write(order);
    return buffer;
}

GetDocumentByHash::GetDocumentByHash(std::string sha256_, int size_, std::string mime_type_) {}

GetDocumentByHash GetDocumentByHash::read(Reader reader)
{
    std::string sha256_ = Bytes::read(reader);
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    return GetDocumentByHash(sha256_, size_, mime_type_);
}

std::string GetDocumentByHash::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(sha256);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    return buffer;
}

GetSavedGifs::GetSavedGifs(int hash_) {}

GetSavedGifs GetSavedGifs::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetSavedGifs(hash_);
}

std::string GetSavedGifs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

SaveGif::SaveGif(TLObject id_, bool unsave_) {}

SaveGif SaveGif::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    bool unsave_ = Bool::read(reader);
    return SaveGif(id_, unsave_);
}

std::string SaveGif::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Bool::write(unsave);
    return buffer;
}

GetInlineBotResults::GetInlineBotResults(TLObject bot_, TLObject peer_, std::string query_, std::string offset_, std::optional<TLObject> geo_point_) {}

GetInlineBotResults GetInlineBotResults::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject bot_ = std::get<TLObject>(TLObject::read(reader));
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> geo_point_;
    geo_point_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string query_ = String::read(reader);
    std::string offset_ = String::read(reader);
    return GetInlineBotResults(bot_, peer_, query_, offset_, geo_point_);
}

std::string GetInlineBotResults::write()
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

SetInlineBotResults::SetInlineBotResults(long query_id_, std::vector<TLObject> results_, int cache_time_, std::optional<bool> gallery_, std::optional<bool> private_, std::optional<std::string> next_offset_, std::optional<TLObject> switch_pm_) {}

SetInlineBotResults SetInlineBotResults::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> gallery_;
    gallery_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> private_;
    private_ = (1 << 1) ? std::optional{true} : std::nullopt;
    long query_id_ = Long::read(reader);
    std::vector<TLObject> results_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int cache_time_ = Int::read(reader);
    std::optional<std::string> next_offset_;
    next_offset_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> switch_pm_;
    switch_pm_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return SetInlineBotResults(query_id_, results_, cache_time_, gallery_, private_, next_offset_, switch_pm_);
}

std::string SetInlineBotResults::write()
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

SendInlineBotResult::SendInlineBotResult(TLObject peer_, long random_id_, long query_id_, std::string id_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<bool> hide_via_, std::optional<int> reply_to_msg_id_, std::optional<int> schedule_date_) {}

SendInlineBotResult SendInlineBotResult::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> background_;
    background_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> clear_draft_;
    clear_draft_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> hide_via_;
    hide_via_ = (1 << 11) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    long random_id_ = Long::read(reader);
    long query_id_ = Long::read(reader);
    std::string id_ = String::read(reader);
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    return SendInlineBotResult(peer_, random_id_, query_id_, id_, silent_, background_, clear_draft_, hide_via_, reply_to_msg_id_, schedule_date_);
}

std::string SendInlineBotResult::write()
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

GetMessageEditData::GetMessageEditData(TLObject peer_, int id_) {}

GetMessageEditData GetMessageEditData::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    return GetMessageEditData(peer_, id_);
}

std::string GetMessageEditData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(id);
    return buffer;
}

EditMessage::EditMessage(TLObject peer_, int id_, std::optional<bool> no_webpage_, std::optional<std::string> message_, std::optional<TLObject> media_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> schedule_date_) {}

EditMessage EditMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    std::optional<std::string> message_;
    message_ = (1 << 11) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> media_;
    media_ = (1 << 14) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 15) ? std::optional{Int::read(reader)} : std::nullopt;
    return EditMessage(peer_, id_, no_webpage_, message_, media_, reply_markup_, entities_, schedule_date_);
}

std::string EditMessage::write()
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

EditInlineBotMessage::EditInlineBotMessage(TLObject id_, std::optional<bool> no_webpage_, std::optional<std::string> message_, std::optional<TLObject> media_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_) {}

EditInlineBotMessage EditInlineBotMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> message_;
    message_ = (1 << 11) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> media_;
    media_ = (1 << 14) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return EditInlineBotMessage(id_, no_webpage_, message_, media_, reply_markup_, entities_);
}

std::string EditInlineBotMessage::write()
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

GetBotCallbackAnswer::GetBotCallbackAnswer(TLObject peer_, int msg_id_, std::optional<bool> game_, std::optional<std::string> data_, std::optional<TLObject> password_) {}

GetBotCallbackAnswer GetBotCallbackAnswer::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> game_;
    game_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    std::optional<std::string> data_;
    data_ = (1 << 0) ? std::optional{Bytes::read(reader)} : std::nullopt;
    std::optional<TLObject> password_;
    password_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return GetBotCallbackAnswer(peer_, msg_id_, game_, data_, password_);
}

std::string GetBotCallbackAnswer::write()
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

SetBotCallbackAnswer::SetBotCallbackAnswer(long query_id_, int cache_time_, std::optional<bool> alert_, std::optional<std::string> message_, std::optional<std::string> url_) {}

SetBotCallbackAnswer SetBotCallbackAnswer::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> alert_;
    alert_ = (1 << 1) ? std::optional{true} : std::nullopt;
    long query_id_ = Long::read(reader);
    std::optional<std::string> message_;
    message_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    int cache_time_ = Int::read(reader);
    return SetBotCallbackAnswer(query_id_, cache_time_, alert_, message_, url_);
}

std::string SetBotCallbackAnswer::write()
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

GetPeerDialogs::GetPeerDialogs(std::vector<TLObject> peers_) {}

GetPeerDialogs GetPeerDialogs::read(Reader reader)
{
    std::vector<TLObject> peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetPeerDialogs(peers_);
}

std::string GetPeerDialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(peers);
    return buffer;
}

SaveDraft::SaveDraft(TLObject peer_, std::string message_, std::optional<bool> no_webpage_, std::optional<int> reply_to_msg_id_, std::optional<std::vector<TLObject>> entities_) {}

SaveDraft SaveDraft::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return SaveDraft(peer_, message_, no_webpage_, reply_to_msg_id_, entities_);
}

std::string SaveDraft::write()
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
GetAllDrafts GetAllDrafts::read(Reader reader)
{
    return GetAllDrafts();
}

std::string GetAllDrafts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetFeaturedStickers::GetFeaturedStickers(int hash_) {}

GetFeaturedStickers GetFeaturedStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetFeaturedStickers(hash_);
}

std::string GetFeaturedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

ReadFeaturedStickers::ReadFeaturedStickers(std::vector<long> id_) {}

ReadFeaturedStickers ReadFeaturedStickers::read(Reader reader)
{
    std::vector<long> id_ = std::get<std::vector<long>>(TLObject::read(reader));
    return ReadFeaturedStickers(id_);
}

std::string ReadFeaturedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(id);
    return buffer;
}

GetRecentStickers::GetRecentStickers(int hash_, std::optional<bool> attached_) {}

GetRecentStickers GetRecentStickers::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;
    attached_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int hash_ = Int::read(reader);
    return GetRecentStickers(hash_, attached_);
}

std::string GetRecentStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    buffer += Int::write(hash);
    return buffer;
}

SaveRecentSticker::SaveRecentSticker(TLObject id_, bool unsave_, std::optional<bool> attached_) {}

SaveRecentSticker SaveRecentSticker::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;
    attached_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    bool unsave_ = Bool::read(reader);
    return SaveRecentSticker(id_, unsave_, attached_);
}

std::string SaveRecentSticker::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    buffer += id.write();
    buffer += Bool::write(unsave);
    return buffer;
}

ClearRecentStickers::ClearRecentStickers(std::optional<bool> attached_) {}

ClearRecentStickers ClearRecentStickers::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> attached_;
    attached_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return ClearRecentStickers(attached_);
}

std::string ClearRecentStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= attached ? 1 << 0 : 0;
    return buffer;
}

GetArchivedStickers::GetArchivedStickers(long offset_id_, int limit_, std::optional<bool> masks_) {}

GetArchivedStickers GetArchivedStickers::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;
    masks_ = (1 << 0) ? std::optional{true} : std::nullopt;
    long offset_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetArchivedStickers(offset_id_, limit_, masks_);
}

std::string GetArchivedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    buffer += Long::write(offset_id);
    buffer += Int::write(limit);
    return buffer;
}

GetMaskStickers::GetMaskStickers(int hash_) {}

GetMaskStickers GetMaskStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetMaskStickers(hash_);
}

std::string GetMaskStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

GetAttachedStickers::GetAttachedStickers(TLObject media_) {}

GetAttachedStickers GetAttachedStickers::read(Reader reader)
{
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    return GetAttachedStickers(media_);
}

std::string GetAttachedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += media.write();
    return buffer;
}

SetGameScore::SetGameScore(TLObject peer_, int id_, TLObject user_id_, int score_, std::optional<bool> edit_message_, std::optional<bool> force_) {}

SetGameScore SetGameScore::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> edit_message_;
    edit_message_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> force_;
    force_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int score_ = Int::read(reader);
    return SetGameScore(peer_, id_, user_id_, score_, edit_message_, force_);
}

std::string SetGameScore::write()
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

SetInlineGameScore::SetInlineGameScore(TLObject id_, TLObject user_id_, int score_, std::optional<bool> edit_message_, std::optional<bool> force_) {}

SetInlineGameScore SetInlineGameScore::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> edit_message_;
    edit_message_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> force_;
    force_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int score_ = Int::read(reader);
    return SetInlineGameScore(id_, user_id_, score_, edit_message_, force_);
}

std::string SetInlineGameScore::write()
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

GetGameHighScores::GetGameHighScores(TLObject peer_, int id_, TLObject user_id_) {}

GetGameHighScores GetGameHighScores::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return GetGameHighScores(peer_, id_, user_id_);
}

std::string GetGameHighScores::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(id);
    buffer += user_id.write();
    return buffer;
}

GetInlineGameHighScores::GetInlineGameHighScores(TLObject id_, TLObject user_id_) {}

GetInlineGameHighScores GetInlineGameHighScores::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return GetInlineGameHighScores(id_, user_id_);
}

std::string GetInlineGameHighScores::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += user_id.write();
    return buffer;
}

GetCommonChats::GetCommonChats(TLObject user_id_, int max_id_, int limit_) {}

GetCommonChats GetCommonChats::read(Reader reader)
{
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetCommonChats(user_id_, max_id_, limit_);
}

std::string GetCommonChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(max_id);
    buffer += Int::write(limit);
    return buffer;
}

GetAllChats::GetAllChats(std::vector<int> except_ids_) {}

GetAllChats GetAllChats::read(Reader reader)
{
    std::vector<int> except_ids_ = std::get<std::vector<int>>(TLObject::read(reader));
    return GetAllChats(except_ids_);
}

std::string GetAllChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(except_ids);
    return buffer;
}

GetWebPage::GetWebPage(std::string url_, int hash_) {}

GetWebPage GetWebPage::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int hash_ = Int::read(reader);
    return GetWebPage(url_, hash_);
}

std::string GetWebPage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(hash);
    return buffer;
}

ToggleDialogPin::ToggleDialogPin(TLObject peer_, std::optional<bool> pinned_) {}

ToggleDialogPin ToggleDialogPin::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ToggleDialogPin(peer_, pinned_);
}

std::string ToggleDialogPin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 0 : 0;
    buffer += peer.write();
    return buffer;
}

ReorderPinnedDialogs::ReorderPinnedDialogs(int folder_id_, std::vector<TLObject> order_, std::optional<bool> force_) {}

ReorderPinnedDialogs ReorderPinnedDialogs::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> force_;
    force_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int folder_id_ = Int::read(reader);
    std::vector<TLObject> order_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ReorderPinnedDialogs(folder_id_, order_, force_);
}

std::string ReorderPinnedDialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= force ? 1 << 0 : 0;
    buffer += Int::write(folder_id);
    buffer += Vector<TLObject>::write(order);
    return buffer;
}

GetPinnedDialogs::GetPinnedDialogs(int folder_id_) {}

GetPinnedDialogs GetPinnedDialogs::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return GetPinnedDialogs(folder_id_);
}

std::string GetPinnedDialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}

SetBotShippingResults::SetBotShippingResults(long query_id_, std::optional<std::string> error_, std::optional<std::vector<TLObject>> shipping_options_) {}

SetBotShippingResults SetBotShippingResults::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    std::optional<std::string> error_;
    error_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> shipping_options_;
    shipping_options_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return SetBotShippingResults(query_id_, error_, shipping_options_);
}

std::string SetBotShippingResults::write()
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

SetBotPrecheckoutResults::SetBotPrecheckoutResults(long query_id_, std::optional<bool> success_, std::optional<std::string> error_) {}

SetBotPrecheckoutResults SetBotPrecheckoutResults::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> success_;
    success_ = (1 << 1) ? std::optional{true} : std::nullopt;
    long query_id_ = Long::read(reader);
    std::optional<std::string> error_;
    error_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    return SetBotPrecheckoutResults(query_id_, success_, error_);
}

std::string SetBotPrecheckoutResults::write()
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

UploadMedia::UploadMedia(TLObject peer_, TLObject media_) {}

UploadMedia UploadMedia::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    return UploadMedia(peer_, media_);
}

std::string UploadMedia::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += media.write();
    return buffer;
}

SendScreenshotNotification::SendScreenshotNotification(TLObject peer_, int reply_to_msg_id_, long random_id_) {}

SendScreenshotNotification SendScreenshotNotification::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int reply_to_msg_id_ = Int::read(reader);
    long random_id_ = Long::read(reader);
    return SendScreenshotNotification(peer_, reply_to_msg_id_, random_id_);
}

std::string SendScreenshotNotification::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(reply_to_msg_id);
    buffer += Long::write(random_id);
    return buffer;
}

GetFavedStickers::GetFavedStickers(int hash_) {}

GetFavedStickers GetFavedStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    return GetFavedStickers(hash_);
}

std::string GetFavedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    return buffer;
}

FaveSticker::FaveSticker(TLObject id_, bool unfave_) {}

FaveSticker FaveSticker::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    bool unfave_ = Bool::read(reader);
    return FaveSticker(id_, unfave_);
}

std::string FaveSticker::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Bool::write(unfave);
    return buffer;
}

GetUnreadMentions::GetUnreadMentions(TLObject peer_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_) {}

GetUnreadMentions GetUnreadMentions::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int offset_id_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    return GetUnreadMentions(peer_, offset_id_, add_offset_, limit_, max_id_, min_id_);
}

std::string GetUnreadMentions::write()
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

ReadMentions::ReadMentions(TLObject peer_) {}

ReadMentions ReadMentions::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ReadMentions(peer_);
}

std::string ReadMentions::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

GetRecentLocations::GetRecentLocations(TLObject peer_, int limit_, int hash_) {}

GetRecentLocations GetRecentLocations::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetRecentLocations(peer_, limit_, hash_);
}

std::string GetRecentLocations::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

SendMultiMedia::SendMultiMedia(TLObject peer_, std::vector<TLObject> multi_media_, std::optional<bool> silent_, std::optional<bool> background_, std::optional<bool> clear_draft_, std::optional<int> reply_to_msg_id_, std::optional<int> schedule_date_) {}

SendMultiMedia SendMultiMedia::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> background_;
    background_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> clear_draft_;
    clear_draft_ = (1 << 7) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::vector<TLObject> multi_media_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    return SendMultiMedia(peer_, multi_media_, silent_, background_, clear_draft_, reply_to_msg_id_, schedule_date_);
}

std::string SendMultiMedia::write()
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

UploadEncryptedFile::UploadEncryptedFile(TLObject peer_, TLObject file_) {}

UploadEncryptedFile UploadEncryptedFile::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    return UploadEncryptedFile(peer_, file_);
}

std::string UploadEncryptedFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += file.write();
    return buffer;
}

SearchStickerSets::SearchStickerSets(std::string q_, int hash_, std::optional<bool> exclude_featured_) {}

SearchStickerSets SearchStickerSets::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> exclude_featured_;
    exclude_featured_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string q_ = String::read(reader);
    int hash_ = Int::read(reader);
    return SearchStickerSets(q_, hash_, exclude_featured_);
}

std::string SearchStickerSets::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= exclude_featured ? 1 << 0 : 0;
    buffer += String::write(q);
    buffer += Int::write(hash);
    return buffer;
}
GetSplitRanges GetSplitRanges::read(Reader reader)
{
    return GetSplitRanges();
}

std::string GetSplitRanges::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MarkDialogUnread::MarkDialogUnread(TLObject peer_, std::optional<bool> unread_) {}

MarkDialogUnread MarkDialogUnread::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> unread_;
    unread_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return MarkDialogUnread(peer_, unread_);
}

std::string MarkDialogUnread::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= unread ? 1 << 0 : 0;
    buffer += peer.write();
    return buffer;
}
GetDialogUnreadMarks GetDialogUnreadMarks::read(Reader reader)
{
    return GetDialogUnreadMarks();
}

std::string GetDialogUnreadMarks::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
ClearAllDrafts ClearAllDrafts::read(Reader reader)
{
    return ClearAllDrafts();
}

std::string ClearAllDrafts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdatePinnedMessage::UpdatePinnedMessage(TLObject peer_, int id_, std::optional<bool> silent_, std::optional<bool> unpin_, std::optional<bool> pm_oneside_) {}

UpdatePinnedMessage UpdatePinnedMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> silent_;
    silent_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> unpin_;
    unpin_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> pm_oneside_;
    pm_oneside_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    return UpdatePinnedMessage(peer_, id_, silent_, unpin_, pm_oneside_);
}

std::string UpdatePinnedMessage::write()
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

SendVote::SendVote(TLObject peer_, int msg_id_, std::vector<std::string> options_) {}

SendVote SendVote::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    std::vector<std::string> options_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return SendVote(peer_, msg_id_, options_);
}

std::string SendVote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Vector<std::string>::write(options);
    return buffer;
}

GetPollResults::GetPollResults(TLObject peer_, int msg_id_) {}

GetPollResults GetPollResults::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    return GetPollResults(peer_, msg_id_);
}

std::string GetPollResults::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

GetOnlines::GetOnlines(TLObject peer_) {}

GetOnlines GetOnlines::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return GetOnlines(peer_);
}

std::string GetOnlines::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

GetStatsURL::GetStatsURL(TLObject peer_, std::string params_, std::optional<bool> dark_) {}

GetStatsURL GetStatsURL::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;
    dark_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string params_ = String::read(reader);
    return GetStatsURL(peer_, params_, dark_);
}

std::string GetStatsURL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += String::write(params);
    return buffer;
}

EditChatAbout::EditChatAbout(TLObject peer_, std::string about_) {}

EditChatAbout EditChatAbout::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string about_ = String::read(reader);
    return EditChatAbout(peer_, about_);
}

std::string EditChatAbout::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(about);
    return buffer;
}

EditChatDefaultBannedRights::EditChatDefaultBannedRights(TLObject peer_, TLObject banned_rights_) {}

EditChatDefaultBannedRights EditChatDefaultBannedRights::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    return EditChatDefaultBannedRights(peer_, banned_rights_);
}

std::string EditChatDefaultBannedRights::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += banned_rights.write();
    return buffer;
}

GetEmojiKeywords::GetEmojiKeywords(std::string lang_code_) {}

GetEmojiKeywords GetEmojiKeywords::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return GetEmojiKeywords(lang_code_);
}

std::string GetEmojiKeywords::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

GetEmojiKeywordsDifference::GetEmojiKeywordsDifference(std::string lang_code_, int from_version_) {}

GetEmojiKeywordsDifference GetEmojiKeywordsDifference::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    return GetEmojiKeywordsDifference(lang_code_, from_version_);
}

std::string GetEmojiKeywordsDifference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    return buffer;
}

GetEmojiKeywordsLanguages::GetEmojiKeywordsLanguages(std::vector<std::string> lang_codes_) {}

GetEmojiKeywordsLanguages GetEmojiKeywordsLanguages::read(Reader reader)
{
    std::vector<std::string> lang_codes_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return GetEmojiKeywordsLanguages(lang_codes_);
}

std::string GetEmojiKeywordsLanguages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<std::string>::write(lang_codes);
    return buffer;
}

GetEmojiURL::GetEmojiURL(std::string lang_code_) {}

GetEmojiURL GetEmojiURL::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return GetEmojiURL(lang_code_);
}

std::string GetEmojiURL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

GetSearchCounters::GetSearchCounters(TLObject peer_, std::vector<TLObject> filters_) {}

GetSearchCounters GetSearchCounters::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> filters_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetSearchCounters(peer_, filters_);
}

std::string GetSearchCounters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<TLObject>::write(filters);
    return buffer;
}

RequestUrlAuth::RequestUrlAuth(std::optional<TLObject> peer_, std::optional<int> msg_id_, std::optional<int> button_id_, std::optional<std::string> url_) {}

RequestUrlAuth RequestUrlAuth::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> peer_;
    peer_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> msg_id_;
    msg_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> button_id_;
    button_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return RequestUrlAuth(peer_, msg_id_, button_id_, url_);
}

std::string RequestUrlAuth::write()
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

AcceptUrlAuth::AcceptUrlAuth(std::optional<bool> write_allowed_, std::optional<TLObject> peer_, std::optional<int> msg_id_, std::optional<int> button_id_, std::optional<std::string> url_) {}

AcceptUrlAuth AcceptUrlAuth::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> write_allowed_;
    write_allowed_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> peer_;
    peer_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> msg_id_;
    msg_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> button_id_;
    button_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return AcceptUrlAuth(write_allowed_, peer_, msg_id_, button_id_, url_);
}

std::string AcceptUrlAuth::write()
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

HidePeerSettingsBar::HidePeerSettingsBar(TLObject peer_) {}

HidePeerSettingsBar HidePeerSettingsBar::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return HidePeerSettingsBar(peer_);
}

std::string HidePeerSettingsBar::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

GetScheduledHistory::GetScheduledHistory(TLObject peer_, int hash_) {}

GetScheduledHistory GetScheduledHistory::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int hash_ = Int::read(reader);
    return GetScheduledHistory(peer_, hash_);
}

std::string GetScheduledHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(hash);
    return buffer;
}

GetScheduledMessages::GetScheduledMessages(TLObject peer_, std::vector<int> id_) {}

GetScheduledMessages GetScheduledMessages::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return GetScheduledMessages(peer_, id_);
}

std::string GetScheduledMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

SendScheduledMessages::SendScheduledMessages(TLObject peer_, std::vector<int> id_) {}

SendScheduledMessages SendScheduledMessages::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return SendScheduledMessages(peer_, id_);
}

std::string SendScheduledMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

DeleteScheduledMessages::DeleteScheduledMessages(TLObject peer_, std::vector<int> id_) {}

DeleteScheduledMessages DeleteScheduledMessages::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> id_ = std::get<std::vector<int>>(TLObject::read(reader));
    return DeleteScheduledMessages(peer_, id_);
}

std::string DeleteScheduledMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(id);
    return buffer;
}

GetPollVotes::GetPollVotes(TLObject peer_, int id_, int limit_, std::optional<std::string> option_, std::optional<std::string> offset_) {}

GetPollVotes GetPollVotes::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int id_ = Int::read(reader);
    std::optional<std::string> option_;
    option_ = (1 << 0) ? std::optional{Bytes::read(reader)} : std::nullopt;
    std::optional<std::string> offset_;
    offset_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    int limit_ = Int::read(reader);
    return GetPollVotes(peer_, id_, limit_, option_, offset_);
}

std::string GetPollVotes::write()
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

ToggleStickerSets::ToggleStickerSets(std::vector<TLObject> stickersets_, std::optional<bool> uninstall_, std::optional<bool> archive_, std::optional<bool> unarchive_) {}

ToggleStickerSets ToggleStickerSets::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> uninstall_;
    uninstall_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> archive_;
    archive_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> unarchive_;
    unarchive_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::vector<TLObject> stickersets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ToggleStickerSets(stickersets_, uninstall_, archive_, unarchive_);
}

std::string ToggleStickerSets::write()
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
GetDialogFilters GetDialogFilters::read(Reader reader)
{
    return GetDialogFilters();
}

std::string GetDialogFilters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
GetSuggestedDialogFilters GetSuggestedDialogFilters::read(Reader reader)
{
    return GetSuggestedDialogFilters();
}

std::string GetSuggestedDialogFilters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateDialogFilter::UpdateDialogFilter(int id_, std::optional<TLObject> filter_) {}

UpdateDialogFilter UpdateDialogFilter::read(Reader reader)
{
    int flags = Int::read(reader);
    int id_ = Int::read(reader);
    std::optional<TLObject> filter_;
    filter_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return UpdateDialogFilter(id_, filter_);
}

std::string UpdateDialogFilter::write()
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

UpdateDialogFiltersOrder::UpdateDialogFiltersOrder(std::vector<int> order_) {}

UpdateDialogFiltersOrder UpdateDialogFiltersOrder::read(Reader reader)
{
    std::vector<int> order_ = std::get<std::vector<int>>(TLObject::read(reader));
    return UpdateDialogFiltersOrder(order_);
}

std::string UpdateDialogFiltersOrder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(order);
    return buffer;
}

GetOldFeaturedStickers::GetOldFeaturedStickers(int offset_, int limit_, int hash_) {}

GetOldFeaturedStickers GetOldFeaturedStickers::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetOldFeaturedStickers(offset_, limit_, hash_);
}

std::string GetOldFeaturedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    buffer += Int::write(hash);
    return buffer;
}

GetReplies::GetReplies(TLObject peer_, int msg_id_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_) {}

GetReplies GetReplies::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int offset_id_ = Int::read(reader);
    int offset_date_ = Int::read(reader);
    int add_offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int min_id_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return GetReplies(peer_, msg_id_, offset_id_, offset_date_, add_offset_, limit_, max_id_, min_id_, hash_);
}

std::string GetReplies::write()
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

GetDiscussionMessage::GetDiscussionMessage(TLObject peer_, int msg_id_) {}

GetDiscussionMessage GetDiscussionMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    return GetDiscussionMessage(peer_, msg_id_);
}

std::string GetDiscussionMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

ReadDiscussion::ReadDiscussion(TLObject peer_, int msg_id_, int read_max_id_) {}

ReadDiscussion ReadDiscussion::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int read_max_id_ = Int::read(reader);
    return ReadDiscussion(peer_, msg_id_, read_max_id_);
}

std::string ReadDiscussion::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(read_max_id);
    return buffer;
}

UnpinAllMessages::UnpinAllMessages(TLObject peer_) {}

UnpinAllMessages UnpinAllMessages::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return UnpinAllMessages(peer_);
}

std::string UnpinAllMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

DeleteChat::DeleteChat(int chat_id_) {}

DeleteChat DeleteChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return DeleteChat(chat_id_);
}

std::string DeleteChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

DeletePhoneCallHistory::DeletePhoneCallHistory(std::optional<bool> revoke_) {}

DeletePhoneCallHistory DeletePhoneCallHistory::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoke_;
    revoke_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return DeletePhoneCallHistory(revoke_);
}

std::string DeletePhoneCallHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoke ? 1 << 0 : 0;
    return buffer;
}

CheckHistoryImport::CheckHistoryImport(std::string import_head_) {}

CheckHistoryImport CheckHistoryImport::read(Reader reader)
{
    std::string import_head_ = String::read(reader);
    return CheckHistoryImport(import_head_);
}

std::string CheckHistoryImport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(import_head);
    return buffer;
}

InitHistoryImport::InitHistoryImport(TLObject peer_, TLObject file_, int media_count_) {}

InitHistoryImport InitHistoryImport::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    int media_count_ = Int::read(reader);
    return InitHistoryImport(peer_, file_, media_count_);
}

std::string InitHistoryImport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += file.write();
    buffer += Int::write(media_count);
    return buffer;
}

UploadImportedMedia::UploadImportedMedia(TLObject peer_, long import_id_, std::string file_name_, TLObject media_) {}

UploadImportedMedia UploadImportedMedia::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long import_id_ = Long::read(reader);
    std::string file_name_ = String::read(reader);
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    return UploadImportedMedia(peer_, import_id_, file_name_, media_);
}

std::string UploadImportedMedia::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(import_id);
    buffer += String::write(file_name);
    buffer += media.write();
    return buffer;
}

StartHistoryImport::StartHistoryImport(TLObject peer_, long import_id_) {}

StartHistoryImport StartHistoryImport::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long import_id_ = Long::read(reader);
    return StartHistoryImport(peer_, import_id_);
}

std::string StartHistoryImport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Long::write(import_id);
    return buffer;
}

GetExportedChatInvites::GetExportedChatInvites(TLObject peer_, TLObject admin_id_, int limit_, std::optional<bool> revoked_, std::optional<int> offset_date_, std::optional<std::string> offset_link_) {}

GetExportedChatInvites GetExportedChatInvites::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoked_;
    revoked_ = (1 << 3) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject admin_id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> offset_date_;
    offset_date_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> offset_link_;
    offset_link_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    int limit_ = Int::read(reader);
    return GetExportedChatInvites(peer_, admin_id_, limit_, revoked_, offset_date_, offset_link_);
}

std::string GetExportedChatInvites::write()
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

GetExportedChatInvite::GetExportedChatInvite(TLObject peer_, std::string link_) {}

GetExportedChatInvite GetExportedChatInvite::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string link_ = String::read(reader);
    return GetExportedChatInvite(peer_, link_);
}

std::string GetExportedChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(link);
    return buffer;
}

EditExportedChatInvite::EditExportedChatInvite(TLObject peer_, std::string link_, std::optional<bool> revoked_, std::optional<int> expire_date_, std::optional<int> usage_limit_) {}

EditExportedChatInvite EditExportedChatInvite::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoked_;
    revoked_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string link_ = String::read(reader);
    std::optional<int> expire_date_;
    expire_date_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> usage_limit_;
    usage_limit_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return EditExportedChatInvite(peer_, link_, revoked_, expire_date_, usage_limit_);
}

std::string EditExportedChatInvite::write()
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

DeleteRevokedExportedChatInvites::DeleteRevokedExportedChatInvites(TLObject peer_, TLObject admin_id_) {}

DeleteRevokedExportedChatInvites DeleteRevokedExportedChatInvites::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject admin_id_ = std::get<TLObject>(TLObject::read(reader));
    return DeleteRevokedExportedChatInvites(peer_, admin_id_);
}

std::string DeleteRevokedExportedChatInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += admin_id.write();
    return buffer;
}

DeleteExportedChatInvite::DeleteExportedChatInvite(TLObject peer_, std::string link_) {}

DeleteExportedChatInvite DeleteExportedChatInvite::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string link_ = String::read(reader);
    return DeleteExportedChatInvite(peer_, link_);
}

std::string DeleteExportedChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += String::write(link);
    return buffer;
}

GetAdminsWithInvites::GetAdminsWithInvites(TLObject peer_) {}

GetAdminsWithInvites GetAdminsWithInvites::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return GetAdminsWithInvites(peer_);
}

std::string GetAdminsWithInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

GetChatInviteImporters::GetChatInviteImporters(TLObject peer_, std::string link_, int offset_date_, TLObject offset_user_, int limit_) {}

GetChatInviteImporters GetChatInviteImporters::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::string link_ = String::read(reader);
    int offset_date_ = Int::read(reader);
    TLObject offset_user_ = std::get<TLObject>(TLObject::read(reader));
    int limit_ = Int::read(reader);
    return GetChatInviteImporters(peer_, link_, offset_date_, offset_user_, limit_);
}

std::string GetChatInviteImporters::write()
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

SetHistoryTTL::SetHistoryTTL(TLObject peer_, int period_) {}

SetHistoryTTL SetHistoryTTL::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int period_ = Int::read(reader);
    return SetHistoryTTL(peer_, period_);
}

std::string SetHistoryTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(period);
    return buffer;
}

CheckHistoryImportPeer::CheckHistoryImportPeer(TLObject peer_) {}

CheckHistoryImportPeer CheckHistoryImportPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return CheckHistoryImportPeer(peer_);
}

std::string CheckHistoryImportPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
