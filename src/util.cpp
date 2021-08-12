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

#include "util.h"

uint128_t::operator uint64_t() const
{
	return __low;
}

uint128_t uint128_t::operator&(const uint128_t &rhs) const
{
	return uint128_t(__high & rhs.__high, __low & rhs.__low);
}

uint128_t &uint128_t::operator&=(const uint128_t &rhs)
{
	__high &= rhs.__high;
	__low &= rhs.__low;
	return *this;
}

uint128_t uint128_t::operator<<(const uint128_t &rhs) const
{
	uint64_t shift = rhs & 127;

	if (shift != 0)
	{
		if (shift > 64)
			return uint128_t(__low << (shift - 64), 0);
		else if (shift < 64)
			return uint128_t((__high << shift) | (__low >> (64 - shift)), __low << shift);
		else
			return uint128_t(__low, 0);
	}
	return uint128_t(__high, __low);
}

uint128_t &uint128_t::operator<<=(const uint128_t &rhs)
{
	*this = *this << rhs;
	return *this;
}

uint128_t uint128_t::operator>>(const uint128_t &rhs) const
{
	uint64_t shift = rhs & 127;

	if (shift != 0)
	{
		if (shift > 64)
			return uint128_t(__high >> (shift - 64), 0);
		else if (shift < 64)
			return uint128_t(__high >> shift, (__low >> shift) | (__high << (64 - shift)));
		else
			return uint128_t(0, __high);
	}
	return uint128_t(__high, __low);
}

uint128_t &uint128_t::operator>>=(const uint128_t &rhs)
{
	*this = *this >> rhs;
	return *this;
}

uint128_t uint128_t::operator+(const uint128_t &rhs) const
{
	return uint128_t(__high + rhs.__high + ((__low + rhs.__low) < __low), __low + rhs.__low);
}

uint128_t &uint128_t::operator+=(const uint128_t &rhs)
{
	__high += rhs.__high + ((__low + rhs.__low) < __low);
	__low += rhs.__low;
	return *this;
}

uint256_t::operator uint64_t() const
{
	return (uint64_t)__low;
}

uint256_t uint256_t::operator&(const uint256_t &rhs) const
{
	return uint256_t(__high & rhs.__high, __low & rhs.__low);
}

uint256_t &uint256_t::operator&=(const uint256_t &rhs)
{
	__high &= rhs.__high;
	__low &= rhs.__low;
	return *this;
}

uint256_t uint256_t::operator<<(const uint256_t &rhs) const
{
	uint64_t shift = rhs & 255;

	if (shift != 0)
	{
		if (shift > 128)
			return uint256_t(__low << (shift - 128), 0);
		else if (shift < 128)
			return uint256_t((__high << shift) | (__low >> (128 - shift)), __low << shift);
		else
			return uint256_t(__low, 0);
	}
	return uint256_t(__high, __low);
}

uint256_t &uint256_t::operator<<=(const uint256_t &rhs)
{
	*this = *this << rhs;
	return *this;
}

uint256_t uint256_t::operator>>(const uint256_t &rhs) const
{
	uint64_t shift = rhs & 255;

	if (shift != 0)
	{
		if (shift > 128)
			return uint256_t(__high >> (shift - 128), 0);
		else if (shift < 128)
			return uint256_t(__high >> shift, (__low >> shift) | (__high << (128 - shift)));
		else
			return uint256_t(0, __high);
	}
	return uint256_t(__high, __low);
}

uint256_t &uint256_t::operator>>=(const uint256_t &rhs)
{
	*this = *this >> rhs;
	return *this;
}

uint256_t uint256_t::operator+(const uint256_t &rhs) const
{
	return uint256_t(__high + rhs.__high + ((__low + rhs.__low) < __low), __low + rhs.__low);
}

uint256_t &uint256_t::operator+=(const uint256_t &rhs)
{
	__high += rhs.__high + ((__low + rhs.__low) < __low);
	__low += rhs.__low;
	return *this;
}

Reader::Reader(std::string buffer) : __buffer(buffer) {}

std::string Reader::read(size_t length)
{
	std::string chunk = __buffer.substr(0, length);
	__buffer.erase(0, length);
	return chunk;
}

unsigned int unpackInt(std::string buffer, std::string byteorder)
{
	int n = 0;
	size_t length = buffer.length();

	for (size_t i = 0; i < length; i++)
		n += (buffer[byteorder == "little" ? i : length - i - 1] & 0xFF) << (i * 8);
	return n;
}

std::string packInt(int n, size_t length, std::string byteorder)
{
	std::string buffer;

	for (size_t i = 0; i < length; i++)
		buffer[byteorder == "little" ? i : length - i - 1] = (n >> (i * 8)) & 0xFF;
	return buffer;
}

uint128_t unpackInt128(std::string buffer, std::string byteorder)
{
	long n = 0;

	for (size_t i = 0; i < 16; i++)
		n += (buffer[byteorder == "little" ? i : 15 - i] & 0xFF) << (i * 8);
	return n;
}

std::string packInt128(uint128_t n, std::string byteorder)
{
	std::string buffer;

	for (size_t i = 0; i < 16; i++)
		buffer[byteorder == "little" ? i : 15 - i] = (n >> (i * 8)) & 0xFF;
	return buffer;
}

uint256_t unpackInt256(std::string buffer, std::string byteorder)
{
	long n = 0;

	for (size_t i = 0; i < 32; i++)
		n += (buffer[byteorder == "little" ? i : 31 - i] & 0xFF) << (i * 8);
	return n;
}

std::string packInt256(uint256_t n, std::string byteorder)
{
	std::string buffer;

	for (size_t i = 0; i < 32; i++)
		buffer[byteorder == "little" ? i : 31 - i] = (n >> (i * 8)) & 0xFF;
	return buffer;
}

unsigned long unpackLong(std::string buffer, std::string byteorder)
{
	long n = 0;

	for (size_t i = 0; i < 8; i++)
		n += (buffer[byteorder == "little" ? i : 7 - i] & 0xFF) << (i * 8);
	return n;
}

std::string packLong(unsigned long n, std::string byteorder)
{
	std::string buffer;

	for (size_t i = 0; i < 8; i++)
		buffer[byteorder == "little" ? i : 7 - i] = (n >> (i * 8)) & 0xFF;
	return buffer;
}
