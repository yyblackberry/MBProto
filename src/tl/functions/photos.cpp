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

#include "tl/functions/photos.h"

UpdateProfilePhoto::UpdateProfilePhoto(TLObject id_) {}

UpdateProfilePhoto UpdateProfilePhoto::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return UpdateProfilePhoto(id_);
}

std::string UpdateProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

UploadProfilePhoto::UploadProfilePhoto(std::optional<TLObject> file_, std::optional<TLObject> video_, std::optional<double> video_start_ts_) {}

UploadProfilePhoto UploadProfilePhoto::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> file_;
    file_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> video_;
    video_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<double> video_start_ts_;
    video_start_ts_ = (1 << 2) ? std::optional{Double::read(reader)} : std::nullopt;
    return UploadProfilePhoto(file_, video_, video_start_ts_);
}

std::string UploadProfilePhoto::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= file ? 1 << 0 : 0;
    flags |= video ? 1 << 1 : 0;
    flags |= video_start_ts ? 1 << 2 : 0;

    if (file)
        buffer += file.value().write();

    if (video)
        buffer += video.value().write();

    if (video_start_ts)
        buffer += Double::write(video_start_ts.value());
    return buffer;
}

DeletePhotos::DeletePhotos(std::vector<TLObject> id_) {}

DeletePhotos DeletePhotos::read(Reader reader)
{
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return DeletePhotos(id_);
}

std::string DeletePhotos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

GetUserPhotos::GetUserPhotos(TLObject user_id_, int offset_, long max_id_, int limit_) {}

GetUserPhotos GetUserPhotos::read(Reader reader)
{
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    int offset_ = Int::read(reader);
    long max_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetUserPhotos(user_id_, offset_, max_id_, limit_);
}

std::string GetUserPhotos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(offset);
    buffer += Long::write(max_id);
    buffer += Int::write(limit);
    return buffer;
}
