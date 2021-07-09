#include "tl/functions/stickers.h"

template <class X>
CreateStickerSet<X>::CreateStickerSet(TLObject user_id_, std::string title_, std::string short_name_, std::vector<TLObject> stickers_, std::optional<bool> masks_, std::optional<bool> animated_, std::optional<TLObject> thumb_, std::optional<std::string> software_) {}

template <class X>
CreateStickerSet<X> CreateStickerSet<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;

    if (1 << 0)
        masks_ = true;
    else
        masks_ = std::nullopt;
    std::optional<bool> animated_;

    if (1 << 1)
        animated_ = true;
    else
        animated_ = std::nullopt;
    TLObject user_id_ = TLObject::read(reader);
    std::string title_ = String::read(reader);
    std::string short_name_ = String::read(reader);
    std::optional<TLObject> thumb_;

    if (1 << 2)
        thumb_ = TLObject::read(reader);
    else
        thumb_ = std::nullopt;
    std::vector<TLObject> stickers_ = Vector<TLObject>::read(reader);
    std::optional<std::string> software_;

    if (1 << 3)
        software_ = String::read(reader);
    else
        software_ = std::nullopt;
    return CreateStickerSet<X>(user_id_, title_, short_name_, stickers_, masks_, animated_, thumb_, software_);
}

template <class X>
std::string CreateStickerSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= masks ? 1 << 0 : 0;
    flags |= animated ? 1 << 1 : 0;
    flags |= thumb ? 1 << 2 : 0;
    flags |= software ? 1 << 3 : 0;
    buffer += user_id.write();
    buffer += String::write(title);
    buffer += String::write(short_name);

    if (thumb)
        buffer += thumb.value().write();
    buffer += Vector<TLObject>::write(stickers);

    if (software)
        buffer += String::write(software.value());
    return buffer;
}

template <class X>
RemoveStickerFromSet<X>::RemoveStickerFromSet(TLObject sticker_) {}

template <class X>
RemoveStickerFromSet<X> RemoveStickerFromSet<X>::read(Reader reader)
{
    TLObject sticker_ = TLObject::read(reader);
    return RemoveStickerFromSet<X>(sticker_);
}

template <class X>
std::string RemoveStickerFromSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += sticker.write();
    return buffer;
}

template <class X>
ChangeStickerPosition<X>::ChangeStickerPosition(TLObject sticker_, int position_) {}

template <class X>
ChangeStickerPosition<X> ChangeStickerPosition<X>::read(Reader reader)
{
    TLObject sticker_ = TLObject::read(reader);
    int position_ = Int::read(reader);
    return ChangeStickerPosition<X>(sticker_, position_);
}

template <class X>
std::string ChangeStickerPosition<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += sticker.write();
    buffer += Int::write(position);
    return buffer;
}

template <class X>
AddStickerToSet<X>::AddStickerToSet(TLObject stickerset_, TLObject sticker_) {}

template <class X>
AddStickerToSet<X> AddStickerToSet<X>::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    TLObject sticker_ = TLObject::read(reader);
    return AddStickerToSet<X>(stickerset_, sticker_);
}

template <class X>
std::string AddStickerToSet<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += sticker.write();
    return buffer;
}

template <class X>
SetStickerSetThumb<X>::SetStickerSetThumb(TLObject stickerset_, TLObject thumb_) {}

template <class X>
SetStickerSetThumb<X> SetStickerSetThumb<X>::read(Reader reader)
{
    TLObject stickerset_ = TLObject::read(reader);
    TLObject thumb_ = TLObject::read(reader);
    return SetStickerSetThumb<X>(stickerset_, thumb_);
}

template <class X>
std::string SetStickerSetThumb<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += thumb.write();
    return buffer;
}

template <class X>
CheckShortName<X>::CheckShortName(std::string short_name_) {}

template <class X>
CheckShortName<X> CheckShortName<X>::read(Reader reader)
{
    std::string short_name_ = String::read(reader);
    return CheckShortName<X>(short_name_);
}

template <class X>
std::string CheckShortName<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(short_name);
    return buffer;
}

template <class X>
SuggestShortName<X>::SuggestShortName(std::string title_) {}

template <class X>
SuggestShortName<X> SuggestShortName<X>::read(Reader reader)
{
    std::string title_ = String::read(reader);
    return SuggestShortName<X>(title_);
}

template <class X>
std::string SuggestShortName<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    return buffer;
}
