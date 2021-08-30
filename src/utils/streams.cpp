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

#include "utils/streams.h"

Reader::Reader(std::vector<unsigned char> data) : __buffer(data) {}

std::vector<unsigned char> Reader::getBuffer()
{
    return __buffer;
}

std::vector<unsigned char> Reader::read(const size_t length)
{
    if (__position + length >= __buffer.size())
        throw std::invalid_argument("The given length is invalid");
    return std::vector<unsigned char>(__buffer.begin() + __position, __buffer.begin() + (__position += length));
}

void Reader::seek(const size_t offset)
{
    if (__position + offset < 0 || __position + offset >= __buffer.size())
        throw std::invalid_argument("The given offset is invalid");
    __position += offset;
}

Writer::Writer(std::vector<unsigned char> data) : __buffer(data) {}

std::vector<unsigned char> Writer::getBuffer()
{
    return __buffer;
}

void Writer::write(std::vector<unsigned char> data)
{
    __buffer.insert(__buffer.begin(), data.begin(), data.end());
}

void Writer::write(unsigned char data)
{
    __buffer.push_back(data);
}
