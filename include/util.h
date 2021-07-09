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
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t(const T &rhs) : __low(rhs), __high(0){};
    template <typename T, typename Q, std::enable_if_t<std::is_integral<T>::value && std::is_integral<Q>::value, bool> = true>
    uint128_t(const T &high_rhs, const Q &low_rhs) : __low(low_rhs), __high(high_rhs){};
    operator uint64_t() const;
    uint128_t operator&(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t operator&(const T &rhs) const
    {
        return *this & uint128_t(rhs);
    };
    uint128_t &operator&=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t &operator&=(const T &rhs)
    {
        return *this &= uint128_t(rhs);
    };
    uint128_t operator<<(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t operator<<(const T &rhs) const
    {
        return *this << uint128_t(rhs);
    };
    uint128_t &operator<<=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t &operator<<=(const T &rhs)
    {

        return *this <<= uint128_t(rhs);
    };
    uint128_t operator>>(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t operator>>(const T &rhs) const
    {
        return *this >> uint128_t(rhs);
    };
    uint128_t &operator>>=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t &operator>>=(const T &rhs)
    {

        return *this >>= uint128_t(rhs);
    };
    uint128_t operator+(const uint128_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    uint128_t operator+(const T &rhs) const
    {
        return *this + uint128_t(rhs);
    };
    uint128_t &operator+=(const uint128_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
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
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t(const T &rhs) : __low(rhs), __high(0){};
    template <typename T, typename Q, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value && std::is_integral<Q>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t(const T &high_rhs, const Q &low_rhs) : __low(low_rhs), __high(high_rhs){};
    operator uint64_t() const;
    uint256_t operator&(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator&(const T &rhs) const
    {
        return *this & uint256_t(rhs);
    };
    uint256_t &operator&=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator&=(const T &rhs)
    {
        return *this &= uint256_t(rhs);
    };
    uint256_t operator<<(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator<<(const T &rhs) const
    {
        return *this << uint256_t(rhs);
    };
    uint256_t &operator<<=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator<<=(const T &rhs)
    {

        return *this <<= uint256_t(rhs);
    };
    uint256_t operator>>(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator>>(const T &rhs) const
    {
        return *this >> uint256_t(rhs);
    };
    uint256_t &operator>>=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t &operator>>=(const T &rhs)
    {

        return *this >>= uint256_t(rhs);
    };
    uint256_t operator+(const uint256_t &rhs) const;
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
    uint256_t operator+(const T &rhs) const
    {
        return *this + uint256_t(rhs);
    };
    uint256_t &operator+=(const uint256_t &rhs);
    template <typename T, std::enable_if_t<std::is_integral<T>::value || std::is_same<T, uint128_t>::value, bool> = true>
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
