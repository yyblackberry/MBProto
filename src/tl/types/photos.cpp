#include "tl/types/photos.h"

Photos::Photos(std::vector<TLObject> photos_, std::vector<TLObject> users_) {}

Photos Photos::read(Reader reader)
{
    std::vector<TLObject> photos_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return Photos(photos_, users_);
}

std::string Photos::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(photos);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

PhotosSlice::PhotosSlice(int count_, std::vector<TLObject> photos_, std::vector<TLObject> users_) {}

PhotosSlice PhotosSlice::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> photos_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return PhotosSlice(count_, photos_, users_);
}

std::string PhotosSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(photos);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

Photo::Photo(TLObject photo_, std::vector<TLObject> users_) {}

Photo Photo::read(Reader reader)
{
    TLObject photo_ = TLObject::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return Photo(photo_, users_);
}

std::string Photo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += photo.write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
