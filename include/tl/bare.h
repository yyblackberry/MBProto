/* Copyright (c) 2021 Mattia Lorenzo Chiabrando
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once
#include <cstring>
#include <string>
#include "tl/TLObject.h"
#include "utils/streams.h"
#include "utils/packing.h"

class Int : public TLObject
{
public:
    static int read(Reader reader);
    static void write(Writer writer, const int value);
};

class Int128 : public TLObject
{
public:
    static int128_t read(Reader reader);
    static void write(Writer writer, const int128_t value);
};

class Int256 : public TLObject
{
public:
    static int256_t read(Reader reader);
    static void write(Writer writer, const int256_t value);
};

class Long : public TLObject
{
public:
    static long read(Reader reader);
    static void write(Writer writer, const long value);
};

class Double : public TLObject
{
public:
    static double read(Reader reader);
    static void write(Writer writer, const double value);
};

class Bytes : public TLObject
{
public:
    static std::vector<unsigned char> read(Reader reader);
    static void write(Writer writer, std::vector<unsigned char> value);
};

class String : public Bytes
{
public:
    static std::string read(Reader reader);
    static void write(Writer writer, std::string value);
};

class Bool : public TLObject
{
private:
    static const int __bool_false_id = 0xbc799737;
    static const int __bool_true_id = 0x997275b5;

public:
    static bool read(Reader reader);
    static void write(Writer writer, const bool value);
};

template <class T, typename U>
class Vector : public TLObject
{
    static_assert(std::is_base_of_v<TLObject, T>);

public:
    static const int tl_id = 0x1cb5c415;

    static std::vector<U> read(Reader reader);
    static void write(Writer writer, std::vector<T> values);
    template <class Q = void, typename = typename std::enable_if_t<!std::is_same_v<U, T>, Q>>
    static void write(Writer writer, std::vector<U> values);
};
