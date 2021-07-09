#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class Photos
{
private:
    int __id = 0x8dca6aa5;

public:
    std::vector<TLObject> photos;
    std::vector<TLObject> users;
    Photos(std::vector<TLObject> photos_, std::vector<TLObject> users_);
    static Photos read(Reader reader);
    std::string write();
};

class PhotosSlice
{
private:
    int __id = 0x15051f54;

public:
    int count;
    std::vector<TLObject> photos;
    std::vector<TLObject> users;
    PhotosSlice(int count_, std::vector<TLObject> photos_, std::vector<TLObject> users_);
    static PhotosSlice read(Reader reader);
    std::string write();
};

class Photo
{
private:
    int __id = 0x20212ca8;

public:
    TLObject photo;
    std::vector<TLObject> users;
    Photo(TLObject photo_, std::vector<TLObject> users_);
    static Photo read(Reader reader);
    std::string write();
};
