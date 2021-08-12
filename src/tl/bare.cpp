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

#include "tl/bare.h"

int Int::read(Reader reader, std::string byteorder = "little")
{
    return unpackInt(reader.read(4), byteorder);
}

std::string Int::write(int value, std::string byteorder = "little")
{
    return packInt(value, 4, byteorder);
}

uint128_t Int128::read(Reader reader, std::string byteorder = "little")
{
    return unpackInt128(reader.read(16), byteorder);
}

std::string Int128::write(uint128_t value, std::string byteorder = "little")
{
    return packInt128(value, byteorder);
}

uint256_t Int256::read(Reader reader, std::string byteorder = "little")
{
    return unpackInt256(reader.read(32), byteorder);
}

std::string Int256::write(uint256_t value, std::string byteorder = "little")
{
    return packInt256(value, byteorder);
}

unsigned long Long::read(Reader reader, std::string byteorder = "little")
{
    return unpackLong(reader.read(8), byteorder);
}

std::string Long::write(unsigned long value, std::string byteorder = "little")
{
    return packLong(value, byteorder);
}

double Double::read(Reader reader)
{
    return std::stod(reader.read(8));
}

std::string Double::write(double value)
{
    return std::to_string(value);
}

std::string Bytes::read(Reader reader)
{
    size_t length = unpackInt(reader.read(1));
    std::string bytes;

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

std::string Bytes::write(std::string value)
{
    std::string buffer;
    size_t length = value.length();

    if (length >= 254)
    {
        buffer.append("\xfe");
        buffer.append(packInt(length, 3));
        buffer.append(value);

        for (size_t i = 0; i < -length % 4; i++)
            buffer.append("\x00");
    }
    else
    {
        buffer.append(packInt(length, 1));
        buffer.append(value);

        for (size_t i = 0; i < -length % 4; i++)
            buffer.append("\x00");
    }
    return buffer;
}

std::string String::read(Reader reader)
{
    return Bytes::read(reader);
};

std::string String::write(std::string value)
{
    return Bytes::write(value);
}

bool Bool::read(Reader reader)
{
    return unpackInt(reader.read(4)) == __bool_true_id;
}

std::string Bool::write(bool value)
{
    return value ? packInt(Bool::__bool_true_id, 4) : packInt(Bool::__bool_false_id, 4);
}

template <class T>
std::vector<T> Vector<T>::read(Reader reader)
{
    size_t length = Int.read(reader);
    std::vector<T> values;

    for (size_t i = 0; i < length; i++)
        values.push_back(T.read(reader));
    return values;
}

template <class T>
std::string Vector<T>::write(std::vector<T> values)
{
    std::string buffer;
    buffer.append(Int.write(__id));
    buffer.append(Int.write(values.size()));

    for (T value : values)
        buffer.append(value.write());
    return buffer;
}
