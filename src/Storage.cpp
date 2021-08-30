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

#include "Storage.h"

Storage::Storage(std::string storage_name)
{
    if (storage_name.size() < 9 || !storage_name.compare(storage_name.size() - 8, 8, ".session"))
        storage_name += ".session";
    __storage_name = storage_name;
}

void Storage::start()
{
    if (__is_started)
        throw std::runtime_error("The storage has already been started");

    if (sqlite3_open(__storage_name.c_str(), &__db) != SQLITE_OK)
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
