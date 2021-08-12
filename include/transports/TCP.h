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
#include "transports/Transport.h"
#include "util.h"

class Abridged : public Transport
{
public:
    Abridged() = default;
    void start() override;
    std::string recv() override;
    void send(std::string buffer) override;
};

class Intermediate : public Transport
{
public:
    Intermediate() = default;
    void start() override;
    std::string recv() override;
    void send(std::string buffer) override;
};

class PaddedIntermediate : public Transport
{
public:
    PaddedIntermediate() = default;
    void start() override;
    std::string recv() override;
    void send(std::string buffer) override;
};

class Full : public Transport
{
public:
    Full() = default;
    void start() override;
    std::string recv() override;
    void send(std::string buffer) override;
};
