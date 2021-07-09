#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class UpdateProfilePhoto
{
private:
    int __id = 0x72d4742c;

public:
    TLObject id;
    UpdateProfilePhoto(TLObject id_);
    static UpdateProfilePhoto<X> read(Reader reader);
    std::string write();
};

template <class X>
class UploadProfilePhoto
{
private:
    int __id = 0x89f30f69;

public:
    std::optional<TLObject> file;
    std::optional<TLObject> video;
    std::optional<double> video_start_ts;
    UploadProfilePhoto(std::optional<TLObject> file_ = std::nullopt, std::optional<TLObject> video_ = std::nullopt, std::optional<double> video_start_ts_ = std::nullopt);
    static UploadProfilePhoto<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeletePhotos
{
private:
    int __id = 0x87cf7f2f;

public:
    std::vector<TLObject> id;
    DeletePhotos(std::vector<TLObject> id_);
    static DeletePhotos<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetUserPhotos
{
private:
    int __id = 0x91cd32a8;

public:
    TLObject user_id;
    int offset;
    long max_id;
    int limit;
    GetUserPhotos(TLObject user_id_, int offset_, long max_id_, int limit_);
    static GetUserPhotos<X> read(Reader reader);
    std::string write();
};
