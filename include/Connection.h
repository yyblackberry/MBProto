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

#pragma once
#include <stdexcept>
#include <string>
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

extern std::string DC1[2];
extern std::string DC2[2];
extern std::string DC3[2];
extern std::string DC4[2];
extern std::string DC5[2];

class Connection
{
private:
    bool __is_started = false;
    struct sockaddr_in __server_address;
    int __sockfd;

public:
    Connection(std::string dc[2] = DC4, int port = 80, bool use_ipv6 = false);
    void start();
    std::string recv(size_t len);
    void send(std::string buf);
    void stop();
    ~Connection();
};
