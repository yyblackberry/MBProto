#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class CreateStickerSet
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
    static CreateStickerSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class RemoveStickerFromSet
{
private:
    int __id = 0xf7760f51;

public:
    TLObject sticker;
    RemoveStickerFromSet(TLObject sticker_);
    static RemoveStickerFromSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class ChangeStickerPosition
{
private:
    int __id = 0xffb6d4ca;

public:
    TLObject sticker;
    int position;
    ChangeStickerPosition(TLObject sticker_, int position_);
    static ChangeStickerPosition<X> read(Reader reader);
    std::string write();
};

template <class X>
class AddStickerToSet
{
private:
    int __id = 0x8653febe;

public:
    TLObject stickerset;
    TLObject sticker;
    AddStickerToSet(TLObject stickerset_, TLObject sticker_);
    static AddStickerToSet<X> read(Reader reader);
    std::string write();
};

template <class X>
class SetStickerSetThumb
{
private:
    int __id = 0x9a364e30;

public:
    TLObject stickerset;
    TLObject thumb;
    SetStickerSetThumb(TLObject stickerset_, TLObject thumb_);
    static SetStickerSetThumb<X> read(Reader reader);
    std::string write();
};

template <class X>
class CheckShortName
{
private:
    int __id = 0x284b3639;

public:
    std::string short_name;
    CheckShortName(std::string short_name_);
    static CheckShortName<X> read(Reader reader);
    std::string write();
};

template <class X>
class SuggestShortName
{
private:
    int __id = 0x4dafc503;

public:
    std::string title;
    SuggestShortName(std::string title_);
    static SuggestShortName<X> read(Reader reader);
    std::string write();
};
