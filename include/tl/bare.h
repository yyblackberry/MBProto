#pragma once
#include "util.h"
#include <vector>

class Int
{
public:
    Int() = default;
    static int read(Reader reader, std::string byteorder = "little");
    static std::string write(int value, std::string byteorder = "little");
};

class Int128
{
public:
    Int128() = default;
    static uint128_t read(Reader reader, std::string byteorder = "little");
    static std::string write(uint128_t value, std::string byteorder = "little");
};

class Int256
{
public:
    Int256() = default;
    static uint256_t read(Reader reader, std::string byteorder = "little");
    static std::string write(uint256_t value, std::string byteorder = "little");
};

class Long
{
public:
    Long() = default;
    static unsigned long read(Reader reader, std::string byteorder = "little");
    static std::string write(unsigned long value, std::string byteorder = "little");
};

class Double
{
public:
    Double() = default;
    static double read(Reader reader);
    static std::string write(double value);
};

class Bytes
{
public:
    Bytes() = default;
    static std::string read(Reader reader);
    static std::string write(std::string value);
};

class String : public Bytes
{
public:
    String() = default;
    static std::string read(Reader reader);
    static std::string write(std::string value);
};

class Bool
{
private:
    static const int Bool::__bool_false_id = 0xbc799737;
    static const int Bool::__bool_true_id = 0x997275b5;

public:
    Bool() = default;
    static bool read(Reader reader);
    static std::string write(bool value);
};

template <class T>
class Vector
{
private:
    int __id = 0x1cb5c415;

public:
    Vector() = default;
    static std::vector<T> read(Reader reader);
    static std::string write(std::vector<T> values);
};
