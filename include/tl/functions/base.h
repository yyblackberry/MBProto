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

class ReqPqMulti : public TLObject
{
private:
    int __id = 0xbe7e8ef1;

public:
    uint128_t nonce;
    ReqPqMulti(uint128_t nonce_);
    static ReqPqMulti read(Reader reader);
    std::string write();
};

class ReqDHParams : public TLObject
{
private:
    int __id = 0xd712e4be;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    std::string p;
    std::string q;
    long public_key_fingerprint;
    std::string encrypted_data;
    ReqDHParams(uint128_t nonce_, uint128_t server_nonce_, std::string p_, std::string q_, long public_key_fingerprint_, std::string encrypted_data_);
    static ReqDHParams read(Reader reader);
    std::string write();
};

class SetClientDHParams : public TLObject
{
private:
    int __id = 0xf5045f1f;

public:
    uint128_t nonce;
    uint128_t server_nonce;
    std::string encrypted_data;
    SetClientDHParams(uint128_t nonce_, uint128_t server_nonce_, std::string encrypted_data_);
    static SetClientDHParams read(Reader reader);
    std::string write();
};

class RpcDropAnswer : public TLObject
{
private:
    int __id = 0x58e4a740;

public:
    long req_msg_id;
    RpcDropAnswer(long req_msg_id_);
    static RpcDropAnswer read(Reader reader);
    std::string write();
};

class GetFutureSalts : public TLObject
{
private:
    int __id = 0xb921bd04;

public:
    int num;
    GetFutureSalts(int num_);
    static GetFutureSalts read(Reader reader);
    std::string write();
};

class Ping : public TLObject
{
private:
    int __id = 0x7abe77ec;

public:
    long ping_id;
    Ping(long ping_id_);
    static Ping read(Reader reader);
    std::string write();
};

class PingDelayDisconnect : public TLObject
{
private:
    int __id = 0xf3427b8c;

public:
    long ping_id;
    int disconnect_delay;
    PingDelayDisconnect(long ping_id_, int disconnect_delay_);
    static PingDelayDisconnect read(Reader reader);
    std::string write();
};

class DestroySession : public TLObject
{
private:
    int __id = 0xe7512126;

public:
    long session_id;
    DestroySession(long session_id_);
    static DestroySession read(Reader reader);
    std::string write();
};

class HttpWait : public TLObject
{
private:
    int __id = 0x9299359f;

public:
    int max_delay;
    int wait_after;
    int max_wait;
    HttpWait(int max_delay_, int wait_after_, int max_wait_);
    static HttpWait read(Reader reader);
    std::string write();
};

class DestroyAuthKey : public TLObject
{
private:
    int __id = 0xd1435160;

public:
    DestroyAuthKey() = default;
    static DestroyAuthKey read(Reader reader);
    std::string write();
};

class Error : public TLObject
{
private:
    int __id = 0xc4b9f9bb;

public:
    int code;
    std::string text;
    Error(int code_, std::string text_);
    static Error read(Reader reader);
    std::string write();
};

class IpPort : public TLObject
{
private:
    int __id = 0xd433ad73;

public:
    int ipv4;
    int port;
    IpPort(int ipv4_, int port_);
    static IpPort read(Reader reader);
    std::string write();
};

class IpPortSecret : public TLObject
{
private:
    int __id = 0x37982646;

public:
    int ipv4;
    int port;
    std::string secret;
    IpPortSecret(int ipv4_, int port_, std::string secret_);
    static IpPortSecret read(Reader reader);
    std::string write();
};

class AccessPointRule : public TLObject
{
private:
    int __id = 0x4679b65f;

public:
    std::string phone_prefix_rules;
    int dc_id;
    std::vector<TLObject> ips;
    AccessPointRule(std::string phone_prefix_rules_, int dc_id_, std::vector<TLObject> ips_);
    static AccessPointRule read(Reader reader);
    std::string write();
};

class InputPeerPhotoFileLocationLegacy : public TLObject
{
private:
    int __id = 0x27d69997;

public:
    std::optional<bool> big;
    TLObject peer;
    long volume_id;
    int local_id;
    InputPeerPhotoFileLocationLegacy(TLObject peer_, long volume_id_, int local_id_, std::optional<bool> big_ = std::nullopt);
    static InputPeerPhotoFileLocationLegacy read(Reader reader);
    std::string write();
};

class InputStickerSetThumbLegacy : public TLObject
{
private:
    int __id = 0xdbaeae9;

public:
    TLObject stickerset;
    long volume_id;
    int local_id;
    InputStickerSetThumbLegacy(TLObject stickerset_, long volume_id_, int local_id_);
    static InputStickerSetThumbLegacy read(Reader reader);
    std::string write();
};

template <class X>
class InvokeAfterMsg : public TLObject
{
private:
    int __id = 0xcb9f372d;

public:
    long msg_id;
    X query;
    InvokeAfterMsg(long msg_id_, X query_);
    static InvokeAfterMsg<X> read(Reader reader);
    std::string write();
};

template <class X>
class InvokeAfterMsgs : public TLObject
{
private:
    int __id = 0x3dc4b4f0;

public:
    std::vector<long> msg_ids;
    X query;
    InvokeAfterMsgs(std::vector<long> msg_ids_, X query_);
    static InvokeAfterMsgs<X> read(Reader reader);
    std::string write();
};

template <class X>
class InitConnection : public TLObject
{
private:
    int __id = 0xc1cd5ea9;

public:
    int api_id;
    std::string device_model;
    std::string system_version;
    std::string app_version;
    std::string system_lang_code;
    std::string lang_pack;
    std::string lang_code;
    std::optional<TLObject> proxy;
    std::optional<TLObject> params;
    X query;
    InitConnection(int api_id_, std::string device_model_, std::string system_version_, std::string app_version_, std::string system_lang_code_, std::string lang_pack_, std::string lang_code_, X query_, std::optional<TLObject> proxy_ = std::nullopt, std::optional<TLObject> params_ = std::nullopt);
    static InitConnection<X> read(Reader reader);
    std::string write();
};

template <class X>
class InvokeWithLayer : public TLObject
{
private:
    int __id = 0xda9b0d0d;

public:
    int layer;
    X query;
    InvokeWithLayer(int layer_, X query_);
    static InvokeWithLayer<X> read(Reader reader);
    std::string write();
};

template <class X>
class InvokeWithoutUpdates : public TLObject
{
private:
    int __id = 0xbf9459b7;

public:
    X query;
    InvokeWithoutUpdates(X query_);
    static InvokeWithoutUpdates<X> read(Reader reader);
    std::string write();
};

template <class X>
class InvokeWithMessagesRange : public TLObject
{
private:
    int __id = 0x365275f2;

public:
    TLObject range;
    X query;
    InvokeWithMessagesRange(TLObject range_, X query_);
    static InvokeWithMessagesRange<X> read(Reader reader);
    std::string write();
};

template <class X>
class InvokeWithTakeout : public TLObject
{
private:
    int __id = 0xaca9fd2e;

public:
    long takeout_id;
    X query;
    InvokeWithTakeout(long takeout_id_, X query_);
    static InvokeWithTakeout<X> read(Reader reader);
    std::string write();
};
