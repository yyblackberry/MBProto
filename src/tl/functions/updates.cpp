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

#include "tl/functions/updates.h"
GetState GetState::read(Reader reader)
{
    return GetState();
}

std::string GetState::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

GetDifference::GetDifference(int pts_, int date_, int qts_, std::optional<int> pts_total_limit_) {}

GetDifference GetDifference::read(Reader reader)
{
    int flags = Int::read(reader);
    int pts_ = Int::read(reader);
    std::optional<int> pts_total_limit_;
    pts_total_limit_ = (1 << 0) ? std::optional{Int::read(reader)} : std::nullopt;
    int date_ = Int::read(reader);
    int qts_ = Int::read(reader);
    return GetDifference(pts_, date_, qts_, pts_total_limit_);
}

std::string GetDifference::write()
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

GetChannelDifference::GetChannelDifference(TLObject channel_, TLObject filter_, int pts_, int limit_, std::optional<bool> force_) {}

GetChannelDifference GetChannelDifference::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> force_;
    force_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject channel_ = std::get<TLObject>(TLObject::read(reader));
    TLObject filter_ = std::get<TLObject>(TLObject::read(reader));
    int pts_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetChannelDifference(channel_, filter_, pts_, limit_, force_);
}

std::string GetChannelDifference::write()
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
