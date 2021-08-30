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
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int unpackInt(const std::vector<unsigned char> buffer, const char *byteorder = "little");
std::vector<unsigned char> packInt(const int n, const size_t length, const char *byteorder = "little");
long unpackLong(const std::vector<unsigned char> buffer, const char *byteorder = "little");
std::vector<unsigned char> packLong(const long n, const char *byteorder = "little");
int128_t unpackInt128(const std::vector<unsigned char> buffer, const char *byteorder = "little");
std::vector<unsigned char> packInt128(const int128_t n, const char *byteorder = "little");
int256_t unpackInt256(const std::vector<unsigned char> buffer, const char *byteorder = "little");
std::vector<unsigned char> packInt256(const int256_t n, const char *byteorder = "little");
