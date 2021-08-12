/* Copyright (C) 2021  Mattia  Lorenzo Chiabrando <https://github.com/mattiabrandon>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "tl/functions/stickers.h"

CreateStickerSet::CreateStickerSet(TLObject user_id_, std::string title_, std::string short_name_, std::vector<TLObject> stickers_, std::optional<bool> masks_, std::optional<bool> animated_, std::optional<TLObject> thumb_, std::optional<std::string> software_) {}

CreateStickerSet CreateStickerSet::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> masks_;
    masks_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> animated_;
    animated_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject user_id_ = std::get<TLObject>(TLObject::read(reader));
    std::string title_ = String::read(reader);
    std::string short_name_ = String::read(reader);
    std::optional<TLObject> thumb_;
    thumb_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::vector<TLObject> stickers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::optional<std::string> software_;
    software_ = (1 << 3) ? std::optional{String::read(reader)} : std::nullopt;
    return CreateStickerSet(user_id_, title_, short_name_, stickers_, masks_, animated_, thumb_, software_);
}

std::string CreateStickerSet::write()
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

RemoveStickerFromSet::RemoveStickerFromSet(TLObject sticker_) {}

RemoveStickerFromSet RemoveStickerFromSet::read(Reader reader)
{
    TLObject sticker_ = std::get<TLObject>(TLObject::read(reader));
    return RemoveStickerFromSet(sticker_);
}

std::string RemoveStickerFromSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += sticker.write();
    return buffer;
}

ChangeStickerPosition::ChangeStickerPosition(TLObject sticker_, int position_) {}

ChangeStickerPosition ChangeStickerPosition::read(Reader reader)
{
    TLObject sticker_ = std::get<TLObject>(TLObject::read(reader));
    int position_ = Int::read(reader);
    return ChangeStickerPosition(sticker_, position_);
}

std::string ChangeStickerPosition::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += sticker.write();
    buffer += Int::write(position);
    return buffer;
}

AddStickerToSet::AddStickerToSet(TLObject stickerset_, TLObject sticker_) {}

AddStickerToSet AddStickerToSet::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    TLObject sticker_ = std::get<TLObject>(TLObject::read(reader));
    return AddStickerToSet(stickerset_, sticker_);
}

std::string AddStickerToSet::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += sticker.write();
    return buffer;
}

SetStickerSetThumb::SetStickerSetThumb(TLObject stickerset_, TLObject thumb_) {}

SetStickerSetThumb SetStickerSetThumb::read(Reader reader)
{
    TLObject stickerset_ = std::get<TLObject>(TLObject::read(reader));
    TLObject thumb_ = std::get<TLObject>(TLObject::read(reader));
    return SetStickerSetThumb(stickerset_, thumb_);
}

std::string SetStickerSetThumb::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += stickerset.write();
    buffer += thumb.write();
    return buffer;
}

CheckShortName::CheckShortName(std::string short_name_) {}

CheckShortName CheckShortName::read(Reader reader)
{
    std::string short_name_ = String::read(reader);
    return CheckShortName(short_name_);
}

std::string CheckShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(short_name);
    return buffer;
}

SuggestShortName::SuggestShortName(std::string title_) {}

SuggestShortName SuggestShortName::read(Reader reader)
{
    std::string title_ = String::read(reader);
    return SuggestShortName(title_);
}

std::string SuggestShortName::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    return buffer;
}
