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

#include "Connection.h"

#ifdef _WIN32
int inet_pton(int af, const char *src, void *dst)
{
    struct sockaddr_storage ss;
    int size = sizeof(ss);
    char src_copy[INET6_ADDRSTRLEN + 1];
    ZeroMemory(&ss, sizeof(ss));
    strncpy(src_copy, src, INET6_ADDRSTRLEN + 1);
    src_copy[INET6_ADDRSTRLEN] = 0;

    if (WSAStringToAddress((LPWSTR)src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0)
        switch (af)
        {
        case AF_INET:
            *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
            return 1;
        case AF_INET6:
            *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
            return 1;
        }
    return 0;
}
#endif

Connection::Connection(datacenter_t dc_id, const int port, const bool use_ipv6)
{
    const char *address = __datacenters[dc_id][use_ipv6 ? 1 : 0];
    __server_address.sin_family = use_ipv6 ? AF_INET6 : AF_INET;
    __sockfd = socket(__server_address.sin_family, SOCK_STREAM, 0);

    if (__sockfd == -1)
        throw std::runtime_error("Can't initialize the connection: " + std::string(strerror(errno)));
    __server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, address, &__server_address.sin_addr) <= 0)
        throw std::runtime_error("Invalid address: " + std::string(address));
}

void Connection::start()
{
    if (__is_started)
        throw std::runtime_error("The connection has already been started");

    if (connect(__sockfd, (struct sockaddr *)&__server_address, sizeof(__server_address)) < 0)
        throw std::runtime_error("Can't start the connection: " + std::string(strerror(errno)));
    __is_started = true;
}

std::vector<unsigned char> Connection::recv(const size_t length)
{
    size_t total = 0;
    std::vector<unsigned char> buffer(length);

    do
    {
#ifdef _WIN32
        size_t chunk = ::recv(__sockfd, (char *)&buffer[total], length - total, 0);
#else
        size_t chunk = ::recv(__sockfd, &buffer[total], length - total, 0);
#endif

        if (chunk <= 0)
            throw std::runtime_error(std::strerror(errno));
        total += chunk;
    } while (total < length);
    return buffer;
}

void Connection::send(const std::vector<unsigned char> buffer)
{
#ifdef _WIN32
    if (::send(__sockfd, (char *)&buffer[0], buffer.size(), 0) <= 0)
#else
    if (::send(__sockfd, &buffer[0], buffer.size(), 0) <= 0)
#endif
        throw std::runtime_error(strerror(errno));
}

void Connection::stop()
{
    if (!__is_started)
        throw std::runtime_error("The connection has not been started yet");

#ifdef _WIN32
    if (closesocket(__sockfd) < 0)
        throw std::runtime_error("Can't close the connection: " + std::string(strerror(errno)));
#else
    if (close(__sockfd) < 0)
        throw std::runtime_error("Can't close the connection: " + std::string(strerror(errno)));
#endif
    __is_started = false;
}

Connection::~Connection()
{
    if (__is_started)
        stop();
}
