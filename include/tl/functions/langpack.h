#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class GetLangPack
{
private:
    int __id = 0xf2f2330a;

public:
    std::string lang_pack;
    std::string lang_code;
    GetLangPack(std::string lang_pack_, std::string lang_code_);
    static GetLangPack<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetStrings
{
private:
    int __id = 0xefea3803;

public:
    std::string lang_pack;
    std::string lang_code;
    std::vector<std::string> keys;
    GetStrings(std::string lang_pack_, std::string lang_code_, std::vector<std::string> keys_);
    static GetStrings<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetDifference
{
private:
    int __id = 0xcd984aa5;

public:
    std::string lang_pack;
    std::string lang_code;
    int from_version;
    GetDifference(std::string lang_pack_, std::string lang_code_, int from_version_);
    static GetDifference<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetLanguages
{
private:
    int __id = 0x42c6978f;

public:
    std::string lang_pack;
    GetLanguages(std::string lang_pack_);
    static GetLanguages<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetLanguage
{
private:
    int __id = 0x6a596502;

public:
    std::string lang_pack;
    std::string lang_code;
    GetLanguage(std::string lang_pack_, std::string lang_code_);
    static GetLanguage<X> read(Reader reader);
    std::string write();
};
