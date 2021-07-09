#include "tl/functions/photos.h"

template <class X>
UpdateProfilePhoto<X>::UpdateProfilePhoto(TLObject id_) {}

template <class X>
UpdateProfilePhoto<X> UpdateProfilePhoto<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return UpdateProfilePhoto<X>(id_);
}

template <class X>
std::string UpdateProfilePhoto<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
UploadProfilePhoto<X>::UploadProfilePhoto(std::optional<TLObject> file_, std::optional<TLObject> video_, std::optional<double> video_start_ts_) {}

template <class X>
UploadProfilePhoto<X> UploadProfilePhoto<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<TLObject> file_;

    if (1 << 0)
        file_ = TLObject::read(reader);
    else
        file_ = std::nullopt;
    std::optional<TLObject> video_;

    if (1 << 1)
        video_ = TLObject::read(reader);
    else
        video_ = std::nullopt;
    std::optional<double> video_start_ts_;

    if (1 << 2)
        video_start_ts_ = Double::read(reader);
    else
        video_start_ts_ = std::nullopt;
    return UploadProfilePhoto<X>(file_, video_, video_start_ts_);
}

template <class X>
std::string UploadProfilePhoto<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= file ? 1 << 0 : 0;
    flags |= video ? 1 << 1 : 0;
    flags |= video_start_ts ? 1 << 2 : 0;

    if (file)
        buffer += file.value().write();

    if (video)
        buffer += video.value().write();

    if (video_start_ts)
        buffer += Double::write(video_start_ts.value());
    return buffer;
}

template <class X>
DeletePhotos<X>::DeletePhotos(std::vector<TLObject> id_) {}

template <class X>
DeletePhotos<X> DeletePhotos<X>::read(Reader reader)
{
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return DeletePhotos<X>(id_);
}

template <class X>
std::string DeletePhotos<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
GetUserPhotos<X>::GetUserPhotos(TLObject user_id_, int offset_, long max_id_, int limit_) {}

template <class X>
GetUserPhotos<X> GetUserPhotos<X>::read(Reader reader)
{
    TLObject user_id_ = TLObject::read(reader);
    int offset_ = Int::read(reader);
    long max_id_ = Long::read(reader);
    int limit_ = Int::read(reader);
    return GetUserPhotos<X>(user_id_, offset_, max_id_, limit_);
}

template <class X>
std::string GetUserPhotos<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += user_id.write();
    buffer += Int::write(offset);
    buffer += Long::write(max_id);
    buffer += Int::write(limit);
    return buffer;
}
