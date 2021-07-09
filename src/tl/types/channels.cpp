#include "tl/types/channels.h"

ChannelParticipants::ChannelParticipants(int count_, std::vector<TLObject> participants_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ChannelParticipants ChannelParticipants::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> participants_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return ChannelParticipants(count_, participants_, chats_, users_);
}

std::string ChannelParticipants::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(participants);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
ChannelParticipantsNotModified ChannelParticipantsNotModified::read(Reader reader)
{
    return ChannelParticipantsNotModified();
}

std::string ChannelParticipantsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

ChannelParticipant::ChannelParticipant(TLObject participant_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ChannelParticipant ChannelParticipant::read(Reader reader)
{
    TLObject participant_ = TLObject::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return ChannelParticipant(participant_, chats_, users_);
}

std::string ChannelParticipant::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += participant.write();
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

AdminLogResults::AdminLogResults(std::vector<TLObject> events_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

AdminLogResults AdminLogResults::read(Reader reader)
{
    std::vector<TLObject> events_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return AdminLogResults(events_, chats_, users_);
}

std::string AdminLogResults::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(events);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
