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
#include "util.h"
#include "TLObject.h"
#include <vector>

class Int : public TLObject
{
public:
    Int() = default;
    static int read(Reader reader, std::string byteorder = "little");
    static std::string write(int value, std::string byteorder = "little");
};

class Int128 : public TLObject
{
public:
    Int128() = default;
    static uint128_t read(Reader reader, std::string byteorder = "little");
    static std::string write(uint128_t value, std::string byteorder = "little");
};

class Int256 : public TLObject
{
public:
    Int256() = default;
    static uint256_t read(Reader reader, std::string byteorder = "little");
    static std::string write(uint256_t value, std::string byteorder = "little");
};

class Long : public TLObject
{
public:
    Long() = default;
    static unsigned long read(Reader reader, std::string byteorder = "little");
    static std::string write(unsigned long value, std::string byteorder = "little");
};

class Double : public TLObject
{
public:
    Double() = default;
    static double read(Reader reader);
    static std::string write(double value);
};

class Bytes : public TLObject
{
public:
    Bytes() = default;
    static std::string read(Reader reader);
    static std::string write(std::string value);
};

class String : public Bytes
{
public:
    String() = default;
    static std::string read(Reader reader);
    static std::string write(std::string value);
};

class Bool : public TLObject
{
private:
    static const int Bool::__bool_false_id = 0xbc799737;
    static const int Bool::__bool_true_id = 0x997275b5;

public:
    Bool() = default;
    static bool read(Reader reader);
    static std::string write(bool value);
};

template <class T>
class Vector : public TLObject
{
private:
    int __id = 0x1cb5c415;

public:
    Vector() = default;
    static std::vector<T> read(Reader reader);
    static std::string write(std::vector<T> values);
};
