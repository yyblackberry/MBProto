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

#include "tl/bare.h"

int Int::read(Reader reader, const char byteorder[])
{
    return unpackInt(reader.read(4), byteorder);
}

void Int::write(Writer writer, int value, const char byteorder[])
{
    return writer.write(packInt(value, 4, byteorder));
}

int128_t Int128::read(Reader reader, const char byteorder[])
{
    return unpackInt128(reader.read(16), byteorder);
}

void Int128::write(Writer writer, int128_t value, const char byteorder[])
{
    return writer.write(packInt128(value, byteorder));
}

int256_t Int256::read(Reader reader, const char byteorder[])
{
    return unpackInt256(reader.read(32), byteorder);
}

void Int256::write(Writer writer, int256_t value, const char byteorder[])
{
    return writer.write(packInt256(value, byteorder));
}

long Long::read(Reader reader, const char byteorder[])
{
    return unpackLong(reader.read(8), byteorder);
}

void Long::write(Writer writer, long value, const char byteorder[])
{
    return writer.write(packLong(value, byteorder));
}

double Double::read(Reader reader)
{
    double value;
    std::vector<unsigned char> buffer = reader.read(8);
    memcpy(&value, &buffer[0], std::min(buffer.size(), sizeof(double)));
    return value;
}

void Double::write(Writer writer, double value)
{
    std::vector<unsigned char> buffer;
    memcpy(&buffer[0], &value, std::min(sizeof(double), buffer.size()));
    writer.write(buffer);
}

std::vector<unsigned char> Bytes::read(Reader reader)
{
    size_t length = unpackInt(reader.read(1));
    std::vector<unsigned char> bytes;

    if (length == 254)
    {
        length = unpackInt(reader.read(3));
        bytes = reader.read(length);
        reader.read(-length % 4);
    }
    else
    {
        bytes = reader.read(length);
        reader.read(-(length + 1) % 4);
    }
    return bytes;
};

void Bytes::write(Writer writer, std::vector<unsigned char> value)
{
    std::vector<unsigned char> buffer;
    std::vector<unsigned char> tmp;
    size_t length = value.size();

    if (length >= 254)
    {
        buffer.push_back('\xfe');
        tmp = packInt(length, 3);
        buffer.insert(buffer.begin(), tmp.begin(), tmp.end());
        buffer.insert(buffer.begin(), value.begin(), value.end());

        for (size_t i = 0; i < -length % 4; i++)
            buffer.push_back('\x00');
    }
    else
    {
        tmp = packInt(length, 1);
        buffer.insert(buffer.begin(), tmp.begin(), tmp.end());
        buffer.insert(buffer.begin(), value.begin(), value.end());

        for (size_t i = 0; i < -length % 4; i++)
            buffer.push_back('\x00');
    }
    writer.write(buffer);
}

std::string String::read(Reader reader)
{
    std::vector<unsigned char> buffer = Bytes::read(reader);
    return std::string(buffer.begin(), buffer.end());
};

void String::write(Writer writer, std::string value)
{
    Bytes::write(writer, std::vector<unsigned char>(value.begin(), value.end()));
}

bool Bool::read(Reader reader)
{
    return unpackInt(reader.read(4)) == __bool_true_id;
}

void Bool::write(Writer writer, bool value)
{
    writer.write(value ? packInt(Bool::__bool_true_id, 4) : packInt(Bool::__bool_false_id, 4));
}
