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

#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class CreateStickerSet : public TLObject
{
private:
    int __id = 0x9021ab67;

public:
    std::optional<bool> masks;
    std::optional<bool> animated;
    TLObject user_id;
    std::string title;
    std::string short_name;
    std::optional<TLObject> thumb;
    std::vector<TLObject> stickers;
    std::optional<std::string> software;
    CreateStickerSet(TLObject user_id_, std::string title_, std::string short_name_, std::vector<TLObject> stickers_, std::optional<bool> masks_ = std::nullopt, std::optional<bool> animated_ = std::nullopt, std::optional<TLObject> thumb_ = std::nullopt, std::optional<std::string> software_ = std::nullopt);
    static CreateStickerSet read(Reader reader);
    std::string write();
};

class RemoveStickerFromSet : public TLObject
{
private:
    int __id = 0xf7760f51;

public:
    TLObject sticker;
    RemoveStickerFromSet(TLObject sticker_);
    static RemoveStickerFromSet read(Reader reader);
    std::string write();
};

class ChangeStickerPosition : public TLObject
{
private:
    int __id = 0xffb6d4ca;

public:
    TLObject sticker;
    int position;
    ChangeStickerPosition(TLObject sticker_, int position_);
    static ChangeStickerPosition read(Reader reader);
    std::string write();
};

class AddStickerToSet : public TLObject
{
private:
    int __id = 0x8653febe;

public:
    TLObject stickerset;
    TLObject sticker;
    AddStickerToSet(TLObject stickerset_, TLObject sticker_);
    static AddStickerToSet read(Reader reader);
    std::string write();
};

class SetStickerSetThumb : public TLObject
{
private:
    int __id = 0x9a364e30;

public:
    TLObject stickerset;
    TLObject thumb;
    SetStickerSetThumb(TLObject stickerset_, TLObject thumb_);
    static SetStickerSetThumb read(Reader reader);
    std::string write();
};

class CheckShortName : public TLObject
{
private:
    int __id = 0x284b3639;

public:
    std::string short_name;
    CheckShortName(std::string short_name_);
    static CheckShortName read(Reader reader);
    std::string write();
};

class SuggestShortName : public TLObject
{
private:
    int __id = 0x4dafc503;

public:
    std::string title;
    SuggestShortName(std::string title_);
    static SuggestShortName read(Reader reader);
    std::string write();
};
