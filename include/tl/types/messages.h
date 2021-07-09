#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class Dialogs
{
private:
    int __id = 0x15ba6c40;

public:
    std::vector<TLObject> dialogs;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    Dialogs(std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static Dialogs read(Reader reader);
    std::string write();
};

class DialogsSlice
{
private:
    int __id = 0x71e094f3;

public:
    int count;
    std::vector<TLObject> dialogs;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    DialogsSlice(int count_, std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static DialogsSlice read(Reader reader);
    std::string write();
};

class DialogsNotModified
{
private:
    int __id = 0xf0e3e596;

public:
    int count;
    DialogsNotModified(int count_);
    static DialogsNotModified read(Reader reader);
    std::string write();
};

class Messages
{
private:
    int __id = 0x8c718e87;

public:
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    Messages(std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static Messages read(Reader reader);
    std::string write();
};

class MessagesSlice
{
private:
    int __id = 0x3a54685e;

public:
    std::optional<bool> inexact;
    int count;
    std::optional<int> next_rate;
    std::optional<int> offset_id_offset;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    MessagesSlice(int count_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> inexact_ = std::nullopt, std::optional<int> next_rate_ = std::nullopt, std::optional<int> offset_id_offset_ = std::nullopt);
    static MessagesSlice read(Reader reader);
    std::string write();
};

class ChannelMessages
{
private:
    int __id = 0x64479808;

public:
    std::optional<bool> inexact;
    int pts;
    int count;
    std::optional<int> offset_id_offset;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChannelMessages(int pts_, int count_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> inexact_ = std::nullopt, std::optional<int> offset_id_offset_ = std::nullopt);
    static ChannelMessages read(Reader reader);
    std::string write();
};

class MessagesNotModified
{
private:
    int __id = 0x74535f21;

public:
    int count;
    MessagesNotModified(int count_);
    static MessagesNotModified read(Reader reader);
    std::string write();
};

class Chats
{
private:
    int __id = 0x64ff9fd5;

public:
    std::vector<TLObject> chats;
    Chats(std::vector<TLObject> chats_);
    static Chats read(Reader reader);
    std::string write();
};

class ChatsSlice
{
private:
    int __id = 0x9cd81144;

public:
    int count;
    std::vector<TLObject> chats;
    ChatsSlice(int count_, std::vector<TLObject> chats_);
    static ChatsSlice read(Reader reader);
    std::string write();
};

class ChatFull
{
private:
    int __id = 0xe5d7d19c;

public:
    TLObject full_chat;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    ChatFull(TLObject full_chat_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static ChatFull read(Reader reader);
    std::string write();
};

class AffectedHistory
{
private:
    int __id = 0xb45c69d1;

public:
    int pts;
    int pts_count;
    int offset;
    AffectedHistory(int pts_, int pts_count_, int offset_);
    static AffectedHistory read(Reader reader);
    std::string write();
};

class DhConfigNotModified
{
private:
    int __id = 0xc0e24635;

public:
    std::string random;
    DhConfigNotModified(std::string random_);
    static DhConfigNotModified read(Reader reader);
    std::string write();
};

class DhConfig
{
private:
    int __id = 0x2c221edd;

public:
    int g;
    std::string p;
    int version;
    std::string random;
    DhConfig(int g_, std::string p_, int version_, std::string random_);
    static DhConfig read(Reader reader);
    std::string write();
};

class SentEncryptedMessage
{
private:
    int __id = 0x560f8935;

public:
    int date;
    SentEncryptedMessage(int date_);
    static SentEncryptedMessage read(Reader reader);
    std::string write();
};

class SentEncryptedFile
{
private:
    int __id = 0x9493ff32;

public:
    int date;
    TLObject file;
    SentEncryptedFile(int date_, TLObject file_);
    static SentEncryptedFile read(Reader reader);
    std::string write();
};

class StickersNotModified
{
private:
    int __id = 0xf1749a22;

public:
    StickersNotModified() = default;
    static StickersNotModified read(Reader reader);
    std::string write();
};

class Stickers
{
private:
    int __id = 0xe4599bbd;

public:
    int hash;
    std::vector<TLObject> stickers;
    Stickers(int hash_, std::vector<TLObject> stickers_);
    static Stickers read(Reader reader);
    std::string write();
};

class AllStickersNotModified
{
private:
    int __id = 0xe86602c3;

public:
    AllStickersNotModified() = default;
    static AllStickersNotModified read(Reader reader);
    std::string write();
};

class AllStickers
{
private:
    int __id = 0xedfd405f;

public:
    int hash;
    std::vector<TLObject> sets;
    AllStickers(int hash_, std::vector<TLObject> sets_);
    static AllStickers read(Reader reader);
    std::string write();
};

class AffectedMessages
{
private:
    int __id = 0x84d19185;

public:
    int pts;
    int pts_count;
    AffectedMessages(int pts_, int pts_count_);
    static AffectedMessages read(Reader reader);
    std::string write();
};

class StickerSet
{
private:
    int __id = 0xb60a24a6;

public:
    TLObject set;
    std::vector<TLObject> packs;
    std::vector<TLObject> documents;
    StickerSet(TLObject set_, std::vector<TLObject> packs_, std::vector<TLObject> documents_);
    static StickerSet read(Reader reader);
    std::string write();
};

class SavedGifsNotModified
{
private:
    int __id = 0xe8025ca2;

public:
    SavedGifsNotModified() = default;
    static SavedGifsNotModified read(Reader reader);
    std::string write();
};

class SavedGifs
{
private:
    int __id = 0x2e0709a5;

public:
    int hash;
    std::vector<TLObject> gifs;
    SavedGifs(int hash_, std::vector<TLObject> gifs_);
    static SavedGifs read(Reader reader);
    std::string write();
};

class BotResults
{
private:
    int __id = 0x947ca848;

public:
    std::optional<bool> gallery;
    long query_id;
    std::optional<std::string> next_offset;
    std::optional<TLObject> switch_pm;
    std::vector<TLObject> results;
    int cache_time;
    std::vector<TLObject> users;
    BotResults(long query_id_, std::vector<TLObject> results_, int cache_time_, std::vector<TLObject> users_, std::optional<bool> gallery_ = std::nullopt, std::optional<std::string> next_offset_ = std::nullopt, std::optional<TLObject> switch_pm_ = std::nullopt);
    static BotResults read(Reader reader);
    std::string write();
};

class BotCallbackAnswer
{
private:
    int __id = 0x36585ea4;

public:
    std::optional<bool> alert;
    std::optional<bool> has_url;
    std::optional<bool> native_ui;
    std::optional<std::string> message;
    std::optional<std::string> url;
    int cache_time;
    BotCallbackAnswer(int cache_time_, std::optional<bool> alert_ = std::nullopt, std::optional<bool> has_url_ = std::nullopt, std::optional<bool> native_ui_ = std::nullopt, std::optional<std::string> message_ = std::nullopt, std::optional<std::string> url_ = std::nullopt);
    static BotCallbackAnswer read(Reader reader);
    std::string write();
};

class MessageEditData
{
private:
    int __id = 0x26b5dde6;

public:
    std::optional<bool> caption;
    MessageEditData(std::optional<bool> caption_ = std::nullopt);
    static MessageEditData read(Reader reader);
    std::string write();
};

class PeerDialogs
{
private:
    int __id = 0x3371c354;

public:
    std::vector<TLObject> dialogs;
    std::vector<TLObject> messages;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    TLObject state;
    PeerDialogs(std::vector<TLObject> dialogs_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject state_);
    static PeerDialogs read(Reader reader);
    std::string write();
};

class FeaturedStickersNotModified
{
private:
    int __id = 0xc6dc0c66;

public:
    int count;
    FeaturedStickersNotModified(int count_);
    static FeaturedStickersNotModified read(Reader reader);
    std::string write();
};

class FeaturedStickers
{
private:
    int __id = 0xb6abc341;

public:
    int hash;
    int count;
    std::vector<TLObject> sets;
    std::vector<long> unread;
    FeaturedStickers(int hash_, int count_, std::vector<TLObject> sets_, std::vector<long> unread_);
    static FeaturedStickers read(Reader reader);
    std::string write();
};

class RecentStickersNotModified
{
private:
    int __id = 0xb17f890;

public:
    RecentStickersNotModified() = default;
    static RecentStickersNotModified read(Reader reader);
    std::string write();
};

class RecentStickers
{
private:
    int __id = 0x22f3afb3;

public:
    int hash;
    std::vector<TLObject> packs;
    std::vector<TLObject> stickers;
    std::vector<int> dates;
    RecentStickers(int hash_, std::vector<TLObject> packs_, std::vector<TLObject> stickers_, std::vector<int> dates_);
    static RecentStickers read(Reader reader);
    std::string write();
};

class ArchivedStickers
{
private:
    int __id = 0x4fcba9c8;

public:
    int count;
    std::vector<TLObject> sets;
    ArchivedStickers(int count_, std::vector<TLObject> sets_);
    static ArchivedStickers read(Reader reader);
    std::string write();
};

class StickerSetInstallResultSuccess
{
private:
    int __id = 0x38641628;

public:
    StickerSetInstallResultSuccess() = default;
    static StickerSetInstallResultSuccess read(Reader reader);
    std::string write();
};

class StickerSetInstallResultArchive
{
private:
    int __id = 0x35e410a8;

public:
    std::vector<TLObject> sets;
    StickerSetInstallResultArchive(std::vector<TLObject> sets_);
    static StickerSetInstallResultArchive read(Reader reader);
    std::string write();
};

class HighScores
{
private:
    int __id = 0x9a3bfd99;

public:
    std::vector<TLObject> scores;
    std::vector<TLObject> users;
    HighScores(std::vector<TLObject> scores_, std::vector<TLObject> users_);
    static HighScores read(Reader reader);
    std::string write();
};

class FavedStickersNotModified
{
private:
    int __id = 0x9e8fa6d3;

public:
    FavedStickersNotModified() = default;
    static FavedStickersNotModified read(Reader reader);
    std::string write();
};

class FavedStickers
{
private:
    int __id = 0xf37f2f16;

public:
    int hash;
    std::vector<TLObject> packs;
    std::vector<TLObject> stickers;
    FavedStickers(int hash_, std::vector<TLObject> packs_, std::vector<TLObject> stickers_);
    static FavedStickers read(Reader reader);
    std::string write();
};

class FoundStickerSetsNotModified
{
private:
    int __id = 0xd54b65d;

public:
    FoundStickerSetsNotModified() = default;
    static FoundStickerSetsNotModified read(Reader reader);
    std::string write();
};

class FoundStickerSets
{
private:
    int __id = 0x5108d648;

public:
    int hash;
    std::vector<TLObject> sets;
    FoundStickerSets(int hash_, std::vector<TLObject> sets_);
    static FoundStickerSets read(Reader reader);
    std::string write();
};

class SearchCounter
{
private:
    int __id = 0xe844ebff;

public:
    std::optional<bool> inexact;
    TLObject filter;
    int count;
    SearchCounter(TLObject filter_, int count_, std::optional<bool> inexact_ = std::nullopt);
    static SearchCounter read(Reader reader);
    std::string write();
};

class InactiveChats
{
private:
    int __id = 0xa927fec5;

public:
    std::vector<int> dates;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    InactiveChats(std::vector<int> dates_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static InactiveChats read(Reader reader);
    std::string write();
};

class VotesList
{
private:
    int __id = 0x823f649;

public:
    int count;
    std::vector<TLObject> votes;
    std::vector<TLObject> users;
    std::optional<std::string> next_offset;
    VotesList(int count_, std::vector<TLObject> votes_, std::vector<TLObject> users_, std::optional<std::string> next_offset_ = std::nullopt);
    static VotesList read(Reader reader);
    std::string write();
};

class MessageViews
{
private:
    int __id = 0xb6c4f543;

public:
    std::vector<TLObject> views;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    MessageViews(std::vector<TLObject> views_, std::vector<TLObject> chats_, std::vector<TLObject> users_);
    static MessageViews read(Reader reader);
    std::string write();
};

class DiscussionMessage
{
private:
    int __id = 0xf5dd8f9d;

public:
    std::vector<TLObject> messages;
    std::optional<int> max_id;
    std::optional<int> read_inbox_max_id;
    std::optional<int> read_outbox_max_id;
    std::vector<TLObject> chats;
    std::vector<TLObject> users;
    DiscussionMessage(std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<int> max_id_ = std::nullopt, std::optional<int> read_inbox_max_id_ = std::nullopt, std::optional<int> read_outbox_max_id_ = std::nullopt);
    static DiscussionMessage read(Reader reader);
    std::string write();
};

class HistoryImport
{
private:
    int __id = 0x1662af0b;

public:
    long id;
    HistoryImport(long id_);
    static HistoryImport read(Reader reader);
    std::string write();
};

class HistoryImportParsed
{
private:
    int __id = 0x5e0fb7b9;

public:
    std::optional<bool> pm;
    std::optional<bool> group;
    std::optional<std::string> title;
    HistoryImportParsed(std::optional<bool> pm_ = std::nullopt, std::optional<bool> group_ = std::nullopt, std::optional<std::string> title_ = std::nullopt);
    static HistoryImportParsed read(Reader reader);
    std::string write();
};

class AffectedFoundMessages
{
private:
    int __id = 0xef8d3e6c;

public:
    int pts;
    int pts_count;
    int offset;
    std::vector<int> messages;
    AffectedFoundMessages(int pts_, int pts_count_, int offset_, std::vector<int> messages_);
    static AffectedFoundMessages read(Reader reader);
    std::string write();
};

class ExportedChatInvites
{
private:
    int __id = 0xbdc62dcc;

public:
    int count;
    std::vector<TLObject> invites;
    std::vector<TLObject> users;
    ExportedChatInvites(int count_, std::vector<TLObject> invites_, std::vector<TLObject> users_);
    static ExportedChatInvites read(Reader reader);
    std::string write();
};

class ExportedChatInvite
{
private:
    int __id = 0x1871be50;

public:
    TLObject invite;
    std::vector<TLObject> users;
    ExportedChatInvite(TLObject invite_, std::vector<TLObject> users_);
    static ExportedChatInvite read(Reader reader);
    std::string write();
};

class ExportedChatInviteReplaced
{
private:
    int __id = 0x222600ef;

public:
    TLObject invite;
    TLObject new_invite;
    std::vector<TLObject> users;
    ExportedChatInviteReplaced(TLObject invite_, TLObject new_invite_, std::vector<TLObject> users_);
    static ExportedChatInviteReplaced read(Reader reader);
    std::string write();
};

class ChatInviteImporters
{
private:
    int __id = 0x81b6b00a;

public:
    int count;
    std::vector<TLObject> importers;
    std::vector<TLObject> users;
    ChatInviteImporters(int count_, std::vector<TLObject> importers_, std::vector<TLObject> users_);
    static ChatInviteImporters read(Reader reader);
    std::string write();
};

class ChatAdminsWithInvites
{
private:
    int __id = 0xb69b72d7;

public:
    std::vector<TLObject> admins;
    std::vector<TLObject> users;
    ChatAdminsWithInvites(std::vector<TLObject> admins_, std::vector<TLObject> users_);
    static ChatAdminsWithInvites read(Reader reader);
    std::string write();
};

class CheckedHistoryImportPeer
{
private:
    int __id = 0xa24de717;

public:
    std::string confirm_text;
    CheckedHistoryImportPeer(std::string confirm_text_);
    static CheckedHistoryImportPeer read(Reader reader);
    std::string write();
};
