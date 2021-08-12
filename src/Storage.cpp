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

#include "Storage.h"

Storage::Storage(std::string storage_name)
{
    if (storage_name.size() < 9 || storage_name.compare(storage_name.size() - 8, 8, ".session"))
        storage_name += ".session";
    __storage_name = storage_name;
}

void Storage::start()
{
    if (__is_started)
        throw std::runtime_error("The storage has already been started");

    if (sqlite3_open(__storage_name, &__db) != SQLITE_OK)
        throw std::runtime_error("Can't open the database: " + std::string(sqlite3_errmsg(__db)));
    __is_started = true;
}

void Storage::stop()
{
    if (!__is_started)
        throw std::runtime_error("The storage has not been started yet");

    if (sqlite3_close(__db) != SQLITE_OK)
        throw std::runtime_error("Can't close the database: " + std::string(sqlite3_errmsg(__db)));
    __is_started = false;
}

Storage::~Storage()
{
    if (__is_started)
        stop();
}
