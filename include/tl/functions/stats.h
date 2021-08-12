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

class GetBroadcastStats : public TLObject
{
private:
    int __id = 0xab42441a;

public:
    std::optional<bool> dark;
    TLObject channel;
    GetBroadcastStats(TLObject channel_, std::optional<bool> dark_ = std::nullopt);
    static GetBroadcastStats read(Reader reader);
    std::string write();
};

class LoadAsyncGraph : public TLObject
{
private:
    int __id = 0x621d5fa0;

public:
    std::string token;
    std::optional<long> x;
    LoadAsyncGraph(std::string token_, std::optional<long> x_ = std::nullopt);
    static LoadAsyncGraph read(Reader reader);
    std::string write();
};

class GetMegagroupStats : public TLObject
{
private:
    int __id = 0xdcdf8607;

public:
    std::optional<bool> dark;
    TLObject channel;
    GetMegagroupStats(TLObject channel_, std::optional<bool> dark_ = std::nullopt);
    static GetMegagroupStats read(Reader reader);
    std::string write();
};

class GetMessagePublicForwards : public TLObject
{
private:
    int __id = 0x5630281b;

public:
    TLObject channel;
    int msg_id;
    int offset_rate;
    TLObject offset_peer;
    int offset_id;
    int limit;
    GetMessagePublicForwards(TLObject channel_, int msg_id_, int offset_rate_, TLObject offset_peer_, int offset_id_, int limit_);
    static GetMessagePublicForwards read(Reader reader);
    std::string write();
};

class GetMessageStats : public TLObject
{
private:
    int __id = 0xb6e0a3f5;

public:
    std::optional<bool> dark;
    TLObject channel;
    int msg_id;
    GetMessageStats(TLObject channel_, int msg_id_, std::optional<bool> dark_ = std::nullopt);
    static GetMessageStats read(Reader reader);
    std::string write();
};
