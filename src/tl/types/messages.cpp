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

#include "tl/types/messages.h"

Dialogs::Dialogs(std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

Dialogs Dialogs::read(Reader reader)
{
    std::vector<TLObject> dialogs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Dialogs(dialogs_, messages_, chats_, users_);
}

std::string Dialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(dialogs);
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

DialogsSlice::DialogsSlice(int count_, std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

DialogsSlice DialogsSlice::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> dialogs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DialogsSlice(count_, dialogs_, messages_, chats_, users_);
}

std::string DialogsSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(dialogs);
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

DialogsNotModified::DialogsNotModified(int count_) {}

DialogsNotModified DialogsNotModified::read(Reader reader)
{
    int count_ = Int::read(reader);
    return DialogsNotModified(count_);
}

std::string DialogsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    return buffer;
}

Messages::Messages(std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

Messages Messages::read(Reader reader)
{
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Messages(messages_, chats_, users_);
}

std::string Messages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

MessagesSlice::MessagesSlice(int count_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> inexact_, std::optional<int> next_rate_, std::optional<int> offset_id_offset_) {}

MessagesSlice MessagesSlice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> inexact_;
    inexact_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int count_ = Int::read(reader);
    std::optional<int> next_rate_;
    next_rate_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> offset_id_offset_;
    offset_id_offset_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return MessagesSlice(count_, messages_, chats_, users_, inexact_, next_rate_, offset_id_offset_);
}

std::string MessagesSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= inexact ? 1 << 1 : 0;
    flags |= next_rate ? 1 << 0 : 0;
    flags |= offset_id_offset ? 1 << 2 : 0;
    buffer += Int::write(count);

    if (next_rate)
        buffer += Int::write(next_rate.value());

    if (offset_id_offset)
        buffer += Int::write(offset_id_offset.value());
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ChannelMessages::ChannelMessages(int pts_, int count_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> inexact_, std::optional<int> offset_id_offset_) {}

ChannelMessages ChannelMessages::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> inexact_;
    inexact_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int pts_ = Int::read(reader);
    int count_ = Int::read(reader);
    std::optional<int> offset_id_offset_;
    offset_id_offset_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelMessages(pts_, count_, messages_, chats_, users_, inexact_, offset_id_offset_);
}

std::string ChannelMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= inexact ? 1 << 1 : 0;
    flags |= offset_id_offset ? 1 << 2 : 0;
    buffer += Int::write(pts);
    buffer += Int::write(count);

    if (offset_id_offset)
        buffer += Int::write(offset_id_offset.value());
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

MessagesNotModified::MessagesNotModified(int count_) {}

MessagesNotModified MessagesNotModified::read(Reader reader)
{
    int count_ = Int::read(reader);
    return MessagesNotModified(count_);
}

std::string MessagesNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    return buffer;
}

Chats::Chats(std::vector<TLObject> chats_) {}

Chats Chats::read(Reader reader)
{
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Chats(chats_);
}

std::string Chats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(chats);
    return buffer;
}

ChatsSlice::ChatsSlice(int count_, std::vector<TLObject> chats_) {}

ChatsSlice ChatsSlice::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChatsSlice(count_, chats_);
}

std::string ChatsSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(chats);
    return buffer;
}

ChatFull::ChatFull(TLObject full_chat_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ChatFull ChatFull::read(Reader reader)
{
    TLObject full_chat_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChatFull(full_chat_, chats_, users_);
}

std::string ChatFull::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += full_chat.write();
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

AffectedHistory::AffectedHistory(int pts_, int pts_count_, int offset_) {}

AffectedHistory AffectedHistory::read(Reader reader)
{
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    int offset_ = Int::read(reader);
    return AffectedHistory(pts_, pts_count_, offset_);
}

std::string AffectedHistory::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    buffer += Int::write(offset);
    return buffer;
}

DhConfigNotModified::DhConfigNotModified(std::string random_) {}

DhConfigNotModified DhConfigNotModified::read(Reader reader)
{
    std::string random_ = Bytes::read(reader);
    return DhConfigNotModified(random_);
}

std::string DhConfigNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(random);
    return buffer;
}

DhConfig::DhConfig(int g_, std::string p_, int version_, std::string random_) {}

DhConfig DhConfig::read(Reader reader)
{
    int g_ = Int::read(reader);
    std::string p_ = Bytes::read(reader);
    int version_ = Int::read(reader);
    std::string random_ = Bytes::read(reader);
    return DhConfig(g_, p_, version_, random_);
}

std::string DhConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(g);
    buffer += Bytes::write(p);
    buffer += Int::write(version);
    buffer += Bytes::write(random);
    return buffer;
}

SentEncryptedMessage::SentEncryptedMessage(int date_) {}

SentEncryptedMessage SentEncryptedMessage::read(Reader reader)
{
    int date_ = Int::read(reader);
    return SentEncryptedMessage(date_);
}

std::string SentEncryptedMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(date);
    return buffer;
}

SentEncryptedFile::SentEncryptedFile(int date_, TLObject file_) {}

SentEncryptedFile SentEncryptedFile::read(Reader reader)
{
    int date_ = Int::read(reader);
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    return SentEncryptedFile(date_, file_);
}

std::string SentEncryptedFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(date);
    buffer += file.write();
    return buffer;
}
StickersNotModified StickersNotModified::read(Reader reader)
{
    return StickersNotModified();
}

std::string StickersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

Stickers::Stickers(int hash_, std::vector<TLObject> stickers_) {}

Stickers Stickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> stickers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Stickers(hash_, stickers_);
}

std::string Stickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(stickers);
    return buffer;
}
AllStickersNotModified AllStickersNotModified::read(Reader reader)
{
    return AllStickersNotModified();
}

std::string AllStickersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

AllStickers::AllStickers(int hash_, std::vector<TLObject> sets_) {}

AllStickers AllStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> sets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return AllStickers(hash_, sets_);
}

std::string AllStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(sets);
    return buffer;
}

AffectedMessages::AffectedMessages(int pts_, int pts_count_) {}

AffectedMessages AffectedMessages::read(Reader reader)
{
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return AffectedMessages(pts_, pts_count_);
}

std::string AffectedMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

StickerSet::StickerSet(TLObject set_, std::vector<TLObject> packs_, std::vector<TLObject> documents_) {}

StickerSet StickerSet::read(Reader reader)
{
    TLObject set_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> packs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> documents_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return StickerSet(set_, packs_, documents_);
}

std::string StickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += set.write();
    buffer += Vector<TLObject>::write(packs);
    buffer += Vector<TLObject>::write(documents);
    return buffer;
}
SavedGifsNotModified SavedGifsNotModified::read(Reader reader)
{
    return SavedGifsNotModified();
}

std::string SavedGifsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SavedGifs::SavedGifs(int hash_, std::vector<TLObject> gifs_) {}

SavedGifs SavedGifs::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> gifs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SavedGifs(hash_, gifs_);
}

std::string SavedGifs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(gifs);
    return buffer;
}

BotResults::BotResults(long query_id_, std::vector<TLObject> results_, int cache_time_, std::vector<TLObject> users_, std::optional<bool> gallery_, std::optional<std::string> next_offset_, std::optional<TLObject> switch_pm_) {}

BotResults BotResults::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> gallery_;
    gallery_ = (1 << 0) ? std::optional{true} : std::nullopt;
    long query_id_ = Long::read(reader);
    std::optional<std::string> next_offset_;
    next_offset_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> switch_pm_;
    switch_pm_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::vector<TLObject> results_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int cache_time_ = Int::read(reader);
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return BotResults(query_id_, results_, cache_time_, users_, gallery_, next_offset_, switch_pm_);
}

std::string BotResults::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= gallery ? 1 << 0 : 0;
    flags |= next_offset ? 1 << 1 : 0;
    flags |= switch_pm ? 1 << 2 : 0;
    buffer += Long::write(query_id);

    if (next_offset)
        buffer += String::write(next_offset.value());

    if (switch_pm)
        buffer += switch_pm.value().write();
    buffer += Vector<TLObject>::write(results);
    buffer += Int::write(cache_time);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

BotCallbackAnswer::BotCallbackAnswer(int cache_time_, std::optional<bool> alert_, std::optional<bool> has_url_, std::optional<bool> native_ui_, std::optional<std::string> message_, std::optional<std::string> url_) {}

BotCallbackAnswer BotCallbackAnswer::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> alert_;
    alert_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_url_;
    has_url_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> native_ui_;
    native_ui_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<std::string> message_;
    message_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    int cache_time_ = Int::read(reader);
    return BotCallbackAnswer(cache_time_, alert_, has_url_, native_ui_, message_, url_);
}

std::string BotCallbackAnswer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= alert ? 1 << 1 : 0;
    flags |= has_url ? 1 << 3 : 0;
    flags |= native_ui ? 1 << 4 : 0;
    flags |= message ? 1 << 0 : 0;
    flags |= url ? 1 << 2 : 0;

    if (message)
        buffer += String::write(message.value());

    if (url)
        buffer += String::write(url.value());
    buffer += Int::write(cache_time);
    return buffer;
}

MessageEditData::MessageEditData(std::optional<bool> caption_) {}

MessageEditData MessageEditData::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> caption_;
    caption_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return MessageEditData(caption_);
}

std::string MessageEditData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= caption ? 1 << 0 : 0;
    return buffer;
}

PeerDialogs::PeerDialogs(std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject state_) {}

PeerDialogs PeerDialogs::read(Reader reader)
{
    std::vector<TLObject> dialogs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject state_ = std::get<TLObject>(TLObject::read(reader));
    return PeerDialogs(dialogs_, messages_, chats_, users_, state_);
}

std::string PeerDialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(dialogs);
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    buffer += state.write();
    return buffer;
}

FeaturedStickersNotModified::FeaturedStickersNotModified(int count_) {}

FeaturedStickersNotModified FeaturedStickersNotModified::read(Reader reader)
{
    int count_ = Int::read(reader);
    return FeaturedStickersNotModified(count_);
}

std::string FeaturedStickersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    return buffer;
}

FeaturedStickers::FeaturedStickers(int hash_, int count_, std::vector<TLObject> sets_, std::vector<long> unread_) {}

FeaturedStickers FeaturedStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    int count_ = Int::read(reader);
    std::vector<TLObject> sets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<long> unread_ = std::get<std::vector<long>>(TLObject::read(reader));
    return FeaturedStickers(hash_, count_, sets_, unread_);
}

std::string FeaturedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(sets);
    buffer += Vector<long>::write(unread);
    return buffer;
}
RecentStickersNotModified RecentStickersNotModified::read(Reader reader)
{
    return RecentStickersNotModified();
}

std::string RecentStickersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

RecentStickers::RecentStickers(int hash_, std::vector<TLObject> packs_, std::vector<TLObject> stickers_, std::vector<int> dates_) {}

RecentStickers RecentStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> packs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> stickers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<int> dates_ = std::get<std::vector<int>>(TLObject::read(reader));
    return RecentStickers(hash_, packs_, stickers_, dates_);
}

std::string RecentStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(packs);
    buffer += Vector<TLObject>::write(stickers);
    buffer += Vector<int>::write(dates);
    return buffer;
}

ArchivedStickers::ArchivedStickers(int count_, std::vector<TLObject> sets_) {}

ArchivedStickers ArchivedStickers::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> sets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ArchivedStickers(count_, sets_);
}

std::string ArchivedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(sets);
    return buffer;
}
StickerSetInstallResultSuccess StickerSetInstallResultSuccess::read(Reader reader)
{
    return StickerSetInstallResultSuccess();
}

std::string StickerSetInstallResultSuccess::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

StickerSetInstallResultArchive::StickerSetInstallResultArchive(std::vector<TLObject> sets_) {}

StickerSetInstallResultArchive StickerSetInstallResultArchive::read(Reader reader)
{
    std::vector<TLObject> sets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return StickerSetInstallResultArchive(sets_);
}

std::string StickerSetInstallResultArchive::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(sets);
    return buffer;
}

HighScores::HighScores(std::vector<TLObject> scores_, std::vector<TLObject> users_) {}

HighScores HighScores::read(Reader reader)
{
    std::vector<TLObject> scores_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return HighScores(scores_, users_);
}

std::string HighScores::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(scores);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
FavedStickersNotModified FavedStickersNotModified::read(Reader reader)
{
    return FavedStickersNotModified();
}

std::string FavedStickersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

FavedStickers::FavedStickers(int hash_, std::vector<TLObject> packs_, std::vector<TLObject> stickers_) {}

FavedStickers FavedStickers::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> packs_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> stickers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return FavedStickers(hash_, packs_, stickers_);
}

std::string FavedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(packs);
    buffer += Vector<TLObject>::write(stickers);
    return buffer;
}
FoundStickerSetsNotModified FoundStickerSetsNotModified::read(Reader reader)
{
    return FoundStickerSetsNotModified();
}

std::string FoundStickerSetsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

FoundStickerSets::FoundStickerSets(int hash_, std::vector<TLObject> sets_) {}

FoundStickerSets FoundStickerSets::read(Reader reader)
{
    int hash_ = Int::read(reader);
    std::vector<TLObject> sets_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return FoundStickerSets(hash_, sets_);
}

std::string FoundStickerSets::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(hash);
    buffer += Vector<TLObject>::write(sets);
    return buffer;
}

SearchCounter::SearchCounter(TLObject filter_, int count_, std::optional<bool> inexact_) {}

SearchCounter SearchCounter::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> inexact_;
    inexact_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    int count_ = Int::read(reader);
    return SearchCounter(filter_, count_, inexact_);
}

std::string SearchCounter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= inexact ? 1 << 1 : 0;
    buffer += filter.write();
    buffer += Int::write(count);
    return buffer;
}

InactiveChats::InactiveChats(std::vector<int> dates_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

InactiveChats InactiveChats::read(Reader reader)
{
    std::vector<int> dates_ = std::get<std::vector<int>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InactiveChats(dates_, chats_, users_);
}

std::string InactiveChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(dates);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

VotesList::VotesList(int count_, std::vector<TLObject> votes_, std::vector<TLObject> users_, std::optional<std::string> next_offset_) {}

VotesList VotesList::read(Reader reader)
{
    int flags = Int::read(reader);
    int count_ = Int::read(reader);
    std::vector<TLObject> votes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<std::string> next_offset_;
    next_offset_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    return VotesList(count_, votes_, users_, next_offset_);
}

std::string VotesList::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= next_offset ? 1 << 0 : 0;
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(votes);
    buffer += Vector<TLObject>::write(users);

    if (next_offset)
        buffer += String::write(next_offset.value());
    return buffer;
}

MessageViews::MessageViews(std::vector<TLObject> views_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

MessageViews MessageViews::read(Reader reader)
{
    std::vector<TLObject> views_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return MessageViews(views_, chats_, users_);
}

std::string MessageViews::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(views);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

DiscussionMessage::DiscussionMessage(std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<int> max_id_, std::optional<int> read_inbox_max_id_, std::optional<int> read_outbox_max_id_) {}

DiscussionMessage DiscussionMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<int> max_id_;
    max_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> read_inbox_max_id_;
    read_inbox_max_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> read_outbox_max_id_;
    read_outbox_max_id_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DiscussionMessage(messages_, chats_, users_, max_id_, read_inbox_max_id_, read_outbox_max_id_);
}

std::string DiscussionMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= max_id ? 1 << 0 : 0;
    flags |= read_inbox_max_id ? 1 << 1 : 0;
    flags |= read_outbox_max_id ? 1 << 2 : 0;
    buffer += Vector<TLObject>::write(messages);

    if (max_id)
        buffer += Int::write(max_id.value());

    if (read_inbox_max_id)
        buffer += Int::write(read_inbox_max_id.value());

    if (read_outbox_max_id)
        buffer += Int::write(read_outbox_max_id.value());
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

HistoryImport::HistoryImport(long id_) {}

HistoryImport HistoryImport::read(Reader reader)
{
    long id_ = Long::read(reader);
    return HistoryImport(id_);
}

std::string HistoryImport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

HistoryImportParsed::HistoryImportParsed(std::optional<bool> pm_, std::optional<bool> group_, std::optional<std::string> title_) {}

HistoryImportParsed HistoryImportParsed::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pm_;
    pm_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> group_;
    group_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<std::string> title_;
    title_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return HistoryImportParsed(pm_, group_, title_);
}

std::string HistoryImportParsed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pm ? 1 << 0 : 0;
    flags |= group ? 1 << 1 : 0;
    flags |= title ? 1 << 2 : 0;

    if (title)
        buffer += String::write(title.value());
    return buffer;
}

AffectedFoundMessages::AffectedFoundMessages(int pts_, int pts_count_, int offset_, std::vector<int> messages_) {}

AffectedFoundMessages AffectedFoundMessages::read(Reader reader)
{
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    int offset_ = Int::read(reader);
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    return AffectedFoundMessages(pts_, pts_count_, offset_, messages_);
}

std::string AffectedFoundMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    buffer += Int::write(offset);
    buffer += Vector<int>::write(messages);
    return buffer;
}

ExportedChatInvites::ExportedChatInvites(int count_, std::vector<TLObject> invites_, std::vector<TLObject> users_) {}

ExportedChatInvites ExportedChatInvites::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> invites_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ExportedChatInvites(count_, invites_, users_);
}

std::string ExportedChatInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(invites);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ExportedChatInvite::ExportedChatInvite(TLObject invite_, std::vector<TLObject> users_) {}

ExportedChatInvite ExportedChatInvite::read(Reader reader)
{
    TLObject invite_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ExportedChatInvite(invite_, users_);
}

std::string ExportedChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += invite.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ExportedChatInviteReplaced::ExportedChatInviteReplaced(TLObject invite_, TLObject new_invite_, std::vector<TLObject> users_) {}

ExportedChatInviteReplaced ExportedChatInviteReplaced::read(Reader reader)
{
    TLObject invite_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_invite_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ExportedChatInviteReplaced(invite_, new_invite_, users_);
}

std::string ExportedChatInviteReplaced::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += invite.write();
    buffer += new_invite.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ChatInviteImporters::ChatInviteImporters(int count_, std::vector<TLObject> importers_, std::vector<TLObject> users_) {}

ChatInviteImporters ChatInviteImporters::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> importers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChatInviteImporters(count_, importers_, users_);
}

std::string ChatInviteImporters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(importers);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ChatAdminsWithInvites::ChatAdminsWithInvites(std::vector<TLObject> admins_, std::vector<TLObject> users_) {}

ChatAdminsWithInvites ChatAdminsWithInvites::read(Reader reader)
{
    std::vector<TLObject> admins_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChatAdminsWithInvites(admins_, users_);
}

std::string ChatAdminsWithInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(admins);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

CheckedHistoryImportPeer::CheckedHistoryImportPeer(std::string confirm_text_) {}

CheckedHistoryImportPeer CheckedHistoryImportPeer::read(Reader reader)
{
    std::string confirm_text_ = String::read(reader);
    return CheckedHistoryImportPeer(confirm_text_);
}

std::string CheckedHistoryImportPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(confirm_text);
    return buffer;
}
