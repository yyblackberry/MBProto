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

#include "transports/tcp.h"

namespace TCP
{
    void Abridged::start()
    {
        if (_is_started)
            throw std::runtime_error("The transport has already been started");
        _connection.start();
        _connection.send(std::vector<unsigned char>({(unsigned char)'\xef'}));
        _is_started = true;
    }

    std::vector<unsigned char> Abridged::recv()
    {
        size_t length = unpackInt(_connection.recv(1));

        if (length == 127)
            length = unpackInt(_connection.recv(3));
        return _connection.recv(length * 4);
    }

    void Abridged::send(const std::vector<unsigned char> buffer)
    {
        size_t length = buffer.size() / 4;

        if (length >= 127)
        {
            _connection.send(std::vector<unsigned char>({'\x7f'}));
            _connection.send(packInt(length, 3));
        }
        else
            _connection.send(packInt(length, 1));
        _connection.send(buffer);
    }

    Abridged::~Abridged()
    {
        if (_is_started)
            Transport::stop();
    }

    void Intermediate::start()
    {
        if (_is_started)
            throw std::runtime_error("The transport has already been started");
        _connection.start();
        _connection.send(std::vector<unsigned char>({(unsigned char)'\xee', (unsigned char)'\xee', (unsigned char)'\xee', (unsigned char)'\xee'}));
        _is_started = true;
    }

    std::vector<unsigned char> Intermediate::recv()
    {
        return _connection.recv(unpackInt(_connection.recv(4)));
    }

    void Intermediate::send(const std::vector<unsigned char> buffer)
    {
        _connection.send(packInt(buffer.size(), 4));
        _connection.send(buffer);
    }

    Intermediate::~Intermediate()
    {
        if (_is_started)
            Transport::stop();
    }

    void PaddedIntermediate::start()
    {
        if (_is_started)
            throw std::runtime_error("The transport has already been started");
        throw std::runtime_error("Not implemented yet");
        _is_started = true;
    }

    std::vector<unsigned char> PaddedIntermediate::recv()
    {
        throw std::runtime_error("Not implemented yet");
        return std::vector<unsigned char>();
    }

    void PaddedIntermediate::send(const std::vector<unsigned char> buffer)
    {
        throw std::runtime_error("Not implemented yet");
    }

    PaddedIntermediate::~PaddedIntermediate()
    {
        if (_is_started)
            Transport::stop();
    }

    void Full::start()
    {
        if (_is_started)
            throw std::runtime_error("The transport has already been started");
        throw std::runtime_error("Not implemented yet");
        _is_started = true;
    }

    std::vector<unsigned char> Full::recv()
    {
        throw std::runtime_error("Not implemented yet");
        return std::vector<unsigned char>();
    }

    void Full::send(const std::vector<unsigned char> buffer)
    {
        throw std::runtime_error("Not implemented yet");
    }

    Full::~Full()
    {
        if (_is_started)
            Transport::stop();
    }
} // namespace TCP
