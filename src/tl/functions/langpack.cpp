#include "tl/functions/langpack.h"

template <class X>
GetLangPack<X>::GetLangPack(std::string lang_pack_, std::string lang_code_) {}

template <class X>
GetLangPack<X> GetLangPack<X>::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    return GetLangPack<X>(lang_pack_, lang_code_);
}

template <class X>
std::string GetLangPack<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    return buffer;
}

template <class X>
GetStrings<X>::GetStrings(std::string lang_pack_, std::string lang_code_, std::vector<std::string> keys_) {}

template <class X>
GetStrings<X> GetStrings<X>::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    std::vector<std::string> keys_ = Vector<std::string>::read(reader);
    return GetStrings<X>(lang_pack_, lang_code_, keys_);
}

template <class X>
std::string GetStrings<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    buffer += Vector<std::string>::write(keys);
    return buffer;
}

template <class X>
GetDifference<X>::GetDifference(std::string lang_pack_, std::string lang_code_, int from_version_) {}

template <class X>
GetDifference<X> GetDifference<X>::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    int from_version_ = Int::read(reader);
    return GetDifference<X>(lang_pack_, lang_code_, from_version_);
}

template <class X>
std::string GetDifference<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    buffer += Int::write(from_version);
    return buffer;
}

template <class X>
GetLanguages<X>::GetLanguages(std::string lang_pack_) {}

template <class X>
GetLanguages<X> GetLanguages<X>::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    return GetLanguages<X>(lang_pack_);
}

template <class X>
std::string GetLanguages<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    return buffer;
}

template <class X>
GetLanguage<X>::GetLanguage(std::string lang_pack_, std::string lang_code_) {}

template <class X>
GetLanguage<X> GetLanguage<X>::read(Reader reader)
{
    std::string lang_pack_ = String::read(reader);
    std::string lang_code_ = String::read(reader);
    return GetLanguage<X>(lang_pack_, lang_code_);
}

template <class X>
std::string GetLanguage<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(lang_pack);
    buffer += String::write(lang_code);
    return buffer;
}
