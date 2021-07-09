#include "tl/functions/updates.h"
template <class X>
GetState<X> GetState<X>::read(Reader reader)
{
    return GetState<X>();
}

template <class X>
std::string GetState<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
GetDifference<X>::GetDifference(int pts_, int date_, int qts_, std::optional<int> pts_total_limit_) {}

template <class X>
GetDifference<X> GetDifference<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    int pts_ = Int::read(reader);
    std::optional<int> pts_total_limit_;

    if (1 << 0)
        pts_total_limit_ = Int::read(reader);
    else
        pts_total_limit_ = std::nullopt;
    int date_ = Int::read(reader);
    int qts_ = Int::read(reader);
    return GetDifference<X>(pts_, date_, qts_, pts_total_limit_);
}

template <class X>
std::string GetDifference<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= pts_total_limit ? 1 << 0 : 0;
    buffer += Int::write(pts);

    if (pts_total_limit)
        buffer += Int::write(pts_total_limit.value());
    buffer += Int::write(date);
    buffer += Int::write(qts);
    return buffer;
}

template <class X>
GetChannelDifference<X>::GetChannelDifference(TLObject channel_, TLObject filter_, int pts_, int limit_, std::optional<bool> force_) {}

template <class X>
GetChannelDifference<X> GetChannelDifference<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> force_;

    if (1 << 0)
        force_ = true;
    else
        force_ = std::nullopt;
    TLObject channel_ = TLObject::read(reader);
    TLObject filter_ = TLObject::read(reader);
    int pts_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetChannelDifference<X>(channel_, filter_, pts_, limit_, force_);
}

template <class X>
std::string GetChannelDifference<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= force ? 1 << 0 : 0;
    buffer += channel.write();
    buffer += filter.write();
    buffer += Int::write(pts);
    buffer += Int::write(limit);
    return buffer;
}
