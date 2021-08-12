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

class SaveFilePart : public TLObject
{
private:
    int __id = 0xb304a621;

public:
    long file_id;
    int file_part;
    std::string bytes;
    SaveFilePart(long file_id_, int file_part_, std::string bytes_);
    static SaveFilePart read(Reader reader);
    std::string write();
};

class GetFile : public TLObject
{
private:
    int __id = 0xb15a9afc;

public:
    std::optional<bool> precise;
    std::optional<bool> cdn_supported;
    TLObject location;
    int offset;
    int limit;
    GetFile(TLObject location_, int offset_, int limit_, std::optional<bool> precise_ = std::nullopt, std::optional<bool> cdn_supported_ = std::nullopt);
    static GetFile read(Reader reader);
    std::string write();
};

class SaveBigFilePart : public TLObject
{
private:
    int __id = 0xde7b673d;

public:
    long file_id;
    int file_part;
    int file_total_parts;
    std::string bytes;
    SaveBigFilePart(long file_id_, int file_part_, int file_total_parts_, std::string bytes_);
    static SaveBigFilePart read(Reader reader);
    std::string write();
};

class GetWebFile : public TLObject
{
private:
    int __id = 0x24e6818d;

public:
    TLObject location;
    int offset;
    int limit;
    GetWebFile(TLObject location_, int offset_, int limit_);
    static GetWebFile read(Reader reader);
    std::string write();
};

class GetCdnFile : public TLObject
{
private:
    int __id = 0x2000bcc3;

public:
    std::string file_token;
    int offset;
    int limit;
    GetCdnFile(std::string file_token_, int offset_, int limit_);
    static GetCdnFile read(Reader reader);
    std::string write();
};

class ReuploadCdnFile : public TLObject
{
private:
    int __id = 0x9b2754a8;

public:
    std::string file_token;
    std::string request_token;
    ReuploadCdnFile(std::string file_token_, std::string request_token_);
    static ReuploadCdnFile read(Reader reader);
    std::string write();
};

class GetCdnFileHashes : public TLObject
{
private:
    int __id = 0x4da54231;

public:
    std::string file_token;
    int offset;
    GetCdnFileHashes(std::string file_token_, int offset_);
    static GetCdnFileHashes read(Reader reader);
    std::string write();
};

class GetFileHashes : public TLObject
{
private:
    int __id = 0xc7025931;

public:
    TLObject location;
    int offset;
    GetFileHashes(TLObject location_, int offset_);
    static GetFileHashes read(Reader reader);
    std::string write();
};
