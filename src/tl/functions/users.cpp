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

#include "tl/functions/users.h"

GetUsers::GetUsers(std::vector<TLObject> id_) {}

GetUsers GetUsers::read(Reader reader)
{
    std::vector<TLObject> id_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return GetUsers(id_);
}

std::string GetUsers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

GetFullUser::GetFullUser(TLObject id_) {}

GetFullUser GetFullUser::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    return GetFullUser(id_);
}

std::string GetFullUser::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

SetSecureValueErrors::SetSecureValueErrors(TLObject id_, std::vector<TLObject> errors_) {}

SetSecureValueErrors SetSecureValueErrors::read(Reader reader)
{
    TLObject id_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> errors_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return SetSecureValueErrors(id_, errors_);
}

std::string SetSecureValueErrors::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Vector<TLObject>::write(errors);
    return buffer;
}
