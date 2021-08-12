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

class GetLangPack : public TLObject
{
private:
    int __id = 0xf2f2330a;

public:
    std::string lang_pack;
    std::string lang_code;
    GetLangPack(std::string lang_pack_, std::string lang_code_);
    static GetLangPack read(Reader reader);
    std::string write();
};

class GetStrings : public TLObject
{
private:
    int __id = 0xefea3803;

public:
    std::string lang_pack;
    std::string lang_code;
    std::vector<std::string> keys;
    GetStrings(std::string lang_pack_, std::string lang_code_, std::vector<std::string> keys_);
    static GetStrings read(Reader reader);
    std::string write();
};

class GetDifference : public TLObject
{
private:
    int __id = 0xcd984aa5;

public:
    std::string lang_pack;
    std::string lang_code;
    int from_version;
    GetDifference(std::string lang_pack_, std::string lang_code_, int from_version_);
    static GetDifference read(Reader reader);
    std::string write();
};

class GetLanguages : public TLObject
{
private:
    int __id = 0x42c6978f;

public:
    std::string lang_pack;
    GetLanguages(std::string lang_pack_);
    static GetLanguages read(Reader reader);
    std::string write();
};

class GetLanguage : public TLObject
{
private:
    int __id = 0x6a596502;

public:
    std::string lang_pack;
    std::string lang_code;
    GetLanguage(std::string lang_pack_, std::string lang_code_);
    static GetLanguage read(Reader reader);
    std::string write();
};
