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

class GetState : public TLObject
{
private:
    int __id = 0xedd4882a;

public:
    GetState() = default;
    static GetState read(Reader reader);
    std::string write();
};

class GetDifference : public TLObject
{
private:
    int __id = 0x25939651;

public:
    int pts;
    std::optional<int> pts_total_limit;
    int date;
    int qts;
    GetDifference(int pts_, int date_, int qts_, std::optional<int> pts_total_limit_ = std::nullopt);
    static GetDifference read(Reader reader);
    std::string write();
};

class GetChannelDifference : public TLObject
{
private:
    int __id = 0x3173d78;

public:
    std::optional<bool> force;
    TLObject channel;
    TLObject filter;
    int pts;
    int limit;
    GetChannelDifference(TLObject channel_, TLObject filter_, int pts_, int limit_, std::optional<bool> force_ = std::nullopt);
    static GetChannelDifference read(Reader reader);
    std::string write();
};
