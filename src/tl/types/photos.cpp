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

#include "tl/types/photos.h"

Photos::Photos(std::vector<TLObject> photos_, std::vector<TLObject> users_) {}

Photos Photos::read(Reader reader)
{
    std::vector<TLObject> photos_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Photos(photos_, users_);
}

std::string Photos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(photos);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

PhotosSlice::PhotosSlice(int count_, std::vector<TLObject> photos_, std::vector<TLObject> users_) {}

PhotosSlice PhotosSlice::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> photos_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PhotosSlice(count_, photos_, users_);
}

std::string PhotosSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(photos);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

Photo::Photo(TLObject photo_, std::vector<TLObject> users_) {}

Photo Photo::read(Reader reader)
{
    TLObject photo_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return Photo(photo_, users_);
}

std::string Photo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += photo.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
