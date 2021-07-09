#include "tl/types/stickers.h"

SuggestedShortName::SuggestedShortName(std::string short_name_) {}

SuggestedShortName SuggestedShortName::read(Reader reader)
{
    std::string short_name_ = String::read(reader);
    return SuggestedShortName(short_name_);
}

std::string SuggestedShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(short_name);
    return buffer;
}
