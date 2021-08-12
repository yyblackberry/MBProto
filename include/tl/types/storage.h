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

class FileUnknown : public TLObject
{
private:
    int __id = 0xaa963b05;

public:
    FileUnknown() = default;
    static FileUnknown read(Reader reader);
    std::string write();
};

class FilePartial : public TLObject
{
private:
    int __id = 0x40bc6f52;

public:
    FilePartial() = default;
    static FilePartial read(Reader reader);
    std::string write();
};

class FileJpeg : public TLObject
{
private:
    int __id = 0x7efe0e;

public:
    FileJpeg() = default;
    static FileJpeg read(Reader reader);
    std::string write();
};

class FileGif : public TLObject
{
private:
    int __id = 0xcae1aadf;

public:
    FileGif() = default;
    static FileGif read(Reader reader);
    std::string write();
};

class FilePng : public TLObject
{
private:
    int __id = 0xa4f63c0;

public:
    FilePng() = default;
    static FilePng read(Reader reader);
    std::string write();
};

class FilePdf : public TLObject
{
private:
    int __id = 0xae1e508d;

public:
    FilePdf() = default;
    static FilePdf read(Reader reader);
    std::string write();
};

class FileMov : public TLObject
{
private:
    int __id = 0x4b09ebbc;

public:
    FileMov() = default;
    static FileMov read(Reader reader);
    std::string write();
};

class FileWebp : public TLObject
{
private:
    int __id = 0x1081464c;

public:
    FileWebp() = default;
    static FileWebp read(Reader reader);
    std::string write();
};
