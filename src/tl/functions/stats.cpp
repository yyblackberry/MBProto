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

#include "tl/functions/stats.h"

GetBroadcastStats::GetBroadcastStats(TLObject channel_, std::optional<bool> dark_) {}

GetBroadcastStats GetBroadcastStats::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;
    dark_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return GetBroadcastStats(channel_, dark_);
}

std::string GetBroadcastStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    return buffer;
}

LoadAsyncGraph::LoadAsyncGraph(std::string token_, std::optional<long> x_) {}

LoadAsyncGraph LoadAsyncGraph::read(Reader reader)
{
    int flags = Int::read(reader);
    std::string token_ = String::read(reader);
    std::optional<long> x_;
    x_ = (1 << 0) ? std::optional{Long::read(reader)} : std::nullopt;
    return LoadAsyncGraph(token_, x_);
}

std::string LoadAsyncGraph::write()
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

GetMegagroupStats::GetMegagroupStats(TLObject channel_, std::optional<bool> dark_) {}

GetMegagroupStats GetMegagroupStats::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;
    dark_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    return GetMegagroupStats(channel_, dark_);
}

std::string GetMegagroupStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    return buffer;
}

GetMessagePublicForwards::GetMessagePublicForwards(TLObject channel_, int msg_id_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_) {}

GetMessagePublicForwards GetMessagePublicForwards::read(Reader reader)
{
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    int offset_rate_ = Int::read(reader);
    TLObject offset_peer_ = std::get<TLObject>(TLObject::read(reader));
    int offset_id_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetMessagePublicForwards(channel_, msg_id_, offset_rate_, offset_peer_, offset_id_, limit_);
}

std::string GetMessagePublicForwards::write()
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

GetMessageStats::GetMessageStats(TLObject channel_, int msg_id_, std::optional<bool> dark_) {}

GetMessageStats GetMessageStats::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> dark_;
    dark_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    return GetMessageStats(channel_, msg_id_, dark_);
}

std::string GetMessageStats::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= dark ? 1 << 0 : 0;
    buffer += channel.write();
    buffer += Int::write(msg_id);
    return buffer;
}
