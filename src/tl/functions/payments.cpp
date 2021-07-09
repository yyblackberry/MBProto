#include "tl/functions/payments.h"

template <class X>
GetPaymentForm<X>::GetPaymentForm(TLObject peer_, int msg_id_, std::optional<TLObject> theme_params_) {}

template <class X>
GetPaymentForm<X> GetPaymentForm<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    std::optional<TLObject> theme_params_;

    if (1 << 0)
        theme_params_ = TLObject::read(reader);
    else
        theme_params_ = std::nullopt;
    return GetPaymentForm<X>(peer_, msg_id_, theme_params_);
}

template <class X>
std::string GetPaymentForm<X>::write()
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

template <class X>
GetPaymentReceipt<X>::GetPaymentReceipt(TLObject peer_, int msg_id_) {}

template <class X>
GetPaymentReceipt<X> GetPaymentReceipt<X>::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    return GetPaymentReceipt<X>(peer_, msg_id_);
}

template <class X>
std::string GetPaymentReceipt<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Int::write(msg_id);
    return buffer;
}

template <class X>
ValidateRequestedInfo<X>::ValidateRequestedInfo(TLObject peer_, int msg_id_, TLObject info_, std::optional<bool> save_) {}

template <class X>
ValidateRequestedInfo<X> ValidateRequestedInfo<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> save_;

    if (1 << 0)
        save_ = true;
    else
        save_ = std::nullopt;
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    TLObject info_ = TLObject::read(reader);
    return ValidateRequestedInfo<X>(peer_, msg_id_, info_, save_);
}

template <class X>
std::string ValidateRequestedInfo<X>::write()
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

template <class X>
SendPaymentForm<X>::SendPaymentForm(long form_id_, TLObject peer_, int msg_id_, TLObject credentials_, std::optional<std::string> requested_info_id_, std::optional<std::string> shipping_option_id_, std::optional<long> tip_amount_) {}

template <class X>
SendPaymentForm<X> SendPaymentForm<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    long form_id_ = Long::read(reader);
    TLObject peer_ = TLObject::read(reader);
    int msg_id_ = Int::read(reader);
    std::optional<std::string> requested_info_id_;

    if (1 << 0)
        requested_info_id_ = String::read(reader);
    else
        requested_info_id_ = std::nullopt;
    std::optional<std::string> shipping_option_id_;

    if (1 << 1)
        shipping_option_id_ = String::read(reader);
    else
        shipping_option_id_ = std::nullopt;
    TLObject credentials_ = TLObject::read(reader);
    std::optional<long> tip_amount_;

    if (1 << 2)
        tip_amount_ = Long::read(reader);
    else
        tip_amount_ = std::nullopt;
    return SendPaymentForm<X>(form_id_, peer_, msg_id_, credentials_, requested_info_id_, shipping_option_id_, tip_amount_);
}

template <class X>
std::string SendPaymentForm<X>::write()
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
template <class X>
GetSavedInfo<X> GetSavedInfo<X>::read(Reader reader)
{
    return GetSavedInfo<X>();
}

template <class X>
std::string GetSavedInfo<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

template <class X>
ClearSavedInfo<X>::ClearSavedInfo(std::optional<bool> credentials_, std::optional<bool> info_) {}

template <class X>
ClearSavedInfo<X> ClearSavedInfo<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> credentials_;

    if (1 << 0)
        credentials_ = true;
    else
        credentials_ = std::nullopt;
    std::optional<bool> info_;

    if (1 << 1)
        info_ = true;
    else
        info_ = std::nullopt;
    return ClearSavedInfo<X>(credentials_, info_);
}

template <class X>
std::string ClearSavedInfo<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= credentials ? 1 << 0 : 0;
    flags |= info ? 1 << 1 : 0;
    return buffer;
}

template <class X>
GetBankCardData<X>::GetBankCardData(std::string number_) {}

template <class X>
GetBankCardData<X> GetBankCardData<X>::read(Reader reader)
{
    std::string number_ = String::read(reader);
    return GetBankCardData<X>(number_);
}

template <class X>
std::string GetBankCardData<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += String::write(number);
    return buffer;
}
