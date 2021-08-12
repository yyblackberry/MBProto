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

#include "transports/TCP.h"

void Abridged::start()
{
    _connection.start();
    _connection.send("\xef");
}

std::string Abridged::recv()
{
    size_t length = unpackInt(_connection.recv(1));

    if (length == 127)
        length = unpackInt(_connection.recv(3));
    return _connection.recv(length * 4);
}

void Abridged::send(std::string buffer)
{
    size_t length = buffer.length() / 4;

    if (length >= 127)
    {
        _connection.send("\x7f");
        _connection.send(packInt(length, 3));
    }
    else
        _connection.send(packInt(length, 1));
    _connection.send(buffer);
}

void Intermediate::start()
{
    _connection.start();
    _connection.send("\xee\xee\xee\xee");
}

std::string Intermediate::recv()
{
    return _connection.recv(unpackInt(_connection.recv(4)));
}

void Intermediate::send(std::string buffer)
{
    _connection.send(packInt(buffer.length(), 4));
    _connection.send(buffer);
}

void PaddedIntermediate::start()
{
    throw std::runtime_error("Not implemented yet");
}

std::string PaddedIntermediate::recv()
{
    throw std::runtime_error("Not implemented yet");
    return 0;
}

void PaddedIntermediate::send(std::string buffer)
{
    throw std::runtime_error("Not implemented yet");
}

void Full::start()
{
    throw std::runtime_error("Not implemented yet");
}

std::string Full::recv()
{
    throw std::runtime_error("Not implemented yet");
    return 0;
}

void Full::send(std::string buffer)
{
    throw std::runtime_error("Not implemented yet");
}
