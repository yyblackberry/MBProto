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

#include "tl/types/stickers.h"

SuggestedShortName::SuggestedShortName(std::string short_name_) {}

SuggestedShortName SuggestedShortName::read(Reader reader)
{
    std::string short_name_ = String::read(reader);
    return SuggestedShortName(short_name_);
}

std::string SuggestedShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(short_name);
    return buffer;
}
