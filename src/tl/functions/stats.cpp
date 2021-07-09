#include "tl/functions/stats.h"

template <class X>
GetBroadcastStats<X>::GetBroadcastStats(TLObject channel_, std::optional<bool> dark_) {}

template <class X>
GetBroadcastStats<X> GetBroadcastStats<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;

    if (1 << 0)
        dark_ = true;
    else
        dark_ = std::nullopt;
    TLObject channel_ = TLObject::read(reader);
    return GetBroadcastStats<X>(channel_, dark_);
}

template <class X>
std::string GetBroadcastStats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    return buffer;
}

template <class X>
LoadAsyncGraph<X>::LoadAsyncGraph(std::string token_, std::optional<long> x_) {}

template <class X>
LoadAsyncGraph<X> LoadAsyncGraph<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string token_ = String::read(reader);
    std::optional<long> x_;

    if (1 << 0)
        x_ = Long::read(reader);
    else
        x_ = std::nullopt;
    return LoadAsyncGraph<X>(token_, x_);
}

template <class X>
std::string LoadAsyncGraph<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= x ? 1 << 0 : 0;
    buffer += String::write(token);

    if (x)
        buffer += Long::write(x.value());
    return buffer;
}

template <class X>
GetMegagroupStats<X>::GetMegagroupStats(TLObject channel_, std::optional<bool> dark_) {}

template <class X>
GetMegagroupStats<X> GetMegagroupStats<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;

    if (1 << 0)
        dark_ = true;
    else
        dark_ = std::nullopt;
    TLObject channel_ = TLObject::read(reader);
    return GetMegagroupStats<X>(channel_, dark_);
}

template <class X>
std::string GetMegagroupStats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    return buffer;
}

template <class X>
GetMessagePublicForwards<X>::GetMessagePublicForwards(TLObject channel_, int msg_id_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_) {}

template <class X>
GetMessagePublicForwards<X> GetMessagePublicForwards<X>::read(Reader reader)
{
    TLObject channel_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    int offset_rate_ = Int::read(reader);
    TLObject offset_peer_ = TLObject::read(reader);
    int offset_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetMessagePublicForwards<X>(channel_, msg_id_, offset_rate_, offset_peer_, offset_id_, limit_);
}

template <class X>
std::string GetMessagePublicForwards<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += channel.write();
    buffer += Int::write(msg_id);
    buffer += Int::write(offset_rate);
    buffer += offset_peer.write();
    buffer += Int::write(offset_id);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
GetMessageStats<X>::GetMessageStats(TLObject channel_, int msg_id_, std::optional<bool> dark_) {}

template <class X>
GetMessageStats<X> GetMessageStats<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;

    if (1 << 0)
        dark_ = true;
    else
        dark_ = std::nullopt;
    TLObject channel_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    return GetMessageStats<X>(channel_, msg_id_, dark_);
}

template <class X>
std::string GetMessageStats<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    buffer += Int::write(msg_id);
    return buffer;
}
