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

class File : public TLObject
{
private:
    int __id = 0x96a18d5;

public:
    TLObject type;
    int mtime;
    std::string bytes;
    File(TLObject type_, int mtime_, std::string bytes_);
    static File read(Reader reader);
    std::string write();
};

class FileCdnRedirect : public TLObject
{
private:
    int __id = 0xf18cda44;

public:
    int dc_id;
    std::string file_token;
    std::string encryption_key;
    std::string encryption_iv;
    std::vector<TLObject> file_hashes;
    FileCdnRedirect(int dc_id_, std::string file_token_, std::string encryption_key_, std::string encryption_iv_, std::vector<TLObject> file_hashes_);
    static FileCdnRedirect read(Reader reader);
    std::string write();
};

class WebFile : public TLObject
{
private:
    int __id = 0x21e753bc;

public:
    int size;
    std::string mime_type;
    TLObject file_type;
    int mtime;
    std::string bytes;
    WebFile(int size_, std::string mime_type_, TLObject file_type_, int mtime_, std::string bytes_);
    static WebFile read(Reader reader);
    std::string write();
};

class CdnFileReuploadNeeded : public TLObject
{
private:
    int __id = 0xeea8e46e;

public:
    std::string request_token;
    CdnFileReuploadNeeded(std::string request_token_);
    static CdnFileReuploadNeeded read(Reader reader);
    std::string write();
};

class CdnFile : public TLObject
{
private:
    int __id = 0xa99fca4f;

public:
    std::string bytes;
    CdnFile(std::string bytes_);
    static CdnFile read(Reader reader);
    std::string write();
};
