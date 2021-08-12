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

class UpdateProfilePhoto : public TLObject
{
private:
    int __id = 0x72d4742c;

public:
    TLObject id;
    UpdateProfilePhoto(TLObject id_);
    static UpdateProfilePhoto read(Reader reader);
    std::string write();
};

class UploadProfilePhoto : public TLObject
{
private:
    int __id = 0x89f30f69;

public:
    std::optional<TLObject> file;
    std::optional<TLObject> video;
    std::optional<double> video_start_ts;
    UploadProfilePhoto(std::optional<TLObject> file_ = std::nullopt, std::optional<TLObject> video_ = std::nullopt, std::optional<double> video_start_ts_ = std::nullopt);
    static UploadProfilePhoto read(Reader reader);
    std::string write();
};

class DeletePhotos : public TLObject
{
private:
    int __id = 0x87cf7f2f;

public:
    std::vector<TLObject> id;
    DeletePhotos(std::vector<TLObject> id_);
    static DeletePhotos read(Reader reader);
    std::string write();
};

class GetUserPhotos : public TLObject
{
private:
    int __id = 0x91cd32a8;

public:
    TLObject user_id;
    int offset;
    long max_id;
    int limit;
    GetUserPhotos(TLObject user_id_, int offset_, long max_id_, int limit_);
    static GetUserPhotos read(Reader reader);
    std::string write();
};
