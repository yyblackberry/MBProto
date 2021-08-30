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
#include "transports/Transport.h"
#include "utils/packing.h"

namespace TCP
{
    class Abridged : public Transport
    {
    public:
        Abridged(datacenter_t dc_id = DC4, const int port = 80, const bool use_ipv6 = false) : Transport(dc_id, port, use_ipv6){};
        void start();
        std::vector<unsigned char> recv();
        void send(const std::vector<unsigned char> buffer);
        ~Abridged();
    };

    class Intermediate : public Transport
    {
    public:
        Intermediate(datacenter_t dc_id = DC4, const int port = 80, const bool use_ipv6 = false) : Transport(dc_id, port, use_ipv6){};
        void start();
        std::vector<unsigned char> recv();
        void send(const std::vector<unsigned char> buffer);
        ~Intermediate();
    };

    class PaddedIntermediate : public Transport
    {
    public:
        PaddedIntermediate(datacenter_t dc_id = DC4, const int port = 80, const bool use_ipv6 = false) : Transport(dc_id, port, use_ipv6){};
        void start();
        std::vector<unsigned char> recv();
        void send(const std::vector<unsigned char> buffer);
        ~PaddedIntermediate();
    };

    class Full : public Transport
    {
    public:
        Full(datacenter_t dc_id = DC4, const int port = 80, const bool use_ipv6 = false) : Transport(dc_id, port, use_ipv6){};
        void start();
        std::vector<unsigned char> recv();
        void send(const std::vector<unsigned char> buffer);
        ~Full();
    };
} // namespace TCP
