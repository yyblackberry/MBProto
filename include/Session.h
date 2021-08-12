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
#include "Storage.h"
#include "transports/TCP.h"

class Session
{
private:
    Storage __storage;
    Transport &__transport;

public:
    Session(
        std::string storage_name,
        int api_id,
        std::string api_key,
        std::string dc[2] = DC4,
        int port = 80,
        bool use_ipv6 = false,
        Transport transport = Abridged()) : __storage(storage_name), __transport(transport)
    {
        __transport.setConnection(dc, port, use_ipv6);
    };
    void start();
    void stop();
};
