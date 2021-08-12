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

class GetPaymentForm : public TLObject
{
private:
    int __id = 0x8a333c8d;

public:
    TLObject peer;
    int msg_id;
    std::optional<TLObject> theme_params;
    GetPaymentForm(TLObject peer_, int msg_id_, std::optional<TLObject> theme_params_ = std::nullopt);
    static GetPaymentForm read(Reader reader);
    std::string write();
};

class GetPaymentReceipt : public TLObject
{
private:
    int __id = 0x2478d1cc;

public:
    TLObject peer;
    int msg_id;
    GetPaymentReceipt(TLObject peer_, int msg_id_);
    static GetPaymentReceipt read(Reader reader);
    std::string write();
};

class ValidateRequestedInfo : public TLObject
{
private:
    int __id = 0xdb103170;

public:
    std::optional<bool> save;
    TLObject peer;
    int msg_id;
    TLObject info;
    ValidateRequestedInfo(TLObject peer_, int msg_id_, TLObject info_, std::optional<bool> save_ = std::nullopt);
    static ValidateRequestedInfo read(Reader reader);
    std::string write();
};

class SendPaymentForm : public TLObject
{
private:
    int __id = 0x30c3bc9d;

public:
    long form_id;
    TLObject peer;
    int msg_id;
    std::optional<std::string> requested_info_id;
    std::optional<std::string> shipping_option_id;
    TLObject credentials;
    std::optional<long> tip_amount;
    SendPaymentForm(long form_id_, TLObject peer_, int msg_id_, TLObject credentials_, std::optional<std::string> requested_info_id_ = std::nullopt, std::optional<std::string> shipping_option_id_ = std::nullopt, std::optional<long> tip_amount_ = std::nullopt);
    static SendPaymentForm read(Reader reader);
    std::string write();
};

class GetSavedInfo : public TLObject
{
private:
    int __id = 0x227d824b;

public:
    GetSavedInfo() = default;
    static GetSavedInfo read(Reader reader);
    std::string write();
};

class ClearSavedInfo : public TLObject
{
private:
    int __id = 0xd83d70c1;

public:
    std::optional<bool> credentials;
    std::optional<bool> info;
    ClearSavedInfo(std::optional<bool> credentials_ = std::nullopt, std::optional<bool> info_ = std::nullopt);
    static ClearSavedInfo read(Reader reader);
    std::string write();
};

class GetBankCardData : public TLObject
{
private:
    int __id = 0x2e79d779;

public:
    std::string number;
    GetBankCardData(std::string number_);
    static GetBankCardData read(Reader reader);
    std::string write();
};
