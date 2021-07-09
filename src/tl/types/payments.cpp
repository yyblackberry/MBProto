#include "tl/types/payments.h"

PaymentForm::PaymentForm(long form_id_, int bot_id_, TLObject invoice_, int provider_id_, std::string url_, std::vector<TLObject> users_, std::optional<bool> can_save_credentials_, std::optional<bool> password_missing_, std::optional<std::string> native_provider_, std::optional<TLObject> native_params_, std::optional<TLObject> saved_info_, std::optional<TLObject> saved_credentials_) {}

PaymentForm PaymentForm::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> can_save_credentials_;

    if (1 << 2)
        can_save_credentials_ = true;
    else
        can_save_credentials_ = std::nullopt;
    std::optional<bool> password_missing_;

    if (1 << 3)
        password_missing_ = true;
    else
        password_missing_ = std::nullopt;
    long form_id_ = Long::read(reader);
    int bot_id_ = Int::read(reader);
    TLObject invoice_ = TLObject::read(reader);
    int provider_id_ = Int::read(reader);
    std::string url_ = String::read(reader);
    std::optional<std::string> native_provider_;

    if (1 << 4)
        native_provider_ = String::read(reader);
    else
        native_provider_ = std::nullopt;
    std::optional<TLObject> native_params_;

    if (1 << 4)
        native_params_ = TLObject::read(reader);
    else
        native_params_ = std::nullopt;
    std::optional<TLObject> saved_info_;

    if (1 << 0)
        saved_info_ = TLObject::read(reader);
    else
        saved_info_ = std::nullopt;
    std::optional<TLObject> saved_credentials_;

    if (1 << 1)
        saved_credentials_ = TLObject::read(reader);
    else
        saved_credentials_ = std::nullopt;
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
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

    if (1 << 0)
        id_ = String::read(reader);
    else
        id_ = std::nullopt;
    std::optional<std::vector<TLObject>> shipping_options_;

    if (1 << 1)
        shipping_options_ = Vector<TLObject>::read(reader);
    else
        shipping_options_ = std::nullopt;
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
    TLObject updates_ = TLObject::read(reader);
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

    if (1 << 2)
        photo_ = TLObject::read(reader);
    else
        photo_ = std::nullopt;
    TLObject invoice_ = TLObject::read(reader);
    std::optional<TLObject> info_;

    if (1 << 0)
        info_ = TLObject::read(reader);
    else
        info_ = std::nullopt;
    std::optional<TLObject> shipping_;

    if (1 << 1)
        shipping_ = TLObject::read(reader);
    else
        shipping_ = std::nullopt;
    std::optional<long> tip_amount_;

    if (1 << 3)
        tip_amount_ = Long::read(reader);
    else
        tip_amount_ = std::nullopt;
    std::string currency_ = String::read(reader);
    long total_amount_ = Long::read(reader);
    std::string credentials_title_ = String::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
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

    if (1 << 1)
        has_saved_credentials_ = true;
    else
        has_saved_credentials_ = std::nullopt;
    std::optional<TLObject> saved_info_;

    if (1 << 0)
        saved_info_ = TLObject::read(reader);
    else
        saved_info_ = std::nullopt;
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
    std::vector<TLObject> open_urls_ = Vector<TLObject>::read(reader);
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
