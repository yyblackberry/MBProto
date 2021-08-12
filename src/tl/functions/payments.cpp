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

#include "tl/functions/payments.h"

GetPaymentForm::GetPaymentForm(TLObject peer_, int msg_id_, std::optional<TLObject> theme_params_) {}

GetPaymentForm GetPaymentForm::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    std::optional<TLObject> theme_params_;
    theme_params_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return GetPaymentForm(peer_, msg_id_, theme_params_);
}

std::string GetPaymentForm::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= theme_params ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Int::write(msg_id);

    if (theme_params)
        buffer += theme_params.value().write();
    return buffer;
}

GetPaymentReceipt::GetPaymentReceipt(TLObject peer_, int msg_id_) {}

GetPaymentReceipt GetPaymentReceipt::read(Reader reader)
{
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    return GetPaymentReceipt(peer_, msg_id_);
}

std::string GetPaymentReceipt::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

ValidateRequestedInfo::ValidateRequestedInfo(TLObject peer_, int msg_id_, TLObject info_, std::optional<bool> save_) {}

ValidateRequestedInfo ValidateRequestedInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> save_;
    save_ = (1 << 0) ? std::optional{true} : std::nullopt;
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    TLObject info_ = std::get<TLObject>(TLObject::read(reader));
    return ValidateRequestedInfo(peer_, msg_id_, info_, save_);
}

std::string ValidateRequestedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= save ? 1 << 0 : 0;
    buffer += peer.write();
    buffer += Int::write(msg_id);
    buffer += info.write();
    return buffer;
}

SendPaymentForm::SendPaymentForm(long form_id_, TLObject peer_, int msg_id_, TLObject credentials_, std::optional<std::string> requested_info_id_, std::optional<std::string> shipping_option_id_, std::optional<long> tip_amount_) {}

SendPaymentForm SendPaymentForm::read(Reader reader)
{
    int flags = Int::read(reader);
    long form_id_ = Long::read(reader);
    TLObject peer_ = std::get<TLObject>(TLObject::read(reader));
    int msg_id_ = Int::read(reader);
    std::optional<std::string> requested_info_id_;
    requested_info_id_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::string> shipping_option_id_;
    shipping_option_id_ = (1 << 1) ? std::optional{String::read(reader)} : std::nullopt;
    TLObject credentials_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<long> tip_amount_;
    tip_amount_ = (1 << 2) ? std::optional{Long::read(reader)} : std::nullopt;
    return SendPaymentForm(form_id_, peer_, msg_id_, credentials_, requested_info_id_, shipping_option_id_, tip_amount_);
}

std::string SendPaymentForm::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= requested_info_id ? 1 << 0 : 0;
    flags |= shipping_option_id ? 1 << 1 : 0;
    flags |= tip_amount ? 1 << 2 : 0;
    buffer += Long::write(form_id);
    buffer += peer.write();
    buffer += Int::write(msg_id);

    if (requested_info_id)
        buffer += String::write(requested_info_id.value());

    if (shipping_option_id)
        buffer += String::write(shipping_option_id.value());
    buffer += credentials.write();

    if (tip_amount)
        buffer += Long::write(tip_amount.value());
    return buffer;
}
GetSavedInfo GetSavedInfo::read(Reader reader)
{
    return GetSavedInfo();
}

std::string GetSavedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ClearSavedInfo::ClearSavedInfo(std::optional<bool> credentials_, std::optional<bool> info_) {}

ClearSavedInfo ClearSavedInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> credentials_;
    credentials_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> info_;
    info_ = (1 << 1) ? std::optional{true} : std::nullopt;
    return ClearSavedInfo(credentials_, info_);
}

std::string ClearSavedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= credentials ? 1 << 0 : 0;
    flags |= info ? 1 << 1 : 0;
    return buffer;
}

GetBankCardData::GetBankCardData(std::string number_) {}

GetBankCardData GetBankCardData::read(Reader reader)
{
    std::string number_ = String::read(reader);
    return GetBankCardData(number_);
}

std::string GetBankCardData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(number);
    return buffer;
}
