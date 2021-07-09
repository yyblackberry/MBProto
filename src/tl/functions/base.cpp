#include "tl/functions/base.h"

ReqPqMulti::ReqPqMulti(uint128_t nonce_) {}

ReqPqMulti ReqPqMulti::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    return ReqPqMulti(nonce_);
}

std::string ReqPqMulti::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    return buffer;
}

ReqDHParams::ReqDHParams(uint128_t nonce_, uint128_t server_nonce_, std::string p_, std::string q_, long public_key_fingerprint_, std::string encrypted_data_) {}

ReqDHParams ReqDHParams::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    std::string p_ = String::read(reader);
    std::string q_ = String::read(reader);
    long public_key_fingerprint_ = Long::read(reader);
    std::string encrypted_data_ = String::read(reader);
    return ReqDHParams(nonce_, server_nonce_, p_, q_, public_key_fingerprint_, encrypted_data_);
}

std::string ReqDHParams::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += String::write(p);
    buffer += String::write(q);
    buffer += Long::write(public_key_fingerprint);
    buffer += String::write(encrypted_data);
    return buffer;
}

SetClientDHParams::SetClientDHParams(uint128_t nonce_, uint128_t server_nonce_, std::string encrypted_data_) {}

SetClientDHParams SetClientDHParams::read(Reader reader)
{
    uint128_t nonce_ = Int128::read(reader);
    uint128_t server_nonce_ = Int128::read(reader);
    std::string encrypted_data_ = String::read(reader);
    return SetClientDHParams(nonce_, server_nonce_, encrypted_data_);
}

std::string SetClientDHParams::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int128::write(nonce);
    buffer += Int128::write(server_nonce);
    buffer += String::write(encrypted_data);
    return buffer;
}

RpcDropAnswer::RpcDropAnswer(long req_msg_id_) {}

RpcDropAnswer RpcDropAnswer::read(Reader reader)
{
    long req_msg_id_ = Long::read(reader);
    return RpcDropAnswer(req_msg_id_);
}

std::string RpcDropAnswer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(req_msg_id);
    return buffer;
}

GetFutureSalts::GetFutureSalts(int num_) {}

GetFutureSalts GetFutureSalts::read(Reader reader)
{
    int num_ = Int::read(reader);
    return GetFutureSalts(num_);
}

std::string GetFutureSalts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(num);
    return buffer;
}

Ping::Ping(long ping_id_) {}

Ping Ping::read(Reader reader)
{
    long ping_id_ = Long::read(reader);
    return Ping(ping_id_);
}

std::string Ping::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(ping_id);
    return buffer;
}

PingDelayDisconnect::PingDelayDisconnect(long ping_id_, int disconnect_delay_) {}

PingDelayDisconnect PingDelayDisconnect::read(Reader reader)
{
    long ping_id_ = Long::read(reader);
    int disconnect_delay_ = Int::read(reader);
    return PingDelayDisconnect(ping_id_, disconnect_delay_);
}

std::string PingDelayDisconnect::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(ping_id);
    buffer += Int::write(disconnect_delay);
    return buffer;
}

DestroySession::DestroySession(long session_id_) {}

DestroySession DestroySession::read(Reader reader)
{
    long session_id_ = Long::read(reader);
    return DestroySession(session_id_);
}

std::string DestroySession::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(session_id);
    return buffer;
}

HttpWait::HttpWait(int max_delay_, int wait_after_, int max_wait_) {}

HttpWait HttpWait::read(Reader reader)
{
    int max_delay_ = Int::read(reader);
    int wait_after_ = Int::read(reader);
    int max_wait_ = Int::read(reader);
    return HttpWait(max_delay_, wait_after_, max_wait_);
}

std::string HttpWait::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(max_delay);
    buffer += Int::write(wait_after);
    buffer += Int::write(max_wait);
    return buffer;
}
DestroyAuthKey DestroyAuthKey::read(Reader reader)
{
    return DestroyAuthKey();
}

std::string DestroyAuthKey::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
True True::read(Reader reader)
{
    return True();
}

std::string True::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BoolFalse BoolFalse::read(Reader reader)
{
    return BoolFalse();
}

std::string BoolFalse::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
BoolTrue BoolTrue::read(Reader reader)
{
    return BoolTrue();
}

std::string BoolTrue::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
Vector Vector::read(Reader reader)
{
    return Vector();
}

std::string Vector::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

Error::Error(int code_, std::string text_) {}

Error Error::read(Reader reader)
{
    int code_ = Int::read(reader);
    std::string text_ = String::read(reader);
    return Error(code_, text_);
}

std::string Error::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(code);
    buffer += String::write(text);
    return buffer;
}

IpPort::IpPort(int ipv4_, int port_) {}

IpPort IpPort::read(Reader reader)
{
    int ipv4_ = Int::read(reader);
    int port_ = Int::read(reader);
    return IpPort(ipv4_, port_);
}

std::string IpPort::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(ipv4);
    buffer += Int::write(port);
    return buffer;
}

IpPortSecret::IpPortSecret(int ipv4_, int port_, std::string secret_) {}

IpPortSecret IpPortSecret::read(Reader reader)
{
    int ipv4_ = Int::read(reader);
    int port_ = Int::read(reader);
    std::string secret_ = Bytes::read(reader);
    return IpPortSecret(ipv4_, port_, secret_);
}

std::string IpPortSecret::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(ipv4);
    buffer += Int::write(port);
    buffer += Bytes::write(secret);
    return buffer;
}

AccessPointRule::AccessPointRule(std::string phone_prefix_rules_, int dc_id_, std::vector<TLObject> ips_) {}

AccessPointRule AccessPointRule::read(Reader reader)
{
    std::string phone_prefix_rules_ = String::read(reader);
    int dc_id_ = Int::read(reader);
    std::vector<TLObject> ips_ = Vector<TLObject>::read(reader);
    return AccessPointRule(phone_prefix_rules_, dc_id_, ips_);
}

std::string AccessPointRule::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(phone_prefix_rules);
    buffer += Int::write(dc_id);
    buffer += Vector<TLObject>::write(ips);
    return buffer;
}

InputPeerPhotoFileLocationLegacy::InputPeerPhotoFileLocationLegacy(TLObject peer_, long volume_id_, int local_id_, std::optional<bool> big_) {}

InputPeerPhotoFileLocationLegacy InputPeerPhotoFileLocationLegacy::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> big_;

    if (1 << 0)
        big_ = true;
    else
        big_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    long volume_id_ = Long::read(reader);
    int local_id_ = Int::read(reader);
    return InputPeerPhotoFileLocationLegacy(peer_, volume_id_, local_id_, big_);
}

std::string InputPeerPhotoFileLocationLegacy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= big ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Long::write(volume_id);
    buffer += Int::write(local_id);
    return buffer;
}

InputStickerSetThumbLegacy::InputStickerSetThumbLegacy(TLObject stickerset_, long volume_id_, int local_id_) {}

InputStickerSetThumbLegacy InputStickerSetThumbLegacy::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    long volume_id_ = Long::read(reader);
    int local_id_ = Int::read(reader);
    return InputStickerSetThumbLegacy(stickerset_, volume_id_, local_id_);
}

std::string InputStickerSetThumbLegacy::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += Long::write(volume_id);
    buffer += Int::write(local_id);
    return buffer;
}

template <class X>
InvokeAfterMsg<X>::InvokeAfterMsg(long msg_id_, X query_) {}

template <class X>
InvokeAfterMsg<X> InvokeAfterMsg<X>::read(Reader reader)
{
    long msg_id_ = Long::read(reader);
    X query_ = X::read(reader);
    return InvokeAfterMsg<X>(msg_id_, query_);
}

template <class X>
std::string InvokeAfterMsg<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(msg_id);
    buffer += query.write();
    return buffer;
}

template <class X>
InvokeAfterMsgs<X>::InvokeAfterMsgs(std::vector<long> msg_ids_, X query_) {}

template <class X>
InvokeAfterMsgs<X> InvokeAfterMsgs<X>::read(Reader reader)
{
    std::vector<long> msg_ids_ = Vector<long>::read(reader);
    X query_ = X::read(reader);
    return InvokeAfterMsgs<X>(msg_ids_, query_);
}

template <class X>
std::string InvokeAfterMsgs<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<long>::write(msg_ids);
    buffer += query.write();
    return buffer;
}

template <class X>
InitConnection<X>::InitConnection(int api_id_, std::string device_model_, std::string system_version_, std::string app_version_, std::string system_lang_code_, std::string lang_pack_, std::string lang_code_, X query_, std::optional<TLObject> proxy_, std::optional<TLObject> params_) {}

template <class X>
InitConnection<X> InitConnection<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    int api_id_ = Int::read(reader);
    std::string device_model_ = String::read(reader);
    std::string system_version_ = String::read(reader);
    std::string app_version_ = String::read(reader);
    std::string system_lang_code_ = String::read(reader);
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    std::optional<TLObject> proxy_;

    if (1 << 0)
        proxy_ = TLObject::read(reader);
    else
        proxy_ = std::nullopt;
    std::optional<TLObject> params_;

    if (1 << 1)
        params_ = TLObject::read(reader);
    else
        params_ = std::nullopt;
    X query_ = X::read(reader);
    return InitConnection<X>(api_id_, device_model_, system_version_, app_version_, system_lang_code_, lang_pack_, lang_code_, query_, proxy_, params_);
}

template <class X>
std::string InitConnection<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= proxy ? 1 << 0 : 0;
    flags |= params ? 1 << 1 : 0;
    buffer += Int::write(api_id);
    buffer += String::write(device_model);
    buffer += String::write(system_version);
    buffer += String::write(app_version);
    buffer += String::write(system_lang_code);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);

    if (proxy)
        buffer += proxy.value().write();

    if (params)
        buffer += params.value().write();
    buffer += query.write();
    return buffer;
}

template <class X>
InvokeWithLayer<X>::InvokeWithLayer(int layer_, X query_) {}

template <class X>
InvokeWithLayer<X> InvokeWithLayer<X>::read(Reader reader)
{
    int layer_ = Int::read(reader);
    X query_ = X::read(reader);
    return InvokeWithLayer<X>(layer_, query_);
}

template <class X>
std::string InvokeWithLayer<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(layer);
    buffer += query.write();
    return buffer;
}

template <class X>
InvokeWithoutUpdates<X>::InvokeWithoutUpdates(X query_) {}

template <class X>
InvokeWithoutUpdates<X> InvokeWithoutUpdates<X>::read(Reader reader)
{
    X query_ = X::read(reader);
    return InvokeWithoutUpdates<X>(query_);
}

template <class X>
std::string InvokeWithoutUpdates<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += query.write();
    return buffer;
}

template <class X>
InvokeWithMessagesRange<X>::InvokeWithMessagesRange(TLObject range_, X query_) {}

template <class X>
InvokeWithMessagesRange<X> InvokeWithMessagesRange<X>::read(Reader reader)
{
    TLObject range_ = TLObject::read(reader);
    X query_ = X::read(reader);
    return InvokeWithMessagesRange<X>(range_, query_);
}

template <class X>
std::string InvokeWithMessagesRange<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += range.write();
    buffer += query.write();
    return buffer;
}

template <class X>
InvokeWithTakeout<X>::InvokeWithTakeout(long takeout_id_, X query_) {}

template <class X>
InvokeWithTakeout<X> InvokeWithTakeout<X>::read(Reader reader)
{
    long takeout_id_ = Long::read(reader);
    X query_ = X::read(reader);
    return InvokeWithTakeout<X>(takeout_id_, query_);
}

template <class X>
std::string InvokeWithTakeout<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(takeout_id);
    buffer += query.write();
    return buffer;
}
