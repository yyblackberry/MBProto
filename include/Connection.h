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
#include <stdexcept>
#include <string>
#include <cstring>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>

int inet_pton(int af, const char *src, void *dst);
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <vector>

enum datacenter_t
{
    DC1,
    DC2,
    DC3,
    DC4,
    DC5
};

class Connection
{
private:
    const char *__datacenters[5][2] = {
        {"149.154.175.53", "2001:b28:f23d:f001::a"},
        {"149.154.167.51", "2001:67c:4e8:f002::a"},
        {"149.154.175.100", "2001:b28:f23d:f003::a"},
        {"149.154.167.91", "2001:67c:4e8:f004::a"},
        {"91.108.56.130", "2001:b28:f23f:f005::a"},
    };
    bool __is_started = false;
    struct sockaddr_in __server_address;
    int __sockfd;

public:
    Connection(datacenter_t dc_id = DC4, const int port = 80, const bool use_ipv6 = false);
    void start();
    std::vector<unsigned char> recv(size_t length);
    void send(const std::vector<unsigned char> buffer);
    void stop();
    ~Connection();
};
