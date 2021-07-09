#pragma once
#include "util.h"

class TLObject
{
public:
    TLObject();
    static TLObject read(Reader reader);
    std::string write();
};
