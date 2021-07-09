#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class ResPQ
{
private:
    int __id = 0x05162463;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    std::string pq;
    std::vector<long> server_public_key_fingerprints;
    ResPQ(uint128_t nonce_, uint128_t server_nonce_, std::string pq_, std::vector<long> server_public_key_fingerprints_);
    static ResPQ read(Reader reader);
    std::string write();
};

class PQInnerDataDc
{
private:
    int __id = 0xa9f55f95;

public:
    std::string pq;
    std::string p;
    std::string q;
    uint128_t nonce;
    uint128_t server_nonce;
    uint256_t new_nonce;
    int dc;
    PQInnerDataDc(std::string pq_, std::string p_, std::string q_, uint128_t nonce_, uint128_t server_nonce_, uint256_t new_nonce_, int dc_);
    static PQInnerDataDc read(Reader reader);
    std::string write();
};

class PQInnerDataTempDc
{
private:
    int __id = 0x56fddf88;

public:
    std::string pq;
    std::string p;
    std::string q;
    uint128_t nonce;
    uint128_t server_nonce;
    uint256_t new_nonce;
    int dc;
    int expires_in;
    PQInnerDataTempDc(std::string pq_, std::string p_, std::string q_, uint128_t nonce_, uint128_t server_nonce_, uint256_t new_nonce_, int dc_, int expires_in_);
    static PQInnerDataTempDc read(Reader reader);
    std::string write();
};

class ServerDHParamsFail
{
private:
    int __id = 0x79cb045d;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    uint128_t new_nonce_hash;
    ServerDHParamsFail(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash_);
    static ServerDHParamsFail read(Reader reader);
    std::string write();
};

class ServerDHParamsOk
{
private:
    int __id = 0xd0e8075c;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    std::string encrypted_answer;
    ServerDHParamsOk(uint128_t nonce_, uint128_t server_nonce_, std::string encrypted_answer_);
    static ServerDHParamsOk read(Reader reader);
    std::string write();
};

class ServerDHInnerData
{
private:
    int __id = 0xb5890dba;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    int g;
    std::string dh_prime;
    std::string g_a;
    int server_time;
    ServerDHInnerData(uint128_t nonce_, uint128_t server_nonce_, int g_, std::string dh_prime_, std::string g_a_, int server_time_);
    static ServerDHInnerData read(Reader reader);
    std::string write();
};

class ClientDHInnerData
{
private:
    int __id = 0x6643b654;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    long retry_id;
    std::string g_b;
    ClientDHInnerData(uint128_t nonce_, uint128_t server_nonce_, long retry_id_, std::string g_b_);
    static ClientDHInnerData read(Reader reader);
    std::string write();
};

class DhGenOk
{
private:
    int __id = 0x3bcbf734;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    uint128_t new_nonce_hash1;
    DhGenOk(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash1_);
    static DhGenOk read(Reader reader);
    std::string write();
};

class DhGenRetry
{
private:
    int __id = 0x46dc1fb9;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    uint128_t new_nonce_hash2;
    DhGenRetry(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash2_);
    static DhGenRetry read(Reader reader);
    std::string write();
};

class DhGenFail
{
private:
    int __id = 0xa69dae02;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    uint128_t new_nonce_hash3;
    DhGenFail(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash3_);
    static DhGenFail read(Reader reader);
    std::string write();
};

class RpcError
{
private:
    int __id = 0x2144ca19;

public:
    int error_code;
    std::string error_message;
    RpcError(int error_code_, std::string error_message_);
    static RpcError read(Reader reader);
    std::string write();
};

class RpcAnswerUnknown
{
private:
    int __id = 0x5e2ad36e;

public:
    RpcAnswerUnknown() = default;
    static RpcAnswerUnknown read(Reader reader);
    std::string write();
};

class RpcAnswerDroppedRunning
{
private:
    int __id = 0xcd78e586;

public:
    RpcAnswerDroppedRunning() = default;
    static RpcAnswerDroppedRunning read(Reader reader);
    std::string write();
};

class RpcAnswerDropped
{
private:
    int __id = 0xa43ad8b7;

public:
    long msg_id;
    int seq_no;
    int bytes;
    RpcAnswerDropped(long msg_id_, int seq_no_, int bytes_);
    static RpcAnswerDropped read(Reader reader);
    std::string write();
};

class FutureSalt
{
private:
    int __id = 0x0949d9dc;

public:
    int valid_since;
    int valid_until;
    long salt;
    FutureSalt(int valid_since_, int valid_until_, long salt_);
    static FutureSalt read(Reader reader);
    std::string write();
};

class FutureSalts
{
private:
    int __id = 0xae500895;

public:
    long req_msg_id;
    int now;
    std::vector<TLObject> salts;
    FutureSalts(long req_msg_id_, int now_, std::vector<TLObject> salts_);
    static FutureSalts read(Reader reader);
    std::string write();
};

class Pong
{
private:
    int __id = 0x347773c5;

public:
    long msg_id;
    long ping_id;
    Pong(long msg_id_, long ping_id_);
    static Pong read(Reader reader);
    std::string write();
};

class DestroySessionOk
{
private:
    int __id = 0xe22045fc;

public:
    long session_id;
    DestroySessionOk(long session_id_);
    static DestroySessionOk read(Reader reader);
    std::string write();
};

class DestroySessionNone
{
private:
    int __id = 0x62d350c9;

public:
    long session_id;
    DestroySessionNone(long session_id_);
    static DestroySessionNone read(Reader reader);
    std::string write();
};

class NewSessionCreated
{
private:
    int __id = 0x9ec20908;

public:
    long first_msg_id;
    long unique_id;
    long server_salt;
    NewSessionCreated(long first_msg_id_, long unique_id_, long server_salt_);
    static NewSessionCreated read(Reader reader);
    std::string write();
};

class GzipPacked
{
private:
    int __id = 0x3072cfa1;

public:
    std::string packed_data;
    GzipPacked(std::string packed_data_);
    static GzipPacked read(Reader reader);
    std::string write();
};

class MsgsAck
{
private:
    int __id = 0x62d6b459;

public:
    std::vector<long> msg_ids;
    MsgsAck(std::vector<long> msg_ids_);
    static MsgsAck read(Reader reader);
    std::string write();
};

class BadMsgNotification
{
private:
    int __id = 0xa7eff811;

public:
    long bad_msg_id;
    int bad_msg_seqno;
    int error_code;
    BadMsgNotification(long bad_msg_id_, int bad_msg_seqno_, int error_code_);
    static BadMsgNotification read(Reader reader);
    std::string write();
};

class BadServerSalt
{
private:
    int __id = 0xedab447b;

public:
    long bad_msg_id;
    int bad_msg_seqno;
    int error_code;
    long new_server_salt;
    BadServerSalt(long bad_msg_id_, int bad_msg_seqno_, int error_code_, long new_server_salt_);
    static BadServerSalt read(Reader reader);
    std::string write();
};

class MsgResendReq
{
private:
    int __id = 0x7d861a08;

public:
    std::vector<long> msg_ids;
    MsgResendReq(std::vector<long> msg_ids_);
    static MsgResendReq read(Reader reader);
    std::string write();
};

class MsgsStateReq
{
private:
    int __id = 0xda69fb52;

public:
    std::vector<long> msg_ids;
    MsgsStateReq(std::vector<long> msg_ids_);
    static MsgsStateReq read(Reader reader);
    std::string write();
};

class MsgsStateInfo
{
private:
    int __id = 0x04deb57d;

public:
    long req_msg_id;
    std::string info;
    MsgsStateInfo(long req_msg_id_, std::string info_);
    static MsgsStateInfo read(Reader reader);
    std::string write();
};

class MsgsAllInfo
{
private:
    int __id = 0x8cc0d131;

public:
    std::vector<long> msg_ids;
    std::string info;
    MsgsAllInfo(std::vector<long> msg_ids_, std::string info_);
    static MsgsAllInfo read(Reader reader);
    std::string write();
};

class MsgDetailedInfo
{
private:
    int __id = 0x276d3ec6;

public:
    long msg_id;
    long answer_msg_id;
    int bytes;
    int status;
    MsgDetailedInfo(long msg_id_, long answer_msg_id_, int bytes_, int status_);
    static MsgDetailedInfo read(Reader reader);
    std::string write();
};

class MsgNewDetailedInfo
{
private:
    int __id = 0x809db6df;

public:
    long answer_msg_id;
    int bytes;
    int status;
    MsgNewDetailedInfo(long answer_msg_id_, int bytes_, int status_);
    static MsgNewDetailedInfo read(Reader reader);
    std::string write();
};

class DestroyAuthKeyOk
{
private:
    int __id = 0xf660e1d4;

public:
    DestroyAuthKeyOk() = default;
    static DestroyAuthKeyOk read(Reader reader);
    std::string write();
};

class DestroyAuthKeyNone
{
private:
    int __id = 0x0a9f2259;

public:
    DestroyAuthKeyNone() = default;
    static DestroyAuthKeyNone read(Reader reader);
    std::string write();
};

class DestroyAuthKeyFail
{
private:
    int __id = 0xea109b13;

public:
    DestroyAuthKeyFail() = default;
    static DestroyAuthKeyFail read(Reader reader);
    std::string write();
};

class InputPeerEmpty
{
private:
    int __id = 0x7f3b18ea;

public:
    InputPeerEmpty() = default;
    static InputPeerEmpty read(Reader reader);
    std::string write();
};

class InputPeerSelf
{
private:
    int __id = 0x7da07ec9;

public:
    InputPeerSelf() = default;
    static InputPeerSelf read(Reader reader);
    std::string write();
};

class InputPeerChat
{
private:
    int __id = 0x179be863;

public:
    int chat_id;
    InputPeerChat(int chat_id_);
    static InputPeerChat read(Reader reader);
    std::string write();
};

class InputPeerUser
{
private:
    int __id = 0x7b8e7de6;

public:
    int user_id;
    long access_hash;
    InputPeerUser(int user_id_, long access_hash_);
    static InputPeerUser read(Reader reader);
    std::string write();
};

class InputPeerChannel
{
private:
    int __id = 0x20adaef8;

public:
    int channel_id;
    long access_hash;
    InputPeerChannel(int channel_id_, long access_hash_);
    static InputPeerChannel read(Reader reader);
    std::string write();
};

class InputPeerUserFromMessage
{
private:
    int __id = 0x17bae2e6;

public:
    TLObject peer;
    int msg_id;
    int user_id;
    InputPeerUserFromMessage(TLObject peer_, int msg_id_, int user_id_);
    static InputPeerUserFromMessage read(Reader reader);
    std::string write();
};

class InputPeerChannelFromMessage
{
private:
    int __id = 0x9c95f7bb;

public:
    TLObject peer;
    int msg_id;
    int channel_id;
    InputPeerChannelFromMessage(TLObject peer_, int msg_id_, int channel_id_);
    static InputPeerChannelFromMessage read(Reader reader);
    std::string write();
};

class InputUserEmpty
{
private:
    int __id = 0xb98886cf;

public:
    InputUserEmpty() = default;
    static InputUserEmpty read(Reader reader);
    std::string write();
};

class InputUserSelf
{
private:
    int __id = 0xf7c1b13f;

public:
    InputUserSelf() = default;
    static InputUserSelf read(Reader reader);
    std::string write();
};

class InputUser
{
private:
    int __id = 0xd8292816;

public:
    int user_id;
    long access_hash;
    InputUser(int user_id_, long access_hash_);
    static InputUser read(Reader reader);
    std::string write();
};

class InputUserFromMessage
{
private:
    int __id = 0x2d117597;

public:
    TLObject peer;
    int msg_id;
    int user_id;
    InputUserFromMessage(TLObject peer_, int msg_id_, int user_id_);
    static InputUserFromMessage read(Reader reader);
    std::string write();
};

class InputPhoneContact
{
private:
    int __id = 0xf392b7f4;

public:
    long client_id;
    std::string phone;
    std::string first_name;
    std::string last_name;
    InputPhoneContact(long client_id_, std::string phone_, std::string first_name_, std::string last_name_);
    static InputPhoneContact read(Reader reader);
    std::string write();
};

class InputFile
{
private:
    int __id = 0xf52ff27f;

public:
    long id;
    int parts;
    std::string name;
    std::string md5_checksum;
    InputFile(long id_, int parts_, std::string name_, std::string md5_checksum_);
    static InputFile read(Reader reader);
    std::string write();
};

class InputFileBig
{
private:
    int __id = 0xfa4f0bb5;

public:
    long id;
    int parts;
    std::string name;
    InputFileBig(long id_, int parts_, std::string name_);
    static InputFileBig read(Reader reader);
    std::string write();
};

class InputMediaEmpty
{
private:
    int __id = 0x9664f57f;

public:
    InputMediaEmpty() = default;
    static InputMediaEmpty read(Reader reader);
    std::string write();
};

class InputMediaUploadedPhoto
{
private:
    int __id = 0x1e287d04;

public:
    TLObject file;
    std::optional<std::vector<TLObject>> stickers;
    std::optional<int> ttl_seconds;
    InputMediaUploadedPhoto(TLObject file_, std::optional<std::vector<TLObject>> stickers_ = std::nullopt, std::optional<int> ttl_seconds_ = std::nullopt);
    static InputMediaUploadedPhoto read(Reader reader);
    std::string write();
};

class InputMediaPhoto
{
private:
    int __id = 0xb3ba0635;

public:
    TLObject id;
    std::optional<int> ttl_seconds;
    InputMediaPhoto(TLObject id_, std::optional<int> ttl_seconds_ = std::nullopt);
    static InputMediaPhoto read(Reader reader);
    std::string write();
};

class InputMediaGeoPoint
{
private:
    int __id = 0xf9c44144;

public:
    TLObject geo_point;
    InputMediaGeoPoint(TLObject geo_point_);
    static InputMediaGeoPoint read(Reader reader);
    std::string write();
};

class InputMediaContact
{
private:
    int __id = 0xf8ab7dfb;

public:
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string vcard;
    InputMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_);
    static InputMediaContact read(Reader reader);
    std::string write();
};

class InputMediaUploadedDocument
{
private:
    int __id = 0x5b38c6c1;

public:
    std::optional<bool> nosound_video;
    std::optional<bool> force_file;
    TLObject file;
    std::optional<TLObject> thumb;
    std::string mime_type;
    std::vector<TLObject> attributes;
    std::optional<std::vector<TLObject>> stickers;
    std::optional<int> ttl_seconds;
    InputMediaUploadedDocument(TLObject file_, std::string mime_type_, std::vector<TLObject> attributes_, std::optional<bool> nosound_video_ = std::nullopt, std::optional<bool> force_file_ = std::nullopt, std::optional<TLObject> thumb_ = std::nullopt, std::optional<std::vector<TLObject>> stickers_ = std::nullopt, std::optional<int> ttl_seconds_ = std::nullopt);
    static InputMediaUploadedDocument read(Reader reader);
    std::string write();
};

class InputMediaDocument
{
private:
    int __id = 0x33473058;

public:
    TLObject id;
    std::optional<int> ttl_seconds;
    std::optional<std::string> query;
    InputMediaDocument(TLObject id_, std::optional<int> ttl_seconds_ = std::nullopt, std::optional<std::string> query_ = std::nullopt);
    static InputMediaDocument read(Reader reader);
    std::string write();
};

class InputMediaVenue
{
private:
    int __id = 0xc13d1c11;

public:
    TLObject geo_point;
    std::string title;
    std::string address;
    std::string provider;
    std::string venue_id;
    std::string venue_type;
    InputMediaVenue(TLObject geo_point_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_);
    static InputMediaVenue read(Reader reader);
    std::string write();
};

class InputMediaPhotoExternal
{
private:
    int __id = 0xe5bbfe1a;

public:
    std::string url;
    std::optional<int> ttl_seconds;
    InputMediaPhotoExternal(std::string url_, std::optional<int> ttl_seconds_ = std::nullopt);
    static InputMediaPhotoExternal read(Reader reader);
    std::string write();
};

class InputMediaDocumentExternal
{
private:
    int __id = 0xfb52dc99;

public:
    std::string url;
    std::optional<int> ttl_seconds;
    InputMediaDocumentExternal(std::string url_, std::optional<int> ttl_seconds_ = std::nullopt);
    static InputMediaDocumentExternal read(Reader reader);
    std::string write();
};

class InputMediaGame
{
private:
    int __id = 0xd33f43f3;

public:
    TLObject id;
    InputMediaGame(TLObject id_);
    static InputMediaGame read(Reader reader);
    std::string write();
};

class InputMediaInvoice
{
private:
    int __id = 0xd9799874;

public:
    std::string title;
    std::string description;
    std::optional<TLObject> photo;
    TLObject invoice;
    std::string payload;
    std::string provider;
    TLObject provider_data;
    std::optional<std::string> start_param;
    InputMediaInvoice(std::string title_, std::string description_, TLObject invoice_, std::string payload_, std::string provider_, TLObject provider_data_, std::optional<TLObject> photo_ = std::nullopt, std::optional<std::string> start_param_ = std::nullopt);
    static InputMediaInvoice read(Reader reader);
    std::string write();
};

class InputMediaGeoLive
{
private:
    int __id = 0x971fa843;

public:
    std::optional<bool> stopped;
    TLObject geo_point;
    std::optional<int> heading;
    std::optional<int> period;
    std::optional<int> proximity_notification_radius;
    InputMediaGeoLive(TLObject geo_point_, std::optional<bool> stopped_ = std::nullopt, std::optional<int> heading_ = std::nullopt, std::optional<int> period_ = std::nullopt, std::optional<int> proximity_notification_radius_ = std::nullopt);
    static InputMediaGeoLive read(Reader reader);
    std::string write();
};

class InputMediaPoll
{
private:
    int __id = 0xf94e5f1;

public:
    TLObject poll;
    std::optional<std::vector<std::string>> correct_answers;
    std::optional<std::string> solution;
    std::optional<std::vector<TLObject>> solution_entities;
    InputMediaPoll(TLObject poll_, std::optional<std::vector<std::string>> correct_answers_ = std::nullopt, std::optional<std::string> solution_ = std::nullopt, std::optional<std::vector<TLObject>> solution_entities_ = std::nullopt);
    static InputMediaPoll read(Reader reader);
    std::string write();
};

class InputMediaDice
{
private:
    int __id = 0xe66fbf7b;

public:
    std::string emoticon;
    InputMediaDice(std::string emoticon_);
    static InputMediaDice read(Reader reader);
    std::string write();
};

class InputChatPhotoEmpty
{
private:
    int __id = 0x1ca48f57;

public:
    InputChatPhotoEmpty() = default;
    static InputChatPhotoEmpty read(Reader reader);
    std::string write();
};

class InputChatUploadedPhoto
{
private:
    int __id = 0xc642724e;

public:
    std::optional<TLObject> file;
    std::optional<TLObject> video;
    std::optional<double> video_start_ts;
    InputChatUploadedPhoto(std::optional<TLObject> file_ = std::nullopt, std::optional<TLObject> video_ = std::nullopt, std::optional<double> video_start_ts_ = std::nullopt);
    static InputChatUploadedPhoto read(Reader reader);
    std::string write();
};

class InputChatPhoto
{
private:
    int __id = 0x8953ad37;

public:
    TLObject id;
    InputChatPhoto(TLObject id_);
    static InputChatPhoto read(Reader reader);
    std::string write();
};

class InputGeoPointEmpty
{
private:
    int __id = 0xe4c123d6;

public:
    InputGeoPointEmpty() = default;
    static InputGeoPointEmpty read(Reader reader);
    std::string write();
};

class InputGeoPoint
{
private:
    int __id = 0x48222faf;

public:
    double lat;
    double long_;
    std::optional<int> accuracy_radius;
    InputGeoPoint(double lat_, double long__, std::optional<int> accuracy_radius_ = std::nullopt);
    static InputGeoPoint read(Reader reader);
    std::string write();
};

class InputPhotoEmpty
{
private:
    int __id = 0x1cd7bf0d;

public:
    InputPhotoEmpty() = default;
    static InputPhotoEmpty read(Reader reader);
    std::string write();
};

class InputPhoto
{
private:
    int __id = 0x3bb3b94a;

public:
    long id;
    long access_hash;
    std::string file_reference;
    InputPhoto(long id_, long access_hash_, std::string file_reference_);
    static InputPhoto read(Reader reader);
    std::string write();
};

class InputFileLocation
{
private:
    int __id = 0xdfdaabe1;

public:
    long volume_id;
    int local_id;
    long secret;
    std::string file_reference;
    InputFileLocation(long volume_id_, int local_id_, long secret_, std::string file_reference_);
    static InputFileLocation read(Reader reader);
    std::string write();
};

class InputEncryptedFileLocation
{
private:
    int __id = 0xf5235d55;

public:
    long id;
    long access_hash;
    InputEncryptedFileLocation(long id_, long access_hash_);
    static InputEncryptedFileLocation read(Reader reader);
    std::string write();
};

class InputDocumentFileLocation
{
private:
    int __id = 0xbad07584;

public:
    long id;
    long access_hash;
    std::string file_reference;
    std::string thumb_size;
    InputDocumentFileLocation(long id_, long access_hash_, std::string file_reference_, std::string thumb_size_);
    static InputDocumentFileLocation read(Reader reader);
    std::string write();
};

class InputSecureFileLocation
{
private:
    int __id = 0xcbc7ee28;

public:
    long id;
    long access_hash;
    InputSecureFileLocation(long id_, long access_hash_);
    static InputSecureFileLocation read(Reader reader);
    std::string write();
};

class InputTakeoutFileLocation
{
private:
    int __id = 0x29be5899;

public:
    InputTakeoutFileLocation() = default;
    static InputTakeoutFileLocation read(Reader reader);
    std::string write();
};

class InputPhotoFileLocation
{
private:
    int __id = 0x40181ffe;

public:
    long id;
    long access_hash;
    std::string file_reference;
    std::string thumb_size;
    InputPhotoFileLocation(long id_, long access_hash_, std::string file_reference_, std::string thumb_size_);
    static InputPhotoFileLocation read(Reader reader);
    std::string write();
};

class InputPhotoLegacyFileLocation
{
private:
    int __id = 0xd83466f3;

public:
    long id;
    long access_hash;
    std::string file_reference;
    long volume_id;
    int local_id;
    long secret;
    InputPhotoLegacyFileLocation(long id_, long access_hash_, std::string file_reference_, long volume_id_, int local_id_, long secret_);
    static InputPhotoLegacyFileLocation read(Reader reader);
    std::string write();
};

class InputPeerPhotoFileLocation
{
private:
    int __id = 0x37257e99;

public:
    std::optional<bool> big;
    TLObject peer;
    long photo_id;
    InputPeerPhotoFileLocation(TLObject peer_, long photo_id_, std::optional<bool> big_ = std::nullopt);
    static InputPeerPhotoFileLocation read(Reader reader);
    std::string write();
};

class InputStickerSetThumb
{
private:
    int __id = 0x9d84f3db;

public:
    TLObject stickerset;
    int thumb_version;
    InputStickerSetThumb(TLObject stickerset_, int thumb_version_);
    static InputStickerSetThumb read(Reader reader);
    std::string write();
};

class InputGroupCallStream
{
private:
    int __id = 0xbba51639;

public:
    TLObject call;
    long time_ms;
    int scale;
    InputGroupCallStream(TLObject call_, long time_ms_, int scale_);
    static InputGroupCallStream read(Reader reader);
    std::string write();
};

class PeerUser
{
private:
    int __id = 0x9db1bc6d;

public:
    int user_id;
    PeerUser(int user_id_);
    static PeerUser read(Reader reader);
    std::string write();
};

class PeerChat
{
private:
    int __id = 0xbad0e5bb;

public:
    int chat_id;
    PeerChat(int chat_id_);
    static PeerChat read(Reader reader);
    std::string write();
};

class PeerChannel
{
private:
    int __id = 0xbddde532;

public:
    int channel_id;
    PeerChannel(int channel_id_);
    static PeerChannel read(Reader reader);
    std::string write();
};

class UserEmpty
{
private:
    int __id = 0x200250ba;

public:
    int id;
    UserEmpty(int id_);
    static UserEmpty read(Reader reader);
    std::string write();
};

class User
{
private:
    int __id = 0x938458c1;

public:
    std::optional<bool> self;
    std::optional<bool> contact;
    std::optional<bool> mutual_contact;
    std::optional<bool> deleted;
    std::optional<bool> bot;
    std::optional<bool> bot_chat_history;
    std::optional<bool> bot_nochats;
    std::optional<bool> verified;
    std::optional<bool> restricted;
    std::optional<bool> min;
    std::optional<bool> bot_inline_geo;
    std::optional<bool> support;
    std::optional<bool> scam;
    std::optional<bool> apply_min_photo;
    std::optional<bool> fake;
    int id;
    std::optional<long> access_hash;
    std::optional<std::string> first_name;
    std::optional<std::string> last_name;
    std::optional<std::string> username;
    std::optional<std::string> phone;
    std::optional<TLObject> photo;
    std::optional<TLObject> status;
    std::optional<int> bot_info_version;
    std::optional<std::vector<TLObject>> restriction_reason;
    std::optional<std::string> bot_inline_placeholder;
    std::optional<std::string> lang_code;
    User(int id_, std::optional<bool> self_ = std::nullopt, std::optional<bool> contact_ = std::nullopt, std::optional<bool> mutual_contact_ = std::nullopt, std::optional<bool> deleted_ = std::nullopt, std::optional<bool> bot_ = std::nullopt, std::optional<bool> bot_chat_history_ = std::nullopt, std::optional<bool> bot_nochats_ = std::nullopt, std::optional<bool> verified_ = std::nullopt, std::optional<bool> restricted_ = std::nullopt, std::optional<bool> min_ = std::nullopt, std::optional<bool> bot_inline_geo_ = std::nullopt, std::optional<bool> support_ = std::nullopt, std::optional<bool> scam_ = std::nullopt, std::optional<bool> apply_min_photo_ = std::nullopt, std::optional<bool> fake_ = std::nullopt, std::optional<long> access_hash_ = std::nullopt, std::optional<std::string> first_name_ = std::nullopt, std::optional<std::string> last_name_ = std::nullopt, std::optional<std::string> username_ = std::nullopt, std::optional<std::string> phone_ = std::nullopt, std::optional<TLObject> photo_ = std::nullopt, std::optional<TLObject> status_ = std::nullopt, std::optional<int> bot_info_version_ = std::nullopt, std::optional<std::vector<TLObject>> restriction_reason_ = std::nullopt, std::optional<std::string> bot_inline_placeholder_ = std::nullopt, std::optional<std::string> lang_code_ = std::nullopt);
    static User read(Reader reader);
    std::string write();
};

class UserProfilePhotoEmpty
{
private:
    int __id = 0x4f11bae1;

public:
    UserProfilePhotoEmpty() = default;
    static UserProfilePhotoEmpty read(Reader reader);
    std::string write();
};

class UserProfilePhoto
{
private:
    int __id = 0x82d1f706;

public:
    std::optional<bool> has_video;
    long photo_id;
    std::optional<std::string> stripped_thumb;
    int dc_id;
    UserProfilePhoto(long photo_id_, int dc_id_, std::optional<bool> has_video_ = std::nullopt, std::optional<std::string> stripped_thumb_ = std::nullopt);
    static UserProfilePhoto read(Reader reader);
    std::string write();
};

class UserStatusEmpty
{
private:
    int __id = 0x9d05049;

public:
    UserStatusEmpty() = default;
    static UserStatusEmpty read(Reader reader);
    std::string write();
};

class UserStatusOnline
{
private:
    int __id = 0xedb93949;

public:
    int expires;
    UserStatusOnline(int expires_);
    static UserStatusOnline read(Reader reader);
    std::string write();
};

class UserStatusOffline
{
private:
    int __id = 0x8c703f;

public:
    int was_online;
    UserStatusOffline(int was_online_);
    static UserStatusOffline read(Reader reader);
    std::string write();
};

class UserStatusRecently
{
private:
    int __id = 0xe26f42f1;

public:
    UserStatusRecently() = default;
    static UserStatusRecently read(Reader reader);
    std::string write();
};

class UserStatusLastWeek
{
private:
    int __id = 0x7bf09fc;

public:
    UserStatusLastWeek() = default;
    static UserStatusLastWeek read(Reader reader);
    std::string write();
};

class UserStatusLastMonth
{
private:
    int __id = 0x77ebc742;

public:
    UserStatusLastMonth() = default;
    static UserStatusLastMonth read(Reader reader);
    std::string write();
};

class ChatEmpty
{
private:
    int __id = 0x9ba2d800;

public:
    int id;
    ChatEmpty(int id_);
    static ChatEmpty read(Reader reader);
    std::string write();
};

class Chat
{
private:
    int __id = 0x3bda1bde;

public:
    std::optional<bool> creator;
    std::optional<bool> kicked;
    std::optional<bool> left;
    std::optional<bool> deactivated;
    std::optional<bool> call_active;
    std::optional<bool> call_not_empty;
    int id;
    std::string title;
    TLObject photo;
    int participants_count;
    int date;
    int version;
    std::optional<TLObject> migrated_to;
    std::optional<TLObject> admin_rights;
    std::optional<TLObject> default_banned_rights;
    Chat(int id_, std::string title_, TLObject photo_, int participants_count_, int date_, int version_, std::optional<bool> creator_ = std::nullopt, std::optional<bool> kicked_ = std::nullopt, std::optional<bool> left_ = std::nullopt, std::optional<bool> deactivated_ = std::nullopt, std::optional<bool> call_active_ = std::nullopt, std::optional<bool> call_not_empty_ = std::nullopt, std::optional<TLObject> migrated_to_ = std::nullopt, std::optional<TLObject> admin_rights_ = std::nullopt, std::optional<TLObject> default_banned_rights_ = std::nullopt);
    static Chat read(Reader reader);
    std::string write();
};

class ChatForbidden
{
private:
    int __id = 0x7328bdb;

public:
    int id;
    std::string title;
    ChatForbidden(int id_, std::string title_);
    static ChatForbidden read(Reader reader);
    std::string write();
};

class Channel
{
private:
    int __id = 0xd31a961e;

public:
    std::optional<bool> creator;
    std::optional<bool> left;
    std::optional<bool> broadcast;
    std::optional<bool> verified;
    std::optional<bool> megagroup;
    std::optional<bool> restricted;
    std::optional<bool> signatures;
    std::optional<bool> min;
    std::optional<bool> scam;
    std::optional<bool> has_link;
    std::optional<bool> has_geo;
    std::optional<bool> slowmode_enabled;
    std::optional<bool> call_active;
    std::optional<bool> call_not_empty;
    std::optional<bool> fake;
    std::optional<bool> gigagroup;
    int id;
    std::optional<long> access_hash;
    std::string title;
    std::optional<std::string> username;
    TLObject photo;
    int date;
    int version;
    std::optional<std::vector<TLObject>> restriction_reason;
    std::optional<TLObject> admin_rights;
    std::optional<TLObject> banned_rights;
    std::optional<TLObject> default_banned_rights;
    std::optional<int> participants_count;
    Channel(int id_, std::string title_, TLObject photo_, int date_, int version_, std::optional<bool> creator_ = std::nullopt, std::optional<bool> left_ = std::nullopt, std::optional<bool> broadcast_ = std::nullopt, std::optional<bool> verified_ = std::nullopt, std::optional<bool> megagroup_ = std::nullopt, std::optional<bool> restricted_ = std::nullopt, std::optional<bool> signatures_ = std::nullopt, std::optional<bool> min_ = std::nullopt, std::optional<bool> scam_ = std::nullopt, std::optional<bool> has_link_ = std::nullopt, std::optional<bool> has_geo_ = std::nullopt, std::optional<bool> slowmode_enabled_ = std::nullopt, std::optional<bool> call_active_ = std::nullopt, std::optional<bool> call_not_empty_ = std::nullopt, std::optional<bool> fake_ = std::nullopt, std::optional<bool> gigagroup_ = std::nullopt, std::optional<long> access_hash_ = std::nullopt, std::optional<std::string> username_ = std::nullopt, std::optional<std::vector<TLObject>> restriction_reason_ = std::nullopt, std::optional<TLObject> admin_rights_ = std::nullopt, std::optional<TLObject> banned_rights_ = std::nullopt, std::optional<TLObject> default_banned_rights_ = std::nullopt, std::optional<int> participants_count_ = std::nullopt);
    static Channel read(Reader reader);
    std::string write();
};

class ChannelForbidden
{
private:
    int __id = 0x289da732;

public:
    std::optional<bool> broadcast;
    std::optional<bool> megagroup;
    int id;
    long access_hash;
    std::string title;
    std::optional<int> until_date;
    ChannelForbidden(int id_, long access_hash_, std::string title_, std::optional<bool> broadcast_ = std::nullopt, std::optional<bool> megagroup_ = std::nullopt, std::optional<int> until_date_ = std::nullopt);
    static ChannelForbidden read(Reader reader);
    std::string write();
};

class ChatFull
{
private:
    int __id = 0x8a1e2983;

public:
    std::optional<bool> can_set_username;
    std::optional<bool> has_scheduled;
    int id;
    std::string about;
    TLObject participants;
    std::optional<TLObject> chat_photo;
    TLObject notify_settings;
    std::optional<TLObject> exported_invite;
    std::optional<std::vector<TLObject>> bot_info;
    std::optional<int> pinned_msg_id;
    std::optional<int> folder_id;
    std::optional<TLObject> call;
    std::optional<int> ttl_period;
    std::optional<TLObject> groupcall_default_join_as;
    ChatFull(int id_, std::string about_, TLObject participants_, TLObject notify_settings_, std::optional<bool> can_set_username_ = std::nullopt, std::optional<bool> has_scheduled_ = std::nullopt, std::optional<TLObject> chat_photo_ = std::nullopt, std::optional<TLObject> exported_invite_ = std::nullopt, std::optional<std::vector<TLObject>> bot_info_ = std::nullopt, std::optional<int> pinned_msg_id_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt, std::optional<TLObject> call_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt, std::optional<TLObject> groupcall_default_join_as_ = std::nullopt);
    static ChatFull read(Reader reader);
    std::string write();
};

class ChannelFull
{
private:
    int __id = 0x548c3f93;

public:
    std::optional<bool> can_view_participants;
    std::optional<bool> can_set_username;
    std::optional<bool> can_set_stickers;
    std::optional<bool> hidden_prehistory;
    std::optional<bool> can_set_location;
    std::optional<bool> has_scheduled;
    std::optional<bool> can_view_stats;
    std::optional<bool> blocked;
    int id;
    std::string about;
    std::optional<int> participants_count;
    std::optional<int> admins_count;
    std::optional<int> kicked_count;
    std::optional<int> banned_count;
    std::optional<int> online_count;
    int read_inbox_max_id;
    int read_outbox_max_id;
    int unread_count;
    TLObject chat_photo;
    TLObject notify_settings;
    std::optional<TLObject> exported_invite;
    std::vector<TLObject> bot_info;
    std::optional<int> migrated_from_chat_id;
    std::optional<int> migrated_from_max_id;
    std::optional<int> pinned_msg_id;
    std::optional<TLObject> stickerset;
    std::optional<int> available_min_id;
    std::optional<int> folder_id;
    std::optional<int> linked_chat_id;
    std::optional<TLObject> location;
    std::optional<int> slowmode_seconds;
    std::optional<int> slowmode_next_send_date;
    std::optional<int> stats_dc;
    int pts;
    std::optional<TLObject> call;
    std::optional<int> ttl_period;
    std::optional<std::vector<std::string>> pending_suggestions;
    std::optional<TLObject> groupcall_default_join_as;
    ChannelFull(int id_, std::string about_, int read_inbox_max_id_, int read_outbox_max_id_, int unread_count_, TLObject chat_photo_, TLObject notify_settings_, std::vector<TLObject> bot_info_, int pts_, std::optional<bool> can_view_participants_ = std::nullopt, std::optional<bool> can_set_username_ = std::nullopt, std::optional<bool> can_set_stickers_ = std::nullopt, std::optional<bool> hidden_prehistory_ = std::nullopt, std::optional<bool> can_set_location_ = std::nullopt, std::optional<bool> has_scheduled_ = std::nullopt, std::optional<bool> can_view_stats_ = std::nullopt, std::optional<bool> blocked_ = std::nullopt, std::optional<int> participants_count_ = std::nullopt, std::optional<int> admins_count_ = std::nullopt, std::optional<int> kicked_count_ = std::nullopt, std::optional<int> banned_count_ = std::nullopt, std::optional<int> online_count_ = std::nullopt, std::optional<TLObject> exported_invite_ = std::nullopt, std::optional<int> migrated_from_chat_id_ = std::nullopt, std::optional<int> migrated_from_max_id_ = std::nullopt, std::optional<int> pinned_msg_id_ = std::nullopt, std::optional<TLObject> stickerset_ = std::nullopt, std::optional<int> available_min_id_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt, std::optional<int> linked_chat_id_ = std::nullopt, std::optional<TLObject> location_ = std::nullopt, std::optional<int> slowmode_seconds_ = std::nullopt, std::optional<int> slowmode_next_send_date_ = std::nullopt, std::optional<int> stats_dc_ = std::nullopt, std::optional<TLObject> call_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt, std::optional<std::vector<std::string>> pending_suggestions_ = std::nullopt, std::optional<TLObject> groupcall_default_join_as_ = std::nullopt);
    static ChannelFull read(Reader reader);
    std::string write();
};

class ChatParticipant
{
private:
    int __id = 0xc8d7493e;

public:
    int user_id;
    int inviter_id;
    int date;
    ChatParticipant(int user_id_, int inviter_id_, int date_);
    static ChatParticipant read(Reader reader);
    std::string write();
};

class ChatParticipantCreator
{
private:
    int __id = 0xda13538a;

public:
    int user_id;
    ChatParticipantCreator(int user_id_);
    static ChatParticipantCreator read(Reader reader);
    std::string write();
};

class ChatParticipantAdmin
{
private:
    int __id = 0xe2d6e436;

public:
    int user_id;
    int inviter_id;
    int date;
    ChatParticipantAdmin(int user_id_, int inviter_id_, int date_);
    static ChatParticipantAdmin read(Reader reader);
    std::string write();
};

class ChatParticipantsForbidden
{
private:
    int __id = 0xfc900c2b;

public:
    int chat_id;
    std::optional<TLObject> self_participant;
    ChatParticipantsForbidden(int chat_id_, std::optional<TLObject> self_participant_ = std::nullopt);
    static ChatParticipantsForbidden read(Reader reader);
    std::string write();
};

class ChatParticipants
{
private:
    int __id = 0x3f460fed;

public:
    int chat_id;
    std::vector<TLObject> participants;
    int version;
    ChatParticipants(int chat_id_, std::vector<TLObject> participants_, int version_);
    static ChatParticipants read(Reader reader);
    std::string write();
};

class ChatPhotoEmpty
{
private:
    int __id = 0x37c1011c;

public:
    ChatPhotoEmpty() = default;
    static ChatPhotoEmpty read(Reader reader);
    std::string write();
};

class ChatPhoto
{
private:
    int __id = 0x1c6e1c11;

public:
    std::optional<bool> has_video;
    long photo_id;
    std::optional<std::string> stripped_thumb;
    int dc_id;
    ChatPhoto(long photo_id_, int dc_id_, std::optional<bool> has_video_ = std::nullopt, std::optional<std::string> stripped_thumb_ = std::nullopt);
    static ChatPhoto read(Reader reader);
    std::string write();
};

class MessageEmpty
{
private:
    int __id = 0x90a6ca84;

public:
    int id;
    std::optional<TLObject> peer_id;
    MessageEmpty(int id_, std::optional<TLObject> peer_id_ = std::nullopt);
    static MessageEmpty read(Reader reader);
    std::string write();
};

class Message
{
private:
    int __id = 0xbce383d2;

public:
    std::optional<bool> out;
    std::optional<bool> mentioned;
    std::optional<bool> media_unread;
    std::optional<bool> silent;
    std::optional<bool> post;
    std::optional<bool> from_scheduled;
    std::optional<bool> legacy;
    std::optional<bool> edit_hide;
    std::optional<bool> pinned;
    int id;
    std::optional<TLObject> from_id;
    TLObject peer_id;
    std::optional<TLObject> fwd_from;
    std::optional<int> via_bot_id;
    std::optional<TLObject> reply_to;
    int date;
    std::string message;
    std::optional<TLObject> media;
    std::optional<TLObject> reply_markup;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> views;
    std::optional<int> forwards;
    std::optional<TLObject> replies;
    std::optional<int> edit_date;
    std::optional<std::string> post_author;
    std::optional<long> grouped_id;
    std::optional<std::vector<TLObject>> restriction_reason;
    std::optional<int> ttl_period;
    Message(int id_, TLObject peer_id_, int date_, std::string message_, std::optional<bool> out_ = std::nullopt, std::optional<bool> mentioned_ = std::nullopt, std::optional<bool> media_unread_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<bool> post_ = std::nullopt, std::optional<bool> from_scheduled_ = std::nullopt, std::optional<bool> legacy_ = std::nullopt, std::optional<bool> edit_hide_ = std::nullopt, std::optional<bool> pinned_ = std::nullopt, std::optional<TLObject> from_id_ = std::nullopt, std::optional<TLObject> fwd_from_ = std::nullopt, std::optional<int> via_bot_id_ = std::nullopt, std::optional<TLObject> reply_to_ = std::nullopt, std::optional<TLObject> media_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> views_ = std::nullopt, std::optional<int> forwards_ = std::nullopt, std::optional<TLObject> replies_ = std::nullopt, std::optional<int> edit_date_ = std::nullopt, std::optional<std::string> post_author_ = std::nullopt, std::optional<long> grouped_id_ = std::nullopt, std::optional<std::vector<TLObject>> restriction_reason_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static Message read(Reader reader);
    std::string write();
};

class MessageService
{
private:
    int __id = 0x2b085862;

public:
    std::optional<bool> out;
    std::optional<bool> mentioned;
    std::optional<bool> media_unread;
    std::optional<bool> silent;
    std::optional<bool> post;
    std::optional<bool> legacy;
    int id;
    std::optional<TLObject> from_id;
    TLObject peer_id;
    std::optional<TLObject> reply_to;
    int date;
    TLObject action;
    std::optional<int> ttl_period;
    MessageService(int id_, TLObject peer_id_, int date_, TLObject action_, std::optional<bool> out_ = std::nullopt, std::optional<bool> mentioned_ = std::nullopt, std::optional<bool> media_unread_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<bool> post_ = std::nullopt, std::optional<bool> legacy_ = std::nullopt, std::optional<TLObject> from_id_ = std::nullopt, std::optional<TLObject> reply_to_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static MessageService read(Reader reader);
    std::string write();
};

class MessageMediaEmpty
{
private:
    int __id = 0x3ded6320;

public:
    MessageMediaEmpty() = default;
    static MessageMediaEmpty read(Reader reader);
    std::string write();
};

class MessageMediaPhoto
{
private:
    int __id = 0x695150d7;

public:
    std::optional<TLObject> photo;
    std::optional<int> ttl_seconds;
    MessageMediaPhoto(std::optional<TLObject> photo_ = std::nullopt, std::optional<int> ttl_seconds_ = std::nullopt);
    static MessageMediaPhoto read(Reader reader);
    std::string write();
};

class MessageMediaGeo
{
private:
    int __id = 0x56e0d474;

public:
    TLObject geo;
    MessageMediaGeo(TLObject geo_);
    static MessageMediaGeo read(Reader reader);
    std::string write();
};

class MessageMediaContact
{
private:
    int __id = 0xcbf24940;

public:
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string vcard;
    int user_id;
    MessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, int user_id_);
    static MessageMediaContact read(Reader reader);
    std::string write();
};

class MessageMediaUnsupported
{
private:
    int __id = 0x9f84f49e;

public:
    MessageMediaUnsupported() = default;
    static MessageMediaUnsupported read(Reader reader);
    std::string write();
};

class MessageMediaDocument
{
private:
    int __id = 0x9cb070d7;

public:
    std::optional<TLObject> document;
    std::optional<int> ttl_seconds;
    MessageMediaDocument(std::optional<TLObject> document_ = std::nullopt, std::optional<int> ttl_seconds_ = std::nullopt);
    static MessageMediaDocument read(Reader reader);
    std::string write();
};

class MessageMediaWebPage
{
private:
    int __id = 0xa32dd600;

public:
    TLObject webpage;
    MessageMediaWebPage(TLObject webpage_);
    static MessageMediaWebPage read(Reader reader);
    std::string write();
};

class MessageMediaVenue
{
private:
    int __id = 0x2ec0533f;

public:
    TLObject geo;
    std::string title;
    std::string address;
    std::string provider;
    std::string venue_id;
    std::string venue_type;
    MessageMediaVenue(TLObject geo_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_);
    static MessageMediaVenue read(Reader reader);
    std::string write();
};

class MessageMediaGame
{
private:
    int __id = 0xfdb19008;

public:
    TLObject game;
    MessageMediaGame(TLObject game_);
    static MessageMediaGame read(Reader reader);
    std::string write();
};

class MessageMediaInvoice
{
private:
    int __id = 0x84551347;

public:
    std::optional<bool> shipping_address_requested;
    std::optional<bool> test;
    std::string title;
    std::string description;
    std::optional<TLObject> photo;
    std::optional<int> receipt_msg_id;
    std::string currency;
    long total_amount;
    std::string start_param;
    MessageMediaInvoice(std::string title_, std::string description_, std::string currency_, long total_amount_, std::string start_param_, std::optional<bool> shipping_address_requested_ = std::nullopt, std::optional<bool> test_ = std::nullopt, std::optional<TLObject> photo_ = std::nullopt, std::optional<int> receipt_msg_id_ = std::nullopt);
    static MessageMediaInvoice read(Reader reader);
    std::string write();
};

class MessageMediaGeoLive
{
private:
    int __id = 0xb940c666;

public:
    TLObject geo;
    std::optional<int> heading;
    int period;
    std::optional<int> proximity_notification_radius;
    MessageMediaGeoLive(TLObject geo_, int period_, std::optional<int> heading_ = std::nullopt, std::optional<int> proximity_notification_radius_ = std::nullopt);
    static MessageMediaGeoLive read(Reader reader);
    std::string write();
};

class MessageMediaPoll
{
private:
    int __id = 0x4bd6e798;

public:
    TLObject poll;
    TLObject results;
    MessageMediaPoll(TLObject poll_, TLObject results_);
    static MessageMediaPoll read(Reader reader);
    std::string write();
};

class MessageMediaDice
{
private:
    int __id = 0x3f7ee58b;

public:
    int value;
    std::string emoticon;
    MessageMediaDice(int value_, std::string emoticon_);
    static MessageMediaDice read(Reader reader);
    std::string write();
};

class MessageActionEmpty
{
private:
    int __id = 0xb6aef7b0;

public:
    MessageActionEmpty() = default;
    static MessageActionEmpty read(Reader reader);
    std::string write();
};

class MessageActionChatCreate
{
private:
    int __id = 0xa6638b9a;

public:
    std::string title;
    std::vector<int> users;
    MessageActionChatCreate(std::string title_, std::vector<int> users_);
    static MessageActionChatCreate read(Reader reader);
    std::string write();
};

class MessageActionChatEditTitle
{
private:
    int __id = 0xb5a1ce5a;

public:
    std::string title;
    MessageActionChatEditTitle(std::string title_);
    static MessageActionChatEditTitle read(Reader reader);
    std::string write();
};

class MessageActionChatEditPhoto
{
private:
    int __id = 0x7fcb13a8;

public:
    TLObject photo;
    MessageActionChatEditPhoto(TLObject photo_);
    static MessageActionChatEditPhoto read(Reader reader);
    std::string write();
};

class MessageActionChatDeletePhoto
{
private:
    int __id = 0x95e3fbef;

public:
    MessageActionChatDeletePhoto() = default;
    static MessageActionChatDeletePhoto read(Reader reader);
    std::string write();
};

class MessageActionChatAddUser
{
private:
    int __id = 0x488a7337;

public:
    std::vector<int> users;
    MessageActionChatAddUser(std::vector<int> users_);
    static MessageActionChatAddUser read(Reader reader);
    std::string write();
};

class MessageActionChatDeleteUser
{
private:
    int __id = 0xb2ae9b0c;

public:
    int user_id;
    MessageActionChatDeleteUser(int user_id_);
    static MessageActionChatDeleteUser read(Reader reader);
    std::string write();
};

class MessageActionChatJoinedByLink
{
private:
    int __id = 0xf89cf5e8;

public:
    int inviter_id;
    MessageActionChatJoinedByLink(int inviter_id_);
    static MessageActionChatJoinedByLink read(Reader reader);
    std::string write();
};

class MessageActionChannelCreate
{
private:
    int __id = 0x95d2ac92;

public:
    std::string title;
    MessageActionChannelCreate(std::string title_);
    static MessageActionChannelCreate read(Reader reader);
    std::string write();
};

class MessageActionChatMigrateTo
{
private:
    int __id = 0x51bdb021;

public:
    int channel_id;
    MessageActionChatMigrateTo(int channel_id_);
    static MessageActionChatMigrateTo read(Reader reader);
    std::string write();
};

class MessageActionChannelMigrateFrom
{
private:
    int __id = 0xb055eaee;

public:
    std::string title;
    int chat_id;
    MessageActionChannelMigrateFrom(std::string title_, int chat_id_);
    static MessageActionChannelMigrateFrom read(Reader reader);
    std::string write();
};

class MessageActionPinMessage
{
private:
    int __id = 0x94bd38ed;

public:
    MessageActionPinMessage() = default;
    static MessageActionPinMessage read(Reader reader);
    std::string write();
};

class MessageActionHistoryClear
{
private:
    int __id = 0x9fbab604;

public:
    MessageActionHistoryClear() = default;
    static MessageActionHistoryClear read(Reader reader);
    std::string write();
};

class MessageActionGameScore
{
private:
    int __id = 0x92a72876;

public:
    long game_id;
    int score;
    MessageActionGameScore(long game_id_, int score_);
    static MessageActionGameScore read(Reader reader);
    std::string write();
};

class MessageActionPaymentSentMe
{
private:
    int __id = 0x8f31b327;

public:
    std::string currency;
    long total_amount;
    std::string payload;
    std::optional<TLObject> info;
    std::optional<std::string> shipping_option_id;
    TLObject charge;
    MessageActionPaymentSentMe(std::string currency_, long total_amount_, std::string payload_, TLObject charge_, std::optional<TLObject> info_ = std::nullopt, std::optional<std::string> shipping_option_id_ = std::nullopt);
    static MessageActionPaymentSentMe read(Reader reader);
    std::string write();
};

class MessageActionPaymentSent
{
private:
    int __id = 0x40699cd0;

public:
    std::string currency;
    long total_amount;
    MessageActionPaymentSent(std::string currency_, long total_amount_);
    static MessageActionPaymentSent read(Reader reader);
    std::string write();
};

class MessageActionPhoneCall
{
private:
    int __id = 0x80e11a7f;

public:
    std::optional<bool> video;
    long call_id;
    std::optional<TLObject> reason;
    std::optional<int> duration;
    MessageActionPhoneCall(long call_id_, std::optional<bool> video_ = std::nullopt, std::optional<TLObject> reason_ = std::nullopt, std::optional<int> duration_ = std::nullopt);
    static MessageActionPhoneCall read(Reader reader);
    std::string write();
};

class MessageActionScreenshotTaken
{
private:
    int __id = 0x4792929b;

public:
    MessageActionScreenshotTaken() = default;
    static MessageActionScreenshotTaken read(Reader reader);
    std::string write();
};

class MessageActionCustomAction
{
private:
    int __id = 0xfae69f56;

public:
    std::string message;
    MessageActionCustomAction(std::string message_);
    static MessageActionCustomAction read(Reader reader);
    std::string write();
};

class MessageActionBotAllowed
{
private:
    int __id = 0xabe9affe;

public:
    std::string domain;
    MessageActionBotAllowed(std::string domain_);
    static MessageActionBotAllowed read(Reader reader);
    std::string write();
};

class MessageActionSecureValuesSentMe
{
private:
    int __id = 0x1b287353;

public:
    std::vector<TLObject> values;
    TLObject credentials;
    MessageActionSecureValuesSentMe(std::vector<TLObject> values_, TLObject credentials_);
    static MessageActionSecureValuesSentMe read(Reader reader);
    std::string write();
};

class MessageActionSecureValuesSent
{
private:
    int __id = 0xd95c6154;

public:
    std::vector<TLObject> types;
    MessageActionSecureValuesSent(std::vector<TLObject> types_);
    static MessageActionSecureValuesSent read(Reader reader);
    std::string write();
};

class MessageActionContactSignUp
{
private:
    int __id = 0xf3f25f76;

public:
    MessageActionContactSignUp() = default;
    static MessageActionContactSignUp read(Reader reader);
    std::string write();
};

class MessageActionGeoProximityReached
{
private:
    int __id = 0x98e0d697;

public:
    TLObject from_id;
    TLObject to_id;
    int distance;
    MessageActionGeoProximityReached(TLObject from_id_, TLObject to_id_, int distance_);
    static MessageActionGeoProximityReached read(Reader reader);
    std::string write();
};

class MessageActionGroupCall
{
private:
    int __id = 0x7a0d7f42;

public:
    TLObject call;
    std::optional<int> duration;
    MessageActionGroupCall(TLObject call_, std::optional<int> duration_ = std::nullopt);
    static MessageActionGroupCall read(Reader reader);
    std::string write();
};

class MessageActionInviteToGroupCall
{
private:
    int __id = 0x76b9f11a;

public:
    TLObject call;
    std::vector<int> users;
    MessageActionInviteToGroupCall(TLObject call_, std::vector<int> users_);
    static MessageActionInviteToGroupCall read(Reader reader);
    std::string write();
};

class MessageActionSetMessagesTTL
{
private:
    int __id = 0xaa1afbfd;

public:
    int period;
    MessageActionSetMessagesTTL(int period_);
    static MessageActionSetMessagesTTL read(Reader reader);
    std::string write();
};

class MessageActionGroupCallScheduled
{
private:
    int __id = 0xb3a07661;

public:
    TLObject call;
    int schedule_date;
    MessageActionGroupCallScheduled(TLObject call_, int schedule_date_);
    static MessageActionGroupCallScheduled read(Reader reader);
    std::string write();
};

class Dialog
{
private:
    int __id = 0x2c171f72;

public:
    std::optional<bool> pinned;
    std::optional<bool> unread_mark;
    TLObject peer;
    int top_message;
    int read_inbox_max_id;
    int read_outbox_max_id;
    int unread_count;
    int unread_mentions_count;
    TLObject notify_settings;
    std::optional<int> pts;
    std::optional<TLObject> draft;
    std::optional<int> folder_id;
    Dialog(TLObject peer_, int top_message_, int read_inbox_max_id_, int read_outbox_max_id_, int unread_count_, int unread_mentions_count_, TLObject notify_settings_, std::optional<bool> pinned_ = std::nullopt, std::optional<bool> unread_mark_ = std::nullopt, std::optional<int> pts_ = std::nullopt, std::optional<TLObject> draft_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt);
    static Dialog read(Reader reader);
    std::string write();
};

class DialogFolder
{
private:
    int __id = 0x71bd134c;

public:
    std::optional<bool> pinned;
    TLObject folder;
    TLObject peer;
    int top_message;
    int unread_muted_peers_count;
    int unread_unmuted_peers_count;
    int unread_muted_messages_count;
    int unread_unmuted_messages_count;
    DialogFolder(TLObject folder_, TLObject peer_, int top_message_, int unread_muted_peers_count_, int unread_unmuted_peers_count_, int unread_muted_messages_count_, int unread_unmuted_messages_count_, std::optional<bool> pinned_ = std::nullopt);
    static DialogFolder read(Reader reader);
    std::string write();
};

class PhotoEmpty
{
private:
    int __id = 0x2331b22d;

public:
    long id;
    PhotoEmpty(long id_);
    static PhotoEmpty read(Reader reader);
    std::string write();
};

class Photo
{
private:
    int __id = 0xfb197a65;

public:
    std::optional<bool> has_stickers;
    long id;
    long access_hash;
    std::string file_reference;
    int date;
    std::vector<TLObject> sizes;
    std::optional<std::vector<TLObject>> video_sizes;
    int dc_id;
    Photo(long id_, long access_hash_, std::string file_reference_, int date_, std::vector<TLObject> sizes_, int dc_id_, std::optional<bool> has_stickers_ = std::nullopt, std::optional<std::vector<TLObject>> video_sizes_ = std::nullopt);
    static Photo read(Reader reader);
    std::string write();
};

class PhotoSizeEmpty
{
private:
    int __id = 0xe17e23c;

public:
    std::string type;
    PhotoSizeEmpty(std::string type_);
    static PhotoSizeEmpty read(Reader reader);
    std::string write();
};

class PhotoSize
{
private:
    int __id = 0x75c78e60;

public:
    std::string type;
    int w;
    int h;
    int size;
    PhotoSize(std::string type_, int w_, int h_, int size_);
    static PhotoSize read(Reader reader);
    std::string write();
};

class PhotoCachedSize
{
private:
    int __id = 0x21e1ad6;

public:
    std::string type;
    int w;
    int h;
    std::string bytes;
    PhotoCachedSize(std::string type_, int w_, int h_, std::string bytes_);
    static PhotoCachedSize read(Reader reader);
    std::string write();
};

class PhotoStrippedSize
{
private:
    int __id = 0xe0b0bc2e;

public:
    std::string type;
    std::string bytes;
    PhotoStrippedSize(std::string type_, std::string bytes_);
    static PhotoStrippedSize read(Reader reader);
    std::string write();
};

class PhotoSizeProgressive
{
private:
    int __id = 0xfa3efb95;

public:
    std::string type;
    int w;
    int h;
    std::vector<int> sizes;
    PhotoSizeProgressive(std::string type_, int w_, int h_, std::vector<int> sizes_);
    static PhotoSizeProgressive read(Reader reader);
    std::string write();
};

class PhotoPathSize
{
private:
    int __id = 0xd8214d41;

public:
    std::string type;
    std::string bytes;
    PhotoPathSize(std::string type_, std::string bytes_);
    static PhotoPathSize read(Reader reader);
    std::string write();
};

class GeoPointEmpty
{
private:
    int __id = 0x1117dd5f;

public:
    GeoPointEmpty() = default;
    static GeoPointEmpty read(Reader reader);
    std::string write();
};

class GeoPoint
{
private:
    int __id = 0xb2a2f663;

public:
    double long_;
    double lat;
    long access_hash;
    std::optional<int> accuracy_radius;
    GeoPoint(double long__, double lat_, long access_hash_, std::optional<int> accuracy_radius_ = std::nullopt);
    static GeoPoint read(Reader reader);
    std::string write();
};

class InputNotifyPeer
{
private:
    int __id = 0xb8bc5b0c;

public:
    TLObject peer;
    InputNotifyPeer(TLObject peer_);
    static InputNotifyPeer read(Reader reader);
    std::string write();
};

class InputNotifyUsers
{
private:
    int __id = 0x193b4417;

public:
    InputNotifyUsers() = default;
    static InputNotifyUsers read(Reader reader);
    std::string write();
};

class InputNotifyChats
{
private:
    int __id = 0x4a95e84e;

public:
    InputNotifyChats() = default;
    static InputNotifyChats read(Reader reader);
    std::string write();
};

class InputNotifyBroadcasts
{
private:
    int __id = 0xb1db7c7e;

public:
    InputNotifyBroadcasts() = default;
    static InputNotifyBroadcasts read(Reader reader);
    std::string write();
};

class InputPeerNotifySettings
{
private:
    int __id = 0x9c3d198e;

public:
    std::optional<bool> show_previews;
    std::optional<bool> silent;
    std::optional<int> mute_until;
    std::optional<std::string> sound;
    InputPeerNotifySettings(std::optional<bool> show_previews_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<int> mute_until_ = std::nullopt, std::optional<std::string> sound_ = std::nullopt);
    static InputPeerNotifySettings read(Reader reader);
    std::string write();
};

class PeerNotifySettings
{
private:
    int __id = 0xaf509d20;

public:
    std::optional<bool> show_previews;
    std::optional<bool> silent;
    std::optional<int> mute_until;
    std::optional<std::string> sound;
    PeerNotifySettings(std::optional<bool> show_previews_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<int> mute_until_ = std::nullopt, std::optional<std::string> sound_ = std::nullopt);
    static PeerNotifySettings read(Reader reader);
    std::string write();
};

class PeerSettings
{
private:
    int __id = 0x733f2961;

public:
    std::optional<bool> report_spam;
    std::optional<bool> add_contact;
    std::optional<bool> block_contact;
    std::optional<bool> share_contact;
    std::optional<bool> need_contacts_exception;
    std::optional<bool> report_geo;
    std::optional<bool> autoarchived;
    std::optional<bool> invite_members;
    std::optional<int> geo_distance;
    PeerSettings(std::optional<bool> report_spam_ = std::nullopt, std::optional<bool> add_contact_ = std::nullopt, std::optional<bool> block_contact_ = std::nullopt, std::optional<bool> share_contact_ = std::nullopt, std::optional<bool> need_contacts_exception_ = std::nullopt, std::optional<bool> report_geo_ = std::nullopt, std::optional<bool> autoarchived_ = std::nullopt, std::optional<bool> invite_members_ = std::nullopt, std::optional<int> geo_distance_ = std::nullopt);
    static PeerSettings read(Reader reader);
    std::string write();
};

class WallPaper
{
private:
    int __id = 0xa437c3ed;

public:
    long id;
    std::optional<bool> creator;
    std::optional<bool> default;
    std::optional<bool> pattern;
    std::optional<bool> dark;
    long access_hash;
    std::string slug;
    TLObject document;
    std::optional<TLObject> settings;
    WallPaper(long id_, long access_hash_, std::string slug_, TLObject document_, std::optional<bool> creator_ = std::nullopt, std::optional<bool> default_ = std::nullopt, std::optional<bool> pattern_ = std::nullopt, std::optional<bool> dark_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static WallPaper read(Reader reader);
    std::string write();
};

class WallPaperNoFile
{
private:
    int __id = 0xe0804116;

public:
    long id;
    std::optional<bool> default;
    std::optional<bool> dark;
    std::optional<TLObject> settings;
    WallPaperNoFile(long id_, std::optional<bool> default_ = std::nullopt, std::optional<bool> dark_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static WallPaperNoFile read(Reader reader);
    std::string write();
};

class InputReportReasonSpam
{
private:
    int __id = 0x58dbcab8;

public:
    InputReportReasonSpam() = default;
    static InputReportReasonSpam read(Reader reader);
    std::string write();
};

class InputReportReasonViolence
{
private:
    int __id = 0x1e22c78d;

public:
    InputReportReasonViolence() = default;
    static InputReportReasonViolence read(Reader reader);
    std::string write();
};

class InputReportReasonPornography
{
private:
    int __id = 0x2e59d922;

public:
    InputReportReasonPornography() = default;
    static InputReportReasonPornography read(Reader reader);
    std::string write();
};

class InputReportReasonChildAbuse
{
private:
    int __id = 0xadf44ee3;

public:
    InputReportReasonChildAbuse() = default;
    static InputReportReasonChildAbuse read(Reader reader);
    std::string write();
};

class InputReportReasonOther
{
private:
    int __id = 0xc1e4a2b1;

public:
    InputReportReasonOther() = default;
    static InputReportReasonOther read(Reader reader);
    std::string write();
};

class InputReportReasonCopyright
{
private:
    int __id = 0x9b89f93a;

public:
    InputReportReasonCopyright() = default;
    static InputReportReasonCopyright read(Reader reader);
    std::string write();
};

class InputReportReasonGeoIrrelevant
{
private:
    int __id = 0xdbd4feed;

public:
    InputReportReasonGeoIrrelevant() = default;
    static InputReportReasonGeoIrrelevant read(Reader reader);
    std::string write();
};

class InputReportReasonFake
{
private:
    int __id = 0xf5ddd6e7;

public:
    InputReportReasonFake() = default;
    static InputReportReasonFake read(Reader reader);
    std::string write();
};

class UserFull
{
private:
    int __id = 0x139a9a77;

public:
    std::optional<bool> blocked;
    std::optional<bool> phone_calls_available;
    std::optional<bool> phone_calls_private;
    std::optional<bool> can_pin_message;
    std::optional<bool> has_scheduled;
    std::optional<bool> video_calls_available;
    TLObject user;
    std::optional<std::string> about;
    TLObject settings;
    std::optional<TLObject> profile_photo;
    TLObject notify_settings;
    std::optional<TLObject> bot_info;
    std::optional<int> pinned_msg_id;
    int common_chats_count;
    std::optional<int> folder_id;
    std::optional<int> ttl_period;
    UserFull(TLObject user_, TLObject settings_, TLObject notify_settings_, int common_chats_count_, std::optional<bool> blocked_ = std::nullopt, std::optional<bool> phone_calls_available_ = std::nullopt, std::optional<bool> phone_calls_private_ = std::nullopt, std::optional<bool> can_pin_message_ = std::nullopt, std::optional<bool> has_scheduled_ = std::nullopt, std::optional<bool> video_calls_available_ = std::nullopt, std::optional<std::string> about_ = std::nullopt, std::optional<TLObject> profile_photo_ = std::nullopt, std::optional<TLObject> bot_info_ = std::nullopt, std::optional<int> pinned_msg_id_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static UserFull read(Reader reader);
    std::string write();
};

class Contact
{
private:
    int __id = 0xf911c994;

public:
    int user_id;
    bool mutual;
    Contact(int user_id_, bool mutual_);
    static Contact read(Reader reader);
    std::string write();
};

class ImportedContact
{
private:
    int __id = 0xd0028438;

public:
    int user_id;
    long client_id;
    ImportedContact(int user_id_, long client_id_);
    static ImportedContact read(Reader reader);
    std::string write();
};

class ContactStatus
{
private:
    int __id = 0xd3680c61;

public:
    int user_id;
    TLObject status;
    ContactStatus(int user_id_, TLObject status_);
    static ContactStatus read(Reader reader);
    std::string write();
};

class InputMessagesFilterEmpty
{
private:
    int __id = 0x57e2f66c;

public:
    InputMessagesFilterEmpty() = default;
    static InputMessagesFilterEmpty read(Reader reader);
    std::string write();
};

class InputMessagesFilterPhotos
{
private:
    int __id = 0x9609a51c;

public:
    InputMessagesFilterPhotos() = default;
    static InputMessagesFilterPhotos read(Reader reader);
    std::string write();
};

class InputMessagesFilterVideo
{
private:
    int __id = 0x9fc00e65;

public:
    InputMessagesFilterVideo() = default;
    static InputMessagesFilterVideo read(Reader reader);
    std::string write();
};

class InputMessagesFilterPhotoVideo
{
private:
    int __id = 0x56e9f0e4;

public:
    InputMessagesFilterPhotoVideo() = default;
    static InputMessagesFilterPhotoVideo read(Reader reader);
    std::string write();
};

class InputMessagesFilterDocument
{
private:
    int __id = 0x9eddf188;

public:
    InputMessagesFilterDocument() = default;
    static InputMessagesFilterDocument read(Reader reader);
    std::string write();
};

class InputMessagesFilterUrl
{
private:
    int __id = 0x7ef0dd87;

public:
    InputMessagesFilterUrl() = default;
    static InputMessagesFilterUrl read(Reader reader);
    std::string write();
};

class InputMessagesFilterGif
{
private:
    int __id = 0xffc86587;

public:
    InputMessagesFilterGif() = default;
    static InputMessagesFilterGif read(Reader reader);
    std::string write();
};

class InputMessagesFilterVoice
{
private:
    int __id = 0x50f5c392;

public:
    InputMessagesFilterVoice() = default;
    static InputMessagesFilterVoice read(Reader reader);
    std::string write();
};

class InputMessagesFilterMusic
{
private:
    int __id = 0x3751b49e;

public:
    InputMessagesFilterMusic() = default;
    static InputMessagesFilterMusic read(Reader reader);
    std::string write();
};

class InputMessagesFilterChatPhotos
{
private:
    int __id = 0x3a20ecb8;

public:
    InputMessagesFilterChatPhotos() = default;
    static InputMessagesFilterChatPhotos read(Reader reader);
    std::string write();
};

class InputMessagesFilterPhoneCalls
{
private:
    int __id = 0x80c99768;

public:
    std::optional<bool> missed;
    InputMessagesFilterPhoneCalls(std::optional<bool> missed_ = std::nullopt);
    static InputMessagesFilterPhoneCalls read(Reader reader);
    std::string write();
};

class InputMessagesFilterRoundVoice
{
private:
    int __id = 0x7a7c17a4;

public:
    InputMessagesFilterRoundVoice() = default;
    static InputMessagesFilterRoundVoice read(Reader reader);
    std::string write();
};

class InputMessagesFilterRoundVideo
{
private:
    int __id = 0xb549da53;

public:
    InputMessagesFilterRoundVideo() = default;
    static InputMessagesFilterRoundVideo read(Reader reader);
    std::string write();
};

class InputMessagesFilterMyMentions
{
private:
    int __id = 0xc1f8e69a;

public:
    InputMessagesFilterMyMentions() = default;
    static InputMessagesFilterMyMentions read(Reader reader);
    std::string write();
};

class InputMessagesFilterGeo
{
private:
    int __id = 0xe7026d0d;

public:
    InputMessagesFilterGeo() = default;
    static InputMessagesFilterGeo read(Reader reader);
    std::string write();
};

class InputMessagesFilterContacts
{
private:
    int __id = 0xe062db83;

public:
    InputMessagesFilterContacts() = default;
    static InputMessagesFilterContacts read(Reader reader);
    std::string write();
};

class InputMessagesFilterPinned
{
private:
    int __id = 0x1bb00451;

public:
    InputMessagesFilterPinned() = default;
    static InputMessagesFilterPinned read(Reader reader);
    std::string write();
};

class UpdateNewMessage
{
private:
    int __id = 0x1f2b0afd;

public:
    TLObject message;
    int pts;
    int pts_count;
    UpdateNewMessage(TLObject message_, int pts_, int pts_count_);
    static UpdateNewMessage read(Reader reader);
    std::string write();
};

class UpdateMessageID
{
private:
    int __id = 0x4e90bfd6;

public:
    int id;
    long random_id;
    UpdateMessageID(int id_, long random_id_);
    static UpdateMessageID read(Reader reader);
    std::string write();
};

class UpdateDeleteMessages
{
private:
    int __id = 0xa20db0e5;

public:
    std::vector<int> messages;
    int pts;
    int pts_count;
    UpdateDeleteMessages(std::vector<int> messages_, int pts_, int pts_count_);
    static UpdateDeleteMessages read(Reader reader);
    std::string write();
};

class UpdateUserTyping
{
private:
    int __id = 0x5c486927;

public:
    int user_id;
    TLObject action;
    UpdateUserTyping(int user_id_, TLObject action_);
    static UpdateUserTyping read(Reader reader);
    std::string write();
};

class UpdateChatUserTyping
{
private:
    int __id = 0x86cadb6c;

public:
    int chat_id;
    TLObject from_id;
    TLObject action;
    UpdateChatUserTyping(int chat_id_, TLObject from_id_, TLObject action_);
    static UpdateChatUserTyping read(Reader reader);
    std::string write();
};

class UpdateChatParticipants
{
private:
    int __id = 0x7761198;

public:
    TLObject participants;
    UpdateChatParticipants(TLObject participants_);
    static UpdateChatParticipants read(Reader reader);
    std::string write();
};

class UpdateUserStatus
{
private:
    int __id = 0x1bfbd823;

public:
    int user_id;
    TLObject status;
    UpdateUserStatus(int user_id_, TLObject status_);
    static UpdateUserStatus read(Reader reader);
    std::string write();
};

class UpdateUserName
{
private:
    int __id = 0xa7332b73;

public:
    int user_id;
    std::string first_name;
    std::string last_name;
    std::string username;
    UpdateUserName(int user_id_, std::string first_name_, std::string last_name_, std::string username_);
    static UpdateUserName read(Reader reader);
    std::string write();
};

class UpdateUserPhoto
{
private:
    int __id = 0x95313b0c;

public:
    int user_id;
    int date;
    TLObject photo;
    bool previous;
    UpdateUserPhoto(int user_id_, int date_, TLObject photo_, bool previous_);
    static UpdateUserPhoto read(Reader reader);
    std::string write();
};

class UpdateNewEncryptedMessage
{
private:
    int __id = 0x12bcbd9a;

public:
    TLObject message;
    int qts;
    UpdateNewEncryptedMessage(TLObject message_, int qts_);
    static UpdateNewEncryptedMessage read(Reader reader);
    std::string write();
};

class UpdateEncryptedChatTyping
{
private:
    int __id = 0x1710f156;

public:
    int chat_id;
    UpdateEncryptedChatTyping(int chat_id_);
    static UpdateEncryptedChatTyping read(Reader reader);
    std::string write();
};

class UpdateEncryption
{
private:
    int __id = 0xb4a2e88d;

public:
    TLObject chat;
    int date;
    UpdateEncryption(TLObject chat_, int date_);
    static UpdateEncryption read(Reader reader);
    std::string write();
};

class UpdateEncryptedMessagesRead
{
private:
    int __id = 0x38fe25b7;

public:
    int chat_id;
    int max_date;
    int date;
    UpdateEncryptedMessagesRead(int chat_id_, int max_date_, int date_);
    static UpdateEncryptedMessagesRead read(Reader reader);
    std::string write();
};

class UpdateChatParticipantAdd
{
private:
    int __id = 0xea4b0e5c;

public:
    int chat_id;
    int user_id;
    int inviter_id;
    int date;
    int version;
    UpdateChatParticipantAdd(int chat_id_, int user_id_, int inviter_id_, int date_, int version_);
    static UpdateChatParticipantAdd read(Reader reader);
    std::string write();
};

class UpdateChatParticipantDelete
{
private:
    int __id = 0x6e5f8c22;

public:
    int chat_id;
    int user_id;
    int version;
    UpdateChatParticipantDelete(int chat_id_, int user_id_, int version_);
    static UpdateChatParticipantDelete read(Reader reader);
    std::string write();
};

class UpdateDcOptions
{
private:
    int __id = 0x8e5e9873;

public:
    std::vector<TLObject> dc_options;
    UpdateDcOptions(std::vector<TLObject> dc_options_);
    static UpdateDcOptions read(Reader reader);
    std::string write();
};

class UpdateNotifySettings
{
private:
    int __id = 0xbec268ef;

public:
    TLObject peer;
    TLObject notify_settings;
    UpdateNotifySettings(TLObject peer_, TLObject notify_settings_);
    static UpdateNotifySettings read(Reader reader);
    std::string write();
};

class UpdateServiceNotification
{
private:
    int __id = 0xebe46819;

public:
    std::optional<bool> popup;
    std::optional<int> inbox_date;
    std::string type;
    std::string message;
    TLObject media;
    std::vector<TLObject> entities;
    UpdateServiceNotification(std::string type_, std::string message_, TLObject media_, std::vector<TLObject> entities_, std::optional<bool> popup_ = std::nullopt, std::optional<int> inbox_date_ = std::nullopt);
    static UpdateServiceNotification read(Reader reader);
    std::string write();
};

class UpdatePrivacy
{
private:
    int __id = 0xee3b272a;

public:
    TLObject key;
    std::vector<TLObject> rules;
    UpdatePrivacy(TLObject key_, std::vector<TLObject> rules_);
    static UpdatePrivacy read(Reader reader);
    std::string write();
};

class UpdateUserPhone
{
private:
    int __id = 0x12b9417b;

public:
    int user_id;
    std::string phone;
    UpdateUserPhone(int user_id_, std::string phone_);
    static UpdateUserPhone read(Reader reader);
    std::string write();
};

class UpdateReadHistoryInbox
{
private:
    int __id = 0x9c974fdf;

public:
    std::optional<int> folder_id;
    TLObject peer;
    int max_id;
    int still_unread_count;
    int pts;
    int pts_count;
    UpdateReadHistoryInbox(TLObject peer_, int max_id_, int still_unread_count_, int pts_, int pts_count_, std::optional<int> folder_id_ = std::nullopt);
    static UpdateReadHistoryInbox read(Reader reader);
    std::string write();
};

class UpdateReadHistoryOutbox
{
private:
    int __id = 0x2f2f21bf;

public:
    TLObject peer;
    int max_id;
    int pts;
    int pts_count;
    UpdateReadHistoryOutbox(TLObject peer_, int max_id_, int pts_, int pts_count_);
    static UpdateReadHistoryOutbox read(Reader reader);
    std::string write();
};

class UpdateWebPage
{
private:
    int __id = 0x7f891213;

public:
    TLObject webpage;
    int pts;
    int pts_count;
    UpdateWebPage(TLObject webpage_, int pts_, int pts_count_);
    static UpdateWebPage read(Reader reader);
    std::string write();
};

class UpdateReadMessagesContents
{
private:
    int __id = 0x68c13933;

public:
    std::vector<int> messages;
    int pts;
    int pts_count;
    UpdateReadMessagesContents(std::vector<int> messages_, int pts_, int pts_count_);
    static UpdateReadMessagesContents read(Reader reader);
    std::string write();
};

class UpdateChannelTooLong
{
private:
    int __id = 0xeb0467fb;

public:
    int channel_id;
    std::optional<int> pts;
    UpdateChannelTooLong(int channel_id_, std::optional<int> pts_ = std::nullopt);
    static UpdateChannelTooLong read(Reader reader);
    std::string write();
};

class UpdateChannel
{
private:
    int __id = 0xb6d45656;

public:
    int channel_id;
    UpdateChannel(int channel_id_);
    static UpdateChannel read(Reader reader);
    std::string write();
};

class UpdateNewChannelMessage
{
private:
    int __id = 0x62ba04d9;

public:
    TLObject message;
    int pts;
    int pts_count;
    UpdateNewChannelMessage(TLObject message_, int pts_, int pts_count_);
    static UpdateNewChannelMessage read(Reader reader);
    std::string write();
};

class UpdateReadChannelInbox
{
private:
    int __id = 0x330b5424;

public:
    std::optional<int> folder_id;
    int channel_id;
    int max_id;
    int still_unread_count;
    int pts;
    UpdateReadChannelInbox(int channel_id_, int max_id_, int still_unread_count_, int pts_, std::optional<int> folder_id_ = std::nullopt);
    static UpdateReadChannelInbox read(Reader reader);
    std::string write();
};

class UpdateDeleteChannelMessages
{
private:
    int __id = 0xc37521c9;

public:
    int channel_id;
    std::vector<int> messages;
    int pts;
    int pts_count;
    UpdateDeleteChannelMessages(int channel_id_, std::vector<int> messages_, int pts_, int pts_count_);
    static UpdateDeleteChannelMessages read(Reader reader);
    std::string write();
};

class UpdateChannelMessageViews
{
private:
    int __id = 0x98a12b4b;

public:
    int channel_id;
    int id;
    int views;
    UpdateChannelMessageViews(int channel_id_, int id_, int views_);
    static UpdateChannelMessageViews read(Reader reader);
    std::string write();
};

class UpdateChatParticipantAdmin
{
private:
    int __id = 0xb6901959;

public:
    int chat_id;
    int user_id;
    bool is_admin;
    int version;
    UpdateChatParticipantAdmin(int chat_id_, int user_id_, bool is_admin_, int version_);
    static UpdateChatParticipantAdmin read(Reader reader);
    std::string write();
};

class UpdateNewStickerSet
{
private:
    int __id = 0x688a30aa;

public:
    TLObject stickerset;
    UpdateNewStickerSet(TLObject stickerset_);
    static UpdateNewStickerSet read(Reader reader);
    std::string write();
};

class UpdateStickerSetsOrder
{
private:
    int __id = 0xbb2d201;

public:
    std::optional<bool> masks;
    std::vector<long> order;
    UpdateStickerSetsOrder(std::vector<long> order_, std::optional<bool> masks_ = std::nullopt);
    static UpdateStickerSetsOrder read(Reader reader);
    std::string write();
};

class UpdateStickerSets
{
private:
    int __id = 0x43ae3dec;

public:
    UpdateStickerSets() = default;
    static UpdateStickerSets read(Reader reader);
    std::string write();
};

class UpdateSavedGifs
{
private:
    int __id = 0x9375341e;

public:
    UpdateSavedGifs() = default;
    static UpdateSavedGifs read(Reader reader);
    std::string write();
};

class UpdateBotInlineQuery
{
private:
    int __id = 0x3f2038db;

public:
    long query_id;
    int user_id;
    std::string query;
    std::optional<TLObject> geo;
    std::optional<TLObject> peer_type;
    std::string offset;
    UpdateBotInlineQuery(long query_id_, int user_id_, std::string query_, std::string offset_, std::optional<TLObject> geo_ = std::nullopt, std::optional<TLObject> peer_type_ = std::nullopt);
    static UpdateBotInlineQuery read(Reader reader);
    std::string write();
};

class UpdateBotInlineSend
{
private:
    int __id = 0xe48f964;

public:
    int user_id;
    std::string query;
    std::optional<TLObject> geo;
    std::string id;
    std::optional<TLObject> msg_id;
    UpdateBotInlineSend(int user_id_, std::string query_, std::string id_, std::optional<TLObject> geo_ = std::nullopt, std::optional<TLObject> msg_id_ = std::nullopt);
    static UpdateBotInlineSend read(Reader reader);
    std::string write();
};

class UpdateEditChannelMessage
{
private:
    int __id = 0x1b3f4df7;

public:
    TLObject message;
    int pts;
    int pts_count;
    UpdateEditChannelMessage(TLObject message_, int pts_, int pts_count_);
    static UpdateEditChannelMessage read(Reader reader);
    std::string write();
};

class UpdateBotCallbackQuery
{
private:
    int __id = 0xe73547e1;

public:
    long query_id;
    int user_id;
    TLObject peer;
    int msg_id;
    long chat_instance;
    std::optional<std::string> data;
    std::optional<std::string> game_short_name;
    UpdateBotCallbackQuery(long query_id_, int user_id_, TLObject peer_, int msg_id_, long chat_instance_, std::optional<std::string> data_ = std::nullopt, std::optional<std::string> game_short_name_ = std::nullopt);
    static UpdateBotCallbackQuery read(Reader reader);
    std::string write();
};

class UpdateEditMessage
{
private:
    int __id = 0xe40370a3;

public:
    TLObject message;
    int pts;
    int pts_count;
    UpdateEditMessage(TLObject message_, int pts_, int pts_count_);
    static UpdateEditMessage read(Reader reader);
    std::string write();
};

class UpdateInlineBotCallbackQuery
{
private:
    int __id = 0xf9d27a5a;

public:
    long query_id;
    int user_id;
    TLObject msg_id;
    long chat_instance;
    std::optional<std::string> data;
    std::optional<std::string> game_short_name;
    UpdateInlineBotCallbackQuery(long query_id_, int user_id_, TLObject msg_id_, long chat_instance_, std::optional<std::string> data_ = std::nullopt, std::optional<std::string> game_short_name_ = std::nullopt);
    static UpdateInlineBotCallbackQuery read(Reader reader);
    std::string write();
};

class UpdateReadChannelOutbox
{
private:
    int __id = 0x25d6c9c7;

public:
    int channel_id;
    int max_id;
    UpdateReadChannelOutbox(int channel_id_, int max_id_);
    static UpdateReadChannelOutbox read(Reader reader);
    std::string write();
};

class UpdateDraftMessage
{
private:
    int __id = 0xee2bb969;

public:
    TLObject peer;
    TLObject draft;
    UpdateDraftMessage(TLObject peer_, TLObject draft_);
    static UpdateDraftMessage read(Reader reader);
    std::string write();
};

class UpdateReadFeaturedStickers
{
private:
    int __id = 0x571d2742;

public:
    UpdateReadFeaturedStickers() = default;
    static UpdateReadFeaturedStickers read(Reader reader);
    std::string write();
};

class UpdateRecentStickers
{
private:
    int __id = 0x9a422c20;

public:
    UpdateRecentStickers() = default;
    static UpdateRecentStickers read(Reader reader);
    std::string write();
};

class UpdateConfig
{
private:
    int __id = 0xa229dd06;

public:
    UpdateConfig() = default;
    static UpdateConfig read(Reader reader);
    std::string write();
};

class UpdatePtsChanged
{
private:
    int __id = 0x3354678f;

public:
    UpdatePtsChanged() = default;
    static UpdatePtsChanged read(Reader reader);
    std::string write();
};

class UpdateChannelWebPage
{
private:
    int __id = 0x40771900;

public:
    int channel_id;
    TLObject webpage;
    int pts;
    int pts_count;
    UpdateChannelWebPage(int channel_id_, TLObject webpage_, int pts_, int pts_count_);
    static UpdateChannelWebPage read(Reader reader);
    std::string write();
};

class UpdateDialogPinned
{
private:
    int __id = 0x6e6fe51c;

public:
    std::optional<bool> pinned;
    std::optional<int> folder_id;
    TLObject peer;
    UpdateDialogPinned(TLObject peer_, std::optional<bool> pinned_ = std::nullopt, std::optional<int> folder_id_ = std::nullopt);
    static UpdateDialogPinned read(Reader reader);
    std::string write();
};

class UpdatePinnedDialogs
{
private:
    int __id = 0xfa0f3ca2;

public:
    std::optional<int> folder_id;
    std::optional<std::vector<TLObject>> order;
    UpdatePinnedDialogs(std::optional<int> folder_id_ = std::nullopt, std::optional<std::vector<TLObject>> order_ = std::nullopt);
    static UpdatePinnedDialogs read(Reader reader);
    std::string write();
};

class UpdateBotWebhookJSON
{
private:
    int __id = 0x8317c0c3;

public:
    TLObject data;
    UpdateBotWebhookJSON(TLObject data_);
    static UpdateBotWebhookJSON read(Reader reader);
    std::string write();
};

class UpdateBotWebhookJSONQuery
{
private:
    int __id = 0x9b9240a6;

public:
    long query_id;
    TLObject data;
    int timeout;
    UpdateBotWebhookJSONQuery(long query_id_, TLObject data_, int timeout_);
    static UpdateBotWebhookJSONQuery read(Reader reader);
    std::string write();
};

class UpdateBotShippingQuery
{
private:
    int __id = 0xe0cdc940;

public:
    long query_id;
    int user_id;
    std::string payload;
    TLObject shipping_address;
    UpdateBotShippingQuery(long query_id_, int user_id_, std::string payload_, TLObject shipping_address_);
    static UpdateBotShippingQuery read(Reader reader);
    std::string write();
};

class UpdateBotPrecheckoutQuery
{
private:
    int __id = 0x5d2f3aa9;

public:
    long query_id;
    int user_id;
    std::string payload;
    std::optional<TLObject> info;
    std::optional<std::string> shipping_option_id;
    std::string currency;
    long total_amount;
    UpdateBotPrecheckoutQuery(long query_id_, int user_id_, std::string payload_, std::string currency_, long total_amount_, std::optional<TLObject> info_ = std::nullopt, std::optional<std::string> shipping_option_id_ = std::nullopt);
    static UpdateBotPrecheckoutQuery read(Reader reader);
    std::string write();
};

class UpdatePhoneCall
{
private:
    int __id = 0xab0f6b1e;

public:
    TLObject phone_call;
    UpdatePhoneCall(TLObject phone_call_);
    static UpdatePhoneCall read(Reader reader);
    std::string write();
};

class UpdateLangPackTooLong
{
private:
    int __id = 0x46560264;

public:
    std::string lang_code;
    UpdateLangPackTooLong(std::string lang_code_);
    static UpdateLangPackTooLong read(Reader reader);
    std::string write();
};

class UpdateLangPack
{
private:
    int __id = 0x56022f4d;

public:
    TLObject difference;
    UpdateLangPack(TLObject difference_);
    static UpdateLangPack read(Reader reader);
    std::string write();
};

class UpdateFavedStickers
{
private:
    int __id = 0xe511996d;

public:
    UpdateFavedStickers() = default;
    static UpdateFavedStickers read(Reader reader);
    std::string write();
};

class UpdateChannelReadMessagesContents
{
private:
    int __id = 0x89893b45;

public:
    int channel_id;
    std::vector<int> messages;
    UpdateChannelReadMessagesContents(int channel_id_, std::vector<int> messages_);
    static UpdateChannelReadMessagesContents read(Reader reader);
    std::string write();
};

class UpdateContactsReset
{
private:
    int __id = 0x7084a7be;

public:
    UpdateContactsReset() = default;
    static UpdateContactsReset read(Reader reader);
    std::string write();
};

class UpdateChannelAvailableMessages
{
private:
    int __id = 0x70db6837;

public:
    int channel_id;
    int available_min_id;
    UpdateChannelAvailableMessages(int channel_id_, int available_min_id_);
    static UpdateChannelAvailableMessages read(Reader reader);
    std::string write();
};

class UpdateDialogUnreadMark
{
private:
    int __id = 0xe16459c3;

public:
    std::optional<bool> unread;
    TLObject peer;
    UpdateDialogUnreadMark(TLObject peer_, std::optional<bool> unread_ = std::nullopt);
    static UpdateDialogUnreadMark read(Reader reader);
    std::string write();
};

class UpdateMessagePoll
{
private:
    int __id = 0xaca1657b;

public:
    long poll_id;
    std::optional<TLObject> poll;
    TLObject results;
    UpdateMessagePoll(long poll_id_, TLObject results_, std::optional<TLObject> poll_ = std::nullopt);
    static UpdateMessagePoll read(Reader reader);
    std::string write();
};

class UpdateChatDefaultBannedRights
{
private:
    int __id = 0x54c01850;

public:
    TLObject peer;
    TLObject default_banned_rights;
    int version;
    UpdateChatDefaultBannedRights(TLObject peer_, TLObject default_banned_rights_, int version_);
    static UpdateChatDefaultBannedRights read(Reader reader);
    std::string write();
};

class UpdateFolderPeers
{
private:
    int __id = 0x19360dc0;

public:
    std::vector<TLObject> folder_peers;
    int pts;
    int pts_count;
    UpdateFolderPeers(std::vector<TLObject> folder_peers_, int pts_, int pts_count_);
    static UpdateFolderPeers read(Reader reader);
    std::string write();
};

class UpdatePeerSettings
{
private:
    int __id = 0x6a7e7366;

public:
    TLObject peer;
    TLObject settings;
    UpdatePeerSettings(TLObject peer_, TLObject settings_);
    static UpdatePeerSettings read(Reader reader);
    std::string write();
};

class UpdatePeerLocated
{
private:
    int __id = 0xb4afcfb0;

public:
    std::vector<TLObject> peers;
    UpdatePeerLocated(std::vector<TLObject> peers_);
    static UpdatePeerLocated read(Reader reader);
    std::string write();
};

class UpdateNewScheduledMessage
{
private:
    int __id = 0x39a51dfb;

public:
    TLObject message;
    UpdateNewScheduledMessage(TLObject message_);
    static UpdateNewScheduledMessage read(Reader reader);
    std::string write();
};

class UpdateDeleteScheduledMessages
{
private:
    int __id = 0x90866cee;

public:
    TLObject peer;
    std::vector<int> messages;
    UpdateDeleteScheduledMessages(TLObject peer_, std::vector<int> messages_);
    static UpdateDeleteScheduledMessages read(Reader reader);
    std::string write();
};

class UpdateTheme
{
private:
    int __id = 0x8216fba3;

public:
    TLObject theme;
    UpdateTheme(TLObject theme_);
    static UpdateTheme read(Reader reader);
    std::string write();
};

class UpdateGeoLiveViewed
{
private:
    int __id = 0x871fb939;

public:
    TLObject peer;
    int msg_id;
    UpdateGeoLiveViewed(TLObject peer_, int msg_id_);
    static UpdateGeoLiveViewed read(Reader reader);
    std::string write();
};

class UpdateLoginToken
{
private:
    int __id = 0x564fe691;

public:
    UpdateLoginToken() = default;
    static UpdateLoginToken read(Reader reader);
    std::string write();
};

class UpdateMessagePollVote
{
private:
    int __id = 0x37f69f0b;

public:
    long poll_id;
    int user_id;
    std::vector<std::string> options;
    int qts;
    UpdateMessagePollVote(long poll_id_, int user_id_, std::vector<std::string> options_, int qts_);
    static UpdateMessagePollVote read(Reader reader);
    std::string write();
};

class UpdateDialogFilter
{
private:
    int __id = 0x26ffde7d;

public:
    int id;
    std::optional<TLObject> filter;
    UpdateDialogFilter(int id_, std::optional<TLObject> filter_ = std::nullopt);
    static UpdateDialogFilter read(Reader reader);
    std::string write();
};

class UpdateDialogFilterOrder
{
private:
    int __id = 0xa5d72105;

public:
    std::vector<int> order;
    UpdateDialogFilterOrder(std::vector<int> order_);
    static UpdateDialogFilterOrder read(Reader reader);
    std::string write();
};

class UpdateDialogFilters
{
private:
    int __id = 0x3504914f;

public:
    UpdateDialogFilters() = default;
    static UpdateDialogFilters read(Reader reader);
    std::string write();
};

class UpdatePhoneCallSignalingData
{
private:
    int __id = 0x2661bf09;

public:
    long phone_call_id;
    std::string data;
    UpdatePhoneCallSignalingData(long phone_call_id_, std::string data_);
    static UpdatePhoneCallSignalingData read(Reader reader);
    std::string write();
};

class UpdateChannelMessageForwards
{
private:
    int __id = 0x6e8a84df;

public:
    int channel_id;
    int id;
    int forwards;
    UpdateChannelMessageForwards(int channel_id_, int id_, int forwards_);
    static UpdateChannelMessageForwards read(Reader reader);
    std::string write();
};

class UpdateReadChannelDiscussionInbox
{
private:
    int __id = 0x1cc7de54;

public:
    int channel_id;
    int top_msg_id;
    int read_max_id;
    std::optional<int> broadcast_id;
    std::optional<int> broadcast_post;
    UpdateReadChannelDiscussionInbox(int channel_id_, int top_msg_id_, int read_max_id_, std::optional<int> broadcast_id_ = std::nullopt, std::optional<int> broadcast_post_ = std::nullopt);
    static UpdateReadChannelDiscussionInbox read(Reader reader);
    std::string write();
};

class UpdateReadChannelDiscussionOutbox
{
private:
    int __id = 0x4638a26c;

public:
    int channel_id;
    int top_msg_id;
    int read_max_id;
    UpdateReadChannelDiscussionOutbox(int channel_id_, int top_msg_id_, int read_max_id_);
    static UpdateReadChannelDiscussionOutbox read(Reader reader);
    std::string write();
};

class UpdatePeerBlocked
{
private:
    int __id = 0x246a4b22;

public:
    TLObject peer_id;
    bool blocked;
    UpdatePeerBlocked(TLObject peer_id_, bool blocked_);
    static UpdatePeerBlocked read(Reader reader);
    std::string write();
};

class UpdateChannelUserTyping
{
private:
    int __id = 0x6b171718;

public:
    int channel_id;
    std::optional<int> top_msg_id;
    TLObject from_id;
    TLObject action;
    UpdateChannelUserTyping(int channel_id_, TLObject from_id_, TLObject action_, std::optional<int> top_msg_id_ = std::nullopt);
    static UpdateChannelUserTyping read(Reader reader);
    std::string write();
};

class UpdatePinnedMessages
{
private:
    int __id = 0xed85eab5;

public:
    std::optional<bool> pinned;
    TLObject peer;
    std::vector<int> messages;
    int pts;
    int pts_count;
    UpdatePinnedMessages(TLObject peer_, std::vector<int> messages_, int pts_, int pts_count_, std::optional<bool> pinned_ = std::nullopt);
    static UpdatePinnedMessages read(Reader reader);
    std::string write();
};

class UpdatePinnedChannelMessages
{
private:
    int __id = 0x8588878b;

public:
    std::optional<bool> pinned;
    int channel_id;
    std::vector<int> messages;
    int pts;
    int pts_count;
    UpdatePinnedChannelMessages(int channel_id_, std::vector<int> messages_, int pts_, int pts_count_, std::optional<bool> pinned_ = std::nullopt);
    static UpdatePinnedChannelMessages read(Reader reader);
    std::string write();
};

class UpdateChat
{
private:
    int __id = 0x1330a196;

public:
    int chat_id;
    UpdateChat(int chat_id_);
    static UpdateChat read(Reader reader);
    std::string write();
};

class UpdateGroupCallParticipants
{
private:
    int __id = 0xf2ebdb4e;

public:
    TLObject call;
    std::vector<TLObject> participants;
    int version;
    UpdateGroupCallParticipants(TLObject call_, std::vector<TLObject> participants_, int version_);
    static UpdateGroupCallParticipants read(Reader reader);
    std::string write();
};

class UpdateGroupCall
{
private:
    int __id = 0xa45eb99b;

public:
    int chat_id;
    TLObject call;
    UpdateGroupCall(int chat_id_, TLObject call_);
    static UpdateGroupCall read(Reader reader);
    std::string write();
};

class UpdatePeerHistoryTTL
{
private:
    int __id = 0xbb9bb9a5;

public:
    TLObject peer;
    std::optional<int> ttl_period;
    UpdatePeerHistoryTTL(TLObject peer_, std::optional<int> ttl_period_ = std::nullopt);
    static UpdatePeerHistoryTTL read(Reader reader);
    std::string write();
};

class UpdateChatParticipant
{
private:
    int __id = 0xf3b3781f;

public:
    int chat_id;
    int date;
    int actor_id;
    int user_id;
    std::optional<TLObject> prev_participant;
    std::optional<TLObject> new_participant;
    std::optional<TLObject> invite;
    int qts;
    UpdateChatParticipant(int chat_id_, int date_, int actor_id_, int user_id_, int qts_, std::optional<TLObject> prev_participant_ = std::nullopt, std::optional<TLObject> new_participant_ = std::nullopt, std::optional<TLObject> invite_ = std::nullopt);
    static UpdateChatParticipant read(Reader reader);
    std::string write();
};

class UpdateChannelParticipant
{
private:
    int __id = 0x7fecb1ec;

public:
    int channel_id;
    int date;
    int actor_id;
    int user_id;
    std::optional<TLObject> prev_participant;
    std::optional<TLObject> new_participant;
    std::optional<TLObject> invite;
    int qts;
    UpdateChannelParticipant(int channel_id_, int date_, int actor_id_, int user_id_, int qts_, std::optional<TLObject> prev_participant_ = std::nullopt, std::optional<TLObject> new_participant_ = std::nullopt, std::optional<TLObject> invite_ = std::nullopt);
    static UpdateChannelParticipant read(Reader reader);
    std::string write();
};

class UpdateBotStopped
{
private:
    int __id = 0x7f9488a;

public:
    int user_id;
    int date;
    bool stopped;
    int qts;
    UpdateBotStopped(int user_id_, int date_, bool stopped_, int qts_);
    static UpdateBotStopped read(Reader reader);
    std::string write();
};

class UpdateGroupCallConnection
{
private:
    int __id = 0xb783982;

public:
    std::optional<bool> presentation;
    TLObject params;
    UpdateGroupCallConnection(TLObject params_, std::optional<bool> presentation_ = std::nullopt);
    static UpdateGroupCallConnection read(Reader reader);
    std::string write();
};

class UpdatesTooLong
{
private:
    int __id = 0xe317af7e;

public:
    UpdatesTooLong() = default;
    static UpdatesTooLong read(Reader reader);
    std::string write();
};

class UpdateShortMessage
{
private:
    int __id = 0xfaeff833;

public:
    std::optional<bool> out;
    std::optional<bool> mentioned;
    std::optional<bool> media_unread;
    std::optional<bool> silent;
    int id;
    int user_id;
    std::string message;
    int pts;
    int pts_count;
    int date;
    std::optional<TLObject> fwd_from;
    std::optional<int> via_bot_id;
    std::optional<TLObject> reply_to;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> ttl_period;
    UpdateShortMessage(int id_, int user_id_, std::string message_, int pts_, int pts_count_, int date_, std::optional<bool> out_ = std::nullopt, std::optional<bool> mentioned_ = std::nullopt, std::optional<bool> media_unread_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<TLObject> fwd_from_ = std::nullopt, std::optional<int> via_bot_id_ = std::nullopt, std::optional<TLObject> reply_to_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static UpdateShortMessage read(Reader reader);
    std::string write();
};

class UpdateShortChatMessage
{
private:
    int __id = 0x1157b858;

public:
    std::optional<bool> out;
    std::optional<bool> mentioned;
    std::optional<bool> media_unread;
    std::optional<bool> silent;
    int id;
    int from_id;
    int chat_id;
    std::string message;
    int pts;
    int pts_count;
    int date;
    std::optional<TLObject> fwd_from;
    std::optional<int> via_bot_id;
    std::optional<TLObject> reply_to;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> ttl_period;
    UpdateShortChatMessage(int id_, int from_id_, int chat_id_, std::string message_, int pts_, int pts_count_, int date_, std::optional<bool> out_ = std::nullopt, std::optional<bool> mentioned_ = std::nullopt, std::optional<bool> media_unread_ = std::nullopt, std::optional<bool> silent_ = std::nullopt, std::optional<TLObject> fwd_from_ = std::nullopt, std::optional<int> via_bot_id_ = std::nullopt, std::optional<TLObject> reply_to_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static UpdateShortChatMessage read(Reader reader);
    std::string write();
};

class UpdateShort
{
private:
    int __id = 0x78d4dec1;

public:
    TLObject update;
    int date;
    UpdateShort(TLObject update_, int date_);
    static UpdateShort read(Reader reader);
    std::string write();
};

class UpdatesCombined
{
private:
    int __id = 0x725b04c3;

public:
    std::vector<TLObject> updates;
    std::vector<TLObject> users;
    std::vector<TLObject> chats;
    int date;
    int seq_start;
    int seq;
    UpdatesCombined(std::vector<TLObject> updates_, std::vector<TLObject> users_, std::vector<TLObject> chats_, int date_, int seq_start_, int seq_);
    static UpdatesCombined read(Reader reader);
    std::string write();
};

class Updates
{
private:
    int __id = 0x74ae4240;

public:
    std::vector<TLObject> updates;
    std::vector<TLObject> users;
    std::vector<TLObject> chats;
    int date;
    int seq;
    Updates(std::vector<TLObject> updates_, std::vector<TLObject> users_, std::vector<TLObject> chats_, int date_, int seq_);
    static Updates read(Reader reader);
    std::string write();
};

class UpdateShortSentMessage
{
private:
    int __id = 0x9015e101;

public:
    std::optional<bool> out;
    int id;
    int pts;
    int pts_count;
    int date;
    std::optional<TLObject> media;
    std::optional<std::vector<TLObject>> entities;
    std::optional<int> ttl_period;
    UpdateShortSentMessage(int id_, int pts_, int pts_count_, int date_, std::optional<bool> out_ = std::nullopt, std::optional<TLObject> media_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<int> ttl_period_ = std::nullopt);
    static UpdateShortSentMessage read(Reader reader);
    std::string write();
};

class DcOption
{
private:
    int __id = 0x18b7a10d;

public:
    std::optional<bool> ipv6;
    std::optional<bool> media_only;
    std::optional<bool> tcpo_only;
    std::optional<bool> cdn;
    std::optional<bool> static_;
    int id;
    std::string ip_address;
    int port;
    std::optional<std::string> secret;
    DcOption(int id_, std::string ip_address_, int port_, std::optional<bool> ipv6_ = std::nullopt, std::optional<bool> media_only_ = std::nullopt, std::optional<bool> tcpo_only_ = std::nullopt, std::optional<bool> cdn_ = std::nullopt, std::optional<bool> static__ = std::nullopt, std::optional<std::string> secret_ = std::nullopt);
    static DcOption read(Reader reader);
    std::string write();
};

class Config
{
private:
    int __id = 0x330b4067;

public:
    std::optional<bool> phonecalls_enabled;
    std::optional<bool> default_p2p_contacts;
    std::optional<bool> preload_featured_stickers;
    std::optional<bool> ignore_phone_entities;
    std::optional<bool> revoke_pm_inbox;
    std::optional<bool> blocked_mode;
    std::optional<bool> pfs_enabled;
    int date;
    int expires;
    bool test_mode;
    int this_dc;
    std::vector<TLObject> dc_options;
    std::string dc_txt_domain_name;
    int chat_size_max;
    int megagroup_size_max;
    int forwarded_count_max;
    int online_update_period_ms;
    int offline_blur_timeout_ms;
    int offline_idle_timeout_ms;
    int online_cloud_timeout_ms;
    int notify_cloud_delay_ms;
    int notify_default_delay_ms;
    int push_chat_period_ms;
    int push_chat_limit;
    int saved_gifs_limit;
    int edit_time_limit;
    int revoke_time_limit;
    int revoke_pm_time_limit;
    int rating_e_decay;
    int stickers_recent_limit;
    int stickers_faved_limit;
    int channels_read_media_period;
    std::optional<int> tmp_sessions;
    int pinned_dialogs_count_max;
    int pinned_infolder_count_max;
    int call_receive_timeout_ms;
    int call_ring_timeout_ms;
    int call_connect_timeout_ms;
    int call_packet_timeout_ms;
    std::string me_url_prefix;
    std::optional<std::string> autoupdate_url_prefix;
    std::optional<std::string> gif_search_username;
    std::optional<std::string> venue_search_username;
    std::optional<std::string> img_search_username;
    std::optional<std::string> static_maps_provider;
    int caption_length_max;
    int message_length_max;
    int webfile_dc_id;
    std::optional<std::string> suggested_lang_code;
    std::optional<int> lang_pack_version;
    std::optional<int> base_lang_pack_version;
    Config(int date_, int expires_, bool test_mode_, int this_dc_, std::vector<TLObject> dc_options_, std::string dc_txt_domain_name_, int chat_size_max_, int megagroup_size_max_, int forwarded_count_max_, int online_update_period_ms_, int offline_blur_timeout_ms_, int offline_idle_timeout_ms_, int online_cloud_timeout_ms_, int notify_cloud_delay_ms_, int notify_default_delay_ms_, int push_chat_period_ms_, int push_chat_limit_, int saved_gifs_limit_, int edit_time_limit_, int revoke_time_limit_, int revoke_pm_time_limit_, int rating_e_decay_, int stickers_recent_limit_, int stickers_faved_limit_, int channels_read_media_period_, int pinned_dialogs_count_max_, int pinned_infolder_count_max_, int call_receive_timeout_ms_, int call_ring_timeout_ms_, int call_connect_timeout_ms_, int call_packet_timeout_ms_, std::string me_url_prefix_, int caption_length_max_, int message_length_max_, int webfile_dc_id_, std::optional<bool> phonecalls_enabled_ = std::nullopt, std::optional<bool> default_p2p_contacts_ = std::nullopt, std::optional<bool> preload_featured_stickers_ = std::nullopt, std::optional<bool> ignore_phone_entities_ = std::nullopt, std::optional<bool> revoke_pm_inbox_ = std::nullopt, std::optional<bool> blocked_mode_ = std::nullopt, std::optional<bool> pfs_enabled_ = std::nullopt, std::optional<int> tmp_sessions_ = std::nullopt, std::optional<std::string> autoupdate_url_prefix_ = std::nullopt, std::optional<std::string> gif_search_username_ = std::nullopt, std::optional<std::string> venue_search_username_ = std::nullopt, std::optional<std::string> img_search_username_ = std::nullopt, std::optional<std::string> static_maps_provider_ = std::nullopt, std::optional<std::string> suggested_lang_code_ = std::nullopt, std::optional<int> lang_pack_version_ = std::nullopt, std::optional<int> base_lang_pack_version_ = std::nullopt);
    static Config read(Reader reader);
    std::string write();
};

class NearestDc
{
private:
    int __id = 0x8e1a1775;

public:
    std::string country;
    int this_dc;
    int nearest_dc;
    NearestDc(std::string country_, int this_dc_, int nearest_dc_);
    static NearestDc read(Reader reader);
    std::string write();
};

class EncryptedChatEmpty
{
private:
    int __id = 0xab7ec0a0;

public:
    int id;
    EncryptedChatEmpty(int id_);
    static EncryptedChatEmpty read(Reader reader);
    std::string write();
};

class EncryptedChatWaiting
{
private:
    int __id = 0x3bf703dc;

public:
    int id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    EncryptedChatWaiting(int id_, long access_hash_, int date_, int admin_id_, int participant_id_);
    static EncryptedChatWaiting read(Reader reader);
    std::string write();
};

class EncryptedChatRequested
{
private:
    int __id = 0x62718a82;

public:
    std::optional<int> folder_id;
    int id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    std::string g_a;
    EncryptedChatRequested(int id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_, std::optional<int> folder_id_ = std::nullopt);
    static EncryptedChatRequested read(Reader reader);
    std::string write();
};

class EncryptedChat
{
private:
    int __id = 0xfa56ce36;

public:
    int id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    std::string g_a_or_b;
    long key_fingerprint;
    EncryptedChat(int id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_or_b_, long key_fingerprint_);
    static EncryptedChat read(Reader reader);
    std::string write();
};

class EncryptedChatDiscarded
{
private:
    int __id = 0x1e1c7c45;

public:
    std::optional<bool> history_deleted;
    int id;
    EncryptedChatDiscarded(int id_, std::optional<bool> history_deleted_ = std::nullopt);
    static EncryptedChatDiscarded read(Reader reader);
    std::string write();
};

class InputEncryptedChat
{
private:
    int __id = 0xf141b5e1;

public:
    int chat_id;
    long access_hash;
    InputEncryptedChat(int chat_id_, long access_hash_);
    static InputEncryptedChat read(Reader reader);
    std::string write();
};

class EncryptedFileEmpty
{
private:
    int __id = 0xc21f497e;

public:
    EncryptedFileEmpty() = default;
    static EncryptedFileEmpty read(Reader reader);
    std::string write();
};

class EncryptedFile
{
private:
    int __id = 0x4a70994c;

public:
    long id;
    long access_hash;
    int size;
    int dc_id;
    int key_fingerprint;
    EncryptedFile(long id_, long access_hash_, int size_, int dc_id_, int key_fingerprint_);
    static EncryptedFile read(Reader reader);
    std::string write();
};

class InputEncryptedFileEmpty
{
private:
    int __id = 0x1837c364;

public:
    InputEncryptedFileEmpty() = default;
    static InputEncryptedFileEmpty read(Reader reader);
    std::string write();
};

class InputEncryptedFileUploaded
{
private:
    int __id = 0x64bd0306;

public:
    long id;
    int parts;
    std::string md5_checksum;
    int key_fingerprint;
    InputEncryptedFileUploaded(long id_, int parts_, std::string md5_checksum_, int key_fingerprint_);
    static InputEncryptedFileUploaded read(Reader reader);
    std::string write();
};

class InputEncryptedFile
{
private:
    int __id = 0x5a17b5e5;

public:
    long id;
    long access_hash;
    InputEncryptedFile(long id_, long access_hash_);
    static InputEncryptedFile read(Reader reader);
    std::string write();
};

class InputEncryptedFileBigUploaded
{
private:
    int __id = 0x2dc173c8;

public:
    long id;
    int parts;
    int key_fingerprint;
    InputEncryptedFileBigUploaded(long id_, int parts_, int key_fingerprint_);
    static InputEncryptedFileBigUploaded read(Reader reader);
    std::string write();
};

class EncryptedMessage
{
private:
    int __id = 0xed18c118;

public:
    long random_id;
    int chat_id;
    int date;
    std::string bytes;
    TLObject file;
    EncryptedMessage(long random_id_, int chat_id_, int date_, std::string bytes_, TLObject file_);
    static EncryptedMessage read(Reader reader);
    std::string write();
};

class EncryptedMessageService
{
private:
    int __id = 0x23734b06;

public:
    long random_id;
    int chat_id;
    int date;
    std::string bytes;
    EncryptedMessageService(long random_id_, int chat_id_, int date_, std::string bytes_);
    static EncryptedMessageService read(Reader reader);
    std::string write();
};

class InputDocumentEmpty
{
private:
    int __id = 0x72f0eaae;

public:
    InputDocumentEmpty() = default;
    static InputDocumentEmpty read(Reader reader);
    std::string write();
};

class InputDocument
{
private:
    int __id = 0x1abfb575;

public:
    long id;
    long access_hash;
    std::string file_reference;
    InputDocument(long id_, long access_hash_, std::string file_reference_);
    static InputDocument read(Reader reader);
    std::string write();
};

class DocumentEmpty
{
private:
    int __id = 0x36f8c871;

public:
    long id;
    DocumentEmpty(long id_);
    static DocumentEmpty read(Reader reader);
    std::string write();
};

class Document
{
private:
    int __id = 0x1e87342b;

public:
    long id;
    long access_hash;
    std::string file_reference;
    int date;
    std::string mime_type;
    int size;
    std::optional<std::vector<TLObject>> thumbs;
    std::optional<std::vector<TLObject>> video_thumbs;
    int dc_id;
    std::vector<TLObject> attributes;
    Document(long id_, long access_hash_, std::string file_reference_, int date_, std::string mime_type_, int size_, int dc_id_, std::vector<TLObject> attributes_, std::optional<std::vector<TLObject>> thumbs_ = std::nullopt, std::optional<std::vector<TLObject>> video_thumbs_ = std::nullopt);
    static Document read(Reader reader);
    std::string write();
};

class NotifyPeer
{
private:
    int __id = 0x9fd40bd8;

public:
    TLObject peer;
    NotifyPeer(TLObject peer_);
    static NotifyPeer read(Reader reader);
    std::string write();
};

class NotifyUsers
{
private:
    int __id = 0xb4c83b4c;

public:
    NotifyUsers() = default;
    static NotifyUsers read(Reader reader);
    std::string write();
};

class NotifyChats
{
private:
    int __id = 0xc007cec3;

public:
    NotifyChats() = default;
    static NotifyChats read(Reader reader);
    std::string write();
};

class NotifyBroadcasts
{
private:
    int __id = 0xd612e8ef;

public:
    NotifyBroadcasts() = default;
    static NotifyBroadcasts read(Reader reader);
    std::string write();
};

class SendMessageTypingAction
{
private:
    int __id = 0x16bf744e;

public:
    SendMessageTypingAction() = default;
    static SendMessageTypingAction read(Reader reader);
    std::string write();
};

class SendMessageCancelAction
{
private:
    int __id = 0xfd5ec8f5;

public:
    SendMessageCancelAction() = default;
    static SendMessageCancelAction read(Reader reader);
    std::string write();
};

class SendMessageRecordVideoAction
{
private:
    int __id = 0xa187d66f;

public:
    SendMessageRecordVideoAction() = default;
    static SendMessageRecordVideoAction read(Reader reader);
    std::string write();
};

class SendMessageUploadVideoAction
{
private:
    int __id = 0xe9763aec;

public:
    int progress;
    SendMessageUploadVideoAction(int progress_);
    static SendMessageUploadVideoAction read(Reader reader);
    std::string write();
};

class SendMessageRecordAudioAction
{
private:
    int __id = 0xd52f73f7;

public:
    SendMessageRecordAudioAction() = default;
    static SendMessageRecordAudioAction read(Reader reader);
    std::string write();
};

class SendMessageUploadAudioAction
{
private:
    int __id = 0xf351d7ab;

public:
    int progress;
    SendMessageUploadAudioAction(int progress_);
    static SendMessageUploadAudioAction read(Reader reader);
    std::string write();
};

class SendMessageUploadPhotoAction
{
private:
    int __id = 0xd1d34a26;

public:
    int progress;
    SendMessageUploadPhotoAction(int progress_);
    static SendMessageUploadPhotoAction read(Reader reader);
    std::string write();
};

class SendMessageUploadDocumentAction
{
private:
    int __id = 0xaa0cd9e4;

public:
    int progress;
    SendMessageUploadDocumentAction(int progress_);
    static SendMessageUploadDocumentAction read(Reader reader);
    std::string write();
};

class SendMessageGeoLocationAction
{
private:
    int __id = 0x176f8ba1;

public:
    SendMessageGeoLocationAction() = default;
    static SendMessageGeoLocationAction read(Reader reader);
    std::string write();
};

class SendMessageChooseContactAction
{
private:
    int __id = 0x628cbc6f;

public:
    SendMessageChooseContactAction() = default;
    static SendMessageChooseContactAction read(Reader reader);
    std::string write();
};

class SendMessageGamePlayAction
{
private:
    int __id = 0xdd6a8f48;

public:
    SendMessageGamePlayAction() = default;
    static SendMessageGamePlayAction read(Reader reader);
    std::string write();
};

class SendMessageRecordRoundAction
{
private:
    int __id = 0x88f27fbc;

public:
    SendMessageRecordRoundAction() = default;
    static SendMessageRecordRoundAction read(Reader reader);
    std::string write();
};

class SendMessageUploadRoundAction
{
private:
    int __id = 0x243e1c66;

public:
    int progress;
    SendMessageUploadRoundAction(int progress_);
    static SendMessageUploadRoundAction read(Reader reader);
    std::string write();
};

class SpeakingInGroupCallAction
{
private:
    int __id = 0xd92c2285;

public:
    SpeakingInGroupCallAction() = default;
    static SpeakingInGroupCallAction read(Reader reader);
    std::string write();
};

class SendMessageHistoryImportAction
{
private:
    int __id = 0xdbda9246;

public:
    int progress;
    SendMessageHistoryImportAction(int progress_);
    static SendMessageHistoryImportAction read(Reader reader);
    std::string write();
};

class InputPrivacyKeyStatusTimestamp
{
private:
    int __id = 0x4f96cb18;

public:
    InputPrivacyKeyStatusTimestamp() = default;
    static InputPrivacyKeyStatusTimestamp read(Reader reader);
    std::string write();
};

class InputPrivacyKeyChatInvite
{
private:
    int __id = 0xbdfb0426;

public:
    InputPrivacyKeyChatInvite() = default;
    static InputPrivacyKeyChatInvite read(Reader reader);
    std::string write();
};

class InputPrivacyKeyPhoneCall
{
private:
    int __id = 0xfabadc5f;

public:
    InputPrivacyKeyPhoneCall() = default;
    static InputPrivacyKeyPhoneCall read(Reader reader);
    std::string write();
};

class InputPrivacyKeyForwards
{
private:
    int __id = 0xa4dd4c08;

public:
    InputPrivacyKeyForwards() = default;
    static InputPrivacyKeyForwards read(Reader reader);
    std::string write();
};

class InputPrivacyKeyProfilePhoto
{
private:
    int __id = 0x5719bacc;

public:
    InputPrivacyKeyProfilePhoto() = default;
    static InputPrivacyKeyProfilePhoto read(Reader reader);
    std::string write();
};

class InputPrivacyKeyPhoneNumber
{
private:
    int __id = 0x352dafa;

public:
    InputPrivacyKeyPhoneNumber() = default;
    static InputPrivacyKeyPhoneNumber read(Reader reader);
    std::string write();
};

class InputPrivacyKeyAddedByPhone
{
private:
    int __id = 0xd1219bdd;

public:
    InputPrivacyKeyAddedByPhone() = default;
    static InputPrivacyKeyAddedByPhone read(Reader reader);
    std::string write();
};

class PrivacyKeyStatusTimestamp
{
private:
    int __id = 0xbc2eab30;

public:
    PrivacyKeyStatusTimestamp() = default;
    static PrivacyKeyStatusTimestamp read(Reader reader);
    std::string write();
};

class PrivacyKeyChatInvite
{
private:
    int __id = 0x500e6dfa;

public:
    PrivacyKeyChatInvite() = default;
    static PrivacyKeyChatInvite read(Reader reader);
    std::string write();
};

class PrivacyKeyPhoneCall
{
private:
    int __id = 0x3d662b7b;

public:
    PrivacyKeyPhoneCall() = default;
    static PrivacyKeyPhoneCall read(Reader reader);
    std::string write();
};

class PrivacyKeyForwards
{
private:
    int __id = 0x69ec56a3;

public:
    PrivacyKeyForwards() = default;
    static PrivacyKeyForwards read(Reader reader);
    std::string write();
};

class PrivacyKeyProfilePhoto
{
private:
    int __id = 0x96151fed;

public:
    PrivacyKeyProfilePhoto() = default;
    static PrivacyKeyProfilePhoto read(Reader reader);
    std::string write();
};

class PrivacyKeyPhoneNumber
{
private:
    int __id = 0xd19ae46d;

public:
    PrivacyKeyPhoneNumber() = default;
    static PrivacyKeyPhoneNumber read(Reader reader);
    std::string write();
};

class PrivacyKeyAddedByPhone
{
private:
    int __id = 0x42ffd42b;

public:
    PrivacyKeyAddedByPhone() = default;
    static PrivacyKeyAddedByPhone read(Reader reader);
    std::string write();
};

class InputPrivacyValueAllowContacts
{
private:
    int __id = 0xd09e07b;

public:
    InputPrivacyValueAllowContacts() = default;
    static InputPrivacyValueAllowContacts read(Reader reader);
    std::string write();
};

class InputPrivacyValueAllowAll
{
private:
    int __id = 0x184b35ce;

public:
    InputPrivacyValueAllowAll() = default;
    static InputPrivacyValueAllowAll read(Reader reader);
    std::string write();
};

class InputPrivacyValueAllowUsers
{
private:
    int __id = 0x131cc67f;

public:
    std::vector<TLObject> users;
    InputPrivacyValueAllowUsers(std::vector<TLObject> users_);
    static InputPrivacyValueAllowUsers read(Reader reader);
    std::string write();
};

class InputPrivacyValueDisallowContacts
{
private:
    int __id = 0xba52007;

public:
    InputPrivacyValueDisallowContacts() = default;
    static InputPrivacyValueDisallowContacts read(Reader reader);
    std::string write();
};

class InputPrivacyValueDisallowAll
{
private:
    int __id = 0xd66b66c9;

public:
    InputPrivacyValueDisallowAll() = default;
    static InputPrivacyValueDisallowAll read(Reader reader);
    std::string write();
};

class InputPrivacyValueDisallowUsers
{
private:
    int __id = 0x90110467;

public:
    std::vector<TLObject> users;
    InputPrivacyValueDisallowUsers(std::vector<TLObject> users_);
    static InputPrivacyValueDisallowUsers read(Reader reader);
    std::string write();
};

class InputPrivacyValueAllowChatParticipants
{
private:
    int __id = 0x4c81c1ba;

public:
    std::vector<int> chats;
    InputPrivacyValueAllowChatParticipants(std::vector<int> chats_);
    static InputPrivacyValueAllowChatParticipants read(Reader reader);
    std::string write();
};

class InputPrivacyValueDisallowChatParticipants
{
private:
    int __id = 0xd82363af;

public:
    std::vector<int> chats;
    InputPrivacyValueDisallowChatParticipants(std::vector<int> chats_);
    static InputPrivacyValueDisallowChatParticipants read(Reader reader);
    std::string write();
};

class PrivacyValueAllowContacts
{
private:
    int __id = 0xfffe1bac;

public:
    PrivacyValueAllowContacts() = default;
    static PrivacyValueAllowContacts read(Reader reader);
    std::string write();
};

class PrivacyValueAllowAll
{
private:
    int __id = 0x65427b82;

public:
    PrivacyValueAllowAll() = default;
    static PrivacyValueAllowAll read(Reader reader);
    std::string write();
};

class PrivacyValueAllowUsers
{
private:
    int __id = 0x4d5bbe0c;

public:
    std::vector<int> users;
    PrivacyValueAllowUsers(std::vector<int> users_);
    static PrivacyValueAllowUsers read(Reader reader);
    std::string write();
};

class PrivacyValueDisallowContacts
{
private:
    int __id = 0xf888fa1a;

public:
    PrivacyValueDisallowContacts() = default;
    static PrivacyValueDisallowContacts read(Reader reader);
    std::string write();
};

class PrivacyValueDisallowAll
{
private:
    int __id = 0x8b73e763;

public:
    PrivacyValueDisallowAll() = default;
    static PrivacyValueDisallowAll read(Reader reader);
    std::string write();
};

class PrivacyValueDisallowUsers
{
private:
    int __id = 0xc7f49b7;

public:
    std::vector<int> users;
    PrivacyValueDisallowUsers(std::vector<int> users_);
    static PrivacyValueDisallowUsers read(Reader reader);
    std::string write();
};

class PrivacyValueAllowChatParticipants
{
private:
    int __id = 0x18be796b;

public:
    std::vector<int> chats;
    PrivacyValueAllowChatParticipants(std::vector<int> chats_);
    static PrivacyValueAllowChatParticipants read(Reader reader);
    std::string write();
};

class PrivacyValueDisallowChatParticipants
{
private:
    int __id = 0xacae0690;

public:
    std::vector<int> chats;
    PrivacyValueDisallowChatParticipants(std::vector<int> chats_);
    static PrivacyValueDisallowChatParticipants read(Reader reader);
    std::string write();
};

class AccountDaysTTL
{
private:
    int __id = 0xb8d0afdf;

public:
    int days;
    AccountDaysTTL(int days_);
    static AccountDaysTTL read(Reader reader);
    std::string write();
};

class DocumentAttributeImageSize
{
private:
    int __id = 0x6c37c15c;

public:
    int w;
    int h;
    DocumentAttributeImageSize(int w_, int h_);
    static DocumentAttributeImageSize read(Reader reader);
    std::string write();
};

class DocumentAttributeAnimated
{
private:
    int __id = 0x11b58939;

public:
    DocumentAttributeAnimated() = default;
    static DocumentAttributeAnimated read(Reader reader);
    std::string write();
};

class DocumentAttributeSticker
{
private:
    int __id = 0x6319d612;

public:
    std::optional<bool> mask;
    std::string alt;
    TLObject stickerset;
    std::optional<TLObject> mask_coords;
    DocumentAttributeSticker(std::string alt_, TLObject stickerset_, std::optional<bool> mask_ = std::nullopt, std::optional<TLObject> mask_coords_ = std::nullopt);
    static DocumentAttributeSticker read(Reader reader);
    std::string write();
};

class DocumentAttributeVideo
{
private:
    int __id = 0xef02ce6;

public:
    std::optional<bool> round_message;
    std::optional<bool> supports_streaming;
    int duration;
    int w;
    int h;
    DocumentAttributeVideo(int duration_, int w_, int h_, std::optional<bool> round_message_ = std::nullopt, std::optional<bool> supports_streaming_ = std::nullopt);
    static DocumentAttributeVideo read(Reader reader);
    std::string write();
};

class DocumentAttributeAudio
{
private:
    int __id = 0x9852f9c6;

public:
    std::optional<bool> voice;
    int duration;
    std::optional<std::string> title;
    std::optional<std::string> performer;
    std::optional<std::string> waveform;
    DocumentAttributeAudio(int duration_, std::optional<bool> voice_ = std::nullopt, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> performer_ = std::nullopt, std::optional<std::string> waveform_ = std::nullopt);
    static DocumentAttributeAudio read(Reader reader);
    std::string write();
};

class DocumentAttributeFilename
{
private:
    int __id = 0x15590068;

public:
    std::string file_name;
    DocumentAttributeFilename(std::string file_name_);
    static DocumentAttributeFilename read(Reader reader);
    std::string write();
};

class DocumentAttributeHasStickers
{
private:
    int __id = 0x9801d2f7;

public:
    DocumentAttributeHasStickers() = default;
    static DocumentAttributeHasStickers read(Reader reader);
    std::string write();
};

class StickerPack
{
private:
    int __id = 0x12b299d4;

public:
    std::string emoticon;
    std::vector<long> documents;
    StickerPack(std::string emoticon_, std::vector<long> documents_);
    static StickerPack read(Reader reader);
    std::string write();
};

class WebPageEmpty
{
private:
    int __id = 0xeb1477e8;

public:
    long id;
    WebPageEmpty(long id_);
    static WebPageEmpty read(Reader reader);
    std::string write();
};

class WebPagePending
{
private:
    int __id = 0xc586da1c;

public:
    long id;
    int date;
    WebPagePending(long id_, int date_);
    static WebPagePending read(Reader reader);
    std::string write();
};

class WebPage
{
private:
    int __id = 0xe89c45b2;

public:
    long id;
    std::string url;
    std::string display_url;
    int hash;
    std::optional<std::string> type;
    std::optional<std::string> site_name;
    std::optional<std::string> title;
    std::optional<std::string> description;
    std::optional<TLObject> photo;
    std::optional<std::string> embed_url;
    std::optional<std::string> embed_type;
    std::optional<int> embed_width;
    std::optional<int> embed_height;
    std::optional<int> duration;
    std::optional<std::string> author;
    std::optional<TLObject> document;
    std::optional<TLObject> cached_page;
    std::optional<std::vector<TLObject>> attributes;
    WebPage(long id_, std::string url_, std::string display_url_, int hash_, std::optional<std::string> type_ = std::nullopt, std::optional<std::string> site_name_ = std::nullopt, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt, std::optional<TLObject> photo_ = std::nullopt, std::optional<std::string> embed_url_ = std::nullopt, std::optional<std::string> embed_type_ = std::nullopt, std::optional<int> embed_width_ = std::nullopt, std::optional<int> embed_height_ = std::nullopt, std::optional<int> duration_ = std::nullopt, std::optional<std::string> author_ = std::nullopt, std::optional<TLObject> document_ = std::nullopt, std::optional<TLObject> cached_page_ = std::nullopt, std::optional<std::vector<TLObject>> attributes_ = std::nullopt);
    static WebPage read(Reader reader);
    std::string write();
};

class WebPageNotModified
{
private:
    int __id = 0x7311ca11;

public:
    std::optional<int> cached_page_views;
    WebPageNotModified(std::optional<int> cached_page_views_ = std::nullopt);
    static WebPageNotModified read(Reader reader);
    std::string write();
};

class Authorization
{
private:
    int __id = 0xad01d61d;

public:
    std::optional<bool> current;
    std::optional<bool> official_app;
    std::optional<bool> password_pending;
    long hash;
    std::string device_model;
    std::string platform;
    std::string system_version;
    int api_id;
    std::string app_name;
    std::string app_version;
    int date_created;
    int date_active;
    std::string ip;
    std::string country;
    std::string region;
    Authorization(long hash_, std::string device_model_, std::string platform_, std::string system_version_, int api_id_, std::string app_name_, std::string app_version_, int date_created_, int date_active_, std::string ip_, std::string country_, std::string region_, std::optional<bool> current_ = std::nullopt, std::optional<bool> official_app_ = std::nullopt, std::optional<bool> password_pending_ = std::nullopt);
    static Authorization read(Reader reader);
    std::string write();
};

class ReceivedNotifyMessage
{
private:
    int __id = 0xa384b779;

public:
    int id;
    ReceivedNotifyMessage(int id_);
    static ReceivedNotifyMessage read(Reader reader);
    std::string write();
};

class ChatInviteExported
{
private:
    int __id = 0x6e24fc9d;

public:
    std::optional<bool> revoked;
    std::optional<bool> permanent;
    std::string link;
    int admin_id;
    int date;
    std::optional<int> start_date;
    std::optional<int> expire_date;
    std::optional<int> usage_limit;
    std::optional<int> usage;
    ChatInviteExported(std::string link_, int admin_id_, int date_, std::optional<bool> revoked_ = std::nullopt, std::optional<bool> permanent_ = std::nullopt, std::optional<int> start_date_ = std::nullopt, std::optional<int> expire_date_ = std::nullopt, std::optional<int> usage_limit_ = std::nullopt, std::optional<int> usage_ = std::nullopt);
    static ChatInviteExported read(Reader reader);
    std::string write();
};

class ChatInviteAlready
{
private:
    int __id = 0x5a686d7c;

public:
    TLObject chat;
    ChatInviteAlready(TLObject chat_);
    static ChatInviteAlready read(Reader reader);
    std::string write();
};

class ChatInvite
{
private:
    int __id = 0xdfc2f58e;

public:
    std::optional<bool> channel;
    std::optional<bool> broadcast;
    std::optional<bool> public_;
    std::optional<bool> megagroup;
    std::string title;
    TLObject photo;
    int participants_count;
    std::optional<std::vector<TLObject>> participants;
    ChatInvite(std::string title_, TLObject photo_, int participants_count_, std::optional<bool> channel_ = std::nullopt, std::optional<bool> broadcast_ = std::nullopt, std::optional<bool> public__ = std::nullopt, std::optional<bool> megagroup_ = std::nullopt, std::optional<std::vector<TLObject>> participants_ = std::nullopt);
    static ChatInvite read(Reader reader);
    std::string write();
};

class ChatInvitePeek
{
private:
    int __id = 0x61695cb0;

public:
    TLObject chat;
    int expires;
    ChatInvitePeek(TLObject chat_, int expires_);
    static ChatInvitePeek read(Reader reader);
    std::string write();
};

class InputStickerSetEmpty
{
private:
    int __id = 0xffb62b95;

public:
    InputStickerSetEmpty() = default;
    static InputStickerSetEmpty read(Reader reader);
    std::string write();
};

class InputStickerSetID
{
private:
    int __id = 0x9de7a269;

public:
    long id;
    long access_hash;
    InputStickerSetID(long id_, long access_hash_);
    static InputStickerSetID read(Reader reader);
    std::string write();
};

class InputStickerSetShortName
{
private:
    int __id = 0x861cc8a0;

public:
    std::string short_name;
    InputStickerSetShortName(std::string short_name_);
    static InputStickerSetShortName read(Reader reader);
    std::string write();
};

class InputStickerSetAnimatedEmoji
{
private:
    int __id = 0x28703c8;

public:
    InputStickerSetAnimatedEmoji() = default;
    static InputStickerSetAnimatedEmoji read(Reader reader);
    std::string write();
};

class InputStickerSetDice
{
private:
    int __id = 0xe67f520e;

public:
    std::string emoticon;
    InputStickerSetDice(std::string emoticon_);
    static InputStickerSetDice read(Reader reader);
    std::string write();
};

class StickerSet
{
private:
    int __id = 0xd7df217a;

public:
    std::optional<bool> archived;
    std::optional<bool> official;
    std::optional<bool> masks;
    std::optional<bool> animated;
    std::optional<int> installed_date;
    long id;
    long access_hash;
    std::string title;
    std::string short_name;
    std::optional<std::vector<TLObject>> thumbs;
    std::optional<int> thumb_dc_id;
    std::optional<int> thumb_version;
    int count;
    int hash;
    StickerSet(long id_, long access_hash_, std::string title_, std::string short_name_, int count_, int hash_, std::optional<bool> archived_ = std::nullopt, std::optional<bool> official_ = std::nullopt, std::optional<bool> masks_ = std::nullopt, std::optional<bool> animated_ = std::nullopt, std::optional<int> installed_date_ = std::nullopt, std::optional<std::vector<TLObject>> thumbs_ = std::nullopt, std::optional<int> thumb_dc_id_ = std::nullopt, std::optional<int> thumb_version_ = std::nullopt);
    static StickerSet read(Reader reader);
    std::string write();
};

class BotCommand
{
private:
    int __id = 0xc27ac8c7;

public:
    std::string command;
    std::string description;
    BotCommand(std::string command_, std::string description_);
    static BotCommand read(Reader reader);
    std::string write();
};

class BotInfo
{
private:
    int __id = 0x98e81d3a;

public:
    int user_id;
    std::string description;
    std::vector<TLObject> commands;
    BotInfo(int user_id_, std::string description_, std::vector<TLObject> commands_);
    static BotInfo read(Reader reader);
    std::string write();
};

class KeyboardButton
{
private:
    int __id = 0xa2fa4880;

public:
    std::string text;
    KeyboardButton(std::string text_);
    static KeyboardButton read(Reader reader);
    std::string write();
};

class KeyboardButtonUrl
{
private:
    int __id = 0x258aff05;

public:
    std::string text;
    std::string url;
    KeyboardButtonUrl(std::string text_, std::string url_);
    static KeyboardButtonUrl read(Reader reader);
    std::string write();
};

class KeyboardButtonCallback
{
private:
    int __id = 0x35bbdb6b;

public:
    std::optional<bool> requires_password;
    std::string text;
    std::string data;
    KeyboardButtonCallback(std::string text_, std::string data_, std::optional<bool> requires_password_ = std::nullopt);
    static KeyboardButtonCallback read(Reader reader);
    std::string write();
};

class KeyboardButtonRequestPhone
{
private:
    int __id = 0xb16a6c29;

public:
    std::string text;
    KeyboardButtonRequestPhone(std::string text_);
    static KeyboardButtonRequestPhone read(Reader reader);
    std::string write();
};

class KeyboardButtonRequestGeoLocation
{
private:
    int __id = 0xfc796b3f;

public:
    std::string text;
    KeyboardButtonRequestGeoLocation(std::string text_);
    static KeyboardButtonRequestGeoLocation read(Reader reader);
    std::string write();
};

class KeyboardButtonSwitchInline
{
private:
    int __id = 0x568a748;

public:
    std::optional<bool> same_peer;
    std::string text;
    std::string query;
    KeyboardButtonSwitchInline(std::string text_, std::string query_, std::optional<bool> same_peer_ = std::nullopt);
    static KeyboardButtonSwitchInline read(Reader reader);
    std::string write();
};

class KeyboardButtonGame
{
private:
    int __id = 0x50f41ccf;

public:
    std::string text;
    KeyboardButtonGame(std::string text_);
    static KeyboardButtonGame read(Reader reader);
    std::string write();
};

class KeyboardButtonBuy
{
private:
    int __id = 0xafd93fbb;

public:
    std::string text;
    KeyboardButtonBuy(std::string text_);
    static KeyboardButtonBuy read(Reader reader);
    std::string write();
};

class KeyboardButtonUrlAuth
{
private:
    int __id = 0x10b78d29;

public:
    std::string text;
    std::optional<std::string> fwd_text;
    std::string url;
    int button_id;
    KeyboardButtonUrlAuth(std::string text_, std::string url_, int button_id_, std::optional<std::string> fwd_text_ = std::nullopt);
    static KeyboardButtonUrlAuth read(Reader reader);
    std::string write();
};

class InputKeyboardButtonUrlAuth
{
private:
    int __id = 0xd02e7fd4;

public:
    std::optional<bool> request_write_access;
    std::string text;
    std::optional<std::string> fwd_text;
    std::string url;
    TLObject bot;
    InputKeyboardButtonUrlAuth(std::string text_, std::string url_, TLObject bot_, std::optional<bool> request_write_access_ = std::nullopt, std::optional<std::string> fwd_text_ = std::nullopt);
    static InputKeyboardButtonUrlAuth read(Reader reader);
    std::string write();
};

class KeyboardButtonRequestPoll
{
private:
    int __id = 0xbbc7515d;

public:
    std::optional<bool> quiz;
    std::string text;
    KeyboardButtonRequestPoll(std::string text_, std::optional<bool> quiz_ = std::nullopt);
    static KeyboardButtonRequestPoll read(Reader reader);
    std::string write();
};

class KeyboardButtonRow
{
private:
    int __id = 0x77608b83;

public:
    std::vector<TLObject> buttons;
    KeyboardButtonRow(std::vector<TLObject> buttons_);
    static KeyboardButtonRow read(Reader reader);
    std::string write();
};

class ReplyKeyboardHide
{
private:
    int __id = 0xa03e5b85;

public:
    std::optional<bool> selective;
    ReplyKeyboardHide(std::optional<bool> selective_ = std::nullopt);
    static ReplyKeyboardHide read(Reader reader);
    std::string write();
};

class ReplyKeyboardForceReply
{
private:
    int __id = 0x86b40b08;

public:
    std::optional<bool> single_use;
    std::optional<bool> selective;
    std::optional<std::string> placeholder;
    ReplyKeyboardForceReply(std::optional<bool> single_use_ = std::nullopt, std::optional<bool> selective_ = std::nullopt, std::optional<std::string> placeholder_ = std::nullopt);
    static ReplyKeyboardForceReply read(Reader reader);
    std::string write();
};

class ReplyKeyboardMarkup
{
private:
    int __id = 0x85dd99d1;

public:
    std::optional<bool> resize;
    std::optional<bool> single_use;
    std::optional<bool> selective;
    std::vector<TLObject> rows;
    std::optional<std::string> placeholder;
    ReplyKeyboardMarkup(std::vector<TLObject> rows_, std::optional<bool> resize_ = std::nullopt, std::optional<bool> single_use_ = std::nullopt, std::optional<bool> selective_ = std::nullopt, std::optional<std::string> placeholder_ = std::nullopt);
    static ReplyKeyboardMarkup read(Reader reader);
    std::string write();
};

class ReplyInlineMarkup
{
private:
    int __id = 0x48a30254;

public:
    std::vector<TLObject> rows;
    ReplyInlineMarkup(std::vector<TLObject> rows_);
    static ReplyInlineMarkup read(Reader reader);
    std::string write();
};

class MessageEntityUnknown
{
private:
    int __id = 0xbb92ba95;

public:
    int offset;
    int length;
    MessageEntityUnknown(int offset_, int length_);
    static MessageEntityUnknown read(Reader reader);
    std::string write();
};

class MessageEntityMention
{
private:
    int __id = 0xfa04579d;

public:
    int offset;
    int length;
    MessageEntityMention(int offset_, int length_);
    static MessageEntityMention read(Reader reader);
    std::string write();
};

class MessageEntityHashtag
{
private:
    int __id = 0x6f635b0d;

public:
    int offset;
    int length;
    MessageEntityHashtag(int offset_, int length_);
    static MessageEntityHashtag read(Reader reader);
    std::string write();
};

class MessageEntityBotCommand
{
private:
    int __id = 0x6cef8ac7;

public:
    int offset;
    int length;
    MessageEntityBotCommand(int offset_, int length_);
    static MessageEntityBotCommand read(Reader reader);
    std::string write();
};

class MessageEntityUrl
{
private:
    int __id = 0x6ed02538;

public:
    int offset;
    int length;
    MessageEntityUrl(int offset_, int length_);
    static MessageEntityUrl read(Reader reader);
    std::string write();
};

class MessageEntityEmail
{
private:
    int __id = 0x64e475c2;

public:
    int offset;
    int length;
    MessageEntityEmail(int offset_, int length_);
    static MessageEntityEmail read(Reader reader);
    std::string write();
};

class MessageEntityBold
{
private:
    int __id = 0xbd610bc9;

public:
    int offset;
    int length;
    MessageEntityBold(int offset_, int length_);
    static MessageEntityBold read(Reader reader);
    std::string write();
};

class MessageEntityItalic
{
private:
    int __id = 0x826f8b60;

public:
    int offset;
    int length;
    MessageEntityItalic(int offset_, int length_);
    static MessageEntityItalic read(Reader reader);
    std::string write();
};

class MessageEntityCode
{
private:
    int __id = 0x28a20571;

public:
    int offset;
    int length;
    MessageEntityCode(int offset_, int length_);
    static MessageEntityCode read(Reader reader);
    std::string write();
};

class MessageEntityPre
{
private:
    int __id = 0x73924be0;

public:
    int offset;
    int length;
    std::string language;
    MessageEntityPre(int offset_, int length_, std::string language_);
    static MessageEntityPre read(Reader reader);
    std::string write();
};

class MessageEntityTextUrl
{
private:
    int __id = 0x76a6d327;

public:
    int offset;
    int length;
    std::string url;
    MessageEntityTextUrl(int offset_, int length_, std::string url_);
    static MessageEntityTextUrl read(Reader reader);
    std::string write();
};

class MessageEntityMentionName
{
private:
    int __id = 0x352dca58;

public:
    int offset;
    int length;
    int user_id;
    MessageEntityMentionName(int offset_, int length_, int user_id_);
    static MessageEntityMentionName read(Reader reader);
    std::string write();
};

class InputMessageEntityMentionName
{
private:
    int __id = 0x208e68c9;

public:
    int offset;
    int length;
    TLObject user_id;
    InputMessageEntityMentionName(int offset_, int length_, TLObject user_id_);
    static InputMessageEntityMentionName read(Reader reader);
    std::string write();
};

class MessageEntityPhone
{
private:
    int __id = 0x9b69e34b;

public:
    int offset;
    int length;
    MessageEntityPhone(int offset_, int length_);
    static MessageEntityPhone read(Reader reader);
    std::string write();
};

class MessageEntityCashtag
{
private:
    int __id = 0x4c4e743f;

public:
    int offset;
    int length;
    MessageEntityCashtag(int offset_, int length_);
    static MessageEntityCashtag read(Reader reader);
    std::string write();
};

class MessageEntityUnderline
{
private:
    int __id = 0x9c4e7e8b;

public:
    int offset;
    int length;
    MessageEntityUnderline(int offset_, int length_);
    static MessageEntityUnderline read(Reader reader);
    std::string write();
};

class MessageEntityStrike
{
private:
    int __id = 0xbf0693d4;

public:
    int offset;
    int length;
    MessageEntityStrike(int offset_, int length_);
    static MessageEntityStrike read(Reader reader);
    std::string write();
};

class MessageEntityBlockquote
{
private:
    int __id = 0x20df5d0;

public:
    int offset;
    int length;
    MessageEntityBlockquote(int offset_, int length_);
    static MessageEntityBlockquote read(Reader reader);
    std::string write();
};

class MessageEntityBankCard
{
private:
    int __id = 0x761e6af4;

public:
    int offset;
    int length;
    MessageEntityBankCard(int offset_, int length_);
    static MessageEntityBankCard read(Reader reader);
    std::string write();
};

class InputChannelEmpty
{
private:
    int __id = 0xee8c1e86;

public:
    InputChannelEmpty() = default;
    static InputChannelEmpty read(Reader reader);
    std::string write();
};

class InputChannel
{
private:
    int __id = 0xafeb712e;

public:
    int channel_id;
    long access_hash;
    InputChannel(int channel_id_, long access_hash_);
    static InputChannel read(Reader reader);
    std::string write();
};

class InputChannelFromMessage
{
private:
    int __id = 0x2a286531;

public:
    TLObject peer;
    int msg_id;
    int channel_id;
    InputChannelFromMessage(TLObject peer_, int msg_id_, int channel_id_);
    static InputChannelFromMessage read(Reader reader);
    std::string write();
};

class MessageRange
{
private:
    int __id = 0xae30253;

public:
    int min_id;
    int max_id;
    MessageRange(int min_id_, int max_id_);
    static MessageRange read(Reader reader);
    std::string write();
};

class ChannelMessagesFilterEmpty
{
private:
    int __id = 0x94d42ee7;

public:
    ChannelMessagesFilterEmpty() = default;
    static ChannelMessagesFilterEmpty read(Reader reader);
    std::string write();
};

class ChannelMessagesFilter
{
private:
    int __id = 0xcd77d957;

public:
    std::optional<bool> exclude_new_messages;
    std::vector<TLObject> ranges;
    ChannelMessagesFilter(std::vector<TLObject> ranges_, std::optional<bool> exclude_new_messages_ = std::nullopt);
    static ChannelMessagesFilter read(Reader reader);
    std::string write();
};

class ChannelParticipant
{
private:
    int __id = 0x15ebac1d;

public:
    int user_id;
    int date;
    ChannelParticipant(int user_id_, int date_);
    static ChannelParticipant read(Reader reader);
    std::string write();
};

class ChannelParticipantSelf
{
private:
    int __id = 0xa3289a6d;

public:
    int user_id;
    int inviter_id;
    int date;
    ChannelParticipantSelf(int user_id_, int inviter_id_, int date_);
    static ChannelParticipantSelf read(Reader reader);
    std::string write();
};

class ChannelParticipantCreator
{
private:
    int __id = 0x447dca4b;

public:
    int user_id;
    TLObject admin_rights;
    std::optional<std::string> rank;
    ChannelParticipantCreator(int user_id_, TLObject admin_rights_, std::optional<std::string> rank_ = std::nullopt);
    static ChannelParticipantCreator read(Reader reader);
    std::string write();
};

class ChannelParticipantAdmin
{
private:
    int __id = 0xccbebbaf;

public:
    std::optional<bool> can_edit;
    std::optional<bool> self;
    int user_id;
    std::optional<int> inviter_id;
    int promoted_by;
    int date;
    TLObject admin_rights;
    std::optional<std::string> rank;
    ChannelParticipantAdmin(int user_id_, int promoted_by_, int date_, TLObject admin_rights_, std::optional<bool> can_edit_ = std::nullopt, std::optional<bool> self_ = std::nullopt, std::optional<int> inviter_id_ = std::nullopt, std::optional<std::string> rank_ = std::nullopt);
    static ChannelParticipantAdmin read(Reader reader);
    std::string write();
};

class ChannelParticipantBanned
{
private:
    int __id = 0x50a1dfd6;

public:
    std::optional<bool> left;
    TLObject peer;
    int kicked_by;
    int date;
    TLObject banned_rights;
    ChannelParticipantBanned(TLObject peer_, int kicked_by_, int date_, TLObject banned_rights_, std::optional<bool> left_ = std::nullopt);
    static ChannelParticipantBanned read(Reader reader);
    std::string write();
};

class ChannelParticipantLeft
{
private:
    int __id = 0x1b03f006;

public:
    TLObject peer;
    ChannelParticipantLeft(TLObject peer_);
    static ChannelParticipantLeft read(Reader reader);
    std::string write();
};

class ChannelParticipantsRecent
{
private:
    int __id = 0xde3f3c79;

public:
    ChannelParticipantsRecent() = default;
    static ChannelParticipantsRecent read(Reader reader);
    std::string write();
};

class ChannelParticipantsAdmins
{
private:
    int __id = 0xb4608969;

public:
    ChannelParticipantsAdmins() = default;
    static ChannelParticipantsAdmins read(Reader reader);
    std::string write();
};

class ChannelParticipantsKicked
{
private:
    int __id = 0xa3b54985;

public:
    std::string q;
    ChannelParticipantsKicked(std::string q_);
    static ChannelParticipantsKicked read(Reader reader);
    std::string write();
};

class ChannelParticipantsBots
{
private:
    int __id = 0xb0d1865b;

public:
    ChannelParticipantsBots() = default;
    static ChannelParticipantsBots read(Reader reader);
    std::string write();
};

class ChannelParticipantsBanned
{
private:
    int __id = 0x1427a5e1;

public:
    std::string q;
    ChannelParticipantsBanned(std::string q_);
    static ChannelParticipantsBanned read(Reader reader);
    std::string write();
};

class ChannelParticipantsSearch
{
private:
    int __id = 0x656ac4b;

public:
    std::string q;
    ChannelParticipantsSearch(std::string q_);
    static ChannelParticipantsSearch read(Reader reader);
    std::string write();
};

class ChannelParticipantsContacts
{
private:
    int __id = 0xbb6ae88d;

public:
    std::string q;
    ChannelParticipantsContacts(std::string q_);
    static ChannelParticipantsContacts read(Reader reader);
    std::string write();
};

class ChannelParticipantsMentions
{
private:
    int __id = 0xe04b5ceb;

public:
    std::optional<std::string> q;
    std::optional<int> top_msg_id;
    ChannelParticipantsMentions(std::optional<std::string> q_ = std::nullopt, std::optional<int> top_msg_id_ = std::nullopt);
    static ChannelParticipantsMentions read(Reader reader);
    std::string write();
};

class InputBotInlineMessageMediaAuto
{
private:
    int __id = 0x3380c786;

public:
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageMediaAuto(std::string message_, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageMediaAuto read(Reader reader);
    std::string write();
};

class InputBotInlineMessageText
{
private:
    int __id = 0x3dcd7a87;

public:
    std::optional<bool> no_webpage;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageText(std::string message_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageText read(Reader reader);
    std::string write();
};

class InputBotInlineMessageMediaGeo
{
private:
    int __id = 0x96929a85;

public:
    TLObject geo_point;
    std::optional<int> heading;
    std::optional<int> period;
    std::optional<int> proximity_notification_radius;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageMediaGeo(TLObject geo_point_, std::optional<int> heading_ = std::nullopt, std::optional<int> period_ = std::nullopt, std::optional<int> proximity_notification_radius_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageMediaGeo read(Reader reader);
    std::string write();
};

class InputBotInlineMessageMediaVenue
{
private:
    int __id = 0x417bbf11;

public:
    TLObject geo_point;
    std::string title;
    std::string address;
    std::string provider;
    std::string venue_id;
    std::string venue_type;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageMediaVenue(TLObject geo_point_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageMediaVenue read(Reader reader);
    std::string write();
};

class InputBotInlineMessageMediaContact
{
private:
    int __id = 0xa6edbffd;

public:
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string vcard;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageMediaContact read(Reader reader);
    std::string write();
};

class InputBotInlineMessageGame
{
private:
    int __id = 0x4b425864;

public:
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageGame(std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageGame read(Reader reader);
    std::string write();
};

class InputBotInlineMessageMediaInvoice
{
private:
    int __id = 0xd7e78225;

public:
    std::string title;
    std::string description;
    std::optional<TLObject> photo;
    TLObject invoice;
    std::string payload;
    std::string provider;
    TLObject provider_data;
    std::optional<TLObject> reply_markup;
    InputBotInlineMessageMediaInvoice(std::string title_, std::string description_, TLObject invoice_, std::string payload_, std::string provider_, TLObject provider_data_, std::optional<TLObject> photo_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static InputBotInlineMessageMediaInvoice read(Reader reader);
    std::string write();
};

class InputBotInlineResult
{
private:
    int __id = 0x88bf9319;

public:
    std::string id;
    std::string type;
    std::optional<std::string> title;
    std::optional<std::string> description;
    std::optional<std::string> url;
    std::optional<TLObject> thumb;
    std::optional<TLObject> content;
    TLObject send_message;
    InputBotInlineResult(std::string id_, std::string type_, TLObject send_message_, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt, std::optional<std::string> url_ = std::nullopt, std::optional<TLObject> thumb_ = std::nullopt, std::optional<TLObject> content_ = std::nullopt);
    static InputBotInlineResult read(Reader reader);
    std::string write();
};

class InputBotInlineResultPhoto
{
private:
    int __id = 0xa8d864a7;

public:
    std::string id;
    std::string type;
    TLObject photo;
    TLObject send_message;
    InputBotInlineResultPhoto(std::string id_, std::string type_, TLObject photo_, TLObject send_message_);
    static InputBotInlineResultPhoto read(Reader reader);
    std::string write();
};

class InputBotInlineResultDocument
{
private:
    int __id = 0xfff8fdc4;

public:
    std::string id;
    std::string type;
    std::optional<std::string> title;
    std::optional<std::string> description;
    TLObject document;
    TLObject send_message;
    InputBotInlineResultDocument(std::string id_, std::string type_, TLObject document_, TLObject send_message_, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt);
    static InputBotInlineResultDocument read(Reader reader);
    std::string write();
};

class InputBotInlineResultGame
{
private:
    int __id = 0x4fa417f2;

public:
    std::string id;
    std::string short_name;
    TLObject send_message;
    InputBotInlineResultGame(std::string id_, std::string short_name_, TLObject send_message_);
    static InputBotInlineResultGame read(Reader reader);
    std::string write();
};

class BotInlineMessageMediaAuto
{
private:
    int __id = 0x764cf810;

public:
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    std::optional<TLObject> reply_markup;
    BotInlineMessageMediaAuto(std::string message_, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageMediaAuto read(Reader reader);
    std::string write();
};

class BotInlineMessageText
{
private:
    int __id = 0x8c7f65e2;

public:
    std::optional<bool> no_webpage;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    std::optional<TLObject> reply_markup;
    BotInlineMessageText(std::string message_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageText read(Reader reader);
    std::string write();
};

class BotInlineMessageMediaGeo
{
private:
    int __id = 0x51846fd;

public:
    TLObject geo;
    std::optional<int> heading;
    std::optional<int> period;
    std::optional<int> proximity_notification_radius;
    std::optional<TLObject> reply_markup;
    BotInlineMessageMediaGeo(TLObject geo_, std::optional<int> heading_ = std::nullopt, std::optional<int> period_ = std::nullopt, std::optional<int> proximity_notification_radius_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageMediaGeo read(Reader reader);
    std::string write();
};

class BotInlineMessageMediaVenue
{
private:
    int __id = 0x8a86659c;

public:
    TLObject geo;
    std::string title;
    std::string address;
    std::string provider;
    std::string venue_id;
    std::string venue_type;
    std::optional<TLObject> reply_markup;
    BotInlineMessageMediaVenue(TLObject geo_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageMediaVenue read(Reader reader);
    std::string write();
};

class BotInlineMessageMediaContact
{
private:
    int __id = 0x18d1cdc2;

public:
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string vcard;
    std::optional<TLObject> reply_markup;
    BotInlineMessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageMediaContact read(Reader reader);
    std::string write();
};

class BotInlineMessageMediaInvoice
{
private:
    int __id = 0x354a9b09;

public:
    std::optional<bool> shipping_address_requested;
    std::optional<bool> test;
    std::string title;
    std::string description;
    std::optional<TLObject> photo;
    std::string currency;
    long total_amount;
    std::optional<TLObject> reply_markup;
    BotInlineMessageMediaInvoice(std::string title_, std::string description_, std::string currency_, long total_amount_, std::optional<bool> shipping_address_requested_ = std::nullopt, std::optional<bool> test_ = std::nullopt, std::optional<TLObject> photo_ = std::nullopt, std::optional<TLObject> reply_markup_ = std::nullopt);
    static BotInlineMessageMediaInvoice read(Reader reader);
    std::string write();
};

class BotInlineResult
{
private:
    int __id = 0x11965f3a;

public:
    std::string id;
    std::string type;
    std::optional<std::string> title;
    std::optional<std::string> description;
    std::optional<std::string> url;
    std::optional<TLObject> thumb;
    std::optional<TLObject> content;
    TLObject send_message;
    BotInlineResult(std::string id_, std::string type_, TLObject send_message_, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt, std::optional<std::string> url_ = std::nullopt, std::optional<TLObject> thumb_ = std::nullopt, std::optional<TLObject> content_ = std::nullopt);
    static BotInlineResult read(Reader reader);
    std::string write();
};

class BotInlineMediaResult
{
private:
    int __id = 0x17db940b;

public:
    std::string id;
    std::string type;
    std::optional<TLObject> photo;
    std::optional<TLObject> document;
    std::optional<std::string> title;
    std::optional<std::string> description;
    TLObject send_message;
    BotInlineMediaResult(std::string id_, std::string type_, TLObject send_message_, std::optional<TLObject> photo_ = std::nullopt, std::optional<TLObject> document_ = std::nullopt, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt);
    static BotInlineMediaResult read(Reader reader);
    std::string write();
};

class ExportedMessageLink
{
private:
    int __id = 0x5dab1af4;

public:
    std::string link;
    std::string html;
    ExportedMessageLink(std::string link_, std::string html_);
    static ExportedMessageLink read(Reader reader);
    std::string write();
};

class MessageFwdHeader
{
private:
    int __id = 0x5f777dce;

public:
    std::optional<bool> imported;
    std::optional<TLObject> from_id;
    std::optional<std::string> from_name;
    int date;
    std::optional<int> channel_post;
    std::optional<std::string> post_author;
    std::optional<TLObject> saved_from_peer;
    std::optional<int> saved_from_msg_id;
    std::optional<std::string> psa_type;
    MessageFwdHeader(int date_, std::optional<bool> imported_ = std::nullopt, std::optional<TLObject> from_id_ = std::nullopt, std::optional<std::string> from_name_ = std::nullopt, std::optional<int> channel_post_ = std::nullopt, std::optional<std::string> post_author_ = std::nullopt, std::optional<TLObject> saved_from_peer_ = std::nullopt, std::optional<int> saved_from_msg_id_ = std::nullopt, std::optional<std::string> psa_type_ = std::nullopt);
    static MessageFwdHeader read(Reader reader);
    std::string write();
};

class InputBotInlineMessageID
{
private:
    int __id = 0x890c3d89;

public:
    int dc_id;
    long id;
    long access_hash;
    InputBotInlineMessageID(int dc_id_, long id_, long access_hash_);
    static InputBotInlineMessageID read(Reader reader);
    std::string write();
};

class InlineBotSwitchPM
{
private:
    int __id = 0x3c20629f;

public:
    std::string text;
    std::string start_param;
    InlineBotSwitchPM(std::string text_, std::string start_param_);
    static InlineBotSwitchPM read(Reader reader);
    std::string write();
};

class TopPeer
{
private:
    int __id = 0xedcdc05b;

public:
    TLObject peer;
    double rating;
    TopPeer(TLObject peer_, double rating_);
    static TopPeer read(Reader reader);
    std::string write();
};

class TopPeerCategoryBotsPM
{
private:
    int __id = 0xab661b5b;

public:
    TopPeerCategoryBotsPM() = default;
    static TopPeerCategoryBotsPM read(Reader reader);
    std::string write();
};

class TopPeerCategoryBotsInline
{
private:
    int __id = 0x148677e2;

public:
    TopPeerCategoryBotsInline() = default;
    static TopPeerCategoryBotsInline read(Reader reader);
    std::string write();
};

class TopPeerCategoryCorrespondents
{
private:
    int __id = 0x637b7ed;

public:
    TopPeerCategoryCorrespondents() = default;
    static TopPeerCategoryCorrespondents read(Reader reader);
    std::string write();
};

class TopPeerCategoryGroups
{
private:
    int __id = 0xbd17a14a;

public:
    TopPeerCategoryGroups() = default;
    static TopPeerCategoryGroups read(Reader reader);
    std::string write();
};

class TopPeerCategoryChannels
{
private:
    int __id = 0x161d9628;

public:
    TopPeerCategoryChannels() = default;
    static TopPeerCategoryChannels read(Reader reader);
    std::string write();
};

class TopPeerCategoryPhoneCalls
{
private:
    int __id = 0x1e76a78c;

public:
    TopPeerCategoryPhoneCalls() = default;
    static TopPeerCategoryPhoneCalls read(Reader reader);
    std::string write();
};

class TopPeerCategoryForwardUsers
{
private:
    int __id = 0xa8406ca9;

public:
    TopPeerCategoryForwardUsers() = default;
    static TopPeerCategoryForwardUsers read(Reader reader);
    std::string write();
};

class TopPeerCategoryForwardChats
{
private:
    int __id = 0xfbeec0f0;

public:
    TopPeerCategoryForwardChats() = default;
    static TopPeerCategoryForwardChats read(Reader reader);
    std::string write();
};

class TopPeerCategoryPeers
{
private:
    int __id = 0xfb834291;

public:
    TLObject category;
    int count;
    std::vector<TLObject> peers;
    TopPeerCategoryPeers(TLObject category_, int count_, std::vector<TLObject> peers_);
    static TopPeerCategoryPeers read(Reader reader);
    std::string write();
};

class DraftMessageEmpty
{
private:
    int __id = 0x1b0c841a;

public:
    std::optional<int> date;
    DraftMessageEmpty(std::optional<int> date_ = std::nullopt);
    static DraftMessageEmpty read(Reader reader);
    std::string write();
};

class DraftMessage
{
private:
    int __id = 0xfd8e711f;

public:
    std::optional<bool> no_webpage;
    std::optional<int> reply_to_msg_id;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    int date;
    DraftMessage(std::string message_, int date_, std::optional<bool> no_webpage_ = std::nullopt, std::optional<int> reply_to_msg_id_ = std::nullopt, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static DraftMessage read(Reader reader);
    std::string write();
};

class StickerSetCovered
{
private:
    int __id = 0x6410a5d2;

public:
    TLObject set;
    TLObject cover;
    StickerSetCovered(TLObject set_, TLObject cover_);
    static StickerSetCovered read(Reader reader);
    std::string write();
};

class StickerSetMultiCovered
{
private:
    int __id = 0x3407e51b;

public:
    TLObject set;
    std::vector<TLObject> covers;
    StickerSetMultiCovered(TLObject set_, std::vector<TLObject> covers_);
    static StickerSetMultiCovered read(Reader reader);
    std::string write();
};

class MaskCoords
{
private:
    int __id = 0xaed6dbb2;

public:
    int n;
    double x;
    double y;
    double zoom;
    MaskCoords(int n_, double x_, double y_, double zoom_);
    static MaskCoords read(Reader reader);
    std::string write();
};

class InputStickeredMediaPhoto
{
private:
    int __id = 0x4a992157;

public:
    TLObject id;
    InputStickeredMediaPhoto(TLObject id_);
    static InputStickeredMediaPhoto read(Reader reader);
    std::string write();
};

class InputStickeredMediaDocument
{
private:
    int __id = 0x438865b;

public:
    TLObject id;
    InputStickeredMediaDocument(TLObject id_);
    static InputStickeredMediaDocument read(Reader reader);
    std::string write();
};

class Game
{
private:
    int __id = 0xbdf9653b;

public:
    long id;
    long access_hash;
    std::string short_name;
    std::string title;
    std::string description;
    TLObject photo;
    std::optional<TLObject> document;
    Game(long id_, long access_hash_, std::string short_name_, std::string title_, std::string description_, TLObject photo_, std::optional<TLObject> document_ = std::nullopt);
    static Game read(Reader reader);
    std::string write();
};

class InputGameID
{
private:
    int __id = 0x32c3e77;

public:
    long id;
    long access_hash;
    InputGameID(long id_, long access_hash_);
    static InputGameID read(Reader reader);
    std::string write();
};

class InputGameShortName
{
private:
    int __id = 0xc331e80a;

public:
    TLObject bot_id;
    std::string short_name;
    InputGameShortName(TLObject bot_id_, std::string short_name_);
    static InputGameShortName read(Reader reader);
    std::string write();
};

class HighScore
{
private:
    int __id = 0x58fffcd0;

public:
    int pos;
    int user_id;
    int score;
    HighScore(int pos_, int user_id_, int score_);
    static HighScore read(Reader reader);
    std::string write();
};

class TextEmpty
{
private:
    int __id = 0xdc3d824f;

public:
    TextEmpty() = default;
    static TextEmpty read(Reader reader);
    std::string write();
};

class TextPlain
{
private:
    int __id = 0x744694e0;

public:
    std::string text;
    TextPlain(std::string text_);
    static TextPlain read(Reader reader);
    std::string write();
};

class TextBold
{
private:
    int __id = 0x6724abc4;

public:
    TLObject text;
    TextBold(TLObject text_);
    static TextBold read(Reader reader);
    std::string write();
};

class TextItalic
{
private:
    int __id = 0xd912a59c;

public:
    TLObject text;
    TextItalic(TLObject text_);
    static TextItalic read(Reader reader);
    std::string write();
};

class TextUnderline
{
private:
    int __id = 0xc12622c4;

public:
    TLObject text;
    TextUnderline(TLObject text_);
    static TextUnderline read(Reader reader);
    std::string write();
};

class TextStrike
{
private:
    int __id = 0x9bf8bb95;

public:
    TLObject text;
    TextStrike(TLObject text_);
    static TextStrike read(Reader reader);
    std::string write();
};

class TextFixed
{
private:
    int __id = 0x6c3f19b9;

public:
    TLObject text;
    TextFixed(TLObject text_);
    static TextFixed read(Reader reader);
    std::string write();
};

class TextUrl
{
private:
    int __id = 0x3c2884c1;

public:
    TLObject text;
    std::string url;
    long webpage_id;
    TextUrl(TLObject text_, std::string url_, long webpage_id_);
    static TextUrl read(Reader reader);
    std::string write();
};

class TextEmail
{
private:
    int __id = 0xde5a0dd6;

public:
    TLObject text;
    std::string email;
    TextEmail(TLObject text_, std::string email_);
    static TextEmail read(Reader reader);
    std::string write();
};

class TextConcat
{
private:
    int __id = 0x7e6260d7;

public:
    std::vector<TLObject> texts;
    TextConcat(std::vector<TLObject> texts_);
    static TextConcat read(Reader reader);
    std::string write();
};

class TextSubscript
{
private:
    int __id = 0xed6a8504;

public:
    TLObject text;
    TextSubscript(TLObject text_);
    static TextSubscript read(Reader reader);
    std::string write();
};

class TextSuperscript
{
private:
    int __id = 0xc7fb5e01;

public:
    TLObject text;
    TextSuperscript(TLObject text_);
    static TextSuperscript read(Reader reader);
    std::string write();
};

class TextMarked
{
private:
    int __id = 0x34b8621;

public:
    TLObject text;
    TextMarked(TLObject text_);
    static TextMarked read(Reader reader);
    std::string write();
};

class TextPhone
{
private:
    int __id = 0x1ccb966a;

public:
    TLObject text;
    std::string phone;
    TextPhone(TLObject text_, std::string phone_);
    static TextPhone read(Reader reader);
    std::string write();
};

class TextImage
{
private:
    int __id = 0x81ccf4f;

public:
    long document_id;
    int w;
    int h;
    TextImage(long document_id_, int w_, int h_);
    static TextImage read(Reader reader);
    std::string write();
};

class TextAnchor
{
private:
    int __id = 0x35553762;

public:
    TLObject text;
    std::string name;
    TextAnchor(TLObject text_, std::string name_);
    static TextAnchor read(Reader reader);
    std::string write();
};

class PageBlockUnsupported
{
private:
    int __id = 0x13567e8a;

public:
    PageBlockUnsupported() = default;
    static PageBlockUnsupported read(Reader reader);
    std::string write();
};

class PageBlockTitle
{
private:
    int __id = 0x70abc3fd;

public:
    TLObject text;
    PageBlockTitle(TLObject text_);
    static PageBlockTitle read(Reader reader);
    std::string write();
};

class PageBlockSubtitle
{
private:
    int __id = 0x8ffa9a1f;

public:
    TLObject text;
    PageBlockSubtitle(TLObject text_);
    static PageBlockSubtitle read(Reader reader);
    std::string write();
};

class PageBlockAuthorDate
{
private:
    int __id = 0xbaafe5e0;

public:
    TLObject author;
    int published_date;
    PageBlockAuthorDate(TLObject author_, int published_date_);
    static PageBlockAuthorDate read(Reader reader);
    std::string write();
};

class PageBlockHeader
{
private:
    int __id = 0xbfd064ec;

public:
    TLObject text;
    PageBlockHeader(TLObject text_);
    static PageBlockHeader read(Reader reader);
    std::string write();
};

class PageBlockSubheader
{
private:
    int __id = 0xf12bb6e1;

public:
    TLObject text;
    PageBlockSubheader(TLObject text_);
    static PageBlockSubheader read(Reader reader);
    std::string write();
};

class PageBlockParagraph
{
private:
    int __id = 0x467a0766;

public:
    TLObject text;
    PageBlockParagraph(TLObject text_);
    static PageBlockParagraph read(Reader reader);
    std::string write();
};

class PageBlockPreformatted
{
private:
    int __id = 0xc070d93e;

public:
    TLObject text;
    std::string language;
    PageBlockPreformatted(TLObject text_, std::string language_);
    static PageBlockPreformatted read(Reader reader);
    std::string write();
};

class PageBlockFooter
{
private:
    int __id = 0x48870999;

public:
    TLObject text;
    PageBlockFooter(TLObject text_);
    static PageBlockFooter read(Reader reader);
    std::string write();
};

class PageBlockDivider
{
private:
    int __id = 0xdb20b188;

public:
    PageBlockDivider() = default;
    static PageBlockDivider read(Reader reader);
    std::string write();
};

class PageBlockAnchor
{
private:
    int __id = 0xce0d37b0;

public:
    std::string name;
    PageBlockAnchor(std::string name_);
    static PageBlockAnchor read(Reader reader);
    std::string write();
};

class PageBlockList
{
private:
    int __id = 0xe4e88011;

public:
    std::vector<TLObject> items;
    PageBlockList(std::vector<TLObject> items_);
    static PageBlockList read(Reader reader);
    std::string write();
};

class PageBlockBlockquote
{
private:
    int __id = 0x263d7c26;

public:
    TLObject text;
    TLObject caption;
    PageBlockBlockquote(TLObject text_, TLObject caption_);
    static PageBlockBlockquote read(Reader reader);
    std::string write();
};

class PageBlockPullquote
{
private:
    int __id = 0x4f4456d3;

public:
    TLObject text;
    TLObject caption;
    PageBlockPullquote(TLObject text_, TLObject caption_);
    static PageBlockPullquote read(Reader reader);
    std::string write();
};

class PageBlockPhoto
{
private:
    int __id = 0x1759c560;

public:
    long photo_id;
    TLObject caption;
    std::optional<std::string> url;
    std::optional<long> webpage_id;
    PageBlockPhoto(long photo_id_, TLObject caption_, std::optional<std::string> url_ = std::nullopt, std::optional<long> webpage_id_ = std::nullopt);
    static PageBlockPhoto read(Reader reader);
    std::string write();
};

class PageBlockVideo
{
private:
    int __id = 0x7c8fe7b6;

public:
    std::optional<bool> autoplay;
    std::optional<bool> loop;
    long video_id;
    TLObject caption;
    PageBlockVideo(long video_id_, TLObject caption_, std::optional<bool> autoplay_ = std::nullopt, std::optional<bool> loop_ = std::nullopt);
    static PageBlockVideo read(Reader reader);
    std::string write();
};

class PageBlockCover
{
private:
    int __id = 0x39f23300;

public:
    TLObject cover;
    PageBlockCover(TLObject cover_);
    static PageBlockCover read(Reader reader);
    std::string write();
};

class PageBlockEmbed
{
private:
    int __id = 0xa8718dc5;

public:
    std::optional<bool> full_width;
    std::optional<bool> allow_scrolling;
    std::optional<std::string> url;
    std::optional<std::string> html;
    std::optional<long> poster_photo_id;
    std::optional<int> w;
    std::optional<int> h;
    TLObject caption;
    PageBlockEmbed(TLObject caption_, std::optional<bool> full_width_ = std::nullopt, std::optional<bool> allow_scrolling_ = std::nullopt, std::optional<std::string> url_ = std::nullopt, std::optional<std::string> html_ = std::nullopt, std::optional<long> poster_photo_id_ = std::nullopt, std::optional<int> w_ = std::nullopt, std::optional<int> h_ = std::nullopt);
    static PageBlockEmbed read(Reader reader);
    std::string write();
};

class PageBlockEmbedPost
{
private:
    int __id = 0xf259a80b;

public:
    std::string url;
    long webpage_id;
    long author_photo_id;
    std::string author;
    int date;
    std::vector<TLObject> blocks;
    TLObject caption;
    PageBlockEmbedPost(std::string url_, long webpage_id_, long author_photo_id_, std::string author_, int date_, std::vector<TLObject> blocks_, TLObject caption_);
    static PageBlockEmbedPost read(Reader reader);
    std::string write();
};

class PageBlockCollage
{
private:
    int __id = 0x65a0fa4d;

public:
    std::vector<TLObject> items;
    TLObject caption;
    PageBlockCollage(std::vector<TLObject> items_, TLObject caption_);
    static PageBlockCollage read(Reader reader);
    std::string write();
};

class PageBlockSlideshow
{
private:
    int __id = 0x31f9590;

public:
    std::vector<TLObject> items;
    TLObject caption;
    PageBlockSlideshow(std::vector<TLObject> items_, TLObject caption_);
    static PageBlockSlideshow read(Reader reader);
    std::string write();
};

class PageBlockChannel
{
private:
    int __id = 0xef1751b5;

public:
    TLObject channel;
    PageBlockChannel(TLObject channel_);
    static PageBlockChannel read(Reader reader);
    std::string write();
};

class PageBlockAudio
{
private:
    int __id = 0x804361ea;

public:
    long audio_id;
    TLObject caption;
    PageBlockAudio(long audio_id_, TLObject caption_);
    static PageBlockAudio read(Reader reader);
    std::string write();
};

class PageBlockKicker
{
private:
    int __id = 0x1e148390;

public:
    TLObject text;
    PageBlockKicker(TLObject text_);
    static PageBlockKicker read(Reader reader);
    std::string write();
};

class PageBlockTable
{
private:
    int __id = 0xbf4dea82;

public:
    std::optional<bool> bordered;
    std::optional<bool> striped;
    TLObject title;
    std::vector<TLObject> rows;
    PageBlockTable(TLObject title_, std::vector<TLObject> rows_, std::optional<bool> bordered_ = std::nullopt, std::optional<bool> striped_ = std::nullopt);
    static PageBlockTable read(Reader reader);
    std::string write();
};

class PageBlockOrderedList
{
private:
    int __id = 0x9a8ae1e1;

public:
    std::vector<TLObject> items;
    PageBlockOrderedList(std::vector<TLObject> items_);
    static PageBlockOrderedList read(Reader reader);
    std::string write();
};

class PageBlockDetails
{
private:
    int __id = 0x76768bed;

public:
    std::optional<bool> open;
    std::vector<TLObject> blocks;
    TLObject title;
    PageBlockDetails(std::vector<TLObject> blocks_, TLObject title_, std::optional<bool> open_ = std::nullopt);
    static PageBlockDetails read(Reader reader);
    std::string write();
};

class PageBlockRelatedArticles
{
private:
    int __id = 0x16115a96;

public:
    TLObject title;
    std::vector<TLObject> articles;
    PageBlockRelatedArticles(TLObject title_, std::vector<TLObject> articles_);
    static PageBlockRelatedArticles read(Reader reader);
    std::string write();
};

class PageBlockMap
{
private:
    int __id = 0xa44f3ef6;

public:
    TLObject geo;
    int zoom;
    int w;
    int h;
    TLObject caption;
    PageBlockMap(TLObject geo_, int zoom_, int w_, int h_, TLObject caption_);
    static PageBlockMap read(Reader reader);
    std::string write();
};

class PhoneCallDiscardReasonMissed
{
private:
    int __id = 0x85e42301;

public:
    PhoneCallDiscardReasonMissed() = default;
    static PhoneCallDiscardReasonMissed read(Reader reader);
    std::string write();
};

class PhoneCallDiscardReasonDisconnect
{
private:
    int __id = 0xe095c1a0;

public:
    PhoneCallDiscardReasonDisconnect() = default;
    static PhoneCallDiscardReasonDisconnect read(Reader reader);
    std::string write();
};

class PhoneCallDiscardReasonHangup
{
private:
    int __id = 0x57adc690;

public:
    PhoneCallDiscardReasonHangup() = default;
    static PhoneCallDiscardReasonHangup read(Reader reader);
    std::string write();
};

class PhoneCallDiscardReasonBusy
{
private:
    int __id = 0xfaf7e8c9;

public:
    PhoneCallDiscardReasonBusy() = default;
    static PhoneCallDiscardReasonBusy read(Reader reader);
    std::string write();
};

class DataJSON
{
private:
    int __id = 0x7d748d04;

public:
    std::string data;
    DataJSON(std::string data_);
    static DataJSON read(Reader reader);
    std::string write();
};

class LabeledPrice
{
private:
    int __id = 0xcb296bf8;

public:
    std::string label;
    long amount;
    LabeledPrice(std::string label_, long amount_);
    static LabeledPrice read(Reader reader);
    std::string write();
};

class Invoice
{
private:
    int __id = 0xcd886e0;

public:
    std::optional<bool> test;
    std::optional<bool> name_requested;
    std::optional<bool> phone_requested;
    std::optional<bool> email_requested;
    std::optional<bool> shipping_address_requested;
    std::optional<bool> flexible;
    std::optional<bool> phone_to_provider;
    std::optional<bool> email_to_provider;
    std::string currency;
    std::vector<TLObject> prices;
    std::optional<long> max_tip_amount;
    std::optional<std::vector<long>> suggested_tip_amounts;
    Invoice(std::string currency_, std::vector<TLObject> prices_, std::optional<bool> test_ = std::nullopt, std::optional<bool> name_requested_ = std::nullopt, std::optional<bool> phone_requested_ = std::nullopt, std::optional<bool> email_requested_ = std::nullopt, std::optional<bool> shipping_address_requested_ = std::nullopt, std::optional<bool> flexible_ = std::nullopt, std::optional<bool> phone_to_provider_ = std::nullopt, std::optional<bool> email_to_provider_ = std::nullopt, std::optional<long> max_tip_amount_ = std::nullopt, std::optional<std::vector<long>> suggested_tip_amounts_ = std::nullopt);
    static Invoice read(Reader reader);
    std::string write();
};

class PaymentCharge
{
private:
    int __id = 0xea02c27e;

public:
    std::string id;
    std::string provider_charge_id;
    PaymentCharge(std::string id_, std::string provider_charge_id_);
    static PaymentCharge read(Reader reader);
    std::string write();
};

class PostAddress
{
private:
    int __id = 0x1e8caaeb;

public:
    std::string street_line1;
    std::string street_line2;
    std::string city;
    std::string state;
    std::string country_iso2;
    std::string post_code;
    PostAddress(std::string street_line1_, std::string street_line2_, std::string city_, std::string state_, std::string country_iso2_, std::string post_code_);
    static PostAddress read(Reader reader);
    std::string write();
};

class PaymentRequestedInfo
{
private:
    int __id = 0x909c3f94;

public:
    std::optional<std::string> name;
    std::optional<std::string> phone;
    std::optional<std::string> email;
    std::optional<TLObject> shipping_address;
    PaymentRequestedInfo(std::optional<std::string> name_ = std::nullopt, std::optional<std::string> phone_ = std::nullopt, std::optional<std::string> email_ = std::nullopt, std::optional<TLObject> shipping_address_ = std::nullopt);
    static PaymentRequestedInfo read(Reader reader);
    std::string write();
};

class PaymentSavedCredentialsCard
{
private:
    int __id = 0xcdc27a1f;

public:
    std::string id;
    std::string title;
    PaymentSavedCredentialsCard(std::string id_, std::string title_);
    static PaymentSavedCredentialsCard read(Reader reader);
    std::string write();
};

class WebDocument
{
private:
    int __id = 0x1c570ed1;

public:
    std::string url;
    long access_hash;
    int size;
    std::string mime_type;
    std::vector<TLObject> attributes;
    WebDocument(std::string url_, long access_hash_, int size_, std::string mime_type_, std::vector<TLObject> attributes_);
    static WebDocument read(Reader reader);
    std::string write();
};

class WebDocumentNoProxy
{
private:
    int __id = 0xf9c8bcc6;

public:
    std::string url;
    int size;
    std::string mime_type;
    std::vector<TLObject> attributes;
    WebDocumentNoProxy(std::string url_, int size_, std::string mime_type_, std::vector<TLObject> attributes_);
    static WebDocumentNoProxy read(Reader reader);
    std::string write();
};

class InputWebDocument
{
private:
    int __id = 0x9bed434d;

public:
    std::string url;
    int size;
    std::string mime_type;
    std::vector<TLObject> attributes;
    InputWebDocument(std::string url_, int size_, std::string mime_type_, std::vector<TLObject> attributes_);
    static InputWebDocument read(Reader reader);
    std::string write();
};

class InputWebFileLocation
{
private:
    int __id = 0xc239d686;

public:
    std::string url;
    long access_hash;
    InputWebFileLocation(std::string url_, long access_hash_);
    static InputWebFileLocation read(Reader reader);
    std::string write();
};

class InputWebFileGeoPointLocation
{
private:
    int __id = 0x9f2221c9;

public:
    TLObject geo_point;
    long access_hash;
    int w;
    int h;
    int zoom;
    int scale;
    InputWebFileGeoPointLocation(TLObject geo_point_, long access_hash_, int w_, int h_, int zoom_, int scale_);
    static InputWebFileGeoPointLocation read(Reader reader);
    std::string write();
};

class InputPaymentCredentialsSaved
{
private:
    int __id = 0xc10eb2cf;

public:
    std::string id;
    std::string tmp_password;
    InputPaymentCredentialsSaved(std::string id_, std::string tmp_password_);
    static InputPaymentCredentialsSaved read(Reader reader);
    std::string write();
};

class InputPaymentCredentials
{
private:
    int __id = 0x3417d728;

public:
    std::optional<bool> save;
    TLObject data;
    InputPaymentCredentials(TLObject data_, std::optional<bool> save_ = std::nullopt);
    static InputPaymentCredentials read(Reader reader);
    std::string write();
};

class InputPaymentCredentialsApplePay
{
private:
    int __id = 0xaa1c39f;

public:
    TLObject payment_data;
    InputPaymentCredentialsApplePay(TLObject payment_data_);
    static InputPaymentCredentialsApplePay read(Reader reader);
    std::string write();
};

class InputPaymentCredentialsGooglePay
{
private:
    int __id = 0x8ac32801;

public:
    TLObject payment_token;
    InputPaymentCredentialsGooglePay(TLObject payment_token_);
    static InputPaymentCredentialsGooglePay read(Reader reader);
    std::string write();
};

class ShippingOption
{
private:
    int __id = 0xb6213cdf;

public:
    std::string id;
    std::string title;
    std::vector<TLObject> prices;
    ShippingOption(std::string id_, std::string title_, std::vector<TLObject> prices_);
    static ShippingOption read(Reader reader);
    std::string write();
};

class InputStickerSetItem
{
private:
    int __id = 0xffa0a496;

public:
    TLObject document;
    std::string emoji;
    std::optional<TLObject> mask_coords;
    InputStickerSetItem(TLObject document_, std::string emoji_, std::optional<TLObject> mask_coords_ = std::nullopt);
    static InputStickerSetItem read(Reader reader);
    std::string write();
};

class InputPhoneCall
{
private:
    int __id = 0x1e36fded;

public:
    long id;
    long access_hash;
    InputPhoneCall(long id_, long access_hash_);
    static InputPhoneCall read(Reader reader);
    std::string write();
};

class PhoneCallEmpty
{
private:
    int __id = 0x5366c915;

public:
    long id;
    PhoneCallEmpty(long id_);
    static PhoneCallEmpty read(Reader reader);
    std::string write();
};

class PhoneCallWaiting
{
private:
    int __id = 0x1b8f4ad1;

public:
    std::optional<bool> video;
    long id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    TLObject protocol;
    std::optional<int> receive_date;
    PhoneCallWaiting(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, TLObject protocol_, std::optional<bool> video_ = std::nullopt, std::optional<int> receive_date_ = std::nullopt);
    static PhoneCallWaiting read(Reader reader);
    std::string write();
};

class PhoneCallRequested
{
private:
    int __id = 0x87eabb53;

public:
    std::optional<bool> video;
    long id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    std::string g_a_hash;
    TLObject protocol;
    PhoneCallRequested(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_hash_, TLObject protocol_, std::optional<bool> video_ = std::nullopt);
    static PhoneCallRequested read(Reader reader);
    std::string write();
};

class PhoneCallAccepted
{
private:
    int __id = 0x997c454a;

public:
    std::optional<bool> video;
    long id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    std::string g_b;
    TLObject protocol;
    PhoneCallAccepted(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_b_, TLObject protocol_, std::optional<bool> video_ = std::nullopt);
    static PhoneCallAccepted read(Reader reader);
    std::string write();
};

class PhoneCall
{
private:
    int __id = 0x8742ae7f;

public:
    std::optional<bool> p2p_allowed;
    std::optional<bool> video;
    long id;
    long access_hash;
    int date;
    int admin_id;
    int participant_id;
    std::string g_a_or_b;
    long key_fingerprint;
    TLObject protocol;
    std::vector<TLObject> connections;
    int start_date;
    PhoneCall(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_or_b_, long key_fingerprint_, TLObject protocol_, std::vector<TLObject> connections_, int start_date_, std::optional<bool> p2p_allowed_ = std::nullopt, std::optional<bool> video_ = std::nullopt);
    static PhoneCall read(Reader reader);
    std::string write();
};

class PhoneCallDiscarded
{
private:
    int __id = 0x50ca4de1;

public:
    std::optional<bool> need_rating;
    std::optional<bool> need_debug;
    std::optional<bool> video;
    long id;
    std::optional<TLObject> reason;
    std::optional<int> duration;
    PhoneCallDiscarded(long id_, std::optional<bool> need_rating_ = std::nullopt, std::optional<bool> need_debug_ = std::nullopt, std::optional<bool> video_ = std::nullopt, std::optional<TLObject> reason_ = std::nullopt, std::optional<int> duration_ = std::nullopt);
    static PhoneCallDiscarded read(Reader reader);
    std::string write();
};

class PhoneConnection
{
private:
    int __id = 0x9d4c17c0;

public:
    long id;
    std::string ip;
    std::string ipv6;
    int port;
    std::string peer_tag;
    PhoneConnection(long id_, std::string ip_, std::string ipv6_, int port_, std::string peer_tag_);
    static PhoneConnection read(Reader reader);
    std::string write();
};

class PhoneConnectionWebrtc
{
private:
    int __id = 0x635fe375;

public:
    std::optional<bool> turn;
    std::optional<bool> stun;
    long id;
    std::string ip;
    std::string ipv6;
    int port;
    std::string username;
    std::string password;
    PhoneConnectionWebrtc(long id_, std::string ip_, std::string ipv6_, int port_, std::string username_, std::string password_, std::optional<bool> turn_ = std::nullopt, std::optional<bool> stun_ = std::nullopt);
    static PhoneConnectionWebrtc read(Reader reader);
    std::string write();
};

class PhoneCallProtocol
{
private:
    int __id = 0xfc878fc8;

public:
    std::optional<bool> udp_p2p;
    std::optional<bool> udp_reflector;
    int min_layer;
    int max_layer;
    std::vector<std::string> library_versions;
    PhoneCallProtocol(int min_layer_, int max_layer_, std::vector<std::string> library_versions_, std::optional<bool> udp_p2p_ = std::nullopt, std::optional<bool> udp_reflector_ = std::nullopt);
    static PhoneCallProtocol read(Reader reader);
    std::string write();
};

class CdnPublicKey
{
private:
    int __id = 0xc982eaba;

public:
    int dc_id;
    std::string public_key;
    CdnPublicKey(int dc_id_, std::string public_key_);
    static CdnPublicKey read(Reader reader);
    std::string write();
};

class CdnConfig
{
private:
    int __id = 0x5725e40a;

public:
    std::vector<TLObject> public_keys;
    CdnConfig(std::vector<TLObject> public_keys_);
    static CdnConfig read(Reader reader);
    std::string write();
};

class LangPackString
{
private:
    int __id = 0xcad181f6;

public:
    std::string key;
    std::string value;
    LangPackString(std::string key_, std::string value_);
    static LangPackString read(Reader reader);
    std::string write();
};

class LangPackStringPluralized
{
private:
    int __id = 0x6c47ac9f;

public:
    std::string key;
    std::optional<std::string> zero_value;
    std::optional<std::string> one_value;
    std::optional<std::string> two_value;
    std::optional<std::string> few_value;
    std::optional<std::string> many_value;
    std::string other_value;
    LangPackStringPluralized(std::string key_, std::string other_value_, std::optional<std::string> zero_value_ = std::nullopt, std::optional<std::string> one_value_ = std::nullopt, std::optional<std::string> two_value_ = std::nullopt, std::optional<std::string> few_value_ = std::nullopt, std::optional<std::string> many_value_ = std::nullopt);
    static LangPackStringPluralized read(Reader reader);
    std::string write();
};

class LangPackStringDeleted
{
private:
    int __id = 0x2979eeb2;

public:
    std::string key;
    LangPackStringDeleted(std::string key_);
    static LangPackStringDeleted read(Reader reader);
    std::string write();
};

class LangPackDifference
{
private:
    int __id = 0xf385c1f6;

public:
    std::string lang_code;
    int from_version;
    int version;
    std::vector<TLObject> strings;
    LangPackDifference(std::string lang_code_, int from_version_, int version_, std::vector<TLObject> strings_);
    static LangPackDifference read(Reader reader);
    std::string write();
};

class LangPackLanguage
{
private:
    int __id = 0xeeca5ce3;

public:
    std::optional<bool> official;
    std::optional<bool> rtl;
    std::optional<bool> beta;
    std::string name;
    std::string native_name;
    std::string lang_code;
    std::optional<std::string> base_lang_code;
    std::string plural_code;
    int strings_count;
    int translated_count;
    std::string translations_url;
    LangPackLanguage(std::string name_, std::string native_name_, std::string lang_code_, std::string plural_code_, int strings_count_, int translated_count_, std::string translations_url_, std::optional<bool> official_ = std::nullopt, std::optional<bool> rtl_ = std::nullopt, std::optional<bool> beta_ = std::nullopt, std::optional<std::string> base_lang_code_ = std::nullopt);
    static LangPackLanguage read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeTitle
{
private:
    int __id = 0xe6dfb825;

public:
    std::string prev_value;
    std::string new_value;
    ChannelAdminLogEventActionChangeTitle(std::string prev_value_, std::string new_value_);
    static ChannelAdminLogEventActionChangeTitle read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeAbout
{
private:
    int __id = 0x55188a2e;

public:
    std::string prev_value;
    std::string new_value;
    ChannelAdminLogEventActionChangeAbout(std::string prev_value_, std::string new_value_);
    static ChannelAdminLogEventActionChangeAbout read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeUsername
{
private:
    int __id = 0x6a4afc38;

public:
    std::string prev_value;
    std::string new_value;
    ChannelAdminLogEventActionChangeUsername(std::string prev_value_, std::string new_value_);
    static ChannelAdminLogEventActionChangeUsername read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangePhoto
{
private:
    int __id = 0x434bd2af;

public:
    TLObject prev_photo;
    TLObject new_photo;
    ChannelAdminLogEventActionChangePhoto(TLObject prev_photo_, TLObject new_photo_);
    static ChannelAdminLogEventActionChangePhoto read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionToggleInvites
{
private:
    int __id = 0x1b7907ae;

public:
    bool new_value;
    ChannelAdminLogEventActionToggleInvites(bool new_value_);
    static ChannelAdminLogEventActionToggleInvites read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionToggleSignatures
{
private:
    int __id = 0x26ae0971;

public:
    bool new_value;
    ChannelAdminLogEventActionToggleSignatures(bool new_value_);
    static ChannelAdminLogEventActionToggleSignatures read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionUpdatePinned
{
private:
    int __id = 0xe9e82c18;

public:
    TLObject message;
    ChannelAdminLogEventActionUpdatePinned(TLObject message_);
    static ChannelAdminLogEventActionUpdatePinned read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionEditMessage
{
private:
    int __id = 0x709b2405;

public:
    TLObject prev_message;
    TLObject new_message;
    ChannelAdminLogEventActionEditMessage(TLObject prev_message_, TLObject new_message_);
    static ChannelAdminLogEventActionEditMessage read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionDeleteMessage
{
private:
    int __id = 0x42e047bb;

public:
    TLObject message;
    ChannelAdminLogEventActionDeleteMessage(TLObject message_);
    static ChannelAdminLogEventActionDeleteMessage read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantJoin
{
private:
    int __id = 0x183040d3;

public:
    ChannelAdminLogEventActionParticipantJoin() = default;
    static ChannelAdminLogEventActionParticipantJoin read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantLeave
{
private:
    int __id = 0xf89777f2;

public:
    ChannelAdminLogEventActionParticipantLeave() = default;
    static ChannelAdminLogEventActionParticipantLeave read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantInvite
{
private:
    int __id = 0xe31c34d8;

public:
    TLObject participant;
    ChannelAdminLogEventActionParticipantInvite(TLObject participant_);
    static ChannelAdminLogEventActionParticipantInvite read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantToggleBan
{
private:
    int __id = 0xe6d83d7e;

public:
    TLObject prev_participant;
    TLObject new_participant;
    ChannelAdminLogEventActionParticipantToggleBan(TLObject prev_participant_, TLObject new_participant_);
    static ChannelAdminLogEventActionParticipantToggleBan read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantToggleAdmin
{
private:
    int __id = 0xd5676710;

public:
    TLObject prev_participant;
    TLObject new_participant;
    ChannelAdminLogEventActionParticipantToggleAdmin(TLObject prev_participant_, TLObject new_participant_);
    static ChannelAdminLogEventActionParticipantToggleAdmin read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeStickerSet
{
private:
    int __id = 0xb1c3caa7;

public:
    TLObject prev_stickerset;
    TLObject new_stickerset;
    ChannelAdminLogEventActionChangeStickerSet(TLObject prev_stickerset_, TLObject new_stickerset_);
    static ChannelAdminLogEventActionChangeStickerSet read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionTogglePreHistoryHidden
{
private:
    int __id = 0x5f5c95f1;

public:
    bool new_value;
    ChannelAdminLogEventActionTogglePreHistoryHidden(bool new_value_);
    static ChannelAdminLogEventActionTogglePreHistoryHidden read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionDefaultBannedRights
{
private:
    int __id = 0x2df5fc0a;

public:
    TLObject prev_banned_rights;
    TLObject new_banned_rights;
    ChannelAdminLogEventActionDefaultBannedRights(TLObject prev_banned_rights_, TLObject new_banned_rights_);
    static ChannelAdminLogEventActionDefaultBannedRights read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionStopPoll
{
private:
    int __id = 0x8f079643;

public:
    TLObject message;
    ChannelAdminLogEventActionStopPoll(TLObject message_);
    static ChannelAdminLogEventActionStopPoll read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeLinkedChat
{
private:
    int __id = 0xa26f881b;

public:
    int prev_value;
    int new_value;
    ChannelAdminLogEventActionChangeLinkedChat(int prev_value_, int new_value_);
    static ChannelAdminLogEventActionChangeLinkedChat read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeLocation
{
private:
    int __id = 0xe6b76ae;

public:
    TLObject prev_value;
    TLObject new_value;
    ChannelAdminLogEventActionChangeLocation(TLObject prev_value_, TLObject new_value_);
    static ChannelAdminLogEventActionChangeLocation read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionToggleSlowMode
{
private:
    int __id = 0x53909779;

public:
    int prev_value;
    int new_value;
    ChannelAdminLogEventActionToggleSlowMode(int prev_value_, int new_value_);
    static ChannelAdminLogEventActionToggleSlowMode read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionStartGroupCall
{
private:
    int __id = 0x23209745;

public:
    TLObject call;
    ChannelAdminLogEventActionStartGroupCall(TLObject call_);
    static ChannelAdminLogEventActionStartGroupCall read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionDiscardGroupCall
{
private:
    int __id = 0xdb9f9140;

public:
    TLObject call;
    ChannelAdminLogEventActionDiscardGroupCall(TLObject call_);
    static ChannelAdminLogEventActionDiscardGroupCall read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantMute
{
private:
    int __id = 0xf92424d2;

public:
    TLObject participant;
    ChannelAdminLogEventActionParticipantMute(TLObject participant_);
    static ChannelAdminLogEventActionParticipantMute read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantUnmute
{
private:
    int __id = 0xe64429c0;

public:
    TLObject participant;
    ChannelAdminLogEventActionParticipantUnmute(TLObject participant_);
    static ChannelAdminLogEventActionParticipantUnmute read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionToggleGroupCallSetting
{
private:
    int __id = 0x56d6a247;

public:
    bool join_muted;
    ChannelAdminLogEventActionToggleGroupCallSetting(bool join_muted_);
    static ChannelAdminLogEventActionToggleGroupCallSetting read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantJoinByInvite
{
private:
    int __id = 0x5cdada77;

public:
    TLObject invite;
    ChannelAdminLogEventActionParticipantJoinByInvite(TLObject invite_);
    static ChannelAdminLogEventActionParticipantJoinByInvite read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionExportedInviteDelete
{
private:
    int __id = 0x5a50fca4;

public:
    TLObject invite;
    ChannelAdminLogEventActionExportedInviteDelete(TLObject invite_);
    static ChannelAdminLogEventActionExportedInviteDelete read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionExportedInviteRevoke
{
private:
    int __id = 0x410a134e;

public:
    TLObject invite;
    ChannelAdminLogEventActionExportedInviteRevoke(TLObject invite_);
    static ChannelAdminLogEventActionExportedInviteRevoke read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionExportedInviteEdit
{
private:
    int __id = 0xe90ebb59;

public:
    TLObject prev_invite;
    TLObject new_invite;
    ChannelAdminLogEventActionExportedInviteEdit(TLObject prev_invite_, TLObject new_invite_);
    static ChannelAdminLogEventActionExportedInviteEdit read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionParticipantVolume
{
private:
    int __id = 0x3e7f6847;

public:
    TLObject participant;
    ChannelAdminLogEventActionParticipantVolume(TLObject participant_);
    static ChannelAdminLogEventActionParticipantVolume read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventActionChangeHistoryTTL
{
private:
    int __id = 0x6e941a38;

public:
    int prev_value;
    int new_value;
    ChannelAdminLogEventActionChangeHistoryTTL(int prev_value_, int new_value_);
    static ChannelAdminLogEventActionChangeHistoryTTL read(Reader reader);
    std::string write();
};

class ChannelAdminLogEvent
{
private:
    int __id = 0x3b5a3e40;

public:
    long id;
    int date;
    int user_id;
    TLObject action;
    ChannelAdminLogEvent(long id_, int date_, int user_id_, TLObject action_);
    static ChannelAdminLogEvent read(Reader reader);
    std::string write();
};

class ChannelAdminLogEventsFilter
{
private:
    int __id = 0xea107ae4;

public:
    std::optional<bool> join;
    std::optional<bool> leave;
    std::optional<bool> invite;
    std::optional<bool> ban;
    std::optional<bool> unban;
    std::optional<bool> kick;
    std::optional<bool> unkick;
    std::optional<bool> promote;
    std::optional<bool> demote;
    std::optional<bool> info;
    std::optional<bool> settings;
    std::optional<bool> pinned;
    std::optional<bool> edit;
    std::optional<bool> delete_;
    std::optional<bool> group_call;
    std::optional<bool> invites;
    ChannelAdminLogEventsFilter(std::optional<bool> join_ = std::nullopt, std::optional<bool> leave_ = std::nullopt, std::optional<bool> invite_ = std::nullopt, std::optional<bool> ban_ = std::nullopt, std::optional<bool> unban_ = std::nullopt, std::optional<bool> kick_ = std::nullopt, std::optional<bool> unkick_ = std::nullopt, std::optional<bool> promote_ = std::nullopt, std::optional<bool> demote_ = std::nullopt, std::optional<bool> info_ = std::nullopt, std::optional<bool> settings_ = std::nullopt, std::optional<bool> pinned_ = std::nullopt, std::optional<bool> edit_ = std::nullopt, std::optional<bool> delete__ = std::nullopt, std::optional<bool> group_call_ = std::nullopt, std::optional<bool> invites_ = std::nullopt);
    static ChannelAdminLogEventsFilter read(Reader reader);
    std::string write();
};

class PopularContact
{
private:
    int __id = 0x5ce14175;

public:
    long client_id;
    int importers;
    PopularContact(long client_id_, int importers_);
    static PopularContact read(Reader reader);
    std::string write();
};

class RecentMeUrlUnknown
{
private:
    int __id = 0x46e1d13d;

public:
    std::string url;
    RecentMeUrlUnknown(std::string url_);
    static RecentMeUrlUnknown read(Reader reader);
    std::string write();
};

class RecentMeUrlUser
{
private:
    int __id = 0x8dbc3336;

public:
    std::string url;
    int user_id;
    RecentMeUrlUser(std::string url_, int user_id_);
    static RecentMeUrlUser read(Reader reader);
    std::string write();
};

class RecentMeUrlChat
{
private:
    int __id = 0xa01b22f9;

public:
    std::string url;
    int chat_id;
    RecentMeUrlChat(std::string url_, int chat_id_);
    static RecentMeUrlChat read(Reader reader);
    std::string write();
};

class RecentMeUrlChatInvite
{
private:
    int __id = 0xeb49081d;

public:
    std::string url;
    TLObject chat_invite;
    RecentMeUrlChatInvite(std::string url_, TLObject chat_invite_);
    static RecentMeUrlChatInvite read(Reader reader);
    std::string write();
};

class RecentMeUrlStickerSet
{
private:
    int __id = 0xbc0a57dc;

public:
    std::string url;
    TLObject set;
    RecentMeUrlStickerSet(std::string url_, TLObject set_);
    static RecentMeUrlStickerSet read(Reader reader);
    std::string write();
};

class InputSingleMedia
{
private:
    int __id = 0x1cc6e91f;

public:
    TLObject media;
    long random_id;
    std::string message;
    std::optional<std::vector<TLObject>> entities;
    InputSingleMedia(TLObject media_, long random_id_, std::string message_, std::optional<std::vector<TLObject>> entities_ = std::nullopt);
    static InputSingleMedia read(Reader reader);
    std::string write();
};

class WebAuthorization
{
private:
    int __id = 0xcac943f2;

public:
    long hash;
    int bot_id;
    std::string domain;
    std::string browser;
    std::string platform;
    int date_created;
    int date_active;
    std::string ip;
    std::string region;
    WebAuthorization(long hash_, int bot_id_, std::string domain_, std::string browser_, std::string platform_, int date_created_, int date_active_, std::string ip_, std::string region_);
    static WebAuthorization read(Reader reader);
    std::string write();
};

class InputMessageID
{
private:
    int __id = 0xa676a322;

public:
    int id;
    InputMessageID(int id_);
    static InputMessageID read(Reader reader);
    std::string write();
};

class InputMessageReplyTo
{
private:
    int __id = 0xbad88395;

public:
    int id;
    InputMessageReplyTo(int id_);
    static InputMessageReplyTo read(Reader reader);
    std::string write();
};

class InputMessagePinned
{
private:
    int __id = 0x86872538;

public:
    InputMessagePinned() = default;
    static InputMessagePinned read(Reader reader);
    std::string write();
};

class InputMessageCallbackQuery
{
private:
    int __id = 0xacfa1a7e;

public:
    int id;
    long query_id;
    InputMessageCallbackQuery(int id_, long query_id_);
    static InputMessageCallbackQuery read(Reader reader);
    std::string write();
};

class InputDialogPeer
{
private:
    int __id = 0xfcaafeb7;

public:
    TLObject peer;
    InputDialogPeer(TLObject peer_);
    static InputDialogPeer read(Reader reader);
    std::string write();
};

class InputDialogPeerFolder
{
private:
    int __id = 0x64600527;

public:
    int folder_id;
    InputDialogPeerFolder(int folder_id_);
    static InputDialogPeerFolder read(Reader reader);
    std::string write();
};

class DialogPeer
{
private:
    int __id = 0xe56dbf05;

public:
    TLObject peer;
    DialogPeer(TLObject peer_);
    static DialogPeer read(Reader reader);
    std::string write();
};

class DialogPeerFolder
{
private:
    int __id = 0x514519e2;

public:
    int folder_id;
    DialogPeerFolder(int folder_id_);
    static DialogPeerFolder read(Reader reader);
    std::string write();
};

class FileHash
{
private:
    int __id = 0x6242c773;

public:
    int offset;
    int limit;
    std::string hash;
    FileHash(int offset_, int limit_, std::string hash_);
    static FileHash read(Reader reader);
    std::string write();
};

class InputClientProxy
{
private:
    int __id = 0x75588b3f;

public:
    std::string address;
    int port;
    InputClientProxy(std::string address_, int port_);
    static InputClientProxy read(Reader reader);
    std::string write();
};

class InputSecureFileUploaded
{
private:
    int __id = 0x3334b0f0;

public:
    long id;
    int parts;
    std::string md5_checksum;
    std::string file_hash;
    std::string secret;
    InputSecureFileUploaded(long id_, int parts_, std::string md5_checksum_, std::string file_hash_, std::string secret_);
    static InputSecureFileUploaded read(Reader reader);
    std::string write();
};

class InputSecureFile
{
private:
    int __id = 0x5367e5be;

public:
    long id;
    long access_hash;
    InputSecureFile(long id_, long access_hash_);
    static InputSecureFile read(Reader reader);
    std::string write();
};

class SecureFileEmpty
{
private:
    int __id = 0x64199744;

public:
    SecureFileEmpty() = default;
    static SecureFileEmpty read(Reader reader);
    std::string write();
};

class SecureFile
{
private:
    int __id = 0xe0277a62;

public:
    long id;
    long access_hash;
    int size;
    int dc_id;
    int date;
    std::string file_hash;
    std::string secret;
    SecureFile(long id_, long access_hash_, int size_, int dc_id_, int date_, std::string file_hash_, std::string secret_);
    static SecureFile read(Reader reader);
    std::string write();
};

class SecureData
{
private:
    int __id = 0x8aeabec3;

public:
    std::string data;
    std::string data_hash;
    std::string secret;
    SecureData(std::string data_, std::string data_hash_, std::string secret_);
    static SecureData read(Reader reader);
    std::string write();
};

class SecurePlainPhone
{
private:
    int __id = 0x7d6099dd;

public:
    std::string phone;
    SecurePlainPhone(std::string phone_);
    static SecurePlainPhone read(Reader reader);
    std::string write();
};

class SecurePlainEmail
{
private:
    int __id = 0x21ec5a5f;

public:
    std::string email;
    SecurePlainEmail(std::string email_);
    static SecurePlainEmail read(Reader reader);
    std::string write();
};

class SecureValueTypePersonalDetails
{
private:
    int __id = 0x9d2a81e3;

public:
    SecureValueTypePersonalDetails() = default;
    static SecureValueTypePersonalDetails read(Reader reader);
    std::string write();
};

class SecureValueTypePassport
{
private:
    int __id = 0x3dac6a00;

public:
    SecureValueTypePassport() = default;
    static SecureValueTypePassport read(Reader reader);
    std::string write();
};

class SecureValueTypeDriverLicense
{
private:
    int __id = 0x6e425c4;

public:
    SecureValueTypeDriverLicense() = default;
    static SecureValueTypeDriverLicense read(Reader reader);
    std::string write();
};

class SecureValueTypeIdentityCard
{
private:
    int __id = 0xa0d0744b;

public:
    SecureValueTypeIdentityCard() = default;
    static SecureValueTypeIdentityCard read(Reader reader);
    std::string write();
};

class SecureValueTypeInternalPassport
{
private:
    int __id = 0x99a48f23;

public:
    SecureValueTypeInternalPassport() = default;
    static SecureValueTypeInternalPassport read(Reader reader);
    std::string write();
};

class SecureValueTypeAddress
{
private:
    int __id = 0xcbe31e26;

public:
    SecureValueTypeAddress() = default;
    static SecureValueTypeAddress read(Reader reader);
    std::string write();
};

class SecureValueTypeUtilityBill
{
private:
    int __id = 0xfc36954e;

public:
    SecureValueTypeUtilityBill() = default;
    static SecureValueTypeUtilityBill read(Reader reader);
    std::string write();
};

class SecureValueTypeBankStatement
{
private:
    int __id = 0x89137c0d;

public:
    SecureValueTypeBankStatement() = default;
    static SecureValueTypeBankStatement read(Reader reader);
    std::string write();
};

class SecureValueTypeRentalAgreement
{
private:
    int __id = 0x8b883488;

public:
    SecureValueTypeRentalAgreement() = default;
    static SecureValueTypeRentalAgreement read(Reader reader);
    std::string write();
};

class SecureValueTypePassportRegistration
{
private:
    int __id = 0x99e3806a;

public:
    SecureValueTypePassportRegistration() = default;
    static SecureValueTypePassportRegistration read(Reader reader);
    std::string write();
};

class SecureValueTypeTemporaryRegistration
{
private:
    int __id = 0xea02ec33;

public:
    SecureValueTypeTemporaryRegistration() = default;
    static SecureValueTypeTemporaryRegistration read(Reader reader);
    std::string write();
};

class SecureValueTypePhone
{
private:
    int __id = 0xb320aadb;

public:
    SecureValueTypePhone() = default;
    static SecureValueTypePhone read(Reader reader);
    std::string write();
};

class SecureValueTypeEmail
{
private:
    int __id = 0x8e3ca7ee;

public:
    SecureValueTypeEmail() = default;
    static SecureValueTypeEmail read(Reader reader);
    std::string write();
};

class SecureValue
{
private:
    int __id = 0x187fa0ca;

public:
    TLObject type;
    std::optional<TLObject> data;
    std::optional<TLObject> front_side;
    std::optional<TLObject> reverse_side;
    std::optional<TLObject> selfie;
    std::optional<std::vector<TLObject>> translation;
    std::optional<std::vector<TLObject>> files;
    std::optional<TLObject> plain_data;
    std::string hash;
    SecureValue(TLObject type_, std::string hash_, std::optional<TLObject> data_ = std::nullopt, std::optional<TLObject> front_side_ = std::nullopt, std::optional<TLObject> reverse_side_ = std::nullopt, std::optional<TLObject> selfie_ = std::nullopt, std::optional<std::vector<TLObject>> translation_ = std::nullopt, std::optional<std::vector<TLObject>> files_ = std::nullopt, std::optional<TLObject> plain_data_ = std::nullopt);
    static SecureValue read(Reader reader);
    std::string write();
};

class InputSecureValue
{
private:
    int __id = 0xdb21d0a7;

public:
    TLObject type;
    std::optional<TLObject> data;
    std::optional<TLObject> front_side;
    std::optional<TLObject> reverse_side;
    std::optional<TLObject> selfie;
    std::optional<std::vector<TLObject>> translation;
    std::optional<std::vector<TLObject>> files;
    std::optional<TLObject> plain_data;
    InputSecureValue(TLObject type_, std::optional<TLObject> data_ = std::nullopt, std::optional<TLObject> front_side_ = std::nullopt, std::optional<TLObject> reverse_side_ = std::nullopt, std::optional<TLObject> selfie_ = std::nullopt, std::optional<std::vector<TLObject>> translation_ = std::nullopt, std::optional<std::vector<TLObject>> files_ = std::nullopt, std::optional<TLObject> plain_data_ = std::nullopt);
    static InputSecureValue read(Reader reader);
    std::string write();
};

class SecureValueHash
{
private:
    int __id = 0xed1ecdb0;

public:
    TLObject type;
    std::string hash;
    SecureValueHash(TLObject type_, std::string hash_);
    static SecureValueHash read(Reader reader);
    std::string write();
};

class SecureValueErrorData
{
private:
    int __id = 0xe8a40bd9;

public:
    TLObject type;
    std::string data_hash;
    std::string field;
    std::string text;
    SecureValueErrorData(TLObject type_, std::string data_hash_, std::string field_, std::string text_);
    static SecureValueErrorData read(Reader reader);
    std::string write();
};

class SecureValueErrorFrontSide
{
private:
    int __id = 0xbe3dfa;

public:
    TLObject type;
    std::string file_hash;
    std::string text;
    SecureValueErrorFrontSide(TLObject type_, std::string file_hash_, std::string text_);
    static SecureValueErrorFrontSide read(Reader reader);
    std::string write();
};

class SecureValueErrorReverseSide
{
private:
    int __id = 0x868a2aa5;

public:
    TLObject type;
    std::string file_hash;
    std::string text;
    SecureValueErrorReverseSide(TLObject type_, std::string file_hash_, std::string text_);
    static SecureValueErrorReverseSide read(Reader reader);
    std::string write();
};

class SecureValueErrorSelfie
{
private:
    int __id = 0xe537ced6;

public:
    TLObject type;
    std::string file_hash;
    std::string text;
    SecureValueErrorSelfie(TLObject type_, std::string file_hash_, std::string text_);
    static SecureValueErrorSelfie read(Reader reader);
    std::string write();
};

class SecureValueErrorFile
{
private:
    int __id = 0x7a700873;

public:
    TLObject type;
    std::string file_hash;
    std::string text;
    SecureValueErrorFile(TLObject type_, std::string file_hash_, std::string text_);
    static SecureValueErrorFile read(Reader reader);
    std::string write();
};

class SecureValueErrorFiles
{
private:
    int __id = 0x666220e9;

public:
    TLObject type;
    std::vector<std::string> file_hash;
    std::string text;
    SecureValueErrorFiles(TLObject type_, std::vector<std::string> file_hash_, std::string text_);
    static SecureValueErrorFiles read(Reader reader);
    std::string write();
};

class SecureValueError
{
private:
    int __id = 0x869d758f;

public:
    TLObject type;
    std::string hash;
    std::string text;
    SecureValueError(TLObject type_, std::string hash_, std::string text_);
    static SecureValueError read(Reader reader);
    std::string write();
};

class SecureValueErrorTranslationFile
{
private:
    int __id = 0xa1144770;

public:
    TLObject type;
    std::string file_hash;
    std::string text;
    SecureValueErrorTranslationFile(TLObject type_, std::string file_hash_, std::string text_);
    static SecureValueErrorTranslationFile read(Reader reader);
    std::string write();
};

class SecureValueErrorTranslationFiles
{
private:
    int __id = 0x34636dd8;

public:
    TLObject type;
    std::vector<std::string> file_hash;
    std::string text;
    SecureValueErrorTranslationFiles(TLObject type_, std::vector<std::string> file_hash_, std::string text_);
    static SecureValueErrorTranslationFiles read(Reader reader);
    std::string write();
};

class SecureCredentialsEncrypted
{
private:
    int __id = 0x33f0ea47;

public:
    std::string data;
    std::string hash;
    std::string secret;
    SecureCredentialsEncrypted(std::string data_, std::string hash_, std::string secret_);
    static SecureCredentialsEncrypted read(Reader reader);
    std::string write();
};

class SavedPhoneContact
{
private:
    int __id = 0x1142bd56;

public:
    std::string phone;
    std::string first_name;
    std::string last_name;
    int date;
    SavedPhoneContact(std::string phone_, std::string first_name_, std::string last_name_, int date_);
    static SavedPhoneContact read(Reader reader);
    std::string write();
};

class PasswordKdfAlgoUnknown
{
private:
    int __id = 0xd45ab096;

public:
    PasswordKdfAlgoUnknown() = default;
    static PasswordKdfAlgoUnknown read(Reader reader);
    std::string write();
};

class SecurePasswordKdfAlgoUnknown
{
private:
    int __id = 0x4a8537;

public:
    SecurePasswordKdfAlgoUnknown() = default;
    static SecurePasswordKdfAlgoUnknown read(Reader reader);
    std::string write();
};

class SecureSecretSettings
{
private:
    int __id = 0x1527bcac;

public:
    TLObject secure_algo;
    std::string secure_secret;
    long secure_secret_id;
    SecureSecretSettings(TLObject secure_algo_, std::string secure_secret_, long secure_secret_id_);
    static SecureSecretSettings read(Reader reader);
    std::string write();
};

class InputCheckPasswordEmpty
{
private:
    int __id = 0x9880f658;

public:
    InputCheckPasswordEmpty() = default;
    static InputCheckPasswordEmpty read(Reader reader);
    std::string write();
};

class InputCheckPasswordSRP
{
private:
    int __id = 0xd27ff082;

public:
    long srp_id;
    std::string A;
    std::string M1;
    InputCheckPasswordSRP(long srp_id_, std::string A_, std::string M1_);
    static InputCheckPasswordSRP read(Reader reader);
    std::string write();
};

class SecureRequiredType
{
private:
    int __id = 0x829d99da;

public:
    std::optional<bool> native_names;
    std::optional<bool> selfie_required;
    std::optional<bool> translation_required;
    TLObject type;
    SecureRequiredType(TLObject type_, std::optional<bool> native_names_ = std::nullopt, std::optional<bool> selfie_required_ = std::nullopt, std::optional<bool> translation_required_ = std::nullopt);
    static SecureRequiredType read(Reader reader);
    std::string write();
};

class SecureRequiredTypeOneOf
{
private:
    int __id = 0x27477b4;

public:
    std::vector<TLObject> types;
    SecureRequiredTypeOneOf(std::vector<TLObject> types_);
    static SecureRequiredTypeOneOf read(Reader reader);
    std::string write();
};

class InputAppEvent
{
private:
    int __id = 0x1d1b1245;

public:
    double time;
    std::string type;
    long peer;
    TLObject data;
    InputAppEvent(double time_, std::string type_, long peer_, TLObject data_);
    static InputAppEvent read(Reader reader);
    std::string write();
};

class JsonObjectValue
{
private:
    int __id = 0xc0de1bd9;

public:
    std::string key;
    TLObject value;
    JsonObjectValue(std::string key_, TLObject value_);
    static JsonObjectValue read(Reader reader);
    std::string write();
};

class JsonNull
{
private:
    int __id = 0x3f6d7b68;

public:
    JsonNull() = default;
    static JsonNull read(Reader reader);
    std::string write();
};

class JsonBool
{
private:
    int __id = 0xc7345e6a;

public:
    bool value;
    JsonBool(bool value_);
    static JsonBool read(Reader reader);
    std::string write();
};

class JsonNumber
{
private:
    int __id = 0x2be0dfa4;

public:
    double value;
    JsonNumber(double value_);
    static JsonNumber read(Reader reader);
    std::string write();
};

class JsonString
{
private:
    int __id = 0xb71e767a;

public:
    std::string value;
    JsonString(std::string value_);
    static JsonString read(Reader reader);
    std::string write();
};

class JsonArray
{
private:
    int __id = 0xf7444763;

public:
    std::vector<TLObject> value;
    JsonArray(std::vector<TLObject> value_);
    static JsonArray read(Reader reader);
    std::string write();
};

class JsonObject
{
private:
    int __id = 0x99c1d49d;

public:
    std::vector<TLObject> value;
    JsonObject(std::vector<TLObject> value_);
    static JsonObject read(Reader reader);
    std::string write();
};

class PageTableCell
{
private:
    int __id = 0x34566b6a;

public:
    std::optional<bool> header;
    std::optional<bool> align_center;
    std::optional<bool> align_right;
    std::optional<bool> valign_middle;
    std::optional<bool> valign_bottom;
    std::optional<TLObject> text;
    std::optional<int> colspan;
    std::optional<int> rowspan;
    PageTableCell(std::optional<bool> header_ = std::nullopt, std::optional<bool> align_center_ = std::nullopt, std::optional<bool> align_right_ = std::nullopt, std::optional<bool> valign_middle_ = std::nullopt, std::optional<bool> valign_bottom_ = std::nullopt, std::optional<TLObject> text_ = std::nullopt, std::optional<int> colspan_ = std::nullopt, std::optional<int> rowspan_ = std::nullopt);
    static PageTableCell read(Reader reader);
    std::string write();
};

class PageTableRow
{
private:
    int __id = 0xe0c0c5e5;

public:
    std::vector<TLObject> cells;
    PageTableRow(std::vector<TLObject> cells_);
    static PageTableRow read(Reader reader);
    std::string write();
};

class PageCaption
{
private:
    int __id = 0x6f747657;

public:
    TLObject text;
    TLObject credit;
    PageCaption(TLObject text_, TLObject credit_);
    static PageCaption read(Reader reader);
    std::string write();
};

class PageListItemText
{
private:
    int __id = 0xb92fb6cd;

public:
    TLObject text;
    PageListItemText(TLObject text_);
    static PageListItemText read(Reader reader);
    std::string write();
};

class PageListItemBlocks
{
private:
    int __id = 0x25e073fc;

public:
    std::vector<TLObject> blocks;
    PageListItemBlocks(std::vector<TLObject> blocks_);
    static PageListItemBlocks read(Reader reader);
    std::string write();
};

class PageListOrderedItemText
{
private:
    int __id = 0x5e068047;

public:
    std::string num;
    TLObject text;
    PageListOrderedItemText(std::string num_, TLObject text_);
    static PageListOrderedItemText read(Reader reader);
    std::string write();
};

class PageListOrderedItemBlocks
{
private:
    int __id = 0x98dd8936;

public:
    std::string num;
    std::vector<TLObject> blocks;
    PageListOrderedItemBlocks(std::string num_, std::vector<TLObject> blocks_);
    static PageListOrderedItemBlocks read(Reader reader);
    std::string write();
};

class PageRelatedArticle
{
private:
    int __id = 0xb390dc08;

public:
    std::string url;
    long webpage_id;
    std::optional<std::string> title;
    std::optional<std::string> description;
    std::optional<long> photo_id;
    std::optional<std::string> author;
    std::optional<int> published_date;
    PageRelatedArticle(std::string url_, long webpage_id_, std::optional<std::string> title_ = std::nullopt, std::optional<std::string> description_ = std::nullopt, std::optional<long> photo_id_ = std::nullopt, std::optional<std::string> author_ = std::nullopt, std::optional<int> published_date_ = std::nullopt);
    static PageRelatedArticle read(Reader reader);
    std::string write();
};

class Page
{
private:
    int __id = 0x98657f0d;

public:
    std::optional<bool> part;
    std::optional<bool> rtl;
    std::optional<bool> v2;
    std::string url;
    std::vector<TLObject> blocks;
    std::vector<TLObject> photos;
    std::vector<TLObject> documents;
    std::optional<int> views;
    Page(std::string url_, std::vector<TLObject> blocks_, std::vector<TLObject> photos_, std::vector<TLObject> documents_, std::optional<bool> part_ = std::nullopt, std::optional<bool> rtl_ = std::nullopt, std::optional<bool> v2_ = std::nullopt, std::optional<int> views_ = std::nullopt);
    static Page read(Reader reader);
    std::string write();
};

class PollAnswer
{
private:
    int __id = 0x6ca9c2e9;

public:
    std::string text;
    std::string option;
    PollAnswer(std::string text_, std::string option_);
    static PollAnswer read(Reader reader);
    std::string write();
};

class Poll
{
private:
    int __id = 0x86e18161;

public:
    long id;
    std::optional<bool> closed;
    std::optional<bool> public_voters;
    std::optional<bool> multiple_choice;
    std::optional<bool> quiz;
    std::string question;
    std::vector<TLObject> answers;
    std::optional<int> close_period;
    std::optional<int> close_date;
    Poll(long id_, std::string question_, std::vector<TLObject> answers_, std::optional<bool> closed_ = std::nullopt, std::optional<bool> public_voters_ = std::nullopt, std::optional<bool> multiple_choice_ = std::nullopt, std::optional<bool> quiz_ = std::nullopt, std::optional<int> close_period_ = std::nullopt, std::optional<int> close_date_ = std::nullopt);
    static Poll read(Reader reader);
    std::string write();
};

class PollAnswerVoters
{
private:
    int __id = 0x3b6ddad2;

public:
    std::optional<bool> chosen;
    std::optional<bool> correct;
    std::string option;
    int voters;
    PollAnswerVoters(std::string option_, int voters_, std::optional<bool> chosen_ = std::nullopt, std::optional<bool> correct_ = std::nullopt);
    static PollAnswerVoters read(Reader reader);
    std::string write();
};

class PollResults
{
private:
    int __id = 0xbadcc1a3;

public:
    std::optional<bool> min;
    std::optional<std::vector<TLObject>> results;
    std::optional<int> total_voters;
    std::optional<std::vector<int>> recent_voters;
    std::optional<std::string> solution;
    std::optional<std::vector<TLObject>> solution_entities;
    PollResults(std::optional<bool> min_ = std::nullopt, std::optional<std::vector<TLObject>> results_ = std::nullopt, std::optional<int> total_voters_ = std::nullopt, std::optional<std::vector<int>> recent_voters_ = std::nullopt, std::optional<std::string> solution_ = std::nullopt, std::optional<std::vector<TLObject>> solution_entities_ = std::nullopt);
    static PollResults read(Reader reader);
    std::string write();
};

class ChatOnlines
{
private:
    int __id = 0xf041e250;

public:
    int onlines;
    ChatOnlines(int onlines_);
    static ChatOnlines read(Reader reader);
    std::string write();
};

class StatsURL
{
private:
    int __id = 0x47a971e0;

public:
    std::string url;
    StatsURL(std::string url_);
    static StatsURL read(Reader reader);
    std::string write();
};

class ChatAdminRights
{
private:
    int __id = 0x5fb224d5;

public:
    std::optional<bool> change_info;
    std::optional<bool> post_messages;
    std::optional<bool> edit_messages;
    std::optional<bool> delete_messages;
    std::optional<bool> ban_users;
    std::optional<bool> invite_users;
    std::optional<bool> pin_messages;
    std::optional<bool> add_admins;
    std::optional<bool> anonymous;
    std::optional<bool> manage_call;
    std::optional<bool> other;
    ChatAdminRights(std::optional<bool> change_info_ = std::nullopt, std::optional<bool> post_messages_ = std::nullopt, std::optional<bool> edit_messages_ = std::nullopt, std::optional<bool> delete_messages_ = std::nullopt, std::optional<bool> ban_users_ = std::nullopt, std::optional<bool> invite_users_ = std::nullopt, std::optional<bool> pin_messages_ = std::nullopt, std::optional<bool> add_admins_ = std::nullopt, std::optional<bool> anonymous_ = std::nullopt, std::optional<bool> manage_call_ = std::nullopt, std::optional<bool> other_ = std::nullopt);
    static ChatAdminRights read(Reader reader);
    std::string write();
};

class ChatBannedRights
{
private:
    int __id = 0x9f120418;

public:
    std::optional<bool> view_messages;
    std::optional<bool> send_messages;
    std::optional<bool> send_media;
    std::optional<bool> send_stickers;
    std::optional<bool> send_gifs;
    std::optional<bool> send_games;
    std::optional<bool> send_inline;
    std::optional<bool> embed_links;
    std::optional<bool> send_polls;
    std::optional<bool> change_info;
    std::optional<bool> invite_users;
    std::optional<bool> pin_messages;
    int until_date;
    ChatBannedRights(int until_date_, std::optional<bool> view_messages_ = std::nullopt, std::optional<bool> send_messages_ = std::nullopt, std::optional<bool> send_media_ = std::nullopt, std::optional<bool> send_stickers_ = std::nullopt, std::optional<bool> send_gifs_ = std::nullopt, std::optional<bool> send_games_ = std::nullopt, std::optional<bool> send_inline_ = std::nullopt, std::optional<bool> embed_links_ = std::nullopt, std::optional<bool> send_polls_ = std::nullopt, std::optional<bool> change_info_ = std::nullopt, std::optional<bool> invite_users_ = std::nullopt, std::optional<bool> pin_messages_ = std::nullopt);
    static ChatBannedRights read(Reader reader);
    std::string write();
};

class InputWallPaper
{
private:
    int __id = 0xe630b979;

public:
    long id;
    long access_hash;
    InputWallPaper(long id_, long access_hash_);
    static InputWallPaper read(Reader reader);
    std::string write();
};

class InputWallPaperSlug
{
private:
    int __id = 0x72091c80;

public:
    std::string slug;
    InputWallPaperSlug(std::string slug_);
    static InputWallPaperSlug read(Reader reader);
    std::string write();
};

class InputWallPaperNoFile
{
private:
    int __id = 0x967a462e;

public:
    long id;
    InputWallPaperNoFile(long id_);
    static InputWallPaperNoFile read(Reader reader);
    std::string write();
};

class CodeSettings
{
private:
    int __id = 0xdebebe83;

public:
    std::optional<bool> allow_flashcall;
    std::optional<bool> current_number;
    std::optional<bool> allow_app_hash;
    CodeSettings(std::optional<bool> allow_flashcall_ = std::nullopt, std::optional<bool> current_number_ = std::nullopt, std::optional<bool> allow_app_hash_ = std::nullopt);
    static CodeSettings read(Reader reader);
    std::string write();
};

class WallPaperSettings
{
private:
    int __id = 0x1dc1bca4;

public:
    std::optional<bool> blur;
    std::optional<bool> motion;
    std::optional<int> background_color;
    std::optional<int> second_background_color;
    std::optional<int> third_background_color;
    std::optional<int> fourth_background_color;
    std::optional<int> intensity;
    std::optional<int> rotation;
    WallPaperSettings(std::optional<bool> blur_ = std::nullopt, std::optional<bool> motion_ = std::nullopt, std::optional<int> background_color_ = std::nullopt, std::optional<int> second_background_color_ = std::nullopt, std::optional<int> third_background_color_ = std::nullopt, std::optional<int> fourth_background_color_ = std::nullopt, std::optional<int> intensity_ = std::nullopt, std::optional<int> rotation_ = std::nullopt);
    static WallPaperSettings read(Reader reader);
    std::string write();
};

class AutoDownloadSettings
{
private:
    int __id = 0xe04232f3;

public:
    std::optional<bool> disabled;
    std::optional<bool> video_preload_large;
    std::optional<bool> audio_preload_next;
    std::optional<bool> phonecalls_less_data;
    int photo_size_max;
    int video_size_max;
    int file_size_max;
    int video_upload_maxbitrate;
    AutoDownloadSettings(int photo_size_max_, int video_size_max_, int file_size_max_, int video_upload_maxbitrate_, std::optional<bool> disabled_ = std::nullopt, std::optional<bool> video_preload_large_ = std::nullopt, std::optional<bool> audio_preload_next_ = std::nullopt, std::optional<bool> phonecalls_less_data_ = std::nullopt);
    static AutoDownloadSettings read(Reader reader);
    std::string write();
};

class EmojiKeyword
{
private:
    int __id = 0xd5b3b9f9;

public:
    std::string keyword;
    std::vector<std::string> emoticons;
    EmojiKeyword(std::string keyword_, std::vector<std::string> emoticons_);
    static EmojiKeyword read(Reader reader);
    std::string write();
};

class EmojiKeywordDeleted
{
private:
    int __id = 0x236df622;

public:
    std::string keyword;
    std::vector<std::string> emoticons;
    EmojiKeywordDeleted(std::string keyword_, std::vector<std::string> emoticons_);
    static EmojiKeywordDeleted read(Reader reader);
    std::string write();
};

class EmojiKeywordsDifference
{
private:
    int __id = 0x5cc761bd;

public:
    std::string lang_code;
    int from_version;
    int version;
    std::vector<TLObject> keywords;
    EmojiKeywordsDifference(std::string lang_code_, int from_version_, int version_, std::vector<TLObject> keywords_);
    static EmojiKeywordsDifference read(Reader reader);
    std::string write();
};

class EmojiURL
{
private:
    int __id = 0xa575739d;

public:
    std::string url;
    EmojiURL(std::string url_);
    static EmojiURL read(Reader reader);
    std::string write();
};

class EmojiLanguage
{
private:
    int __id = 0xb3fb5361;

public:
    std::string lang_code;
    EmojiLanguage(std::string lang_code_);
    static EmojiLanguage read(Reader reader);
    std::string write();
};

class Folder
{
private:
    int __id = 0xff544e65;

public:
    std::optional<bool> autofill_new_broadcasts;
    std::optional<bool> autofill_public_groups;
    std::optional<bool> autofill_new_correspondents;
    int id;
    std::string title;
    std::optional<TLObject> photo;
    Folder(int id_, std::string title_, std::optional<bool> autofill_new_broadcasts_ = std::nullopt, std::optional<bool> autofill_public_groups_ = std::nullopt, std::optional<bool> autofill_new_correspondents_ = std::nullopt, std::optional<TLObject> photo_ = std::nullopt);
    static Folder read(Reader reader);
    std::string write();
};

class InputFolderPeer
{
private:
    int __id = 0xfbd2c296;

public:
    TLObject peer;
    int folder_id;
    InputFolderPeer(TLObject peer_, int folder_id_);
    static InputFolderPeer read(Reader reader);
    std::string write();
};

class FolderPeer
{
private:
    int __id = 0xe9baa668;

public:
    TLObject peer;
    int folder_id;
    FolderPeer(TLObject peer_, int folder_id_);
    static FolderPeer read(Reader reader);
    std::string write();
};

class UrlAuthResultRequest
{
private:
    int __id = 0x92d33a0e;

public:
    std::optional<bool> request_write_access;
    TLObject bot;
    std::string domain;
    UrlAuthResultRequest(TLObject bot_, std::string domain_, std::optional<bool> request_write_access_ = std::nullopt);
    static UrlAuthResultRequest read(Reader reader);
    std::string write();
};

class UrlAuthResultAccepted
{
private:
    int __id = 0x8f8c0e4e;

public:
    std::string url;
    UrlAuthResultAccepted(std::string url_);
    static UrlAuthResultAccepted read(Reader reader);
    std::string write();
};

class UrlAuthResultDefault
{
private:
    int __id = 0xa9d6db1f;

public:
    UrlAuthResultDefault() = default;
    static UrlAuthResultDefault read(Reader reader);
    std::string write();
};

class ChannelLocationEmpty
{
private:
    int __id = 0xbfb5ad8b;

public:
    ChannelLocationEmpty() = default;
    static ChannelLocationEmpty read(Reader reader);
    std::string write();
};

class ChannelLocation
{
private:
    int __id = 0x209b82db;

public:
    TLObject geo_point;
    std::string address;
    ChannelLocation(TLObject geo_point_, std::string address_);
    static ChannelLocation read(Reader reader);
    std::string write();
};

class PeerLocated
{
private:
    int __id = 0xca461b5d;

public:
    TLObject peer;
    int expires;
    int distance;
    PeerLocated(TLObject peer_, int expires_, int distance_);
    static PeerLocated read(Reader reader);
    std::string write();
};

class PeerSelfLocated
{
private:
    int __id = 0xf8ec284b;

public:
    int expires;
    PeerSelfLocated(int expires_);
    static PeerSelfLocated read(Reader reader);
    std::string write();
};

class RestrictionReason
{
private:
    int __id = 0xd072acb4;

public:
    std::string platform;
    std::string reason;
    std::string text;
    RestrictionReason(std::string platform_, std::string reason_, std::string text_);
    static RestrictionReason read(Reader reader);
    std::string write();
};

class InputTheme
{
private:
    int __id = 0x3c5693e9;

public:
    long id;
    long access_hash;
    InputTheme(long id_, long access_hash_);
    static InputTheme read(Reader reader);
    std::string write();
};

class InputThemeSlug
{
private:
    int __id = 0xf5890df1;

public:
    std::string slug;
    InputThemeSlug(std::string slug_);
    static InputThemeSlug read(Reader reader);
    std::string write();
};

class Theme
{
private:
    int __id = 0x28f1114;

public:
    std::optional<bool> creator;
    std::optional<bool> default;
    long id;
    long access_hash;
    std::string slug;
    std::string title;
    std::optional<TLObject> document;
    std::optional<TLObject> settings;
    int installs_count;
    Theme(long id_, long access_hash_, std::string slug_, std::string title_, int installs_count_, std::optional<bool> creator_ = std::nullopt, std::optional<bool> default_ = std::nullopt, std::optional<TLObject> document_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static Theme read(Reader reader);
    std::string write();
};

class BaseThemeClassic
{
private:
    int __id = 0xc3a12462;

public:
    BaseThemeClassic() = default;
    static BaseThemeClassic read(Reader reader);
    std::string write();
};

class BaseThemeDay
{
private:
    int __id = 0xfbd81688;

public:
    BaseThemeDay() = default;
    static BaseThemeDay read(Reader reader);
    std::string write();
};

class BaseThemeNight
{
private:
    int __id = 0xb7b31ea8;

public:
    BaseThemeNight() = default;
    static BaseThemeNight read(Reader reader);
    std::string write();
};

class BaseThemeTinted
{
private:
    int __id = 0x6d5f77ee;

public:
    BaseThemeTinted() = default;
    static BaseThemeTinted read(Reader reader);
    std::string write();
};

class BaseThemeArctic
{
private:
    int __id = 0x5b11125a;

public:
    BaseThemeArctic() = default;
    static BaseThemeArctic read(Reader reader);
    std::string write();
};

class InputThemeSettings
{
private:
    int __id = 0xbd507cd1;

public:
    TLObject base_theme;
    int accent_color;
    std::optional<int> message_top_color;
    std::optional<int> message_bottom_color;
    std::optional<TLObject> wallpaper;
    std::optional<TLObject> wallpaper_settings;
    InputThemeSettings(TLObject base_theme_, int accent_color_, std::optional<int> message_top_color_ = std::nullopt, std::optional<int> message_bottom_color_ = std::nullopt, std::optional<TLObject> wallpaper_ = std::nullopt, std::optional<TLObject> wallpaper_settings_ = std::nullopt);
    static InputThemeSettings read(Reader reader);
    std::string write();
};

class ThemeSettings
{
private:
    int __id = 0x9c14984a;

public:
    TLObject base_theme;
    int accent_color;
    std::optional<int> message_top_color;
    std::optional<int> message_bottom_color;
    std::optional<TLObject> wallpaper;
    ThemeSettings(TLObject base_theme_, int accent_color_, std::optional<int> message_top_color_ = std::nullopt, std::optional<int> message_bottom_color_ = std::nullopt, std::optional<TLObject> wallpaper_ = std::nullopt);
    static ThemeSettings read(Reader reader);
    std::string write();
};

class WebPageAttributeTheme
{
private:
    int __id = 0x54b56617;

public:
    std::optional<std::vector<TLObject>> documents;
    std::optional<TLObject> settings;
    WebPageAttributeTheme(std::optional<std::vector<TLObject>> documents_ = std::nullopt, std::optional<TLObject> settings_ = std::nullopt);
    static WebPageAttributeTheme read(Reader reader);
    std::string write();
};

class MessageUserVote
{
private:
    int __id = 0xa28e5559;

public:
    int user_id;
    std::string option;
    int date;
    MessageUserVote(int user_id_, std::string option_, int date_);
    static MessageUserVote read(Reader reader);
    std::string write();
};

class MessageUserVoteInputOption
{
private:
    int __id = 0x36377430;

public:
    int user_id;
    int date;
    MessageUserVoteInputOption(int user_id_, int date_);
    static MessageUserVoteInputOption read(Reader reader);
    std::string write();
};

class MessageUserVoteMultiple
{
private:
    int __id = 0xe8fe0de;

public:
    int user_id;
    std::vector<std::string> options;
    int date;
    MessageUserVoteMultiple(int user_id_, std::vector<std::string> options_, int date_);
    static MessageUserVoteMultiple read(Reader reader);
    std::string write();
};

class BankCardOpenUrl
{
private:
    int __id = 0xf568028a;

public:
    std::string url;
    std::string name;
    BankCardOpenUrl(std::string url_, std::string name_);
    static BankCardOpenUrl read(Reader reader);
    std::string write();
};

class DialogFilter
{
private:
    int __id = 0x7438f7e8;

public:
    std::optional<bool> contacts;
    std::optional<bool> non_contacts;
    std::optional<bool> groups;
    std::optional<bool> broadcasts;
    std::optional<bool> bots;
    std::optional<bool> exclude_muted;
    std::optional<bool> exclude_read;
    std::optional<bool> exclude_archived;
    int id;
    std::string title;
    std::optional<std::string> emoticon;
    std::vector<TLObject> pinned_peers;
    std::vector<TLObject> include_peers;
    std::vector<TLObject> exclude_peers;
    DialogFilter(int id_, std::string title_, std::vector<TLObject> pinned_peers_, std::vector<TLObject> include_peers_, std::vector<TLObject> exclude_peers_, std::optional<bool> contacts_ = std::nullopt, std::optional<bool> non_contacts_ = std::nullopt, std::optional<bool> groups_ = std::nullopt, std::optional<bool> broadcasts_ = std::nullopt, std::optional<bool> bots_ = std::nullopt, std::optional<bool> exclude_muted_ = std::nullopt, std::optional<bool> exclude_read_ = std::nullopt, std::optional<bool> exclude_archived_ = std::nullopt, std::optional<std::string> emoticon_ = std::nullopt);
    static DialogFilter read(Reader reader);
    std::string write();
};

class DialogFilterSuggested
{
private:
    int __id = 0x77744d4a;

public:
    TLObject filter;
    std::string description;
    DialogFilterSuggested(TLObject filter_, std::string description_);
    static DialogFilterSuggested read(Reader reader);
    std::string write();
};

class StatsDateRangeDays
{
private:
    int __id = 0xb637edaf;

public:
    int min_date;
    int max_date;
    StatsDateRangeDays(int min_date_, int max_date_);
    static StatsDateRangeDays read(Reader reader);
    std::string write();
};

class StatsAbsValueAndPrev
{
private:
    int __id = 0xcb43acde;

public:
    double current;
    double previous;
    StatsAbsValueAndPrev(double current_, double previous_);
    static StatsAbsValueAndPrev read(Reader reader);
    std::string write();
};

class StatsPercentValue
{
private:
    int __id = 0xcbce2fe0;

public:
    double part;
    double total;
    StatsPercentValue(double part_, double total_);
    static StatsPercentValue read(Reader reader);
    std::string write();
};

class StatsGraphAsync
{
private:
    int __id = 0x4a27eb2d;

public:
    std::string token;
    StatsGraphAsync(std::string token_);
    static StatsGraphAsync read(Reader reader);
    std::string write();
};

class StatsGraphError
{
private:
    int __id = 0xbedc9822;

public:
    std::string error;
    StatsGraphError(std::string error_);
    static StatsGraphError read(Reader reader);
    std::string write();
};

class StatsGraph
{
private:
    int __id = 0x8ea464b6;

public:
    TLObject json;
    std::optional<std::string> zoom_token;
    StatsGraph(TLObject json_, std::optional<std::string> zoom_token_ = std::nullopt);
    static StatsGraph read(Reader reader);
    std::string write();
};

class MessageInteractionCounters
{
private:
    int __id = 0xad4fc9bd;

public:
    int msg_id;
    int views;
    int forwards;
    MessageInteractionCounters(int msg_id_, int views_, int forwards_);
    static MessageInteractionCounters read(Reader reader);
    std::string write();
};

class VideoSize
{
private:
    int __id = 0xde33b094;

public:
    std::string type;
    int w;
    int h;
    int size;
    std::optional<double> video_start_ts;
    VideoSize(std::string type_, int w_, int h_, int size_, std::optional<double> video_start_ts_ = std::nullopt);
    static VideoSize read(Reader reader);
    std::string write();
};

class StatsGroupTopPoster
{
private:
    int __id = 0x18f3d0f7;

public:
    int user_id;
    int messages;
    int avg_chars;
    StatsGroupTopPoster(int user_id_, int messages_, int avg_chars_);
    static StatsGroupTopPoster read(Reader reader);
    std::string write();
};

class StatsGroupTopAdmin
{
private:
    int __id = 0x6014f412;

public:
    int user_id;
    int deleted;
    int kicked;
    int banned;
    StatsGroupTopAdmin(int user_id_, int deleted_, int kicked_, int banned_);
    static StatsGroupTopAdmin read(Reader reader);
    std::string write();
};

class StatsGroupTopInviter
{
private:
    int __id = 0x31962a4c;

public:
    int user_id;
    int invitations;
    StatsGroupTopInviter(int user_id_, int invitations_);
    static StatsGroupTopInviter read(Reader reader);
    std::string write();
};

class GlobalPrivacySettings
{
private:
    int __id = 0xbea2f424;

public:
    std::optional<bool> archive_and_mute_new_noncontact_peers;
    GlobalPrivacySettings(std::optional<bool> archive_and_mute_new_noncontact_peers_ = std::nullopt);
    static GlobalPrivacySettings read(Reader reader);
    std::string write();
};

class MessageViews
{
private:
    int __id = 0x455b853d;

public:
    std::optional<int> views;
    std::optional<int> forwards;
    std::optional<TLObject> replies;
    MessageViews(std::optional<int> views_ = std::nullopt, std::optional<int> forwards_ = std::nullopt, std::optional<TLObject> replies_ = std::nullopt);
    static MessageViews read(Reader reader);
    std::string write();
};

class MessageReplyHeader
{
private:
    int __id = 0xa6d57763;

public:
    int reply_to_msg_id;
    std::optional<TLObject> reply_to_peer_id;
    std::optional<int> reply_to_top_id;
    MessageReplyHeader(int reply_to_msg_id_, std::optional<TLObject> reply_to_peer_id_ = std::nullopt, std::optional<int> reply_to_top_id_ = std::nullopt);
    static MessageReplyHeader read(Reader reader);
    std::string write();
};

class MessageReplies
{
private:
    int __id = 0x4128faac;

public:
    std::optional<bool> comments;
    int replies;
    int replies_pts;
    std::optional<std::vector<TLObject>> recent_repliers;
    std::optional<int> channel_id;
    std::optional<int> max_id;
    std::optional<int> read_max_id;
    MessageReplies(int replies_, int replies_pts_, std::optional<bool> comments_ = std::nullopt, std::optional<std::vector<TLObject>> recent_repliers_ = std::nullopt, std::optional<int> channel_id_ = std::nullopt, std::optional<int> max_id_ = std::nullopt, std::optional<int> read_max_id_ = std::nullopt);
    static MessageReplies read(Reader reader);
    std::string write();
};

class PeerBlocked
{
private:
    int __id = 0xe8fd8014;

public:
    TLObject peer_id;
    int date;
    PeerBlocked(TLObject peer_id_, int date_);
    static PeerBlocked read(Reader reader);
    std::string write();
};

class GroupCallDiscarded
{
private:
    int __id = 0x7780bcb4;

public:
    long id;
    long access_hash;
    int duration;
    GroupCallDiscarded(long id_, long access_hash_, int duration_);
    static GroupCallDiscarded read(Reader reader);
    std::string write();
};

class GroupCall
{
private:
    int __id = 0x653dbaad;

public:
    std::optional<bool> join_muted;
    std::optional<bool> can_change_join_muted;
    std::optional<bool> join_date_asc;
    std::optional<bool> schedule_start_subscribed;
    std::optional<bool> can_start_video;
    long id;
    long access_hash;
    int participants_count;
    std::optional<std::string> title;
    std::optional<int> stream_dc_id;
    std::optional<int> record_start_date;
    std::optional<int> schedule_date;
    int version;
    GroupCall(long id_, long access_hash_, int participants_count_, int version_, std::optional<bool> join_muted_ = std::nullopt, std::optional<bool> can_change_join_muted_ = std::nullopt, std::optional<bool> join_date_asc_ = std::nullopt, std::optional<bool> schedule_start_subscribed_ = std::nullopt, std::optional<bool> can_start_video_ = std::nullopt, std::optional<std::string> title_ = std::nullopt, std::optional<int> stream_dc_id_ = std::nullopt, std::optional<int> record_start_date_ = std::nullopt, std::optional<int> schedule_date_ = std::nullopt);
    static GroupCall read(Reader reader);
    std::string write();
};

class InputGroupCall
{
private:
    int __id = 0xd8aa840f;

public:
    long id;
    long access_hash;
    InputGroupCall(long id_, long access_hash_);
    static InputGroupCall read(Reader reader);
    std::string write();
};

class GroupCallParticipant
{
private:
    int __id = 0xeba636fe;

public:
    std::optional<bool> muted;
    std::optional<bool> left;
    std::optional<bool> can_self_unmute;
    std::optional<bool> just_joined;
    std::optional<bool> versioned;
    std::optional<bool> min;
    std::optional<bool> muted_by_you;
    std::optional<bool> volume_by_admin;
    std::optional<bool> self;
    std::optional<bool> video_joined;
    TLObject peer;
    int date;
    std::optional<int> active_date;
    int source;
    std::optional<int> volume;
    std::optional<std::string> about;
    std::optional<long> raise_hand_rating;
    std::optional<TLObject> video;
    std::optional<TLObject> presentation;
    GroupCallParticipant(TLObject peer_, int date_, int source_, std::optional<bool> muted_ = std::nullopt, std::optional<bool> left_ = std::nullopt, std::optional<bool> can_self_unmute_ = std::nullopt, std::optional<bool> just_joined_ = std::nullopt, std::optional<bool> versioned_ = std::nullopt, std::optional<bool> min_ = std::nullopt, std::optional<bool> muted_by_you_ = std::nullopt, std::optional<bool> volume_by_admin_ = std::nullopt, std::optional<bool> self_ = std::nullopt, std::optional<bool> video_joined_ = std::nullopt, std::optional<int> active_date_ = std::nullopt, std::optional<int> volume_ = std::nullopt, std::optional<std::string> about_ = std::nullopt, std::optional<long> raise_hand_rating_ = std::nullopt, std::optional<TLObject> video_ = std::nullopt, std::optional<TLObject> presentation_ = std::nullopt);
    static GroupCallParticipant read(Reader reader);
    std::string write();
};

class InlineQueryPeerTypeSameBotPM
{
private:
    int __id = 0x3081ed9d;

public:
    InlineQueryPeerTypeSameBotPM() = default;
    static InlineQueryPeerTypeSameBotPM read(Reader reader);
    std::string write();
};

class InlineQueryPeerTypePM
{
private:
    int __id = 0x833c0fac;

public:
    InlineQueryPeerTypePM() = default;
    static InlineQueryPeerTypePM read(Reader reader);
    std::string write();
};

class InlineQueryPeerTypeChat
{
private:
    int __id = 0xd766c50a;

public:
    InlineQueryPeerTypeChat() = default;
    static InlineQueryPeerTypeChat read(Reader reader);
    std::string write();
};

class InlineQueryPeerTypeMegagroup
{
private:
    int __id = 0x5ec4be43;

public:
    InlineQueryPeerTypeMegagroup() = default;
    static InlineQueryPeerTypeMegagroup read(Reader reader);
    std::string write();
};

class InlineQueryPeerTypeBroadcast
{
private:
    int __id = 0x6334ee9a;

public:
    InlineQueryPeerTypeBroadcast() = default;
    static InlineQueryPeerTypeBroadcast read(Reader reader);
    std::string write();
};

class ChatInviteImporter
{
private:
    int __id = 0x1e3e6680;

public:
    int user_id;
    int date;
    ChatInviteImporter(int user_id_, int date_);
    static ChatInviteImporter read(Reader reader);
    std::string write();
};

class ChatAdminWithInvites
{
private:
    int __id = 0xdfd2330f;

public:
    int admin_id;
    int invites_count;
    int revoked_invites_count;
    ChatAdminWithInvites(int admin_id_, int invites_count_, int revoked_invites_count_);
    static ChatAdminWithInvites read(Reader reader);
    std::string write();
};

class GroupCallParticipantVideoSourceGroup
{
private:
    int __id = 0xdcb118b7;

public:
    std::string semantics;
    std::vector<int> sources;
    GroupCallParticipantVideoSourceGroup(std::string semantics_, std::vector<int> sources_);
    static GroupCallParticipantVideoSourceGroup read(Reader reader);
    std::string write();
};

class GroupCallParticipantVideo
{
private:
    int __id = 0x78e41663;

public:
    std::optional<bool> paused;
    std::string endpoint;
    std::vector<TLObject> source_groups;
    GroupCallParticipantVideo(std::string endpoint_, std::vector<TLObject> source_groups_, std::optional<bool> paused_ = std::nullopt);
    static GroupCallParticipantVideo read(Reader reader);
    std::string write();
};

class BotCommandScopeDefault
{
private:
    int __id = 0x2f6cb2ab;

public:
    BotCommandScopeDefault() = default;
    static BotCommandScopeDefault read(Reader reader);
    std::string write();
};

class BotCommandScopeUsers
{
private:
    int __id = 0x3c4f04d8;

public:
    BotCommandScopeUsers() = default;
    static BotCommandScopeUsers read(Reader reader);
    std::string write();
};

class BotCommandScopeChats
{
private:
    int __id = 0x6fe1a881;

public:
    BotCommandScopeChats() = default;
    static BotCommandScopeChats read(Reader reader);
    std::string write();
};

class BotCommandScopeChatAdmins
{
private:
    int __id = 0xb9aa606a;

public:
    BotCommandScopeChatAdmins() = default;
    static BotCommandScopeChatAdmins read(Reader reader);
    std::string write();
};

class BotCommandScopePeer
{
private:
    int __id = 0xdb9d897d;

public:
    TLObject peer;
    BotCommandScopePeer(TLObject peer_);
    static BotCommandScopePeer read(Reader reader);
    std::string write();
};

class BotCommandScopePeerAdmins
{
private:
    int __id = 0x3fd863d1;

public:
    TLObject peer;
    BotCommandScopePeerAdmins(TLObject peer_);
    static BotCommandScopePeerAdmins read(Reader reader);
    std::string write();
};

class BotCommandScopePeerUser
{
private:
    int __id = 0xa1321f3;

public:
    TLObject peer;
    TLObject user_id;
    BotCommandScopePeerUser(TLObject peer_, TLObject user_id_);
    static BotCommandScopePeerUser read(Reader reader);
    std::string write();
};
