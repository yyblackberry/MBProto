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

#include "tl/types/updates.h"

State::State(int pts_, int qts_, int date_, int seq_, int unread_count_) {}

State State::read(Reader reader)
{
    int pts_ = Int::read(reader);
    int qts_ = Int::read(reader);
    int date_ = Int::read(reader);
    int seq_ = Int::read(reader);
    int unread_count_ = Int::read(reader);
    return State(pts_, qts_, date_, seq_, unread_count_);
}

std::string State::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pts);
    buffer += Int::write(qts);
    buffer += Int::write(date);
    buffer += Int::write(seq);
    buffer += Int::write(unread_count);
    return buffer;
}

DifferenceEmpty::DifferenceEmpty(int date_, int seq_) {}

DifferenceEmpty DifferenceEmpty::read(Reader reader)
{
    int date_ = Int::read(reader);
    int seq_ = Int::read(reader);
    return DifferenceEmpty(date_, seq_);
}

std::string DifferenceEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(date);
    buffer += Int::write(seq);
    return buffer;
}

Difference::Difference(std::vector<TLObject> new_messages_, std::vector<TLObject> new_encrypted_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject state_) {}

Difference Difference::read(Reader reader)
{
    std::vector<TLObject> new_messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> new_encrypted_messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> other_updates_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject state_ = std::get<TLObject>(TLObject::read(reader));
    return Difference(new_messages_, new_encrypted_messages_, other_updates_, chats_, users_, state_);
}

std::string Difference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(new_messages);
    buffer += Vector<TLObject>::write(new_encrypted_messages);
    buffer += Vector<TLObject>::write(other_updates);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    buffer += state.write();
    return buffer;
}

DifferenceSlice::DifferenceSlice(std::vector<TLObject> new_messages_, std::vector<TLObject> new_encrypted_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, TLObject intermediate_state_) {}

DifferenceSlice DifferenceSlice::read(Reader reader)
{
    std::vector<TLObject> new_messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> new_encrypted_messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> other_updates_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    TLObject intermediate_state_ = std::get<TLObject>(TLObject::read(reader));
    return DifferenceSlice(new_messages_, new_encrypted_messages_, other_updates_, chats_, users_, intermediate_state_);
}

std::string DifferenceSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(new_messages);
    buffer += Vector<TLObject>::write(new_encrypted_messages);
    buffer += Vector<TLObject>::write(other_updates);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    buffer += intermediate_state.write();
    return buffer;
}

DifferenceTooLong::DifferenceTooLong(int pts_) {}

DifferenceTooLong DifferenceTooLong::read(Reader reader)
{
    int pts_ = Int::read(reader);
    return DifferenceTooLong(pts_);
}

std::string DifferenceTooLong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(pts);
    return buffer;
}

ChannelDifferenceEmpty::ChannelDifferenceEmpty(int pts_, std::optional<bool> final_, std::optional<int> timeout_) {}

ChannelDifferenceEmpty ChannelDifferenceEmpty::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> final_;
    final_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int pts_ = Int::read(reader);
    std::optional<int> timeout_;
    timeout_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    return ChannelDifferenceEmpty(pts_, final_, timeout_);
}

std::string ChannelDifferenceEmpty::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= final ? 1 << 0 : 0;
    flags |= timeout ? 1 << 1 : 0;
    buffer += Int::write(pts);

    if (timeout)
        buffer += Int::write(timeout.value());
    return buffer;
}

ChannelDifferenceTooLong::ChannelDifferenceTooLong(TLObject dialog_, std::vector<TLObject> messages_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> final_, std::optional<int> timeout_) {}

ChannelDifferenceTooLong ChannelDifferenceTooLong::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> final_;
    final_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<int> timeout_;
    timeout_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    TLObject dialog_ = std::get<TLObject>(TLObject::read(reader));
    std::vector<TLObject> messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelDifferenceTooLong(dialog_, messages_, chats_, users_, final_, timeout_);
}

std::string ChannelDifferenceTooLong::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= final ? 1 << 0 : 0;
    flags |= timeout ? 1 << 1 : 0;

    if (timeout)
        buffer += Int::write(timeout.value());
    buffer += dialog.write();
    buffer += Vector<TLObject>::write(messages);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ChannelDifference::ChannelDifference(int pts_, std::vector<TLObject> new_messages_, std::vector<TLObject> other_updates_, std::vector<TLObject> chats_, std::vector<TLObject> users_, std::optional<bool> final_, std::optional<int> timeout_) {}

ChannelDifference ChannelDifference::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> final_;
    final_ = (1 << 0) ? std::optional{true} : std::nullopt;
    int pts_ = Int::read(reader);
    std::optional<int> timeout_;
    timeout_ = (1 << 1) ? std::optional{Int::read(reader)} : std::nullopt;
    std::vector<TLObject> new_messages_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> other_updates_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> chats_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    std::vector<TLObject> users_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return ChannelDifference(pts_, new_messages_, other_updates_, chats_, users_, final_, timeout_);
}

std::string ChannelDifference::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= final ? 1 << 0 : 0;
    flags |= timeout ? 1 << 1 : 0;
    buffer += Int::write(pts);

    if (timeout)
        buffer += Int::write(timeout.value());
    buffer += Vector<TLObject>::write(new_messages);
    buffer += Vector<TLObject>::write(other_updates);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
