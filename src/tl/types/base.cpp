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

#include "tl/types/base.h"

ResPQ::ResPQ(uint128_t nonce_, uint128_t server_nonce_, std::string pq_, std::vector<long> server_public_key_fingerprints_) {}

ResPQ ResPQ::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    std::string pq_ = String::read(reader);
    std::vector<long> server_public_key_fingerprints_ = std::get<std::vector<long>>(TLObject::read(reader));
    return ResPQ(nonce_, server_nonce_, pq_, server_public_key_fingerprints_);
}

std::string ResPQ::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += String::write(pq);
    buffer += Vector<long>::write(server_public_key_fingerprints);
    return buffer;
}

PQInnerDataDc::PQInnerDataDc(std::string pq_, std::string p_, std::string q_, uint128_t nonce_, uint128_t server_nonce_, uint256_t new_nonce_, int dc_) {}

PQInnerDataDc PQInnerDataDc::read(Reader reader)
{
    std::string pq_ = String::read(reader);
    std::string p_ = String::read(reader);
    std::string q_ = String::read(reader);
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint256_t new_nonce_ = Int256::read(reader);
    int dc_ = Int::read(reader);
    return PQInnerDataDc(pq_, p_, q_, nonce_, server_nonce_, new_nonce_, dc_);
}

std::string PQInnerDataDc::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(pq);
    buffer += String::write(p);
    buffer += String::write(q);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int256::write(new_nonce);
    buffer += Int::write(dc);
    return buffer;
}

PQInnerDataTempDc::PQInnerDataTempDc(std::string pq_, std::string p_, std::string q_, uint128_t nonce_, uint128_t server_nonce_, uint256_t new_nonce_, int dc_, int expires_in_) {}

PQInnerDataTempDc PQInnerDataTempDc::read(Reader reader)
{
    std::string pq_ = String::read(reader);
    std::string p_ = String::read(reader);
    std::string q_ = String::read(reader);
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint256_t new_nonce_ = Int256::read(reader);
    int dc_ = Int::read(reader);
    int expires_in_ = Int::read(reader);
    return PQInnerDataTempDc(pq_, p_, q_, nonce_, server_nonce_, new_nonce_, dc_, expires_in_);
}

std::string PQInnerDataTempDc::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(pq);
    buffer += String::write(p);
    buffer += String::write(q);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int256::write(new_nonce);
    buffer += Int::write(dc);
    buffer += Int::write(expires_in);
    return buffer;
}

ServerDHParamsFail::ServerDHParamsFail(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash_) {}

ServerDHParamsFail ServerDHParamsFail::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint128_t new_nonce_hash_ = Int128::read(reader);
    return ServerDHParamsFail(nonce_, server_nonce_, new_nonce_hash_);
}

std::string ServerDHParamsFail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int128::write(new_nonce_hash);
    return buffer;
}

ServerDHParamsOk::ServerDHParamsOk(uint128_t nonce_, uint128_t server_nonce_, std::string encrypted_answer_) {}

ServerDHParamsOk ServerDHParamsOk::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    std::string encrypted_answer_ = String::read(reader);
    return ServerDHParamsOk(nonce_, server_nonce_, encrypted_answer_);
}

std::string ServerDHParamsOk::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += String::write(encrypted_answer);
    return buffer;
}

ServerDHInnerData::ServerDHInnerData(uint128_t nonce_, uint128_t server_nonce_, int g_, std::string dh_prime_, std::string g_a_, int server_time_) {}

ServerDHInnerData ServerDHInnerData::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    int g_ = Int::read(reader);
    std::string dh_prime_ = String::read(reader);
    std::string g_a_ = String::read(reader);
    int server_time_ = Int::read(reader);
    return ServerDHInnerData(nonce_, server_nonce_, g_, dh_prime_, g_a_, server_time_);
}

std::string ServerDHInnerData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int::write(g);
    buffer += String::write(dh_prime);
    buffer += String::write(g_a);
    buffer += Int::write(server_time);
    return buffer;
}

ClientDHInnerData::ClientDHInnerData(uint128_t nonce_, uint128_t server_nonce_, long retry_id_, std::string g_b_) {}

ClientDHInnerData ClientDHInnerData::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    long retry_id_ = Long::read(reader);
    std::string g_b_ = String::read(reader);
    return ClientDHInnerData(nonce_, server_nonce_, retry_id_, g_b_);
}

std::string ClientDHInnerData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Long::write(retry_id);
    buffer += String::write(g_b);
    return buffer;
}

DhGenOk::DhGenOk(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash1_) {}

DhGenOk DhGenOk::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint128_t new_nonce_hash1_ = Int128::read(reader);
    return DhGenOk(nonce_, server_nonce_, new_nonce_hash1_);
}

std::string DhGenOk::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int128::write(new_nonce_hash1);
    return buffer;
}

DhGenRetry::DhGenRetry(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash2_) {}

DhGenRetry DhGenRetry::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint128_t new_nonce_hash2_ = Int128::read(reader);
    return DhGenRetry(nonce_, server_nonce_, new_nonce_hash2_);
}

std::string DhGenRetry::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int128::write(new_nonce_hash2);
    return buffer;
}

DhGenFail::DhGenFail(uint128_t nonce_, uint128_t server_nonce_, uint128_t new_nonce_hash3_) {}

DhGenFail DhGenFail::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    uint128_t new_nonce_hash3_ = Int128::read(reader);
    return DhGenFail(nonce_, server_nonce_, new_nonce_hash3_);
}

std::string DhGenFail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += Int128::write(new_nonce_hash3);
    return buffer;
}

RpcError::RpcError(int error_code_, std::string error_message_) {}

RpcError RpcError::read(Reader reader)
{
    int error_code_ = Int::read(reader);
    std::string error_message_ = String::read(reader);
    return RpcError(error_code_, error_message_);
}

std::string RpcError::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(error_code);
    buffer += String::write(error_message);
    return buffer;
}
RpcAnswerUnknown RpcAnswerUnknown::read(Reader reader)
{
    return RpcAnswerUnknown();
}

std::string RpcAnswerUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
RpcAnswerDroppedRunning RpcAnswerDroppedRunning::read(Reader reader)
{
    return RpcAnswerDroppedRunning();
}

std::string RpcAnswerDroppedRunning::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

RpcAnswerDropped::RpcAnswerDropped(long msg_id_, int seq_no_, int bytes_) {}

RpcAnswerDropped RpcAnswerDropped::read(Reader reader)
{
    long msg_id_ = Long::read(reader);
    int seq_no_ = Int::read(reader);
    int bytes_ = Int::read(reader);
    return RpcAnswerDropped(msg_id_, seq_no_, bytes_);
}

std::string RpcAnswerDropped::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(msg_id);
    buffer += Int::write(seq_no);
    buffer += Int::write(bytes);
    return buffer;
}

FutureSalt::FutureSalt(int valid_since_, int valid_until_, long salt_) {}

FutureSalt FutureSalt::read(Reader reader)
{
    int valid_since_ = Int::read(reader);
    int valid_until_ = Int::read(reader);
    long salt_ = Long::read(reader);
    return FutureSalt(valid_since_, valid_until_, salt_);
}

std::string FutureSalt::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(valid_since);
    buffer += Int::write(valid_until);
    buffer += Long::write(salt);
    return buffer;
}

FutureSalts::FutureSalts(long req_msg_id_, int now_, std::vector<TLObject> salts_) {}

FutureSalts FutureSalts::read(Reader reader)
{
    long req_msg_id_ = Long::read(reader);
    int now_ = Int::read(reader);
    std::vector<TLObject> salts_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return FutureSalts(req_msg_id_, now_, salts_);
}

std::string FutureSalts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(req_msg_id);
    buffer += Int::write(now);
    buffer += Vector<TLObject>::write(salts);
    return buffer;
}

Pong::Pong(long msg_id_, long ping_id_) {}

Pong Pong::read(Reader reader)
{
    long msg_id_ = Long::read(reader);
    long ping_id_ = Long::read(reader);
    return Pong(msg_id_, ping_id_);
}

std::string Pong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(msg_id);
    buffer += Long::write(ping_id);
    return buffer;
}

DestroySessionOk::DestroySessionOk(long session_id_) {}

DestroySessionOk DestroySessionOk::read(Reader reader)
{
    long session_id_ = Long::read(reader);
    return DestroySessionOk(session_id_);
}

std::string DestroySessionOk::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(session_id);
    return buffer;
}

DestroySessionNone::DestroySessionNone(long session_id_) {}

DestroySessionNone DestroySessionNone::read(Reader reader)
{
    long session_id_ = Long::read(reader);
    return DestroySessionNone(session_id_);
}

std::string DestroySessionNone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(session_id);
    return buffer;
}

NewSessionCreated::NewSessionCreated(long first_msg_id_, long unique_id_, long server_salt_) {}

NewSessionCreated NewSessionCreated::read(Reader reader)
{
    long first_msg_id_ = Long::read(reader);
    long unique_id_ = Long::read(reader);
    long server_salt_ = Long::read(reader);
    return NewSessionCreated(first_msg_id_, unique_id_, server_salt_);
}

std::string NewSessionCreated::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(first_msg_id);
    buffer += Long::write(unique_id);
    buffer += Long::write(server_salt);
    return buffer;
}

GzipPacked::GzipPacked(std::string packed_data_) {}

GzipPacked GzipPacked::read(Reader reader)
{
    std::string packed_data_ = String::read(reader);
    return GzipPacked(packed_data_);
}

std::string GzipPacked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(packed_data);
    return buffer;
}

MsgsAck::MsgsAck(std::vector<long> msg_ids_) {}

MsgsAck MsgsAck::read(Reader reader)
{
    std::vector<long> msg_ids_ = std::get<std::vector<long>>(TLObject::read(reader));
    return MsgsAck(msg_ids_);
}

std::string MsgsAck::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(msg_ids);
    return buffer;
}

BadMsgNotification::BadMsgNotification(long bad_msg_id_, int bad_msg_seqno_, int error_code_) {}

BadMsgNotification BadMsgNotification::read(Reader reader)
{
    long bad_msg_id_ = Long::read(reader);
    int bad_msg_seqno_ = Int::read(reader);
    int error_code_ = Int::read(reader);
    return BadMsgNotification(bad_msg_id_, bad_msg_seqno_, error_code_);
}

std::string BadMsgNotification::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(bad_msg_id);
    buffer += Int::write(bad_msg_seqno);
    buffer += Int::write(error_code);
    return buffer;
}

BadServerSalt::BadServerSalt(long bad_msg_id_, int bad_msg_seqno_, int error_code_, long new_server_salt_) {}

BadServerSalt BadServerSalt::read(Reader reader)
{
    long bad_msg_id_ = Long::read(reader);
    int bad_msg_seqno_ = Int::read(reader);
    int error_code_ = Int::read(reader);
    long new_server_salt_ = Long::read(reader);
    return BadServerSalt(bad_msg_id_, bad_msg_seqno_, error_code_, new_server_salt_);
}

std::string BadServerSalt::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(bad_msg_id);
    buffer += Int::write(bad_msg_seqno);
    buffer += Int::write(error_code);
    buffer += Long::write(new_server_salt);
    return buffer;
}

MsgResendReq::MsgResendReq(std::vector<long> msg_ids_) {}

MsgResendReq MsgResendReq::read(Reader reader)
{
    std::vector<long> msg_ids_ = std::get<std::vector<long>>(TLObject::read(reader));
    return MsgResendReq(msg_ids_);
}

std::string MsgResendReq::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(msg_ids);
    return buffer;
}

MsgsStateReq::MsgsStateReq(std::vector<long> msg_ids_) {}

MsgsStateReq MsgsStateReq::read(Reader reader)
{
    std::vector<long> msg_ids_ = std::get<std::vector<long>>(TLObject::read(reader));
    return MsgsStateReq(msg_ids_);
}

std::string MsgsStateReq::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(msg_ids);
    return buffer;
}

MsgsStateInfo::MsgsStateInfo(long req_msg_id_, std::string info_) {}

MsgsStateInfo MsgsStateInfo::read(Reader reader)
{
    long req_msg_id_ = Long::read(reader);
    std::string info_ = String::read(reader);
    return MsgsStateInfo(req_msg_id_, info_);
}

std::string MsgsStateInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(req_msg_id);
    buffer += String::write(info);
    return buffer;
}

MsgsAllInfo::MsgsAllInfo(std::vector<long> msg_ids_, std::string info_) {}

MsgsAllInfo MsgsAllInfo::read(Reader reader)
{
    std::vector<long> msg_ids_ = std::get<std::vector<long>>(TLObject::read(reader));
    std::string info_ = String::read(reader);
    return MsgsAllInfo(msg_ids_, info_);
}

std::string MsgsAllInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(msg_ids);
    buffer += String::write(info);
    return buffer;
}

MsgDetailedInfo::MsgDetailedInfo(long msg_id_, long answer_msg_id_, int bytes_, int status_) {}

MsgDetailedInfo MsgDetailedInfo::read(Reader reader)
{
    long msg_id_ = Long::read(reader);
    long answer_msg_id_ = Long::read(reader);
    int bytes_ = Int::read(reader);
    int status_ = Int::read(reader);
    return MsgDetailedInfo(msg_id_, answer_msg_id_, bytes_, status_);
}

std::string MsgDetailedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(msg_id);
    buffer += Long::write(answer_msg_id);
    buffer += Int::write(bytes);
    buffer += Int::write(status);
    return buffer;
}

MsgNewDetailedInfo::MsgNewDetailedInfo(long answer_msg_id_, int bytes_, int status_) {}

MsgNewDetailedInfo MsgNewDetailedInfo::read(Reader reader)
{
    long answer_msg_id_ = Long::read(reader);
    int bytes_ = Int::read(reader);
    int status_ = Int::read(reader);
    return MsgNewDetailedInfo(answer_msg_id_, bytes_, status_);
}

std::string MsgNewDetailedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(answer_msg_id);
    buffer += Int::write(bytes);
    buffer += Int::write(status);
    return buffer;
}
DestroyAuthKeyOk DestroyAuthKeyOk::read(Reader reader)
{
    return DestroyAuthKeyOk();
}

std::string DestroyAuthKeyOk::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
DestroyAuthKeyNone DestroyAuthKeyNone::read(Reader reader)
{
    return DestroyAuthKeyNone();
}

std::string DestroyAuthKeyNone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
DestroyAuthKeyFail DestroyAuthKeyFail::read(Reader reader)
{
    return DestroyAuthKeyFail();
}

std::string DestroyAuthKeyFail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPeerEmpty InputPeerEmpty::read(Reader reader)
{
    return InputPeerEmpty();
}

std::string InputPeerEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPeerSelf InputPeerSelf::read(Reader reader)
{
    return InputPeerSelf();
}

std::string InputPeerSelf::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPeerChat::InputPeerChat(int chat_id_) {}

InputPeerChat InputPeerChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return InputPeerChat(chat_id_);
}

std::string InputPeerChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

InputPeerUser::InputPeerUser(int user_id_, long access_hash_) {}

InputPeerUser InputPeerUser::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    return InputPeerUser(user_id_, access_hash_);
}

std::string InputPeerUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputPeerChannel::InputPeerChannel(int channel_id_, long access_hash_) {}

InputPeerChannel InputPeerChannel::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    return InputPeerChannel(channel_id_, access_hash_);
}

std::string InputPeerChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputPeerUserFromMessage::InputPeerUserFromMessage(TLObject peer_, int msg_id_, int user_id_) {}

InputPeerUserFromMessage InputPeerUserFromMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    return InputPeerUserFromMessage(peer_, msg_id_, user_id_);
}

std::string InputPeerUserFromMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(user_id);
    return buffer;
}

InputPeerChannelFromMessage::InputPeerChannelFromMessage(TLObject peer_, int msg_id_, int channel_id_) {}

InputPeerChannelFromMessage InputPeerChannelFromMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int channel_id_ = Int::read(reader);
    return InputPeerChannelFromMessage(peer_, msg_id_, channel_id_);
}

std::string InputPeerChannelFromMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(channel_id);
    return buffer;
}
InputUserEmpty InputUserEmpty::read(Reader reader)
{
    return InputUserEmpty();
}

std::string InputUserEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputUserSelf InputUserSelf::read(Reader reader)
{
    return InputUserSelf();
}

std::string InputUserSelf::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputUser::InputUser(int user_id_, long access_hash_) {}

InputUser InputUser::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    return InputUser(user_id_, access_hash_);
}

std::string InputUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputUserFromMessage::InputUserFromMessage(TLObject peer_, int msg_id_, int user_id_) {}

InputUserFromMessage InputUserFromMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    return InputUserFromMessage(peer_, msg_id_, user_id_);
}

std::string InputUserFromMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(user_id);
    return buffer;
}

InputPhoneContact::InputPhoneContact(long client_id_, std::string phone_, std::string first_name_, std::string last_name_) {}

InputPhoneContact InputPhoneContact::read(Reader reader)
{
    long client_id_ = Long::read(reader);
    std::string phone_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    return InputPhoneContact(client_id_, phone_, first_name_, last_name_);
}

std::string InputPhoneContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(client_id);
    buffer += String::write(phone);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    return buffer;
}

InputFile::InputFile(long id_, int parts_, std::string name_, std::string md5_checksum_) {}

InputFile InputFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    int parts_ = Int::read(reader);
    std::string name_ = String::read(reader);
    std::string md5_checksum_ = String::read(reader);
    return InputFile(id_, parts_, name_, md5_checksum_);
}

std::string InputFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(parts);
    buffer += String::write(name);
    buffer += String::write(md5_checksum);
    return buffer;
}

InputFileBig::InputFileBig(long id_, int parts_, std::string name_) {}

InputFileBig InputFileBig::read(Reader reader)
{
    long id_ = Long::read(reader);
    int parts_ = Int::read(reader);
    std::string name_ = String::read(reader);
    return InputFileBig(id_, parts_, name_);
}

std::string InputFileBig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(parts);
    buffer += String::write(name);
    return buffer;
}
InputMediaEmpty InputMediaEmpty::read(Reader reader)
{
    return InputMediaEmpty();
}

std::string InputMediaEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputMediaUploadedPhoto::InputMediaUploadedPhoto(TLObject file_, std::optional<std::vector<TLObject>> stickers_, std::optional<int> ttl_seconds_) {}

InputMediaUploadedPhoto InputMediaUploadedPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::vector<TLObject>> stickers_;
    stickers_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaUploadedPhoto(file_, stickers_, ttl_seconds_);
}

std::string InputMediaUploadedPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= stickers ? 1 << 0 : 0;
    flags |= ttl_seconds ? 1 << 1 : 0;
    buffer += file.write();

    if (stickers)
        buffer += Vector<TLObject>::write(stickers.value());

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

InputMediaPhoto::InputMediaPhoto(TLObject id_, std::optional<int> ttl_seconds_) {}

InputMediaPhoto InputMediaPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaPhoto(id_, ttl_seconds_);
}

std::string InputMediaPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ttl_seconds ? 1 << 0 : 0;
    buffer += id.write();

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

InputMediaGeoPoint::InputMediaGeoPoint(TLObject geo_point_) {}

InputMediaGeoPoint InputMediaGeoPoint::read(Reader reader)
{
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    return InputMediaGeoPoint(geo_point_);
}

std::string InputMediaGeoPoint::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo_point.write();
    return buffer;
}

InputMediaContact::InputMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_) {}

InputMediaContact InputMediaContact::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string vcard_ = String::read(reader);
    return InputMediaContact(phone_number_, first_name_, last_name_, vcard_);
}

std::string InputMediaContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(vcard);
    return buffer;
}

InputMediaUploadedDocument::InputMediaUploadedDocument(TLObject file_, std::string mime_type_, std::vector<TLObject> attributes_, std::optional<bool> nosound_video_, std::optional<bool> force_file_, std::optional<TLObject> thumb_, std::optional<std::vector<TLObject>> stickers_, std::optional<int> ttl_seconds_) {}

InputMediaUploadedDocument InputMediaUploadedDocument::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> nosound_video_;
    nosound_video_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> force_file_;
    force_file_ = (1 << 4) ? std::optional{true} : std::nullopt;
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> thumb_;
    thumb_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string mime_type_ = String::read(reader);
    std::vector<TLObject> attributes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<std::vector<TLObject>> stickers_;
    stickers_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaUploadedDocument(file_, mime_type_, attributes_, nosound_video_, force_file_, thumb_, stickers_, ttl_seconds_);
}

std::string InputMediaUploadedDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= nosound_video ? 1 << 3 : 0;
    flags |= force_file ? 1 << 4 : 0;
    flags |= thumb ? 1 << 2 : 0;
    flags |= stickers ? 1 << 0 : 0;
    flags |= ttl_seconds ? 1 << 1 : 0;
    buffer += file.write();

    if (thumb)
        buffer += thumb.value().write();
    buffer += String::write(mime_type);
    buffer += Vector<TLObject>::write(attributes);

    if (stickers)
        buffer += Vector<TLObject>::write(stickers.value());

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

InputMediaDocument::InputMediaDocument(TLObject id_, std::optional<int> ttl_seconds_, std::optional<std::string> query_) {}

InputMediaDocument InputMediaDocument::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> query_;
    query_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    return InputMediaDocument(id_, ttl_seconds_, query_);
}

std::string InputMediaDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ttl_seconds ? 1 << 0 : 0;
    flags |= query ? 1 << 1 : 0;
    buffer += id.write();

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());

    if (query)
        buffer += String::write(query.value());
    return buffer;
}

InputMediaVenue::InputMediaVenue(TLObject geo_point_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_) {}

InputMediaVenue InputMediaVenue::read(Reader reader)
{
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    std::string address_ = String::read(reader);
    std::string provider_ = String::read(reader);
    std::string venue_id_ = String::read(reader);
    std::string venue_type_ = String::read(reader);
    return InputMediaVenue(geo_point_, title_, address_, provider_, venue_id_, venue_type_);
}

std::string InputMediaVenue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo_point.write();
    buffer += String::write(title);
    buffer += String::write(address);
    buffer += String::write(provider);
    buffer += String::write(venue_id);
    buffer += String::write(venue_type);
    return buffer;
}

InputMediaPhotoExternal::InputMediaPhotoExternal(std::string url_, std::optional<int> ttl_seconds_) {}

InputMediaPhotoExternal InputMediaPhotoExternal::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string url_ = String::read(reader);
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaPhotoExternal(url_, ttl_seconds_);
}

std::string InputMediaPhotoExternal::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ttl_seconds ? 1 << 0 : 0;
    buffer += String::write(url);

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

InputMediaDocumentExternal::InputMediaDocumentExternal(std::string url_, std::optional<int> ttl_seconds_) {}

InputMediaDocumentExternal InputMediaDocumentExternal::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string url_ = String::read(reader);
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaDocumentExternal(url_, ttl_seconds_);
}

std::string InputMediaDocumentExternal::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ttl_seconds ? 1 << 0 : 0;
    buffer += String::write(url);

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

InputMediaGame::InputMediaGame(TLObject id_) {}

InputMediaGame InputMediaGame::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return InputMediaGame(id_);
}

std::string InputMediaGame::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

InputMediaInvoice::InputMediaInvoice(std::string title_, std::string description_, TLObject invoice_, std::string payload_, std::string provider_, TLObject provider_data_, std::optional<TLObject> photo_, std::optional<std::string> start_param_) {}

InputMediaInvoice InputMediaInvoice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject invoice_ = std::get<TLObject>(TLObject::read(reader));
    std::string payload_ = Bytes::read(reader);
    std::string provider_ = String::read(reader);
    TLObject provider_data_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> start_param_;
    start_param_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    return InputMediaInvoice(title_, description_, invoice_, payload_, provider_, provider_data_, photo_, start_param_);
}

std::string InputMediaInvoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= start_param ? 1 << 1 : 0;
    buffer += String::write(title);
    buffer += String::write(description);

    if (photo)
        buffer += photo.value().write();
    buffer += invoice.write();
    buffer += Bytes::write(payload);
    buffer += String::write(provider);
    buffer += provider_data.write();

    if (start_param)
        buffer += String::write(start_param.value());
    return buffer;
}

InputMediaGeoLive::InputMediaGeoLive(TLObject geo_point_, std::optional<bool> stopped_, std::optional<int> heading_, std::optional<int> period_, std::optional<int> proximity_notification_radius_) {}

InputMediaGeoLive InputMediaGeoLive::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> stopped_;
    stopped_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> heading_;
    heading_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> period_;
    period_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> proximity_notification_radius_;
    proximity_notification_radius_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputMediaGeoLive(geo_point_, stopped_, heading_, period_, proximity_notification_radius_);
}

std::string InputMediaGeoLive::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= stopped ? 1 << 0 : 0;
    flags |= heading ? 1 << 2 : 0;
    flags |= period ? 1 << 1 : 0;
    flags |= proximity_notification_radius ? 1 << 3 : 0;
    buffer += geo_point.write();

    if (heading)
        buffer += Int::write(heading.value());

    if (period)
        buffer += Int::write(period.value());

    if (proximity_notification_radius)
        buffer += Int::write(proximity_notification_radius.value());
    return buffer;
}

InputMediaPoll::InputMediaPoll(TLObject poll_, std::optional<std::vector<std::string>> correct_answers_, std::optional<std::string> solution_, std::optional<std::vector<TLObject>> solution_entities_) {}

InputMediaPoll InputMediaPoll::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject poll_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::vector<std::string>> correct_answers_;
    correct_answers_ = (1 << 0) ? std::optional{std::get<std::vector<std::string>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> solution_;
    solution_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> solution_entities_;
    solution_entities_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return InputMediaPoll(poll_, correct_answers_, solution_, solution_entities_);
}

std::string InputMediaPoll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= correct_answers ? 1 << 0 : 0;
    flags |= solution ? 1 << 1 : 0;
    flags |= solution_entities ? 1 << 1 : 0;
    buffer += poll.write();

    if (correct_answers)
        buffer += Vector<std::string>::write(correct_answers.value());

    if (solution)
        buffer += String::write(solution.value());

    if (solution_entities)
        buffer += Vector<TLObject>::write(solution_entities.value());
    return buffer;
}

InputMediaDice::InputMediaDice(std::string emoticon_) {}

InputMediaDice InputMediaDice::read(Reader reader)
{
    std::string emoticon_ = String::read(reader);
    return InputMediaDice(emoticon_);
}

std::string InputMediaDice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(emoticon);
    return buffer;
}
InputChatPhotoEmpty InputChatPhotoEmpty::read(Reader reader)
{
    return InputChatPhotoEmpty();
}

std::string InputChatPhotoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputChatUploadedPhoto::InputChatUploadedPhoto(std::optional<TLObject> file_, std::optional<TLObject> video_, std::optional<double> video_start_ts_) {}

InputChatUploadedPhoto InputChatUploadedPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> file_;
    file_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> video_;
    video_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<double> video_start_ts_;
    video_start_ts_ = (1 << 2) ? std::optional{Double::read(reader)} : std::nullopt;
    return InputChatUploadedPhoto(file_, video_, video_start_ts_);
}

std::string InputChatUploadedPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= file ? 1 << 0 : 0;
    flags |= video ? 1 << 1 : 0;
    flags |= video_start_ts ? 1 << 2 : 0;

    if (file)
        buffer += file.value().write();

    if (video)
        buffer += video.value().write();

    if (video_start_ts)
        buffer += Double::write(video_start_ts.value());
    return buffer;
}

InputChatPhoto::InputChatPhoto(TLObject id_) {}

InputChatPhoto InputChatPhoto::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return InputChatPhoto(id_);
}

std::string InputChatPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}
InputGeoPointEmpty InputGeoPointEmpty::read(Reader reader)
{
    return InputGeoPointEmpty();
}

std::string InputGeoPointEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputGeoPoint::InputGeoPoint(double lat_, double long__, std::optional<int> accuracy_radius_) {}

InputGeoPoint InputGeoPoint::read(Reader reader)
{
    int flags = Int::read(reader);
    double lat_ = Double::read(reader);
    double long__ = Double::read(reader);
    std::optional<int> accuracy_radius_;
    accuracy_radius_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return InputGeoPoint(lat_, long__, accuracy_radius_);
}

std::string InputGeoPoint::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= accuracy_radius ? 1 << 0 : 0;
    buffer += Double::write(lat);
    buffer += Double::write(long_);

    if (accuracy_radius)
        buffer += Int::write(accuracy_radius.value());
    return buffer;
}
InputPhotoEmpty InputPhotoEmpty::read(Reader reader)
{
    return InputPhotoEmpty();
}

std::string InputPhotoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPhoto::InputPhoto(long id_, long access_hash_, std::string file_reference_) {}

InputPhoto InputPhoto::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    return InputPhoto(id_, access_hash_, file_reference_);
}

std::string InputPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    return buffer;
}

InputFileLocation::InputFileLocation(long volume_id_, int local_id_, long secret_, std::string file_reference_) {}

InputFileLocation InputFileLocation::read(Reader reader)
{
    long volume_id_ = Long::read(reader);
    int local_id_ = Int::read(reader);
    long secret_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    return InputFileLocation(volume_id_, local_id_, secret_, file_reference_);
}

std::string InputFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(volume_id);
    buffer += Int::write(local_id);
    buffer += Long::write(secret);
    buffer += Bytes::write(file_reference);
    return buffer;
}

InputEncryptedFileLocation::InputEncryptedFileLocation(long id_, long access_hash_) {}

InputEncryptedFileLocation InputEncryptedFileLocation::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputEncryptedFileLocation(id_, access_hash_);
}

std::string InputEncryptedFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputDocumentFileLocation::InputDocumentFileLocation(long id_, long access_hash_, std::string file_reference_, std::string thumb_size_) {}

InputDocumentFileLocation InputDocumentFileLocation::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    std::string thumb_size_ = String::read(reader);
    return InputDocumentFileLocation(id_, access_hash_, file_reference_, thumb_size_);
}

std::string InputDocumentFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    buffer += String::write(thumb_size);
    return buffer;
}

InputSecureFileLocation::InputSecureFileLocation(long id_, long access_hash_) {}

InputSecureFileLocation InputSecureFileLocation::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputSecureFileLocation(id_, access_hash_);
}

std::string InputSecureFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}
InputTakeoutFileLocation InputTakeoutFileLocation::read(Reader reader)
{
    return InputTakeoutFileLocation();
}

std::string InputTakeoutFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPhotoFileLocation::InputPhotoFileLocation(long id_, long access_hash_, std::string file_reference_, std::string thumb_size_) {}

InputPhotoFileLocation InputPhotoFileLocation::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    std::string thumb_size_ = String::read(reader);
    return InputPhotoFileLocation(id_, access_hash_, file_reference_, thumb_size_);
}

std::string InputPhotoFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    buffer += String::write(thumb_size);
    return buffer;
}

InputPhotoLegacyFileLocation::InputPhotoLegacyFileLocation(long id_, long access_hash_, std::string file_reference_, long volume_id_, int local_id_, long secret_) {}

InputPhotoLegacyFileLocation InputPhotoLegacyFileLocation::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    long volume_id_ = Long::read(reader);
    int local_id_ = Int::read(reader);
    long secret_ = Long::read(reader);
    return InputPhotoLegacyFileLocation(id_, access_hash_, file_reference_, volume_id_, local_id_, secret_);
}

std::string InputPhotoLegacyFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    buffer += Long::write(volume_id);
    buffer += Int::write(local_id);
    buffer += Long::write(secret);
    return buffer;
}

InputPeerPhotoFileLocation::InputPeerPhotoFileLocation(TLObject peer_, long photo_id_, std::optional<bool> big_) {}

InputPeerPhotoFileLocation InputPeerPhotoFileLocation::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> big_;
    big_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    long photo_id_ = Long::read(reader);
    return InputPeerPhotoFileLocation(peer_, photo_id_, big_);
}

std::string InputPeerPhotoFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= big ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Long::write(photo_id);
    return buffer;
}

InputStickerSetThumb::InputStickerSetThumb(TLObject stickerset_, int thumb_version_) {}

InputStickerSetThumb InputStickerSetThumb::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    int thumb_version_ = Int::read(reader);
    return InputStickerSetThumb(stickerset_, thumb_version_);
}

std::string InputStickerSetThumb::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += Int::write(thumb_version);
    return buffer;
}

InputGroupCallStream::InputGroupCallStream(TLObject call_, long time_ms_, int scale_) {}

InputGroupCallStream InputGroupCallStream::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    long time_ms_ = Long::read(reader);
    int scale_ = Int::read(reader);
    return InputGroupCallStream(call_, time_ms_, scale_);
}

std::string InputGroupCallStream::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Long::write(time_ms);
    buffer += Int::write(scale);
    return buffer;
}

PeerUser::PeerUser(int user_id_) {}

PeerUser PeerUser::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    return PeerUser(user_id_);
}

std::string PeerUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    return buffer;
}

PeerChat::PeerChat(int chat_id_) {}

PeerChat PeerChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return PeerChat(chat_id_);
}

std::string PeerChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

PeerChannel::PeerChannel(int channel_id_) {}

PeerChannel PeerChannel::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    return PeerChannel(channel_id_);
}

std::string PeerChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    return buffer;
}

UserEmpty::UserEmpty(int id_) {}

UserEmpty UserEmpty::read(Reader reader)
{
    int id_ = Int::read(reader);
    return UserEmpty(id_);
}

std::string UserEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    return buffer;
}

User::User(int id_, std::optional<bool> self_, std::optional<bool> contact_, std::optional<bool> mutual_contact_, std::optional<bool> deleted_, std::optional<bool> bot_, std::optional<bool> bot_chat_history_, std::optional<bool> bot_nochats_, std::optional<bool> verified_, std::optional<bool> restricted_, std::optional<bool> min_, std::optional<bool> bot_inline_geo_, std::optional<bool> support_, std::optional<bool> scam_, std::optional<bool> apply_min_photo_, std::optional<bool> fake_, std::optional<long> access_hash_, std::optional<std::string> first_name_, std::optional<std::string> last_name_, std::optional<std::string> username_, std::optional<std::string> phone_, std::optional<TLObject> photo_, std::optional<TLObject> status_, std::optional<int> bot_info_version_, std::optional<std::vector<TLObject>> restriction_reason_, std::optional<std::string> bot_inline_placeholder_, std::optional<std::string> lang_code_) {}

User User::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> self_;
    self_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> contact_;
    contact_ = (1 << 11) ? std::optional{true} : std::nullopt;
    std::optional<bool> mutual_contact_;
    mutual_contact_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> deleted_;
    deleted_ = (1 << 13) ? std::optional{true} : std::nullopt;
    std::optional<bool> bot_;
    bot_ = (1 << 14) ? std::optional{true} : std::nullopt;
    std::optional<bool> bot_chat_history_;
    bot_chat_history_ = (1 << 15) ? std::optional{true} : std::nullopt;
    std::optional<bool> bot_nochats_;
    bot_nochats_ = (1 << 16) ? std::optional{true} : std::nullopt;
    std::optional<bool> verified_;
    verified_ = (1 << 17) ? std::optional{true} : std::nullopt;
    std::optional<bool> restricted_;
    restricted_ = (1 << 18) ? std::optional{true} : std::nullopt;
    std::optional<bool> min_;
    min_ = (1 << 20) ? std::optional{true} : std::nullopt;
    std::optional<bool> bot_inline_geo_;
    bot_inline_geo_ = (1 << 21) ? std::optional{true} : std::nullopt;
    std::optional<bool> support_;
    support_ = (1 << 23) ? std::optional{true} : std::nullopt;
    std::optional<bool> scam_;
    scam_ = (1 << 24) ? std::optional{true} : std::nullopt;
    std::optional<bool> apply_min_photo_;
    apply_min_photo_ = (1 << 25) ? std::optional{true} : std::nullopt;
    std::optional<bool> fake_;
    fake_ = (1 << 26) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::optional<long> access_hash_;
    access_hash_ = (1 << 0) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<std::string> first_name_;
    first_name_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> last_name_;
    last_name_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> username_;
    username_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> phone_;
    phone_ = (1 << 4) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> photo_;
    photo_ = (1 << 5) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> status_;
    status_ = (1 << 6) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> bot_info_version_;
    bot_info_version_ = (1 << 14) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> restriction_reason_;
    restriction_reason_ = (1 << 18) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> bot_inline_placeholder_;
    bot_inline_placeholder_ = (1 << 19) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> lang_code_;
    lang_code_ = (1 << 22) ? std::optional{String::read(reader)} : std::nullopt;
    return User(id_, self_, contact_, mutual_contact_, deleted_, bot_, bot_chat_history_, bot_nochats_, verified_, restricted_, min_, bot_inline_geo_, support_, scam_, apply_min_photo_, fake_, access_hash_, first_name_, last_name_, username_, phone_, photo_, status_, bot_info_version_, restriction_reason_, bot_inline_placeholder_, lang_code_);
}

std::string User::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= self ? 1 << 10 : 0;
    flags |= contact ? 1 << 11 : 0;
    flags |= mutual_contact ? 1 << 12 : 0;
    flags |= deleted ? 1 << 13 : 0;
    flags |= bot ? 1 << 14 : 0;
    flags |= bot_chat_history ? 1 << 15 : 0;
    flags |= bot_nochats ? 1 << 16 : 0;
    flags |= verified ? 1 << 17 : 0;
    flags |= restricted ? 1 << 18 : 0;
    flags |= min ? 1 << 20 : 0;
    flags |= bot_inline_geo ? 1 << 21 : 0;
    flags |= support ? 1 << 23 : 0;
    flags |= scam ? 1 << 24 : 0;
    flags |= apply_min_photo ? 1 << 25 : 0;
    flags |= fake ? 1 << 26 : 0;
    flags |= access_hash ? 1 << 0 : 0;
    flags |= first_name ? 1 << 1 : 0;
    flags |= last_name ? 1 << 2 : 0;
    flags |= username ? 1 << 3 : 0;
    flags |= phone ? 1 << 4 : 0;
    flags |= photo ? 1 << 5 : 0;
    flags |= status ? 1 << 6 : 0;
    flags |= bot_info_version ? 1 << 14 : 0;
    flags |= restriction_reason ? 1 << 18 : 0;
    flags |= bot_inline_placeholder ? 1 << 19 : 0;
    flags |= lang_code ? 1 << 22 : 0;
    buffer += Int::write(id);

    if (access_hash)
        buffer += Long::write(access_hash.value());

    if (first_name)
        buffer += String::write(first_name.value());

    if (last_name)
        buffer += String::write(last_name.value());

    if (username)
        buffer += String::write(username.value());

    if (phone)
        buffer += String::write(phone.value());

    if (photo)
        buffer += photo.value().write();

    if (status)
        buffer += status.value().write();

    if (bot_info_version)
        buffer += Int::write(bot_info_version.value());

    if (restriction_reason)
        buffer += Vector<TLObject>::write(restriction_reason.value());

    if (bot_inline_placeholder)
        buffer += String::write(bot_inline_placeholder.value());

    if (lang_code)
        buffer += String::write(lang_code.value());
    return buffer;
}
UserProfilePhotoEmpty UserProfilePhotoEmpty::read(Reader reader)
{
    return UserProfilePhotoEmpty();
}

std::string UserProfilePhotoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UserProfilePhoto::UserProfilePhoto(long photo_id_, int dc_id_, std::optional<bool> has_video_, std::optional<std::string> stripped_thumb_) {}

UserProfilePhoto UserProfilePhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> has_video_;
    has_video_ = (1 << 0) ? std::optional{true} : std::nullopt;
    long photo_id_ = Long::read(reader);
    std::optional<std::string> stripped_thumb_;
    stripped_thumb_ = (1 << 1) ? std::optional{Bytes::read(reader)} : std::nullopt;
    int dc_id_ = Int::read(reader);
    return UserProfilePhoto(photo_id_, dc_id_, has_video_, stripped_thumb_);
}

std::string UserProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= has_video ? 1 << 0 : 0;
    flags |= stripped_thumb ? 1 << 1 : 0;
    buffer += Long::write(photo_id);

    if (stripped_thumb)
        buffer += Bytes::write(stripped_thumb.value());
    buffer += Int::write(dc_id);
    return buffer;
}
UserStatusEmpty UserStatusEmpty::read(Reader reader)
{
    return UserStatusEmpty();
}

std::string UserStatusEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UserStatusOnline::UserStatusOnline(int expires_) {}

UserStatusOnline UserStatusOnline::read(Reader reader)
{
    int expires_ = Int::read(reader);
    return UserStatusOnline(expires_);
}

std::string UserStatusOnline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    return buffer;
}

UserStatusOffline::UserStatusOffline(int was_online_) {}

UserStatusOffline UserStatusOffline::read(Reader reader)
{
    int was_online_ = Int::read(reader);
    return UserStatusOffline(was_online_);
}

std::string UserStatusOffline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(was_online);
    return buffer;
}
UserStatusRecently UserStatusRecently::read(Reader reader)
{
    return UserStatusRecently();
}

std::string UserStatusRecently::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UserStatusLastWeek UserStatusLastWeek::read(Reader reader)
{
    return UserStatusLastWeek();
}

std::string UserStatusLastWeek::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UserStatusLastMonth UserStatusLastMonth::read(Reader reader)
{
    return UserStatusLastMonth();
}

std::string UserStatusLastMonth::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChatEmpty::ChatEmpty(int id_) {}

ChatEmpty ChatEmpty::read(Reader reader)
{
    int id_ = Int::read(reader);
    return ChatEmpty(id_);
}

std::string ChatEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    return buffer;
}

Chat::Chat(int id_, std::string title_, TLObject photo_, int participants_count_, int date_, int version_, std::optional<bool> creator_, std::optional<bool> kicked_, std::optional<bool> left_, std::optional<bool> deactivated_, std::optional<bool> call_active_, std::optional<bool> call_not_empty_, std::optional<TLObject> migrated_to_, std::optional<TLObject> admin_rights_, std::optional<TLObject> default_banned_rights_) {}

Chat Chat::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> creator_;
    creator_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> kicked_;
    kicked_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> left_;
    left_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> deactivated_;
    deactivated_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> call_active_;
    call_active_ = (1 << 23) ? std::optional{true} : std::nullopt;
    std::optional<bool> call_not_empty_;
    call_not_empty_ = (1 << 24) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    int participants_count_ = Int::read(reader);
    int date_ = Int::read(reader);
    int version_ = Int::read(reader);
    std::optional<TLObject> migrated_to_;
    migrated_to_ = (1 << 6) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> admin_rights_;
    admin_rights_ = (1 << 14) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> default_banned_rights_;
    default_banned_rights_ = (1 << 18) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return Chat(id_, title_, photo_, participants_count_, date_, version_, creator_, kicked_, left_, deactivated_, call_active_, call_not_empty_, migrated_to_, admin_rights_, default_banned_rights_);
}

std::string Chat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= creator ? 1 << 0 : 0;
    flags |= kicked ? 1 << 1 : 0;
    flags |= left ? 1 << 2 : 0;
    flags |= deactivated ? 1 << 5 : 0;
    flags |= call_active ? 1 << 23 : 0;
    flags |= call_not_empty ? 1 << 24 : 0;
    flags |= migrated_to ? 1 << 6 : 0;
    flags |= admin_rights ? 1 << 14 : 0;
    flags |= default_banned_rights ? 1 << 18 : 0;
    buffer += Int::write(id);
    buffer += String::write(title);
    buffer += photo.write();
    buffer += Int::write(participants_count);
    buffer += Int::write(date);
    buffer += Int::write(version);

    if (migrated_to)
        buffer += migrated_to.value().write();

    if (admin_rights)
        buffer += admin_rights.value().write();

    if (default_banned_rights)
        buffer += default_banned_rights.value().write();
    return buffer;
}

ChatForbidden::ChatForbidden(int id_, std::string title_) {}

ChatForbidden ChatForbidden::read(Reader reader)
{
    int id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    return ChatForbidden(id_, title_);
}

std::string ChatForbidden::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += String::write(title);
    return buffer;
}

Channel::Channel(int id_, std::string title_, TLObject photo_, int date_, int version_, std::optional<bool> creator_, std::optional<bool> left_, std::optional<bool> broadcast_, std::optional<bool> verified_, std::optional<bool> megagroup_, std::optional<bool> restricted_, std::optional<bool> signatures_, std::optional<bool> min_, std::optional<bool> scam_, std::optional<bool> has_link_, std::optional<bool> has_geo_, std::optional<bool> slowmode_enabled_, std::optional<bool> call_active_, std::optional<bool> call_not_empty_, std::optional<bool> fake_, std::optional<bool> gigagroup_, std::optional<long> access_hash_, std::optional<std::string> username_, std::optional<std::vector<TLObject>> restriction_reason_, std::optional<TLObject> admin_rights_, std::optional<TLObject> banned_rights_, std::optional<TLObject> default_banned_rights_, std::optional<int> participants_count_) {}

Channel Channel::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> creator_;
    creator_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> left_;
    left_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> broadcast_;
    broadcast_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> verified_;
    verified_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> megagroup_;
    megagroup_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> restricted_;
    restricted_ = (1 << 9) ? std::optional{true} : std::nullopt;
    std::optional<bool> signatures_;
    signatures_ = (1 << 11) ? std::optional{true} : std::nullopt;
    std::optional<bool> min_;
    min_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> scam_;
    scam_ = (1 << 19) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_link_;
    has_link_ = (1 << 20) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_geo_;
    has_geo_ = (1 << 21) ? std::optional{true} : std::nullopt;
    std::optional<bool> slowmode_enabled_;
    slowmode_enabled_ = (1 << 22) ? std::optional{true} : std::nullopt;
    std::optional<bool> call_active_;
    call_active_ = (1 << 23) ? std::optional{true} : std::nullopt;
    std::optional<bool> call_not_empty_;
    call_not_empty_ = (1 << 24) ? std::optional{true} : std::nullopt;
    std::optional<bool> fake_;
    fake_ = (1 << 25) ? std::optional{true} : std::nullopt;
    std::optional<bool> gigagroup_;
    gigagroup_ = (1 << 26) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::optional<long> access_hash_;
    access_hash_ = (1 << 13) ? std::optional{Long::read(reader)} : std::nullopt;
    std::string title_ = String::read(reader);
    std::optional<std::string> username_;
    username_ = (1 << 6) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    int date_ = Int::read(reader);
    int version_ = Int::read(reader);
    std::optional<std::vector<TLObject>> restriction_reason_;
    restriction_reason_ = (1 << 9) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> admin_rights_;
    admin_rights_ = (1 << 14) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> banned_rights_;
    banned_rights_ = (1 << 15) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> default_banned_rights_;
    default_banned_rights_ = (1 << 18) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> participants_count_;
    participants_count_ = (1 << 17) ? std::optional{Int::read(reader)} : std::nullopt;
    return Channel(id_, title_, photo_, date_, version_, creator_, left_, broadcast_, verified_, megagroup_, restricted_, signatures_, min_, scam_, has_link_, has_geo_, slowmode_enabled_, call_active_, call_not_empty_, fake_, gigagroup_, access_hash_, username_, restriction_reason_, admin_rights_, banned_rights_, default_banned_rights_, participants_count_);
}

std::string Channel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= creator ? 1 << 0 : 0;
    flags |= left ? 1 << 2 : 0;
    flags |= broadcast ? 1 << 5 : 0;
    flags |= verified ? 1 << 7 : 0;
    flags |= megagroup ? 1 << 8 : 0;
    flags |= restricted ? 1 << 9 : 0;
    flags |= signatures ? 1 << 11 : 0;
    flags |= min ? 1 << 12 : 0;
    flags |= scam ? 1 << 19 : 0;
    flags |= has_link ? 1 << 20 : 0;
    flags |= has_geo ? 1 << 21 : 0;
    flags |= slowmode_enabled ? 1 << 22 : 0;
    flags |= call_active ? 1 << 23 : 0;
    flags |= call_not_empty ? 1 << 24 : 0;
    flags |= fake ? 1 << 25 : 0;
    flags |= gigagroup ? 1 << 26 : 0;
    flags |= access_hash ? 1 << 13 : 0;
    flags |= username ? 1 << 6 : 0;
    flags |= restriction_reason ? 1 << 9 : 0;
    flags |= admin_rights ? 1 << 14 : 0;
    flags |= banned_rights ? 1 << 15 : 0;
    flags |= default_banned_rights ? 1 << 18 : 0;
    flags |= participants_count ? 1 << 17 : 0;
    buffer += Int::write(id);

    if (access_hash)
        buffer += Long::write(access_hash.value());
    buffer += String::write(title);

    if (username)
        buffer += String::write(username.value());
    buffer += photo.write();
    buffer += Int::write(date);
    buffer += Int::write(version);

    if (restriction_reason)
        buffer += Vector<TLObject>::write(restriction_reason.value());

    if (admin_rights)
        buffer += admin_rights.value().write();

    if (banned_rights)
        buffer += banned_rights.value().write();

    if (default_banned_rights)
        buffer += default_banned_rights.value().write();

    if (participants_count)
        buffer += Int::write(participants_count.value());
    return buffer;
}

ChannelForbidden::ChannelForbidden(int id_, long access_hash_, std::string title_, std::optional<bool> broadcast_, std::optional<bool> megagroup_, std::optional<int> until_date_) {}

ChannelForbidden ChannelForbidden::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> broadcast_;
    broadcast_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> megagroup_;
    megagroup_ = (1 << 8) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    std::string title_ = String::read(reader);
    std::optional<int> until_date_;
    until_date_ = (1 << 16) ? std::optional{Int::read(reader)} : std::nullopt;
    return ChannelForbidden(id_, access_hash_, title_, broadcast_, megagroup_, until_date_);
}

std::string ChannelForbidden::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= broadcast ? 1 << 5 : 0;
    flags |= megagroup ? 1 << 8 : 0;
    flags |= until_date ? 1 << 16 : 0;
    buffer += Int::write(id);
    buffer += Long::write(access_hash);
    buffer += String::write(title);

    if (until_date)
        buffer += Int::write(until_date.value());
    return buffer;
}

ChatFull::ChatFull(int id_, std::string about_, TLObject participants_, TLObject notify_settings_, std::optional<bool> can_set_username_, std::optional<bool> has_scheduled_, std::optional<TLObject> chat_photo_, std::optional<TLObject> exported_invite_, std::optional<std::vector<TLObject>> bot_info_, std::optional<int> pinned_msg_id_, std::optional<int> folder_id_, std::optional<TLObject> call_, std::optional<int> ttl_period_, std::optional<TLObject> groupcall_default_join_as_) {}

ChatFull ChatFull::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_set_username_;
    can_set_username_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_scheduled_;
    has_scheduled_ = (1 << 8) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string about_ = String::read(reader);
    TLObject participants_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> chat_photo_;
    chat_photo_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject notify_settings_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> exported_invite_;
    exported_invite_ = (1 << 13) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> bot_info_;
    bot_info_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> pinned_msg_id_;
    pinned_msg_id_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> folder_id_;
    folder_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> call_;
    call_ = (1 << 12) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 14) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> groupcall_default_join_as_;
    groupcall_default_join_as_ = (1 << 15) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return ChatFull(id_, about_, participants_, notify_settings_, can_set_username_, has_scheduled_, chat_photo_, exported_invite_, bot_info_, pinned_msg_id_, folder_id_, call_, ttl_period_, groupcall_default_join_as_);
}

std::string ChatFull::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_set_username ? 1 << 7 : 0;
    flags |= has_scheduled ? 1 << 8 : 0;
    flags |= chat_photo ? 1 << 2 : 0;
    flags |= exported_invite ? 1 << 13 : 0;
    flags |= bot_info ? 1 << 3 : 0;
    flags |= pinned_msg_id ? 1 << 6 : 0;
    flags |= folder_id ? 1 << 11 : 0;
    flags |= call ? 1 << 12 : 0;
    flags |= ttl_period ? 1 << 14 : 0;
    flags |= groupcall_default_join_as ? 1 << 15 : 0;
    buffer += Int::write(id);
    buffer += String::write(about);
    buffer += participants.write();

    if (chat_photo)
        buffer += chat_photo.value().write();
    buffer += notify_settings.write();

    if (exported_invite)
        buffer += exported_invite.value().write();

    if (bot_info)
        buffer += Vector<TLObject>::write(bot_info.value());

    if (pinned_msg_id)
        buffer += Int::write(pinned_msg_id.value());

    if (folder_id)
        buffer += Int::write(folder_id.value());

    if (call)
        buffer += call.value().write();

    if (ttl_period)
        buffer += Int::write(ttl_period.value());

    if (groupcall_default_join_as)
        buffer += groupcall_default_join_as.value().write();
    return buffer;
}

ChannelFull::ChannelFull(int id_, std::string about_, int read_inbox_max_id_, int read_outbox_max_id_, int unread_count_, TLObject chat_photo_, TLObject notify_settings_, std::vector<TLObject> bot_info_, int pts_, std::optional<bool> can_view_participants_, std::optional<bool> can_set_username_, std::optional<bool> can_set_stickers_, std::optional<bool> hidden_prehistory_, std::optional<bool> can_set_location_, std::optional<bool> has_scheduled_, std::optional<bool> can_view_stats_, std::optional<bool> blocked_, std::optional<int> participants_count_, std::optional<int> admins_count_, std::optional<int> kicked_count_, std::optional<int> banned_count_, std::optional<int> online_count_, std::optional<TLObject> exported_invite_, std::optional<int> migrated_from_chat_id_, std::optional<int> migrated_from_max_id_, std::optional<int> pinned_msg_id_, std::optional<TLObject> stickerset_, std::optional<int> available_min_id_, std::optional<int> folder_id_, std::optional<int> linked_chat_id_, std::optional<TLObject> location_, std::optional<int> slowmode_seconds_, std::optional<int> slowmode_next_send_date_, std::optional<int> stats_dc_, std::optional<TLObject> call_, std::optional<int> ttl_period_, std::optional<std::vector<std::string>> pending_suggestions_, std::optional<TLObject> groupcall_default_join_as_) {}

ChannelFull ChannelFull::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_view_participants_;
    can_view_participants_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_set_username_;
    can_set_username_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_set_stickers_;
    can_set_stickers_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> hidden_prehistory_;
    hidden_prehistory_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_set_location_;
    can_set_location_ = (1 << 16) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_scheduled_;
    has_scheduled_ = (1 << 19) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_view_stats_;
    can_view_stats_ = (1 << 20) ? std::optional{true} : std::nullopt;
    std::optional<bool> blocked_;
    blocked_ = (1 << 22) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string about_ = String::read(reader);
    std::optional<int> participants_count_;
    participants_count_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> admins_count_;
    admins_count_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> kicked_count_;
    kicked_count_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> banned_count_;
    banned_count_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> online_count_;
    online_count_ = (1 << 13) ? std::optional{Int::read(reader)} : std::nullopt;
    int read_inbox_max_id_ = Int::read(reader);
    int read_outbox_max_id_ = Int::read(reader);
    int unread_count_ = Int::read(reader);
    TLObject chat_photo_ = std::get<TLObject>(TLObject::read(reader));
    TLObject notify_settings_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> exported_invite_;
    exported_invite_ = (1 << 23) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::vector<TLObject> bot_info_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<int> migrated_from_chat_id_;
    migrated_from_chat_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> migrated_from_max_id_;
    migrated_from_max_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> pinned_msg_id_;
    pinned_msg_id_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> stickerset_;
    stickerset_ = (1 << 8) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> available_min_id_;
    available_min_id_ = (1 << 9) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> folder_id_;
    folder_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> linked_chat_id_;
    linked_chat_id_ = (1 << 14) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> location_;
    location_ = (1 << 15) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> slowmode_seconds_;
    slowmode_seconds_ = (1 << 17) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> slowmode_next_send_date_;
    slowmode_next_send_date_ = (1 << 18) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> stats_dc_;
    stats_dc_ = (1 << 12) ? std::optional{Int::read(reader)} : std::nullopt;
    int pts_ = Int::read(reader);
    std::optional<TLObject> call_;
    call_ = (1 << 21) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 24) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::vector<std::string>> pending_suggestions_;
    pending_suggestions_ = (1 << 25) ? std::optional{std::get<std::vector<std::string>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> groupcall_default_join_as_;
    groupcall_default_join_as_ = (1 << 26) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return ChannelFull(id_, about_, read_inbox_max_id_, read_outbox_max_id_, unread_count_, chat_photo_, notify_settings_, bot_info_, pts_, can_view_participants_, can_set_username_, can_set_stickers_, hidden_prehistory_, can_set_location_, has_scheduled_, can_view_stats_, blocked_, participants_count_, admins_count_, kicked_count_, banned_count_, online_count_, exported_invite_, migrated_from_chat_id_, migrated_from_max_id_, pinned_msg_id_, stickerset_, available_min_id_, folder_id_, linked_chat_id_, location_, slowmode_seconds_, slowmode_next_send_date_, stats_dc_, call_, ttl_period_, pending_suggestions_, groupcall_default_join_as_);
}

std::string ChannelFull::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_view_participants ? 1 << 3 : 0;
    flags |= can_set_username ? 1 << 6 : 0;
    flags |= can_set_stickers ? 1 << 7 : 0;
    flags |= hidden_prehistory ? 1 << 10 : 0;
    flags |= can_set_location ? 1 << 16 : 0;
    flags |= has_scheduled ? 1 << 19 : 0;
    flags |= can_view_stats ? 1 << 20 : 0;
    flags |= blocked ? 1 << 22 : 0;
    flags |= participants_count ? 1 << 0 : 0;
    flags |= admins_count ? 1 << 1 : 0;
    flags |= kicked_count ? 1 << 2 : 0;
    flags |= banned_count ? 1 << 2 : 0;
    flags |= online_count ? 1 << 13 : 0;
    flags |= exported_invite ? 1 << 23 : 0;
    flags |= migrated_from_chat_id ? 1 << 4 : 0;
    flags |= migrated_from_max_id ? 1 << 4 : 0;
    flags |= pinned_msg_id ? 1 << 5 : 0;
    flags |= stickerset ? 1 << 8 : 0;
    flags |= available_min_id ? 1 << 9 : 0;
    flags |= folder_id ? 1 << 11 : 0;
    flags |= linked_chat_id ? 1 << 14 : 0;
    flags |= location ? 1 << 15 : 0;
    flags |= slowmode_seconds ? 1 << 17 : 0;
    flags |= slowmode_next_send_date ? 1 << 18 : 0;
    flags |= stats_dc ? 1 << 12 : 0;
    flags |= call ? 1 << 21 : 0;
    flags |= ttl_period ? 1 << 24 : 0;
    flags |= pending_suggestions ? 1 << 25 : 0;
    flags |= groupcall_default_join_as ? 1 << 26 : 0;
    buffer += Int::write(id);
    buffer += String::write(about);

    if (participants_count)
        buffer += Int::write(participants_count.value());

    if (admins_count)
        buffer += Int::write(admins_count.value());

    if (kicked_count)
        buffer += Int::write(kicked_count.value());

    if (banned_count)
        buffer += Int::write(banned_count.value());

    if (online_count)
        buffer += Int::write(online_count.value());
    buffer += Int::write(read_inbox_max_id);
    buffer += Int::write(read_outbox_max_id);
    buffer += Int::write(unread_count);
    buffer += chat_photo.write();
    buffer += notify_settings.write();

    if (exported_invite)
        buffer += exported_invite.value().write();
    buffer += Vector<TLObject>::write(bot_info);

    if (migrated_from_chat_id)
        buffer += Int::write(migrated_from_chat_id.value());

    if (migrated_from_max_id)
        buffer += Int::write(migrated_from_max_id.value());

    if (pinned_msg_id)
        buffer += Int::write(pinned_msg_id.value());

    if (stickerset)
        buffer += stickerset.value().write();

    if (available_min_id)
        buffer += Int::write(available_min_id.value());

    if (folder_id)
        buffer += Int::write(folder_id.value());

    if (linked_chat_id)
        buffer += Int::write(linked_chat_id.value());

    if (location)
        buffer += location.value().write();

    if (slowmode_seconds)
        buffer += Int::write(slowmode_seconds.value());

    if (slowmode_next_send_date)
        buffer += Int::write(slowmode_next_send_date.value());

    if (stats_dc)
        buffer += Int::write(stats_dc.value());
    buffer += Int::write(pts);

    if (call)
        buffer += call.value().write();

    if (ttl_period)
        buffer += Int::write(ttl_period.value());

    if (pending_suggestions)
        buffer += Vector<std::string>::write(pending_suggestions.value());

    if (groupcall_default_join_as)
        buffer += groupcall_default_join_as.value().write();
    return buffer;
}

ChatParticipant::ChatParticipant(int user_id_, int inviter_id_, int date_) {}

ChatParticipant ChatParticipant::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int inviter_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return ChatParticipant(user_id_, inviter_id_, date_);
}

std::string ChatParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(inviter_id);
    buffer += Int::write(date);
    return buffer;
}

ChatParticipantCreator::ChatParticipantCreator(int user_id_) {}

ChatParticipantCreator ChatParticipantCreator::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    return ChatParticipantCreator(user_id_);
}

std::string ChatParticipantCreator::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    return buffer;
}

ChatParticipantAdmin::ChatParticipantAdmin(int user_id_, int inviter_id_, int date_) {}

ChatParticipantAdmin ChatParticipantAdmin::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int inviter_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return ChatParticipantAdmin(user_id_, inviter_id_, date_);
}

std::string ChatParticipantAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(inviter_id);
    buffer += Int::write(date);
    return buffer;
}

ChatParticipantsForbidden::ChatParticipantsForbidden(int chat_id_, std::optional<TLObject> self_participant_) {}

ChatParticipantsForbidden ChatParticipantsForbidden::read(Reader reader)
{
    int flags = Int::read(reader);
    int chat_id_ = Int::read(reader);
    std::optional<TLObject> self_participant_;
    self_participant_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return ChatParticipantsForbidden(chat_id_, self_participant_);
}

std::string ChatParticipantsForbidden::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= self_participant ? 1 << 0 : 0;
    buffer += Int::write(chat_id);

    if (self_participant)
        buffer += self_participant.value().write();
    return buffer;
}

ChatParticipants::ChatParticipants(int chat_id_, std::vector<TLObject> participants_, int version_) {}

ChatParticipants ChatParticipants::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    std::vector<TLObject> participants_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int version_ = Int::read(reader);
    return ChatParticipants(chat_id_, participants_, version_);
}

std::string ChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Vector<TLObject>::write(participants);
    buffer += Int::write(version);
    return buffer;
}
ChatPhotoEmpty ChatPhotoEmpty::read(Reader reader)
{
    return ChatPhotoEmpty();
}

std::string ChatPhotoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChatPhoto::ChatPhoto(long photo_id_, int dc_id_, std::optional<bool> has_video_, std::optional<std::string> stripped_thumb_) {}

ChatPhoto ChatPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> has_video_;
    has_video_ = (1 << 0) ? std::optional{true} : std::nullopt;
    long photo_id_ = Long::read(reader);
    std::optional<std::string> stripped_thumb_;
    stripped_thumb_ = (1 << 1) ? std::optional{Bytes::read(reader)} : std::nullopt;
    int dc_id_ = Int::read(reader);
    return ChatPhoto(photo_id_, dc_id_, has_video_, stripped_thumb_);
}

std::string ChatPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= has_video ? 1 << 0 : 0;
    flags |= stripped_thumb ? 1 << 1 : 0;
    buffer += Long::write(photo_id);

    if (stripped_thumb)
        buffer += Bytes::write(stripped_thumb.value());
    buffer += Int::write(dc_id);
    return buffer;
}

MessageEmpty::MessageEmpty(int id_, std::optional<TLObject> peer_id_) {}

MessageEmpty MessageEmpty::read(Reader reader)
{
    int flags = Int::read(reader);
    int id_ = Int::read(reader);
    std::optional<TLObject> peer_id_;
    peer_id_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return MessageEmpty(id_, peer_id_);
}

std::string MessageEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= peer_id ? 1 << 0 : 0;
    buffer += Int::write(id);

    if (peer_id)
        buffer += peer_id.value().write();
    return buffer;
}

Message::Message(int id_, TLObject peer_id_, int date_, std::string message_, std::optional<bool> out_, std::optional<bool> mentioned_, std::optional<bool> media_unread_, std::optional<bool> silent_, std::optional<bool> post_, std::optional<bool> from_scheduled_, std::optional<bool> legacy_, std::optional<bool> edit_hide_, std::optional<bool> pinned_, std::optional<TLObject> from_id_, std::optional<TLObject> fwd_from_, std::optional<int> via_bot_id_, std::optional<TLObject> reply_to_, std::optional<TLObject> media_, std::optional<TLObject> reply_markup_, std::optional<std::vector<TLObject>> entities_, std::optional<int> views_, std::optional<int> forwards_, std::optional<TLObject> replies_, std::optional<int> edit_date_, std::optional<std::string> post_author_, std::optional<long> grouped_id_, std::optional<std::vector<TLObject>> restriction_reason_, std::optional<int> ttl_period_) {}

Message Message::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> out_;
    out_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> mentioned_;
    mentioned_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> media_unread_;
    media_unread_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 13) ? std::optional{true} : std::nullopt;
    std::optional<bool> post_;
    post_ = (1 << 14) ? std::optional{true} : std::nullopt;
    std::optional<bool> from_scheduled_;
    from_scheduled_ = (1 << 18) ? std::optional{true} : std::nullopt;
    std::optional<bool> legacy_;
    legacy_ = (1 << 19) ? std::optional{true} : std::nullopt;
    std::optional<bool> edit_hide_;
    edit_hide_ = (1 << 21) ? std::optional{true} : std::nullopt;
    std::optional<bool> pinned_;
    pinned_ = (1 << 24) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::optional<TLObject> from_id_;
    from_id_ = (1 << 8) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject peer_id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> fwd_from_;
    fwd_from_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> via_bot_id_;
    via_bot_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> reply_to_;
    reply_to_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    int date_ = Int::read(reader);
    std::string message_ = String::read(reader);
    std::optional<TLObject> media_;
    media_ = (1 << 9) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 6) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 7) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> views_;
    views_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> forwards_;
    forwards_ = (1 << 10) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> replies_;
    replies_ = (1 << 23) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> edit_date_;
    edit_date_ = (1 << 15) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> post_author_;
    post_author_ = (1 << 16) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<long> grouped_id_;
    grouped_id_ = (1 << 17) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> restriction_reason_;
    restriction_reason_ = (1 << 22) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 25) ? std::optional{Int::read(reader)} : std::nullopt;
    return Message(id_, peer_id_, date_, message_, out_, mentioned_, media_unread_, silent_, post_, from_scheduled_, legacy_, edit_hide_, pinned_, from_id_, fwd_from_, via_bot_id_, reply_to_, media_, reply_markup_, entities_, views_, forwards_, replies_, edit_date_, post_author_, grouped_id_, restriction_reason_, ttl_period_);
}

std::string Message::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= out ? 1 << 1 : 0;
    flags |= mentioned ? 1 << 4 : 0;
    flags |= media_unread ? 1 << 5 : 0;
    flags |= silent ? 1 << 13 : 0;
    flags |= post ? 1 << 14 : 0;
    flags |= from_scheduled ? 1 << 18 : 0;
    flags |= legacy ? 1 << 19 : 0;
    flags |= edit_hide ? 1 << 21 : 0;
    flags |= pinned ? 1 << 24 : 0;
    flags |= from_id ? 1 << 8 : 0;
    flags |= fwd_from ? 1 << 2 : 0;
    flags |= via_bot_id ? 1 << 11 : 0;
    flags |= reply_to ? 1 << 3 : 0;
    flags |= media ? 1 << 9 : 0;
    flags |= reply_markup ? 1 << 6 : 0;
    flags |= entities ? 1 << 7 : 0;
    flags |= views ? 1 << 10 : 0;
    flags |= forwards ? 1 << 10 : 0;
    flags |= replies ? 1 << 23 : 0;
    flags |= edit_date ? 1 << 15 : 0;
    flags |= post_author ? 1 << 16 : 0;
    flags |= grouped_id ? 1 << 17 : 0;
    flags |= restriction_reason ? 1 << 22 : 0;
    flags |= ttl_period ? 1 << 25 : 0;
    buffer += Int::write(id);

    if (from_id)
        buffer += from_id.value().write();
    buffer += peer_id.write();

    if (fwd_from)
        buffer += fwd_from.value().write();

    if (via_bot_id)
        buffer += Int::write(via_bot_id.value());

    if (reply_to)
        buffer += reply_to.value().write();
    buffer += Int::write(date);
    buffer += String::write(message);

    if (media)
        buffer += media.value().write();

    if (reply_markup)
        buffer += reply_markup.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (views)
        buffer += Int::write(views.value());

    if (forwards)
        buffer += Int::write(forwards.value());

    if (replies)
        buffer += replies.value().write();

    if (edit_date)
        buffer += Int::write(edit_date.value());

    if (post_author)
        buffer += String::write(post_author.value());

    if (grouped_id)
        buffer += Long::write(grouped_id.value());

    if (restriction_reason)
        buffer += Vector<TLObject>::write(restriction_reason.value());

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

MessageService::MessageService(int id_, TLObject peer_id_, int date_, TLObject action_, std::optional<bool> out_, std::optional<bool> mentioned_, std::optional<bool> media_unread_, std::optional<bool> silent_, std::optional<bool> post_, std::optional<bool> legacy_, std::optional<TLObject> from_id_, std::optional<TLObject> reply_to_, std::optional<int> ttl_period_) {}

MessageService MessageService::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> out_;
    out_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> mentioned_;
    mentioned_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> media_unread_;
    media_unread_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 13) ? std::optional{true} : std::nullopt;
    std::optional<bool> post_;
    post_ = (1 << 14) ? std::optional{true} : std::nullopt;
    std::optional<bool> legacy_;
    legacy_ = (1 << 19) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::optional<TLObject> from_id_;
    from_id_ = (1 << 8) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject peer_id_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> reply_to_;
    reply_to_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    int date_ = Int::read(reader);
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 25) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageService(id_, peer_id_, date_, action_, out_, mentioned_, media_unread_, silent_, post_, legacy_, from_id_, reply_to_, ttl_period_);
}

std::string MessageService::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= out ? 1 << 1 : 0;
    flags |= mentioned ? 1 << 4 : 0;
    flags |= media_unread ? 1 << 5 : 0;
    flags |= silent ? 1 << 13 : 0;
    flags |= post ? 1 << 14 : 0;
    flags |= legacy ? 1 << 19 : 0;
    flags |= from_id ? 1 << 8 : 0;
    flags |= reply_to ? 1 << 3 : 0;
    flags |= ttl_period ? 1 << 25 : 0;
    buffer += Int::write(id);

    if (from_id)
        buffer += from_id.value().write();
    buffer += peer_id.write();

    if (reply_to)
        buffer += reply_to.value().write();
    buffer += Int::write(date);
    buffer += action.write();

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}
MessageMediaEmpty MessageMediaEmpty::read(Reader reader)
{
    return MessageMediaEmpty();
}

std::string MessageMediaEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageMediaPhoto::MessageMediaPhoto(std::optional<TLObject> photo_, std::optional<int> ttl_seconds_) {}

MessageMediaPhoto MessageMediaPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageMediaPhoto(photo_, ttl_seconds_);
}

std::string MessageMediaPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= ttl_seconds ? 1 << 2 : 0;

    if (photo)
        buffer += photo.value().write();

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

MessageMediaGeo::MessageMediaGeo(TLObject geo_) {}

MessageMediaGeo MessageMediaGeo::read(Reader reader)
{
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    return MessageMediaGeo(geo_);
}

std::string MessageMediaGeo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo.write();
    return buffer;
}

MessageMediaContact::MessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, int user_id_) {}

MessageMediaContact MessageMediaContact::read(Reader reader)
{
    std::string phone_number_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string vcard_ = String::read(reader);
    int user_id_ = Int::read(reader);
    return MessageMediaContact(phone_number_, first_name_, last_name_, vcard_, user_id_);
}

std::string MessageMediaContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_number);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(vcard);
    buffer += Int::write(user_id);
    return buffer;
}
MessageMediaUnsupported MessageMediaUnsupported::read(Reader reader)
{
    return MessageMediaUnsupported();
}

std::string MessageMediaUnsupported::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageMediaDocument::MessageMediaDocument(std::optional<TLObject> document_, std::optional<int> ttl_seconds_) {}

MessageMediaDocument MessageMediaDocument::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> document_;
    document_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_seconds_;
    ttl_seconds_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageMediaDocument(document_, ttl_seconds_);
}

std::string MessageMediaDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= document ? 1 << 0 : 0;
    flags |= ttl_seconds ? 1 << 2 : 0;

    if (document)
        buffer += document.value().write();

    if (ttl_seconds)
        buffer += Int::write(ttl_seconds.value());
    return buffer;
}

MessageMediaWebPage::MessageMediaWebPage(TLObject webpage_) {}

MessageMediaWebPage MessageMediaWebPage::read(Reader reader)
{
    TLObject webpage_ = std::get<TLObject>(TLObject::read(reader));
    return MessageMediaWebPage(webpage_);
}

std::string MessageMediaWebPage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += webpage.write();
    return buffer;
}

MessageMediaVenue::MessageMediaVenue(TLObject geo_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_) {}

MessageMediaVenue MessageMediaVenue::read(Reader reader)
{
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    std::string address_ = String::read(reader);
    std::string provider_ = String::read(reader);
    std::string venue_id_ = String::read(reader);
    std::string venue_type_ = String::read(reader);
    return MessageMediaVenue(geo_, title_, address_, provider_, venue_id_, venue_type_);
}

std::string MessageMediaVenue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo.write();
    buffer += String::write(title);
    buffer += String::write(address);
    buffer += String::write(provider);
    buffer += String::write(venue_id);
    buffer += String::write(venue_type);
    return buffer;
}

MessageMediaGame::MessageMediaGame(TLObject game_) {}

MessageMediaGame MessageMediaGame::read(Reader reader)
{
    TLObject game_ = std::get<TLObject>(TLObject::read(reader));
    return MessageMediaGame(game_);
}

std::string MessageMediaGame::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += game.write();
    return buffer;
}

MessageMediaInvoice::MessageMediaInvoice(std::string title_, std::string description_, std::string currency_, long total_amount_, std::string start_param_, std::optional<bool> shipping_address_requested_, std::optional<bool> test_, std::optional<TLObject> photo_, std::optional<int> receipt_msg_id_) {}

MessageMediaInvoice MessageMediaInvoice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> shipping_address_requested_;
    shipping_address_requested_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> test_;
    test_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> receipt_msg_id_;
    receipt_msg_id_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    std::string start_param_ = String::read(reader);
    return MessageMediaInvoice(title_, description_, currency_, total_amount_, start_param_, shipping_address_requested_, test_, photo_, receipt_msg_id_);
}

std::string MessageMediaInvoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= shipping_address_requested ? 1 << 1 : 0;
    flags |= test ? 1 << 3 : 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= receipt_msg_id ? 1 << 2 : 0;
    buffer += String::write(title);
    buffer += String::write(description);

    if (photo)
        buffer += photo.value().write();

    if (receipt_msg_id)
        buffer += Int::write(receipt_msg_id.value());
    buffer += String::write(currency);
    buffer += Long::write(total_amount);
    buffer += String::write(start_param);
    return buffer;
}

MessageMediaGeoLive::MessageMediaGeoLive(TLObject geo_, int period_, std::optional<int> heading_, std::optional<int> proximity_notification_radius_) {}

MessageMediaGeoLive MessageMediaGeoLive::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> heading_;
    heading_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    int period_ = Int::read(reader);
    std::optional<int> proximity_notification_radius_;
    proximity_notification_radius_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageMediaGeoLive(geo_, period_, heading_, proximity_notification_radius_);
}

std::string MessageMediaGeoLive::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= heading ? 1 << 0 : 0;
    flags |= proximity_notification_radius ? 1 << 1 : 0;
    buffer += geo.write();

    if (heading)
        buffer += Int::write(heading.value());
    buffer += Int::write(period);

    if (proximity_notification_radius)
        buffer += Int::write(proximity_notification_radius.value());
    return buffer;
}

MessageMediaPoll::MessageMediaPoll(TLObject poll_, TLObject results_) {}

MessageMediaPoll MessageMediaPoll::read(Reader reader)
{
    TLObject poll_ = std::get<TLObject>(TLObject::read(reader));
    TLObject results_ = std::get<TLObject>(TLObject::read(reader));
    return MessageMediaPoll(poll_, results_);
}

std::string MessageMediaPoll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += poll.write();
    buffer += results.write();
    return buffer;
}

MessageMediaDice::MessageMediaDice(int value_, std::string emoticon_) {}

MessageMediaDice MessageMediaDice::read(Reader reader)
{
    int value_ = Int::read(reader);
    std::string emoticon_ = String::read(reader);
    return MessageMediaDice(value_, emoticon_);
}

std::string MessageMediaDice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(value);
    buffer += String::write(emoticon);
    return buffer;
}
MessageActionEmpty MessageActionEmpty::read(Reader reader)
{
    return MessageActionEmpty();
}

std::string MessageActionEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageActionChatCreate::MessageActionChatCreate(std::string title_, std::vector<int> users_) {}

MessageActionChatCreate MessageActionChatCreate::read(Reader reader)
{
    std::string title_ = String::read(reader);
    std::vector<int> users_ = std::get<std::vector<int>>(TLObject::read(reader));
    return MessageActionChatCreate(title_, users_);
}

std::string MessageActionChatCreate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    buffer += Vector<int>::write(users);
    return buffer;
}

MessageActionChatEditTitle::MessageActionChatEditTitle(std::string title_) {}

MessageActionChatEditTitle MessageActionChatEditTitle::read(Reader reader)
{
    std::string title_ = String::read(reader);
    return MessageActionChatEditTitle(title_);
}

std::string MessageActionChatEditTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    return buffer;
}

MessageActionChatEditPhoto::MessageActionChatEditPhoto(TLObject photo_) {}

MessageActionChatEditPhoto MessageActionChatEditPhoto::read(Reader reader)
{
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    return MessageActionChatEditPhoto(photo_);
}

std::string MessageActionChatEditPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += photo.write();
    return buffer;
}
MessageActionChatDeletePhoto MessageActionChatDeletePhoto::read(Reader reader)
{
    return MessageActionChatDeletePhoto();
}

std::string MessageActionChatDeletePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageActionChatAddUser::MessageActionChatAddUser(std::vector<int> users_) {}

MessageActionChatAddUser MessageActionChatAddUser::read(Reader reader)
{
    std::vector<int> users_ = std::get<std::vector<int>>(TLObject::read(reader));
    return MessageActionChatAddUser(users_);
}

std::string MessageActionChatAddUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(users);
    return buffer;
}

MessageActionChatDeleteUser::MessageActionChatDeleteUser(int user_id_) {}

MessageActionChatDeleteUser MessageActionChatDeleteUser::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    return MessageActionChatDeleteUser(user_id_);
}

std::string MessageActionChatDeleteUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    return buffer;
}

MessageActionChatJoinedByLink::MessageActionChatJoinedByLink(int inviter_id_) {}

MessageActionChatJoinedByLink MessageActionChatJoinedByLink::read(Reader reader)
{
    int inviter_id_ = Int::read(reader);
    return MessageActionChatJoinedByLink(inviter_id_);
}

std::string MessageActionChatJoinedByLink::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(inviter_id);
    return buffer;
}

MessageActionChannelCreate::MessageActionChannelCreate(std::string title_) {}

MessageActionChannelCreate MessageActionChannelCreate::read(Reader reader)
{
    std::string title_ = String::read(reader);
    return MessageActionChannelCreate(title_);
}

std::string MessageActionChannelCreate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    return buffer;
}

MessageActionChatMigrateTo::MessageActionChatMigrateTo(int channel_id_) {}

MessageActionChatMigrateTo MessageActionChatMigrateTo::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    return MessageActionChatMigrateTo(channel_id_);
}

std::string MessageActionChatMigrateTo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    return buffer;
}

MessageActionChannelMigrateFrom::MessageActionChannelMigrateFrom(std::string title_, int chat_id_) {}

MessageActionChannelMigrateFrom MessageActionChannelMigrateFrom::read(Reader reader)
{
    std::string title_ = String::read(reader);
    int chat_id_ = Int::read(reader);
    return MessageActionChannelMigrateFrom(title_, chat_id_);
}

std::string MessageActionChannelMigrateFrom::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    buffer += Int::write(chat_id);
    return buffer;
}
MessageActionPinMessage MessageActionPinMessage::read(Reader reader)
{
    return MessageActionPinMessage();
}

std::string MessageActionPinMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
MessageActionHistoryClear MessageActionHistoryClear::read(Reader reader)
{
    return MessageActionHistoryClear();
}

std::string MessageActionHistoryClear::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageActionGameScore::MessageActionGameScore(long game_id_, int score_) {}

MessageActionGameScore MessageActionGameScore::read(Reader reader)
{
    long game_id_ = Long::read(reader);
    int score_ = Int::read(reader);
    return MessageActionGameScore(game_id_, score_);
}

std::string MessageActionGameScore::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(game_id);
    buffer += Int::write(score);
    return buffer;
}

MessageActionPaymentSentMe::MessageActionPaymentSentMe(std::string currency_, long total_amount_, std::string payload_, TLObject charge_, std::optional<TLObject> info_, std::optional<std::string> shipping_option_id_) {}

MessageActionPaymentSentMe MessageActionPaymentSentMe::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    std::string payload_ = Bytes::read(reader);
    std::optional<TLObject> info_;
    info_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> shipping_option_id_;
    shipping_option_id_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject charge_ = std::get<TLObject>(TLObject::read(reader));
    return MessageActionPaymentSentMe(currency_, total_amount_, payload_, charge_, info_, shipping_option_id_);
}

std::string MessageActionPaymentSentMe::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= info ? 1 << 0 : 0;
    flags |= shipping_option_id ? 1 << 1 : 0;
    buffer += String::write(currency);
    buffer += Long::write(total_amount);
    buffer += Bytes::write(payload);

    if (info)
        buffer += info.value().write();

    if (shipping_option_id)
        buffer += String::write(shipping_option_id.value());
    buffer += charge.write();
    return buffer;
}

MessageActionPaymentSent::MessageActionPaymentSent(std::string currency_, long total_amount_) {}

MessageActionPaymentSent MessageActionPaymentSent::read(Reader reader)
{
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    return MessageActionPaymentSent(currency_, total_amount_);
}

std::string MessageActionPaymentSent::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(currency);
    buffer += Long::write(total_amount);
    return buffer;
}

MessageActionPhoneCall::MessageActionPhoneCall(long call_id_, std::optional<bool> video_, std::optional<TLObject> reason_, std::optional<int> duration_) {}

MessageActionPhoneCall MessageActionPhoneCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 2) ? std::optional{true} : std::nullopt;
    long call_id_ = Long::read(reader);
    std::optional<TLObject> reason_;
    reason_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> duration_;
    duration_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageActionPhoneCall(call_id_, video_, reason_, duration_);
}

std::string MessageActionPhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 2 : 0;
    flags |= reason ? 1 << 0 : 0;
    flags |= duration ? 1 << 1 : 0;
    buffer += Long::write(call_id);

    if (reason)
        buffer += reason.value().write();

    if (duration)
        buffer += Int::write(duration.value());
    return buffer;
}
MessageActionScreenshotTaken MessageActionScreenshotTaken::read(Reader reader)
{
    return MessageActionScreenshotTaken();
}

std::string MessageActionScreenshotTaken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageActionCustomAction::MessageActionCustomAction(std::string message_) {}

MessageActionCustomAction MessageActionCustomAction::read(Reader reader)
{
    std::string message_ = String::read(reader);
    return MessageActionCustomAction(message_);
}

std::string MessageActionCustomAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(message);
    return buffer;
}

MessageActionBotAllowed::MessageActionBotAllowed(std::string domain_) {}

MessageActionBotAllowed MessageActionBotAllowed::read(Reader reader)
{
    std::string domain_ = String::read(reader);
    return MessageActionBotAllowed(domain_);
}

std::string MessageActionBotAllowed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(domain);
    return buffer;
}

MessageActionSecureValuesSentMe::MessageActionSecureValuesSentMe(std::vector<TLObject> values_, TLObject credentials_) {}

MessageActionSecureValuesSentMe MessageActionSecureValuesSentMe::read(Reader reader)
{
    std::vector<TLObject> values_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject credentials_ = std::get<TLObject>(TLObject::read(reader));
    return MessageActionSecureValuesSentMe(values_, credentials_);
}

std::string MessageActionSecureValuesSentMe::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(values);
    buffer += credentials.write();
    return buffer;
}

MessageActionSecureValuesSent::MessageActionSecureValuesSent(std::vector<TLObject> types_) {}

MessageActionSecureValuesSent MessageActionSecureValuesSent::read(Reader reader)
{
    std::vector<TLObject> types_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return MessageActionSecureValuesSent(types_);
}

std::string MessageActionSecureValuesSent::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}
MessageActionContactSignUp MessageActionContactSignUp::read(Reader reader)
{
    return MessageActionContactSignUp();
}

std::string MessageActionContactSignUp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

MessageActionGeoProximityReached::MessageActionGeoProximityReached(TLObject from_id_, TLObject to_id_, int distance_) {}

MessageActionGeoProximityReached MessageActionGeoProximityReached::read(Reader reader)
{
    TLObject from_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject to_id_ = std::get<TLObject>(TLObject::read(reader));
    int distance_ = Int::read(reader);
    return MessageActionGeoProximityReached(from_id_, to_id_, distance_);
}

std::string MessageActionGeoProximityReached::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += from_id.write();
    buffer += to_id.write();
    buffer += Int::write(distance);
    return buffer;
}

MessageActionGroupCall::MessageActionGroupCall(TLObject call_, std::optional<int> duration_) {}

MessageActionGroupCall MessageActionGroupCall::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> duration_;
    duration_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageActionGroupCall(call_, duration_);
}

std::string MessageActionGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= duration ? 1 << 0 : 0;
    buffer += call.write();

    if (duration)
        buffer += Int::write(duration.value());
    return buffer;
}

MessageActionInviteToGroupCall::MessageActionInviteToGroupCall(TLObject call_, std::vector<int> users_) {}

MessageActionInviteToGroupCall MessageActionInviteToGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> users_ = std::get<std::vector<int>>(TLObject::read(reader));
    return MessageActionInviteToGroupCall(call_, users_);
}

std::string MessageActionInviteToGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<int>::write(users);
    return buffer;
}

MessageActionSetMessagesTTL::MessageActionSetMessagesTTL(int period_) {}

MessageActionSetMessagesTTL MessageActionSetMessagesTTL::read(Reader reader)
{
    int period_ = Int::read(reader);
    return MessageActionSetMessagesTTL(period_);
}

std::string MessageActionSetMessagesTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(period);
    return buffer;
}

MessageActionGroupCallScheduled::MessageActionGroupCallScheduled(TLObject call_, int schedule_date_) {}

MessageActionGroupCallScheduled MessageActionGroupCallScheduled::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    int schedule_date_ = Int::read(reader);
    return MessageActionGroupCallScheduled(call_, schedule_date_);
}

std::string MessageActionGroupCallScheduled::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Int::write(schedule_date);
    return buffer;
}

Dialog::Dialog(TLObject peer_, int top_message_, int read_inbox_max_id_, int read_outbox_max_id_, int unread_count_, int unread_mentions_count_, TLObject notify_settings_, std::optional<bool> pinned_, std::optional<bool> unread_mark_, std::optional<int> pts_, std::optional<TLObject> draft_, std::optional<int> folder_id_) {}

Dialog Dialog::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> unread_mark_;
    unread_mark_ = (1 << 3) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int top_message_ = Int::read(reader);
    int read_inbox_max_id_ = Int::read(reader);
    int read_outbox_max_id_ = Int::read(reader);
    int unread_count_ = Int::read(reader);
    int unread_mentions_count_ = Int::read(reader);
    TLObject notify_settings_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> pts_;
    pts_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> draft_;
    draft_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> folder_id_;
    folder_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    return Dialog(peer_, top_message_, read_inbox_max_id_, read_outbox_max_id_, unread_count_, unread_mentions_count_, notify_settings_, pinned_, unread_mark_, pts_, draft_, folder_id_);
}

std::string Dialog::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 2 : 0;
    flags |= unread_mark ? 1 << 3 : 0;
    flags |= pts ? 1 << 0 : 0;
    flags |= draft ? 1 << 1 : 0;
    flags |= folder_id ? 1 << 4 : 0;
    buffer += peer.write();
    buffer += Int::write(top_message);
    buffer += Int::write(read_inbox_max_id);
    buffer += Int::write(read_outbox_max_id);
    buffer += Int::write(unread_count);
    buffer += Int::write(unread_mentions_count);
    buffer += notify_settings.write();

    if (pts)
        buffer += Int::write(pts.value());

    if (draft)
        buffer += draft.value().write();

    if (folder_id)
        buffer += Int::write(folder_id.value());
    return buffer;
}

DialogFolder::DialogFolder(TLObject folder_, TLObject peer_, int top_message_, int unread_muted_peers_count_, int unread_unmuted_peers_count_, int unread_muted_messages_count_, int unread_unmuted_messages_count_, std::optional<bool> pinned_) {}

DialogFolder DialogFolder::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject folder_ = std::get<TLObject>(TLObject::read(reader));
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int top_message_ = Int::read(reader);
    int unread_muted_peers_count_ = Int::read(reader);
    int unread_unmuted_peers_count_ = Int::read(reader);
    int unread_muted_messages_count_ = Int::read(reader);
    int unread_unmuted_messages_count_ = Int::read(reader);
    return DialogFolder(folder_, peer_, top_message_, unread_muted_peers_count_, unread_unmuted_peers_count_, unread_muted_messages_count_, unread_unmuted_messages_count_, pinned_);
}

std::string DialogFolder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 2 : 0;
    buffer += folder.write();
    buffer += peer.write();
    buffer += Int::write(top_message);
    buffer += Int::write(unread_muted_peers_count);
    buffer += Int::write(unread_unmuted_peers_count);
    buffer += Int::write(unread_muted_messages_count);
    buffer += Int::write(unread_unmuted_messages_count);
    return buffer;
}

PhotoEmpty::PhotoEmpty(long id_) {}

PhotoEmpty PhotoEmpty::read(Reader reader)
{
    long id_ = Long::read(reader);
    return PhotoEmpty(id_);
}

std::string PhotoEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

Photo::Photo(long id_, long access_hash_, std::string file_reference_, int date_, std::vector<TLObject> sizes_, int dc_id_, std::optional<bool> has_stickers_, std::optional<std::vector<TLObject>> video_sizes_) {}

Photo Photo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> has_stickers_;
    has_stickers_ = (1 << 0) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    int date_ = Int::read(reader);
    std::vector<TLObject> sizes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<std::vector<TLObject>> video_sizes_;
    video_sizes_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    int dc_id_ = Int::read(reader);
    return Photo(id_, access_hash_, file_reference_, date_, sizes_, dc_id_, has_stickers_, video_sizes_);
}

std::string Photo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= has_stickers ? 1 << 0 : 0;
    flags |= video_sizes ? 1 << 1 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    buffer += Int::write(date);
    buffer += Vector<TLObject>::write(sizes);

    if (video_sizes)
        buffer += Vector<TLObject>::write(video_sizes.value());
    buffer += Int::write(dc_id);
    return buffer;
}

PhotoSizeEmpty::PhotoSizeEmpty(std::string type_) {}

PhotoSizeEmpty PhotoSizeEmpty::read(Reader reader)
{
    std::string type_ = String::read(reader);
    return PhotoSizeEmpty(type_);
}

std::string PhotoSizeEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    return buffer;
}

PhotoSize::PhotoSize(std::string type_, int w_, int h_, int size_) {}

PhotoSize PhotoSize::read(Reader reader)
{
    std::string type_ = String::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    int size_ = Int::read(reader);
    return PhotoSize(type_, w_, h_, size_);
}

std::string PhotoSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += Int::write(size);
    return buffer;
}

PhotoCachedSize::PhotoCachedSize(std::string type_, int w_, int h_, std::string bytes_) {}

PhotoCachedSize PhotoCachedSize::read(Reader reader)
{
    std::string type_ = String::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return PhotoCachedSize(type_, w_, h_, bytes_);
}

std::string PhotoCachedSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += Bytes::write(bytes);
    return buffer;
}

PhotoStrippedSize::PhotoStrippedSize(std::string type_, std::string bytes_) {}

PhotoStrippedSize PhotoStrippedSize::read(Reader reader)
{
    std::string type_ = String::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return PhotoStrippedSize(type_, bytes_);
}

std::string PhotoStrippedSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    buffer += Bytes::write(bytes);
    return buffer;
}

PhotoSizeProgressive::PhotoSizeProgressive(std::string type_, int w_, int h_, std::vector<int> sizes_) {}

PhotoSizeProgressive PhotoSizeProgressive::read(Reader reader)
{
    std::string type_ = String::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    std::vector<int> sizes_ = std::get<std::vector<int>>(TLObject::read(reader));
    return PhotoSizeProgressive(type_, w_, h_, sizes_);
}

std::string PhotoSizeProgressive::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += Vector<int>::write(sizes);
    return buffer;
}

PhotoPathSize::PhotoPathSize(std::string type_, std::string bytes_) {}

PhotoPathSize PhotoPathSize::read(Reader reader)
{
    std::string type_ = String::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return PhotoPathSize(type_, bytes_);
}

std::string PhotoPathSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(type);
    buffer += Bytes::write(bytes);
    return buffer;
}
GeoPointEmpty GeoPointEmpty::read(Reader reader)
{
    return GeoPointEmpty();
}

std::string GeoPointEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GeoPoint::GeoPoint(double long__, double lat_, long access_hash_, std::optional<int> accuracy_radius_) {}

GeoPoint GeoPoint::read(Reader reader)
{
    int flags = Int::read(reader);
    double long__ = Double::read(reader);
    double lat_ = Double::read(reader);
    long access_hash_ = Long::read(reader);
    std::optional<int> accuracy_radius_;
    accuracy_radius_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return GeoPoint(long__, lat_, access_hash_, accuracy_radius_);
}

std::string GeoPoint::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= accuracy_radius ? 1 << 0 : 0;
    buffer += Double::write(long_);
    buffer += Double::write(lat);
    buffer += Long::write(access_hash);

    if (accuracy_radius)
        buffer += Int::write(accuracy_radius.value());
    return buffer;
}

InputNotifyPeer::InputNotifyPeer(TLObject peer_) {}

InputNotifyPeer InputNotifyPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return InputNotifyPeer(peer_);
}

std::string InputNotifyPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
InputNotifyUsers InputNotifyUsers::read(Reader reader)
{
    return InputNotifyUsers();
}

std::string InputNotifyUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputNotifyChats InputNotifyChats::read(Reader reader)
{
    return InputNotifyChats();
}

std::string InputNotifyChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputNotifyBroadcasts InputNotifyBroadcasts::read(Reader reader)
{
    return InputNotifyBroadcasts();
}

std::string InputNotifyBroadcasts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPeerNotifySettings::InputPeerNotifySettings(std::optional<bool> show_previews_, std::optional<bool> silent_, std::optional<int> mute_until_, std::optional<std::string> sound_) {}

InputPeerNotifySettings InputPeerNotifySettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> show_previews_;
    show_previews_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<int> mute_until_;
    mute_until_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> sound_;
    sound_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    return InputPeerNotifySettings(show_previews_, silent_, mute_until_, sound_);
}

std::string InputPeerNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= show_previews ? 1 << 0 : 0;
    flags |= silent ? 1 << 1 : 0;
    flags |= mute_until ? 1 << 2 : 0;
    flags |= sound ? 1 << 3 : 0;

    if (mute_until)
        buffer += Int::write(mute_until.value());

    if (sound)
        buffer += String::write(sound.value());
    return buffer;
}

PeerNotifySettings::PeerNotifySettings(std::optional<bool> show_previews_, std::optional<bool> silent_, std::optional<int> mute_until_, std::optional<std::string> sound_) {}

PeerNotifySettings PeerNotifySettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> show_previews_;
    show_previews_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<int> mute_until_;
    mute_until_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> sound_;
    sound_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    return PeerNotifySettings(show_previews_, silent_, mute_until_, sound_);
}

std::string PeerNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= show_previews ? 1 << 0 : 0;
    flags |= silent ? 1 << 1 : 0;
    flags |= mute_until ? 1 << 2 : 0;
    flags |= sound ? 1 << 3 : 0;

    if (mute_until)
        buffer += Int::write(mute_until.value());

    if (sound)
        buffer += String::write(sound.value());
    return buffer;
}

PeerSettings::PeerSettings(std::optional<bool> report_spam_, std::optional<bool> add_contact_, std::optional<bool> block_contact_, std::optional<bool> share_contact_, std::optional<bool> need_contacts_exception_, std::optional<bool> report_geo_, std::optional<bool> autoarchived_, std::optional<bool> invite_members_, std::optional<int> geo_distance_) {}

PeerSettings PeerSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> report_spam_;
    report_spam_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> add_contact_;
    add_contact_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> block_contact_;
    block_contact_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> share_contact_;
    share_contact_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> need_contacts_exception_;
    need_contacts_exception_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> report_geo_;
    report_geo_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> autoarchived_;
    autoarchived_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> invite_members_;
    invite_members_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<int> geo_distance_;
    geo_distance_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    return PeerSettings(report_spam_, add_contact_, block_contact_, share_contact_, need_contacts_exception_, report_geo_, autoarchived_, invite_members_, geo_distance_);
}

std::string PeerSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= report_spam ? 1 << 0 : 0;
    flags |= add_contact ? 1 << 1 : 0;
    flags |= block_contact ? 1 << 2 : 0;
    flags |= share_contact ? 1 << 3 : 0;
    flags |= need_contacts_exception ? 1 << 4 : 0;
    flags |= report_geo ? 1 << 5 : 0;
    flags |= autoarchived ? 1 << 7 : 0;
    flags |= invite_members ? 1 << 8 : 0;
    flags |= geo_distance ? 1 << 6 : 0;

    if (geo_distance)
        buffer += Int::write(geo_distance.value());
    return buffer;
}

WallPaper::WallPaper(long id_, long access_hash_, std::string slug_, TLObject document_, std::optional<bool> creator_, std::optional<bool> default__, std::optional<bool> pattern_, std::optional<bool> dark_, std::optional<TLObject> settings_) {}

WallPaper WallPaper::read(Reader reader)
{
    long id_ = Long::read(reader);
    int flags = Int::read(reader);
    std::optional<bool> creator_;
    creator_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> default__;
    default__ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> pattern_;
    pattern_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> dark_;
    dark_ = (1 << 4) ? std::optional{true} : std::nullopt;
    long access_hash_ = Long::read(reader);
    std::string slug_ = String::read(reader);
    TLObject document_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> settings_;
    settings_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return WallPaper(id_, access_hash_, slug_, document_, creator_, default__, pattern_, dark_, settings_);
}

std::string WallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= creator ? 1 << 0 : 0;
    flags |= default_ ? 1 << 1 : 0;
    flags |= pattern ? 1 << 3 : 0;
    flags |= dark ? 1 << 4 : 0;
    flags |= settings ? 1 << 2 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += String::write(slug);
    buffer += document.write();

    if (settings)
        buffer += settings.value().write();
    return buffer;
}

WallPaperNoFile::WallPaperNoFile(long id_, std::optional<bool> default__, std::optional<bool> dark_, std::optional<TLObject> settings_) {}

WallPaperNoFile WallPaperNoFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    int flags = Int::read(reader);
    std::optional<bool> default__;
    default__ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> dark_;
    dark_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> settings_;
    settings_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return WallPaperNoFile(id_, default__, dark_, settings_);
}

std::string WallPaperNoFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= default_ ? 1 << 1 : 0;
    flags |= dark ? 1 << 4 : 0;
    flags |= settings ? 1 << 2 : 0;
    buffer += Long::write(id);

    if (settings)
        buffer += settings.value().write();
    return buffer;
}
InputReportReasonSpam InputReportReasonSpam::read(Reader reader)
{
    return InputReportReasonSpam();
}

std::string InputReportReasonSpam::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonViolence InputReportReasonViolence::read(Reader reader)
{
    return InputReportReasonViolence();
}

std::string InputReportReasonViolence::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonPornography InputReportReasonPornography::read(Reader reader)
{
    return InputReportReasonPornography();
}

std::string InputReportReasonPornography::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonChildAbuse InputReportReasonChildAbuse::read(Reader reader)
{
    return InputReportReasonChildAbuse();
}

std::string InputReportReasonChildAbuse::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonOther InputReportReasonOther::read(Reader reader)
{
    return InputReportReasonOther();
}

std::string InputReportReasonOther::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonCopyright InputReportReasonCopyright::read(Reader reader)
{
    return InputReportReasonCopyright();
}

std::string InputReportReasonCopyright::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonGeoIrrelevant InputReportReasonGeoIrrelevant::read(Reader reader)
{
    return InputReportReasonGeoIrrelevant();
}

std::string InputReportReasonGeoIrrelevant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputReportReasonFake InputReportReasonFake::read(Reader reader)
{
    return InputReportReasonFake();
}

std::string InputReportReasonFake::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UserFull::UserFull(TLObject user_, TLObject settings_, TLObject notify_settings_, int common_chats_count_, std::optional<bool> blocked_, std::optional<bool> phone_calls_available_, std::optional<bool> phone_calls_private_, std::optional<bool> can_pin_message_, std::optional<bool> has_scheduled_, std::optional<bool> video_calls_available_, std::optional<std::string> about_, std::optional<TLObject> profile_photo_, std::optional<TLObject> bot_info_, std::optional<int> pinned_msg_id_, std::optional<int> folder_id_, std::optional<int> ttl_period_) {}

UserFull UserFull::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> blocked_;
    blocked_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> phone_calls_available_;
    phone_calls_available_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> phone_calls_private_;
    phone_calls_private_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_pin_message_;
    can_pin_message_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> has_scheduled_;
    has_scheduled_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_calls_available_;
    video_calls_available_ = (1 << 13) ? std::optional{true} : std::nullopt;
    TLObject user_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> about_;
    about_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> profile_photo_;
    profile_photo_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject notify_settings_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> bot_info_;
    bot_info_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> pinned_msg_id_;
    pinned_msg_id_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    int common_chats_count_ = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 14) ? std::optional{Int::read(reader)} : std::nullopt;
    return UserFull(user_, settings_, notify_settings_, common_chats_count_, blocked_, phone_calls_available_, phone_calls_private_, can_pin_message_, has_scheduled_, video_calls_available_, about_, profile_photo_, bot_info_, pinned_msg_id_, folder_id_, ttl_period_);
}

std::string UserFull::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= blocked ? 1 << 0 : 0;
    flags |= phone_calls_available ? 1 << 4 : 0;
    flags |= phone_calls_private ? 1 << 5 : 0;
    flags |= can_pin_message ? 1 << 7 : 0;
    flags |= has_scheduled ? 1 << 12 : 0;
    flags |= video_calls_available ? 1 << 13 : 0;
    flags |= about ? 1 << 1 : 0;
    flags |= profile_photo ? 1 << 2 : 0;
    flags |= bot_info ? 1 << 3 : 0;
    flags |= pinned_msg_id ? 1 << 6 : 0;
    flags |= folder_id ? 1 << 11 : 0;
    flags |= ttl_period ? 1 << 14 : 0;
    buffer += user.write();

    if (about)
        buffer += String::write(about.value());
    buffer += settings.write();

    if (profile_photo)
        buffer += profile_photo.value().write();
    buffer += notify_settings.write();

    if (bot_info)
        buffer += bot_info.value().write();

    if (pinned_msg_id)
        buffer += Int::write(pinned_msg_id.value());
    buffer += Int::write(common_chats_count);

    if (folder_id)
        buffer += Int::write(folder_id.value());

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

Contact::Contact(int user_id_, bool mutual_) {}

Contact Contact::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    bool mutual_ = Bool::read(reader);
    return Contact(user_id_, mutual_);
}

std::string Contact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Bool::write(mutual);
    return buffer;
}

ImportedContact::ImportedContact(int user_id_, long client_id_) {}

ImportedContact ImportedContact::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    long client_id_ = Long::read(reader);
    return ImportedContact(user_id_, client_id_);
}

std::string ImportedContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Long::write(client_id);
    return buffer;
}

ContactStatus::ContactStatus(int user_id_, TLObject status_) {}

ContactStatus ContactStatus::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    TLObject status_ = std::get<TLObject>(TLObject::read(reader));
    return ContactStatus(user_id_, status_);
}

std::string ContactStatus::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += status.write();
    return buffer;
}
InputMessagesFilterEmpty InputMessagesFilterEmpty::read(Reader reader)
{
    return InputMessagesFilterEmpty();
}

std::string InputMessagesFilterEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterPhotos InputMessagesFilterPhotos::read(Reader reader)
{
    return InputMessagesFilterPhotos();
}

std::string InputMessagesFilterPhotos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterVideo InputMessagesFilterVideo::read(Reader reader)
{
    return InputMessagesFilterVideo();
}

std::string InputMessagesFilterVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterPhotoVideo InputMessagesFilterPhotoVideo::read(Reader reader)
{
    return InputMessagesFilterPhotoVideo();
}

std::string InputMessagesFilterPhotoVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterDocument InputMessagesFilterDocument::read(Reader reader)
{
    return InputMessagesFilterDocument();
}

std::string InputMessagesFilterDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterUrl InputMessagesFilterUrl::read(Reader reader)
{
    return InputMessagesFilterUrl();
}

std::string InputMessagesFilterUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterGif InputMessagesFilterGif::read(Reader reader)
{
    return InputMessagesFilterGif();
}

std::string InputMessagesFilterGif::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterVoice InputMessagesFilterVoice::read(Reader reader)
{
    return InputMessagesFilterVoice();
}

std::string InputMessagesFilterVoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterMusic InputMessagesFilterMusic::read(Reader reader)
{
    return InputMessagesFilterMusic();
}

std::string InputMessagesFilterMusic::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterChatPhotos InputMessagesFilterChatPhotos::read(Reader reader)
{
    return InputMessagesFilterChatPhotos();
}

std::string InputMessagesFilterChatPhotos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputMessagesFilterPhoneCalls::InputMessagesFilterPhoneCalls(std::optional<bool> missed_) {}

InputMessagesFilterPhoneCalls InputMessagesFilterPhoneCalls::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> missed_;
    missed_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return InputMessagesFilterPhoneCalls(missed_);
}

std::string InputMessagesFilterPhoneCalls::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= missed ? 1 << 0 : 0;
    return buffer;
}
InputMessagesFilterRoundVoice InputMessagesFilterRoundVoice::read(Reader reader)
{
    return InputMessagesFilterRoundVoice();
}

std::string InputMessagesFilterRoundVoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterRoundVideo InputMessagesFilterRoundVideo::read(Reader reader)
{
    return InputMessagesFilterRoundVideo();
}

std::string InputMessagesFilterRoundVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterMyMentions InputMessagesFilterMyMentions::read(Reader reader)
{
    return InputMessagesFilterMyMentions();
}

std::string InputMessagesFilterMyMentions::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterGeo InputMessagesFilterGeo::read(Reader reader)
{
    return InputMessagesFilterGeo();
}

std::string InputMessagesFilterGeo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterContacts InputMessagesFilterContacts::read(Reader reader)
{
    return InputMessagesFilterContacts();
}

std::string InputMessagesFilterContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputMessagesFilterPinned InputMessagesFilterPinned::read(Reader reader)
{
    return InputMessagesFilterPinned();
}

std::string InputMessagesFilterPinned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateNewMessage::UpdateNewMessage(TLObject message_, int pts_, int pts_count_) {}

UpdateNewMessage UpdateNewMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateNewMessage(message_, pts_, pts_count_);
}

std::string UpdateNewMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateMessageID::UpdateMessageID(int id_, long random_id_) {}

UpdateMessageID UpdateMessageID::read(Reader reader)
{
    int id_ = Int::read(reader);
    long random_id_ = Long::read(reader);
    return UpdateMessageID(id_, random_id_);
}

std::string UpdateMessageID::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Long::write(random_id);
    return buffer;
}

UpdateDeleteMessages::UpdateDeleteMessages(std::vector<int> messages_, int pts_, int pts_count_) {}

UpdateDeleteMessages UpdateDeleteMessages::read(Reader reader)
{
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateDeleteMessages(messages_, pts_, pts_count_);
}

std::string UpdateDeleteMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(messages);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateUserTyping::UpdateUserTyping(int user_id_, TLObject action_) {}

UpdateUserTyping UpdateUserTyping::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateUserTyping(user_id_, action_);
}

std::string UpdateUserTyping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += action.write();
    return buffer;
}

UpdateChatUserTyping::UpdateChatUserTyping(int chat_id_, TLObject from_id_, TLObject action_) {}

UpdateChatUserTyping UpdateChatUserTyping::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject from_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateChatUserTyping(chat_id_, from_id_, action_);
}

std::string UpdateChatUserTyping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += from_id.write();
    buffer += action.write();
    return buffer;
}

UpdateChatParticipants::UpdateChatParticipants(TLObject participants_) {}

UpdateChatParticipants UpdateChatParticipants::read(Reader reader)
{
    TLObject participants_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateChatParticipants(participants_);
}

std::string UpdateChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participants.write();
    return buffer;
}

UpdateUserStatus::UpdateUserStatus(int user_id_, TLObject status_) {}

UpdateUserStatus UpdateUserStatus::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    TLObject status_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateUserStatus(user_id_, status_);
}

std::string UpdateUserStatus::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += status.write();
    return buffer;
}

UpdateUserName::UpdateUserName(int user_id_, std::string first_name_, std::string last_name_, std::string username_) {}

UpdateUserName UpdateUserName::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string username_ = String::read(reader);
    return UpdateUserName(user_id_, first_name_, last_name_, username_);
}

std::string UpdateUserName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(username);
    return buffer;
}

UpdateUserPhoto::UpdateUserPhoto(int user_id_, int date_, TLObject photo_, bool previous_) {}

UpdateUserPhoto UpdateUserPhoto::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    bool previous_ = Bool::read(reader);
    return UpdateUserPhoto(user_id_, date_, photo_, previous_);
}

std::string UpdateUserPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(date);
    buffer += photo.write();
    buffer += Bool::write(previous);
    return buffer;
}

UpdateNewEncryptedMessage::UpdateNewEncryptedMessage(TLObject message_, int qts_) {}

UpdateNewEncryptedMessage UpdateNewEncryptedMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    int qts_ = Int::read(reader);
    return UpdateNewEncryptedMessage(message_, qts_);
}

std::string UpdateNewEncryptedMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    buffer += Int::write(qts);
    return buffer;
}

UpdateEncryptedChatTyping::UpdateEncryptedChatTyping(int chat_id_) {}

UpdateEncryptedChatTyping UpdateEncryptedChatTyping::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return UpdateEncryptedChatTyping(chat_id_);
}

std::string UpdateEncryptedChatTyping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

UpdateEncryption::UpdateEncryption(TLObject chat_, int date_) {}

UpdateEncryption UpdateEncryption::read(Reader reader)
{
    TLObject chat_ = std::get<TLObject>(TLObject::read(reader));
    int date_ = Int::read(reader);
    return UpdateEncryption(chat_, date_);
}

std::string UpdateEncryption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += chat.write();
    buffer += Int::write(date);
    return buffer;
}

UpdateEncryptedMessagesRead::UpdateEncryptedMessagesRead(int chat_id_, int max_date_, int date_) {}

UpdateEncryptedMessagesRead UpdateEncryptedMessagesRead::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    int date_ = Int::read(reader);
    return UpdateEncryptedMessagesRead(chat_id_, max_date_, date_);
}

std::string UpdateEncryptedMessagesRead::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Int::write(max_date);
    buffer += Int::write(date);
    return buffer;
}

UpdateChatParticipantAdd::UpdateChatParticipantAdd(int chat_id_, int user_id_, int inviter_id_, int date_, int version_) {}

UpdateChatParticipantAdd UpdateChatParticipantAdd::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    int inviter_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    int version_ = Int::read(reader);
    return UpdateChatParticipantAdd(chat_id_, user_id_, inviter_id_, date_, version_);
}

std::string UpdateChatParticipantAdd::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Int::write(user_id);
    buffer += Int::write(inviter_id);
    buffer += Int::write(date);
    buffer += Int::write(version);
    return buffer;
}

UpdateChatParticipantDelete::UpdateChatParticipantDelete(int chat_id_, int user_id_, int version_) {}

UpdateChatParticipantDelete UpdateChatParticipantDelete::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    int version_ = Int::read(reader);
    return UpdateChatParticipantDelete(chat_id_, user_id_, version_);
}

std::string UpdateChatParticipantDelete::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Int::write(user_id);
    buffer += Int::write(version);
    return buffer;
}

UpdateDcOptions::UpdateDcOptions(std::vector<TLObject> dc_options_) {}

UpdateDcOptions UpdateDcOptions::read(Reader reader)
{
    std::vector<TLObject> dc_options_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return UpdateDcOptions(dc_options_);
}

std::string UpdateDcOptions::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(dc_options);
    return buffer;
}

UpdateNotifySettings::UpdateNotifySettings(TLObject peer_, TLObject notify_settings_) {}

UpdateNotifySettings UpdateNotifySettings::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject notify_settings_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateNotifySettings(peer_, notify_settings_);
}

std::string UpdateNotifySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += notify_settings.write();
    return buffer;
}

UpdateServiceNotification::UpdateServiceNotification(std::string type_, std::string message_, TLObject media_, std::vector<TLObject> entities_, std::optional<bool> popup_, std::optional<int> inbox_date_) {}

UpdateServiceNotification UpdateServiceNotification::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> popup_;
    popup_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<int> inbox_date_;
    inbox_date_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::string type_ = String::read(reader);
    std::string message_ = String::read(reader);
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> entities_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return UpdateServiceNotification(type_, message_, media_, entities_, popup_, inbox_date_);
}

std::string UpdateServiceNotification::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= popup ? 1 << 0 : 0;
    flags |= inbox_date ? 1 << 1 : 0;

    if (inbox_date)
        buffer += Int::write(inbox_date.value());
    buffer += String::write(type);
    buffer += String::write(message);
    buffer += media.write();
    buffer += Vector<TLObject>::write(entities);
    return buffer;
}

UpdatePrivacy::UpdatePrivacy(TLObject key_, std::vector<TLObject> rules_) {}

UpdatePrivacy UpdatePrivacy::read(Reader reader)
{
    TLObject key_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> rules_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return UpdatePrivacy(key_, rules_);
}

std::string UpdatePrivacy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += key.write();
    buffer += Vector<TLObject>::write(rules);
    return buffer;
}

UpdateUserPhone::UpdateUserPhone(int user_id_, std::string phone_) {}

UpdateUserPhone UpdateUserPhone::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    std::string phone_ = String::read(reader);
    return UpdateUserPhone(user_id_, phone_);
}

std::string UpdateUserPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += String::write(phone);
    return buffer;
}

UpdateReadHistoryInbox::UpdateReadHistoryInbox(TLObject peer_, int max_id_, int still_unread_count_, int pts_, int pts_count_, std::optional<int> folder_id_) {}

UpdateReadHistoryInbox UpdateReadHistoryInbox::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    int still_unread_count_ = Int::read(reader);
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateReadHistoryInbox(peer_, max_id_, still_unread_count_, pts_, pts_count_, folder_id_);
}

std::string UpdateReadHistoryInbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= folder_id ? 1 << 0 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += peer.write();
    buffer += Int::write(max_id);
    buffer += Int::write(still_unread_count);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateReadHistoryOutbox::UpdateReadHistoryOutbox(TLObject peer_, int max_id_, int pts_, int pts_count_) {}

UpdateReadHistoryOutbox UpdateReadHistoryOutbox::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int max_id_ = Int::read(reader);
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateReadHistoryOutbox(peer_, max_id_, pts_, pts_count_);
}

std::string UpdateReadHistoryOutbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(max_id);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateWebPage::UpdateWebPage(TLObject webpage_, int pts_, int pts_count_) {}

UpdateWebPage UpdateWebPage::read(Reader reader)
{
    TLObject webpage_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateWebPage(webpage_, pts_, pts_count_);
}

std::string UpdateWebPage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += webpage.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateReadMessagesContents::UpdateReadMessagesContents(std::vector<int> messages_, int pts_, int pts_count_) {}

UpdateReadMessagesContents UpdateReadMessagesContents::read(Reader reader)
{
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateReadMessagesContents(messages_, pts_, pts_count_);
}

std::string UpdateReadMessagesContents::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(messages);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateChannelTooLong::UpdateChannelTooLong(int channel_id_, std::optional<int> pts_) {}

UpdateChannelTooLong UpdateChannelTooLong::read(Reader reader)
{
    int flags = Int::read(reader);
    int channel_id_ = Int::read(reader);
    std::optional<int> pts_;
    pts_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdateChannelTooLong(channel_id_, pts_);
}

std::string UpdateChannelTooLong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pts ? 1 << 0 : 0;
    buffer += Int::write(channel_id);

    if (pts)
        buffer += Int::write(pts.value());
    return buffer;
}

UpdateChannel::UpdateChannel(int channel_id_) {}

UpdateChannel UpdateChannel::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    return UpdateChannel(channel_id_);
}

std::string UpdateChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    return buffer;
}

UpdateNewChannelMessage::UpdateNewChannelMessage(TLObject message_, int pts_, int pts_count_) {}

UpdateNewChannelMessage UpdateNewChannelMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateNewChannelMessage(message_, pts_, pts_count_);
}

std::string UpdateNewChannelMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateReadChannelInbox::UpdateReadChannelInbox(int channel_id_, int max_id_, int still_unread_count_, int pts_, std::optional<int> folder_id_) {}

UpdateReadChannelInbox UpdateReadChannelInbox::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    int channel_id_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    int still_unread_count_ = Int::read(reader);
    int pts_ = Int::read(reader);
    return UpdateReadChannelInbox(channel_id_, max_id_, still_unread_count_, pts_, folder_id_);
}

std::string UpdateReadChannelInbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= folder_id ? 1 << 0 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += Int::write(channel_id);
    buffer += Int::write(max_id);
    buffer += Int::write(still_unread_count);
    buffer += Int::write(pts);
    return buffer;
}

UpdateDeleteChannelMessages::UpdateDeleteChannelMessages(int channel_id_, std::vector<int> messages_, int pts_, int pts_count_) {}

UpdateDeleteChannelMessages UpdateDeleteChannelMessages::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateDeleteChannelMessages(channel_id_, messages_, pts_, pts_count_);
}

std::string UpdateDeleteChannelMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Vector<int>::write(messages);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateChannelMessageViews::UpdateChannelMessageViews(int channel_id_, int id_, int views_) {}

UpdateChannelMessageViews UpdateChannelMessageViews::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    int id_ = Int::read(reader);
    int views_ = Int::read(reader);
    return UpdateChannelMessageViews(channel_id_, id_, views_);
}

std::string UpdateChannelMessageViews::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Int::write(id);
    buffer += Int::write(views);
    return buffer;
}

UpdateChatParticipantAdmin::UpdateChatParticipantAdmin(int chat_id_, int user_id_, bool is_admin_, int version_) {}

UpdateChatParticipantAdmin UpdateChatParticipantAdmin::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    bool is_admin_ = Bool::read(reader);
    int version_ = Int::read(reader);
    return UpdateChatParticipantAdmin(chat_id_, user_id_, is_admin_, version_);
}

std::string UpdateChatParticipantAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Int::write(user_id);
    buffer += Bool::write(is_admin);
    buffer += Int::write(version);
    return buffer;
}

UpdateNewStickerSet::UpdateNewStickerSet(TLObject stickerset_) {}

UpdateNewStickerSet UpdateNewStickerSet::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateNewStickerSet(stickerset_);
}

std::string UpdateNewStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    return buffer;
}

UpdateStickerSetsOrder::UpdateStickerSetsOrder(std::vector<long> order_, std::optional<bool> masks_) {}

UpdateStickerSetsOrder UpdateStickerSetsOrder::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;
    masks_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::vector<long> order_ = std::get<std::vector<long>>(TLObject::read(reader));
    return UpdateStickerSetsOrder(order_, masks_);
}

std::string UpdateStickerSetsOrder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    buffer += Vector<long>::write(order);
    return buffer;
}
UpdateStickerSets UpdateStickerSets::read(Reader reader)
{
    return UpdateStickerSets();
}

std::string UpdateStickerSets::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UpdateSavedGifs UpdateSavedGifs::read(Reader reader)
{
    return UpdateSavedGifs();
}

std::string UpdateSavedGifs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateBotInlineQuery::UpdateBotInlineQuery(long query_id_, int user_id_, std::string query_, std::string offset_, std::optional<TLObject> geo_, std::optional<TLObject> peer_type_) {}

UpdateBotInlineQuery UpdateBotInlineQuery::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    std::string query_ = String::read(reader);
    std::optional<TLObject> geo_;
    geo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> peer_type_;
    peer_type_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string offset_ = String::read(reader);
    return UpdateBotInlineQuery(query_id_, user_id_, query_, offset_, geo_, peer_type_);
}

std::string UpdateBotInlineQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= geo ? 1 << 0 : 0;
    flags |= peer_type ? 1 << 1 : 0;
    buffer += Long::write(query_id);
    buffer += Int::write(user_id);
    buffer += String::write(query);

    if (geo)
        buffer += geo.value().write();

    if (peer_type)
        buffer += peer_type.value().write();
    buffer += String::write(offset);
    return buffer;
}

UpdateBotInlineSend::UpdateBotInlineSend(int user_id_, std::string query_, std::string id_, std::optional<TLObject> geo_, std::optional<TLObject> msg_id_) {}

UpdateBotInlineSend UpdateBotInlineSend::read(Reader reader)
{
    int flags = Int::read(reader);
    int user_id_ = Int::read(reader);
    std::string query_ = String::read(reader);
    std::optional<TLObject> geo_;
    geo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string id_ = String::read(reader);
    std::optional<TLObject> msg_id_;
    msg_id_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return UpdateBotInlineSend(user_id_, query_, id_, geo_, msg_id_);
}

std::string UpdateBotInlineSend::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= geo ? 1 << 0 : 0;
    flags |= msg_id ? 1 << 1 : 0;
    buffer += Int::write(user_id);
    buffer += String::write(query);

    if (geo)
        buffer += geo.value().write();
    buffer += String::write(id);

    if (msg_id)
        buffer += msg_id.value().write();
    return buffer;
}

UpdateEditChannelMessage::UpdateEditChannelMessage(TLObject message_, int pts_, int pts_count_) {}

UpdateEditChannelMessage UpdateEditChannelMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateEditChannelMessage(message_, pts_, pts_count_);
}

std::string UpdateEditChannelMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateBotCallbackQuery::UpdateBotCallbackQuery(long query_id_, int user_id_, TLObject peer_, int msg_id_, long chat_instance_, std::optional<std::string> data_, std::optional<std::string> game_short_name_) {}

UpdateBotCallbackQuery UpdateBotCallbackQuery::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    long chat_instance_ = Long::read(reader);
    std::optional<std::string> data_;
    data_ = (1 << 0) ? std::optional{Bytes::read(reader)} : std::nullopt;
    std::optional<std::string> game_short_name_;
    game_short_name_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    return UpdateBotCallbackQuery(query_id_, user_id_, peer_, msg_id_, chat_instance_, data_, game_short_name_);
}

std::string UpdateBotCallbackQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= data ? 1 << 0 : 0;
    flags |= game_short_name ? 1 << 1 : 0;
    buffer += Long::write(query_id);
    buffer += Int::write(user_id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Long::write(chat_instance);

    if (data)
        buffer += Bytes::write(data.value());

    if (game_short_name)
        buffer += String::write(game_short_name.value());
    return buffer;
}

UpdateEditMessage::UpdateEditMessage(TLObject message_, int pts_, int pts_count_) {}

UpdateEditMessage UpdateEditMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateEditMessage(message_, pts_, pts_count_);
}

std::string UpdateEditMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateInlineBotCallbackQuery::UpdateInlineBotCallbackQuery(long query_id_, int user_id_, TLObject msg_id_, long chat_instance_, std::optional<std::string> data_, std::optional<std::string> game_short_name_) {}

UpdateInlineBotCallbackQuery UpdateInlineBotCallbackQuery::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    TLObject msg_id_ = std::get<TLObject>(TLObject::read(reader));
    long chat_instance_ = Long::read(reader);
    std::optional<std::string> data_;
    data_ = (1 << 0) ? std::optional{Bytes::read(reader)} : std::nullopt;
    std::optional<std::string> game_short_name_;
    game_short_name_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    return UpdateInlineBotCallbackQuery(query_id_, user_id_, msg_id_, chat_instance_, data_, game_short_name_);
}

std::string UpdateInlineBotCallbackQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= data ? 1 << 0 : 0;
    flags |= game_short_name ? 1 << 1 : 0;
    buffer += Long::write(query_id);
    buffer += Int::write(user_id);
    buffer += msg_id.write();
    buffer += Long::write(chat_instance);

    if (data)
        buffer += Bytes::write(data.value());

    if (game_short_name)
        buffer += String::write(game_short_name.value());
    return buffer;
}

UpdateReadChannelOutbox::UpdateReadChannelOutbox(int channel_id_, int max_id_) {}

UpdateReadChannelOutbox UpdateReadChannelOutbox::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    return UpdateReadChannelOutbox(channel_id_, max_id_);
}

std::string UpdateReadChannelOutbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Int::write(max_id);
    return buffer;
}

UpdateDraftMessage::UpdateDraftMessage(TLObject peer_, TLObject draft_) {}

UpdateDraftMessage UpdateDraftMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject draft_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateDraftMessage(peer_, draft_);
}

std::string UpdateDraftMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += draft.write();
    return buffer;
}
UpdateReadFeaturedStickers UpdateReadFeaturedStickers::read(Reader reader)
{
    return UpdateReadFeaturedStickers();
}

std::string UpdateReadFeaturedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UpdateRecentStickers UpdateRecentStickers::read(Reader reader)
{
    return UpdateRecentStickers();
}

std::string UpdateRecentStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UpdateConfig UpdateConfig::read(Reader reader)
{
    return UpdateConfig();
}

std::string UpdateConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
UpdatePtsChanged UpdatePtsChanged::read(Reader reader)
{
    return UpdatePtsChanged();
}

std::string UpdatePtsChanged::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateChannelWebPage::UpdateChannelWebPage(int channel_id_, TLObject webpage_, int pts_, int pts_count_) {}

UpdateChannelWebPage UpdateChannelWebPage::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    TLObject webpage_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateChannelWebPage(channel_id_, webpage_, pts_, pts_count_);
}

std::string UpdateChannelWebPage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += webpage.write();
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateDialogPinned::UpdateDialogPinned(TLObject peer_, std::optional<bool> pinned_, std::optional<int> folder_id_) {}

UpdateDialogPinned UpdateDialogPinned::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<int> folder_id_;
    folder_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateDialogPinned(peer_, pinned_, folder_id_);
}

std::string UpdateDialogPinned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 0 : 0;
    flags |= folder_id ? 1 << 1 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += peer.write();
    return buffer;
}

UpdatePinnedDialogs::UpdatePinnedDialogs(std::optional<int> folder_id_, std::optional<std::vector<TLObject>> order_) {}

UpdatePinnedDialogs UpdatePinnedDialogs::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> order_;
    order_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return UpdatePinnedDialogs(folder_id_, order_);
}

std::string UpdatePinnedDialogs::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= folder_id ? 1 << 1 : 0;
    flags |= order ? 1 << 0 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());

    if (order)
        buffer += Vector<TLObject>::write(order.value());
    return buffer;
}

UpdateBotWebhookJSON::UpdateBotWebhookJSON(TLObject data_) {}

UpdateBotWebhookJSON UpdateBotWebhookJSON::read(Reader reader)
{
    TLObject data_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateBotWebhookJSON(data_);
}

std::string UpdateBotWebhookJSON::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += data.write();
    return buffer;
}

UpdateBotWebhookJSONQuery::UpdateBotWebhookJSONQuery(long query_id_, TLObject data_, int timeout_) {}

UpdateBotWebhookJSONQuery UpdateBotWebhookJSONQuery::read(Reader reader)
{
    long query_id_ = Long::read(reader);
    TLObject data_ = std::get<TLObject>(TLObject::read(reader));
    int timeout_ = Int::read(reader);
    return UpdateBotWebhookJSONQuery(query_id_, data_, timeout_);
}

std::string UpdateBotWebhookJSONQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(query_id);
    buffer += data.write();
    buffer += Int::write(timeout);
    return buffer;
}

UpdateBotShippingQuery::UpdateBotShippingQuery(long query_id_, int user_id_, std::string payload_, TLObject shipping_address_) {}

UpdateBotShippingQuery UpdateBotShippingQuery::read(Reader reader)
{
    long query_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    std::string payload_ = Bytes::read(reader);
    TLObject shipping_address_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateBotShippingQuery(query_id_, user_id_, payload_, shipping_address_);
}

std::string UpdateBotShippingQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(query_id);
    buffer += Int::write(user_id);
    buffer += Bytes::write(payload);
    buffer += shipping_address.write();
    return buffer;
}

UpdateBotPrecheckoutQuery::UpdateBotPrecheckoutQuery(long query_id_, int user_id_, std::string payload_, std::string currency_, long total_amount_, std::optional<TLObject> info_, std::optional<std::string> shipping_option_id_) {}

UpdateBotPrecheckoutQuery UpdateBotPrecheckoutQuery::read(Reader reader)
{
    int flags = Int::read(reader);
    long query_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    std::string payload_ = Bytes::read(reader);
    std::optional<TLObject> info_;
    info_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> shipping_option_id_;
    shipping_option_id_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    return UpdateBotPrecheckoutQuery(query_id_, user_id_, payload_, currency_, total_amount_, info_, shipping_option_id_);
}

std::string UpdateBotPrecheckoutQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= info ? 1 << 0 : 0;
    flags |= shipping_option_id ? 1 << 1 : 0;
    buffer += Long::write(query_id);
    buffer += Int::write(user_id);
    buffer += Bytes::write(payload);

    if (info)
        buffer += info.value().write();

    if (shipping_option_id)
        buffer += String::write(shipping_option_id.value());
    buffer += String::write(currency);
    buffer += Long::write(total_amount);
    return buffer;
}

UpdatePhoneCall::UpdatePhoneCall(TLObject phone_call_) {}

UpdatePhoneCall UpdatePhoneCall::read(Reader reader)
{
    TLObject phone_call_ = std::get<TLObject>(TLObject::read(reader));
    return UpdatePhoneCall(phone_call_);
}

std::string UpdatePhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += phone_call.write();
    return buffer;
}

UpdateLangPackTooLong::UpdateLangPackTooLong(std::string lang_code_) {}

UpdateLangPackTooLong UpdateLangPackTooLong::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return UpdateLangPackTooLong(lang_code_);
}

std::string UpdateLangPackTooLong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

UpdateLangPack::UpdateLangPack(TLObject difference_) {}

UpdateLangPack UpdateLangPack::read(Reader reader)
{
    TLObject difference_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateLangPack(difference_);
}

std::string UpdateLangPack::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += difference.write();
    return buffer;
}
UpdateFavedStickers UpdateFavedStickers::read(Reader reader)
{
    return UpdateFavedStickers();
}

std::string UpdateFavedStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateChannelReadMessagesContents::UpdateChannelReadMessagesContents(int channel_id_, std::vector<int> messages_) {}

UpdateChannelReadMessagesContents UpdateChannelReadMessagesContents::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    return UpdateChannelReadMessagesContents(channel_id_, messages_);
}

std::string UpdateChannelReadMessagesContents::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Vector<int>::write(messages);
    return buffer;
}
UpdateContactsReset UpdateContactsReset::read(Reader reader)
{
    return UpdateContactsReset();
}

std::string UpdateContactsReset::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateChannelAvailableMessages::UpdateChannelAvailableMessages(int channel_id_, int available_min_id_) {}

UpdateChannelAvailableMessages UpdateChannelAvailableMessages::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    int available_min_id_ = Int::read(reader);
    return UpdateChannelAvailableMessages(channel_id_, available_min_id_);
}

std::string UpdateChannelAvailableMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Int::write(available_min_id);
    return buffer;
}

UpdateDialogUnreadMark::UpdateDialogUnreadMark(TLObject peer_, std::optional<bool> unread_) {}

UpdateDialogUnreadMark UpdateDialogUnreadMark::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> unread_;
    unread_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateDialogUnreadMark(peer_, unread_);
}

std::string UpdateDialogUnreadMark::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= unread ? 1 << 0 : 0;
    buffer += peer.write();
    return buffer;
}

UpdateMessagePoll::UpdateMessagePoll(long poll_id_, TLObject results_, std::optional<TLObject> poll_) {}

UpdateMessagePoll UpdateMessagePoll::read(Reader reader)
{
    int flags = Int::read(reader);
    long poll_id_ = Long::read(reader);
    std::optional<TLObject> poll_;
    poll_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject results_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateMessagePoll(poll_id_, results_, poll_);
}

std::string UpdateMessagePoll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= poll ? 1 << 0 : 0;
    buffer += Long::write(poll_id);

    if (poll)
        buffer += poll.value().write();
    buffer += results.write();
    return buffer;
}

UpdateChatDefaultBannedRights::UpdateChatDefaultBannedRights(TLObject peer_, TLObject default_banned_rights_, int version_) {}

UpdateChatDefaultBannedRights UpdateChatDefaultBannedRights::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject default_banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    int version_ = Int::read(reader);
    return UpdateChatDefaultBannedRights(peer_, default_banned_rights_, version_);
}

std::string UpdateChatDefaultBannedRights::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += default_banned_rights.write();
    buffer += Int::write(version);
    return buffer;
}

UpdateFolderPeers::UpdateFolderPeers(std::vector<TLObject> folder_peers_, int pts_, int pts_count_) {}

UpdateFolderPeers UpdateFolderPeers::read(Reader reader)
{
    std::vector<TLObject> folder_peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdateFolderPeers(folder_peers_, pts_, pts_count_);
}

std::string UpdateFolderPeers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(folder_peers);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdatePeerSettings::UpdatePeerSettings(TLObject peer_, TLObject settings_) {}

UpdatePeerSettings UpdatePeerSettings::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject settings_ = std::get<TLObject>(TLObject::read(reader));
    return UpdatePeerSettings(peer_, settings_);
}

std::string UpdatePeerSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += settings.write();
    return buffer;
}

UpdatePeerLocated::UpdatePeerLocated(std::vector<TLObject> peers_) {}

UpdatePeerLocated UpdatePeerLocated::read(Reader reader)
{
    std::vector<TLObject> peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return UpdatePeerLocated(peers_);
}

std::string UpdatePeerLocated::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(peers);
    return buffer;
}

UpdateNewScheduledMessage::UpdateNewScheduledMessage(TLObject message_) {}

UpdateNewScheduledMessage UpdateNewScheduledMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateNewScheduledMessage(message_);
}

std::string UpdateNewScheduledMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    return buffer;
}

UpdateDeleteScheduledMessages::UpdateDeleteScheduledMessages(TLObject peer_, std::vector<int> messages_) {}

UpdateDeleteScheduledMessages UpdateDeleteScheduledMessages::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    return UpdateDeleteScheduledMessages(peer_, messages_);
}

std::string UpdateDeleteScheduledMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<int>::write(messages);
    return buffer;
}

UpdateTheme::UpdateTheme(TLObject theme_) {}

UpdateTheme UpdateTheme::read(Reader reader)
{
    TLObject theme_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateTheme(theme_);
}

std::string UpdateTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += theme.write();
    return buffer;
}

UpdateGeoLiveViewed::UpdateGeoLiveViewed(TLObject peer_, int msg_id_) {}

UpdateGeoLiveViewed UpdateGeoLiveViewed::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    return UpdateGeoLiveViewed(peer_, msg_id_);
}

std::string UpdateGeoLiveViewed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}
UpdateLoginToken UpdateLoginToken::read(Reader reader)
{
    return UpdateLoginToken();
}

std::string UpdateLoginToken::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateMessagePollVote::UpdateMessagePollVote(long poll_id_, int user_id_, std::vector<std::string> options_, int qts_) {}

UpdateMessagePollVote UpdateMessagePollVote::read(Reader reader)
{
    long poll_id_ = Long::read(reader);
    int user_id_ = Int::read(reader);
    std::vector<std::string> options_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    int qts_ = Int::read(reader);
    return UpdateMessagePollVote(poll_id_, user_id_, options_, qts_);
}

std::string UpdateMessagePollVote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(poll_id);
    buffer += Int::write(user_id);
    buffer += Vector<std::string>::write(options);
    buffer += Int::write(qts);
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

UpdateDialogFilterOrder::UpdateDialogFilterOrder(std::vector<int> order_) {}

UpdateDialogFilterOrder UpdateDialogFilterOrder::read(Reader reader)
{
    std::vector<int> order_ = std::get<std::vector<int>>(TLObject::read(reader));
    return UpdateDialogFilterOrder(order_);
}

std::string UpdateDialogFilterOrder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(order);
    return buffer;
}
UpdateDialogFilters UpdateDialogFilters::read(Reader reader)
{
    return UpdateDialogFilters();
}

std::string UpdateDialogFilters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdatePhoneCallSignalingData::UpdatePhoneCallSignalingData(long phone_call_id_, std::string data_) {}

UpdatePhoneCallSignalingData UpdatePhoneCallSignalingData::read(Reader reader)
{
    long phone_call_id_ = Long::read(reader);
    std::string data_ = Bytes::read(reader);
    return UpdatePhoneCallSignalingData(phone_call_id_, data_);
}

std::string UpdatePhoneCallSignalingData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(phone_call_id);
    buffer += Bytes::write(data);
    return buffer;
}

UpdateChannelMessageForwards::UpdateChannelMessageForwards(int channel_id_, int id_, int forwards_) {}

UpdateChannelMessageForwards UpdateChannelMessageForwards::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    int id_ = Int::read(reader);
    int forwards_ = Int::read(reader);
    return UpdateChannelMessageForwards(channel_id_, id_, forwards_);
}

std::string UpdateChannelMessageForwards::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Int::write(id);
    buffer += Int::write(forwards);
    return buffer;
}

UpdateReadChannelDiscussionInbox::UpdateReadChannelDiscussionInbox(int channel_id_, int top_msg_id_, int read_max_id_, std::optional<int> broadcast_id_, std::optional<int> broadcast_post_) {}

UpdateReadChannelDiscussionInbox UpdateReadChannelDiscussionInbox::read(Reader reader)
{
    int flags = Int::read(reader);
    int channel_id_ = Int::read(reader);
    int top_msg_id_ = Int::read(reader);
    int read_max_id_ = Int::read(reader);
    std::optional<int> broadcast_id_;
    broadcast_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> broadcast_post_;
    broadcast_post_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdateReadChannelDiscussionInbox(channel_id_, top_msg_id_, read_max_id_, broadcast_id_, broadcast_post_);
}

std::string UpdateReadChannelDiscussionInbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= broadcast_id ? 1 << 0 : 0;
    flags |= broadcast_post ? 1 << 0 : 0;
    buffer += Int::write(channel_id);
    buffer += Int::write(top_msg_id);
    buffer += Int::write(read_max_id);

    if (broadcast_id)
        buffer += Int::write(broadcast_id.value());

    if (broadcast_post)
        buffer += Int::write(broadcast_post.value());
    return buffer;
}

UpdateReadChannelDiscussionOutbox::UpdateReadChannelDiscussionOutbox(int channel_id_, int top_msg_id_, int read_max_id_) {}

UpdateReadChannelDiscussionOutbox UpdateReadChannelDiscussionOutbox::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    int top_msg_id_ = Int::read(reader);
    int read_max_id_ = Int::read(reader);
    return UpdateReadChannelDiscussionOutbox(channel_id_, top_msg_id_, read_max_id_);
}

std::string UpdateReadChannelDiscussionOutbox::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Int::write(top_msg_id);
    buffer += Int::write(read_max_id);
    return buffer;
}

UpdatePeerBlocked::UpdatePeerBlocked(TLObject peer_id_, bool blocked_) {}

UpdatePeerBlocked UpdatePeerBlocked::read(Reader reader)
{
    TLObject peer_id_ = std::get<TLObject>(TLObject::read(reader));
    bool blocked_ = Bool::read(reader);
    return UpdatePeerBlocked(peer_id_, blocked_);
}

std::string UpdatePeerBlocked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer_id.write();
    buffer += Bool::write(blocked);
    return buffer;
}

UpdateChannelUserTyping::UpdateChannelUserTyping(int channel_id_, TLObject from_id_, TLObject action_, std::optional<int> top_msg_id_) {}

UpdateChannelUserTyping UpdateChannelUserTyping::read(Reader reader)
{
    int flags = Int::read(reader);
    int channel_id_ = Int::read(reader);
    std::optional<int> top_msg_id_;
    top_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject from_id_ = std::get<TLObject>(TLObject::read(reader));
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateChannelUserTyping(channel_id_, from_id_, action_, top_msg_id_);
}

std::string UpdateChannelUserTyping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= top_msg_id ? 1 << 0 : 0;
    buffer += Int::write(channel_id);

    if (top_msg_id)
        buffer += Int::write(top_msg_id.value());
    buffer += from_id.write();
    buffer += action.write();
    return buffer;
}

UpdatePinnedMessages::UpdatePinnedMessages(TLObject peer_, std::vector<int> messages_, int pts_, int pts_count_, std::optional<bool> pinned_) {}

UpdatePinnedMessages UpdatePinnedMessages::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdatePinnedMessages(peer_, messages_, pts_, pts_count_, pinned_);
}

std::string UpdatePinnedMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Vector<int>::write(messages);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdatePinnedChannelMessages::UpdatePinnedChannelMessages(int channel_id_, std::vector<int> messages_, int pts_, int pts_count_, std::optional<bool> pinned_) {}

UpdatePinnedChannelMessages UpdatePinnedChannelMessages::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> pinned_;
    pinned_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int channel_id_ = Int::read(reader);
    std::vector<int> messages_ = std::get<std::vector<int>>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    return UpdatePinnedChannelMessages(channel_id_, messages_, pts_, pts_count_, pinned_);
}

std::string UpdatePinnedChannelMessages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pinned ? 1 << 0 : 0;
    buffer += Int::write(channel_id);
    buffer += Vector<int>::write(messages);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    return buffer;
}

UpdateChat::UpdateChat(int chat_id_) {}

UpdateChat UpdateChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    return UpdateChat(chat_id_);
}

std::string UpdateChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    return buffer;
}

UpdateGroupCallParticipants::UpdateGroupCallParticipants(TLObject call_, std::vector<TLObject> participants_, int version_) {}

UpdateGroupCallParticipants UpdateGroupCallParticipants::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> participants_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int version_ = Int::read(reader);
    return UpdateGroupCallParticipants(call_, participants_, version_);
}

std::string UpdateGroupCallParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    buffer += Vector<TLObject>::write(participants);
    buffer += Int::write(version);
    return buffer;
}

UpdateGroupCall::UpdateGroupCall(int chat_id_, TLObject call_) {}

UpdateGroupCall UpdateGroupCall::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateGroupCall(chat_id_, call_);
}

std::string UpdateGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += call.write();
    return buffer;
}

UpdatePeerHistoryTTL::UpdatePeerHistoryTTL(TLObject peer_, std::optional<int> ttl_period_) {}

UpdatePeerHistoryTTL UpdatePeerHistoryTTL::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdatePeerHistoryTTL(peer_, ttl_period_);
}

std::string UpdatePeerHistoryTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ttl_period ? 1 << 0 : 0;
    buffer += peer.write();

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

UpdateChatParticipant::UpdateChatParticipant(int chat_id_, int date_, int actor_id_, int user_id_, int qts_, std::optional<TLObject> prev_participant_, std::optional<TLObject> new_participant_, std::optional<TLObject> invite_) {}

UpdateChatParticipant UpdateChatParticipant::read(Reader reader)
{
    int flags = Int::read(reader);
    int chat_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    int actor_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    std::optional<TLObject> prev_participant_;
    prev_participant_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> new_participant_;
    new_participant_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> invite_;
    invite_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    int qts_ = Int::read(reader);
    return UpdateChatParticipant(chat_id_, date_, actor_id_, user_id_, qts_, prev_participant_, new_participant_, invite_);
}

std::string UpdateChatParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= prev_participant ? 1 << 0 : 0;
    flags |= new_participant ? 1 << 1 : 0;
    flags |= invite ? 1 << 2 : 0;
    buffer += Int::write(chat_id);
    buffer += Int::write(date);
    buffer += Int::write(actor_id);
    buffer += Int::write(user_id);

    if (prev_participant)
        buffer += prev_participant.value().write();

    if (new_participant)
        buffer += new_participant.value().write();

    if (invite)
        buffer += invite.value().write();
    buffer += Int::write(qts);
    return buffer;
}

UpdateChannelParticipant::UpdateChannelParticipant(int channel_id_, int date_, int actor_id_, int user_id_, int qts_, std::optional<TLObject> prev_participant_, std::optional<TLObject> new_participant_, std::optional<TLObject> invite_) {}

UpdateChannelParticipant UpdateChannelParticipant::read(Reader reader)
{
    int flags = Int::read(reader);
    int channel_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    int actor_id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    std::optional<TLObject> prev_participant_;
    prev_participant_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> new_participant_;
    new_participant_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> invite_;
    invite_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    int qts_ = Int::read(reader);
    return UpdateChannelParticipant(channel_id_, date_, actor_id_, user_id_, qts_, prev_participant_, new_participant_, invite_);
}

std::string UpdateChannelParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= prev_participant ? 1 << 0 : 0;
    flags |= new_participant ? 1 << 1 : 0;
    flags |= invite ? 1 << 2 : 0;
    buffer += Int::write(channel_id);
    buffer += Int::write(date);
    buffer += Int::write(actor_id);
    buffer += Int::write(user_id);

    if (prev_participant)
        buffer += prev_participant.value().write();

    if (new_participant)
        buffer += new_participant.value().write();

    if (invite)
        buffer += invite.value().write();
    buffer += Int::write(qts);
    return buffer;
}

UpdateBotStopped::UpdateBotStopped(int user_id_, int date_, bool stopped_, int qts_) {}

UpdateBotStopped UpdateBotStopped::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    bool stopped_ = Bool::read(reader);
    int qts_ = Int::read(reader);
    return UpdateBotStopped(user_id_, date_, stopped_, qts_);
}

std::string UpdateBotStopped::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(date);
    buffer += Bool::write(stopped);
    buffer += Int::write(qts);
    return buffer;
}

UpdateGroupCallConnection::UpdateGroupCallConnection(TLObject params_, std::optional<bool> presentation_) {}

UpdateGroupCallConnection UpdateGroupCallConnection::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> presentation_;
    presentation_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject params_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateGroupCallConnection(params_, presentation_);
}

std::string UpdateGroupCallConnection::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= presentation ? 1 << 0 : 0;
    buffer += params.write();
    return buffer;
}
UpdatesTooLong UpdatesTooLong::read(Reader reader)
{
    return UpdatesTooLong();
}

std::string UpdatesTooLong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

UpdateShortMessage::UpdateShortMessage(int id_, int user_id_, std::string message_, int pts_, int pts_count_, int date_, std::optional<bool> out_, std::optional<bool> mentioned_, std::optional<bool> media_unread_, std::optional<bool> silent_, std::optional<TLObject> fwd_from_, std::optional<int> via_bot_id_, std::optional<TLObject> reply_to_, std::optional<std::vector<TLObject>> entities_, std::optional<int> ttl_period_) {}

UpdateShortMessage UpdateShortMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> out_;
    out_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> mentioned_;
    mentioned_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> media_unread_;
    media_unread_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 13) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    std::string message_ = String::read(reader);
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::optional<TLObject> fwd_from_;
    fwd_from_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> via_bot_id_;
    via_bot_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> reply_to_;
    reply_to_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 7) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 25) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdateShortMessage(id_, user_id_, message_, pts_, pts_count_, date_, out_, mentioned_, media_unread_, silent_, fwd_from_, via_bot_id_, reply_to_, entities_, ttl_period_);
}

std::string UpdateShortMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= out ? 1 << 1 : 0;
    flags |= mentioned ? 1 << 4 : 0;
    flags |= media_unread ? 1 << 5 : 0;
    flags |= silent ? 1 << 13 : 0;
    flags |= fwd_from ? 1 << 2 : 0;
    flags |= via_bot_id ? 1 << 11 : 0;
    flags |= reply_to ? 1 << 3 : 0;
    flags |= entities ? 1 << 7 : 0;
    flags |= ttl_period ? 1 << 25 : 0;
    buffer += Int::write(id);
    buffer += Int::write(user_id);
    buffer += String::write(message);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    buffer += Int::write(date);

    if (fwd_from)
        buffer += fwd_from.value().write();

    if (via_bot_id)
        buffer += Int::write(via_bot_id.value());

    if (reply_to)
        buffer += reply_to.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

UpdateShortChatMessage::UpdateShortChatMessage(int id_, int from_id_, int chat_id_, std::string message_, int pts_, int pts_count_, int date_, std::optional<bool> out_, std::optional<bool> mentioned_, std::optional<bool> media_unread_, std::optional<bool> silent_, std::optional<TLObject> fwd_from_, std::optional<int> via_bot_id_, std::optional<TLObject> reply_to_, std::optional<std::vector<TLObject>> entities_, std::optional<int> ttl_period_) {}

UpdateShortChatMessage UpdateShortChatMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> out_;
    out_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> mentioned_;
    mentioned_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> media_unread_;
    media_unread_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> silent_;
    silent_ = (1 << 13) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    int from_id_ = Int::read(reader);
    int chat_id_ = Int::read(reader);
    std::string message_ = String::read(reader);
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::optional<TLObject> fwd_from_;
    fwd_from_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> via_bot_id_;
    via_bot_id_ = (1 << 11) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> reply_to_;
    reply_to_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 7) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 25) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdateShortChatMessage(id_, from_id_, chat_id_, message_, pts_, pts_count_, date_, out_, mentioned_, media_unread_, silent_, fwd_from_, via_bot_id_, reply_to_, entities_, ttl_period_);
}

std::string UpdateShortChatMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= out ? 1 << 1 : 0;
    flags |= mentioned ? 1 << 4 : 0;
    flags |= media_unread ? 1 << 5 : 0;
    flags |= silent ? 1 << 13 : 0;
    flags |= fwd_from ? 1 << 2 : 0;
    flags |= via_bot_id ? 1 << 11 : 0;
    flags |= reply_to ? 1 << 3 : 0;
    flags |= entities ? 1 << 7 : 0;
    flags |= ttl_period ? 1 << 25 : 0;
    buffer += Int::write(id);
    buffer += Int::write(from_id);
    buffer += Int::write(chat_id);
    buffer += String::write(message);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    buffer += Int::write(date);

    if (fwd_from)
        buffer += fwd_from.value().write();

    if (via_bot_id)
        buffer += Int::write(via_bot_id.value());

    if (reply_to)
        buffer += reply_to.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

UpdateShort::UpdateShort(TLObject update_, int date_) {}

UpdateShort UpdateShort::read(Reader reader)
{
    TLObject update_ = std::get<TLObject>(TLObject::read(reader));
    int date_ = Int::read(reader);
    return UpdateShort(update_, date_);
}

std::string UpdateShort::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += update.write();
    buffer += Int::write(date);
    return buffer;
}

UpdatesCombined::UpdatesCombined(std::vector<TLObject> updates_, std::vector<TLObject> users_, std::vector<TLObject> chats_, int date_, int seq_start_, int seq_) {}

UpdatesCombined UpdatesCombined::read(Reader reader)
{
    std::vector<TLObject> updates_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int date_ = Int::read(reader);
    int seq_start_ = Int::read(reader);
    int seq_ = Int::read(reader);
    return UpdatesCombined(updates_, users_, chats_, date_, seq_start_, seq_);
}

std::string UpdatesCombined::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(updates);
    buffer += Vector<TLObject>::write(users);
    buffer += Vector<TLObject>::write(chats);
    buffer += Int::write(date);
    buffer += Int::write(seq_start);
    buffer += Int::write(seq);
    return buffer;
}

Updates::Updates(std::vector<TLObject> updates_, std::vector<TLObject> users_, std::vector<TLObject> chats_, int date_, int seq_) {}

Updates Updates::read(Reader reader)
{
    std::vector<TLObject> updates_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int date_ = Int::read(reader);
    int seq_ = Int::read(reader);
    return Updates(updates_, users_, chats_, date_, seq_);
}

std::string Updates::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(updates);
    buffer += Vector<TLObject>::write(users);
    buffer += Vector<TLObject>::write(chats);
    buffer += Int::write(date);
    buffer += Int::write(seq);
    return buffer;
}

UpdateShortSentMessage::UpdateShortSentMessage(int id_, int pts_, int pts_count_, int date_, std::optional<bool> out_, std::optional<TLObject> media_, std::optional<std::vector<TLObject>> entities_, std::optional<int> ttl_period_) {}

UpdateShortSentMessage UpdateShortSentMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> out_;
    out_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    int pts_ = Int::read(reader);
    int pts_count_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::optional<TLObject> media_;
    media_ = (1 << 9) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 7) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> ttl_period_;
    ttl_period_ = (1 << 25) ? std::optional{Int::read(reader)} : std::nullopt;
    return UpdateShortSentMessage(id_, pts_, pts_count_, date_, out_, media_, entities_, ttl_period_);
}

std::string UpdateShortSentMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= out ? 1 << 1 : 0;
    flags |= media ? 1 << 9 : 0;
    flags |= entities ? 1 << 7 : 0;
    flags |= ttl_period ? 1 << 25 : 0;
    buffer += Int::write(id);
    buffer += Int::write(pts);
    buffer += Int::write(pts_count);
    buffer += Int::write(date);

    if (media)
        buffer += media.value().write();

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (ttl_period)
        buffer += Int::write(ttl_period.value());
    return buffer;
}

DcOption::DcOption(int id_, std::string ip_address_, int port_, std::optional<bool> ipv6_, std::optional<bool> media_only_, std::optional<bool> tcpo_only_, std::optional<bool> cdn_, std::optional<bool> static__, std::optional<std::string> secret_) {}

DcOption DcOption::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> ipv6_;
    ipv6_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> media_only_;
    media_only_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> tcpo_only_;
    tcpo_only_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> cdn_;
    cdn_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> static__;
    static__ = (1 << 4) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string ip_address_ = String::read(reader);
    int port_ = Int::read(reader);
    std::optional<std::string> secret_;
    secret_ = (1 << 10) ? std::optional{Bytes::read(reader)} : std::nullopt;
    return DcOption(id_, ip_address_, port_, ipv6_, media_only_, tcpo_only_, cdn_, static__, secret_);
}

std::string DcOption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= ipv6 ? 1 << 0 : 0;
    flags |= media_only ? 1 << 1 : 0;
    flags |= tcpo_only ? 1 << 2 : 0;
    flags |= cdn ? 1 << 3 : 0;
    flags |= static_ ? 1 << 4 : 0;
    flags |= secret ? 1 << 10 : 0;
    buffer += Int::write(id);
    buffer += String::write(ip_address);
    buffer += Int::write(port);

    if (secret)
        buffer += Bytes::write(secret.value());
    return buffer;
}

Config::Config(int date_, int expires_, bool test_mode_, int this_dc_, std::vector<TLObject> dc_options_, std::string dc_txt_domain_name_, int chat_size_max_, int megagroup_size_max_, int forwarded_count_max_, int online_update_period_ms_, int offline_blur_timeout_ms_, int offline_idle_timeout_ms_, int online_cloud_timeout_ms_, int notify_cloud_delay_ms_, int notify_default_delay_ms_, int push_chat_period_ms_, int push_chat_limit_, int saved_gifs_limit_, int edit_time_limit_, int revoke_time_limit_, int revoke_pm_time_limit_, int rating_e_decay_, int stickers_recent_limit_, int stickers_faved_limit_, int channels_read_media_period_, int pinned_dialogs_count_max_, int pinned_infolder_count_max_, int call_receive_timeout_ms_, int call_ring_timeout_ms_, int call_connect_timeout_ms_, int call_packet_timeout_ms_, std::string me_url_prefix_, int caption_length_max_, int message_length_max_, int webfile_dc_id_, std::optional<bool> phonecalls_enabled_, std::optional<bool> default_p2p_contacts_, std::optional<bool> preload_featured_stickers_, std::optional<bool> ignore_phone_entities_, std::optional<bool> revoke_pm_inbox_, std::optional<bool> blocked_mode_, std::optional<bool> pfs_enabled_, std::optional<int> tmp_sessions_, std::optional<std::string> autoupdate_url_prefix_, std::optional<std::string> gif_search_username_, std::optional<std::string> venue_search_username_, std::optional<std::string> img_search_username_, std::optional<std::string> static_maps_provider_, std::optional<std::string> suggested_lang_code_, std::optional<int> lang_pack_version_, std::optional<int> base_lang_pack_version_) {}

Config Config::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> phonecalls_enabled_;
    phonecalls_enabled_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> default_p2p_contacts_;
    default_p2p_contacts_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> preload_featured_stickers_;
    preload_featured_stickers_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> ignore_phone_entities_;
    ignore_phone_entities_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> revoke_pm_inbox_;
    revoke_pm_inbox_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> blocked_mode_;
    blocked_mode_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> pfs_enabled_;
    pfs_enabled_ = (1 << 13) ? std::optional{true} : std::nullopt;
    int date_ = Int::read(reader);
    int expires_ = Int::read(reader);
    bool test_mode_ = Bool::read(reader);
    int this_dc_ = Int::read(reader);
    std::vector<TLObject> dc_options_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::string dc_txt_domain_name_ = String::read(reader);
    int chat_size_max_ = Int::read(reader);
    int megagroup_size_max_ = Int::read(reader);
    int forwarded_count_max_ = Int::read(reader);
    int online_update_period_ms_ = Int::read(reader);
    int offline_blur_timeout_ms_ = Int::read(reader);
    int offline_idle_timeout_ms_ = Int::read(reader);
    int online_cloud_timeout_ms_ = Int::read(reader);
    int notify_cloud_delay_ms_ = Int::read(reader);
    int notify_default_delay_ms_ = Int::read(reader);
    int push_chat_period_ms_ = Int::read(reader);
    int push_chat_limit_ = Int::read(reader);
    int saved_gifs_limit_ = Int::read(reader);
    int edit_time_limit_ = Int::read(reader);
    int revoke_time_limit_ = Int::read(reader);
    int revoke_pm_time_limit_ = Int::read(reader);
    int rating_e_decay_ = Int::read(reader);
    int stickers_recent_limit_ = Int::read(reader);
    int stickers_faved_limit_ = Int::read(reader);
    int channels_read_media_period_ = Int::read(reader);
    std::optional<int> tmp_sessions_;
    tmp_sessions_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    int pinned_dialogs_count_max_ = Int::read(reader);
    int pinned_infolder_count_max_ = Int::read(reader);
    int call_receive_timeout_ms_ = Int::read(reader);
    int call_ring_timeout_ms_ = Int::read(reader);
    int call_connect_timeout_ms_ = Int::read(reader);
    int call_packet_timeout_ms_ = Int::read(reader);
    std::string me_url_prefix_ = String::read(reader);
    std::optional<std::string> autoupdate_url_prefix_;
    autoupdate_url_prefix_ = (1 << 7) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> gif_search_username_;
    gif_search_username_ = (1 << 9) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> venue_search_username_;
    venue_search_username_ = (1 << 10) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> img_search_username_;
    img_search_username_ = (1 << 11) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> static_maps_provider_;
    static_maps_provider_ = (1 << 12) ? std::optional{String::read(reader)} : std::nullopt;
    int caption_length_max_ = Int::read(reader);
    int message_length_max_ = Int::read(reader);
    int webfile_dc_id_ = Int::read(reader);
    std::optional<std::string> suggested_lang_code_;
    suggested_lang_code_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> lang_pack_version_;
    lang_pack_version_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> base_lang_pack_version_;
    base_lang_pack_version_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    return Config(date_, expires_, test_mode_, this_dc_, dc_options_, dc_txt_domain_name_, chat_size_max_, megagroup_size_max_, forwarded_count_max_, online_update_period_ms_, offline_blur_timeout_ms_, offline_idle_timeout_ms_, online_cloud_timeout_ms_, notify_cloud_delay_ms_, notify_default_delay_ms_, push_chat_period_ms_, push_chat_limit_, saved_gifs_limit_, edit_time_limit_, revoke_time_limit_, revoke_pm_time_limit_, rating_e_decay_, stickers_recent_limit_, stickers_faved_limit_, channels_read_media_period_, pinned_dialogs_count_max_, pinned_infolder_count_max_, call_receive_timeout_ms_, call_ring_timeout_ms_, call_connect_timeout_ms_, call_packet_timeout_ms_, me_url_prefix_, caption_length_max_, message_length_max_, webfile_dc_id_, phonecalls_enabled_, default_p2p_contacts_, preload_featured_stickers_, ignore_phone_entities_, revoke_pm_inbox_, blocked_mode_, pfs_enabled_, tmp_sessions_, autoupdate_url_prefix_, gif_search_username_, venue_search_username_, img_search_username_, static_maps_provider_, suggested_lang_code_, lang_pack_version_, base_lang_pack_version_);
}

std::string Config::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= phonecalls_enabled ? 1 << 1 : 0;
    flags |= default_p2p_contacts ? 1 << 3 : 0;
    flags |= preload_featured_stickers ? 1 << 4 : 0;
    flags |= ignore_phone_entities ? 1 << 5 : 0;
    flags |= revoke_pm_inbox ? 1 << 6 : 0;
    flags |= blocked_mode ? 1 << 8 : 0;
    flags |= pfs_enabled ? 1 << 13 : 0;
    flags |= tmp_sessions ? 1 << 0 : 0;
    flags |= autoupdate_url_prefix ? 1 << 7 : 0;
    flags |= gif_search_username ? 1 << 9 : 0;
    flags |= venue_search_username ? 1 << 10 : 0;
    flags |= img_search_username ? 1 << 11 : 0;
    flags |= static_maps_provider ? 1 << 12 : 0;
    flags |= suggested_lang_code ? 1 << 2 : 0;
    flags |= lang_pack_version ? 1 << 2 : 0;
    flags |= base_lang_pack_version ? 1 << 2 : 0;
    buffer += Int::write(date);
    buffer += Int::write(expires);
    buffer += Bool::write(test_mode);
    buffer += Int::write(this_dc);
    buffer += Vector<TLObject>::write(dc_options);
    buffer += String::write(dc_txt_domain_name);
    buffer += Int::write(chat_size_max);
    buffer += Int::write(megagroup_size_max);
    buffer += Int::write(forwarded_count_max);
    buffer += Int::write(online_update_period_ms);
    buffer += Int::write(offline_blur_timeout_ms);
    buffer += Int::write(offline_idle_timeout_ms);
    buffer += Int::write(online_cloud_timeout_ms);
    buffer += Int::write(notify_cloud_delay_ms);
    buffer += Int::write(notify_default_delay_ms);
    buffer += Int::write(push_chat_period_ms);
    buffer += Int::write(push_chat_limit);
    buffer += Int::write(saved_gifs_limit);
    buffer += Int::write(edit_time_limit);
    buffer += Int::write(revoke_time_limit);
    buffer += Int::write(revoke_pm_time_limit);
    buffer += Int::write(rating_e_decay);
    buffer += Int::write(stickers_recent_limit);
    buffer += Int::write(stickers_faved_limit);
    buffer += Int::write(channels_read_media_period);

    if (tmp_sessions)
        buffer += Int::write(tmp_sessions.value());
    buffer += Int::write(pinned_dialogs_count_max);
    buffer += Int::write(pinned_infolder_count_max);
    buffer += Int::write(call_receive_timeout_ms);
    buffer += Int::write(call_ring_timeout_ms);
    buffer += Int::write(call_connect_timeout_ms);
    buffer += Int::write(call_packet_timeout_ms);
    buffer += String::write(me_url_prefix);

    if (autoupdate_url_prefix)
        buffer += String::write(autoupdate_url_prefix.value());

    if (gif_search_username)
        buffer += String::write(gif_search_username.value());

    if (venue_search_username)
        buffer += String::write(venue_search_username.value());

    if (img_search_username)
        buffer += String::write(img_search_username.value());

    if (static_maps_provider)
        buffer += String::write(static_maps_provider.value());
    buffer += Int::write(caption_length_max);
    buffer += Int::write(message_length_max);
    buffer += Int::write(webfile_dc_id);

    if (suggested_lang_code)
        buffer += String::write(suggested_lang_code.value());

    if (lang_pack_version)
        buffer += Int::write(lang_pack_version.value());

    if (base_lang_pack_version)
        buffer += Int::write(base_lang_pack_version.value());
    return buffer;
}

NearestDc::NearestDc(std::string country_, int this_dc_, int nearest_dc_) {}

NearestDc NearestDc::read(Reader reader)
{
    std::string country_ = String::read(reader);
    int this_dc_ = Int::read(reader);
    int nearest_dc_ = Int::read(reader);
    return NearestDc(country_, this_dc_, nearest_dc_);
}

std::string NearestDc::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(country);
    buffer += Int::write(this_dc);
    buffer += Int::write(nearest_dc);
    return buffer;
}

EncryptedChatEmpty::EncryptedChatEmpty(int id_) {}

EncryptedChatEmpty EncryptedChatEmpty::read(Reader reader)
{
    int id_ = Int::read(reader);
    return EncryptedChatEmpty(id_);
}

std::string EncryptedChatEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    return buffer;
}

EncryptedChatWaiting::EncryptedChatWaiting(int id_, long access_hash_, int date_, int admin_id_, int participant_id_) {}

EncryptedChatWaiting EncryptedChatWaiting::read(Reader reader)
{
    int id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    return EncryptedChatWaiting(id_, access_hash_, date_, admin_id_, participant_id_);
}

std::string EncryptedChatWaiting::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    return buffer;
}

EncryptedChatRequested::EncryptedChatRequested(int id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_, std::optional<int> folder_id_) {}

EncryptedChatRequested EncryptedChatRequested::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> folder_id_;
    folder_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    int id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    std::string g_a_ = Bytes::read(reader);
    return EncryptedChatRequested(id_, access_hash_, date_, admin_id_, participant_id_, g_a_, folder_id_);
}

std::string EncryptedChatRequested::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= folder_id ? 1 << 0 : 0;

    if (folder_id)
        buffer += Int::write(folder_id.value());
    buffer += Int::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += Bytes::write(g_a);
    return buffer;
}

EncryptedChat::EncryptedChat(int id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_or_b_, long key_fingerprint_) {}

EncryptedChat EncryptedChat::read(Reader reader)
{
    int id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    std::string g_a_or_b_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    return EncryptedChat(id_, access_hash_, date_, admin_id_, participant_id_, g_a_or_b_, key_fingerprint_);
}

std::string EncryptedChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += Bytes::write(g_a_or_b);
    buffer += Long::write(key_fingerprint);
    return buffer;
}

EncryptedChatDiscarded::EncryptedChatDiscarded(int id_, std::optional<bool> history_deleted_) {}

EncryptedChatDiscarded EncryptedChatDiscarded::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> history_deleted_;
    history_deleted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    return EncryptedChatDiscarded(id_, history_deleted_);
}

std::string EncryptedChatDiscarded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= history_deleted ? 1 << 0 : 0;
    buffer += Int::write(id);
    return buffer;
}

InputEncryptedChat::InputEncryptedChat(int chat_id_, long access_hash_) {}

InputEncryptedChat InputEncryptedChat::read(Reader reader)
{
    int chat_id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    return InputEncryptedChat(chat_id_, access_hash_);
}

std::string InputEncryptedChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(chat_id);
    buffer += Long::write(access_hash);
    return buffer;
}
EncryptedFileEmpty EncryptedFileEmpty::read(Reader reader)
{
    return EncryptedFileEmpty();
}

std::string EncryptedFileEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

EncryptedFile::EncryptedFile(long id_, long access_hash_, int size_, int dc_id_, int key_fingerprint_) {}

EncryptedFile EncryptedFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int size_ = Int::read(reader);
    int dc_id_ = Int::read(reader);
    int key_fingerprint_ = Int::read(reader);
    return EncryptedFile(id_, access_hash_, size_, dc_id_, key_fingerprint_);
}

std::string EncryptedFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(size);
    buffer += Int::write(dc_id);
    buffer += Int::write(key_fingerprint);
    return buffer;
}
InputEncryptedFileEmpty InputEncryptedFileEmpty::read(Reader reader)
{
    return InputEncryptedFileEmpty();
}

std::string InputEncryptedFileEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputEncryptedFileUploaded::InputEncryptedFileUploaded(long id_, int parts_, std::string md5_checksum_, int key_fingerprint_) {}

InputEncryptedFileUploaded InputEncryptedFileUploaded::read(Reader reader)
{
    long id_ = Long::read(reader);
    int parts_ = Int::read(reader);
    std::string md5_checksum_ = String::read(reader);
    int key_fingerprint_ = Int::read(reader);
    return InputEncryptedFileUploaded(id_, parts_, md5_checksum_, key_fingerprint_);
}

std::string InputEncryptedFileUploaded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(parts);
    buffer += String::write(md5_checksum);
    buffer += Int::write(key_fingerprint);
    return buffer;
}

InputEncryptedFile::InputEncryptedFile(long id_, long access_hash_) {}

InputEncryptedFile InputEncryptedFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputEncryptedFile(id_, access_hash_);
}

std::string InputEncryptedFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputEncryptedFileBigUploaded::InputEncryptedFileBigUploaded(long id_, int parts_, int key_fingerprint_) {}

InputEncryptedFileBigUploaded InputEncryptedFileBigUploaded::read(Reader reader)
{
    long id_ = Long::read(reader);
    int parts_ = Int::read(reader);
    int key_fingerprint_ = Int::read(reader);
    return InputEncryptedFileBigUploaded(id_, parts_, key_fingerprint_);
}

std::string InputEncryptedFileBigUploaded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(parts);
    buffer += Int::write(key_fingerprint);
    return buffer;
}

EncryptedMessage::EncryptedMessage(long random_id_, int chat_id_, int date_, std::string bytes_, TLObject file_) {}

EncryptedMessage EncryptedMessage::read(Reader reader)
{
    long random_id_ = Long::read(reader);
    int chat_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    TLObject file_ = std::get<TLObject>(TLObject::read(reader));
    return EncryptedMessage(random_id_, chat_id_, date_, bytes_, file_);
}

std::string EncryptedMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(random_id);
    buffer += Int::write(chat_id);
    buffer += Int::write(date);
    buffer += Bytes::write(bytes);
    buffer += file.write();
    return buffer;
}

EncryptedMessageService::EncryptedMessageService(long random_id_, int chat_id_, int date_, std::string bytes_) {}

EncryptedMessageService EncryptedMessageService::read(Reader reader)
{
    long random_id_ = Long::read(reader);
    int chat_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return EncryptedMessageService(random_id_, chat_id_, date_, bytes_);
}

std::string EncryptedMessageService::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(random_id);
    buffer += Int::write(chat_id);
    buffer += Int::write(date);
    buffer += Bytes::write(bytes);
    return buffer;
}
InputDocumentEmpty InputDocumentEmpty::read(Reader reader)
{
    return InputDocumentEmpty();
}

std::string InputDocumentEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputDocument::InputDocument(long id_, long access_hash_, std::string file_reference_) {}

InputDocument InputDocument::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    return InputDocument(id_, access_hash_, file_reference_);
}

std::string InputDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    return buffer;
}

DocumentEmpty::DocumentEmpty(long id_) {}

DocumentEmpty DocumentEmpty::read(Reader reader)
{
    long id_ = Long::read(reader);
    return DocumentEmpty(id_);
}

std::string DocumentEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

Document::Document(long id_, long access_hash_, std::string file_reference_, int date_, std::string mime_type_, int size_, int dc_id_, std::vector<TLObject> attributes_, std::optional<std::vector<TLObject>> thumbs_, std::optional<std::vector<TLObject>> video_thumbs_) {}

Document Document::read(Reader reader)
{
    int flags = Int::read(reader);
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string file_reference_ = Bytes::read(reader);
    int date_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    int size_ = Int::read(reader);
    std::optional<std::vector<TLObject>> thumbs_;
    thumbs_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> video_thumbs_;
    video_thumbs_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    int dc_id_ = Int::read(reader);
    std::vector<TLObject> attributes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Document(id_, access_hash_, file_reference_, date_, mime_type_, size_, dc_id_, attributes_, thumbs_, video_thumbs_);
}

std::string Document::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= thumbs ? 1 << 0 : 0;
    flags |= video_thumbs ? 1 << 1 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Bytes::write(file_reference);
    buffer += Int::write(date);
    buffer += String::write(mime_type);
    buffer += Int::write(size);

    if (thumbs)
        buffer += Vector<TLObject>::write(thumbs.value());

    if (video_thumbs)
        buffer += Vector<TLObject>::write(video_thumbs.value());
    buffer += Int::write(dc_id);
    buffer += Vector<TLObject>::write(attributes);
    return buffer;
}

NotifyPeer::NotifyPeer(TLObject peer_) {}

NotifyPeer NotifyPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return NotifyPeer(peer_);
}

std::string NotifyPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
NotifyUsers NotifyUsers::read(Reader reader)
{
    return NotifyUsers();
}

std::string NotifyUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
NotifyChats NotifyChats::read(Reader reader)
{
    return NotifyChats();
}

std::string NotifyChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
NotifyBroadcasts NotifyBroadcasts::read(Reader reader)
{
    return NotifyBroadcasts();
}

std::string NotifyBroadcasts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageTypingAction SendMessageTypingAction::read(Reader reader)
{
    return SendMessageTypingAction();
}

std::string SendMessageTypingAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageCancelAction SendMessageCancelAction::read(Reader reader)
{
    return SendMessageCancelAction();
}

std::string SendMessageCancelAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageRecordVideoAction SendMessageRecordVideoAction::read(Reader reader)
{
    return SendMessageRecordVideoAction();
}

std::string SendMessageRecordVideoAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SendMessageUploadVideoAction::SendMessageUploadVideoAction(int progress_) {}

SendMessageUploadVideoAction SendMessageUploadVideoAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageUploadVideoAction(progress_);
}

std::string SendMessageUploadVideoAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}
SendMessageRecordAudioAction SendMessageRecordAudioAction::read(Reader reader)
{
    return SendMessageRecordAudioAction();
}

std::string SendMessageRecordAudioAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SendMessageUploadAudioAction::SendMessageUploadAudioAction(int progress_) {}

SendMessageUploadAudioAction SendMessageUploadAudioAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageUploadAudioAction(progress_);
}

std::string SendMessageUploadAudioAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}

SendMessageUploadPhotoAction::SendMessageUploadPhotoAction(int progress_) {}

SendMessageUploadPhotoAction SendMessageUploadPhotoAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageUploadPhotoAction(progress_);
}

std::string SendMessageUploadPhotoAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}

SendMessageUploadDocumentAction::SendMessageUploadDocumentAction(int progress_) {}

SendMessageUploadDocumentAction SendMessageUploadDocumentAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageUploadDocumentAction(progress_);
}

std::string SendMessageUploadDocumentAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}
SendMessageGeoLocationAction SendMessageGeoLocationAction::read(Reader reader)
{
    return SendMessageGeoLocationAction();
}

std::string SendMessageGeoLocationAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageChooseContactAction SendMessageChooseContactAction::read(Reader reader)
{
    return SendMessageChooseContactAction();
}

std::string SendMessageChooseContactAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageGamePlayAction SendMessageGamePlayAction::read(Reader reader)
{
    return SendMessageGamePlayAction();
}

std::string SendMessageGamePlayAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SendMessageRecordRoundAction SendMessageRecordRoundAction::read(Reader reader)
{
    return SendMessageRecordRoundAction();
}

std::string SendMessageRecordRoundAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SendMessageUploadRoundAction::SendMessageUploadRoundAction(int progress_) {}

SendMessageUploadRoundAction SendMessageUploadRoundAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageUploadRoundAction(progress_);
}

std::string SendMessageUploadRoundAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}
SpeakingInGroupCallAction SpeakingInGroupCallAction::read(Reader reader)
{
    return SpeakingInGroupCallAction();
}

std::string SpeakingInGroupCallAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SendMessageHistoryImportAction::SendMessageHistoryImportAction(int progress_) {}

SendMessageHistoryImportAction SendMessageHistoryImportAction::read(Reader reader)
{
    int progress_ = Int::read(reader);
    return SendMessageHistoryImportAction(progress_);
}

std::string SendMessageHistoryImportAction::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(progress);
    return buffer;
}
InputPrivacyKeyStatusTimestamp InputPrivacyKeyStatusTimestamp::read(Reader reader)
{
    return InputPrivacyKeyStatusTimestamp();
}

std::string InputPrivacyKeyStatusTimestamp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyChatInvite InputPrivacyKeyChatInvite::read(Reader reader)
{
    return InputPrivacyKeyChatInvite();
}

std::string InputPrivacyKeyChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyPhoneCall InputPrivacyKeyPhoneCall::read(Reader reader)
{
    return InputPrivacyKeyPhoneCall();
}

std::string InputPrivacyKeyPhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyForwards InputPrivacyKeyForwards::read(Reader reader)
{
    return InputPrivacyKeyForwards();
}

std::string InputPrivacyKeyForwards::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyProfilePhoto InputPrivacyKeyProfilePhoto::read(Reader reader)
{
    return InputPrivacyKeyProfilePhoto();
}

std::string InputPrivacyKeyProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyPhoneNumber InputPrivacyKeyPhoneNumber::read(Reader reader)
{
    return InputPrivacyKeyPhoneNumber();
}

std::string InputPrivacyKeyPhoneNumber::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyKeyAddedByPhone InputPrivacyKeyAddedByPhone::read(Reader reader)
{
    return InputPrivacyKeyAddedByPhone();
}

std::string InputPrivacyKeyAddedByPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyStatusTimestamp PrivacyKeyStatusTimestamp::read(Reader reader)
{
    return PrivacyKeyStatusTimestamp();
}

std::string PrivacyKeyStatusTimestamp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyChatInvite PrivacyKeyChatInvite::read(Reader reader)
{
    return PrivacyKeyChatInvite();
}

std::string PrivacyKeyChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyPhoneCall PrivacyKeyPhoneCall::read(Reader reader)
{
    return PrivacyKeyPhoneCall();
}

std::string PrivacyKeyPhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyForwards PrivacyKeyForwards::read(Reader reader)
{
    return PrivacyKeyForwards();
}

std::string PrivacyKeyForwards::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyProfilePhoto PrivacyKeyProfilePhoto::read(Reader reader)
{
    return PrivacyKeyProfilePhoto();
}

std::string PrivacyKeyProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyPhoneNumber PrivacyKeyPhoneNumber::read(Reader reader)
{
    return PrivacyKeyPhoneNumber();
}

std::string PrivacyKeyPhoneNumber::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyKeyAddedByPhone PrivacyKeyAddedByPhone::read(Reader reader)
{
    return PrivacyKeyAddedByPhone();
}

std::string PrivacyKeyAddedByPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyValueAllowContacts InputPrivacyValueAllowContacts::read(Reader reader)
{
    return InputPrivacyValueAllowContacts();
}

std::string InputPrivacyValueAllowContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyValueAllowAll InputPrivacyValueAllowAll::read(Reader reader)
{
    return InputPrivacyValueAllowAll();
}

std::string InputPrivacyValueAllowAll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPrivacyValueAllowUsers::InputPrivacyValueAllowUsers(std::vector<TLObject> users_) {}

InputPrivacyValueAllowUsers InputPrivacyValueAllowUsers::read(Reader reader)
{
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InputPrivacyValueAllowUsers(users_);
}

std::string InputPrivacyValueAllowUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
InputPrivacyValueDisallowContacts InputPrivacyValueDisallowContacts::read(Reader reader)
{
    return InputPrivacyValueDisallowContacts();
}

std::string InputPrivacyValueDisallowContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InputPrivacyValueDisallowAll InputPrivacyValueDisallowAll::read(Reader reader)
{
    return InputPrivacyValueDisallowAll();
}

std::string InputPrivacyValueDisallowAll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputPrivacyValueDisallowUsers::InputPrivacyValueDisallowUsers(std::vector<TLObject> users_) {}

InputPrivacyValueDisallowUsers InputPrivacyValueDisallowUsers::read(Reader reader)
{
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InputPrivacyValueDisallowUsers(users_);
}

std::string InputPrivacyValueDisallowUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

InputPrivacyValueAllowChatParticipants::InputPrivacyValueAllowChatParticipants(std::vector<int> chats_) {}

InputPrivacyValueAllowChatParticipants InputPrivacyValueAllowChatParticipants::read(Reader reader)
{
    std::vector<int> chats_ = std::get<std::vector<int>>(TLObject::read(reader));
    return InputPrivacyValueAllowChatParticipants(chats_);
}

std::string InputPrivacyValueAllowChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(chats);
    return buffer;
}

InputPrivacyValueDisallowChatParticipants::InputPrivacyValueDisallowChatParticipants(std::vector<int> chats_) {}

InputPrivacyValueDisallowChatParticipants InputPrivacyValueDisallowChatParticipants::read(Reader reader)
{
    std::vector<int> chats_ = std::get<std::vector<int>>(TLObject::read(reader));
    return InputPrivacyValueDisallowChatParticipants(chats_);
}

std::string InputPrivacyValueDisallowChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(chats);
    return buffer;
}
PrivacyValueAllowContacts PrivacyValueAllowContacts::read(Reader reader)
{
    return PrivacyValueAllowContacts();
}

std::string PrivacyValueAllowContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyValueAllowAll PrivacyValueAllowAll::read(Reader reader)
{
    return PrivacyValueAllowAll();
}

std::string PrivacyValueAllowAll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

PrivacyValueAllowUsers::PrivacyValueAllowUsers(std::vector<int> users_) {}

PrivacyValueAllowUsers PrivacyValueAllowUsers::read(Reader reader)
{
    std::vector<int> users_ = std::get<std::vector<int>>(TLObject::read(reader));
    return PrivacyValueAllowUsers(users_);
}

std::string PrivacyValueAllowUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(users);
    return buffer;
}
PrivacyValueDisallowContacts PrivacyValueDisallowContacts::read(Reader reader)
{
    return PrivacyValueDisallowContacts();
}

std::string PrivacyValueDisallowContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PrivacyValueDisallowAll PrivacyValueDisallowAll::read(Reader reader)
{
    return PrivacyValueDisallowAll();
}

std::string PrivacyValueDisallowAll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

PrivacyValueDisallowUsers::PrivacyValueDisallowUsers(std::vector<int> users_) {}

PrivacyValueDisallowUsers PrivacyValueDisallowUsers::read(Reader reader)
{
    std::vector<int> users_ = std::get<std::vector<int>>(TLObject::read(reader));
    return PrivacyValueDisallowUsers(users_);
}

std::string PrivacyValueDisallowUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(users);
    return buffer;
}

PrivacyValueAllowChatParticipants::PrivacyValueAllowChatParticipants(std::vector<int> chats_) {}

PrivacyValueAllowChatParticipants PrivacyValueAllowChatParticipants::read(Reader reader)
{
    std::vector<int> chats_ = std::get<std::vector<int>>(TLObject::read(reader));
    return PrivacyValueAllowChatParticipants(chats_);
}

std::string PrivacyValueAllowChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(chats);
    return buffer;
}

PrivacyValueDisallowChatParticipants::PrivacyValueDisallowChatParticipants(std::vector<int> chats_) {}

PrivacyValueDisallowChatParticipants PrivacyValueDisallowChatParticipants::read(Reader reader)
{
    std::vector<int> chats_ = std::get<std::vector<int>>(TLObject::read(reader));
    return PrivacyValueDisallowChatParticipants(chats_);
}

std::string PrivacyValueDisallowChatParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<int>::write(chats);
    return buffer;
}

AccountDaysTTL::AccountDaysTTL(int days_) {}

AccountDaysTTL AccountDaysTTL::read(Reader reader)
{
    int days_ = Int::read(reader);
    return AccountDaysTTL(days_);
}

std::string AccountDaysTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(days);
    return buffer;
}

DocumentAttributeImageSize::DocumentAttributeImageSize(int w_, int h_) {}

DocumentAttributeImageSize DocumentAttributeImageSize::read(Reader reader)
{
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    return DocumentAttributeImageSize(w_, h_);
}

std::string DocumentAttributeImageSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(w);
    buffer += Int::write(h);
    return buffer;
}
DocumentAttributeAnimated DocumentAttributeAnimated::read(Reader reader)
{
    return DocumentAttributeAnimated();
}

std::string DocumentAttributeAnimated::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

DocumentAttributeSticker::DocumentAttributeSticker(std::string alt_, TLObject stickerset_, std::optional<bool> mask_, std::optional<TLObject> mask_coords_) {}

DocumentAttributeSticker DocumentAttributeSticker::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> mask_;
    mask_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::string alt_ = String::read(reader);
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> mask_coords_;
    mask_coords_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return DocumentAttributeSticker(alt_, stickerset_, mask_, mask_coords_);
}

std::string DocumentAttributeSticker::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= mask ? 1 << 1 : 0;
    flags |= mask_coords ? 1 << 0 : 0;
    buffer += String::write(alt);
    buffer += stickerset.write();

    if (mask_coords)
        buffer += mask_coords.value().write();
    return buffer;
}

DocumentAttributeVideo::DocumentAttributeVideo(int duration_, int w_, int h_, std::optional<bool> round_message_, std::optional<bool> supports_streaming_) {}

DocumentAttributeVideo DocumentAttributeVideo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> round_message_;
    round_message_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> supports_streaming_;
    supports_streaming_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int duration_ = Int::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    return DocumentAttributeVideo(duration_, w_, h_, round_message_, supports_streaming_);
}

std::string DocumentAttributeVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= round_message ? 1 << 0 : 0;
    flags |= supports_streaming ? 1 << 1 : 0;
    buffer += Int::write(duration);
    buffer += Int::write(w);
    buffer += Int::write(h);
    return buffer;
}

DocumentAttributeAudio::DocumentAttributeAudio(int duration_, std::optional<bool> voice_, std::optional<std::string> title_, std::optional<std::string> performer_, std::optional<std::string> waveform_) {}

DocumentAttributeAudio DocumentAttributeAudio::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> voice_;
    voice_ = (1 << 10) ? std::optional{true} : std::nullopt;
    int duration_ = Int::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> performer_;
    performer_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> waveform_;
    waveform_ = (1 << 2) ? std::optional{Bytes::read(reader)} : std::nullopt;
    return DocumentAttributeAudio(duration_, voice_, title_, performer_, waveform_);
}

std::string DocumentAttributeAudio::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= voice ? 1 << 10 : 0;
    flags |= title ? 1 << 0 : 0;
    flags |= performer ? 1 << 1 : 0;
    flags |= waveform ? 1 << 2 : 0;
    buffer += Int::write(duration);

    if (title)
        buffer += String::write(title.value());

    if (performer)
        buffer += String::write(performer.value());

    if (waveform)
        buffer += Bytes::write(waveform.value());
    return buffer;
}

DocumentAttributeFilename::DocumentAttributeFilename(std::string file_name_) {}

DocumentAttributeFilename DocumentAttributeFilename::read(Reader reader)
{
    std::string file_name_ = String::read(reader);
    return DocumentAttributeFilename(file_name_);
}

std::string DocumentAttributeFilename::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(file_name);
    return buffer;
}
DocumentAttributeHasStickers DocumentAttributeHasStickers::read(Reader reader)
{
    return DocumentAttributeHasStickers();
}

std::string DocumentAttributeHasStickers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

StickerPack::StickerPack(std::string emoticon_, std::vector<long> documents_) {}

StickerPack StickerPack::read(Reader reader)
{
    std::string emoticon_ = String::read(reader);
    std::vector<long> documents_ = std::get<std::vector<long>>(TLObject::read(reader));
    return StickerPack(emoticon_, documents_);
}

std::string StickerPack::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(emoticon);
    buffer += Vector<long>::write(documents);
    return buffer;
}

WebPageEmpty::WebPageEmpty(long id_) {}

WebPageEmpty WebPageEmpty::read(Reader reader)
{
    long id_ = Long::read(reader);
    return WebPageEmpty(id_);
}

std::string WebPageEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

WebPagePending::WebPagePending(long id_, int date_) {}

WebPagePending WebPagePending::read(Reader reader)
{
    long id_ = Long::read(reader);
    int date_ = Int::read(reader);
    return WebPagePending(id_, date_);
}

std::string WebPagePending::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(date);
    return buffer;
}

WebPage::WebPage(long id_, std::string url_, std::string display_url_, int hash_, std::optional<std::string> type_, std::optional<std::string> site_name_, std::optional<std::string> title_, std::optional<std::string> description_, std::optional<TLObject> photo_, std::optional<std::string> embed_url_, std::optional<std::string> embed_type_, std::optional<int> embed_width_, std::optional<int> embed_height_, std::optional<int> duration_, std::optional<std::string> author_, std::optional<TLObject> document_, std::optional<TLObject> cached_page_, std::optional<std::vector<TLObject>> attributes_) {}

WebPage WebPage::read(Reader reader)
{
    int flags = Int::read(reader);
    long id_ = Long::read(reader);
    std::string url_ = String::read(reader);
    std::string display_url_ = String::read(reader);
    int hash_ = Int::read(reader);
    std::optional<std::string> type_;
    type_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> site_name_;
    site_name_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> title_;
    title_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> photo_;
    photo_ = (1 << 4) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> embed_url_;
    embed_url_ = (1 << 5) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> embed_type_;
    embed_type_ = (1 << 5) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> embed_width_;
    embed_width_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> embed_height_;
    embed_height_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> duration_;
    duration_ = (1 << 7) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> author_;
    author_ = (1 << 8) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> document_;
    document_ = (1 << 9) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> cached_page_;
    cached_page_ = (1 << 10) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> attributes_;
    attributes_ = (1 << 12) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return WebPage(id_, url_, display_url_, hash_, type_, site_name_, title_, description_, photo_, embed_url_, embed_type_, embed_width_, embed_height_, duration_, author_, document_, cached_page_, attributes_);
}

std::string WebPage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= type ? 1 << 0 : 0;
    flags |= site_name ? 1 << 1 : 0;
    flags |= title ? 1 << 2 : 0;
    flags |= description ? 1 << 3 : 0;
    flags |= photo ? 1 << 4 : 0;
    flags |= embed_url ? 1 << 5 : 0;
    flags |= embed_type ? 1 << 5 : 0;
    flags |= embed_width ? 1 << 6 : 0;
    flags |= embed_height ? 1 << 6 : 0;
    flags |= duration ? 1 << 7 : 0;
    flags |= author ? 1 << 8 : 0;
    flags |= document ? 1 << 9 : 0;
    flags |= cached_page ? 1 << 10 : 0;
    flags |= attributes ? 1 << 12 : 0;
    buffer += Long::write(id);
    buffer += String::write(url);
    buffer += String::write(display_url);
    buffer += Int::write(hash);

    if (type)
        buffer += String::write(type.value());

    if (site_name)
        buffer += String::write(site_name.value());

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());

    if (photo)
        buffer += photo.value().write();

    if (embed_url)
        buffer += String::write(embed_url.value());

    if (embed_type)
        buffer += String::write(embed_type.value());

    if (embed_width)
        buffer += Int::write(embed_width.value());

    if (embed_height)
        buffer += Int::write(embed_height.value());

    if (duration)
        buffer += Int::write(duration.value());

    if (author)
        buffer += String::write(author.value());

    if (document)
        buffer += document.value().write();

    if (cached_page)
        buffer += cached_page.value().write();

    if (attributes)
        buffer += Vector<TLObject>::write(attributes.value());
    return buffer;
}

WebPageNotModified::WebPageNotModified(std::optional<int> cached_page_views_) {}

WebPageNotModified WebPageNotModified::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> cached_page_views_;
    cached_page_views_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return WebPageNotModified(cached_page_views_);
}

std::string WebPageNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= cached_page_views ? 1 << 0 : 0;

    if (cached_page_views)
        buffer += Int::write(cached_page_views.value());
    return buffer;
}

Authorization::Authorization(long hash_, std::string device_model_, std::string platform_, std::string system_version_, int api_id_, std::string app_name_, std::string app_version_, int date_created_, int date_active_, std::string ip_, std::string country_, std::string region_, std::optional<bool> current_, std::optional<bool> official_app_, std::optional<bool> password_pending_) {}

Authorization Authorization::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> current_;
    current_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> official_app_;
    official_app_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> password_pending_;
    password_pending_ = (1 << 2) ? std::optional{true} : std::nullopt;
    long hash_ = Long::read(reader);
    std::string device_model_ = String::read(reader);
    std::string platform_ = String::read(reader);
    std::string system_version_ = String::read(reader);
    int api_id_ = Int::read(reader);
    std::string app_name_ = String::read(reader);
    std::string app_version_ = String::read(reader);
    int date_created_ = Int::read(reader);
    int date_active_ = Int::read(reader);
    std::string ip_ = String::read(reader);
    std::string country_ = String::read(reader);
    std::string region_ = String::read(reader);
    return Authorization(hash_, device_model_, platform_, system_version_, api_id_, app_name_, app_version_, date_created_, date_active_, ip_, country_, region_, current_, official_app_, password_pending_);
}

std::string Authorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= current ? 1 << 0 : 0;
    flags |= official_app ? 1 << 1 : 0;
    flags |= password_pending ? 1 << 2 : 0;
    buffer += Long::write(hash);
    buffer += String::write(device_model);
    buffer += String::write(platform);
    buffer += String::write(system_version);
    buffer += Int::write(api_id);
    buffer += String::write(app_name);
    buffer += String::write(app_version);
    buffer += Int::write(date_created);
    buffer += Int::write(date_active);
    buffer += String::write(ip);
    buffer += String::write(country);
    buffer += String::write(region);
    return buffer;
}

ReceivedNotifyMessage::ReceivedNotifyMessage(int id_) {}

ReceivedNotifyMessage ReceivedNotifyMessage::read(Reader reader)
{
    int id_ = Int::read(reader);
    int flags = Int::read(reader);
    return ReceivedNotifyMessage(id_);
}

std::string ReceivedNotifyMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    buffer += Int::write(id);
    return buffer;
}

ChatInviteExported::ChatInviteExported(std::string link_, int admin_id_, int date_, std::optional<bool> revoked_, std::optional<bool> permanent_, std::optional<int> start_date_, std::optional<int> expire_date_, std::optional<int> usage_limit_, std::optional<int> usage_) {}

ChatInviteExported ChatInviteExported::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> revoked_;
    revoked_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> permanent_;
    permanent_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::string link_ = String::read(reader);
    int admin_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::optional<int> start_date_;
    start_date_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> expire_date_;
    expire_date_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> usage_limit_;
    usage_limit_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> usage_;
    usage_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    return ChatInviteExported(link_, admin_id_, date_, revoked_, permanent_, start_date_, expire_date_, usage_limit_, usage_);
}

std::string ChatInviteExported::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= revoked ? 1 << 0 : 0;
    flags |= permanent ? 1 << 5 : 0;
    flags |= start_date ? 1 << 4 : 0;
    flags |= expire_date ? 1 << 1 : 0;
    flags |= usage_limit ? 1 << 2 : 0;
    flags |= usage ? 1 << 3 : 0;
    buffer += String::write(link);
    buffer += Int::write(admin_id);
    buffer += Int::write(date);

    if (start_date)
        buffer += Int::write(start_date.value());

    if (expire_date)
        buffer += Int::write(expire_date.value());

    if (usage_limit)
        buffer += Int::write(usage_limit.value());

    if (usage)
        buffer += Int::write(usage.value());
    return buffer;
}

ChatInviteAlready::ChatInviteAlready(TLObject chat_) {}

ChatInviteAlready ChatInviteAlready::read(Reader reader)
{
    TLObject chat_ = std::get<TLObject>(TLObject::read(reader));
    return ChatInviteAlready(chat_);
}

std::string ChatInviteAlready::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += chat.write();
    return buffer;
}

ChatInvite::ChatInvite(std::string title_, TLObject photo_, int participants_count_, std::optional<bool> channel_, std::optional<bool> broadcast_, std::optional<bool> public__, std::optional<bool> megagroup_, std::optional<std::vector<TLObject>> participants_) {}

ChatInvite ChatInvite::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> channel_;
    channel_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> broadcast_;
    broadcast_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> public__;
    public__ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> megagroup_;
    megagroup_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string title_ = String::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    int participants_count_ = Int::read(reader);
    std::optional<std::vector<TLObject>> participants_;
    participants_ = (1 << 4) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return ChatInvite(title_, photo_, participants_count_, channel_, broadcast_, public__, megagroup_, participants_);
}

std::string ChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= channel ? 1 << 0 : 0;
    flags |= broadcast ? 1 << 1 : 0;
    flags |= public_ ? 1 << 2 : 0;
    flags |= megagroup ? 1 << 3 : 0;
    flags |= participants ? 1 << 4 : 0;
    buffer += String::write(title);
    buffer += photo.write();
    buffer += Int::write(participants_count);

    if (participants)
        buffer += Vector<TLObject>::write(participants.value());
    return buffer;
}

ChatInvitePeek::ChatInvitePeek(TLObject chat_, int expires_) {}

ChatInvitePeek ChatInvitePeek::read(Reader reader)
{
    TLObject chat_ = std::get<TLObject>(TLObject::read(reader));
    int expires_ = Int::read(reader);
    return ChatInvitePeek(chat_, expires_);
}

std::string ChatInvitePeek::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += chat.write();
    buffer += Int::write(expires);
    return buffer;
}
InputStickerSetEmpty InputStickerSetEmpty::read(Reader reader)
{
    return InputStickerSetEmpty();
}

std::string InputStickerSetEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputStickerSetID::InputStickerSetID(long id_, long access_hash_) {}

InputStickerSetID InputStickerSetID::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputStickerSetID(id_, access_hash_);
}

std::string InputStickerSetID::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputStickerSetShortName::InputStickerSetShortName(std::string short_name_) {}

InputStickerSetShortName InputStickerSetShortName::read(Reader reader)
{
    std::string short_name_ = String::read(reader);
    return InputStickerSetShortName(short_name_);
}

std::string InputStickerSetShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(short_name);
    return buffer;
}
InputStickerSetAnimatedEmoji InputStickerSetAnimatedEmoji::read(Reader reader)
{
    return InputStickerSetAnimatedEmoji();
}

std::string InputStickerSetAnimatedEmoji::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputStickerSetDice::InputStickerSetDice(std::string emoticon_) {}

InputStickerSetDice InputStickerSetDice::read(Reader reader)
{
    std::string emoticon_ = String::read(reader);
    return InputStickerSetDice(emoticon_);
}

std::string InputStickerSetDice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(emoticon);
    return buffer;
}

StickerSet::StickerSet(long id_, long access_hash_, std::string title_, std::string short_name_, int count_, int hash_, std::optional<bool> archived_, std::optional<bool> official_, std::optional<bool> masks_, std::optional<bool> animated_, std::optional<int> installed_date_, std::optional<std::vector<TLObject>> thumbs_, std::optional<int> thumb_dc_id_, std::optional<int> thumb_version_) {}

StickerSet StickerSet::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> archived_;
    archived_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> official_;
    official_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> masks_;
    masks_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> animated_;
    animated_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<int> installed_date_;
    installed_date_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string title_ = String::read(reader);
    std::string short_name_ = String::read(reader);
    std::optional<std::vector<TLObject>> thumbs_;
    thumbs_ = (1 << 4) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> thumb_dc_id_;
    thumb_dc_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> thumb_version_;
    thumb_version_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    int count_ = Int::read(reader);
    int hash_ = Int::read(reader);
    return StickerSet(id_, access_hash_, title_, short_name_, count_, hash_, archived_, official_, masks_, animated_, installed_date_, thumbs_, thumb_dc_id_, thumb_version_);
}

std::string StickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= archived ? 1 << 1 : 0;
    flags |= official ? 1 << 2 : 0;
    flags |= masks ? 1 << 3 : 0;
    flags |= animated ? 1 << 5 : 0;
    flags |= installed_date ? 1 << 0 : 0;
    flags |= thumbs ? 1 << 4 : 0;
    flags |= thumb_dc_id ? 1 << 4 : 0;
    flags |= thumb_version ? 1 << 4 : 0;

    if (installed_date)
        buffer += Int::write(installed_date.value());
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += String::write(title);
    buffer += String::write(short_name);

    if (thumbs)
        buffer += Vector<TLObject>::write(thumbs.value());

    if (thumb_dc_id)
        buffer += Int::write(thumb_dc_id.value());

    if (thumb_version)
        buffer += Int::write(thumb_version.value());
    buffer += Int::write(count);
    buffer += Int::write(hash);
    return buffer;
}

BotCommand::BotCommand(std::string command_, std::string description_) {}

BotCommand BotCommand::read(Reader reader)
{
    std::string command_ = String::read(reader);
    std::string description_ = String::read(reader);
    return BotCommand(command_, description_);
}

std::string BotCommand::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(command);
    buffer += String::write(description);
    return buffer;
}

BotInfo::BotInfo(int user_id_, std::string description_, std::vector<TLObject> commands_) {}

BotInfo BotInfo::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    std::string description_ = String::read(reader);
    std::vector<TLObject> commands_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return BotInfo(user_id_, description_, commands_);
}

std::string BotInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += String::write(description);
    buffer += Vector<TLObject>::write(commands);
    return buffer;
}

KeyboardButton::KeyboardButton(std::string text_) {}

KeyboardButton KeyboardButton::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return KeyboardButton(text_);
}

std::string KeyboardButton::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonUrl::KeyboardButtonUrl(std::string text_, std::string url_) {}

KeyboardButtonUrl KeyboardButtonUrl::read(Reader reader)
{
    std::string text_ = String::read(reader);
    std::string url_ = String::read(reader);
    return KeyboardButtonUrl(text_, url_);
}

std::string KeyboardButtonUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    buffer += String::write(url);
    return buffer;
}

KeyboardButtonCallback::KeyboardButtonCallback(std::string text_, std::string data_, std::optional<bool> requires_password_) {}

KeyboardButtonCallback KeyboardButtonCallback::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> requires_password_;
    requires_password_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string text_ = String::read(reader);
    std::string data_ = Bytes::read(reader);
    return KeyboardButtonCallback(text_, data_, requires_password_);
}

std::string KeyboardButtonCallback::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= requires_password ? 1 << 0 : 0;
    buffer += String::write(text);
    buffer += Bytes::write(data);
    return buffer;
}

KeyboardButtonRequestPhone::KeyboardButtonRequestPhone(std::string text_) {}

KeyboardButtonRequestPhone KeyboardButtonRequestPhone::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return KeyboardButtonRequestPhone(text_);
}

std::string KeyboardButtonRequestPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonRequestGeoLocation::KeyboardButtonRequestGeoLocation(std::string text_) {}

KeyboardButtonRequestGeoLocation KeyboardButtonRequestGeoLocation::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return KeyboardButtonRequestGeoLocation(text_);
}

std::string KeyboardButtonRequestGeoLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonSwitchInline::KeyboardButtonSwitchInline(std::string text_, std::string query_, std::optional<bool> same_peer_) {}

KeyboardButtonSwitchInline KeyboardButtonSwitchInline::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> same_peer_;
    same_peer_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string text_ = String::read(reader);
    std::string query_ = String::read(reader);
    return KeyboardButtonSwitchInline(text_, query_, same_peer_);
}

std::string KeyboardButtonSwitchInline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= same_peer ? 1 << 0 : 0;
    buffer += String::write(text);
    buffer += String::write(query);
    return buffer;
}

KeyboardButtonGame::KeyboardButtonGame(std::string text_) {}

KeyboardButtonGame KeyboardButtonGame::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return KeyboardButtonGame(text_);
}

std::string KeyboardButtonGame::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonBuy::KeyboardButtonBuy(std::string text_) {}

KeyboardButtonBuy KeyboardButtonBuy::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return KeyboardButtonBuy(text_);
}

std::string KeyboardButtonBuy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonUrlAuth::KeyboardButtonUrlAuth(std::string text_, std::string url_, int button_id_, std::optional<std::string> fwd_text_) {}

KeyboardButtonUrlAuth KeyboardButtonUrlAuth::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string text_ = String::read(reader);
    std::optional<std::string> fwd_text_;
    fwd_text_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::string url_ = String::read(reader);
    int button_id_ = Int::read(reader);
    return KeyboardButtonUrlAuth(text_, url_, button_id_, fwd_text_);
}

std::string KeyboardButtonUrlAuth::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= fwd_text ? 1 << 0 : 0;
    buffer += String::write(text);

    if (fwd_text)
        buffer += String::write(fwd_text.value());
    buffer += String::write(url);
    buffer += Int::write(button_id);
    return buffer;
}

InputKeyboardButtonUrlAuth::InputKeyboardButtonUrlAuth(std::string text_, std::string url_, TLObject bot_, std::optional<bool> request_write_access_, std::optional<std::string> fwd_text_) {}

InputKeyboardButtonUrlAuth InputKeyboardButtonUrlAuth::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> request_write_access_;
    request_write_access_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string text_ = String::read(reader);
    std::optional<std::string> fwd_text_;
    fwd_text_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::string url_ = String::read(reader);
    TLObject bot_ = std::get<TLObject>(TLObject::read(reader));
    return InputKeyboardButtonUrlAuth(text_, url_, bot_, request_write_access_, fwd_text_);
}

std::string InputKeyboardButtonUrlAuth::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= request_write_access ? 1 << 0 : 0;
    flags |= fwd_text ? 1 << 1 : 0;
    buffer += String::write(text);

    if (fwd_text)
        buffer += String::write(fwd_text.value());
    buffer += String::write(url);
    buffer += bot.write();
    return buffer;
}

KeyboardButtonRequestPoll::KeyboardButtonRequestPoll(std::string text_, std::optional<bool> quiz_) {}

KeyboardButtonRequestPoll KeyboardButtonRequestPoll::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> quiz_;
    quiz_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string text_ = String::read(reader);
    return KeyboardButtonRequestPoll(text_, quiz_);
}

std::string KeyboardButtonRequestPoll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= quiz ? 1 << 0 : 0;
    buffer += String::write(text);
    return buffer;
}

KeyboardButtonRow::KeyboardButtonRow(std::vector<TLObject> buttons_) {}

KeyboardButtonRow KeyboardButtonRow::read(Reader reader)
{
    std::vector<TLObject> buttons_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return KeyboardButtonRow(buttons_);
}

std::string KeyboardButtonRow::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(buttons);
    return buffer;
}

ReplyKeyboardHide::ReplyKeyboardHide(std::optional<bool> selective_) {}

ReplyKeyboardHide ReplyKeyboardHide::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> selective_;
    selective_ = (1 << 2) ? std::optional{true} : std::nullopt;
    return ReplyKeyboardHide(selective_);
}

std::string ReplyKeyboardHide::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= selective ? 1 << 2 : 0;
    return buffer;
}

ReplyKeyboardForceReply::ReplyKeyboardForceReply(std::optional<bool> single_use_, std::optional<bool> selective_, std::optional<std::string> placeholder_) {}

ReplyKeyboardForceReply ReplyKeyboardForceReply::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> single_use_;
    single_use_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> selective_;
    selective_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<std::string> placeholder_;
    placeholder_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    return ReplyKeyboardForceReply(single_use_, selective_, placeholder_);
}

std::string ReplyKeyboardForceReply::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= single_use ? 1 << 1 : 0;
    flags |= selective ? 1 << 2 : 0;
    flags |= placeholder ? 1 << 3 : 0;

    if (placeholder)
        buffer += String::write(placeholder.value());
    return buffer;
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(std::vector<TLObject> rows_, std::optional<bool> resize_, std::optional<bool> single_use_, std::optional<bool> selective_, std::optional<std::string> placeholder_) {}

ReplyKeyboardMarkup ReplyKeyboardMarkup::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> resize_;
    resize_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> single_use_;
    single_use_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> selective_;
    selective_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::vector<TLObject> rows_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<std::string> placeholder_;
    placeholder_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    return ReplyKeyboardMarkup(rows_, resize_, single_use_, selective_, placeholder_);
}

std::string ReplyKeyboardMarkup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= resize ? 1 << 0 : 0;
    flags |= single_use ? 1 << 1 : 0;
    flags |= selective ? 1 << 2 : 0;
    flags |= placeholder ? 1 << 3 : 0;
    buffer += Vector<TLObject>::write(rows);

    if (placeholder)
        buffer += String::write(placeholder.value());
    return buffer;
}

ReplyInlineMarkup::ReplyInlineMarkup(std::vector<TLObject> rows_) {}

ReplyInlineMarkup ReplyInlineMarkup::read(Reader reader)
{
    std::vector<TLObject> rows_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ReplyInlineMarkup(rows_);
}

std::string ReplyInlineMarkup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(rows);
    return buffer;
}

MessageEntityUnknown::MessageEntityUnknown(int offset_, int length_) {}

MessageEntityUnknown MessageEntityUnknown::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityUnknown(offset_, length_);
}

std::string MessageEntityUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityMention::MessageEntityMention(int offset_, int length_) {}

MessageEntityMention MessageEntityMention::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityMention(offset_, length_);
}

std::string MessageEntityMention::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityHashtag::MessageEntityHashtag(int offset_, int length_) {}

MessageEntityHashtag MessageEntityHashtag::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityHashtag(offset_, length_);
}

std::string MessageEntityHashtag::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityBotCommand::MessageEntityBotCommand(int offset_, int length_) {}

MessageEntityBotCommand MessageEntityBotCommand::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityBotCommand(offset_, length_);
}

std::string MessageEntityBotCommand::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityUrl::MessageEntityUrl(int offset_, int length_) {}

MessageEntityUrl MessageEntityUrl::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityUrl(offset_, length_);
}

std::string MessageEntityUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityEmail::MessageEntityEmail(int offset_, int length_) {}

MessageEntityEmail MessageEntityEmail::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityEmail(offset_, length_);
}

std::string MessageEntityEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityBold::MessageEntityBold(int offset_, int length_) {}

MessageEntityBold MessageEntityBold::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityBold(offset_, length_);
}

std::string MessageEntityBold::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityItalic::MessageEntityItalic(int offset_, int length_) {}

MessageEntityItalic MessageEntityItalic::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityItalic(offset_, length_);
}

std::string MessageEntityItalic::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityCode::MessageEntityCode(int offset_, int length_) {}

MessageEntityCode MessageEntityCode::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityCode(offset_, length_);
}

std::string MessageEntityCode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityPre::MessageEntityPre(int offset_, int length_, std::string language_) {}

MessageEntityPre MessageEntityPre::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    std::string language_ = String::read(reader);
    return MessageEntityPre(offset_, length_, language_);
}

std::string MessageEntityPre::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    buffer += String::write(language);
    return buffer;
}

MessageEntityTextUrl::MessageEntityTextUrl(int offset_, int length_, std::string url_) {}

MessageEntityTextUrl MessageEntityTextUrl::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    std::string url_ = String::read(reader);
    return MessageEntityTextUrl(offset_, length_, url_);
}

std::string MessageEntityTextUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    buffer += String::write(url);
    return buffer;
}

MessageEntityMentionName::MessageEntityMentionName(int offset_, int length_, int user_id_) {}

MessageEntityMentionName MessageEntityMentionName::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    return MessageEntityMentionName(offset_, length_, user_id_);
}

std::string MessageEntityMentionName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    buffer += Int::write(user_id);
    return buffer;
}

InputMessageEntityMentionName::InputMessageEntityMentionName(int offset_, int length_, TLObject user_id_) {}

InputMessageEntityMentionName InputMessageEntityMentionName::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return InputMessageEntityMentionName(offset_, length_, user_id_);
}

std::string InputMessageEntityMentionName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    buffer += user_id.write();
    return buffer;
}

MessageEntityPhone::MessageEntityPhone(int offset_, int length_) {}

MessageEntityPhone MessageEntityPhone::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityPhone(offset_, length_);
}

std::string MessageEntityPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityCashtag::MessageEntityCashtag(int offset_, int length_) {}

MessageEntityCashtag MessageEntityCashtag::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityCashtag(offset_, length_);
}

std::string MessageEntityCashtag::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityUnderline::MessageEntityUnderline(int offset_, int length_) {}

MessageEntityUnderline MessageEntityUnderline::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityUnderline(offset_, length_);
}

std::string MessageEntityUnderline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityStrike::MessageEntityStrike(int offset_, int length_) {}

MessageEntityStrike MessageEntityStrike::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityStrike(offset_, length_);
}

std::string MessageEntityStrike::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityBlockquote::MessageEntityBlockquote(int offset_, int length_) {}

MessageEntityBlockquote MessageEntityBlockquote::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityBlockquote(offset_, length_);
}

std::string MessageEntityBlockquote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}

MessageEntityBankCard::MessageEntityBankCard(int offset_, int length_) {}

MessageEntityBankCard MessageEntityBankCard::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int length_ = Int::read(reader);
    return MessageEntityBankCard(offset_, length_);
}

std::string MessageEntityBankCard::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(length);
    return buffer;
}
InputChannelEmpty InputChannelEmpty::read(Reader reader)
{
    return InputChannelEmpty();
}

std::string InputChannelEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputChannel::InputChannel(int channel_id_, long access_hash_) {}

InputChannel InputChannel::read(Reader reader)
{
    int channel_id_ = Int::read(reader);
    long access_hash_ = Long::read(reader);
    return InputChannel(channel_id_, access_hash_);
}

std::string InputChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(channel_id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputChannelFromMessage::InputChannelFromMessage(TLObject peer_, int msg_id_, int channel_id_) {}

InputChannelFromMessage InputChannelFromMessage::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int channel_id_ = Int::read(reader);
    return InputChannelFromMessage(peer_, msg_id_, channel_id_);
}

std::string InputChannelFromMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(channel_id);
    return buffer;
}

MessageRange::MessageRange(int min_id_, int max_id_) {}

MessageRange MessageRange::read(Reader reader)
{
    int min_id_ = Int::read(reader);
    int max_id_ = Int::read(reader);
    return MessageRange(min_id_, max_id_);
}

std::string MessageRange::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(min_id);
    buffer += Int::write(max_id);
    return buffer;
}
ChannelMessagesFilterEmpty ChannelMessagesFilterEmpty::read(Reader reader)
{
    return ChannelMessagesFilterEmpty();
}

std::string ChannelMessagesFilterEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelMessagesFilter::ChannelMessagesFilter(std::vector<TLObject> ranges_, std::optional<bool> exclude_new_messages_) {}

ChannelMessagesFilter ChannelMessagesFilter::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> exclude_new_messages_;
    exclude_new_messages_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::vector<TLObject> ranges_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelMessagesFilter(ranges_, exclude_new_messages_);
}

std::string ChannelMessagesFilter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= exclude_new_messages ? 1 << 1 : 0;
    buffer += Vector<TLObject>::write(ranges);
    return buffer;
}

ChannelParticipant::ChannelParticipant(int user_id_, int date_) {}

ChannelParticipant ChannelParticipant::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return ChannelParticipant(user_id_, date_);
}

std::string ChannelParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(date);
    return buffer;
}

ChannelParticipantSelf::ChannelParticipantSelf(int user_id_, int inviter_id_, int date_) {}

ChannelParticipantSelf ChannelParticipantSelf::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int inviter_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return ChannelParticipantSelf(user_id_, inviter_id_, date_);
}

std::string ChannelParticipantSelf::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(inviter_id);
    buffer += Int::write(date);
    return buffer;
}

ChannelParticipantCreator::ChannelParticipantCreator(int user_id_, TLObject admin_rights_, std::optional<std::string> rank_) {}

ChannelParticipantCreator ChannelParticipantCreator::read(Reader reader)
{
    int flags = Int::read(reader);
    int user_id_ = Int::read(reader);
    TLObject admin_rights_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> rank_;
    rank_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    return ChannelParticipantCreator(user_id_, admin_rights_, rank_);
}

std::string ChannelParticipantCreator::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= rank ? 1 << 0 : 0;
    buffer += Int::write(user_id);
    buffer += admin_rights.write();

    if (rank)
        buffer += String::write(rank.value());
    return buffer;
}

ChannelParticipantAdmin::ChannelParticipantAdmin(int user_id_, int promoted_by_, int date_, TLObject admin_rights_, std::optional<bool> can_edit_, std::optional<bool> self_, std::optional<int> inviter_id_, std::optional<std::string> rank_) {}

ChannelParticipantAdmin ChannelParticipantAdmin::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_edit_;
    can_edit_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> self_;
    self_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int user_id_ = Int::read(reader);
    std::optional<int> inviter_id_;
    inviter_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    int promoted_by_ = Int::read(reader);
    int date_ = Int::read(reader);
    TLObject admin_rights_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> rank_;
    rank_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    return ChannelParticipantAdmin(user_id_, promoted_by_, date_, admin_rights_, can_edit_, self_, inviter_id_, rank_);
}

std::string ChannelParticipantAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_edit ? 1 << 0 : 0;
    flags |= self ? 1 << 1 : 0;
    flags |= inviter_id ? 1 << 1 : 0;
    flags |= rank ? 1 << 2 : 0;
    buffer += Int::write(user_id);

    if (inviter_id)
        buffer += Int::write(inviter_id.value());
    buffer += Int::write(promoted_by);
    buffer += Int::write(date);
    buffer += admin_rights.write();

    if (rank)
        buffer += String::write(rank.value());
    return buffer;
}

ChannelParticipantBanned::ChannelParticipantBanned(TLObject peer_, int kicked_by_, int date_, TLObject banned_rights_, std::optional<bool> left_) {}

ChannelParticipantBanned ChannelParticipantBanned::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> left_;
    left_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int kicked_by_ = Int::read(reader);
    int date_ = Int::read(reader);
    TLObject banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelParticipantBanned(peer_, kicked_by_, date_, banned_rights_, left_);
}

std::string ChannelParticipantBanned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= left ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Int::write(kicked_by);
    buffer += Int::write(date);
    buffer += banned_rights.write();
    return buffer;
}

ChannelParticipantLeft::ChannelParticipantLeft(TLObject peer_) {}

ChannelParticipantLeft ChannelParticipantLeft::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelParticipantLeft(peer_);
}

std::string ChannelParticipantLeft::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}
ChannelParticipantsRecent ChannelParticipantsRecent::read(Reader reader)
{
    return ChannelParticipantsRecent();
}

std::string ChannelParticipantsRecent::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
ChannelParticipantsAdmins ChannelParticipantsAdmins::read(Reader reader)
{
    return ChannelParticipantsAdmins();
}

std::string ChannelParticipantsAdmins::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelParticipantsKicked::ChannelParticipantsKicked(std::string q_) {}

ChannelParticipantsKicked ChannelParticipantsKicked::read(Reader reader)
{
    std::string q_ = String::read(reader);
    return ChannelParticipantsKicked(q_);
}

std::string ChannelParticipantsKicked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    return buffer;
}
ChannelParticipantsBots ChannelParticipantsBots::read(Reader reader)
{
    return ChannelParticipantsBots();
}

std::string ChannelParticipantsBots::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelParticipantsBanned::ChannelParticipantsBanned(std::string q_) {}

ChannelParticipantsBanned ChannelParticipantsBanned::read(Reader reader)
{
    std::string q_ = String::read(reader);
    return ChannelParticipantsBanned(q_);
}

std::string ChannelParticipantsBanned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    return buffer;
}

ChannelParticipantsSearch::ChannelParticipantsSearch(std::string q_) {}

ChannelParticipantsSearch ChannelParticipantsSearch::read(Reader reader)
{
    std::string q_ = String::read(reader);
    return ChannelParticipantsSearch(q_);
}

std::string ChannelParticipantsSearch::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    return buffer;
}

ChannelParticipantsContacts::ChannelParticipantsContacts(std::string q_) {}

ChannelParticipantsContacts ChannelParticipantsContacts::read(Reader reader)
{
    std::string q_ = String::read(reader);
    return ChannelParticipantsContacts(q_);
}

std::string ChannelParticipantsContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(q);
    return buffer;
}

ChannelParticipantsMentions::ChannelParticipantsMentions(std::optional<std::string> q_, std::optional<int> top_msg_id_) {}

ChannelParticipantsMentions ChannelParticipantsMentions::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> q_;
    q_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> top_msg_id_;
    top_msg_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return ChannelParticipantsMentions(q_, top_msg_id_);
}

std::string ChannelParticipantsMentions::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= q ? 1 << 0 : 0;
    flags |= top_msg_id ? 1 << 1 : 0;

    if (q)
        buffer += String::write(q.value());

    if (top_msg_id)
        buffer += Int::write(top_msg_id.value());
    return buffer;
}

InputBotInlineMessageMediaAuto::InputBotInlineMessageMediaAuto(std::string message_, std::optional<std::vector<TLObject>> entities_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageMediaAuto InputBotInlineMessageMediaAuto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageMediaAuto(message_, entities_, reply_markup_);
}

std::string InputBotInlineMessageMediaAuto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= entities ? 1 << 1 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageText::InputBotInlineMessageText(std::string message_, std::optional<bool> no_webpage_, std::optional<std::vector<TLObject>> entities_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageText InputBotInlineMessageText::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageText(message_, no_webpage_, entities_, reply_markup_);
}

std::string InputBotInlineMessageText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 0 : 0;
    flags |= entities ? 1 << 1 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageMediaGeo::InputBotInlineMessageMediaGeo(TLObject geo_point_, std::optional<int> heading_, std::optional<int> period_, std::optional<int> proximity_notification_radius_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageMediaGeo InputBotInlineMessageMediaGeo::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> heading_;
    heading_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> period_;
    period_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> proximity_notification_radius_;
    proximity_notification_radius_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageMediaGeo(geo_point_, heading_, period_, proximity_notification_radius_, reply_markup_);
}

std::string InputBotInlineMessageMediaGeo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= heading ? 1 << 0 : 0;
    flags |= period ? 1 << 1 : 0;
    flags |= proximity_notification_radius ? 1 << 3 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += geo_point.write();

    if (heading)
        buffer += Int::write(heading.value());

    if (period)
        buffer += Int::write(period.value());

    if (proximity_notification_radius)
        buffer += Int::write(proximity_notification_radius.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageMediaVenue::InputBotInlineMessageMediaVenue(TLObject geo_point_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageMediaVenue InputBotInlineMessageMediaVenue::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    std::string address_ = String::read(reader);
    std::string provider_ = String::read(reader);
    std::string venue_id_ = String::read(reader);
    std::string venue_type_ = String::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageMediaVenue(geo_point_, title_, address_, provider_, venue_id_, venue_type_, reply_markup_);
}

std::string InputBotInlineMessageMediaVenue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += geo_point.write();
    buffer += String::write(title);
    buffer += String::write(address);
    buffer += String::write(provider);
    buffer += String::write(venue_id);
    buffer += String::write(venue_type);

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageMediaContact::InputBotInlineMessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageMediaContact InputBotInlineMessageMediaContact::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string phone_number_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string vcard_ = String::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageMediaContact(phone_number_, first_name_, last_name_, vcard_, reply_markup_);
}

std::string InputBotInlineMessageMediaContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(phone_number);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(vcard);

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageGame::InputBotInlineMessageGame(std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageGame InputBotInlineMessageGame::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageGame(reply_markup_);
}

std::string InputBotInlineMessageGame::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_markup ? 1 << 2 : 0;

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineMessageMediaInvoice::InputBotInlineMessageMediaInvoice(std::string title_, std::string description_, TLObject invoice_, std::string payload_, std::string provider_, TLObject provider_data_, std::optional<TLObject> photo_, std::optional<TLObject> reply_markup_) {}

InputBotInlineMessageMediaInvoice InputBotInlineMessageMediaInvoice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject invoice_ = std::get<TLObject>(TLObject::read(reader));
    std::string payload_ = Bytes::read(reader);
    std::string provider_ = String::read(reader);
    TLObject provider_data_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputBotInlineMessageMediaInvoice(title_, description_, invoice_, payload_, provider_, provider_data_, photo_, reply_markup_);
}

std::string InputBotInlineMessageMediaInvoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(title);
    buffer += String::write(description);

    if (photo)
        buffer += photo.value().write();
    buffer += invoice.write();
    buffer += Bytes::write(payload);
    buffer += String::write(provider);
    buffer += provider_data.write();

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

InputBotInlineResult::InputBotInlineResult(std::string id_, std::string type_, TLObject send_message_, std::optional<std::string> title_, std::optional<std::string> description_, std::optional<std::string> url_, std::optional<TLObject> thumb_, std::optional<TLObject> content_) {}

InputBotInlineResult InputBotInlineResult::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string id_ = String::read(reader);
    std::string type_ = String::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> thumb_;
    thumb_ = (1 << 4) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> content_;
    content_ = (1 << 5) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return InputBotInlineResult(id_, type_, send_message_, title_, description_, url_, thumb_, content_);
}

std::string InputBotInlineResult::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= title ? 1 << 1 : 0;
    flags |= description ? 1 << 2 : 0;
    flags |= url ? 1 << 3 : 0;
    flags |= thumb ? 1 << 4 : 0;
    flags |= content ? 1 << 5 : 0;
    buffer += String::write(id);
    buffer += String::write(type);

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());

    if (url)
        buffer += String::write(url.value());

    if (thumb)
        buffer += thumb.value().write();

    if (content)
        buffer += content.value().write();
    buffer += send_message.write();
    return buffer;
}

InputBotInlineResultPhoto::InputBotInlineResultPhoto(std::string id_, std::string type_, TLObject photo_, TLObject send_message_) {}

InputBotInlineResultPhoto InputBotInlineResultPhoto::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string type_ = String::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return InputBotInlineResultPhoto(id_, type_, photo_, send_message_);
}

std::string InputBotInlineResultPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += String::write(type);
    buffer += photo.write();
    buffer += send_message.write();
    return buffer;
}

InputBotInlineResultDocument::InputBotInlineResultDocument(std::string id_, std::string type_, TLObject document_, TLObject send_message_, std::optional<std::string> title_, std::optional<std::string> description_) {}

InputBotInlineResultDocument InputBotInlineResultDocument::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string id_ = String::read(reader);
    std::string type_ = String::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject document_ = std::get<TLObject>(TLObject::read(reader));
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return InputBotInlineResultDocument(id_, type_, document_, send_message_, title_, description_);
}

std::string InputBotInlineResultDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= title ? 1 << 1 : 0;
    flags |= description ? 1 << 2 : 0;
    buffer += String::write(id);
    buffer += String::write(type);

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());
    buffer += document.write();
    buffer += send_message.write();
    return buffer;
}

InputBotInlineResultGame::InputBotInlineResultGame(std::string id_, std::string short_name_, TLObject send_message_) {}

InputBotInlineResultGame InputBotInlineResultGame::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string short_name_ = String::read(reader);
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return InputBotInlineResultGame(id_, short_name_, send_message_);
}

std::string InputBotInlineResultGame::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += String::write(short_name);
    buffer += send_message.write();
    return buffer;
}

BotInlineMessageMediaAuto::BotInlineMessageMediaAuto(std::string message_, std::optional<std::vector<TLObject>> entities_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageMediaAuto BotInlineMessageMediaAuto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageMediaAuto(message_, entities_, reply_markup_);
}

std::string BotInlineMessageMediaAuto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= entities ? 1 << 1 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineMessageText::BotInlineMessageText(std::string message_, std::optional<bool> no_webpage_, std::optional<std::vector<TLObject>> entities_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageText BotInlineMessageText::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageText(message_, no_webpage_, entities_, reply_markup_);
}

std::string BotInlineMessageText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 0 : 0;
    flags |= entities ? 1 << 1 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineMessageMediaGeo::BotInlineMessageMediaGeo(TLObject geo_, std::optional<int> heading_, std::optional<int> period_, std::optional<int> proximity_notification_radius_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageMediaGeo BotInlineMessageMediaGeo::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> heading_;
    heading_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> period_;
    period_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> proximity_notification_radius_;
    proximity_notification_radius_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageMediaGeo(geo_, heading_, period_, proximity_notification_radius_, reply_markup_);
}

std::string BotInlineMessageMediaGeo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= heading ? 1 << 0 : 0;
    flags |= period ? 1 << 1 : 0;
    flags |= proximity_notification_radius ? 1 << 3 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += geo.write();

    if (heading)
        buffer += Int::write(heading.value());

    if (period)
        buffer += Int::write(period.value());

    if (proximity_notification_radius)
        buffer += Int::write(proximity_notification_radius.value());

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineMessageMediaVenue::BotInlineMessageMediaVenue(TLObject geo_, std::string title_, std::string address_, std::string provider_, std::string venue_id_, std::string venue_type_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageMediaVenue BotInlineMessageMediaVenue::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    std::string address_ = String::read(reader);
    std::string provider_ = String::read(reader);
    std::string venue_id_ = String::read(reader);
    std::string venue_type_ = String::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageMediaVenue(geo_, title_, address_, provider_, venue_id_, venue_type_, reply_markup_);
}

std::string BotInlineMessageMediaVenue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += geo.write();
    buffer += String::write(title);
    buffer += String::write(address);
    buffer += String::write(provider);
    buffer += String::write(venue_id);
    buffer += String::write(venue_type);

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineMessageMediaContact::BotInlineMessageMediaContact(std::string phone_number_, std::string first_name_, std::string last_name_, std::string vcard_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageMediaContact BotInlineMessageMediaContact::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string phone_number_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    std::string vcard_ = String::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageMediaContact(phone_number_, first_name_, last_name_, vcard_, reply_markup_);
}

std::string BotInlineMessageMediaContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(phone_number);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += String::write(vcard);

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineMessageMediaInvoice::BotInlineMessageMediaInvoice(std::string title_, std::string description_, std::string currency_, long total_amount_, std::optional<bool> shipping_address_requested_, std::optional<bool> test_, std::optional<TLObject> photo_, std::optional<TLObject> reply_markup_) {}

BotInlineMessageMediaInvoice BotInlineMessageMediaInvoice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> shipping_address_requested_;
    shipping_address_requested_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> test_;
    test_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    std::optional<TLObject> reply_markup_;
    reply_markup_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return BotInlineMessageMediaInvoice(title_, description_, currency_, total_amount_, shipping_address_requested_, test_, photo_, reply_markup_);
}

std::string BotInlineMessageMediaInvoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= shipping_address_requested ? 1 << 1 : 0;
    flags |= test ? 1 << 3 : 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= reply_markup ? 1 << 2 : 0;
    buffer += String::write(title);
    buffer += String::write(description);

    if (photo)
        buffer += photo.value().write();
    buffer += String::write(currency);
    buffer += Long::write(total_amount);

    if (reply_markup)
        buffer += reply_markup.value().write();
    return buffer;
}

BotInlineResult::BotInlineResult(std::string id_, std::string type_, TLObject send_message_, std::optional<std::string> title_, std::optional<std::string> description_, std::optional<std::string> url_, std::optional<TLObject> thumb_, std::optional<TLObject> content_) {}

BotInlineResult BotInlineResult::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string id_ = String::read(reader);
    std::string type_ = String::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> thumb_;
    thumb_ = (1 << 4) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> content_;
    content_ = (1 << 5) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return BotInlineResult(id_, type_, send_message_, title_, description_, url_, thumb_, content_);
}

std::string BotInlineResult::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= title ? 1 << 1 : 0;
    flags |= description ? 1 << 2 : 0;
    flags |= url ? 1 << 3 : 0;
    flags |= thumb ? 1 << 4 : 0;
    flags |= content ? 1 << 5 : 0;
    buffer += String::write(id);
    buffer += String::write(type);

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());

    if (url)
        buffer += String::write(url.value());

    if (thumb)
        buffer += thumb.value().write();

    if (content)
        buffer += content.value().write();
    buffer += send_message.write();
    return buffer;
}

BotInlineMediaResult::BotInlineMediaResult(std::string id_, std::string type_, TLObject send_message_, std::optional<TLObject> photo_, std::optional<TLObject> document_, std::optional<std::string> title_, std::optional<std::string> description_) {}

BotInlineMediaResult BotInlineMediaResult::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string id_ = String::read(reader);
    std::string type_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> document_;
    document_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> title_;
    title_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject send_message_ = std::get<TLObject>(TLObject::read(reader));
    return BotInlineMediaResult(id_, type_, send_message_, photo_, document_, title_, description_);
}

std::string BotInlineMediaResult::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= photo ? 1 << 0 : 0;
    flags |= document ? 1 << 1 : 0;
    flags |= title ? 1 << 2 : 0;
    flags |= description ? 1 << 3 : 0;
    buffer += String::write(id);
    buffer += String::write(type);

    if (photo)
        buffer += photo.value().write();

    if (document)
        buffer += document.value().write();

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());
    buffer += send_message.write();
    return buffer;
}

ExportedMessageLink::ExportedMessageLink(std::string link_, std::string html_) {}

ExportedMessageLink ExportedMessageLink::read(Reader reader)
{
    std::string link_ = String::read(reader);
    std::string html_ = String::read(reader);
    return ExportedMessageLink(link_, html_);
}

std::string ExportedMessageLink::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(link);
    buffer += String::write(html);
    return buffer;
}

MessageFwdHeader::MessageFwdHeader(int date_, std::optional<bool> imported_, std::optional<TLObject> from_id_, std::optional<std::string> from_name_, std::optional<int> channel_post_, std::optional<std::string> post_author_, std::optional<TLObject> saved_from_peer_, std::optional<int> saved_from_msg_id_, std::optional<std::string> psa_type_) {}

MessageFwdHeader MessageFwdHeader::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> imported_;
    imported_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> from_id_;
    from_id_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> from_name_;
    from_name_ = (1 << 5) ? std::optional{String::read(reader)} : std::nullopt;
    int date_ = Int::read(reader);
    std::optional<int> channel_post_;
    channel_post_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> post_author_;
    post_author_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> saved_from_peer_;
    saved_from_peer_ = (1 << 4) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> saved_from_msg_id_;
    saved_from_msg_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> psa_type_;
    psa_type_ = (1 << 6) ? std::optional{String::read(reader)} : std::nullopt;
    return MessageFwdHeader(date_, imported_, from_id_, from_name_, channel_post_, post_author_, saved_from_peer_, saved_from_msg_id_, psa_type_);
}

std::string MessageFwdHeader::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= imported ? 1 << 7 : 0;
    flags |= from_id ? 1 << 0 : 0;
    flags |= from_name ? 1 << 5 : 0;
    flags |= channel_post ? 1 << 2 : 0;
    flags |= post_author ? 1 << 3 : 0;
    flags |= saved_from_peer ? 1 << 4 : 0;
    flags |= saved_from_msg_id ? 1 << 4 : 0;
    flags |= psa_type ? 1 << 6 : 0;

    if (from_id)
        buffer += from_id.value().write();

    if (from_name)
        buffer += String::write(from_name.value());
    buffer += Int::write(date);

    if (channel_post)
        buffer += Int::write(channel_post.value());

    if (post_author)
        buffer += String::write(post_author.value());

    if (saved_from_peer)
        buffer += saved_from_peer.value().write();

    if (saved_from_msg_id)
        buffer += Int::write(saved_from_msg_id.value());

    if (psa_type)
        buffer += String::write(psa_type.value());
    return buffer;
}

InputBotInlineMessageID::InputBotInlineMessageID(int dc_id_, long id_, long access_hash_) {}

InputBotInlineMessageID InputBotInlineMessageID::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputBotInlineMessageID(dc_id_, id_, access_hash_);
}

std::string InputBotInlineMessageID::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InlineBotSwitchPM::InlineBotSwitchPM(std::string text_, std::string start_param_) {}

InlineBotSwitchPM InlineBotSwitchPM::read(Reader reader)
{
    std::string text_ = String::read(reader);
    std::string start_param_ = String::read(reader);
    return InlineBotSwitchPM(text_, start_param_);
}

std::string InlineBotSwitchPM::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    buffer += String::write(start_param);
    return buffer;
}

TopPeer::TopPeer(TLObject peer_, double rating_) {}

TopPeer TopPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    double rating_ = Double::read(reader);
    return TopPeer(peer_, rating_);
}

std::string TopPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Double::write(rating);
    return buffer;
}
TopPeerCategoryBotsPM TopPeerCategoryBotsPM::read(Reader reader)
{
    return TopPeerCategoryBotsPM();
}

std::string TopPeerCategoryBotsPM::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryBotsInline TopPeerCategoryBotsInline::read(Reader reader)
{
    return TopPeerCategoryBotsInline();
}

std::string TopPeerCategoryBotsInline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryCorrespondents TopPeerCategoryCorrespondents::read(Reader reader)
{
    return TopPeerCategoryCorrespondents();
}

std::string TopPeerCategoryCorrespondents::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryGroups TopPeerCategoryGroups::read(Reader reader)
{
    return TopPeerCategoryGroups();
}

std::string TopPeerCategoryGroups::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryChannels TopPeerCategoryChannels::read(Reader reader)
{
    return TopPeerCategoryChannels();
}

std::string TopPeerCategoryChannels::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryPhoneCalls TopPeerCategoryPhoneCalls::read(Reader reader)
{
    return TopPeerCategoryPhoneCalls();
}

std::string TopPeerCategoryPhoneCalls::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryForwardUsers TopPeerCategoryForwardUsers::read(Reader reader)
{
    return TopPeerCategoryForwardUsers();
}

std::string TopPeerCategoryForwardUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
TopPeerCategoryForwardChats TopPeerCategoryForwardChats::read(Reader reader)
{
    return TopPeerCategoryForwardChats();
}

std::string TopPeerCategoryForwardChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

TopPeerCategoryPeers::TopPeerCategoryPeers(TLObject category_, int count_, std::vector<TLObject> peers_) {}

TopPeerCategoryPeers TopPeerCategoryPeers::read(Reader reader)
{
    TLObject category_ = std::get<TLObject>(TLObject::read(reader));
    int count_ = Int::read(reader);
    std::vector<TLObject> peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return TopPeerCategoryPeers(category_, count_, peers_);
}

std::string TopPeerCategoryPeers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += category.write();
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(peers);
    return buffer;
}

DraftMessageEmpty::DraftMessageEmpty(std::optional<int> date_) {}

DraftMessageEmpty DraftMessageEmpty::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> date_;
    date_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return DraftMessageEmpty(date_);
}

std::string DraftMessageEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= date ? 1 << 0 : 0;

    if (date)
        buffer += Int::write(date.value());
    return buffer;
}

DraftMessage::DraftMessage(std::string message_, int date_, std::optional<bool> no_webpage_, std::optional<int> reply_to_msg_id_, std::optional<std::vector<TLObject>> entities_) {}

DraftMessage DraftMessage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> no_webpage_;
    no_webpage_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<int> reply_to_msg_id_;
    reply_to_msg_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 3) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    int date_ = Int::read(reader);
    return DraftMessage(message_, date_, no_webpage_, reply_to_msg_id_, entities_);
}

std::string DraftMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= no_webpage ? 1 << 1 : 0;
    flags |= reply_to_msg_id ? 1 << 0 : 0;
    flags |= entities ? 1 << 3 : 0;

    if (reply_to_msg_id)
        buffer += Int::write(reply_to_msg_id.value());
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    buffer += Int::write(date);
    return buffer;
}

StickerSetCovered::StickerSetCovered(TLObject set_, TLObject cover_) {}

StickerSetCovered StickerSetCovered::read(Reader reader)
{
    TLObject set_ = std::get<TLObject>(TLObject::read(reader));
    TLObject cover_ = std::get<TLObject>(TLObject::read(reader));
    return StickerSetCovered(set_, cover_);
}

std::string StickerSetCovered::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += set.write();
    buffer += cover.write();
    return buffer;
}

StickerSetMultiCovered::StickerSetMultiCovered(TLObject set_, std::vector<TLObject> covers_) {}

StickerSetMultiCovered StickerSetMultiCovered::read(Reader reader)
{
    TLObject set_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> covers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return StickerSetMultiCovered(set_, covers_);
}

std::string StickerSetMultiCovered::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += set.write();
    buffer += Vector<TLObject>::write(covers);
    return buffer;
}

MaskCoords::MaskCoords(int n_, double x_, double y_, double zoom_) {}

MaskCoords MaskCoords::read(Reader reader)
{
    int n_ = Int::read(reader);
    double x_ = Double::read(reader);
    double y_ = Double::read(reader);
    double zoom_ = Double::read(reader);
    return MaskCoords(n_, x_, y_, zoom_);
}

std::string MaskCoords::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(n);
    buffer += Double::write(x);
    buffer += Double::write(y);
    buffer += Double::write(zoom);
    return buffer;
}

InputStickeredMediaPhoto::InputStickeredMediaPhoto(TLObject id_) {}

InputStickeredMediaPhoto InputStickeredMediaPhoto::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return InputStickeredMediaPhoto(id_);
}

std::string InputStickeredMediaPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

InputStickeredMediaDocument::InputStickeredMediaDocument(TLObject id_) {}

InputStickeredMediaDocument InputStickeredMediaDocument::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return InputStickeredMediaDocument(id_);
}

std::string InputStickeredMediaDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

Game::Game(long id_, long access_hash_, std::string short_name_, std::string title_, std::string description_, TLObject photo_, std::optional<TLObject> document_) {}

Game Game::read(Reader reader)
{
    int flags = Int::read(reader);
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string short_name_ = String::read(reader);
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> document_;
    document_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return Game(id_, access_hash_, short_name_, title_, description_, photo_, document_);
}

std::string Game::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= document ? 1 << 0 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += String::write(short_name);
    buffer += String::write(title);
    buffer += String::write(description);
    buffer += photo.write();

    if (document)
        buffer += document.value().write();
    return buffer;
}

InputGameID::InputGameID(long id_, long access_hash_) {}

InputGameID InputGameID::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputGameID(id_, access_hash_);
}

std::string InputGameID::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputGameShortName::InputGameShortName(TLObject bot_id_, std::string short_name_) {}

InputGameShortName InputGameShortName::read(Reader reader)
{
    TLObject bot_id_ = std::get<TLObject>(TLObject::read(reader));
    std::string short_name_ = String::read(reader);
    return InputGameShortName(bot_id_, short_name_);
}

std::string InputGameShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += bot_id.write();
    buffer += String::write(short_name);
    return buffer;
}

HighScore::HighScore(int pos_, int user_id_, int score_) {}

HighScore HighScore::read(Reader reader)
{
    int pos_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    int score_ = Int::read(reader);
    return HighScore(pos_, user_id_, score_);
}

std::string HighScore::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pos);
    buffer += Int::write(user_id);
    buffer += Int::write(score);
    return buffer;
}
TextEmpty TextEmpty::read(Reader reader)
{
    return TextEmpty();
}

std::string TextEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

TextPlain::TextPlain(std::string text_) {}

TextPlain TextPlain::read(Reader reader)
{
    std::string text_ = String::read(reader);
    return TextPlain(text_);
}

std::string TextPlain::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    return buffer;
}

TextBold::TextBold(TLObject text_) {}

TextBold TextBold::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextBold(text_);
}

std::string TextBold::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextItalic::TextItalic(TLObject text_) {}

TextItalic TextItalic::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextItalic(text_);
}

std::string TextItalic::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextUnderline::TextUnderline(TLObject text_) {}

TextUnderline TextUnderline::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextUnderline(text_);
}

std::string TextUnderline::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextStrike::TextStrike(TLObject text_) {}

TextStrike TextStrike::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextStrike(text_);
}

std::string TextStrike::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextFixed::TextFixed(TLObject text_) {}

TextFixed TextFixed::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextFixed(text_);
}

std::string TextFixed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextUrl::TextUrl(TLObject text_, std::string url_, long webpage_id_) {}

TextUrl TextUrl::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    std::string url_ = String::read(reader);
    long webpage_id_ = Long::read(reader);
    return TextUrl(text_, url_, webpage_id_);
}

std::string TextUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += String::write(url);
    buffer += Long::write(webpage_id);
    return buffer;
}

TextEmail::TextEmail(TLObject text_, std::string email_) {}

TextEmail TextEmail::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    std::string email_ = String::read(reader);
    return TextEmail(text_, email_);
}

std::string TextEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += String::write(email);
    return buffer;
}

TextConcat::TextConcat(std::vector<TLObject> texts_) {}

TextConcat TextConcat::read(Reader reader)
{
    std::vector<TLObject> texts_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return TextConcat(texts_);
}

std::string TextConcat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(texts);
    return buffer;
}

TextSubscript::TextSubscript(TLObject text_) {}

TextSubscript TextSubscript::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextSubscript(text_);
}

std::string TextSubscript::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextSuperscript::TextSuperscript(TLObject text_) {}

TextSuperscript TextSuperscript::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextSuperscript(text_);
}

std::string TextSuperscript::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextMarked::TextMarked(TLObject text_) {}

TextMarked TextMarked::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return TextMarked(text_);
}

std::string TextMarked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

TextPhone::TextPhone(TLObject text_, std::string phone_) {}

TextPhone TextPhone::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    std::string phone_ = String::read(reader);
    return TextPhone(text_, phone_);
}

std::string TextPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += String::write(phone);
    return buffer;
}

TextImage::TextImage(long document_id_, int w_, int h_) {}

TextImage TextImage::read(Reader reader)
{
    long document_id_ = Long::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    return TextImage(document_id_, w_, h_);
}

std::string TextImage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(document_id);
    buffer += Int::write(w);
    buffer += Int::write(h);
    return buffer;
}

TextAnchor::TextAnchor(TLObject text_, std::string name_) {}

TextAnchor TextAnchor::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    std::string name_ = String::read(reader);
    return TextAnchor(text_, name_);
}

std::string TextAnchor::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += String::write(name);
    return buffer;
}
PageBlockUnsupported PageBlockUnsupported::read(Reader reader)
{
    return PageBlockUnsupported();
}

std::string PageBlockUnsupported::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

PageBlockTitle::PageBlockTitle(TLObject text_) {}

PageBlockTitle PageBlockTitle::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockTitle(text_);
}

std::string PageBlockTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockSubtitle::PageBlockSubtitle(TLObject text_) {}

PageBlockSubtitle PageBlockSubtitle::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockSubtitle(text_);
}

std::string PageBlockSubtitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockAuthorDate::PageBlockAuthorDate(TLObject author_, int published_date_) {}

PageBlockAuthorDate PageBlockAuthorDate::read(Reader reader)
{
    TLObject author_ = std::get<TLObject>(TLObject::read(reader));
    int published_date_ = Int::read(reader);
    return PageBlockAuthorDate(author_, published_date_);
}

std::string PageBlockAuthorDate::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += author.write();
    buffer += Int::write(published_date);
    return buffer;
}

PageBlockHeader::PageBlockHeader(TLObject text_) {}

PageBlockHeader PageBlockHeader::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockHeader(text_);
}

std::string PageBlockHeader::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockSubheader::PageBlockSubheader(TLObject text_) {}

PageBlockSubheader PageBlockSubheader::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockSubheader(text_);
}

std::string PageBlockSubheader::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockParagraph::PageBlockParagraph(TLObject text_) {}

PageBlockParagraph PageBlockParagraph::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockParagraph(text_);
}

std::string PageBlockParagraph::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockPreformatted::PageBlockPreformatted(TLObject text_, std::string language_) {}

PageBlockPreformatted PageBlockPreformatted::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    std::string language_ = String::read(reader);
    return PageBlockPreformatted(text_, language_);
}

std::string PageBlockPreformatted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += String::write(language);
    return buffer;
}

PageBlockFooter::PageBlockFooter(TLObject text_) {}

PageBlockFooter PageBlockFooter::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockFooter(text_);
}

std::string PageBlockFooter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}
PageBlockDivider PageBlockDivider::read(Reader reader)
{
    return PageBlockDivider();
}

std::string PageBlockDivider::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

PageBlockAnchor::PageBlockAnchor(std::string name_) {}

PageBlockAnchor PageBlockAnchor::read(Reader reader)
{
    std::string name_ = String::read(reader);
    return PageBlockAnchor(name_);
}

std::string PageBlockAnchor::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(name);
    return buffer;
}

PageBlockList::PageBlockList(std::vector<TLObject> items_) {}

PageBlockList PageBlockList::read(Reader reader)
{
    std::vector<TLObject> items_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageBlockList(items_);
}

std::string PageBlockList::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(items);
    return buffer;
}

PageBlockBlockquote::PageBlockBlockquote(TLObject text_, TLObject caption_) {}

PageBlockBlockquote PageBlockBlockquote::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockBlockquote(text_, caption_);
}

std::string PageBlockBlockquote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += caption.write();
    return buffer;
}

PageBlockPullquote::PageBlockPullquote(TLObject text_, TLObject caption_) {}

PageBlockPullquote PageBlockPullquote::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockPullquote(text_, caption_);
}

std::string PageBlockPullquote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += caption.write();
    return buffer;
}

PageBlockPhoto::PageBlockPhoto(long photo_id_, TLObject caption_, std::optional<std::string> url_, std::optional<long> webpage_id_) {}

PageBlockPhoto PageBlockPhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    long photo_id_ = Long::read(reader);
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> url_;
    url_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<long> webpage_id_;
    webpage_id_ = (1 << 0) ? std::optional{Long::read(reader)} : std::nullopt;
    return PageBlockPhoto(photo_id_, caption_, url_, webpage_id_);
}

std::string PageBlockPhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= url ? 1 << 0 : 0;
    flags |= webpage_id ? 1 << 0 : 0;
    buffer += Long::write(photo_id);
    buffer += caption.write();

    if (url)
        buffer += String::write(url.value());

    if (webpage_id)
        buffer += Long::write(webpage_id.value());
    return buffer;
}

PageBlockVideo::PageBlockVideo(long video_id_, TLObject caption_, std::optional<bool> autoplay_, std::optional<bool> loop_) {}

PageBlockVideo PageBlockVideo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> autoplay_;
    autoplay_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> loop_;
    loop_ = (1 << 1) ? std::optional{true} : std::nullopt;
    long video_id_ = Long::read(reader);
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockVideo(video_id_, caption_, autoplay_, loop_);
}

std::string PageBlockVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= autoplay ? 1 << 0 : 0;
    flags |= loop ? 1 << 1 : 0;
    buffer += Long::write(video_id);
    buffer += caption.write();
    return buffer;
}

PageBlockCover::PageBlockCover(TLObject cover_) {}

PageBlockCover PageBlockCover::read(Reader reader)
{
    TLObject cover_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockCover(cover_);
}

std::string PageBlockCover::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += cover.write();
    return buffer;
}

PageBlockEmbed::PageBlockEmbed(TLObject caption_, std::optional<bool> full_width_, std::optional<bool> allow_scrolling_, std::optional<std::string> url_, std::optional<std::string> html_, std::optional<long> poster_photo_id_, std::optional<int> w_, std::optional<int> h_) {}

PageBlockEmbed PageBlockEmbed::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> full_width_;
    full_width_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> allow_scrolling_;
    allow_scrolling_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<std::string> url_;
    url_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> html_;
    html_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<long> poster_photo_id_;
    poster_photo_id_ = (1 << 4) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<int> w_;
    w_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> h_;
    h_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockEmbed(caption_, full_width_, allow_scrolling_, url_, html_, poster_photo_id_, w_, h_);
}

std::string PageBlockEmbed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= full_width ? 1 << 0 : 0;
    flags |= allow_scrolling ? 1 << 3 : 0;
    flags |= url ? 1 << 1 : 0;
    flags |= html ? 1 << 2 : 0;
    flags |= poster_photo_id ? 1 << 4 : 0;
    flags |= w ? 1 << 5 : 0;
    flags |= h ? 1 << 5 : 0;

    if (url)
        buffer += String::write(url.value());

    if (html)
        buffer += String::write(html.value());

    if (poster_photo_id)
        buffer += Long::write(poster_photo_id.value());

    if (w)
        buffer += Int::write(w.value());

    if (h)
        buffer += Int::write(h.value());
    buffer += caption.write();
    return buffer;
}

PageBlockEmbedPost::PageBlockEmbedPost(std::string url_, long webpage_id_, long author_photo_id_, std::string author_, int date_, std::vector<TLObject> blocks_, TLObject caption_) {}

PageBlockEmbedPost PageBlockEmbedPost::read(Reader reader)
{
    std::string url_ = String::read(reader);
    long webpage_id_ = Long::read(reader);
    long author_photo_id_ = Long::read(reader);
    std::string author_ = String::read(reader);
    int date_ = Int::read(reader);
    std::vector<TLObject> blocks_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockEmbedPost(url_, webpage_id_, author_photo_id_, author_, date_, blocks_, caption_);
}

std::string PageBlockEmbedPost::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Long::write(webpage_id);
    buffer += Long::write(author_photo_id);
    buffer += String::write(author);
    buffer += Int::write(date);
    buffer += Vector<TLObject>::write(blocks);
    buffer += caption.write();
    return buffer;
}

PageBlockCollage::PageBlockCollage(std::vector<TLObject> items_, TLObject caption_) {}

PageBlockCollage PageBlockCollage::read(Reader reader)
{
    std::vector<TLObject> items_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockCollage(items_, caption_);
}

std::string PageBlockCollage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(items);
    buffer += caption.write();
    return buffer;
}

PageBlockSlideshow::PageBlockSlideshow(std::vector<TLObject> items_, TLObject caption_) {}

PageBlockSlideshow PageBlockSlideshow::read(Reader reader)
{
    std::vector<TLObject> items_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockSlideshow(items_, caption_);
}

std::string PageBlockSlideshow::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(items);
    buffer += caption.write();
    return buffer;
}

PageBlockChannel::PageBlockChannel(TLObject channel_) {}

PageBlockChannel PageBlockChannel::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockChannel(channel_);
}

std::string PageBlockChannel::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    return buffer;
}

PageBlockAudio::PageBlockAudio(long audio_id_, TLObject caption_) {}

PageBlockAudio PageBlockAudio::read(Reader reader)
{
    long audio_id_ = Long::read(reader);
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockAudio(audio_id_, caption_);
}

std::string PageBlockAudio::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(audio_id);
    buffer += caption.write();
    return buffer;
}

PageBlockKicker::PageBlockKicker(TLObject text_) {}

PageBlockKicker PageBlockKicker::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockKicker(text_);
}

std::string PageBlockKicker::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageBlockTable::PageBlockTable(TLObject title_, std::vector<TLObject> rows_, std::optional<bool> bordered_, std::optional<bool> striped_) {}

PageBlockTable PageBlockTable::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> bordered_;
    bordered_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> striped_;
    striped_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject title_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> rows_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageBlockTable(title_, rows_, bordered_, striped_);
}

std::string PageBlockTable::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= bordered ? 1 << 0 : 0;
    flags |= striped ? 1 << 1 : 0;
    buffer += title.write();
    buffer += Vector<TLObject>::write(rows);
    return buffer;
}

PageBlockOrderedList::PageBlockOrderedList(std::vector<TLObject> items_) {}

PageBlockOrderedList PageBlockOrderedList::read(Reader reader)
{
    std::vector<TLObject> items_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageBlockOrderedList(items_);
}

std::string PageBlockOrderedList::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(items);
    return buffer;
}

PageBlockDetails::PageBlockDetails(std::vector<TLObject> blocks_, TLObject title_, std::optional<bool> open_) {}

PageBlockDetails PageBlockDetails::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> open_;
    open_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::vector<TLObject> blocks_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject title_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockDetails(blocks_, title_, open_);
}

std::string PageBlockDetails::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= open ? 1 << 0 : 0;
    buffer += Vector<TLObject>::write(blocks);
    buffer += title.write();
    return buffer;
}

PageBlockRelatedArticles::PageBlockRelatedArticles(TLObject title_, std::vector<TLObject> articles_) {}

PageBlockRelatedArticles PageBlockRelatedArticles::read(Reader reader)
{
    TLObject title_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> articles_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageBlockRelatedArticles(title_, articles_);
}

std::string PageBlockRelatedArticles::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += title.write();
    buffer += Vector<TLObject>::write(articles);
    return buffer;
}

PageBlockMap::PageBlockMap(TLObject geo_, int zoom_, int w_, int h_, TLObject caption_) {}

PageBlockMap PageBlockMap::read(Reader reader)
{
    TLObject geo_ = std::get<TLObject>(TLObject::read(reader));
    int zoom_ = Int::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    TLObject caption_ = std::get<TLObject>(TLObject::read(reader));
    return PageBlockMap(geo_, zoom_, w_, h_, caption_);
}

std::string PageBlockMap::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo.write();
    buffer += Int::write(zoom);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += caption.write();
    return buffer;
}
PhoneCallDiscardReasonMissed PhoneCallDiscardReasonMissed::read(Reader reader)
{
    return PhoneCallDiscardReasonMissed();
}

std::string PhoneCallDiscardReasonMissed::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PhoneCallDiscardReasonDisconnect PhoneCallDiscardReasonDisconnect::read(Reader reader)
{
    return PhoneCallDiscardReasonDisconnect();
}

std::string PhoneCallDiscardReasonDisconnect::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PhoneCallDiscardReasonHangup PhoneCallDiscardReasonHangup::read(Reader reader)
{
    return PhoneCallDiscardReasonHangup();
}

std::string PhoneCallDiscardReasonHangup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
PhoneCallDiscardReasonBusy PhoneCallDiscardReasonBusy::read(Reader reader)
{
    return PhoneCallDiscardReasonBusy();
}

std::string PhoneCallDiscardReasonBusy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

DataJSON::DataJSON(std::string data_) {}

DataJSON DataJSON::read(Reader reader)
{
    std::string data_ = String::read(reader);
    return DataJSON(data_);
}

std::string DataJSON::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(data);
    return buffer;
}

LabeledPrice::LabeledPrice(std::string label_, long amount_) {}

LabeledPrice LabeledPrice::read(Reader reader)
{
    std::string label_ = String::read(reader);
    long amount_ = Long::read(reader);
    return LabeledPrice(label_, amount_);
}

std::string LabeledPrice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(label);
    buffer += Long::write(amount);
    return buffer;
}

Invoice::Invoice(std::string currency_, std::vector<TLObject> prices_, std::optional<bool> test_, std::optional<bool> name_requested_, std::optional<bool> phone_requested_, std::optional<bool> email_requested_, std::optional<bool> shipping_address_requested_, std::optional<bool> flexible_, std::optional<bool> phone_to_provider_, std::optional<bool> email_to_provider_, std::optional<long> max_tip_amount_, std::optional<std::vector<long>> suggested_tip_amounts_) {}

Invoice Invoice::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> test_;
    test_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> name_requested_;
    name_requested_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> phone_requested_;
    phone_requested_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> email_requested_;
    email_requested_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> shipping_address_requested_;
    shipping_address_requested_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> flexible_;
    flexible_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> phone_to_provider_;
    phone_to_provider_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> email_to_provider_;
    email_to_provider_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::string currency_ = String::read(reader);
    std::vector<TLObject> prices_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<long> max_tip_amount_;
    max_tip_amount_ = (1 << 8) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<std::vector<long>> suggested_tip_amounts_;
    suggested_tip_amounts_ = (1 << 8) ? std::optional{std::get<std::vector<long>>(TLObject::read(reader))} : std::nullopt;
    return Invoice(currency_, prices_, test_, name_requested_, phone_requested_, email_requested_, shipping_address_requested_, flexible_, phone_to_provider_, email_to_provider_, max_tip_amount_, suggested_tip_amounts_);
}

std::string Invoice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= test ? 1 << 0 : 0;
    flags |= name_requested ? 1 << 1 : 0;
    flags |= phone_requested ? 1 << 2 : 0;
    flags |= email_requested ? 1 << 3 : 0;
    flags |= shipping_address_requested ? 1 << 4 : 0;
    flags |= flexible ? 1 << 5 : 0;
    flags |= phone_to_provider ? 1 << 6 : 0;
    flags |= email_to_provider ? 1 << 7 : 0;
    flags |= max_tip_amount ? 1 << 8 : 0;
    flags |= suggested_tip_amounts ? 1 << 8 : 0;
    buffer += String::write(currency);
    buffer += Vector<TLObject>::write(prices);

    if (max_tip_amount)
        buffer += Long::write(max_tip_amount.value());

    if (suggested_tip_amounts)
        buffer += Vector<long>::write(suggested_tip_amounts.value());
    return buffer;
}

PaymentCharge::PaymentCharge(std::string id_, std::string provider_charge_id_) {}

PaymentCharge PaymentCharge::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string provider_charge_id_ = String::read(reader);
    return PaymentCharge(id_, provider_charge_id_);
}

std::string PaymentCharge::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += String::write(provider_charge_id);
    return buffer;
}

PostAddress::PostAddress(std::string street_line1_, std::string street_line2_, std::string city_, std::string state_, std::string country_iso2_, std::string post_code_) {}

PostAddress PostAddress::read(Reader reader)
{
    std::string street_line1_ = String::read(reader);
    std::string street_line2_ = String::read(reader);
    std::string city_ = String::read(reader);
    std::string state_ = String::read(reader);
    std::string country_iso2_ = String::read(reader);
    std::string post_code_ = String::read(reader);
    return PostAddress(street_line1_, street_line2_, city_, state_, country_iso2_, post_code_);
}

std::string PostAddress::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(street_line1);
    buffer += String::write(street_line2);
    buffer += String::write(city);
    buffer += String::write(state);
    buffer += String::write(country_iso2);
    buffer += String::write(post_code);
    return buffer;
}

PaymentRequestedInfo::PaymentRequestedInfo(std::optional<std::string> name_, std::optional<std::string> phone_, std::optional<std::string> email_, std::optional<TLObject> shipping_address_) {}

PaymentRequestedInfo PaymentRequestedInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> name_;
    name_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> phone_;
    phone_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> email_;
    email_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> shipping_address_;
    shipping_address_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return PaymentRequestedInfo(name_, phone_, email_, shipping_address_);
}

std::string PaymentRequestedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= name ? 1 << 0 : 0;
    flags |= phone ? 1 << 1 : 0;
    flags |= email ? 1 << 2 : 0;
    flags |= shipping_address ? 1 << 3 : 0;

    if (name)
        buffer += String::write(name.value());

    if (phone)
        buffer += String::write(phone.value());

    if (email)
        buffer += String::write(email.value());

    if (shipping_address)
        buffer += shipping_address.value().write();
    return buffer;
}

PaymentSavedCredentialsCard::PaymentSavedCredentialsCard(std::string id_, std::string title_) {}

PaymentSavedCredentialsCard PaymentSavedCredentialsCard::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string title_ = String::read(reader);
    return PaymentSavedCredentialsCard(id_, title_);
}

std::string PaymentSavedCredentialsCard::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += String::write(title);
    return buffer;
}

WebDocument::WebDocument(std::string url_, long access_hash_, int size_, std::string mime_type_, std::vector<TLObject> attributes_) {}

WebDocument WebDocument::read(Reader reader)
{
    std::string url_ = String::read(reader);
    long access_hash_ = Long::read(reader);
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    std::vector<TLObject> attributes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return WebDocument(url_, access_hash_, size_, mime_type_, attributes_);
}

std::string WebDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Long::write(access_hash);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    buffer += Vector<TLObject>::write(attributes);
    return buffer;
}

WebDocumentNoProxy::WebDocumentNoProxy(std::string url_, int size_, std::string mime_type_, std::vector<TLObject> attributes_) {}

WebDocumentNoProxy WebDocumentNoProxy::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    std::vector<TLObject> attributes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return WebDocumentNoProxy(url_, size_, mime_type_, attributes_);
}

std::string WebDocumentNoProxy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    buffer += Vector<TLObject>::write(attributes);
    return buffer;
}

InputWebDocument::InputWebDocument(std::string url_, int size_, std::string mime_type_, std::vector<TLObject> attributes_) {}

InputWebDocument InputWebDocument::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    std::vector<TLObject> attributes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return InputWebDocument(url_, size_, mime_type_, attributes_);
}

std::string InputWebDocument::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    buffer += Vector<TLObject>::write(attributes);
    return buffer;
}

InputWebFileLocation::InputWebFileLocation(std::string url_, long access_hash_) {}

InputWebFileLocation InputWebFileLocation::read(Reader reader)
{
    std::string url_ = String::read(reader);
    long access_hash_ = Long::read(reader);
    return InputWebFileLocation(url_, access_hash_);
}

std::string InputWebFileLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Long::write(access_hash);
    return buffer;
}

InputWebFileGeoPointLocation::InputWebFileGeoPointLocation(TLObject geo_point_, long access_hash_, int w_, int h_, int zoom_, int scale_) {}

InputWebFileGeoPointLocation InputWebFileGeoPointLocation::read(Reader reader)
{
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    long access_hash_ = Long::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    int zoom_ = Int::read(reader);
    int scale_ = Int::read(reader);
    return InputWebFileGeoPointLocation(geo_point_, access_hash_, w_, h_, zoom_, scale_);
}

std::string InputWebFileGeoPointLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo_point.write();
    buffer += Long::write(access_hash);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += Int::write(zoom);
    buffer += Int::write(scale);
    return buffer;
}

InputPaymentCredentialsSaved::InputPaymentCredentialsSaved(std::string id_, std::string tmp_password_) {}

InputPaymentCredentialsSaved InputPaymentCredentialsSaved::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string tmp_password_ = Bytes::read(reader);
    return InputPaymentCredentialsSaved(id_, tmp_password_);
}

std::string InputPaymentCredentialsSaved::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += Bytes::write(tmp_password);
    return buffer;
}

InputPaymentCredentials::InputPaymentCredentials(TLObject data_, std::optional<bool> save_) {}

InputPaymentCredentials InputPaymentCredentials::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> save_;
    save_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject data_ = std::get<TLObject>(TLObject::read(reader));
    return InputPaymentCredentials(data_, save_);
}

std::string InputPaymentCredentials::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= save ? 1 << 0 : 0;
    buffer += data.write();
    return buffer;
}

InputPaymentCredentialsApplePay::InputPaymentCredentialsApplePay(TLObject payment_data_) {}

InputPaymentCredentialsApplePay InputPaymentCredentialsApplePay::read(Reader reader)
{
    TLObject payment_data_ = std::get<TLObject>(TLObject::read(reader));
    return InputPaymentCredentialsApplePay(payment_data_);
}

std::string InputPaymentCredentialsApplePay::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += payment_data.write();
    return buffer;
}

InputPaymentCredentialsGooglePay::InputPaymentCredentialsGooglePay(TLObject payment_token_) {}

InputPaymentCredentialsGooglePay InputPaymentCredentialsGooglePay::read(Reader reader)
{
    TLObject payment_token_ = std::get<TLObject>(TLObject::read(reader));
    return InputPaymentCredentialsGooglePay(payment_token_);
}

std::string InputPaymentCredentialsGooglePay::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += payment_token.write();
    return buffer;
}

ShippingOption::ShippingOption(std::string id_, std::string title_, std::vector<TLObject> prices_) {}

ShippingOption ShippingOption::read(Reader reader)
{
    std::string id_ = String::read(reader);
    std::string title_ = String::read(reader);
    std::vector<TLObject> prices_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ShippingOption(id_, title_, prices_);
}

std::string ShippingOption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(id);
    buffer += String::write(title);
    buffer += Vector<TLObject>::write(prices);
    return buffer;
}

InputStickerSetItem::InputStickerSetItem(TLObject document_, std::string emoji_, std::optional<TLObject> mask_coords_) {}

InputStickerSetItem InputStickerSetItem::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject document_ = std::get<TLObject>(TLObject::read(reader));
    std::string emoji_ = String::read(reader);
    std::optional<TLObject> mask_coords_;
    mask_coords_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputStickerSetItem(document_, emoji_, mask_coords_);
}

std::string InputStickerSetItem::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= mask_coords ? 1 << 0 : 0;
    buffer += document.write();
    buffer += String::write(emoji);

    if (mask_coords)
        buffer += mask_coords.value().write();
    return buffer;
}

InputPhoneCall::InputPhoneCall(long id_, long access_hash_) {}

InputPhoneCall InputPhoneCall::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputPhoneCall(id_, access_hash_);
}

std::string InputPhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

PhoneCallEmpty::PhoneCallEmpty(long id_) {}

PhoneCallEmpty PhoneCallEmpty::read(Reader reader)
{
    long id_ = Long::read(reader);
    return PhoneCallEmpty(id_);
}

std::string PhoneCallEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

PhoneCallWaiting::PhoneCallWaiting(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, TLObject protocol_, std::optional<bool> video_, std::optional<int> receive_date_) {}

PhoneCallWaiting PhoneCallWaiting::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 6) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<int> receive_date_;
    receive_date_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    return PhoneCallWaiting(id_, access_hash_, date_, admin_id_, participant_id_, protocol_, video_, receive_date_);
}

std::string PhoneCallWaiting::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 6 : 0;
    flags |= receive_date ? 1 << 0 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += protocol.write();

    if (receive_date)
        buffer += Int::write(receive_date.value());
    return buffer;
}

PhoneCallRequested::PhoneCallRequested(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_hash_, TLObject protocol_, std::optional<bool> video_) {}

PhoneCallRequested PhoneCallRequested::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 6) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    std::string g_a_hash_ = Bytes::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    return PhoneCallRequested(id_, access_hash_, date_, admin_id_, participant_id_, g_a_hash_, protocol_, video_);
}

std::string PhoneCallRequested::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 6 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += Bytes::write(g_a_hash);
    buffer += protocol.write();
    return buffer;
}

PhoneCallAccepted::PhoneCallAccepted(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_b_, TLObject protocol_, std::optional<bool> video_) {}

PhoneCallAccepted PhoneCallAccepted::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> video_;
    video_ = (1 << 6) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    std::string g_b_ = Bytes::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    return PhoneCallAccepted(id_, access_hash_, date_, admin_id_, participant_id_, g_b_, protocol_, video_);
}

std::string PhoneCallAccepted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video ? 1 << 6 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += Bytes::write(g_b);
    buffer += protocol.write();
    return buffer;
}

PhoneCall::PhoneCall(long id_, long access_hash_, int date_, int admin_id_, int participant_id_, std::string g_a_or_b_, long key_fingerprint_, TLObject protocol_, std::vector<TLObject> connections_, int start_date_, std::optional<bool> p2p_allowed_, std::optional<bool> video_) {}

PhoneCall PhoneCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> p2p_allowed_;
    p2p_allowed_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_;
    video_ = (1 << 6) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int date_ = Int::read(reader);
    int admin_id_ = Int::read(reader);
    int participant_id_ = Int::read(reader);
    std::string g_a_or_b_ = Bytes::read(reader);
    long key_fingerprint_ = Long::read(reader);
    TLObject protocol_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> connections_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    int start_date_ = Int::read(reader);
    return PhoneCall(id_, access_hash_, date_, admin_id_, participant_id_, g_a_or_b_, key_fingerprint_, protocol_, connections_, start_date_, p2p_allowed_, video_);
}

std::string PhoneCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= p2p_allowed ? 1 << 5 : 0;
    flags |= video ? 1 << 6 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(date);
    buffer += Int::write(admin_id);
    buffer += Int::write(participant_id);
    buffer += Bytes::write(g_a_or_b);
    buffer += Long::write(key_fingerprint);
    buffer += protocol.write();
    buffer += Vector<TLObject>::write(connections);
    buffer += Int::write(start_date);
    return buffer;
}

PhoneCallDiscarded::PhoneCallDiscarded(long id_, std::optional<bool> need_rating_, std::optional<bool> need_debug_, std::optional<bool> video_, std::optional<TLObject> reason_, std::optional<int> duration_) {}

PhoneCallDiscarded PhoneCallDiscarded::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> need_rating_;
    need_rating_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> need_debug_;
    need_debug_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_;
    video_ = (1 << 6) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    std::optional<TLObject> reason_;
    reason_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> duration_;
    duration_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return PhoneCallDiscarded(id_, need_rating_, need_debug_, video_, reason_, duration_);
}

std::string PhoneCallDiscarded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= need_rating ? 1 << 2 : 0;
    flags |= need_debug ? 1 << 3 : 0;
    flags |= video ? 1 << 6 : 0;
    flags |= reason ? 1 << 0 : 0;
    flags |= duration ? 1 << 1 : 0;
    buffer += Long::write(id);

    if (reason)
        buffer += reason.value().write();

    if (duration)
        buffer += Int::write(duration.value());
    return buffer;
}

PhoneConnection::PhoneConnection(long id_, std::string ip_, std::string ipv6_, int port_, std::string peer_tag_) {}

PhoneConnection PhoneConnection::read(Reader reader)
{
    long id_ = Long::read(reader);
    std::string ip_ = String::read(reader);
    std::string ipv6_ = String::read(reader);
    int port_ = Int::read(reader);
    std::string peer_tag_ = Bytes::read(reader);
    return PhoneConnection(id_, ip_, ipv6_, port_, peer_tag_);
}

std::string PhoneConnection::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += String::write(ip);
    buffer += String::write(ipv6);
    buffer += Int::write(port);
    buffer += Bytes::write(peer_tag);
    return buffer;
}

PhoneConnectionWebrtc::PhoneConnectionWebrtc(long id_, std::string ip_, std::string ipv6_, int port_, std::string username_, std::string password_, std::optional<bool> turn_, std::optional<bool> stun_) {}

PhoneConnectionWebrtc PhoneConnectionWebrtc::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> turn_;
    turn_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> stun_;
    stun_ = (1 << 1) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    std::string ip_ = String::read(reader);
    std::string ipv6_ = String::read(reader);
    int port_ = Int::read(reader);
    std::string username_ = String::read(reader);
    std::string password_ = String::read(reader);
    return PhoneConnectionWebrtc(id_, ip_, ipv6_, port_, username_, password_, turn_, stun_);
}

std::string PhoneConnectionWebrtc::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= turn ? 1 << 0 : 0;
    flags |= stun ? 1 << 1 : 0;
    buffer += Long::write(id);
    buffer += String::write(ip);
    buffer += String::write(ipv6);
    buffer += Int::write(port);
    buffer += String::write(username);
    buffer += String::write(password);
    return buffer;
}

PhoneCallProtocol::PhoneCallProtocol(int min_layer_, int max_layer_, std::vector<std::string> library_versions_, std::optional<bool> udp_p2p_, std::optional<bool> udp_reflector_) {}

PhoneCallProtocol PhoneCallProtocol::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> udp_p2p_;
    udp_p2p_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> udp_reflector_;
    udp_reflector_ = (1 << 1) ? std::optional{true} : std::nullopt;
    int min_layer_ = Int::read(reader);
    int max_layer_ = Int::read(reader);
    std::vector<std::string> library_versions_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return PhoneCallProtocol(min_layer_, max_layer_, library_versions_, udp_p2p_, udp_reflector_);
}

std::string PhoneCallProtocol::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= udp_p2p ? 1 << 0 : 0;
    flags |= udp_reflector ? 1 << 1 : 0;
    buffer += Int::write(min_layer);
    buffer += Int::write(max_layer);
    buffer += Vector<std::string>::write(library_versions);
    return buffer;
}

CdnPublicKey::CdnPublicKey(int dc_id_, std::string public_key_) {}

CdnPublicKey CdnPublicKey::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    std::string public_key_ = String::read(reader);
    return CdnPublicKey(dc_id_, public_key_);
}

std::string CdnPublicKey::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    buffer += String::write(public_key);
    return buffer;
}

CdnConfig::CdnConfig(std::vector<TLObject> public_keys_) {}

CdnConfig CdnConfig::read(Reader reader)
{
    std::vector<TLObject> public_keys_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return CdnConfig(public_keys_);
}

std::string CdnConfig::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(public_keys);
    return buffer;
}

LangPackString::LangPackString(std::string key_, std::string value_) {}

LangPackString LangPackString::read(Reader reader)
{
    std::string key_ = String::read(reader);
    std::string value_ = String::read(reader);
    return LangPackString(key_, value_);
}

std::string LangPackString::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(key);
    buffer += String::write(value);
    return buffer;
}

LangPackStringPluralized::LangPackStringPluralized(std::string key_, std::string other_value_, std::optional<std::string> zero_value_, std::optional<std::string> one_value_, std::optional<std::string> two_value_, std::optional<std::string> few_value_, std::optional<std::string> many_value_) {}

LangPackStringPluralized LangPackStringPluralized::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string key_ = String::read(reader);
    std::optional<std::string> zero_value_;
    zero_value_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> one_value_;
    one_value_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> two_value_;
    two_value_ = (1 << 2) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> few_value_;
    few_value_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> many_value_;
    many_value_ = (1 << 4) ? std::optional{String::read(reader)} : std::nullopt;
    std::string other_value_ = String::read(reader);
    return LangPackStringPluralized(key_, other_value_, zero_value_, one_value_, two_value_, few_value_, many_value_);
}

std::string LangPackStringPluralized::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= zero_value ? 1 << 0 : 0;
    flags |= one_value ? 1 << 1 : 0;
    flags |= two_value ? 1 << 2 : 0;
    flags |= few_value ? 1 << 3 : 0;
    flags |= many_value ? 1 << 4 : 0;
    buffer += String::write(key);

    if (zero_value)
        buffer += String::write(zero_value.value());

    if (one_value)
        buffer += String::write(one_value.value());

    if (two_value)
        buffer += String::write(two_value.value());

    if (few_value)
        buffer += String::write(few_value.value());

    if (many_value)
        buffer += String::write(many_value.value());
    buffer += String::write(other_value);
    return buffer;
}

LangPackStringDeleted::LangPackStringDeleted(std::string key_) {}

LangPackStringDeleted LangPackStringDeleted::read(Reader reader)
{
    std::string key_ = String::read(reader);
    return LangPackStringDeleted(key_);
}

std::string LangPackStringDeleted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(key);
    return buffer;
}

LangPackDifference::LangPackDifference(std::string lang_code_, int from_version_, int version_, std::vector<TLObject> strings_) {}

LangPackDifference LangPackDifference::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    int version_ = Int::read(reader);
    std::vector<TLObject> strings_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return LangPackDifference(lang_code_, from_version_, version_, strings_);
}

std::string LangPackDifference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    buffer += Int::write(version);
    buffer += Vector<TLObject>::write(strings);
    return buffer;
}

LangPackLanguage::LangPackLanguage(std::string name_, std::string native_name_, std::string lang_code_, std::string plural_code_, int strings_count_, int translated_count_, std::string translations_url_, std::optional<bool> official_, std::optional<bool> rtl_, std::optional<bool> beta_, std::optional<std::string> base_lang_code_) {}

LangPackLanguage LangPackLanguage::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> official_;
    official_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> rtl_;
    rtl_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> beta_;
    beta_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string name_ = String::read(reader);
    std::string native_name_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    std::optional<std::string> base_lang_code_;
    base_lang_code_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::string plural_code_ = String::read(reader);
    int strings_count_ = Int::read(reader);
    int translated_count_ = Int::read(reader);
    std::string translations_url_ = String::read(reader);
    return LangPackLanguage(name_, native_name_, lang_code_, plural_code_, strings_count_, translated_count_, translations_url_, official_, rtl_, beta_, base_lang_code_);
}

std::string LangPackLanguage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= official ? 1 << 0 : 0;
    flags |= rtl ? 1 << 2 : 0;
    flags |= beta ? 1 << 3 : 0;
    flags |= base_lang_code ? 1 << 1 : 0;
    buffer += String::write(name);
    buffer += String::write(native_name);
    buffer += String::write(lang_code);

    if (base_lang_code)
        buffer += String::write(base_lang_code.value());
    buffer += String::write(plural_code);
    buffer += Int::write(strings_count);
    buffer += Int::write(translated_count);
    buffer += String::write(translations_url);
    return buffer;
}

ChannelAdminLogEventActionChangeTitle::ChannelAdminLogEventActionChangeTitle(std::string prev_value_, std::string new_value_) {}

ChannelAdminLogEventActionChangeTitle ChannelAdminLogEventActionChangeTitle::read(Reader reader)
{
    std::string prev_value_ = String::read(reader);
    std::string new_value_ = String::read(reader);
    return ChannelAdminLogEventActionChangeTitle(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeTitle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(prev_value);
    buffer += String::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionChangeAbout::ChannelAdminLogEventActionChangeAbout(std::string prev_value_, std::string new_value_) {}

ChannelAdminLogEventActionChangeAbout ChannelAdminLogEventActionChangeAbout::read(Reader reader)
{
    std::string prev_value_ = String::read(reader);
    std::string new_value_ = String::read(reader);
    return ChannelAdminLogEventActionChangeAbout(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeAbout::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(prev_value);
    buffer += String::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionChangeUsername::ChannelAdminLogEventActionChangeUsername(std::string prev_value_, std::string new_value_) {}

ChannelAdminLogEventActionChangeUsername ChannelAdminLogEventActionChangeUsername::read(Reader reader)
{
    std::string prev_value_ = String::read(reader);
    std::string new_value_ = String::read(reader);
    return ChannelAdminLogEventActionChangeUsername(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeUsername::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(prev_value);
    buffer += String::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionChangePhoto::ChannelAdminLogEventActionChangePhoto(TLObject prev_photo_, TLObject new_photo_) {}

ChannelAdminLogEventActionChangePhoto ChannelAdminLogEventActionChangePhoto::read(Reader reader)
{
    TLObject prev_photo_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_photo_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionChangePhoto(prev_photo_, new_photo_);
}

std::string ChannelAdminLogEventActionChangePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_photo.write();
    buffer += new_photo.write();
    return buffer;
}

ChannelAdminLogEventActionToggleInvites::ChannelAdminLogEventActionToggleInvites(bool new_value_) {}

ChannelAdminLogEventActionToggleInvites ChannelAdminLogEventActionToggleInvites::read(Reader reader)
{
    bool new_value_ = Bool::read(reader);
    return ChannelAdminLogEventActionToggleInvites(new_value_);
}

std::string ChannelAdminLogEventActionToggleInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionToggleSignatures::ChannelAdminLogEventActionToggleSignatures(bool new_value_) {}

ChannelAdminLogEventActionToggleSignatures ChannelAdminLogEventActionToggleSignatures::read(Reader reader)
{
    bool new_value_ = Bool::read(reader);
    return ChannelAdminLogEventActionToggleSignatures(new_value_);
}

std::string ChannelAdminLogEventActionToggleSignatures::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionUpdatePinned::ChannelAdminLogEventActionUpdatePinned(TLObject message_) {}

ChannelAdminLogEventActionUpdatePinned ChannelAdminLogEventActionUpdatePinned::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionUpdatePinned(message_);
}

std::string ChannelAdminLogEventActionUpdatePinned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    return buffer;
}

ChannelAdminLogEventActionEditMessage::ChannelAdminLogEventActionEditMessage(TLObject prev_message_, TLObject new_message_) {}

ChannelAdminLogEventActionEditMessage ChannelAdminLogEventActionEditMessage::read(Reader reader)
{
    TLObject prev_message_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_message_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionEditMessage(prev_message_, new_message_);
}

std::string ChannelAdminLogEventActionEditMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_message.write();
    buffer += new_message.write();
    return buffer;
}

ChannelAdminLogEventActionDeleteMessage::ChannelAdminLogEventActionDeleteMessage(TLObject message_) {}

ChannelAdminLogEventActionDeleteMessage ChannelAdminLogEventActionDeleteMessage::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionDeleteMessage(message_);
}

std::string ChannelAdminLogEventActionDeleteMessage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    return buffer;
}
ChannelAdminLogEventActionParticipantJoin ChannelAdminLogEventActionParticipantJoin::read(Reader reader)
{
    return ChannelAdminLogEventActionParticipantJoin();
}

std::string ChannelAdminLogEventActionParticipantJoin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
ChannelAdminLogEventActionParticipantLeave ChannelAdminLogEventActionParticipantLeave::read(Reader reader)
{
    return ChannelAdminLogEventActionParticipantLeave();
}

std::string ChannelAdminLogEventActionParticipantLeave::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelAdminLogEventActionParticipantInvite::ChannelAdminLogEventActionParticipantInvite(TLObject participant_) {}

ChannelAdminLogEventActionParticipantInvite ChannelAdminLogEventActionParticipantInvite::read(Reader reader)
{
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantInvite(participant_);
}

std::string ChannelAdminLogEventActionParticipantInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    return buffer;
}

ChannelAdminLogEventActionParticipantToggleBan::ChannelAdminLogEventActionParticipantToggleBan(TLObject prev_participant_, TLObject new_participant_) {}

ChannelAdminLogEventActionParticipantToggleBan ChannelAdminLogEventActionParticipantToggleBan::read(Reader reader)
{
    TLObject prev_participant_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantToggleBan(prev_participant_, new_participant_);
}

std::string ChannelAdminLogEventActionParticipantToggleBan::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_participant.write();
    buffer += new_participant.write();
    return buffer;
}

ChannelAdminLogEventActionParticipantToggleAdmin::ChannelAdminLogEventActionParticipantToggleAdmin(TLObject prev_participant_, TLObject new_participant_) {}

ChannelAdminLogEventActionParticipantToggleAdmin ChannelAdminLogEventActionParticipantToggleAdmin::read(Reader reader)
{
    TLObject prev_participant_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantToggleAdmin(prev_participant_, new_participant_);
}

std::string ChannelAdminLogEventActionParticipantToggleAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_participant.write();
    buffer += new_participant.write();
    return buffer;
}

ChannelAdminLogEventActionChangeStickerSet::ChannelAdminLogEventActionChangeStickerSet(TLObject prev_stickerset_, TLObject new_stickerset_) {}

ChannelAdminLogEventActionChangeStickerSet ChannelAdminLogEventActionChangeStickerSet::read(Reader reader)
{
    TLObject prev_stickerset_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_stickerset_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionChangeStickerSet(prev_stickerset_, new_stickerset_);
}

std::string ChannelAdminLogEventActionChangeStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_stickerset.write();
    buffer += new_stickerset.write();
    return buffer;
}

ChannelAdminLogEventActionTogglePreHistoryHidden::ChannelAdminLogEventActionTogglePreHistoryHidden(bool new_value_) {}

ChannelAdminLogEventActionTogglePreHistoryHidden ChannelAdminLogEventActionTogglePreHistoryHidden::read(Reader reader)
{
    bool new_value_ = Bool::read(reader);
    return ChannelAdminLogEventActionTogglePreHistoryHidden(new_value_);
}

std::string ChannelAdminLogEventActionTogglePreHistoryHidden::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionDefaultBannedRights::ChannelAdminLogEventActionDefaultBannedRights(TLObject prev_banned_rights_, TLObject new_banned_rights_) {}

ChannelAdminLogEventActionDefaultBannedRights ChannelAdminLogEventActionDefaultBannedRights::read(Reader reader)
{
    TLObject prev_banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_banned_rights_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionDefaultBannedRights(prev_banned_rights_, new_banned_rights_);
}

std::string ChannelAdminLogEventActionDefaultBannedRights::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_banned_rights.write();
    buffer += new_banned_rights.write();
    return buffer;
}

ChannelAdminLogEventActionStopPoll::ChannelAdminLogEventActionStopPoll(TLObject message_) {}

ChannelAdminLogEventActionStopPoll ChannelAdminLogEventActionStopPoll::read(Reader reader)
{
    TLObject message_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionStopPoll(message_);
}

std::string ChannelAdminLogEventActionStopPoll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += message.write();
    return buffer;
}

ChannelAdminLogEventActionChangeLinkedChat::ChannelAdminLogEventActionChangeLinkedChat(int prev_value_, int new_value_) {}

ChannelAdminLogEventActionChangeLinkedChat ChannelAdminLogEventActionChangeLinkedChat::read(Reader reader)
{
    int prev_value_ = Int::read(reader);
    int new_value_ = Int::read(reader);
    return ChannelAdminLogEventActionChangeLinkedChat(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeLinkedChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(prev_value);
    buffer += Int::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionChangeLocation::ChannelAdminLogEventActionChangeLocation(TLObject prev_value_, TLObject new_value_) {}

ChannelAdminLogEventActionChangeLocation ChannelAdminLogEventActionChangeLocation::read(Reader reader)
{
    TLObject prev_value_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_value_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionChangeLocation(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_value.write();
    buffer += new_value.write();
    return buffer;
}

ChannelAdminLogEventActionToggleSlowMode::ChannelAdminLogEventActionToggleSlowMode(int prev_value_, int new_value_) {}

ChannelAdminLogEventActionToggleSlowMode ChannelAdminLogEventActionToggleSlowMode::read(Reader reader)
{
    int prev_value_ = Int::read(reader);
    int new_value_ = Int::read(reader);
    return ChannelAdminLogEventActionToggleSlowMode(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionToggleSlowMode::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(prev_value);
    buffer += Int::write(new_value);
    return buffer;
}

ChannelAdminLogEventActionStartGroupCall::ChannelAdminLogEventActionStartGroupCall(TLObject call_) {}

ChannelAdminLogEventActionStartGroupCall ChannelAdminLogEventActionStartGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionStartGroupCall(call_);
}

std::string ChannelAdminLogEventActionStartGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

ChannelAdminLogEventActionDiscardGroupCall::ChannelAdminLogEventActionDiscardGroupCall(TLObject call_) {}

ChannelAdminLogEventActionDiscardGroupCall ChannelAdminLogEventActionDiscardGroupCall::read(Reader reader)
{
    TLObject call_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionDiscardGroupCall(call_);
}

std::string ChannelAdminLogEventActionDiscardGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += call.write();
    return buffer;
}

ChannelAdminLogEventActionParticipantMute::ChannelAdminLogEventActionParticipantMute(TLObject participant_) {}

ChannelAdminLogEventActionParticipantMute ChannelAdminLogEventActionParticipantMute::read(Reader reader)
{
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantMute(participant_);
}

std::string ChannelAdminLogEventActionParticipantMute::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    return buffer;
}

ChannelAdminLogEventActionParticipantUnmute::ChannelAdminLogEventActionParticipantUnmute(TLObject participant_) {}

ChannelAdminLogEventActionParticipantUnmute ChannelAdminLogEventActionParticipantUnmute::read(Reader reader)
{
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantUnmute(participant_);
}

std::string ChannelAdminLogEventActionParticipantUnmute::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    return buffer;
}

ChannelAdminLogEventActionToggleGroupCallSetting::ChannelAdminLogEventActionToggleGroupCallSetting(bool join_muted_) {}

ChannelAdminLogEventActionToggleGroupCallSetting ChannelAdminLogEventActionToggleGroupCallSetting::read(Reader reader)
{
    bool join_muted_ = Bool::read(reader);
    return ChannelAdminLogEventActionToggleGroupCallSetting(join_muted_);
}

std::string ChannelAdminLogEventActionToggleGroupCallSetting::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(join_muted);
    return buffer;
}

ChannelAdminLogEventActionParticipantJoinByInvite::ChannelAdminLogEventActionParticipantJoinByInvite(TLObject invite_) {}

ChannelAdminLogEventActionParticipantJoinByInvite ChannelAdminLogEventActionParticipantJoinByInvite::read(Reader reader)
{
    TLObject invite_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantJoinByInvite(invite_);
}

std::string ChannelAdminLogEventActionParticipantJoinByInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += invite.write();
    return buffer;
}

ChannelAdminLogEventActionExportedInviteDelete::ChannelAdminLogEventActionExportedInviteDelete(TLObject invite_) {}

ChannelAdminLogEventActionExportedInviteDelete ChannelAdminLogEventActionExportedInviteDelete::read(Reader reader)
{
    TLObject invite_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionExportedInviteDelete(invite_);
}

std::string ChannelAdminLogEventActionExportedInviteDelete::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += invite.write();
    return buffer;
}

ChannelAdminLogEventActionExportedInviteRevoke::ChannelAdminLogEventActionExportedInviteRevoke(TLObject invite_) {}

ChannelAdminLogEventActionExportedInviteRevoke ChannelAdminLogEventActionExportedInviteRevoke::read(Reader reader)
{
    TLObject invite_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionExportedInviteRevoke(invite_);
}

std::string ChannelAdminLogEventActionExportedInviteRevoke::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += invite.write();
    return buffer;
}

ChannelAdminLogEventActionExportedInviteEdit::ChannelAdminLogEventActionExportedInviteEdit(TLObject prev_invite_, TLObject new_invite_) {}

ChannelAdminLogEventActionExportedInviteEdit ChannelAdminLogEventActionExportedInviteEdit::read(Reader reader)
{
    TLObject prev_invite_ = std::get<TLObject>(TLObject::read(reader));
    TLObject new_invite_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionExportedInviteEdit(prev_invite_, new_invite_);
}

std::string ChannelAdminLogEventActionExportedInviteEdit::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += prev_invite.write();
    buffer += new_invite.write();
    return buffer;
}

ChannelAdminLogEventActionParticipantVolume::ChannelAdminLogEventActionParticipantVolume(TLObject participant_) {}

ChannelAdminLogEventActionParticipantVolume ChannelAdminLogEventActionParticipantVolume::read(Reader reader)
{
    TLObject participant_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEventActionParticipantVolume(participant_);
}

std::string ChannelAdminLogEventActionParticipantVolume::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    return buffer;
}

ChannelAdminLogEventActionChangeHistoryTTL::ChannelAdminLogEventActionChangeHistoryTTL(int prev_value_, int new_value_) {}

ChannelAdminLogEventActionChangeHistoryTTL ChannelAdminLogEventActionChangeHistoryTTL::read(Reader reader)
{
    int prev_value_ = Int::read(reader);
    int new_value_ = Int::read(reader);
    return ChannelAdminLogEventActionChangeHistoryTTL(prev_value_, new_value_);
}

std::string ChannelAdminLogEventActionChangeHistoryTTL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(prev_value);
    buffer += Int::write(new_value);
    return buffer;
}

ChannelAdminLogEvent::ChannelAdminLogEvent(long id_, int date_, int user_id_, TLObject action_) {}

ChannelAdminLogEvent ChannelAdminLogEvent::read(Reader reader)
{
    long id_ = Long::read(reader);
    int date_ = Int::read(reader);
    int user_id_ = Int::read(reader);
    TLObject action_ = std::get<TLObject>(TLObject::read(reader));
    return ChannelAdminLogEvent(id_, date_, user_id_, action_);
}

std::string ChannelAdminLogEvent::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(date);
    buffer += Int::write(user_id);
    buffer += action.write();
    return buffer;
}

ChannelAdminLogEventsFilter::ChannelAdminLogEventsFilter(std::optional<bool> join_, std::optional<bool> leave_, std::optional<bool> invite_, std::optional<bool> ban_, std::optional<bool> unban_, std::optional<bool> kick_, std::optional<bool> unkick_, std::optional<bool> promote_, std::optional<bool> demote_, std::optional<bool> info_, std::optional<bool> settings_, std::optional<bool> pinned_, std::optional<bool> edit_, std::optional<bool> delete__, std::optional<bool> group_call_, std::optional<bool> invites_) {}

ChannelAdminLogEventsFilter ChannelAdminLogEventsFilter::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> join_;
    join_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> leave_;
    leave_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> invite_;
    invite_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> ban_;
    ban_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> unban_;
    unban_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> kick_;
    kick_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> unkick_;
    unkick_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> promote_;
    promote_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> demote_;
    demote_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> info_;
    info_ = (1 << 9) ? std::optional{true} : std::nullopt;
    std::optional<bool> settings_;
    settings_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> pinned_;
    pinned_ = (1 << 11) ? std::optional{true} : std::nullopt;
    std::optional<bool> edit_;
    edit_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> delete__;
    delete__ = (1 << 13) ? std::optional{true} : std::nullopt;
    std::optional<bool> group_call_;
    group_call_ = (1 << 14) ? std::optional{true} : std::nullopt;
    std::optional<bool> invites_;
    invites_ = (1 << 15) ? std::optional{true} : std::nullopt;
    return ChannelAdminLogEventsFilter(join_, leave_, invite_, ban_, unban_, kick_, unkick_, promote_, demote_, info_, settings_, pinned_, edit_, delete__, group_call_, invites_);
}

std::string ChannelAdminLogEventsFilter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= join ? 1 << 0 : 0;
    flags |= leave ? 1 << 1 : 0;
    flags |= invite ? 1 << 2 : 0;
    flags |= ban ? 1 << 3 : 0;
    flags |= unban ? 1 << 4 : 0;
    flags |= kick ? 1 << 5 : 0;
    flags |= unkick ? 1 << 6 : 0;
    flags |= promote ? 1 << 7 : 0;
    flags |= demote ? 1 << 8 : 0;
    flags |= info ? 1 << 9 : 0;
    flags |= settings ? 1 << 10 : 0;
    flags |= pinned ? 1 << 11 : 0;
    flags |= edit ? 1 << 12 : 0;
    flags |= delete_ ? 1 << 13 : 0;
    flags |= group_call ? 1 << 14 : 0;
    flags |= invites ? 1 << 15 : 0;
    return buffer;
}

PopularContact::PopularContact(long client_id_, int importers_) {}

PopularContact PopularContact::read(Reader reader)
{
    long client_id_ = Long::read(reader);
    int importers_ = Int::read(reader);
    return PopularContact(client_id_, importers_);
}

std::string PopularContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(client_id);
    buffer += Int::write(importers);
    return buffer;
}

RecentMeUrlUnknown::RecentMeUrlUnknown(std::string url_) {}

RecentMeUrlUnknown RecentMeUrlUnknown::read(Reader reader)
{
    std::string url_ = String::read(reader);
    return RecentMeUrlUnknown(url_);
}

std::string RecentMeUrlUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    return buffer;
}

RecentMeUrlUser::RecentMeUrlUser(std::string url_, int user_id_) {}

RecentMeUrlUser RecentMeUrlUser::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int user_id_ = Int::read(reader);
    return RecentMeUrlUser(url_, user_id_);
}

std::string RecentMeUrlUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(user_id);
    return buffer;
}

RecentMeUrlChat::RecentMeUrlChat(std::string url_, int chat_id_) {}

RecentMeUrlChat RecentMeUrlChat::read(Reader reader)
{
    std::string url_ = String::read(reader);
    int chat_id_ = Int::read(reader);
    return RecentMeUrlChat(url_, chat_id_);
}

std::string RecentMeUrlChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += Int::write(chat_id);
    return buffer;
}

RecentMeUrlChatInvite::RecentMeUrlChatInvite(std::string url_, TLObject chat_invite_) {}

RecentMeUrlChatInvite RecentMeUrlChatInvite::read(Reader reader)
{
    std::string url_ = String::read(reader);
    TLObject chat_invite_ = std::get<TLObject>(TLObject::read(reader));
    return RecentMeUrlChatInvite(url_, chat_invite_);
}

std::string RecentMeUrlChatInvite::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += chat_invite.write();
    return buffer;
}

RecentMeUrlStickerSet::RecentMeUrlStickerSet(std::string url_, TLObject set_) {}

RecentMeUrlStickerSet RecentMeUrlStickerSet::read(Reader reader)
{
    std::string url_ = String::read(reader);
    TLObject set_ = std::get<TLObject>(TLObject::read(reader));
    return RecentMeUrlStickerSet(url_, set_);
}

std::string RecentMeUrlStickerSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += set.write();
    return buffer;
}

InputSingleMedia::InputSingleMedia(TLObject media_, long random_id_, std::string message_, std::optional<std::vector<TLObject>> entities_) {}

InputSingleMedia InputSingleMedia::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject media_ = std::get<TLObject>(TLObject::read(reader));
    long random_id_ = Long::read(reader);
    std::string message_ = String::read(reader);
    std::optional<std::vector<TLObject>> entities_;
    entities_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return InputSingleMedia(media_, random_id_, message_, entities_);
}

std::string InputSingleMedia::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= entities ? 1 << 0 : 0;
    buffer += media.write();
    buffer += Long::write(random_id);
    buffer += String::write(message);

    if (entities)
        buffer += Vector<TLObject>::write(entities.value());
    return buffer;
}

WebAuthorization::WebAuthorization(long hash_, int bot_id_, std::string domain_, std::string browser_, std::string platform_, int date_created_, int date_active_, std::string ip_, std::string region_) {}

WebAuthorization WebAuthorization::read(Reader reader)
{
    long hash_ = Long::read(reader);
    int bot_id_ = Int::read(reader);
    std::string domain_ = String::read(reader);
    std::string browser_ = String::read(reader);
    std::string platform_ = String::read(reader);
    int date_created_ = Int::read(reader);
    int date_active_ = Int::read(reader);
    std::string ip_ = String::read(reader);
    std::string region_ = String::read(reader);
    return WebAuthorization(hash_, bot_id_, domain_, browser_, platform_, date_created_, date_active_, ip_, region_);
}

std::string WebAuthorization::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(hash);
    buffer += Int::write(bot_id);
    buffer += String::write(domain);
    buffer += String::write(browser);
    buffer += String::write(platform);
    buffer += Int::write(date_created);
    buffer += Int::write(date_active);
    buffer += String::write(ip);
    buffer += String::write(region);
    return buffer;
}

InputMessageID::InputMessageID(int id_) {}

InputMessageID InputMessageID::read(Reader reader)
{
    int id_ = Int::read(reader);
    return InputMessageID(id_);
}

std::string InputMessageID::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    return buffer;
}

InputMessageReplyTo::InputMessageReplyTo(int id_) {}

InputMessageReplyTo InputMessageReplyTo::read(Reader reader)
{
    int id_ = Int::read(reader);
    return InputMessageReplyTo(id_);
}

std::string InputMessageReplyTo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    return buffer;
}
InputMessagePinned InputMessagePinned::read(Reader reader)
{
    return InputMessagePinned();
}

std::string InputMessagePinned::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputMessageCallbackQuery::InputMessageCallbackQuery(int id_, long query_id_) {}

InputMessageCallbackQuery InputMessageCallbackQuery::read(Reader reader)
{
    int id_ = Int::read(reader);
    long query_id_ = Long::read(reader);
    return InputMessageCallbackQuery(id_, query_id_);
}

std::string InputMessageCallbackQuery::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(id);
    buffer += Long::write(query_id);
    return buffer;
}

InputDialogPeer::InputDialogPeer(TLObject peer_) {}

InputDialogPeer InputDialogPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return InputDialogPeer(peer_);
}

std::string InputDialogPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

InputDialogPeerFolder::InputDialogPeerFolder(int folder_id_) {}

InputDialogPeerFolder InputDialogPeerFolder::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return InputDialogPeerFolder(folder_id_);
}

std::string InputDialogPeerFolder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}

DialogPeer::DialogPeer(TLObject peer_) {}

DialogPeer DialogPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return DialogPeer(peer_);
}

std::string DialogPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

DialogPeerFolder::DialogPeerFolder(int folder_id_) {}

DialogPeerFolder DialogPeerFolder::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return DialogPeerFolder(folder_id_);
}

std::string DialogPeerFolder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}

FileHash::FileHash(int offset_, int limit_, std::string hash_) {}

FileHash FileHash::read(Reader reader)
{
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    std::string hash_ = Bytes::read(reader);
    return FileHash(offset_, limit_, hash_);
}

std::string FileHash::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    buffer += Bytes::write(hash);
    return buffer;
}

InputClientProxy::InputClientProxy(std::string address_, int port_) {}

InputClientProxy InputClientProxy::read(Reader reader)
{
    std::string address_ = String::read(reader);
    int port_ = Int::read(reader);
    return InputClientProxy(address_, port_);
}

std::string InputClientProxy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(address);
    buffer += Int::write(port);
    return buffer;
}

InputSecureFileUploaded::InputSecureFileUploaded(long id_, int parts_, std::string md5_checksum_, std::string file_hash_, std::string secret_) {}

InputSecureFileUploaded InputSecureFileUploaded::read(Reader reader)
{
    long id_ = Long::read(reader);
    int parts_ = Int::read(reader);
    std::string md5_checksum_ = String::read(reader);
    std::string file_hash_ = Bytes::read(reader);
    std::string secret_ = Bytes::read(reader);
    return InputSecureFileUploaded(id_, parts_, md5_checksum_, file_hash_, secret_);
}

std::string InputSecureFileUploaded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Int::write(parts);
    buffer += String::write(md5_checksum);
    buffer += Bytes::write(file_hash);
    buffer += Bytes::write(secret);
    return buffer;
}

InputSecureFile::InputSecureFile(long id_, long access_hash_) {}

InputSecureFile InputSecureFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputSecureFile(id_, access_hash_);
}

std::string InputSecureFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}
SecureFileEmpty SecureFileEmpty::read(Reader reader)
{
    return SecureFileEmpty();
}

std::string SecureFileEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SecureFile::SecureFile(long id_, long access_hash_, int size_, int dc_id_, int date_, std::string file_hash_, std::string secret_) {}

SecureFile SecureFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int size_ = Int::read(reader);
    int dc_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    std::string file_hash_ = Bytes::read(reader);
    std::string secret_ = Bytes::read(reader);
    return SecureFile(id_, access_hash_, size_, dc_id_, date_, file_hash_, secret_);
}

std::string SecureFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(size);
    buffer += Int::write(dc_id);
    buffer += Int::write(date);
    buffer += Bytes::write(file_hash);
    buffer += Bytes::write(secret);
    return buffer;
}

SecureData::SecureData(std::string data_, std::string data_hash_, std::string secret_) {}

SecureData SecureData::read(Reader reader)
{
    std::string data_ = Bytes::read(reader);
    std::string data_hash_ = Bytes::read(reader);
    std::string secret_ = Bytes::read(reader);
    return SecureData(data_, data_hash_, secret_);
}

std::string SecureData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(data);
    buffer += Bytes::write(data_hash);
    buffer += Bytes::write(secret);
    return buffer;
}

SecurePlainPhone::SecurePlainPhone(std::string phone_) {}

SecurePlainPhone SecurePlainPhone::read(Reader reader)
{
    std::string phone_ = String::read(reader);
    return SecurePlainPhone(phone_);
}

std::string SecurePlainPhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone);
    return buffer;
}

SecurePlainEmail::SecurePlainEmail(std::string email_) {}

SecurePlainEmail SecurePlainEmail::read(Reader reader)
{
    std::string email_ = String::read(reader);
    return SecurePlainEmail(email_);
}

std::string SecurePlainEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(email);
    return buffer;
}
SecureValueTypePersonalDetails SecureValueTypePersonalDetails::read(Reader reader)
{
    return SecureValueTypePersonalDetails();
}

std::string SecureValueTypePersonalDetails::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypePassport SecureValueTypePassport::read(Reader reader)
{
    return SecureValueTypePassport();
}

std::string SecureValueTypePassport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeDriverLicense SecureValueTypeDriverLicense::read(Reader reader)
{
    return SecureValueTypeDriverLicense();
}

std::string SecureValueTypeDriverLicense::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeIdentityCard SecureValueTypeIdentityCard::read(Reader reader)
{
    return SecureValueTypeIdentityCard();
}

std::string SecureValueTypeIdentityCard::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeInternalPassport SecureValueTypeInternalPassport::read(Reader reader)
{
    return SecureValueTypeInternalPassport();
}

std::string SecureValueTypeInternalPassport::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeAddress SecureValueTypeAddress::read(Reader reader)
{
    return SecureValueTypeAddress();
}

std::string SecureValueTypeAddress::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeUtilityBill SecureValueTypeUtilityBill::read(Reader reader)
{
    return SecureValueTypeUtilityBill();
}

std::string SecureValueTypeUtilityBill::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeBankStatement SecureValueTypeBankStatement::read(Reader reader)
{
    return SecureValueTypeBankStatement();
}

std::string SecureValueTypeBankStatement::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeRentalAgreement SecureValueTypeRentalAgreement::read(Reader reader)
{
    return SecureValueTypeRentalAgreement();
}

std::string SecureValueTypeRentalAgreement::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypePassportRegistration SecureValueTypePassportRegistration::read(Reader reader)
{
    return SecureValueTypePassportRegistration();
}

std::string SecureValueTypePassportRegistration::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeTemporaryRegistration SecureValueTypeTemporaryRegistration::read(Reader reader)
{
    return SecureValueTypeTemporaryRegistration();
}

std::string SecureValueTypeTemporaryRegistration::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypePhone SecureValueTypePhone::read(Reader reader)
{
    return SecureValueTypePhone();
}

std::string SecureValueTypePhone::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecureValueTypeEmail SecureValueTypeEmail::read(Reader reader)
{
    return SecureValueTypeEmail();
}

std::string SecureValueTypeEmail::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SecureValue::SecureValue(TLObject type_, std::string hash_, std::optional<TLObject> data_, std::optional<TLObject> front_side_, std::optional<TLObject> reverse_side_, std::optional<TLObject> selfie_, std::optional<std::vector<TLObject>> translation_, std::optional<std::vector<TLObject>> files_, std::optional<TLObject> plain_data_) {}

SecureValue SecureValue::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> data_;
    data_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> front_side_;
    front_side_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reverse_side_;
    reverse_side_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> selfie_;
    selfie_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> translation_;
    translation_ = (1 << 6) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> files_;
    files_ = (1 << 4) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> plain_data_;
    plain_data_ = (1 << 5) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::string hash_ = Bytes::read(reader);
    return SecureValue(type_, hash_, data_, front_side_, reverse_side_, selfie_, translation_, files_, plain_data_);
}

std::string SecureValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= data ? 1 << 0 : 0;
    flags |= front_side ? 1 << 1 : 0;
    flags |= reverse_side ? 1 << 2 : 0;
    flags |= selfie ? 1 << 3 : 0;
    flags |= translation ? 1 << 6 : 0;
    flags |= files ? 1 << 4 : 0;
    flags |= plain_data ? 1 << 5 : 0;
    buffer += type.write();

    if (data)
        buffer += data.value().write();

    if (front_side)
        buffer += front_side.value().write();

    if (reverse_side)
        buffer += reverse_side.value().write();

    if (selfie)
        buffer += selfie.value().write();

    if (translation)
        buffer += Vector<TLObject>::write(translation.value());

    if (files)
        buffer += Vector<TLObject>::write(files.value());

    if (plain_data)
        buffer += plain_data.value().write();
    buffer += Bytes::write(hash);
    return buffer;
}

InputSecureValue::InputSecureValue(TLObject type_, std::optional<TLObject> data_, std::optional<TLObject> front_side_, std::optional<TLObject> reverse_side_, std::optional<TLObject> selfie_, std::optional<std::vector<TLObject>> translation_, std::optional<std::vector<TLObject>> files_, std::optional<TLObject> plain_data_) {}

InputSecureValue InputSecureValue::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> data_;
    data_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> front_side_;
    front_side_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> reverse_side_;
    reverse_side_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> selfie_;
    selfie_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> translation_;
    translation_ = (1 << 6) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::vector<TLObject>> files_;
    files_ = (1 << 4) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> plain_data_;
    plain_data_ = (1 << 5) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputSecureValue(type_, data_, front_side_, reverse_side_, selfie_, translation_, files_, plain_data_);
}

std::string InputSecureValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= data ? 1 << 0 : 0;
    flags |= front_side ? 1 << 1 : 0;
    flags |= reverse_side ? 1 << 2 : 0;
    flags |= selfie ? 1 << 3 : 0;
    flags |= translation ? 1 << 6 : 0;
    flags |= files ? 1 << 4 : 0;
    flags |= plain_data ? 1 << 5 : 0;
    buffer += type.write();

    if (data)
        buffer += data.value().write();

    if (front_side)
        buffer += front_side.value().write();

    if (reverse_side)
        buffer += reverse_side.value().write();

    if (selfie)
        buffer += selfie.value().write();

    if (translation)
        buffer += Vector<TLObject>::write(translation.value());

    if (files)
        buffer += Vector<TLObject>::write(files.value());

    if (plain_data)
        buffer += plain_data.value().write();
    return buffer;
}

SecureValueHash::SecureValueHash(TLObject type_, std::string hash_) {}

SecureValueHash SecureValueHash::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string hash_ = Bytes::read(reader);
    return SecureValueHash(type_, hash_);
}

std::string SecureValueHash::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(hash);
    return buffer;
}

SecureValueErrorData::SecureValueErrorData(TLObject type_, std::string data_hash_, std::string field_, std::string text_) {}

SecureValueErrorData SecureValueErrorData::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string data_hash_ = Bytes::read(reader);
    std::string field_ = String::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorData(type_, data_hash_, field_, text_);
}

std::string SecureValueErrorData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(data_hash);
    buffer += String::write(field);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorFrontSide::SecureValueErrorFrontSide(TLObject type_, std::string file_hash_, std::string text_) {}

SecureValueErrorFrontSide SecureValueErrorFrontSide::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string file_hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorFrontSide(type_, file_hash_, text_);
}

std::string SecureValueErrorFrontSide::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorReverseSide::SecureValueErrorReverseSide(TLObject type_, std::string file_hash_, std::string text_) {}

SecureValueErrorReverseSide SecureValueErrorReverseSide::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string file_hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorReverseSide(type_, file_hash_, text_);
}

std::string SecureValueErrorReverseSide::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorSelfie::SecureValueErrorSelfie(TLObject type_, std::string file_hash_, std::string text_) {}

SecureValueErrorSelfie SecureValueErrorSelfie::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string file_hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorSelfie(type_, file_hash_, text_);
}

std::string SecureValueErrorSelfie::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorFile::SecureValueErrorFile(TLObject type_, std::string file_hash_, std::string text_) {}

SecureValueErrorFile SecureValueErrorFile::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string file_hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorFile(type_, file_hash_, text_);
}

std::string SecureValueErrorFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorFiles::SecureValueErrorFiles(TLObject type_, std::vector<std::string> file_hash_, std::string text_) {}

SecureValueErrorFiles SecureValueErrorFiles::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<std::string> file_hash_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    std::string text_ = String::read(reader);
    return SecureValueErrorFiles(type_, file_hash_, text_);
}

std::string SecureValueErrorFiles::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Vector<std::string>::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueError::SecureValueError(TLObject type_, std::string hash_, std::string text_) {}

SecureValueError SecureValueError::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueError(type_, hash_, text_);
}

std::string SecureValueError::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorTranslationFile::SecureValueErrorTranslationFile(TLObject type_, std::string file_hash_, std::string text_) {}

SecureValueErrorTranslationFile SecureValueErrorTranslationFile::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::string file_hash_ = Bytes::read(reader);
    std::string text_ = String::read(reader);
    return SecureValueErrorTranslationFile(type_, file_hash_, text_);
}

std::string SecureValueErrorTranslationFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Bytes::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureValueErrorTranslationFiles::SecureValueErrorTranslationFiles(TLObject type_, std::vector<std::string> file_hash_, std::string text_) {}

SecureValueErrorTranslationFiles SecureValueErrorTranslationFiles::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<std::string> file_hash_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    std::string text_ = String::read(reader);
    return SecureValueErrorTranslationFiles(type_, file_hash_, text_);
}

std::string SecureValueErrorTranslationFiles::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Vector<std::string>::write(file_hash);
    buffer += String::write(text);
    return buffer;
}

SecureCredentialsEncrypted::SecureCredentialsEncrypted(std::string data_, std::string hash_, std::string secret_) {}

SecureCredentialsEncrypted SecureCredentialsEncrypted::read(Reader reader)
{
    std::string data_ = Bytes::read(reader);
    std::string hash_ = Bytes::read(reader);
    std::string secret_ = Bytes::read(reader);
    return SecureCredentialsEncrypted(data_, hash_, secret_);
}

std::string SecureCredentialsEncrypted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(data);
    buffer += Bytes::write(hash);
    buffer += Bytes::write(secret);
    return buffer;
}

SavedPhoneContact::SavedPhoneContact(std::string phone_, std::string first_name_, std::string last_name_, int date_) {}

SavedPhoneContact SavedPhoneContact::read(Reader reader)
{
    std::string phone_ = String::read(reader);
    std::string first_name_ = String::read(reader);
    std::string last_name_ = String::read(reader);
    int date_ = Int::read(reader);
    return SavedPhoneContact(phone_, first_name_, last_name_, date_);
}

std::string SavedPhoneContact::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone);
    buffer += String::write(first_name);
    buffer += String::write(last_name);
    buffer += Int::write(date);
    return buffer;
}
PasswordKdfAlgoUnknown PasswordKdfAlgoUnknown::read(Reader reader)
{
    return PasswordKdfAlgoUnknown();
}

std::string PasswordKdfAlgoUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
SecurePasswordKdfAlgoUnknown SecurePasswordKdfAlgoUnknown::read(Reader reader)
{
    return SecurePasswordKdfAlgoUnknown();
}

std::string SecurePasswordKdfAlgoUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

SecureSecretSettings::SecureSecretSettings(TLObject secure_algo_, std::string secure_secret_, long secure_secret_id_) {}

SecureSecretSettings SecureSecretSettings::read(Reader reader)
{
    TLObject secure_algo_ = std::get<TLObject>(TLObject::read(reader));
    std::string secure_secret_ = Bytes::read(reader);
    long secure_secret_id_ = Long::read(reader);
    return SecureSecretSettings(secure_algo_, secure_secret_, secure_secret_id_);
}

std::string SecureSecretSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += secure_algo.write();
    buffer += Bytes::write(secure_secret);
    buffer += Long::write(secure_secret_id);
    return buffer;
}
InputCheckPasswordEmpty InputCheckPasswordEmpty::read(Reader reader)
{
    return InputCheckPasswordEmpty();
}

std::string InputCheckPasswordEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputCheckPasswordSRP::InputCheckPasswordSRP(long srp_id_, std::string A_, std::string M1_) {}

InputCheckPasswordSRP InputCheckPasswordSRP::read(Reader reader)
{
    long srp_id_ = Long::read(reader);
    std::string A_ = Bytes::read(reader);
    std::string M1_ = Bytes::read(reader);
    return InputCheckPasswordSRP(srp_id_, A_, M1_);
}

std::string InputCheckPasswordSRP::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(srp_id);
    buffer += Bytes::write(A);
    buffer += Bytes::write(M1);
    return buffer;
}

SecureRequiredType::SecureRequiredType(TLObject type_, std::optional<bool> native_names_, std::optional<bool> selfie_required_, std::optional<bool> translation_required_) {}

SecureRequiredType SecureRequiredType::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> native_names_;
    native_names_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> selfie_required_;
    selfie_required_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> translation_required_;
    translation_required_ = (1 << 2) ? std::optional{true} : std::nullopt;
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    return SecureRequiredType(type_, native_names_, selfie_required_, translation_required_);
}

std::string SecureRequiredType::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= native_names ? 1 << 0 : 0;
    flags |= selfie_required ? 1 << 1 : 0;
    flags |= translation_required ? 1 << 2 : 0;
    buffer += type.write();
    return buffer;
}

SecureRequiredTypeOneOf::SecureRequiredTypeOneOf(std::vector<TLObject> types_) {}

SecureRequiredTypeOneOf SecureRequiredTypeOneOf::read(Reader reader)
{
    std::vector<TLObject> types_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SecureRequiredTypeOneOf(types_);
}

std::string SecureRequiredTypeOneOf::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(types);
    return buffer;
}

InputAppEvent::InputAppEvent(double time_, std::string type_, long peer_, TLObject data_) {}

InputAppEvent InputAppEvent::read(Reader reader)
{
    double time_ = Double::read(reader);
    std::string type_ = String::read(reader);
    long peer_ = Long::read(reader);
    TLObject data_ = std::get<TLObject>(TLObject::read(reader));
    return InputAppEvent(time_, type_, peer_, data_);
}

std::string InputAppEvent::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Double::write(time);
    buffer += String::write(type);
    buffer += Long::write(peer);
    buffer += data.write();
    return buffer;
}

JsonObjectValue::JsonObjectValue(std::string key_, TLObject value_) {}

JsonObjectValue JsonObjectValue::read(Reader reader)
{
    std::string key_ = String::read(reader);
    TLObject value_ = std::get<TLObject>(TLObject::read(reader));
    return JsonObjectValue(key_, value_);
}

std::string JsonObjectValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(key);
    buffer += value.write();
    return buffer;
}
JsonNull JsonNull::read(Reader reader)
{
    return JsonNull();
}

std::string JsonNull::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

JsonBool::JsonBool(bool value_) {}

JsonBool JsonBool::read(Reader reader)
{
    bool value_ = Bool::read(reader);
    return JsonBool(value_);
}

std::string JsonBool::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bool::write(value);
    return buffer;
}

JsonNumber::JsonNumber(double value_) {}

JsonNumber JsonNumber::read(Reader reader)
{
    double value_ = Double::read(reader);
    return JsonNumber(value_);
}

std::string JsonNumber::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Double::write(value);
    return buffer;
}

JsonString::JsonString(std::string value_) {}

JsonString JsonString::read(Reader reader)
{
    std::string value_ = String::read(reader);
    return JsonString(value_);
}

std::string JsonString::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(value);
    return buffer;
}

JsonArray::JsonArray(std::vector<TLObject> value_) {}

JsonArray JsonArray::read(Reader reader)
{
    std::vector<TLObject> value_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return JsonArray(value_);
}

std::string JsonArray::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(value);
    return buffer;
}

JsonObject::JsonObject(std::vector<TLObject> value_) {}

JsonObject JsonObject::read(Reader reader)
{
    std::vector<TLObject> value_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return JsonObject(value_);
}

std::string JsonObject::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(value);
    return buffer;
}

PageTableCell::PageTableCell(std::optional<bool> header_, std::optional<bool> align_center_, std::optional<bool> align_right_, std::optional<bool> valign_middle_, std::optional<bool> valign_bottom_, std::optional<TLObject> text_, std::optional<int> colspan_, std::optional<int> rowspan_) {}

PageTableCell PageTableCell::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> header_;
    header_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> align_center_;
    align_center_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> align_right_;
    align_right_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> valign_middle_;
    valign_middle_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> valign_bottom_;
    valign_bottom_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> text_;
    text_ = (1 << 7) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> colspan_;
    colspan_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> rowspan_;
    rowspan_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    return PageTableCell(header_, align_center_, align_right_, valign_middle_, valign_bottom_, text_, colspan_, rowspan_);
}

std::string PageTableCell::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= header ? 1 << 0 : 0;
    flags |= align_center ? 1 << 3 : 0;
    flags |= align_right ? 1 << 4 : 0;
    flags |= valign_middle ? 1 << 5 : 0;
    flags |= valign_bottom ? 1 << 6 : 0;
    flags |= text ? 1 << 7 : 0;
    flags |= colspan ? 1 << 1 : 0;
    flags |= rowspan ? 1 << 2 : 0;

    if (text)
        buffer += text.value().write();

    if (colspan)
        buffer += Int::write(colspan.value());

    if (rowspan)
        buffer += Int::write(rowspan.value());
    return buffer;
}

PageTableRow::PageTableRow(std::vector<TLObject> cells_) {}

PageTableRow PageTableRow::read(Reader reader)
{
    std::vector<TLObject> cells_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageTableRow(cells_);
}

std::string PageTableRow::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(cells);
    return buffer;
}

PageCaption::PageCaption(TLObject text_, TLObject credit_) {}

PageCaption PageCaption::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    TLObject credit_ = std::get<TLObject>(TLObject::read(reader));
    return PageCaption(text_, credit_);
}

std::string PageCaption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    buffer += credit.write();
    return buffer;
}

PageListItemText::PageListItemText(TLObject text_) {}

PageListItemText PageListItemText::read(Reader reader)
{
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageListItemText(text_);
}

std::string PageListItemText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += text.write();
    return buffer;
}

PageListItemBlocks::PageListItemBlocks(std::vector<TLObject> blocks_) {}

PageListItemBlocks PageListItemBlocks::read(Reader reader)
{
    std::vector<TLObject> blocks_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageListItemBlocks(blocks_);
}

std::string PageListItemBlocks::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(blocks);
    return buffer;
}

PageListOrderedItemText::PageListOrderedItemText(std::string num_, TLObject text_) {}

PageListOrderedItemText PageListOrderedItemText::read(Reader reader)
{
    std::string num_ = String::read(reader);
    TLObject text_ = std::get<TLObject>(TLObject::read(reader));
    return PageListOrderedItemText(num_, text_);
}

std::string PageListOrderedItemText::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(num);
    buffer += text.write();
    return buffer;
}

PageListOrderedItemBlocks::PageListOrderedItemBlocks(std::string num_, std::vector<TLObject> blocks_) {}

PageListOrderedItemBlocks PageListOrderedItemBlocks::read(Reader reader)
{
    std::string num_ = String::read(reader);
    std::vector<TLObject> blocks_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PageListOrderedItemBlocks(num_, blocks_);
}

std::string PageListOrderedItemBlocks::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(num);
    buffer += Vector<TLObject>::write(blocks);
    return buffer;
}

PageRelatedArticle::PageRelatedArticle(std::string url_, long webpage_id_, std::optional<std::string> title_, std::optional<std::string> description_, std::optional<long> photo_id_, std::optional<std::string> author_, std::optional<int> published_date_) {}

PageRelatedArticle PageRelatedArticle::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string url_ = String::read(reader);
    long webpage_id_ = Long::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> description_;
    description_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<long> photo_id_;
    photo_id_ = (1 << 2) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<std::string> author_;
    author_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> published_date_;
    published_date_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    return PageRelatedArticle(url_, webpage_id_, title_, description_, photo_id_, author_, published_date_);
}

std::string PageRelatedArticle::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= title ? 1 << 0 : 0;
    flags |= description ? 1 << 1 : 0;
    flags |= photo_id ? 1 << 2 : 0;
    flags |= author ? 1 << 3 : 0;
    flags |= published_date ? 1 << 4 : 0;
    buffer += String::write(url);
    buffer += Long::write(webpage_id);

    if (title)
        buffer += String::write(title.value());

    if (description)
        buffer += String::write(description.value());

    if (photo_id)
        buffer += Long::write(photo_id.value());

    if (author)
        buffer += String::write(author.value());

    if (published_date)
        buffer += Int::write(published_date.value());
    return buffer;
}

Page::Page(std::string url_, std::vector<TLObject> blocks_, std::vector<TLObject> photos_, std::vector<TLObject> documents_, std::optional<bool> part_, std::optional<bool> rtl_, std::optional<bool> v2_, std::optional<int> views_) {}

Page Page::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> part_;
    part_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> rtl_;
    rtl_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> v2_;
    v2_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::string url_ = String::read(reader);
    std::vector<TLObject> blocks_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> photos_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> documents_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<int> views_;
    views_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    return Page(url_, blocks_, photos_, documents_, part_, rtl_, v2_, views_);
}

std::string Page::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= part ? 1 << 0 : 0;
    flags |= rtl ? 1 << 1 : 0;
    flags |= v2 ? 1 << 2 : 0;
    flags |= views ? 1 << 3 : 0;
    buffer += String::write(url);
    buffer += Vector<TLObject>::write(blocks);
    buffer += Vector<TLObject>::write(photos);
    buffer += Vector<TLObject>::write(documents);

    if (views)
        buffer += Int::write(views.value());
    return buffer;
}

PollAnswer::PollAnswer(std::string text_, std::string option_) {}

PollAnswer PollAnswer::read(Reader reader)
{
    std::string text_ = String::read(reader);
    std::string option_ = Bytes::read(reader);
    return PollAnswer(text_, option_);
}

std::string PollAnswer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(text);
    buffer += Bytes::write(option);
    return buffer;
}

Poll::Poll(long id_, std::string question_, std::vector<TLObject> answers_, std::optional<bool> closed_, std::optional<bool> public_voters_, std::optional<bool> multiple_choice_, std::optional<bool> quiz_, std::optional<int> close_period_, std::optional<int> close_date_) {}

Poll Poll::read(Reader reader)
{
    long id_ = Long::read(reader);
    int flags = Int::read(reader);
    std::optional<bool> closed_;
    closed_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> public_voters_;
    public_voters_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> multiple_choice_;
    multiple_choice_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> quiz_;
    quiz_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::string question_ = String::read(reader);
    std::vector<TLObject> answers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<int> close_period_;
    close_period_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> close_date_;
    close_date_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    return Poll(id_, question_, answers_, closed_, public_voters_, multiple_choice_, quiz_, close_period_, close_date_);
}

std::string Poll::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= closed ? 1 << 0 : 0;
    flags |= public_voters ? 1 << 1 : 0;
    flags |= multiple_choice ? 1 << 2 : 0;
    flags |= quiz ? 1 << 3 : 0;
    flags |= close_period ? 1 << 4 : 0;
    flags |= close_date ? 1 << 5 : 0;
    buffer += Long::write(id);
    buffer += String::write(question);
    buffer += Vector<TLObject>::write(answers);

    if (close_period)
        buffer += Int::write(close_period.value());

    if (close_date)
        buffer += Int::write(close_date.value());
    return buffer;
}

PollAnswerVoters::PollAnswerVoters(std::string option_, int voters_, std::optional<bool> chosen_, std::optional<bool> correct_) {}

PollAnswerVoters PollAnswerVoters::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> chosen_;
    chosen_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> correct_;
    correct_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::string option_ = Bytes::read(reader);
    int voters_ = Int::read(reader);
    return PollAnswerVoters(option_, voters_, chosen_, correct_);
}

std::string PollAnswerVoters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= chosen ? 1 << 0 : 0;
    flags |= correct ? 1 << 1 : 0;
    buffer += Bytes::write(option);
    buffer += Int::write(voters);
    return buffer;
}

PollResults::PollResults(std::optional<bool> min_, std::optional<std::vector<TLObject>> results_, std::optional<int> total_voters_, std::optional<std::vector<int>> recent_voters_, std::optional<std::string> solution_, std::optional<std::vector<TLObject>> solution_entities_) {}

PollResults PollResults::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> min_;
    min_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<std::vector<TLObject>> results_;
    results_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> total_voters_;
    total_voters_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::vector<int>> recent_voters_;
    recent_voters_ = (1 << 3) ? std::optional{std::get<std::vector<int>>(TLObject::read(reader))} : std::nullopt;
    std::optional<std::string> solution_;
    solution_ = (1 << 4) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> solution_entities_;
    solution_entities_ = (1 << 4) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return PollResults(min_, results_, total_voters_, recent_voters_, solution_, solution_entities_);
}

std::string PollResults::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= min ? 1 << 0 : 0;
    flags |= results ? 1 << 1 : 0;
    flags |= total_voters ? 1 << 2 : 0;
    flags |= recent_voters ? 1 << 3 : 0;
    flags |= solution ? 1 << 4 : 0;
    flags |= solution_entities ? 1 << 4 : 0;

    if (results)
        buffer += Vector<TLObject>::write(results.value());

    if (total_voters)
        buffer += Int::write(total_voters.value());

    if (recent_voters)
        buffer += Vector<int>::write(recent_voters.value());

    if (solution)
        buffer += String::write(solution.value());

    if (solution_entities)
        buffer += Vector<TLObject>::write(solution_entities.value());
    return buffer;
}

ChatOnlines::ChatOnlines(int onlines_) {}

ChatOnlines ChatOnlines::read(Reader reader)
{
    int onlines_ = Int::read(reader);
    return ChatOnlines(onlines_);
}

std::string ChatOnlines::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(onlines);
    return buffer;
}

StatsURL::StatsURL(std::string url_) {}

StatsURL StatsURL::read(Reader reader)
{
    std::string url_ = String::read(reader);
    return StatsURL(url_);
}

std::string StatsURL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    return buffer;
}

ChatAdminRights::ChatAdminRights(std::optional<bool> change_info_, std::optional<bool> post_messages_, std::optional<bool> edit_messages_, std::optional<bool> delete_messages_, std::optional<bool> ban_users_, std::optional<bool> invite_users_, std::optional<bool> pin_messages_, std::optional<bool> add_admins_, std::optional<bool> anonymous_, std::optional<bool> manage_call_, std::optional<bool> other_) {}

ChatAdminRights ChatAdminRights::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> change_info_;
    change_info_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> post_messages_;
    post_messages_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> edit_messages_;
    edit_messages_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> delete_messages_;
    delete_messages_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> ban_users_;
    ban_users_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> invite_users_;
    invite_users_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> pin_messages_;
    pin_messages_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> add_admins_;
    add_admins_ = (1 << 9) ? std::optional{true} : std::nullopt;
    std::optional<bool> anonymous_;
    anonymous_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> manage_call_;
    manage_call_ = (1 << 11) ? std::optional{true} : std::nullopt;
    std::optional<bool> other_;
    other_ = (1 << 12) ? std::optional{true} : std::nullopt;
    return ChatAdminRights(change_info_, post_messages_, edit_messages_, delete_messages_, ban_users_, invite_users_, pin_messages_, add_admins_, anonymous_, manage_call_, other_);
}

std::string ChatAdminRights::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= change_info ? 1 << 0 : 0;
    flags |= post_messages ? 1 << 1 : 0;
    flags |= edit_messages ? 1 << 2 : 0;
    flags |= delete_messages ? 1 << 3 : 0;
    flags |= ban_users ? 1 << 4 : 0;
    flags |= invite_users ? 1 << 5 : 0;
    flags |= pin_messages ? 1 << 7 : 0;
    flags |= add_admins ? 1 << 9 : 0;
    flags |= anonymous ? 1 << 10 : 0;
    flags |= manage_call ? 1 << 11 : 0;
    flags |= other ? 1 << 12 : 0;
    return buffer;
}

ChatBannedRights::ChatBannedRights(int until_date_, std::optional<bool> view_messages_, std::optional<bool> send_messages_, std::optional<bool> send_media_, std::optional<bool> send_stickers_, std::optional<bool> send_gifs_, std::optional<bool> send_games_, std::optional<bool> send_inline_, std::optional<bool> embed_links_, std::optional<bool> send_polls_, std::optional<bool> change_info_, std::optional<bool> invite_users_, std::optional<bool> pin_messages_) {}

ChatBannedRights ChatBannedRights::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> view_messages_;
    view_messages_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_messages_;
    send_messages_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_media_;
    send_media_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_stickers_;
    send_stickers_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_gifs_;
    send_gifs_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_games_;
    send_games_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_inline_;
    send_inline_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> embed_links_;
    embed_links_ = (1 << 7) ? std::optional{true} : std::nullopt;
    std::optional<bool> send_polls_;
    send_polls_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> change_info_;
    change_info_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> invite_users_;
    invite_users_ = (1 << 15) ? std::optional{true} : std::nullopt;
    std::optional<bool> pin_messages_;
    pin_messages_ = (1 << 17) ? std::optional{true} : std::nullopt;
    int until_date_ = Int::read(reader);
    return ChatBannedRights(until_date_, view_messages_, send_messages_, send_media_, send_stickers_, send_gifs_, send_games_, send_inline_, embed_links_, send_polls_, change_info_, invite_users_, pin_messages_);
}

std::string ChatBannedRights::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= view_messages ? 1 << 0 : 0;
    flags |= send_messages ? 1 << 1 : 0;
    flags |= send_media ? 1 << 2 : 0;
    flags |= send_stickers ? 1 << 3 : 0;
    flags |= send_gifs ? 1 << 4 : 0;
    flags |= send_games ? 1 << 5 : 0;
    flags |= send_inline ? 1 << 6 : 0;
    flags |= embed_links ? 1 << 7 : 0;
    flags |= send_polls ? 1 << 8 : 0;
    flags |= change_info ? 1 << 10 : 0;
    flags |= invite_users ? 1 << 15 : 0;
    flags |= pin_messages ? 1 << 17 : 0;
    buffer += Int::write(until_date);
    return buffer;
}

InputWallPaper::InputWallPaper(long id_, long access_hash_) {}

InputWallPaper InputWallPaper::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputWallPaper(id_, access_hash_);
}

std::string InputWallPaper::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputWallPaperSlug::InputWallPaperSlug(std::string slug_) {}

InputWallPaperSlug InputWallPaperSlug::read(Reader reader)
{
    std::string slug_ = String::read(reader);
    return InputWallPaperSlug(slug_);
}

std::string InputWallPaperSlug::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(slug);
    return buffer;
}

InputWallPaperNoFile::InputWallPaperNoFile(long id_) {}

InputWallPaperNoFile InputWallPaperNoFile::read(Reader reader)
{
    long id_ = Long::read(reader);
    return InputWallPaperNoFile(id_);
}

std::string InputWallPaperNoFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    return buffer;
}

CodeSettings::CodeSettings(std::optional<bool> allow_flashcall_, std::optional<bool> current_number_, std::optional<bool> allow_app_hash_) {}

CodeSettings CodeSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> allow_flashcall_;
    allow_flashcall_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> current_number_;
    current_number_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> allow_app_hash_;
    allow_app_hash_ = (1 << 4) ? std::optional{true} : std::nullopt;
    return CodeSettings(allow_flashcall_, current_number_, allow_app_hash_);
}

std::string CodeSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= allow_flashcall ? 1 << 0 : 0;
    flags |= current_number ? 1 << 1 : 0;
    flags |= allow_app_hash ? 1 << 4 : 0;
    return buffer;
}

WallPaperSettings::WallPaperSettings(std::optional<bool> blur_, std::optional<bool> motion_, std::optional<int> background_color_, std::optional<int> second_background_color_, std::optional<int> third_background_color_, std::optional<int> fourth_background_color_, std::optional<int> intensity_, std::optional<int> rotation_) {}

WallPaperSettings WallPaperSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> blur_;
    blur_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> motion_;
    motion_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<int> background_color_;
    background_color_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> second_background_color_;
    second_background_color_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> third_background_color_;
    third_background_color_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> fourth_background_color_;
    fourth_background_color_ = (1 << 6) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> intensity_;
    intensity_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> rotation_;
    rotation_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    return WallPaperSettings(blur_, motion_, background_color_, second_background_color_, third_background_color_, fourth_background_color_, intensity_, rotation_);
}

std::string WallPaperSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= blur ? 1 << 1 : 0;
    flags |= motion ? 1 << 2 : 0;
    flags |= background_color ? 1 << 0 : 0;
    flags |= second_background_color ? 1 << 4 : 0;
    flags |= third_background_color ? 1 << 5 : 0;
    flags |= fourth_background_color ? 1 << 6 : 0;
    flags |= intensity ? 1 << 3 : 0;
    flags |= rotation ? 1 << 4 : 0;

    if (background_color)
        buffer += Int::write(background_color.value());

    if (second_background_color)
        buffer += Int::write(second_background_color.value());

    if (third_background_color)
        buffer += Int::write(third_background_color.value());

    if (fourth_background_color)
        buffer += Int::write(fourth_background_color.value());

    if (intensity)
        buffer += Int::write(intensity.value());

    if (rotation)
        buffer += Int::write(rotation.value());
    return buffer;
}

AutoDownloadSettings::AutoDownloadSettings(int photo_size_max_, int video_size_max_, int file_size_max_, int video_upload_maxbitrate_, std::optional<bool> disabled_, std::optional<bool> video_preload_large_, std::optional<bool> audio_preload_next_, std::optional<bool> phonecalls_less_data_) {}

AutoDownloadSettings AutoDownloadSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> disabled_;
    disabled_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_preload_large_;
    video_preload_large_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> audio_preload_next_;
    audio_preload_next_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> phonecalls_less_data_;
    phonecalls_less_data_ = (1 << 3) ? std::optional{true} : std::nullopt;
    int photo_size_max_ = Int::read(reader);
    int video_size_max_ = Int::read(reader);
    int file_size_max_ = Int::read(reader);
    int video_upload_maxbitrate_ = Int::read(reader);
    return AutoDownloadSettings(photo_size_max_, video_size_max_, file_size_max_, video_upload_maxbitrate_, disabled_, video_preload_large_, audio_preload_next_, phonecalls_less_data_);
}

std::string AutoDownloadSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= disabled ? 1 << 0 : 0;
    flags |= video_preload_large ? 1 << 1 : 0;
    flags |= audio_preload_next ? 1 << 2 : 0;
    flags |= phonecalls_less_data ? 1 << 3 : 0;
    buffer += Int::write(photo_size_max);
    buffer += Int::write(video_size_max);
    buffer += Int::write(file_size_max);
    buffer += Int::write(video_upload_maxbitrate);
    return buffer;
}

EmojiKeyword::EmojiKeyword(std::string keyword_, std::vector<std::string> emoticons_) {}

EmojiKeyword EmojiKeyword::read(Reader reader)
{
    std::string keyword_ = String::read(reader);
    std::vector<std::string> emoticons_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return EmojiKeyword(keyword_, emoticons_);
}

std::string EmojiKeyword::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(keyword);
    buffer += Vector<std::string>::write(emoticons);
    return buffer;
}

EmojiKeywordDeleted::EmojiKeywordDeleted(std::string keyword_, std::vector<std::string> emoticons_) {}

EmojiKeywordDeleted EmojiKeywordDeleted::read(Reader reader)
{
    std::string keyword_ = String::read(reader);
    std::vector<std::string> emoticons_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return EmojiKeywordDeleted(keyword_, emoticons_);
}

std::string EmojiKeywordDeleted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(keyword);
    buffer += Vector<std::string>::write(emoticons);
    return buffer;
}

EmojiKeywordsDifference::EmojiKeywordsDifference(std::string lang_code_, int from_version_, int version_, std::vector<TLObject> keywords_) {}

EmojiKeywordsDifference EmojiKeywordsDifference::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    int version_ = Int::read(reader);
    std::vector<TLObject> keywords_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return EmojiKeywordsDifference(lang_code_, from_version_, version_, keywords_);
}

std::string EmojiKeywordsDifference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    buffer += Int::write(version);
    buffer += Vector<TLObject>::write(keywords);
    return buffer;
}

EmojiURL::EmojiURL(std::string url_) {}

EmojiURL EmojiURL::read(Reader reader)
{
    std::string url_ = String::read(reader);
    return EmojiURL(url_);
}

std::string EmojiURL::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    return buffer;
}

EmojiLanguage::EmojiLanguage(std::string lang_code_) {}

EmojiLanguage EmojiLanguage::read(Reader reader)
{
    std::string lang_code_ = String::read(reader);
    return EmojiLanguage(lang_code_);
}

std::string EmojiLanguage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_code);
    return buffer;
}

Folder::Folder(int id_, std::string title_, std::optional<bool> autofill_new_broadcasts_, std::optional<bool> autofill_public_groups_, std::optional<bool> autofill_new_correspondents_, std::optional<TLObject> photo_) {}

Folder Folder::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> autofill_new_broadcasts_;
    autofill_new_broadcasts_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> autofill_public_groups_;
    autofill_public_groups_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> autofill_new_correspondents_;
    autofill_new_correspondents_ = (1 << 2) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return Folder(id_, title_, autofill_new_broadcasts_, autofill_public_groups_, autofill_new_correspondents_, photo_);
}

std::string Folder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= autofill_new_broadcasts ? 1 << 0 : 0;
    flags |= autofill_public_groups ? 1 << 1 : 0;
    flags |= autofill_new_correspondents ? 1 << 2 : 0;
    flags |= photo ? 1 << 3 : 0;
    buffer += Int::write(id);
    buffer += String::write(title);

    if (photo)
        buffer += photo.value().write();
    return buffer;
}

InputFolderPeer::InputFolderPeer(TLObject peer_, int folder_id_) {}

InputFolderPeer InputFolderPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int folder_id_ = Int::read(reader);
    return InputFolderPeer(peer_, folder_id_);
}

std::string InputFolderPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(folder_id);
    return buffer;
}

FolderPeer::FolderPeer(TLObject peer_, int folder_id_) {}

FolderPeer FolderPeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int folder_id_ = Int::read(reader);
    return FolderPeer(peer_, folder_id_);
}

std::string FolderPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(folder_id);
    return buffer;
}

UrlAuthResultRequest::UrlAuthResultRequest(TLObject bot_, std::string domain_, std::optional<bool> request_write_access_) {}

UrlAuthResultRequest UrlAuthResultRequest::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> request_write_access_;
    request_write_access_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject bot_ = std::get<TLObject>(TLObject::read(reader));
    std::string domain_ = String::read(reader);
    return UrlAuthResultRequest(bot_, domain_, request_write_access_);
}

std::string UrlAuthResultRequest::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= request_write_access ? 1 << 0 : 0;
    buffer += bot.write();
    buffer += String::write(domain);
    return buffer;
}

UrlAuthResultAccepted::UrlAuthResultAccepted(std::string url_) {}

UrlAuthResultAccepted UrlAuthResultAccepted::read(Reader reader)
{
    std::string url_ = String::read(reader);
    return UrlAuthResultAccepted(url_);
}

std::string UrlAuthResultAccepted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    return buffer;
}
UrlAuthResultDefault UrlAuthResultDefault::read(Reader reader)
{
    return UrlAuthResultDefault();
}

std::string UrlAuthResultDefault::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
ChannelLocationEmpty ChannelLocationEmpty::read(Reader reader)
{
    return ChannelLocationEmpty();
}

std::string ChannelLocationEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelLocation::ChannelLocation(TLObject geo_point_, std::string address_) {}

ChannelLocation ChannelLocation::read(Reader reader)
{
    TLObject geo_point_ = std::get<TLObject>(TLObject::read(reader));
    std::string address_ = String::read(reader);
    return ChannelLocation(geo_point_, address_);
}

std::string ChannelLocation::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += geo_point.write();
    buffer += String::write(address);
    return buffer;
}

PeerLocated::PeerLocated(TLObject peer_, int expires_, int distance_) {}

PeerLocated PeerLocated::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int expires_ = Int::read(reader);
    int distance_ = Int::read(reader);
    return PeerLocated(peer_, expires_, distance_);
}

std::string PeerLocated::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(expires);
    buffer += Int::write(distance);
    return buffer;
}

PeerSelfLocated::PeerSelfLocated(int expires_) {}

PeerSelfLocated PeerSelfLocated::read(Reader reader)
{
    int expires_ = Int::read(reader);
    return PeerSelfLocated(expires_);
}

std::string PeerSelfLocated::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(expires);
    return buffer;
}

RestrictionReason::RestrictionReason(std::string platform_, std::string reason_, std::string text_) {}

RestrictionReason RestrictionReason::read(Reader reader)
{
    std::string platform_ = String::read(reader);
    std::string reason_ = String::read(reader);
    std::string text_ = String::read(reader);
    return RestrictionReason(platform_, reason_, text_);
}

std::string RestrictionReason::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(platform);
    buffer += String::write(reason);
    buffer += String::write(text);
    return buffer;
}

InputTheme::InputTheme(long id_, long access_hash_) {}

InputTheme InputTheme::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputTheme(id_, access_hash_);
}

std::string InputTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

InputThemeSlug::InputThemeSlug(std::string slug_) {}

InputThemeSlug InputThemeSlug::read(Reader reader)
{
    std::string slug_ = String::read(reader);
    return InputThemeSlug(slug_);
}

std::string InputThemeSlug::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(slug);
    return buffer;
}

Theme::Theme(long id_, long access_hash_, std::string slug_, std::string title_, int installs_count_, std::optional<bool> creator_, std::optional<bool> default__, std::optional<TLObject> document_, std::optional<TLObject> settings_) {}

Theme Theme::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> creator_;
    creator_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> default__;
    default__ = (1 << 1) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    std::string slug_ = String::read(reader);
    std::string title_ = String::read(reader);
    std::optional<TLObject> document_;
    document_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> settings_;
    settings_ = (1 << 3) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    int installs_count_ = Int::read(reader);
    return Theme(id_, access_hash_, slug_, title_, installs_count_, creator_, default__, document_, settings_);
}

std::string Theme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= creator ? 1 << 0 : 0;
    flags |= default_ ? 1 << 1 : 0;
    flags |= document ? 1 << 2 : 0;
    flags |= settings ? 1 << 3 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += String::write(slug);
    buffer += String::write(title);

    if (document)
        buffer += document.value().write();

    if (settings)
        buffer += settings.value().write();
    buffer += Int::write(installs_count);
    return buffer;
}
BaseThemeClassic BaseThemeClassic::read(Reader reader)
{
    return BaseThemeClassic();
}

std::string BaseThemeClassic::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BaseThemeDay BaseThemeDay::read(Reader reader)
{
    return BaseThemeDay();
}

std::string BaseThemeDay::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BaseThemeNight BaseThemeNight::read(Reader reader)
{
    return BaseThemeNight();
}

std::string BaseThemeNight::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BaseThemeTinted BaseThemeTinted::read(Reader reader)
{
    return BaseThemeTinted();
}

std::string BaseThemeTinted::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BaseThemeArctic BaseThemeArctic::read(Reader reader)
{
    return BaseThemeArctic();
}

std::string BaseThemeArctic::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

InputThemeSettings::InputThemeSettings(TLObject base_theme_, int accent_color_, std::optional<int> message_top_color_, std::optional<int> message_bottom_color_, std::optional<TLObject> wallpaper_, std::optional<TLObject> wallpaper_settings_) {}

InputThemeSettings InputThemeSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject base_theme_ = std::get<TLObject>(TLObject::read(reader));
    int accent_color_ = Int::read(reader);
    std::optional<int> message_top_color_;
    message_top_color_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> message_bottom_color_;
    message_bottom_color_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> wallpaper_;
    wallpaper_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> wallpaper_settings_;
    wallpaper_settings_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return InputThemeSettings(base_theme_, accent_color_, message_top_color_, message_bottom_color_, wallpaper_, wallpaper_settings_);
}

std::string InputThemeSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= message_top_color ? 1 << 0 : 0;
    flags |= message_bottom_color ? 1 << 0 : 0;
    flags |= wallpaper ? 1 << 1 : 0;
    flags |= wallpaper_settings ? 1 << 1 : 0;
    buffer += base_theme.write();
    buffer += Int::write(accent_color);

    if (message_top_color)
        buffer += Int::write(message_top_color.value());

    if (message_bottom_color)
        buffer += Int::write(message_bottom_color.value());

    if (wallpaper)
        buffer += wallpaper.value().write();

    if (wallpaper_settings)
        buffer += wallpaper_settings.value().write();
    return buffer;
}

ThemeSettings::ThemeSettings(TLObject base_theme_, int accent_color_, std::optional<int> message_top_color_, std::optional<int> message_bottom_color_, std::optional<TLObject> wallpaper_) {}

ThemeSettings ThemeSettings::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject base_theme_ = std::get<TLObject>(TLObject::read(reader));
    int accent_color_ = Int::read(reader);
    std::optional<int> message_top_color_;
    message_top_color_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> message_bottom_color_;
    message_bottom_color_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> wallpaper_;
    wallpaper_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return ThemeSettings(base_theme_, accent_color_, message_top_color_, message_bottom_color_, wallpaper_);
}

std::string ThemeSettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= message_top_color ? 1 << 0 : 0;
    flags |= message_bottom_color ? 1 << 0 : 0;
    flags |= wallpaper ? 1 << 1 : 0;
    buffer += base_theme.write();
    buffer += Int::write(accent_color);

    if (message_top_color)
        buffer += Int::write(message_top_color.value());

    if (message_bottom_color)
        buffer += Int::write(message_bottom_color.value());

    if (wallpaper)
        buffer += wallpaper.value().write();
    return buffer;
}

WebPageAttributeTheme::WebPageAttributeTheme(std::optional<std::vector<TLObject>> documents_, std::optional<TLObject> settings_) {}

WebPageAttributeTheme WebPageAttributeTheme::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::vector<TLObject>> documents_;
    documents_ = (1 << 0) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> settings_;
    settings_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return WebPageAttributeTheme(documents_, settings_);
}

std::string WebPageAttributeTheme::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= documents ? 1 << 0 : 0;
    flags |= settings ? 1 << 1 : 0;

    if (documents)
        buffer += Vector<TLObject>::write(documents.value());

    if (settings)
        buffer += settings.value().write();
    return buffer;
}

MessageUserVote::MessageUserVote(int user_id_, std::string option_, int date_) {}

MessageUserVote MessageUserVote::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    std::string option_ = Bytes::read(reader);
    int date_ = Int::read(reader);
    return MessageUserVote(user_id_, option_, date_);
}

std::string MessageUserVote::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Bytes::write(option);
    buffer += Int::write(date);
    return buffer;
}

MessageUserVoteInputOption::MessageUserVoteInputOption(int user_id_, int date_) {}

MessageUserVoteInputOption MessageUserVoteInputOption::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return MessageUserVoteInputOption(user_id_, date_);
}

std::string MessageUserVoteInputOption::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(date);
    return buffer;
}

MessageUserVoteMultiple::MessageUserVoteMultiple(int user_id_, std::vector<std::string> options_, int date_) {}

MessageUserVoteMultiple MessageUserVoteMultiple::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    std::vector<std::string> options_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    int date_ = Int::read(reader);
    return MessageUserVoteMultiple(user_id_, options_, date_);
}

std::string MessageUserVoteMultiple::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Vector<std::string>::write(options);
    buffer += Int::write(date);
    return buffer;
}

BankCardOpenUrl::BankCardOpenUrl(std::string url_, std::string name_) {}

BankCardOpenUrl BankCardOpenUrl::read(Reader reader)
{
    std::string url_ = String::read(reader);
    std::string name_ = String::read(reader);
    return BankCardOpenUrl(url_, name_);
}

std::string BankCardOpenUrl::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    buffer += String::write(name);
    return buffer;
}

DialogFilter::DialogFilter(int id_, std::string title_, std::vector<TLObject> pinned_peers_, std::vector<TLObject> include_peers_, std::vector<TLObject> exclude_peers_, std::optional<bool> contacts_, std::optional<bool> non_contacts_, std::optional<bool> groups_, std::optional<bool> broadcasts_, std::optional<bool> bots_, std::optional<bool> exclude_muted_, std::optional<bool> exclude_read_, std::optional<bool> exclude_archived_, std::optional<std::string> emoticon_) {}

DialogFilter DialogFilter::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> contacts_;
    contacts_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> non_contacts_;
    non_contacts_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> groups_;
    groups_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> broadcasts_;
    broadcasts_ = (1 << 3) ? std::optional{true} : std::nullopt;
    std::optional<bool> bots_;
    bots_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> exclude_muted_;
    exclude_muted_ = (1 << 11) ? std::optional{true} : std::nullopt;
    std::optional<bool> exclude_read_;
    exclude_read_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> exclude_archived_;
    exclude_archived_ = (1 << 13) ? std::optional{true} : std::nullopt;
    int id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    std::optional<std::string> emoticon_;
    emoticon_ = (1 << 25) ? std::optional{String::read(reader)} : std::nullopt;
    std::vector<TLObject> pinned_peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> include_peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> exclude_peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DialogFilter(id_, title_, pinned_peers_, include_peers_, exclude_peers_, contacts_, non_contacts_, groups_, broadcasts_, bots_, exclude_muted_, exclude_read_, exclude_archived_, emoticon_);
}

std::string DialogFilter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= contacts ? 1 << 0 : 0;
    flags |= non_contacts ? 1 << 1 : 0;
    flags |= groups ? 1 << 2 : 0;
    flags |= broadcasts ? 1 << 3 : 0;
    flags |= bots ? 1 << 4 : 0;
    flags |= exclude_muted ? 1 << 11 : 0;
    flags |= exclude_read ? 1 << 12 : 0;
    flags |= exclude_archived ? 1 << 13 : 0;
    flags |= emoticon ? 1 << 25 : 0;
    buffer += Int::write(id);
    buffer += String::write(title);

    if (emoticon)
        buffer += String::write(emoticon.value());
    buffer += Vector<TLObject>::write(pinned_peers);
    buffer += Vector<TLObject>::write(include_peers);
    buffer += Vector<TLObject>::write(exclude_peers);
    return buffer;
}

DialogFilterSuggested::DialogFilterSuggested(TLObject filter_, std::string description_) {}

DialogFilterSuggested DialogFilterSuggested::read(Reader reader)
{
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    std::string description_ = String::read(reader);
    return DialogFilterSuggested(filter_, description_);
}

std::string DialogFilterSuggested::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += filter.write();
    buffer += String::write(description);
    return buffer;
}

StatsDateRangeDays::StatsDateRangeDays(int min_date_, int max_date_) {}

StatsDateRangeDays StatsDateRangeDays::read(Reader reader)
{
    int min_date_ = Int::read(reader);
    int max_date_ = Int::read(reader);
    return StatsDateRangeDays(min_date_, max_date_);
}

std::string StatsDateRangeDays::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(min_date);
    buffer += Int::write(max_date);
    return buffer;
}

StatsAbsValueAndPrev::StatsAbsValueAndPrev(double current_, double previous_) {}

StatsAbsValueAndPrev StatsAbsValueAndPrev::read(Reader reader)
{
    double current_ = Double::read(reader);
    double previous_ = Double::read(reader);
    return StatsAbsValueAndPrev(current_, previous_);
}

std::string StatsAbsValueAndPrev::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Double::write(current);
    buffer += Double::write(previous);
    return buffer;
}

StatsPercentValue::StatsPercentValue(double part_, double total_) {}

StatsPercentValue StatsPercentValue::read(Reader reader)
{
    double part_ = Double::read(reader);
    double total_ = Double::read(reader);
    return StatsPercentValue(part_, total_);
}

std::string StatsPercentValue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Double::write(part);
    buffer += Double::write(total);
    return buffer;
}

StatsGraphAsync::StatsGraphAsync(std::string token_) {}

StatsGraphAsync StatsGraphAsync::read(Reader reader)
{
    std::string token_ = String::read(reader);
    return StatsGraphAsync(token_);
}

std::string StatsGraphAsync::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(token);
    return buffer;
}

StatsGraphError::StatsGraphError(std::string error_) {}

StatsGraphError StatsGraphError::read(Reader reader)
{
    std::string error_ = String::read(reader);
    return StatsGraphError(error_);
}

std::string StatsGraphError::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(error);
    return buffer;
}

StatsGraph::StatsGraph(TLObject json_, std::optional<std::string> zoom_token_) {}

StatsGraph StatsGraph::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject json_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<std::string> zoom_token_;
    zoom_token_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    return StatsGraph(json_, zoom_token_);
}

std::string StatsGraph::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= zoom_token ? 1 << 0 : 0;
    buffer += json.write();

    if (zoom_token)
        buffer += String::write(zoom_token.value());
    return buffer;
}

MessageInteractionCounters::MessageInteractionCounters(int msg_id_, int views_, int forwards_) {}

MessageInteractionCounters MessageInteractionCounters::read(Reader reader)
{
    int msg_id_ = Int::read(reader);
    int views_ = Int::read(reader);
    int forwards_ = Int::read(reader);
    return MessageInteractionCounters(msg_id_, views_, forwards_);
}

std::string MessageInteractionCounters::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(msg_id);
    buffer += Int::write(views);
    buffer += Int::write(forwards);
    return buffer;
}

VideoSize::VideoSize(std::string type_, int w_, int h_, int size_, std::optional<double> video_start_ts_) {}

VideoSize VideoSize::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string type_ = String::read(reader);
    int w_ = Int::read(reader);
    int h_ = Int::read(reader);
    int size_ = Int::read(reader);
    std::optional<double> video_start_ts_;
    video_start_ts_ = (1 << 0) ? std::optional{Double::read(reader)} : std::nullopt;
    return VideoSize(type_, w_, h_, size_, video_start_ts_);
}

std::string VideoSize::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= video_start_ts ? 1 << 0 : 0;
    buffer += String::write(type);
    buffer += Int::write(w);
    buffer += Int::write(h);
    buffer += Int::write(size);

    if (video_start_ts)
        buffer += Double::write(video_start_ts.value());
    return buffer;
}

StatsGroupTopPoster::StatsGroupTopPoster(int user_id_, int messages_, int avg_chars_) {}

StatsGroupTopPoster StatsGroupTopPoster::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int messages_ = Int::read(reader);
    int avg_chars_ = Int::read(reader);
    return StatsGroupTopPoster(user_id_, messages_, avg_chars_);
}

std::string StatsGroupTopPoster::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(messages);
    buffer += Int::write(avg_chars);
    return buffer;
}

StatsGroupTopAdmin::StatsGroupTopAdmin(int user_id_, int deleted_, int kicked_, int banned_) {}

StatsGroupTopAdmin StatsGroupTopAdmin::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int deleted_ = Int::read(reader);
    int kicked_ = Int::read(reader);
    int banned_ = Int::read(reader);
    return StatsGroupTopAdmin(user_id_, deleted_, kicked_, banned_);
}

std::string StatsGroupTopAdmin::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(deleted);
    buffer += Int::write(kicked);
    buffer += Int::write(banned);
    return buffer;
}

StatsGroupTopInviter::StatsGroupTopInviter(int user_id_, int invitations_) {}

StatsGroupTopInviter StatsGroupTopInviter::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int invitations_ = Int::read(reader);
    return StatsGroupTopInviter(user_id_, invitations_);
}

std::string StatsGroupTopInviter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(invitations);
    return buffer;
}

GlobalPrivacySettings::GlobalPrivacySettings(std::optional<bool> archive_and_mute_new_noncontact_peers_) {}

GlobalPrivacySettings GlobalPrivacySettings::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> archive_and_mute_new_noncontact_peers_;
    archive_and_mute_new_noncontact_peers_ = (1 << 0) ? std::optional{true} : std::nullopt;
    return GlobalPrivacySettings(archive_and_mute_new_noncontact_peers_);
}

std::string GlobalPrivacySettings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= archive_and_mute_new_noncontact_peers ? 1 << 0 : 0;
    return buffer;
}

MessageViews::MessageViews(std::optional<int> views_, std::optional<int> forwards_, std::optional<TLObject> replies_) {}

MessageViews MessageViews::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<int> views_;
    views_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> forwards_;
    forwards_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<TLObject> replies_;
    replies_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return MessageViews(views_, forwards_, replies_);
}

std::string MessageViews::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= views ? 1 << 0 : 0;
    flags |= forwards ? 1 << 1 : 0;
    flags |= replies ? 1 << 2 : 0;

    if (views)
        buffer += Int::write(views.value());

    if (forwards)
        buffer += Int::write(forwards.value());

    if (replies)
        buffer += replies.value().write();
    return buffer;
}

MessageReplyHeader::MessageReplyHeader(int reply_to_msg_id_, std::optional<TLObject> reply_to_peer_id_, std::optional<int> reply_to_top_id_) {}

MessageReplyHeader MessageReplyHeader::read(Reader reader)
{
    int flags = Int::read(reader);
    int reply_to_msg_id_ = Int::read(reader);
    std::optional<TLObject> reply_to_peer_id_;
    reply_to_peer_id_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> reply_to_top_id_;
    reply_to_top_id_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageReplyHeader(reply_to_msg_id_, reply_to_peer_id_, reply_to_top_id_);
}

std::string MessageReplyHeader::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= reply_to_peer_id ? 1 << 0 : 0;
    flags |= reply_to_top_id ? 1 << 1 : 0;
    buffer += Int::write(reply_to_msg_id);

    if (reply_to_peer_id)
        buffer += reply_to_peer_id.value().write();

    if (reply_to_top_id)
        buffer += Int::write(reply_to_top_id.value());
    return buffer;
}

MessageReplies::MessageReplies(int replies_, int replies_pts_, std::optional<bool> comments_, std::optional<std::vector<TLObject>> recent_repliers_, std::optional<int> channel_id_, std::optional<int> max_id_, std::optional<int> read_max_id_) {}

MessageReplies MessageReplies::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> comments_;
    comments_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int replies_ = Int::read(reader);
    int replies_pts_ = Int::read(reader);
    std::optional<std::vector<TLObject>> recent_repliers_;
    recent_repliers_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    std::optional<int> channel_id_;
    channel_id_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> max_id_;
    max_id_ = (1 << 2) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> read_max_id_;
    read_max_id_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    return MessageReplies(replies_, replies_pts_, comments_, recent_repliers_, channel_id_, max_id_, read_max_id_);
}

std::string MessageReplies::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= comments ? 1 << 0 : 0;
    flags |= recent_repliers ? 1 << 1 : 0;
    flags |= channel_id ? 1 << 0 : 0;
    flags |= max_id ? 1 << 2 : 0;
    flags |= read_max_id ? 1 << 3 : 0;
    buffer += Int::write(replies);
    buffer += Int::write(replies_pts);

    if (recent_repliers)
        buffer += Vector<TLObject>::write(recent_repliers.value());

    if (channel_id)
        buffer += Int::write(channel_id.value());

    if (max_id)
        buffer += Int::write(max_id.value());

    if (read_max_id)
        buffer += Int::write(read_max_id.value());
    return buffer;
}

PeerBlocked::PeerBlocked(TLObject peer_id_, int date_) {}

PeerBlocked PeerBlocked::read(Reader reader)
{
    TLObject peer_id_ = std::get<TLObject>(TLObject::read(reader));
    int date_ = Int::read(reader);
    return PeerBlocked(peer_id_, date_);
}

std::string PeerBlocked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer_id.write();
    buffer += Int::write(date);
    return buffer;
}

GroupCallDiscarded::GroupCallDiscarded(long id_, long access_hash_, int duration_) {}

GroupCallDiscarded GroupCallDiscarded::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int duration_ = Int::read(reader);
    return GroupCallDiscarded(id_, access_hash_, duration_);
}

std::string GroupCallDiscarded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(duration);
    return buffer;
}

GroupCall::GroupCall(long id_, long access_hash_, int participants_count_, int version_, std::optional<bool> join_muted_, std::optional<bool> can_change_join_muted_, std::optional<bool> join_date_asc_, std::optional<bool> schedule_start_subscribed_, std::optional<bool> can_start_video_, std::optional<std::string> title_, std::optional<int> stream_dc_id_, std::optional<int> record_start_date_, std::optional<int> schedule_date_) {}

GroupCall GroupCall::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> join_muted_;
    join_muted_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_change_join_muted_;
    can_change_join_muted_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> join_date_asc_;
    join_date_asc_ = (1 << 6) ? std::optional{true} : std::nullopt;
    std::optional<bool> schedule_start_subscribed_;
    schedule_start_subscribed_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_start_video_;
    can_start_video_ = (1 << 9) ? std::optional{true} : std::nullopt;
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    int participants_count_ = Int::read(reader);
    std::optional<std::string> title_;
    title_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<int> stream_dc_id_;
    stream_dc_id_ = (1 << 4) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> record_start_date_;
    record_start_date_ = (1 << 5) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<int> schedule_date_;
    schedule_date_ = (1 << 7) ? std::optional{Int::read(reader)} : std::nullopt;
    int version_ = Int::read(reader);
    return GroupCall(id_, access_hash_, participants_count_, version_, join_muted_, can_change_join_muted_, join_date_asc_, schedule_start_subscribed_, can_start_video_, title_, stream_dc_id_, record_start_date_, schedule_date_);
}

std::string GroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= join_muted ? 1 << 1 : 0;
    flags |= can_change_join_muted ? 1 << 2 : 0;
    flags |= join_date_asc ? 1 << 6 : 0;
    flags |= schedule_start_subscribed ? 1 << 8 : 0;
    flags |= can_start_video ? 1 << 9 : 0;
    flags |= title ? 1 << 3 : 0;
    flags |= stream_dc_id ? 1 << 4 : 0;
    flags |= record_start_date ? 1 << 5 : 0;
    flags |= schedule_date ? 1 << 7 : 0;
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    buffer += Int::write(participants_count);

    if (title)
        buffer += String::write(title.value());

    if (stream_dc_id)
        buffer += Int::write(stream_dc_id.value());

    if (record_start_date)
        buffer += Int::write(record_start_date.value());

    if (schedule_date)
        buffer += Int::write(schedule_date.value());
    buffer += Int::write(version);
    return buffer;
}

InputGroupCall::InputGroupCall(long id_, long access_hash_) {}

InputGroupCall InputGroupCall::read(Reader reader)
{
    long id_ = Long::read(reader);
    long access_hash_ = Long::read(reader);
    return InputGroupCall(id_, access_hash_);
}

std::string InputGroupCall::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(id);
    buffer += Long::write(access_hash);
    return buffer;
}

GroupCallParticipant::GroupCallParticipant(TLObject peer_, int date_, int source_, std::optional<bool> muted_, std::optional<bool> left_, std::optional<bool> can_self_unmute_, std::optional<bool> just_joined_, std::optional<bool> versioned_, std::optional<bool> min_, std::optional<bool> muted_by_you_, std::optional<bool> volume_by_admin_, std::optional<bool> self_, std::optional<bool> video_joined_, std::optional<int> active_date_, std::optional<int> volume_, std::optional<std::string> about_, std::optional<long> raise_hand_rating_, std::optional<TLObject> video_, std::optional<TLObject> presentation_) {}

GroupCallParticipant GroupCallParticipant::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> muted_;
    muted_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> left_;
    left_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<bool> can_self_unmute_;
    can_self_unmute_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> just_joined_;
    just_joined_ = (1 << 4) ? std::optional{true} : std::nullopt;
    std::optional<bool> versioned_;
    versioned_ = (1 << 5) ? std::optional{true} : std::nullopt;
    std::optional<bool> min_;
    min_ = (1 << 8) ? std::optional{true} : std::nullopt;
    std::optional<bool> muted_by_you_;
    muted_by_you_ = (1 << 9) ? std::optional{true} : std::nullopt;
    std::optional<bool> volume_by_admin_;
    volume_by_admin_ = (1 << 10) ? std::optional{true} : std::nullopt;
    std::optional<bool> self_;
    self_ = (1 << 12) ? std::optional{true} : std::nullopt;
    std::optional<bool> video_joined_;
    video_joined_ = (1 << 15) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int date_ = Int::read(reader);
    std::optional<int> active_date_;
    active_date_ = (1 << 3) ? std::optional{Int::read(reader)} : std::nullopt;
    int source_ = Int::read(reader);
    std::optional<int> volume_;
    volume_ = (1 << 7) ? std::optional{Int::read(reader)} : std::nullopt;
    std::optional<std::string> about_;
    about_ = (1 << 11) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<long> raise_hand_rating_;
    raise_hand_rating_ = (1 << 13) ? std::optional{Long::read(reader)} : std::nullopt;
    std::optional<TLObject> video_;
    video_ = (1 << 6) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> presentation_;
    presentation_ = (1 << 14) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return GroupCallParticipant(peer_, date_, source_, muted_, left_, can_self_unmute_, just_joined_, versioned_, min_, muted_by_you_, volume_by_admin_, self_, video_joined_, active_date_, volume_, about_, raise_hand_rating_, video_, presentation_);
}

std::string GroupCallParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= muted ? 1 << 0 : 0;
    flags |= left ? 1 << 1 : 0;
    flags |= can_self_unmute ? 1 << 2 : 0;
    flags |= just_joined ? 1 << 4 : 0;
    flags |= versioned ? 1 << 5 : 0;
    flags |= min ? 1 << 8 : 0;
    flags |= muted_by_you ? 1 << 9 : 0;
    flags |= volume_by_admin ? 1 << 10 : 0;
    flags |= self ? 1 << 12 : 0;
    flags |= video_joined ? 1 << 15 : 0;
    flags |= active_date ? 1 << 3 : 0;
    flags |= volume ? 1 << 7 : 0;
    flags |= about ? 1 << 11 : 0;
    flags |= raise_hand_rating ? 1 << 13 : 0;
    flags |= video ? 1 << 6 : 0;
    flags |= presentation ? 1 << 14 : 0;
    buffer += peer.write();
    buffer += Int::write(date);

    if (active_date)
        buffer += Int::write(active_date.value());
    buffer += Int::write(source);

    if (volume)
        buffer += Int::write(volume.value());

    if (about)
        buffer += String::write(about.value());

    if (raise_hand_rating)
        buffer += Long::write(raise_hand_rating.value());

    if (video)
        buffer += video.value().write();

    if (presentation)
        buffer += presentation.value().write();
    return buffer;
}
InlineQueryPeerTypeSameBotPM InlineQueryPeerTypeSameBotPM::read(Reader reader)
{
    return InlineQueryPeerTypeSameBotPM();
}

std::string InlineQueryPeerTypeSameBotPM::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InlineQueryPeerTypePM InlineQueryPeerTypePM::read(Reader reader)
{
    return InlineQueryPeerTypePM();
}

std::string InlineQueryPeerTypePM::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InlineQueryPeerTypeChat InlineQueryPeerTypeChat::read(Reader reader)
{
    return InlineQueryPeerTypeChat();
}

std::string InlineQueryPeerTypeChat::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InlineQueryPeerTypeMegagroup InlineQueryPeerTypeMegagroup::read(Reader reader)
{
    return InlineQueryPeerTypeMegagroup();
}

std::string InlineQueryPeerTypeMegagroup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
InlineQueryPeerTypeBroadcast InlineQueryPeerTypeBroadcast::read(Reader reader)
{
    return InlineQueryPeerTypeBroadcast();
}

std::string InlineQueryPeerTypeBroadcast::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChatInviteImporter::ChatInviteImporter(int user_id_, int date_) {}

ChatInviteImporter ChatInviteImporter::read(Reader reader)
{
    int user_id_ = Int::read(reader);
    int date_ = Int::read(reader);
    return ChatInviteImporter(user_id_, date_);
}

std::string ChatInviteImporter::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(user_id);
    buffer += Int::write(date);
    return buffer;
}

ChatAdminWithInvites::ChatAdminWithInvites(int admin_id_, int invites_count_, int revoked_invites_count_) {}

ChatAdminWithInvites ChatAdminWithInvites::read(Reader reader)
{
    int admin_id_ = Int::read(reader);
    int invites_count_ = Int::read(reader);
    int revoked_invites_count_ = Int::read(reader);
    return ChatAdminWithInvites(admin_id_, invites_count_, revoked_invites_count_);
}

std::string ChatAdminWithInvites::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(admin_id);
    buffer += Int::write(invites_count);
    buffer += Int::write(revoked_invites_count);
    return buffer;
}

GroupCallParticipantVideoSourceGroup::GroupCallParticipantVideoSourceGroup(std::string semantics_, std::vector<int> sources_) {}

GroupCallParticipantVideoSourceGroup GroupCallParticipantVideoSourceGroup::read(Reader reader)
{
    std::string semantics_ = String::read(reader);
    std::vector<int> sources_ = std::get<std::vector<int>>(TLObject::read(reader));
    return GroupCallParticipantVideoSourceGroup(semantics_, sources_);
}

std::string GroupCallParticipantVideoSourceGroup::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(semantics);
    buffer += Vector<int>::write(sources);
    return buffer;
}

GroupCallParticipantVideo::GroupCallParticipantVideo(std::string endpoint_, std::vector<TLObject> source_groups_, std::optional<bool> paused_) {}

GroupCallParticipantVideo GroupCallParticipantVideo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> paused_;
    paused_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::string endpoint_ = String::read(reader);
    std::vector<TLObject> source_groups_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GroupCallParticipantVideo(endpoint_, source_groups_, paused_);
}

std::string GroupCallParticipantVideo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= paused ? 1 << 0 : 0;
    buffer += String::write(endpoint);
    buffer += Vector<TLObject>::write(source_groups);
    return buffer;
}
BotCommandScopeDefault BotCommandScopeDefault::read(Reader reader)
{
    return BotCommandScopeDefault();
}

std::string BotCommandScopeDefault::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BotCommandScopeUsers BotCommandScopeUsers::read(Reader reader)
{
    return BotCommandScopeUsers();
}

std::string BotCommandScopeUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BotCommandScopeChats BotCommandScopeChats::read(Reader reader)
{
    return BotCommandScopeChats();
}

std::string BotCommandScopeChats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BotCommandScopeChatAdmins BotCommandScopeChatAdmins::read(Reader reader)
{
    return BotCommandScopeChatAdmins();
}

std::string BotCommandScopeChatAdmins::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

BotCommandScopePeer::BotCommandScopePeer(TLObject peer_) {}

BotCommandScopePeer BotCommandScopePeer::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return BotCommandScopePeer(peer_);
}

std::string BotCommandScopePeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

BotCommandScopePeerAdmins::BotCommandScopePeerAdmins(TLObject peer_) {}

BotCommandScopePeerAdmins BotCommandScopePeerAdmins::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    return BotCommandScopePeerAdmins(peer_);
}

std::string BotCommandScopePeerAdmins::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    return buffer;
}

BotCommandScopePeerUser::BotCommandScopePeerUser(TLObject peer_, TLObject user_id_) {}

BotCommandScopePeerUser BotCommandScopePeerUser::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    return BotCommandScopePeerUser(peer_, user_id_);
}

std::string BotCommandScopePeerUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += user_id.write();
    return buffer;
}
