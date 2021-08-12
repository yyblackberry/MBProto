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

class GetUsers : public TLObject
{
private:
    int __id = 0xd91a548;

public:
    std::vector<TLObject> id;
    GetUsers(std::vector<TLObject> id_);
    static GetUsers read(Reader reader);
    std::string write();
};

class GetFullUser : public TLObject
{
private:
    int __id = 0xca30a5b1;

public:
    TLObject id;
    GetFullUser(TLObject id_);
    static GetFullUser read(Reader reader);
    std::string write();
};

class SetSecureValueErrors : public TLObject
{
private:
    int __id = 0x90c894b5;

public:
    TLObject id;
    std::vector<TLObject> errors;
    SetSecureValueErrors(TLObject id_, std::vector<TLObject> errors_);
    static SetSecureValueErrors read(Reader reader);
    std::string write();
};
