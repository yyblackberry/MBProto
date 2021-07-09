#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class SuggestedShortName
{
private:
    int __id = 0x85fea03f;

public:
    std::string short_name;
    SuggestedShortName(std::string short_name_);
    static SuggestedShortName read(Reader reader);
    std::string write();
};
