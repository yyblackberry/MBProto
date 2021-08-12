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

#include "tl/functions/langpack.h"

GetLangPack::GetLangPack(std::string lang_pack_, std::string lang_code_) {}

GetLangPack GetLangPack::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    return GetLangPack(lang_pack_, lang_code_);
}

std::string GetLangPack::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    return buffer;
}

GetStrings::GetStrings(std::string lang_pack_, std::string lang_code_, std::vector<std::string> keys_) {}

GetStrings GetStrings::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    std::vector<std::string> keys_ = std::get<std::vector<std::string>>(TLObject::read(reader));
    return GetStrings(lang_pack_, lang_code_, keys_);
}

std::string GetStrings::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    buffer += Vector<std::string>::write(keys);
    return buffer;
}

GetDifference::GetDifference(std::string lang_pack_, std::string lang_code_, int from_version_) {}

GetDifference GetDifference::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    return GetDifference(lang_pack_, lang_code_, from_version_);
}

std::string GetDifference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    return buffer;
}

GetLanguages::GetLanguages(std::string lang_pack_) {}

GetLanguages GetLanguages::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    return GetLanguages(lang_pack_);
}

std::string GetLanguages::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    return buffer;
}

GetLanguage::GetLanguage(std::string lang_pack_, std::string lang_code_) {}

GetLanguage GetLanguage::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    return GetLanguage(lang_pack_, lang_code_);
}

std::string GetLanguage::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    return buffer;
}
