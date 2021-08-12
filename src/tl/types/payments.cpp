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

#include "tl/types/payments.h"

PaymentForm::PaymentForm(long form_id_, int bot_id_, TLObject invoice_, int provider_id_, std::string url_, std::vector<TLObject> users_, std::optional<bool> can_save_credentials_, std::optional<bool> password_missing_, std::optional<std::string> native_provider_, std::optional<TLObject> native_params_, std::optional<TLObject> saved_info_, std::optional<TLObject> saved_credentials_) {}

PaymentForm PaymentForm::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_save_credentials_;
    can_save_credentials_ = (1 << 2) ? std::optional{true} : std::nullopt;
    std::optional<bool> password_missing_;
    password_missing_ = (1 << 3) ? std::optional{true} : std::nullopt;
    long form_id_ = Long::read(reader);
    int bot_id_ = Int::read(reader);
    TLObject invoice_ = std::get<TLObject>(TLObject::read(reader));
    int provider_id_ = Int::read(reader);
    std::string url_ = String::read(reader);
    std::optional<std::string> native_provider_;
    native_provider_ = (1 << 4) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<TLObject> native_params_;
    native_params_ = (1 << 4) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> saved_info_;
    saved_info_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> saved_credentials_;
    saved_credentials_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PaymentForm(form_id_, bot_id_, invoice_, provider_id_, url_, users_, can_save_credentials_, password_missing_, native_provider_, native_params_, saved_info_, saved_credentials_);
}

std::string PaymentForm::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= can_save_credentials ? 1 << 2 : 0;
    flags |= password_missing ? 1 << 3 : 0;
    flags |= native_provider ? 1 << 4 : 0;
    flags |= native_params ? 1 << 4 : 0;
    flags |= saved_info ? 1 << 0 : 0;
    flags |= saved_credentials ? 1 << 1 : 0;
    buffer += Long::write(form_id);
    buffer += Int::write(bot_id);
    buffer += invoice.write();
    buffer += Int::write(provider_id);
    buffer += String::write(url);

    if (native_provider)
        buffer += String::write(native_provider.value());

    if (native_params)
        buffer += native_params.value().write();

    if (saved_info)
        buffer += saved_info.value().write();

    if (saved_credentials)
        buffer += saved_credentials.value().write();
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ValidatedRequestedInfo::ValidatedRequestedInfo(std::optional<std::string> id_, std::optional<std::vector<TLObject>> shipping_options_) {}

ValidatedRequestedInfo ValidatedRequestedInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<std::string> id_;
    id_ = (1 << 0) ? std::optional{String::read(reader)} : std::nullopt;
    std::optional<std::vector<TLObject>> shipping_options_;
    shipping_options_ = (1 << 1) ? std::optional{std::get<std::vector<TLObject>>(TLObject::read(reader))} : std::nullopt;
    return ValidatedRequestedInfo(id_, shipping_options_);
}

std::string ValidatedRequestedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= id ? 1 << 0 : 0;
    flags |= shipping_options ? 1 << 1 : 0;

    if (id)
        buffer += String::write(id.value());

    if (shipping_options)
        buffer += Vector<TLObject>::write(shipping_options.value());
    return buffer;
}

PaymentResult::PaymentResult(TLObject updates_) {}

PaymentResult PaymentResult::read(Reader reader)
{
    TLObject updates_ = std::get<TLObject>(TLObject::read(reader));
    return PaymentResult(updates_);
}

std::string PaymentResult::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += updates.write();
    return buffer;
}

PaymentVerificationNeeded::PaymentVerificationNeeded(std::string url_) {}

PaymentVerificationNeeded PaymentVerificationNeeded::read(Reader reader)
{
    std::string url_ = String::read(reader);
    return PaymentVerificationNeeded(url_);
}

std::string PaymentVerificationNeeded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(url);
    return buffer;
}

PaymentReceipt::PaymentReceipt(int date_, int bot_id_, int provider_id_, std::string title_, std::string description_, TLObject invoice_, std::string currency_, long total_amount_, std::string credentials_title_, std::vector<TLObject> users_, std::optional<TLObject> photo_, std::optional<TLObject> info_, std::optional<TLObject> shipping_, std::optional<long> tip_amount_) {}

PaymentReceipt PaymentReceipt::read(Reader reader)
{
    int flags = Int::read(reader);
    int date_ = Int::read(reader);
    int bot_id_ = Int::read(reader);
    int provider_id_ = Int::read(reader);
    std::string title_ = String::read(reader);
    std::string description_ = String::read(reader);
    std::optional<TLObject> photo_;
    photo_ = (1 << 2) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    TLObject invoice_ = std::get<TLObject>(TLObject::read(reader));
    std::optional<TLObject> info_;
    info_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<TLObject> shipping_;
    shipping_ = (1 << 1) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    std::optional<long> tip_amount_;
    tip_amount_ = (1 << 3) ? std::optional{Long::read(reader)} : std::nullopt;
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    std::string credentials_title_ = String::read(reader);
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return PaymentReceipt(date_, bot_id_, provider_id_, title_, description_, invoice_, currency_, total_amount_, credentials_title_, users_, photo_, info_, shipping_, tip_amount_);
}

std::string PaymentReceipt::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= photo ? 1 << 2 : 0;
    flags |= info ? 1 << 0 : 0;
    flags |= shipping ? 1 << 1 : 0;
    flags |= tip_amount ? 1 << 3 : 0;
    buffer += Int::write(date);
    buffer += Int::write(bot_id);
    buffer += Int::write(provider_id);
    buffer += String::write(title);
    buffer += String::write(description);

    if (photo)
        buffer += photo.value().write();
    buffer += invoice.write();

    if (info)
        buffer += info.value().write();

    if (shipping)
        buffer += shipping.value().write();

    if (tip_amount)
        buffer += Long::write(tip_amount.value());
    buffer += String::write(currency);
    buffer += Long::write(total_amount);
    buffer += String::write(credentials_title);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

SavedInfo::SavedInfo(std::optional<bool> has_saved_credentials_, std::optional<TLObject> saved_info_) {}

SavedInfo SavedInfo::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> has_saved_credentials_;
    has_saved_credentials_ = (1 << 1) ? std::optional{true} : std::nullopt;
    std::optional<TLObject> saved_info_;
    saved_info_ = (1 << 0) ? std::optional{std::get<TLObject>(TLObject::read(reader))} : std::nullopt;
    return SavedInfo(has_saved_credentials_, saved_info_);
}

std::string SavedInfo::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= has_saved_credentials ? 1 << 1 : 0;
    flags |= saved_info ? 1 << 0 : 0;

    if (saved_info)
        buffer += saved_info.value().write();
    return buffer;
}

BankCardData::BankCardData(std::string title_, std::vector<TLObject> open_urls_) {}

BankCardData BankCardData::read(Reader reader)
{
    std::string title_ = String::read(reader);
    std::vector<TLObject> open_urls_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return BankCardData(title_, open_urls_);
}

std::string BankCardData::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(title);
    buffer += Vector<TLObject>::write(open_urls);
    return buffer;
}
