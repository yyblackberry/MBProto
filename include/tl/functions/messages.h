#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetMessages
{
private:
    int __id = 0x63c66506;

public:
    std::vector<TLObject> id;
    GetMessages(std::vector<TLObject> id_);
    static GetMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDialogs
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
    static GetDialogs<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetHistory
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
    static GetHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class Search
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
    static Search<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadHistory
{
private:
    int __id = 0xe306d3a;

public:
    TLObject peer;
    int max_id;
    ReadHistory(TLObject peer_, int max_id_);
    static ReadHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteHistory
{
private:
    int __id = 0x1c015b09;

public:
    std::optional<bool> just_clear;
    std::optional<bool> revoke;
    TLObject peer;
    int max_id;
    DeleteHistory(TLObject peer_, int max_id_, std::optional<bool> just_clear_ = std::nullopt, std::optional<bool> revoke_ = std::nullopt);
    static DeleteHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteMessages
{
private:
    int __id = 0xe58e95d2;

public:
    std::optional<bool> revoke;
    std::vector<int> id;
    DeleteMessages(std::vector<int> id_, std::optional<bool> revoke_ = std::nullopt);
    static DeleteMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReceivedMessages
{
private:
    int __id = 0x5a954c0;

public:
    int max_id;
    ReceivedMessages(int max_id_);
    static ReceivedMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetTyping
{
private:
    int __id = 0x58943ee2;

public:
    TLObject peer;
    std::optional<int> top_msg_id;
    TLObject action;
    SetTyping(TLObject peer_, TLObject action_, std::optional<int> top_msg_id_ = std::nullopt);
    static SetTyping<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendMessage
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
    static SendMessage<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendMedia
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
    static SendMedia<X> read(Reader reader);
    std::string write();
};

template <class X>
class ForwardMessages
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
    static ForwardMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReportSpam
{
private:
    int __id = 0xcf1592db;

public:
    TLObject peer;
    ReportSpam(TLObject peer_);
    static ReportSpam<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPeerSettings
{
private:
    int __id = 0x3672e09c;

public:
    TLObject peer;
    GetPeerSettings(TLObject peer_);
    static GetPeerSettings<X> read(Reader reader);
    std::string write();
};

template <class X>
class Report
{
private:
    int __id = 0x8953ab4e;

public:
    TLObject peer;
    std::vector<int> id;
    TLObject reason;
    std::string message;
    Report(TLObject peer_, std::vector<int> id_, TLObject reason_, std::string message_);
    static Report<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetChats
{
private:
    int __id = 0x3c6aa187;

public:
    std::vector<int> id;
    GetChats(std::vector<int> id_);
    static GetChats<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFullChat
{
private:
    int __id = 0x3b831c66;

public:
    int chat_id;
    GetFullChat(int chat_id_);
    static GetFullChat<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditChatTitle
{
private:
    int __id = 0xdc452855;

public:
    int chat_id;
    std::string title;
    EditChatTitle(int chat_id_, std::string title_);
    static EditChatTitle<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditChatPhoto
{
private:
    int __id = 0xca4c79d8;

public:
    int chat_id;
    TLObject photo;
    EditChatPhoto(int chat_id_, TLObject photo_);
    static EditChatPhoto<X> read(Reader reader);
    std::string write();
};

template <class X>
class AddChatUser
{
private:
    int __id = 0xf9a0aa09;

public:
    int chat_id;
    TLObject user_id;
    int fwd_limit;
    AddChatUser(int chat_id_, TLObject user_id_, int fwd_limit_);
    static AddChatUser<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteChatUser
{
private:
    int __id = 0xc534459a;

public:
    std::optional<bool> revoke_history;
    int chat_id;
    TLObject user_id;
    DeleteChatUser(int chat_id_, TLObject user_id_, std::optional<bool> revoke_history_ = std::nullopt);
    static DeleteChatUser<X> read(Reader reader);
    std::string write();
};

template <class X>
class CreateChat
{
private:
    int __id = 0x9cb126e;

public:
    std::vector<TLObject> users;
    std::string title;
    CreateChat(std::vector<TLObject> users_, std::string title_);
    static CreateChat<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDhConfig
{
private:
    int __id = 0x26cf8950;

public:
    int version;
    int random_length;
    GetDhConfig(int version_, int random_length_);
    static GetDhConfig<X> read(Reader reader);
    std::string write();
};

template <class X>
class RequestEncryption
{
private:
    int __id = 0xf64daf43;

public:
    TLObject user_id;
    int random_id;
    std::string g_a;
    RequestEncryption(TLObject user_id_, int random_id_, std::string g_a_);
    static RequestEncryption<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptEncryption
{
private:
    int __id = 0x3dbc0415;

public:
    TLObject peer;
    std::string g_b;
    long key_fingerprint;
    AcceptEncryption(TLObject peer_, std::string g_b_, long key_fingerprint_);
    static AcceptEncryption<X> read(Reader reader);
    std::string write();
};

template <class X>
class DiscardEncryption
{
private:
    int __id = 0xf393aea0;

public:
    std::optional<bool> delete_history;
    int chat_id;
    DiscardEncryption(int chat_id_, std::optional<bool> delete_history_ = std::nullopt);
    static DiscardEncryption<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetEncryptedTyping
{
private:
    int __id = 0x791451ed;

public:
    TLObject peer;
    bool typing;
    SetEncryptedTyping(TLObject peer_, bool typing_);
    static SetEncryptedTyping<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadEncryptedHistory
{
private:
    int __id = 0x7f4b690a;

public:
    TLObject peer;
    int max_date;
    ReadEncryptedHistory(TLObject peer_, int max_date_);
    static ReadEncryptedHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendEncrypted
{
private:
    int __id = 0x44fa7a15;

public:
    std::optional<bool> silent;
    TLObject peer;
    long random_id;
    std::string data;
    SendEncrypted(TLObject peer_, long random_id_, std::string data_, std::optional<bool> silent_ = std::nullopt);
    static SendEncrypted<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendEncryptedFile
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
    static SendEncryptedFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendEncryptedService
{
private:
    int __id = 0x32d439a4;

public:
    TLObject peer;
    long random_id;
    std::string data;
    SendEncryptedService(TLObject peer_, long random_id_, std::string data_);
    static SendEncryptedService<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReceivedQueue
{
private:
    int __id = 0x55a5bb66;

public:
    int max_qts;
    ReceivedQueue(int max_qts_);
    static ReceivedQueue<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReportEncryptedSpam
{
private:
    int __id = 0x4b0c8c0f;

public:
    TLObject peer;
    ReportEncryptedSpam(TLObject peer_);
    static ReportEncryptedSpam<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadMessageContents
{
private:
    int __id = 0x36a73f77;

public:
    std::vector<int> id;
    ReadMessageContents(std::vector<int> id_);
    static ReadMessageContents<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetStickers
{
private:
    int __id = 0x43d4f2c;

public:
    std::string emoticon;
    int hash;
    GetStickers(std::string emoticon_, int hash_);
    static GetStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAllStickers
{
private:
    int __id = 0x1c9618b1;

public:
    int hash;
    GetAllStickers(int hash_);
    static GetAllStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetWebPagePreview
{
private:
    int __id = 0x8b68b0cc;

public:
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    GetWebPagePreview(std::string message_, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static GetWebPagePreview<X> read(Reader reader);
    std::string write();
};

template <class X>
class ExportChatInvite
{
private:
    int __id = 0x14b9bcd7;

public:
    std::optional<bool> legacy_revoke_permanent;
    TLObject peer;
    std::optional<int> expire_date;
    std::optional<int> usage_limit;
    ExportChatInvite(TLObject peer_, std::optional<bool> legacy_revoke_permanent_ = std::nullopt, std::optional<int> expire_date_ = std::nullopt, std::optional<int> usage_limit_ = std::nullopt);
    static ExportChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckChatInvite
{
private:
    int __id = 0x3eadb1bb;

public:
    std::string hash;
    CheckChatInvite(std::string hash_);
    static CheckChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class ImportChatInvite
{
private:
    int __id = 0x6c50051c;

public:
    std::string hash;
    ImportChatInvite(std::string hash_);
    static ImportChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetStickerSet
{
private:
    int __id = 0x2619a90e;

public:
    TLObject stickerset;
    GetStickerSet(TLObject stickerset_);
    static GetStickerSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class InstallStickerSet
{
private:
    int __id = 0xc78fe460;

public:
    TLObject stickerset;
    bool archived;
    InstallStickerSet(TLObject stickerset_, bool archived_);
    static InstallStickerSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class UninstallStickerSet
{
private:
    int __id = 0xf96e55de;

public:
    TLObject stickerset;
    UninstallStickerSet(TLObject stickerset_);
    static UninstallStickerSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class StartBot
{
private:
    int __id = 0xe6df7378;

public:
    TLObject bot;
    TLObject peer;
    long random_id;
    std::string start_param;
    StartBot(TLObject bot_, TLObject peer_, long random_id_, std::string start_param_);
    static StartBot<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMessagesViews
{
private:
    int __id = 0x5784d3e1;

public:
    TLObject peer;
    std::vector<int> id;
    bool increment;
    GetMessagesViews(TLObject peer_, std::vector<int> id_, bool increment_);
    static GetMessagesViews<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditChatAdmin
{
private:
    int __id = 0xa9e69f2e;

public:
    int chat_id;
    TLObject user_id;
    bool is_admin;
    EditChatAdmin(int chat_id_, TLObject user_id_, bool is_admin_);
    static EditChatAdmin<X> read(Reader reader);
    std::string write();
};

template <class X>
class MigrateChat
{
private:
    int __id = 0x15a3b8e3;

public:
    int chat_id;
    MigrateChat(int chat_id_);
    static MigrateChat<X> read(Reader reader);
    std::string write();
};

template <class X>
class SearchGlobal
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
    static SearchGlobal<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReorderStickerSets
{
private:
    int __id = 0x78337739;

public:
    std::optional<bool> masks;
    std::vector<long> order;
    ReorderStickerSets(std::vector<long> order_, std::optional<bool> masks_ = std::nullopt);
    static ReorderStickerSets<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDocumentByHash
{
private:
    int __id = 0x338e2464;

public:
    std::string sha256;
    int size;
    std::string mime_type;
    GetDocumentByHash(std::string sha256_, int size_, std::string mime_type_);
    static GetDocumentByHash<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSavedGifs
{
private:
    int __id = 0x83bf3d52;

public:
    int hash;
    GetSavedGifs(int hash_);
    static GetSavedGifs<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveGif
{
private:
    int __id = 0x327a30cb;

public:
    TLObject id;
    bool unsave;
    SaveGif(TLObject id_, bool unsave_);
    static SaveGif<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetInlineBotResults
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
    static GetInlineBotResults<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetInlineBotResults
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
    static SetInlineBotResults<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendInlineBotResult
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
    static SendInlineBotResult<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMessageEditData
{
private:
    int __id = 0xfda68d36;

public:
    TLObject peer;
    int id;
    GetMessageEditData(TLObject peer_, int id_);
    static GetMessageEditData<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditMessage
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
    static EditMessage<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditInlineBotMessage
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
    static EditInlineBotMessage<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetBotCallbackAnswer
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
    static GetBotCallbackAnswer<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetBotCallbackAnswer
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
    static SetBotCallbackAnswer<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPeerDialogs
{
private:
    int __id = 0xe470bcfd;

public:
    std::vector<TLObject> peers;
    GetPeerDialogs(std::vector<TLObject> peers_);
    static GetPeerDialogs<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveDraft
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
    static SaveDraft<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAllDrafts
{
private:
    int __id = 0x6a3f8d65;

public:
    GetAllDrafts() = default;
    static GetAllDrafts<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFeaturedStickers
{
private:
    int __id = 0x2dacca4f;

public:
    int hash;
    GetFeaturedStickers(int hash_);
    static GetFeaturedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadFeaturedStickers
{
private:
    int __id = 0x5b118126;

public:
    std::vector<long> id;
    ReadFeaturedStickers(std::vector<long> id_);
    static ReadFeaturedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetRecentStickers
{
private:
    int __id = 0x5ea192c9;

public:
    std::optional<bool> attached;
    int hash;
    GetRecentStickers(int hash_, std::optional<bool> attached_ = std::nullopt);
    static GetRecentStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveRecentSticker
{
private:
    int __id = 0x392718f8;

public:
    std::optional<bool> attached;
    TLObject id;
    bool unsave;
    SaveRecentSticker(TLObject id_, bool unsave_, std::optional<bool> attached_ = std::nullopt);
    static SaveRecentSticker<X> read(Reader reader);
    std::string write();
};

template <class X>
class ClearRecentStickers
{
private:
    int __id = 0x8999602d;

public:
    std::optional<bool> attached;
    ClearRecentStickers(std::optional<bool> attached_ = std::nullopt);
    static ClearRecentStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetArchivedStickers
{
private:
    int __id = 0x57f17692;

public:
    std::optional<bool> masks;
    long offset_id;
    int limit;
    GetArchivedStickers(long offset_id_, int limit_, std::optional<bool> masks_ = std::nullopt);
    static GetArchivedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetMaskStickers
{
private:
    int __id = 0x65b8c79f;

public:
    int hash;
    GetMaskStickers(int hash_);
    static GetMaskStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAttachedStickers
{
private:
    int __id = 0xcc5b67cc;

public:
    TLObject media;
    GetAttachedStickers(TLObject media_);
    static GetAttachedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetGameScore
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
    static SetGameScore<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetInlineGameScore
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
    static SetInlineGameScore<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetGameHighScores
{
private:
    int __id = 0xe822649d;

public:
    TLObject peer;
    int id;
    TLObject user_id;
    GetGameHighScores(TLObject peer_, int id_, TLObject user_id_);
    static GetGameHighScores<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetInlineGameHighScores
{
private:
    int __id = 0xf635e1b;

public:
    TLObject id;
    TLObject user_id;
    GetInlineGameHighScores(TLObject id_, TLObject user_id_);
    static GetInlineGameHighScores<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetCommonChats
{
private:
    int __id = 0xd0a48c4;

public:
    TLObject user_id;
    int max_id;
    int limit;
    GetCommonChats(TLObject user_id_, int max_id_, int limit_);
    static GetCommonChats<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAllChats
{
private:
    int __id = 0xeba80ff0;

public:
    std::vector<int> except_ids;
    GetAllChats(std::vector<int> except_ids_);
    static GetAllChats<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetWebPage
{
private:
    int __id = 0x32ca8f91;

public:
    std::string url;
    int hash;
    GetWebPage(std::string url_, int hash_);
    static GetWebPage<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleDialogPin
{
private:
    int __id = 0xa731e257;

public:
    std::optional<bool> pinned;
    TLObject peer;
    ToggleDialogPin(TLObject peer_, std::optional<bool> pinned_ = std::nullopt);
    static ToggleDialogPin<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReorderPinnedDialogs
{
private:
    int __id = 0x3b1adf37;

public:
    std::optional<bool> force;
    int folder_id;
    std::vector<TLObject> order;
    ReorderPinnedDialogs(int folder_id_, std::vector<TLObject> order_, std::optional<bool> force_ = std::nullopt);
    static ReorderPinnedDialogs<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPinnedDialogs
{
private:
    int __id = 0xd6b94df2;

public:
    int folder_id;
    GetPinnedDialogs(int folder_id_);
    static GetPinnedDialogs<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetBotShippingResults
{
private:
    int __id = 0xe5f672fa;

public:
    long query_id;
    std::optional<std::string> error;
    std::optional<std::vector<TLObject>> shipping_options;
    SetBotShippingResults(long query_id_, std::optional<std::string> error_ = std::nullopt, std::optional<std::vector<TLObject>> shipping_options_ = std::nullopt);
    static SetBotShippingResults<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetBotPrecheckoutResults
{
private:
    int __id = 0x9c2dd95;

public:
    std::optional<bool> success;
    long query_id;
    std::optional<std::string> error;
    SetBotPrecheckoutResults(long query_id_, std::optional<bool> success_ = std::nullopt, std::optional<std::string> error_ = std::nullopt);
    static SetBotPrecheckoutResults<X> read(Reader reader);
    std::string write();
};

template <class X>
class UploadMedia
{
private:
    int __id = 0x519bc2b1;

public:
    TLObject peer;
    TLObject media;
    UploadMedia(TLObject peer_, TLObject media_);
    static UploadMedia<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendScreenshotNotification
{
private:
    int __id = 0xc97df020;

public:
    TLObject peer;
    int reply_to_msg_id;
    long random_id;
    SendScreenshotNotification(TLObject peer_, int reply_to_msg_id_, long random_id_);
    static SendScreenshotNotification<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFavedStickers
{
private:
    int __id = 0x21ce0b0e;

public:
    int hash;
    GetFavedStickers(int hash_);
    static GetFavedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class FaveSticker
{
private:
    int __id = 0xb9ffc55b;

public:
    TLObject id;
    bool unfave;
    FaveSticker(TLObject id_, bool unfave_);
    static FaveSticker<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetUnreadMentions
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
    static GetUnreadMentions<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadMentions
{
private:
    int __id = 0xf0189d3;

public:
    TLObject peer;
    ReadMentions(TLObject peer_);
    static ReadMentions<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetRecentLocations
{
private:
    int __id = 0xbbc45b09;

public:
    TLObject peer;
    int limit;
    int hash;
    GetRecentLocations(TLObject peer_, int limit_, int hash_);
    static GetRecentLocations<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendMultiMedia
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
    static SendMultiMedia<X> read(Reader reader);
    std::string write();
};

template <class X>
class UploadEncryptedFile
{
private:
    int __id = 0x5057c497;

public:
    TLObject peer;
    TLObject file;
    UploadEncryptedFile(TLObject peer_, TLObject file_);
    static UploadEncryptedFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class SearchStickerSets
{
private:
    int __id = 0xc2b7d08b;

public:
    std::optional<bool> exclude_featured;
    std::string q;
    int hash;
    SearchStickerSets(std::string q_, int hash_, std::optional<bool> exclude_featured_ = std::nullopt);
    static SearchStickerSets<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSplitRanges
{
private:
    int __id = 0x1cff7e08;

public:
    GetSplitRanges() = default;
    static GetSplitRanges<X> read(Reader reader);
    std::string write();
};

template <class X>
class MarkDialogUnread
{
private:
    int __id = 0xc286d98f;

public:
    std::optional<bool> unread;
    TLObject peer;
    MarkDialogUnread(TLObject peer_, std::optional<bool> unread_ = std::nullopt);
    static MarkDialogUnread<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDialogUnreadMarks
{
private:
    int __id = 0x22e24e22;

public:
    GetDialogUnreadMarks() = default;
    static GetDialogUnreadMarks<X> read(Reader reader);
    std::string write();
};

template <class X>
class ClearAllDrafts
{
private:
    int __id = 0x7e58ee9c;

public:
    ClearAllDrafts() = default;
    static ClearAllDrafts<X> read(Reader reader);
    std::string write();
};

template <class X>
class UpdatePinnedMessage
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
    static UpdatePinnedMessage<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendVote
{
private:
    int __id = 0x10ea6184;

public:
    TLObject peer;
    int msg_id;
    std::vector<std::string> options;
    SendVote(TLObject peer_, int msg_id_, std::vector<std::string> options_);
    static SendVote<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPollResults
{
private:
    int __id = 0x73bb643b;

public:
    TLObject peer;
    int msg_id;
    GetPollResults(TLObject peer_, int msg_id_);
    static GetPollResults<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetOnlines
{
private:
    int __id = 0x6e2be050;

public:
    TLObject peer;
    GetOnlines(TLObject peer_);
    static GetOnlines<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetStatsURL
{
private:
    int __id = 0x812c2ae6;

public:
    std::optional<bool> dark;
    TLObject peer;
    std::string params;
    GetStatsURL(TLObject peer_, std::string params_, std::optional<bool> dark_ = std::nullopt);
    static GetStatsURL<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditChatAbout
{
private:
    int __id = 0xdef60797;

public:
    TLObject peer;
    std::string about;
    EditChatAbout(TLObject peer_, std::string about_);
    static EditChatAbout<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditChatDefaultBannedRights
{
private:
    int __id = 0xa5866b41;

public:
    TLObject peer;
    TLObject banned_rights;
    EditChatDefaultBannedRights(TLObject peer_, TLObject banned_rights_);
    static EditChatDefaultBannedRights<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetEmojiKeywords
{
private:
    int __id = 0x35a0e062;

public:
    std::string lang_code;
    GetEmojiKeywords(std::string lang_code_);
    static GetEmojiKeywords<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetEmojiKeywordsDifference
{
private:
    int __id = 0x1508b6af;

public:
    std::string lang_code;
    int from_version;
    GetEmojiKeywordsDifference(std::string lang_code_, int from_version_);
    static GetEmojiKeywordsDifference<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetEmojiKeywordsLanguages
{
private:
    int __id = 0x4e9963b2;

public:
    std::vector<std::string> lang_codes;
    GetEmojiKeywordsLanguages(std::vector<std::string> lang_codes_);
    static GetEmojiKeywordsLanguages<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetEmojiURL
{
private:
    int __id = 0xd5b10c26;

public:
    std::string lang_code;
    GetEmojiURL(std::string lang_code_);
    static GetEmojiURL<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSearchCounters
{
private:
    int __id = 0x732eef00;

public:
    TLObject peer;
    std::vector<TLObject> filters;
    GetSearchCounters(TLObject peer_, std::vector<TLObject> filters_);
    static GetSearchCounters<X> read(Reader reader);
    std::string write();
};

template <class X>
class RequestUrlAuth
{
private:
    int __id = 0x198fb446;

public:
    std::optional<TLObject> peer;
    std::optional<int> msg_id;
    std::optional<int> button_id;
    std::optional<std::string> url;
    RequestUrlAuth(std::optional<TLObject> peer_ = std::nullopt, std::optional<int> msg_id_ = std::nullopt, std::optional<int> button_id_ = std::nullopt, std::optional<std::string> url_ = std::nullopt);
    static RequestUrlAuth<X> read(Reader reader);
    std::string write();
};

template <class X>
class AcceptUrlAuth
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
    static AcceptUrlAuth<X> read(Reader reader);
    std::string write();
};

template <class X>
class HidePeerSettingsBar
{
private:
    int __id = 0x4facb138;

public:
    TLObject peer;
    HidePeerSettingsBar(TLObject peer_);
    static HidePeerSettingsBar<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetScheduledHistory
{
private:
    int __id = 0xe2c2685b;

public:
    TLObject peer;
    int hash;
    GetScheduledHistory(TLObject peer_, int hash_);
    static GetScheduledHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetScheduledMessages
{
private:
    int __id = 0xbdbb0464;

public:
    TLObject peer;
    std::vector<int> id;
    GetScheduledMessages(TLObject peer_, std::vector<int> id_);
    static GetScheduledMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class SendScheduledMessages
{
private:
    int __id = 0xbd38850a;

public:
    TLObject peer;
    std::vector<int> id;
    SendScheduledMessages(TLObject peer_, std::vector<int> id_);
    static SendScheduledMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteScheduledMessages
{
private:
    int __id = 0x59ae2b16;

public:
    TLObject peer;
    std::vector<int> id;
    DeleteScheduledMessages(TLObject peer_, std::vector<int> id_);
    static DeleteScheduledMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetPollVotes
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
    static GetPollVotes<X> read(Reader reader);
    std::string write();
};

template <class X>
class ToggleStickerSets
{
private:
    int __id = 0xb5052fea;

public:
    std::optional<bool> uninstall;
    std::optional<bool> archive;
    std::optional<bool> unarchive;
    std::vector<TLObject> stickersets;
    ToggleStickerSets(std::vector<TLObject> stickersets_, std::optional<bool> uninstall_ = std::nullopt, std::optional<bool> archive_ = std::nullopt, std::optional<bool> unarchive_ = std::nullopt);
    static ToggleStickerSets<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDialogFilters
{
private:
    int __id = 0xf19ed96d;

public:
    GetDialogFilters() = default;
    static GetDialogFilters<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetSuggestedDialogFilters
{
private:
    int __id = 0xa29cd42c;

public:
    GetSuggestedDialogFilters() = default;
    static GetSuggestedDialogFilters<X> read(Reader reader);
    std::string write();
};

template <class X>
class UpdateDialogFilter
{
private:
    int __id = 0x1ad4a04a;

public:
    int id;
    std::optional<TLObject> filter;
    UpdateDialogFilter(int id_, std::optional<TLObject> filter_ = std::nullopt);
    static UpdateDialogFilter<X> read(Reader reader);
    std::string write();
};

template <class X>
class UpdateDialogFiltersOrder
{
private:
    int __id = 0xc563c1e4;

public:
    std::vector<int> order;
    UpdateDialogFiltersOrder(std::vector<int> order_);
    static UpdateDialogFiltersOrder<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetOldFeaturedStickers
{
private:
    int __id = 0x5fe7025b;

public:
    int offset;
    int limit;
    int hash;
    GetOldFeaturedStickers(int offset_, int limit_, int hash_);
    static GetOldFeaturedStickers<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetReplies
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
    static GetReplies<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDiscussionMessage
{
private:
    int __id = 0x446972fd;

public:
    TLObject peer;
    int msg_id;
    GetDiscussionMessage(TLObject peer_, int msg_id_);
    static GetDiscussionMessage<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReadDiscussion
{
private:
    int __id = 0xf731a9f4;

public:
    TLObject peer;
    int msg_id;
    int read_max_id;
    ReadDiscussion(TLObject peer_, int msg_id_, int read_max_id_);
    static ReadDiscussion<X> read(Reader reader);
    std::string write();
};

template <class X>
class UnpinAllMessages
{
private:
    int __id = 0xf025bc8b;

public:
    TLObject peer;
    UnpinAllMessages(TLObject peer_);
    static UnpinAllMessages<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteChat
{
private:
    int __id = 0x83247d11;

public:
    int chat_id;
    DeleteChat(int chat_id_);
    static DeleteChat<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeletePhoneCallHistory
{
private:
    int __id = 0xf9cbe409;

public:
    std::optional<bool> revoke;
    DeletePhoneCallHistory(std::optional<bool> revoke_ = std::nullopt);
    static DeletePhoneCallHistory<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckHistoryImport
{
private:
    int __id = 0x43fe19f3;

public:
    std::string import_head;
    CheckHistoryImport(std::string import_head_);
    static CheckHistoryImport<X> read(Reader reader);
    std::string write();
};

template <class X>
class InitHistoryImport
{
private:
    int __id = 0x34090c3b;

public:
    TLObject peer;
    TLObject file;
    int media_count;
    InitHistoryImport(TLObject peer_, TLObject file_, int media_count_);
    static InitHistoryImport<X> read(Reader reader);
    std::string write();
};

template <class X>
class UploadImportedMedia
{
private:
    int __id = 0x2a862092;

public:
    TLObject peer;
    long import_id;
    std::string file_name;
    TLObject media;
    UploadImportedMedia(TLObject peer_, long import_id_, std::string file_name_, TLObject media_);
    static UploadImportedMedia<X> read(Reader reader);
    std::string write();
};

template <class X>
class StartHistoryImport
{
private:
    int __id = 0xb43df344;

public:
    TLObject peer;
    long import_id;
    StartHistoryImport(TLObject peer_, long import_id_);
    static StartHistoryImport<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetExportedChatInvites
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
    static GetExportedChatInvites<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetExportedChatInvite
{
private:
    int __id = 0x73746f5c;

public:
    TLObject peer;
    std::string link;
    GetExportedChatInvite(TLObject peer_, std::string link_);
    static GetExportedChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class EditExportedChatInvite
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
    static EditExportedChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteRevokedExportedChatInvites
{
private:
    int __id = 0x56987bd5;

public:
    TLObject peer;
    TLObject admin_id;
    DeleteRevokedExportedChatInvites(TLObject peer_, TLObject admin_id_);
    static DeleteRevokedExportedChatInvites<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteExportedChatInvite
{
private:
    int __id = 0xd464a42b;

public:
    TLObject peer;
    std::string link;
    DeleteExportedChatInvite(TLObject peer_, std::string link_);
    static DeleteExportedChatInvite<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetAdminsWithInvites
{
private:
    int __id = 0x3920e6ef;

public:
    TLObject peer;
    GetAdminsWithInvites(TLObject peer_);
    static GetAdminsWithInvites<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetChatInviteImporters
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
    static GetChatInviteImporters<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetHistoryTTL
{
private:
    int __id = 0xb80e5fe4;

public:
    TLObject peer;
    int period;
    SetHistoryTTL(TLObject peer_, int period_);
    static SetHistoryTTL<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckHistoryImportPeer
{
private:
    int __id = 0x5dc60f03;

public:
    TLObject peer;
    CheckHistoryImportPeer(TLObject peer_);
    static CheckHistoryImportPeer<X> read(Reader reader);
    std::string write();
};
