#include "tl/functions/users.h"

template <class X>
GetUsers<X>::GetUsers(std::vector<TLObject> id_) {}

template <class X>
GetUsers<X> GetUsers<X>::read(Reader reader)
{
    std::vector<TLObject> id_ = Vector<TLObject>::read(reader);
    return GetUsers<X>(id_);
}

template <class X>
std::string GetUsers<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(id);
    return buffer;
}

template <class X>
GetFullUser<X>::GetFullUser(TLObject id_) {}

template <class X>
GetFullUser<X> GetFullUser<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    return GetFullUser<X>(id_);
}

template <class X>
std::string GetFullUser<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    return buffer;
}

template <class X>
SetSecureValueErrors<X>::SetSecureValueErrors(TLObject id_, std::vector<TLObject> errors_) {}

template <class X>
SetSecureValueErrors<X> SetSecureValueErrors<X>::read(Reader reader)
{
    TLObject id_ = TLObject::read(reader);
    std::vector<TLObject> errors_ = Vector<TLObject>::read(reader);
    return SetSecureValueErrors<X>(id_, errors_);
}

template <class X>
std::string SetSecureValueErrors<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += id.write();
    buffer += Vector<TLObject>::write(errors);
    return buffer;
}
