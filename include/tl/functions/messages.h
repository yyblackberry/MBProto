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

#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class GetMessages : public TLObject
{
private:
    int __id = 0x63c66506;

public:
    std::vector<TLObject> id;
    GetMessages(std::vector<TLObject> id_);
    static GetMessages read(Reader reader);
    std::string write();
};

class GetDialogs : public TLObject
{
private:
    int __id = 0xa0ee3b73;

public:
    std::optional<bool> exclude_pinned;
    std::optional<int> folder_id;
    int offset_date;
    int offset_id;
    TLObject offset_peer;
    int limit;
    int hash;
    GetDialogs(int offset_date_, int offset_id_, TLObject offset_peer_, int limit_, int hash_, std::optional<bool> exclude_pinned_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt);
    static GetDialogs read(Reader reader);
    std::string write();
};

class GetHistory : public TLObject
{
private:
    int __id = 0xdcbb8260;

public:
    TLObject peer;
    int offset_id;
    int offset_date;
    int add_offset;
    int limit;
    int max_id;
    int min_id;
    int hash;
    GetHistory(TLObject peer_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_);
    static GetHistory read(Reader reader);
    std::string write();
};

class Search : public TLObject
{
private:
    int __id = 0xc352eec;

public:
    TLObject peer;
    std::string q;
    std::optional<TLObject> from_id;
    std::optional<int> top_msg_id;
    TLObject filter;
    int min_date;
    int max_date;
    int offset_id;
    int add_offset;
    int limit;
    int max_id;
    int min_id;
    int hash;
    Search(TLObject peer_, std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_, std::optional<TLObject> from_id_ = std::nullopt, std::optional<int> top_msg_id_ = std::nullopt);
    static Search read(Reader reader);
    std::string write();
};

class ReadHistory : public TLObject
{
private:
    int __id = 0xe306d3a;

public:
    TLObject peer;
    int max_id;
    ReadHistory(TLObject peer_, int max_id_);
    static ReadHistory read(Reader reader);
    std::string write();
};

class DeleteHistory : public TLObject
{
private:
    int __id = 0x1c015b09;

public:
    std::optional<bool> just_clear;
    std::optional<bool> revoke;
    TLObject peer;
    int max_id;
    DeleteHistory(TLObject peer_, int max_id_, std::optional<bool> just_clear_ = std::nullopt, std::optional<bool> revoke_ = std::nullopt);
    static DeleteHistory read(Reader reader);
    std::string write();
};

class DeleteMessages : public TLObject
{
private:
    int __id = 0xe58e95d2;

public:
    std::optional<bool> revoke;
    std::vector<int> id;
    DeleteMessages(std::vector<int> id_, std::optional<bool> revoke_ = std::nullopt);
    static DeleteMessages read(Reader reader);
    std::string write();
};

class ReceivedMessages : public TLObject
{
private:
    int __id = 0x5a954c0;

public:
    int max_id;
    ReceivedMessages(int max_id_);
    static ReceivedMessages read(Reader reader);
    std::string write();
};

class SetTyping : public TLObject
{
private:
    int __id = 0x58943ee2;

public:
    TLObject peer;
    std::optional<int> top_msg_id;
    TLObject action;
    SetTyping(TLObject peer_, TLObject action_, std::optional<int> top_msg_id_ = std::nullopt);
    static SetTyping read(Reader reader);
    std::string write();
};

class SendMessage : public TLObject
{
private:
    int __id = 0x520c3870;

public:
    std::optional<bool> no_webpage;
    std::optional<bool> silent;
    std::optional<bool> background;
    std::optional<bool> clear_draft;
    TLObject peer;
    std::optional<int> reply_to_msg_id;
    std::string message;
    long random_id;
    std::optional<TLObject> reply_markup;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> schedule_date;
    SendMessage(TLObject peer_, std::string message_, long random_id_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<bool> background_ = std::nullopt, std::optional<bool> clear_draft_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static SendMessage read(Reader reader);
    std::string write();
};

class SendMedia : public TLObject
{
private:
    int __id = 0x3491eba9;

public:
    std::optional<bool> silent;
    std::optional<bool> background;
    std::optional<bool> clear_draft;
    TLObject peer;
    std::optional<int> reply_to_msg_id;
    TLObject media;
    std::string message;
    long random_id;
    std::optional<TLObject> reply_markup;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> schedule_date;
    SendMedia(TLObject peer_, TLObject media_, std::string message_, long random_id_, std::optional<bool> silent_ = std::nullopt, std::optional<bool> background_ = std::nullopt, std::optional<bool> clear_draft_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static SendMedia read(Reader reader);
    std::string write();
};

class ForwardMessages : public TLObject
{
private:
    int __id = 0xd9fee60e;

public:
    std::optional<bool> silent;
    std::optional<bool> background;
    std::optional<bool> with_my_score;
    TLObject from_peer;
    std::vector<int> id;
    std::vector<long> random_id;
    TLObject to_peer;
    std::optional<int> schedule_date;
    ForwardMessages(TLObject from_peer_, std::vector<int> id_, std::vector<long> random_id_, TLObject to_peer_, std::optional<bool> silent_ = std::nullopt, std::optional<bool> background_ = std::nullopt, std::optional<bool> with_my_score_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static ForwardMessages read(Reader reader);
    std::string write();
};

class ReportSpam : public TLObject
{
private:
    int __id = 0xcf1592db;

public:
    TLObject peer;
    ReportSpam(TLObject peer_);
    static ReportSpam read(Reader reader);
    std::string write();
};

class GetPeerSettings : public TLObject
{
private:
    int __id = 0x3672e09c;

public:
    TLObject peer;
    GetPeerSettings(TLObject peer_);
    static GetPeerSettings read(Reader reader);
    std::string write();
};

class Report : public TLObject
{
private:
    int __id = 0x8953ab4e;

public:
    TLObject peer;
    std::vector<int> id;
    TLObject reason;
    std::string message;
    Report(TLObject peer_, std::vector<int> id_, TLObject reason_, std::string message_);
    static Report read(Reader reader);
    std::string write();
};

class GetChats : public TLObject
{
private:
    int __id = 0x3c6aa187;

public:
    std::vector<int> id;
    GetChats(std::vector<int> id_);
    static GetChats read(Reader reader);
    std::string write();
};

class GetFullChat : public TLObject
{
private:
    int __id = 0x3b831c66;

public:
    int chat_id;
    GetFullChat(int chat_id_);
    static GetFullChat read(Reader reader);
    std::string write();
};

class EditChatTitle : public TLObject
{
private:
    int __id = 0xdc452855;

public:
    int chat_id;
    std::string title;
    EditChatTitle(int chat_id_, std::string title_);
    static EditChatTitle read(Reader reader);
    std::string write();
};

class EditChatPhoto : public TLObject
{
private:
    int __id = 0xca4c79d8;

public:
    int chat_id;
    TLObject photo;
    EditChatPhoto(int chat_id_, TLObject photo_);
    static EditChatPhoto read(Reader reader);
    std::string write();
};

class AddChatUser : public TLObject
{
private:
    int __id = 0xf9a0aa09;

public:
    int chat_id;
    TLObject user_id;
    int fwd_limit;
    AddChatUser(int chat_id_, TLObject user_id_, int fwd_limit_);
    static AddChatUser read(Reader reader);
    std::string write();
};

class DeleteChatUser : public TLObject
{
private:
    int __id = 0xc534459a;

public:
    std::optional<bool> revoke_history;
    int chat_id;
    TLObject user_id;
    DeleteChatUser(int chat_id_, TLObject user_id_, std::optional<bool> revoke_history_ = std::nullopt);
    static DeleteChatUser read(Reader reader);
    std::string write();
};

class CreateChat : public TLObject
{
private:
    int __id = 0x9cb126e;

public:
    std::vector<TLObject> users;
    std::string title;
    CreateChat(std::vector<TLObject> users_, std::string title_);
    static CreateChat read(Reader reader);
    std::string write();
};

class GetDhConfig : public TLObject
{
private:
    int __id = 0x26cf8950;

public:
    int version;
    int random_length;
    GetDhConfig(int version_, int random_length_);
    static GetDhConfig read(Reader reader);
    std::string write();
};

class RequestEncryption : public TLObject
{
private:
    int __id = 0xf64daf43;

public:
    TLObject user_id;
    int random_id;
    std::string g_a;
    RequestEncryption(TLObject user_id_, int random_id_, std::string g_a_);
    static RequestEncryption read(Reader reader);
    std::string write();
};

class AcceptEncryption : public TLObject
{
private:
    int __id = 0x3dbc0415;

public:
    TLObject peer;
    std::string g_b;
    long key_fingerprint;
    AcceptEncryption(TLObject peer_, std::string g_b_, long key_fingerprint_);
    static AcceptEncryption read(Reader reader);
    std::string write();
};

class DiscardEncryption : public TLObject
{
private:
    int __id = 0xf393aea0;

public:
    std::optional<bool> delete_history;
    int chat_id;
    DiscardEncryption(int chat_id_, std::optional<bool> delete_history_ = std::nullopt);
    static DiscardEncryption read(Reader reader);
    std::string write();
};

class SetEncryptedTyping : public TLObject
{
private:
    int __id = 0x791451ed;

public:
    TLObject peer;
    bool typing;
    SetEncryptedTyping(TLObject peer_, bool typing_);
    static SetEncryptedTyping read(Reader reader);
    std::string write();
};

class ReadEncryptedHistory : public TLObject
{
private:
    int __id = 0x7f4b690a;

public:
    TLObject peer;
    int max_date;
    ReadEncryptedHistory(TLObject peer_, int max_date_);
    static ReadEncryptedHistory read(Reader reader);
    std::string write();
};

class SendEncrypted : public TLObject
{
private:
    int __id = 0x44fa7a15;

public:
    std::optional<bool> silent;
    TLObject peer;
    long random_id;
    std::string data;
    SendEncrypted(TLObject peer_, long random_id_, std::string data_, std::optional<bool> silent_ = std::nullopt);
    static SendEncrypted read(Reader reader);
    std::string write();
};

class SendEncryptedFile : public TLObject
{
private:
    int __id = 0x5559481d;

public:
    std::optional<bool> silent;
    TLObject peer;
    long random_id;
    std::string data;
    TLObject file;
    SendEncryptedFile(TLObject peer_, long random_id_, std::string data_, TLObject file_, std::optional<bool> silent_ = std::nullopt);
    static SendEncryptedFile read(Reader reader);
    std::string write();
};

class SendEncryptedService : public TLObject
{
private:
    int __id = 0x32d439a4;

public:
    TLObject peer;
    long random_id;
    std::string data;
    SendEncryptedService(TLObject peer_, long random_id_, std::string data_);
    static SendEncryptedService read(Reader reader);
    std::string write();
};

class ReceivedQueue : public TLObject
{
private:
    int __id = 0x55a5bb66;

public:
    int max_qts;
    ReceivedQueue(int max_qts_);
    static ReceivedQueue read(Reader reader);
    std::string write();
};

class ReportEncryptedSpam : public TLObject
{
private:
    int __id = 0x4b0c8c0f;

public:
    TLObject peer;
    ReportEncryptedSpam(TLObject peer_);
    static ReportEncryptedSpam read(Reader reader);
    std::string write();
};

class ReadMessageContents : public TLObject
{
private:
    int __id = 0x36a73f77;

public:
    std::vector<int> id;
    ReadMessageContents(std::vector<int> id_);
    static ReadMessageContents read(Reader reader);
    std::string write();
};

class GetStickers : public TLObject
{
private:
    int __id = 0x43d4f2c;

public:
    std::string emoticon;
    int hash;
    GetStickers(std::string emoticon_, int hash_);
    static GetStickers read(Reader reader);
    std::string write();
};

class GetAllStickers : public TLObject
{
private:
    int __id = 0x1c9618b1;

public:
    int hash;
    GetAllStickers(int hash_);
    static GetAllStickers read(Reader reader);
    std::string write();
};

class GetWebPagePreview : public TLObject
{
private:
    int __id = 0x8b68b0cc;

public:
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    GetWebPagePreview(std::string message_, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static GetWebPagePreview read(Reader reader);
    std::string write();
};

class ExportChatInvite : public TLObject
{
private:
    int __id = 0x14b9bcd7;

public:
    std::optional<bool> legacy_revoke_permanent;
    TLObject peer;
    std::optional<int> expire_date;
    std::optional<int> usage_limit;
    ExportChatInvite(TLObject peer_, std::optional<bool> legacy_revoke_permanent_ = std::nullopt, std::optional<int> expire_date_ = std::nullopt, std::optional<int> usage_limit_ = std::nullopt);
    static ExportChatInvite read(Reader reader);
    std::string write();
};

class CheckChatInvite : public TLObject
{
private:
    int __id = 0x3eadb1bb;

public:
    std::string hash;
    CheckChatInvite(std::string hash_);
    static CheckChatInvite read(Reader reader);
    std::string write();
};

class ImportChatInvite : public TLObject
{
private:
    int __id = 0x6c50051c;

public:
    std::string hash;
    ImportChatInvite(std::string hash_);
    static ImportChatInvite read(Reader reader);
    std::string write();
};

class GetStickerSet : public TLObject
{
private:
    int __id = 0x2619a90e;

public:
    TLObject stickerset;
    GetStickerSet(TLObject stickerset_);
    static GetStickerSet read(Reader reader);
    std::string write();
};

class InstallStickerSet : public TLObject
{
private:
    int __id = 0xc78fe460;

public:
    TLObject stickerset;
    bool archived;
    InstallStickerSet(TLObject stickerset_, bool archived_);
    static InstallStickerSet read(Reader reader);
    std::string write();
};

class UninstallStickerSet : public TLObject
{
private:
    int __id = 0xf96e55de;

public:
    TLObject stickerset;
    UninstallStickerSet(TLObject stickerset_);
    static UninstallStickerSet read(Reader reader);
    std::string write();
};

class StartBot : public TLObject
{
private:
    int __id = 0xe6df7378;

public:
    TLObject bot;
    TLObject peer;
    long random_id;
    std::string start_param;
    StartBot(TLObject bot_, TLObject peer_, long random_id_, std::string start_param_);
    static StartBot read(Reader reader);
    std::string write();
};

class GetMessagesViews : public TLObject
{
private:
    int __id = 0x5784d3e1;

public:
    TLObject peer;
    std::vector<int> id;
    bool increment;
    GetMessagesViews(TLObject peer_, std::vector<int> id_, bool increment_);
    static GetMessagesViews read(Reader reader);
    std::string write();
};

class EditChatAdmin : public TLObject
{
private:
    int __id = 0xa9e69f2e;

public:
    int chat_id;
    TLObject user_id;
    bool is_admin;
    EditChatAdmin(int chat_id_, TLObject user_id_, bool is_admin_);
    static EditChatAdmin read(Reader reader);
    std::string write();
};

class MigrateChat : public TLObject
{
private:
    int __id = 0x15a3b8e3;

public:
    int chat_id;
    MigrateChat(int chat_id_);
    static MigrateChat read(Reader reader);
    std::string write();
};

class SearchGlobal : public TLObject
{
private:
    int __id = 0x4bc6589a;

public:
    std::optional<int> folder_id;
    std::string q;
    TLObject filter;
    int min_date;
    int max_date;
    int offset_rate;
    TLObject offset_peer;
    int offset_id;
    int limit;
    SearchGlobal(std::string q_, TLObject filter_, int min_date_, int max_date_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_, std::optional<int> folder_id_ = std::nullopt);
    static SearchGlobal read(Reader reader);
    std::string write();
};

class ReorderStickerSets : public TLObject
{
private:
    int __id = 0x78337739;

public:
    std::optional<bool> masks;
    std::vector<long> order;
    ReorderStickerSets(std::vector<long> order_, std::optional<bool> masks_ = std::nullopt);
    static ReorderStickerSets read(Reader reader);
    std::string write();
};

class GetDocumentByHash : public TLObject
{
private:
    int __id = 0x338e2464;

public:
    std::string sha256;
    int size;
    std::string mime_type;
    GetDocumentByHash(std::string sha256_, int size_, std::string mime_type_);
    static GetDocumentByHash read(Reader reader);
    std::string write();
};

class GetSavedGifs : public TLObject
{
private:
    int __id = 0x83bf3d52;

public:
    int hash;
    GetSavedGifs(int hash_);
    static GetSavedGifs read(Reader reader);
    std::string write();
};

class SaveGif : public TLObject
{
private:
    int __id = 0x327a30cb;

public:
    TLObject id;
    bool unsave;
    SaveGif(TLObject id_, bool unsave_);
    static SaveGif read(Reader reader);
    std::string write();
};

class GetInlineBotResults : public TLObject
{
private:
    int __id = 0x514e999d;

public:
    TLObject bot;
    TLObject peer;
    std::optional<TLObject> geo_point;
    std::string query;
    std::string offset;
    GetInlineBotResults(TLObject bot_, TLObject peer_, std::string query_, std::string offset_, std::optional<TLObject> geo_point_ = std::nullopt);
    static GetInlineBotResults read(Reader reader);
    std::string write();
};

class SetInlineBotResults : public TLObject
{
private:
    int __id = 0xeb5ea206;

public:
    std::optional<bool> gallery;
    std::optional<bool> private;
    long query_id;
    std::vector<TLObject> results;
    int cache_time;
    std::optional<std::string> next_offset;
    std::optional<TLObject> switch_pm;
    SetInlineBotResults(long query_id_, std::vector<TLObject> results_, int cache_time_, std::optional<bool> gallery_ = std::nullopt, std::optional<bool> private_ = std::nullopt, std::optional<std::string> next_offset_ = std::nullopt, std::optional<TLObject> switch_pm_ = std::nullopt);
    static SetInlineBotResults read(Reader reader);
    std::string write();
};

class SendInlineBotResult : public TLObject
{
private:
    int __id = 0x220815b0;

public:
    std::optional<bool> silent;
    std::optional<bool> background;
    std::optional<bool> clear_draft;
    std::optional<bool> hide_via;
    TLObject peer;
    std::optional<int> reply_to_msg_id;
    long random_id;
    long query_id;
    std::string id;
    std::optional<int> schedule_date;
    SendInlineBotResult(TLObject peer_, long random_id_, long query_id_, std::string id_, std::optional<bool> silent_ = std::nullopt, std::optional<bool> background_ = std::nullopt, std::optional<bool> clear_draft_ = std::nullopt, std::optional<bool> hide_via_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static SendInlineBotResult read(Reader reader);
    std::string write();
};

class GetMessageEditData : public TLObject
{
private:
    int __id = 0xfda68d36;

public:
    TLObject peer;
    int id;
    GetMessageEditData(TLObject peer_, int id_);
    static GetMessageEditData read(Reader reader);
    std::string write();
};

class EditMessage : public TLObject
{
private:
    int __id = 0x48f71778;

public:
    std::optional<bool> no_webpage;
    TLObject peer;
    int id;
    std::optional<std::string> message;
    std::optional<TLObject> media;
    std::optional<TLObject> reply_markup;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> schedule_date;
    EditMessage(TLObject peer_, int id_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<std::string> message_ = std::nullopt, std::optional<TLObject> media_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static EditMessage read(Reader reader);
    std::string write();
};

class EditInlineBotMessage : public TLObject
{
private:
    int __id = 0x83557dba;

public:
    std::optional<bool> no_webpage;
    TLObject id;
    std::optional<std::string> message;
    std::optional<TLObject> media;
    std::optional<TLObject> reply_markup;
    std::optional<std::vector<TLObject>> entities;
    EditInlineBotMessage(TLObject id_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<std::string> message_ = std::nullopt, std::optional<TLObject> media_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static EditInlineBotMessage read(Reader reader);
    std::string write();
};

class GetBotCallbackAnswer : public TLObject
{
private:
    int __id = 0x9342ca07;

public:
    std::optional<bool> game;
    TLObject peer;
    int msg_id;
    std::optional<std::string> data;
    std::optional<TLObject> password;
    GetBotCallbackAnswer(TLObject peer_, int msg_id_, std::optional<bool> game_ = std::nullopt, std::optional<std::string> data_ = std::nullopt, std::optional<TLObject> password_ = std::nullopt);
    static GetBotCallbackAnswer read(Reader reader);
    std::string write();
};

class SetBotCallbackAnswer : public TLObject
{
private:
    int __id = 0xd58f130a;

public:
    std::optional<bool> alert;
    long query_id;
    std::optional<std::string> message;
    std::optional<std::string> url;
    int cache_time;
    SetBotCallbackAnswer(long query_id_, int cache_time_, std::optional<bool> alert_ = std::nullopt, std::optional<std::string> message_ = std::nullopt, std::optional<std::string> url_ = std::nullopt);
    static SetBotCallbackAnswer read(Reader reader);
    std::string write();
};

class GetPeerDialogs : public TLObject
{
private:
    int __id = 0xe470bcfd;

public:
    std::vector<TLObject> peers;
    GetPeerDialogs(std::vector<TLObject> peers_);
    static GetPeerDialogs read(Reader reader);
    std::string write();
};

class SaveDraft : public TLObject
{
private:
    int __id = 0xbc39e14b;

public:
    std::optional<bool> no_webpage;
    std::optional<int> reply_to_msg_id;
    TLObject peer;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    SaveDraft(TLObject peer_, std::string message_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static SaveDraft read(Reader reader);
    std::string write();
};

class GetAllDrafts : public TLObject
{
private:
    int __id = 0x6a3f8d65;

public:
    GetAllDrafts() = default;
    static GetAllDrafts read(Reader reader);
    std::string write();
};

class GetFeaturedStickers : public TLObject
{
private:
    int __id = 0x2dacca4f;

public:
    int hash;
    GetFeaturedStickers(int hash_);
    static GetFeaturedStickers read(Reader reader);
    std::string write();
};

class ReadFeaturedStickers : public TLObject
{
private:
    int __id = 0x5b118126;

public:
    std::vector<long> id;
    ReadFeaturedStickers(std::vector<long> id_);
    static ReadFeaturedStickers read(Reader reader);
    std::string write();
};

class GetRecentStickers : public TLObject
{
private:
    int __id = 0x5ea192c9;

public:
    std::optional<bool> attached;
    int hash;
    GetRecentStickers(int hash_, std::optional<bool> attached_ = std::nullopt);
    static GetRecentStickers read(Reader reader);
    std::string write();
};

class SaveRecentSticker : public TLObject
{
private:
    int __id = 0x392718f8;

public:
    std::optional<bool> attached;
    TLObject id;
    bool unsave;
    SaveRecentSticker(TLObject id_, bool unsave_, std::optional<bool> attached_ = std::nullopt);
    static SaveRecentSticker read(Reader reader);
    std::string write();
};

class ClearRecentStickers : public TLObject
{
private:
    int __id = 0x8999602d;

public:
    std::optional<bool> attached;
    ClearRecentStickers(std::optional<bool> attached_ = std::nullopt);
    static ClearRecentStickers read(Reader reader);
    std::string write();
};

class GetArchivedStickers : public TLObject
{
private:
    int __id = 0x57f17692;

public:
    std::optional<bool> masks;
    long offset_id;
    int limit;
    GetArchivedStickers(long offset_id_, int limit_, std::optional<bool> masks_ = std::nullopt);
    static GetArchivedStickers read(Reader reader);
    std::string write();
};

class GetMaskStickers : public TLObject
{
private:
    int __id = 0x65b8c79f;

public:
    int hash;
    GetMaskStickers(int hash_);
    static GetMaskStickers read(Reader reader);
    std::string write();
};

class GetAttachedStickers : public TLObject
{
private:
    int __id = 0xcc5b67cc;

public:
    TLObject media;
    GetAttachedStickers(TLObject media_);
    static GetAttachedStickers read(Reader reader);
    std::string write();
};

class SetGameScore : public TLObject
{
private:
    int __id = 0x8ef8ecc0;

public:
    std::optional<bool> edit_message;
    std::optional<bool> force;
    TLObject peer;
    int id;
    TLObject user_id;
    int score;
    SetGameScore(TLObject peer_, int id_, TLObject user_id_, int score_, std::optional<bool> edit_message_ = std::nullopt, std::optional<bool> force_ = std::nullopt);
    static SetGameScore read(Reader reader);
    std::string write();
};

class SetInlineGameScore : public TLObject
{
private:
    int __id = 0x15ad9f64;

public:
    std::optional<bool> edit_message;
    std::optional<bool> force;
    TLObject id;
    TLObject user_id;
    int score;
    SetInlineGameScore(TLObject id_, TLObject user_id_, int score_, std::optional<bool> edit_message_ = std::nullopt, std::optional<bool> force_ = std::nullopt);
    static SetInlineGameScore read(Reader reader);
    std::string write();
};

class GetGameHighScores : public TLObject
{
private:
    int __id = 0xe822649d;

public:
    TLObject peer;
    int id;
    TLObject user_id;
    GetGameHighScores(TLObject peer_, int id_, TLObject user_id_);
    static GetGameHighScores read(Reader reader);
    std::string write();
};

class GetInlineGameHighScores : public TLObject
{
private:
    int __id = 0xf635e1b;

public:
    TLObject id;
    TLObject user_id;
    GetInlineGameHighScores(TLObject id_, TLObject user_id_);
    static GetInlineGameHighScores read(Reader reader);
    std::string write();
};

class GetCommonChats : public TLObject
{
private:
    int __id = 0xd0a48c4;

public:
    TLObject user_id;
    int max_id;
    int limit;
    GetCommonChats(TLObject user_id_, int max_id_, int limit_);
    static GetCommonChats read(Reader reader);
    std::string write();
};

class GetAllChats : public TLObject
{
private:
    int __id = 0xeba80ff0;

public:
    std::vector<int> except_ids;
    GetAllChats(std::vector<int> except_ids_);
    static GetAllChats read(Reader reader);
    std::string write();
};

class GetWebPage : public TLObject
{
private:
    int __id = 0x32ca8f91;

public:
    std::string url;
    int hash;
    GetWebPage(std::string url_, int hash_);
    static GetWebPage read(Reader reader);
    std::string write();
};

class ToggleDialogPin : public TLObject
{
private:
    int __id = 0xa731e257;

public:
    std::optional<bool> pinned;
    TLObject peer;
    ToggleDialogPin(TLObject peer_, std::optional<bool> pinned_ = std::nullopt);
    static ToggleDialogPin read(Reader reader);
    std::string write();
};

class ReorderPinnedDialogs : public TLObject
{
private:
    int __id = 0x3b1adf37;

public:
    std::optional<bool> force;
    int folder_id;
    std::vector<TLObject> order;
    ReorderPinnedDialogs(int folder_id_, std::vector<TLObject> order_, std::optional<bool> force_ = std::nullopt);
    static ReorderPinnedDialogs read(Reader reader);
    std::string write();
};

class GetPinnedDialogs : public TLObject
{
private:
    int __id = 0xd6b94df2;

public:
    int folder_id;
    GetPinnedDialogs(int folder_id_);
    static GetPinnedDialogs read(Reader reader);
    std::string write();
};

class SetBotShippingResults : public TLObject
{
private:
    int __id = 0xe5f672fa;

public:
    long query_id;
    std::optional<std::string> error;
    std::optional<std::vector<TLObject>> shipping_options;
    SetBotShippingResults(long query_id_, std::optional<std::string> error_ = std::nullopt, std::optional<std::vector<TLObject>> shipping_options_ = std::nullopt);
    static SetBotShippingResults read(Reader reader);
    std::string write();
};

class SetBotPrecheckoutResults : public TLObject
{
private:
    int __id = 0x9c2dd95;

public:
    std::optional<bool> success;
    long query_id;
    std::optional<std::string> error;
    SetBotPrecheckoutResults(long query_id_, std::optional<bool> success_ = std::nullopt, std::optional<std::string> error_ = std::nullopt);
    static SetBotPrecheckoutResults read(Reader reader);
    std::string write();
};

class UploadMedia : public TLObject
{
private:
    int __id = 0x519bc2b1;

public:
    TLObject peer;
    TLObject media;
    UploadMedia(TLObject peer_, TLObject media_);
    static UploadMedia read(Reader reader);
    std::string write();
};

class SendScreenshotNotification : public TLObject
{
private:
    int __id = 0xc97df020;

public:
    TLObject peer;
    int reply_to_msg_id;
    long random_id;
    SendScreenshotNotification(TLObject peer_, int reply_to_msg_id_, long random_id_);
    static SendScreenshotNotification read(Reader reader);
    std::string write();
};

class GetFavedStickers : public TLObject
{
private:
    int __id = 0x21ce0b0e;

public:
    int hash;
    GetFavedStickers(int hash_);
    static GetFavedStickers read(Reader reader);
    std::string write();
};

class FaveSticker : public TLObject
{
private:
    int __id = 0xb9ffc55b;

public:
    TLObject id;
    bool unfave;
    FaveSticker(TLObject id_, bool unfave_);
    static FaveSticker read(Reader reader);
    std::string write();
};

class GetUnreadMentions : public TLObject
{
private:
    int __id = 0x46578472;

public:
    TLObject peer;
    int offset_id;
    int add_offset;
    int limit;
    int max_id;
    int min_id;
    GetUnreadMentions(TLObject peer_, int offset_id_, int add_offset_, int limit_, int max_id_, int min_id_);
    static GetUnreadMentions read(Reader reader);
    std::string write();
};

class ReadMentions : public TLObject
{
private:
    int __id = 0xf0189d3;

public:
    TLObject peer;
    ReadMentions(TLObject peer_);
    static ReadMentions read(Reader reader);
    std::string write();
};

class GetRecentLocations : public TLObject
{
private:
    int __id = 0xbbc45b09;

public:
    TLObject peer;
    int limit;
    int hash;
    GetRecentLocations(TLObject peer_, int limit_, int hash_);
    static GetRecentLocations read(Reader reader);
    std::string write();
};

class SendMultiMedia : public TLObject
{
private:
    int __id = 0xcc0110cb;

public:
    std::optional<bool> silent;
    std::optional<bool> background;
    std::optional<bool> clear_draft;
    TLObject peer;
    std::optional<int> reply_to_msg_id;
    std::vector<TLObject> multi_media;
    std::optional<int> schedule_date;
    SendMultiMedia(TLObject peer_, std::vector<TLObject> multi_media_, std::optional<bool> silent_ = std::nullopt, std::optional<bool> background_ = std::nullopt, std::optional<bool> clear_draft_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static SendMultiMedia read(Reader reader);
    std::string write();
};

class UploadEncryptedFile : public TLObject
{
private:
    int __id = 0x5057c497;

public:
    TLObject peer;
    TLObject file;
    UploadEncryptedFile(TLObject peer_, TLObject file_);
    static UploadEncryptedFile read(Reader reader);
    std::string write();
};

class SearchStickerSets : public TLObject
{
private:
    int __id = 0xc2b7d08b;

public:
    std::optional<bool> exclude_featured;
    std::string q;
    int hash;
    SearchStickerSets(std::string q_, int hash_, std::optional<bool> exclude_featured_ = std::nullopt);
    static SearchStickerSets read(Reader reader);
    std::string write();
};

class GetSplitRanges : public TLObject
{
private:
    int __id = 0x1cff7e08;

public:
    GetSplitRanges() = default;
    static GetSplitRanges read(Reader reader);
    std::string write();
};

class MarkDialogUnread : public TLObject
{
private:
    int __id = 0xc286d98f;

public:
    std::optional<bool> unread;
    TLObject peer;
    MarkDialogUnread(TLObject peer_, std::optional<bool> unread_ = std::nullopt);
    static MarkDialogUnread read(Reader reader);
    std::string write();
};

class GetDialogUnreadMarks : public TLObject
{
private:
    int __id = 0x22e24e22;

public:
    GetDialogUnreadMarks() = default;
    static GetDialogUnreadMarks read(Reader reader);
    std::string write();
};

class ClearAllDrafts : public TLObject
{
private:
    int __id = 0x7e58ee9c;

public:
    ClearAllDrafts() = default;
    static ClearAllDrafts read(Reader reader);
    std::string write();
};

class UpdatePinnedMessage : public TLObject
{
private:
    int __id = 0xd2aaf7ec;

public:
    std::optional<bool> silent;
    std::optional<bool> unpin;
    std::optional<bool> pm_oneside;
    TLObject peer;
    int id;
    UpdatePinnedMessage(TLObject peer_, int id_, std::optional<bool> silent_ = std::nullopt, std::optional<bool> unpin_ = std::nullopt, std::optional<bool> pm_oneside_ = std::nullopt);
    static UpdatePinnedMessage read(Reader reader);
    std::string write();
};

class SendVote : public TLObject
{
private:
    int __id = 0x10ea6184;

public:
    TLObject peer;
    int msg_id;
    std::vector<std::string> options;
    SendVote(TLObject peer_, int msg_id_, std::vector<std::string> options_);
    static SendVote read(Reader reader);
    std::string write();
};

class GetPollResults : public TLObject
{
private:
    int __id = 0x73bb643b;

public:
    TLObject peer;
    int msg_id;
    GetPollResults(TLObject peer_, int msg_id_);
    static GetPollResults read(Reader reader);
    std::string write();
};

class GetOnlines : public TLObject
{
private:
    int __id = 0x6e2be050;

public:
    TLObject peer;
    GetOnlines(TLObject peer_);
    static GetOnlines read(Reader reader);
    std::string write();
};

class GetStatsURL : public TLObject
{
private:
    int __id = 0x812c2ae6;

public:
    std::optional<bool> dark;
    TLObject peer;
    std::string params;
    GetStatsURL(TLObject peer_, std::string params_, std::optional<bool> dark_ = std::nullopt);
    static GetStatsURL read(Reader reader);
    std::string write();
};

class EditChatAbout : public TLObject
{
private:
    int __id = 0xdef60797;

public:
    TLObject peer;
    std::string about;
    EditChatAbout(TLObject peer_, std::string about_);
    static EditChatAbout read(Reader reader);
    std::string write();
};

class EditChatDefaultBannedRights : public TLObject
{
private:
    int __id = 0xa5866b41;

public:
    TLObject peer;
    TLObject banned_rights;
    EditChatDefaultBannedRights(TLObject peer_, TLObject banned_rights_);
    static EditChatDefaultBannedRights read(Reader reader);
    std::string write();
};

class GetEmojiKeywords : public TLObject
{
private:
    int __id = 0x35a0e062;

public:
    std::string lang_code;
    GetEmojiKeywords(std::string lang_code_);
    static GetEmojiKeywords read(Reader reader);
    std::string write();
};

class GetEmojiKeywordsDifference : public TLObject
{
private:
    int __id = 0x1508b6af;

public:
    std::string lang_code;
    int from_version;
    GetEmojiKeywordsDifference(std::string lang_code_, int from_version_);
    static GetEmojiKeywordsDifference read(Reader reader);
    std::string write();
};

class GetEmojiKeywordsLanguages : public TLObject
{
private:
    int __id = 0x4e9963b2;

public:
    std::vector<std::string> lang_codes;
    GetEmojiKeywordsLanguages(std::vector<std::string> lang_codes_);
    static GetEmojiKeywordsLanguages read(Reader reader);
    std::string write();
};

class GetEmojiURL : public TLObject
{
private:
    int __id = 0xd5b10c26;

public:
    std::string lang_code;
    GetEmojiURL(std::string lang_code_);
    static GetEmojiURL read(Reader reader);
    std::string write();
};

class GetSearchCounters : public TLObject
{
private:
    int __id = 0x732eef00;

public:
    TLObject peer;
    std::vector<TLObject> filters;
    GetSearchCounters(TLObject peer_, std::vector<TLObject> filters_);
    static GetSearchCounters read(Reader reader);
    std::string write();
};

class RequestUrlAuth : public TLObject
{
private:
    int __id = 0x198fb446;

public:
    std::optional<TLObject> peer;
    std::optional<int> msg_id;
    std::optional<int> button_id;
    std::optional<std::string> url;
    RequestUrlAuth(std::optional<TLObject> peer_ = std::nullopt, std::optional<int> msg_id_ = std::nullopt, std::optional<int> button_id_ = std::nullopt, std::optional<std::string> url_ = std::nullopt);
    static RequestUrlAuth read(Reader reader);
    std::string write();
};

class AcceptUrlAuth : public TLObject
{
private:
    int __id = 0xb12c7125;

public:
    std::optional<bool> write_allowed;
    std::optional<TLObject> peer;
    std::optional<int> msg_id;
    std::optional<int> button_id;
    std::optional<std::string> url;
    AcceptUrlAuth(std::optional<bool> write_allowed_ = std::nullopt, std::optional<TLObject> peer_ = std::nullopt, std::optional<int> msg_id_ = std::nullopt, std::optional<int> button_id_ = std::nullopt, std::optional<std::string> url_ = std::nullopt);
    static AcceptUrlAuth read(Reader reader);
    std::string write();
};

class HidePeerSettingsBar : public TLObject
{
private:
    int __id = 0x4facb138;

public:
    TLObject peer;
    HidePeerSettingsBar(TLObject peer_);
    static HidePeerSettingsBar read(Reader reader);
    std::string write();
};

class GetScheduledHistory : public TLObject
{
private:
    int __id = 0xe2c2685b;

public:
    TLObject peer;
    int hash;
    GetScheduledHistory(TLObject peer_, int hash_);
    static GetScheduledHistory read(Reader reader);
    std::string write();
};

class GetScheduledMessages : public TLObject
{
private:
    int __id = 0xbdbb0464;

public:
    TLObject peer;
    std::vector<int> id;
    GetScheduledMessages(TLObject peer_, std::vector<int> id_);
    static GetScheduledMessages read(Reader reader);
    std::string write();
};

class SendScheduledMessages : public TLObject
{
private:
    int __id = 0xbd38850a;

public:
    TLObject peer;
    std::vector<int> id;
    SendScheduledMessages(TLObject peer_, std::vector<int> id_);
    static SendScheduledMessages read(Reader reader);
    std::string write();
};

class DeleteScheduledMessages : public TLObject
{
private:
    int __id = 0x59ae2b16;

public:
    TLObject peer;
    std::vector<int> id;
    DeleteScheduledMessages(TLObject peer_, std::vector<int> id_);
    static DeleteScheduledMessages read(Reader reader);
    std::string write();
};

class GetPollVotes : public TLObject
{
private:
    int __id = 0xb86e380e;

public:
    TLObject peer;
    int id;
    std::optional<std::string> option;
    std::optional<std::string> offset;
    int limit;
    GetPollVotes(TLObject peer_, int id_, int limit_, std::optional<std::string> option_ = std::nullopt, std::optional<std::string> offset_ = std::nullopt);
    static GetPollVotes read(Reader reader);
    std::string write();
};

class ToggleStickerSets : public TLObject
{
private:
    int __id = 0xb5052fea;

public:
    std::optional<bool> uninstall;
    std::optional<bool> archive;
    std::optional<bool> unarchive;
    std::vector<TLObject> stickersets;
    ToggleStickerSets(std::vector<TLObject> stickersets_, std::optional<bool> uninstall_ = std::nullopt, std::optional<bool> archive_ = std::nullopt, std::optional<bool> unarchive_ = std::nullopt);
    static ToggleStickerSets read(Reader reader);
    std::string write();
};

class GetDialogFilters : public TLObject
{
private:
    int __id = 0xf19ed96d;

public:
    GetDialogFilters() = default;
    static GetDialogFilters read(Reader reader);
    std::string write();
};

class GetSuggestedDialogFilters : public TLObject
{
private:
    int __id = 0xa29cd42c;

public:
    GetSuggestedDialogFilters() = default;
    static GetSuggestedDialogFilters read(Reader reader);
    std::string write();
};

class UpdateDialogFilter : public TLObject
{
private:
    int __id = 0x1ad4a04a;

public:
    int id;
    std::optional<TLObject> filter;
    UpdateDialogFilter(int id_, std::optional<TLObject> filter_ = std::nullopt);
    static UpdateDialogFilter read(Reader reader);
    std::string write();
};

class UpdateDialogFiltersOrder : public TLObject
{
private:
    int __id = 0xc563c1e4;

public:
    std::vector<int> order;
    UpdateDialogFiltersOrder(std::vector<int> order_);
    static UpdateDialogFiltersOrder read(Reader reader);
    std::string write();
};

class GetOldFeaturedStickers : public TLObject
{
private:
    int __id = 0x5fe7025b;

public:
    int offset;
    int limit;
    int hash;
    GetOldFeaturedStickers(int offset_, int limit_, int hash_);
    static GetOldFeaturedStickers read(Reader reader);
    std::string write();
};

class GetReplies : public TLObject
{
private:
    int __id = 0x24b581ba;

public:
    TLObject peer;
    int msg_id;
    int offset_id;
    int offset_date;
    int add_offset;
    int limit;
    int max_id;
    int min_id;
    int hash;
    GetReplies(TLObject peer_, int msg_id_, int offset_id_, int offset_date_, int add_offset_, int limit_, int max_id_, int min_id_, int hash_);
    static GetReplies read(Reader reader);
    std::string write();
};

class GetDiscussionMessage : public TLObject
{
private:
    int __id = 0x446972fd;

public:
    TLObject peer;
    int msg_id;
    GetDiscussionMessage(TLObject peer_, int msg_id_);
    static GetDiscussionMessage read(Reader reader);
    std::string write();
};

class ReadDiscussion : public TLObject
{
private:
    int __id = 0xf731a9f4;

public:
    TLObject peer;
    int msg_id;
    int read_max_id;
    ReadDiscussion(TLObject peer_, int msg_id_, int read_max_id_);
    static ReadDiscussion read(Reader reader);
    std::string write();
};

class UnpinAllMessages : public TLObject
{
private:
    int __id = 0xf025bc8b;

public:
    TLObject peer;
    UnpinAllMessages(TLObject peer_);
    static UnpinAllMessages read(Reader reader);
    std::string write();
};

class DeleteChat : public TLObject
{
private:
    int __id = 0x83247d11;

public:
    int chat_id;
    DeleteChat(int chat_id_);
    static DeleteChat read(Reader reader);
    std::string write();
};

class DeletePhoneCallHistory : public TLObject
{
private:
    int __id = 0xf9cbe409;

public:
    std::optional<bool> revoke;
    DeletePhoneCallHistory(std::optional<bool> revoke_ = std::nullopt);
    static DeletePhoneCallHistory read(Reader reader);
    std::string write();
};

class CheckHistoryImport : public TLObject
{
private:
    int __id = 0x43fe19f3;

public:
    std::string import_head;
    CheckHistoryImport(std::string import_head_);
    static CheckHistoryImport read(Reader reader);
    std::string write();
};

class InitHistoryImport : public TLObject
{
private:
    int __id = 0x34090c3b;

public:
    TLObject peer;
    TLObject file;
    int media_count;
    InitHistoryImport(TLObject peer_, TLObject file_, int media_count_);
    static InitHistoryImport read(Reader reader);
    std::string write();
};

class UploadImportedMedia : public TLObject
{
private:
    int __id = 0x2a862092;

public:
    TLObject peer;
    long import_id;
    std::string file_name;
    TLObject media;
    UploadImportedMedia(TLObject peer_, long import_id_, std::string file_name_, TLObject media_);
    static UploadImportedMedia read(Reader reader);
    std::string write();
};

class StartHistoryImport : public TLObject
{
private:
    int __id = 0xb43df344;

public:
    TLObject peer;
    long import_id;
    StartHistoryImport(TLObject peer_, long import_id_);
    static StartHistoryImport read(Reader reader);
    std::string write();
};

class GetExportedChatInvites : public TLObject
{
private:
    int __id = 0xa2b5a3f6;

public:
    std::optional<bool> revoked;
    TLObject peer;
    TLObject admin_id;
    std::optional<int> offset_date;
    std::optional<std::string> offset_link;
    int limit;
    GetExportedChatInvites(TLObject peer_, TLObject admin_id_, int limit_, std::optional<bool> revoked_ = std::nullopt, std::optional<int> offset_date_ = std::nullopt, std::optional<std::string> offset_link_ = std::nullopt);
    static GetExportedChatInvites read(Reader reader);
    std::string write();
};

class GetExportedChatInvite : public TLObject
{
private:
    int __id = 0x73746f5c;

public:
    TLObject peer;
    std::string link;
    GetExportedChatInvite(TLObject peer_, std::string link_);
    static GetExportedChatInvite read(Reader reader);
    std::string write();
};

class EditExportedChatInvite : public TLObject
{
private:
    int __id = 0x2e4ffbe;

public:
    std::optional<bool> revoked;
    TLObject peer;
    std::string link;
    std::optional<int> expire_date;
    std::optional<int> usage_limit;
    EditExportedChatInvite(TLObject peer_, std::string link_, std::optional<bool> revoked_ = std::nullopt, std::optional<int> expire_date_ = std::nullopt, std::optional<int> usage_limit_ = std::nullopt);
    static EditExportedChatInvite read(Reader reader);
    std::string write();
};

class DeleteRevokedExportedChatInvites : public TLObject
{
private:
    int __id = 0x56987bd5;

public:
    TLObject peer;
    TLObject admin_id;
    DeleteRevokedExportedChatInvites(TLObject peer_, TLObject admin_id_);
    static DeleteRevokedExportedChatInvites read(Reader reader);
    std::string write();
};

class DeleteExportedChatInvite : public TLObject
{
private:
    int __id = 0xd464a42b;

public:
    TLObject peer;
    std::string link;
    DeleteExportedChatInvite(TLObject peer_, std::string link_);
    static DeleteExportedChatInvite read(Reader reader);
    std::string write();
};

class GetAdminsWithInvites : public TLObject
{
private:
    int __id = 0x3920e6ef;

public:
    TLObject peer;
    GetAdminsWithInvites(TLObject peer_);
    static GetAdminsWithInvites read(Reader reader);
    std::string write();
};

class GetChatInviteImporters : public TLObject
{
private:
    int __id = 0x26fb7289;

public:
    TLObject peer;
    std::string link;
    int offset_date;
    TLObject offset_user;
    int limit;
    GetChatInviteImporters(TLObject peer_, std::string link_, int offset_date_, TLObject offset_user_, int limit_);
    static GetChatInviteImporters read(Reader reader);
    std::string write();
};

class SetHistoryTTL : public TLObject
{
private:
    int __id = 0xb80e5fe4;

public:
    TLObject peer;
    int period;
    SetHistoryTTL(TLObject peer_, int period_);
    static SetHistoryTTL read(Reader reader);
    std::string write();
};

class CheckHistoryImportPeer : public TLObject
{
private:
    int __id = 0x5dc60f03;

public:
    TLObject peer;
    CheckHistoryImportPeer(TLObject peer_);
    static CheckHistoryImportPeer read(Reader reader);
    std::string write();
};
