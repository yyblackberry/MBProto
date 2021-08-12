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
#include <string>
#include <stdint.h>
#include <type_traits>

class uint128_t
{
private:
    uint64_t __low, __high;

public:
    uint128_t() = default;
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t(const T &rhs) : __low(rhs), __high(0){};
    template <typename T, typename Q, std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<Q>, bool> = true>
    uint128_t(const T &high_rhs, const Q &low_rhs) : __low(low_rhs), __high(high_rhs){};
    operator uint64_t() const;
    uint128_t operator&(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t operator&(const T &rhs) const
    {
        return *this & uint128_t(rhs);
    };
    uint128_t &operator&=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t &operator&=(const T &rhs)
    {
        return *this &= uint128_t(rhs);
    };
    uint128_t operator<<(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t operator<<(const T &rhs) const
    {
        return *this << uint128_t(rhs);
    };
    uint128_t &operator<<=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t &operator<<=(const T &rhs)
    {

        return *this <<= uint128_t(rhs);
    };
    uint128_t operator>>(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t operator>>(const T &rhs) const
    {
        return *this >> uint128_t(rhs);
    };
    uint128_t &operator>>=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t &operator>>=(const T &rhs)
    {

        return *this >>= uint128_t(rhs);
    };
    uint128_t operator+(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t operator+(const T &rhs) const
    {
        return *this + uint128_t(rhs);
    };
    uint128_t &operator+=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    uint128_t &operator+=(const T &rhs)
    {
        return *this += uint128_t(rhs);
    };
};

class uint256_t
{
private:
    uint128_t __low, __high;

public:
    uint256_t() = default;
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t(const T &rhs) : __low(rhs), __high(0){};
    template <typename T, typename Q, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value && std::is_integral_v<Q> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t(const T &high_rhs, const Q &low_rhs) : __low(low_rhs), __high(high_rhs){};
    operator uint64_t() const;
    uint256_t operator&(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator&(const T &rhs) const
    {
        return *this & uint256_t(rhs);
    };
    uint256_t &operator&=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator&=(const T &rhs)
    {
        return *this &= uint256_t(rhs);
    };
    uint256_t operator<<(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator<<(const T &rhs) const
    {
        return *this << uint256_t(rhs);
    };
    uint256_t &operator<<=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator<<=(const T &rhs)
    {

        return *this <<= uint256_t(rhs);
    };
    uint256_t operator>>(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator>>(const T &rhs) const
    {
        return *this >> uint256_t(rhs);
    };
    uint256_t &operator>>=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator>>=(const T &rhs)
    {

        return *this >>= uint256_t(rhs);
    };
    uint256_t operator+(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator+(const T &rhs) const
    {
        return *this + uint256_t(rhs);
    };
    uint256_t &operator+=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral_v<T> || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator+=(const T &rhs)
    {
        return *this += uint256_t(rhs);
    };
};

class Reader
{
private:
    std::string __buffer;

public:
    Reader(std::string buffer);
    std::string read(size_t length);
};

unsigned int unpackInt(std::string buffer, std::string byteorder = "little");
std::string packInt(unsigned int n, size_t length, std::string byteorder = "little");
uint128_t unpackInt128(std::string buffer, std::string byteorder = "little");
std::string packInt128(uint128_t n, std::string byteorder = "little");
uint256_t unpackInt256(std::string buffer, std::string byteorder = "little");
std::string packInt256(uint256_t n, std::string byteorder = "little");
unsigned long unpackLong(std::string buffer, std::string byteorder = "little");
std::string packLong(unsigned long n, std::string byteorder = "little");
