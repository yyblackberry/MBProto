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

#include "utils/packing.h"

int unpackInt(const std::vector<unsigned char> buffer, const char byteorder[])
{
    int n = 0;
    size_t length = buffer.size();

    for (size_t i = 0; i < length; i++)
        n |= buffer[i] << ((byteorder == "little" ? i : length - 1 - i) * 8);
    return n;
}

std::vector<unsigned char> packInt(const int n, const size_t length, const char byteorder[])
{
    std::vector<unsigned char> buffer(length);

    for (size_t i = 0; i < length; i++)
        buffer[i] = n >> ((byteorder == "little" ? i : length - 1 - i) * 8) & 0xFF;
    return buffer;
}

long unpackLong(const std::vector<unsigned char> buffer, const char byteorder[])
{
    long n = 0;

    for (size_t i = 0; i < 8; i++)
        n |= buffer[i] << ((byteorder == "little" ? i : 7 - i) * 8);
    return n;
}

std::vector<unsigned char> packLong(const long n, const char byteorder[])
{
    std::vector<unsigned char> buffer(8);

    for (size_t i = 0; i < 8; i++)
        buffer[i] = n >> ((byteorder == "little" ? i : 7 - i) * 8) & 0xFF;
    return buffer;
}

int128_t unpackInt128(const std::vector<unsigned char> buffer, const char byteorder[])
{
    int128_t n = 0;

    for (size_t i = 0; i < 16; i++)
        n |= buffer[i] << ((byteorder == "little" ? i : 15 - i) * 8);
    return n;
}

std::vector<unsigned char> packInt128(const int128_t n, const char byteorder[])
{
    std::vector<unsigned char> buffer(16);

    for (size_t i = 0; i < 16; i++)
        buffer[i] = (uint8_t)(n >> ((byteorder == "little" ? i : 15 - i) * 8) & 0xFF);
    return buffer;
}

int256_t unpackInt256(const std::vector<unsigned char> buffer, const char byteorder[])
{
    int256_t n = 0;

    for (size_t i = 0; i < 32; i++)
        n |= buffer[i] << ((byteorder == "little" ? i : 31 - i) * 8);
    return n;
}

std::vector<unsigned char> packInt256(const int256_t n, const char byteorder[])
{
    std::vector<unsigned char> buffer(32);

    for (size_t i = 0; i < 32; i++)
        buffer[i] = (uint8_t)(n >> ((byteorder == "little" ? i : 31 - i) * 8) & 0xFF);
    return buffer;
}
