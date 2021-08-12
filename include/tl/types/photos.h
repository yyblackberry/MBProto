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

class Photos : public TLObject
{
private:
    int __id = 0x8dca6aa5;

public:
    std::vector<TLObject> photos;
    std::vector<TLObject> users;
    Photos(std::vector<TLObject> photos_, std::vector<TLObject> users_);
    static Photos read(Reader reader);
    std::string write();
};

class PhotosSlice : public TLObject
{
private:
    int __id = 0x15051f54;

public:
    int count;
    std::vector<TLObject> photos;
    std::vector<TLObject> users;
    PhotosSlice(int count_, std::vector<TLObject> photos_, std::vector<TLObject> users_);
    static PhotosSlice read(Reader reader);
    std::string write();
};

class Photo : public TLObject
{
private:
    int __id = 0x20212ca8;

public:
    TLObject photo;
    std::vector<TLObject> users;
    Photo(TLObject photo_, std::vector<TLObject> users_);
    static Photo read(Reader reader);
    std::string write();
};
