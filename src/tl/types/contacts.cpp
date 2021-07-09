#include "tl/types/contacts.h"
ContactsNotModified ContactsNotModified::read(Reader reader)
{
    return ContactsNotModified();
}

std::string ContactsNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

Contacts::Contacts(std::vector<TLObject> contacts_, int saved_count_, std::vector<TLObject> users_) {}

Contacts Contacts::read(Reader reader)
{
    std::vector<TLObject> contacts_ = Vector<TLObject>::read(reader);
    int saved_count_ = Int::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return Contacts(contacts_, saved_count_, users_);
}

std::string Contacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(contacts);
    buffer += Int::write(saved_count);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ImportedContacts::ImportedContacts(std::vector<TLObject> imported_, std::vector<TLObject> popular_invites_, std::vector<long> retry_contacts_, std::vector<TLObject> users_) {}

ImportedContacts ImportedContacts::read(Reader reader)
{
    std::vector<TLObject> imported_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> popular_invites_ = Vector<TLObject>::read(reader);
    std::vector<long> retry_contacts_ = Vector<long>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return ImportedContacts(imported_, popular_invites_, retry_contacts_, users_);
}

std::string ImportedContacts::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(imported);
    buffer += Vector<TLObject>::write(popular_invites);
    buffer += Vector<long>::write(retry_contacts);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

Blocked::Blocked(std::vector<TLObject> blocked_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

Blocked Blocked::read(Reader reader)
{
    std::vector<TLObject> blocked_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return Blocked(blocked_, chats_, users_);
}

std::string Blocked::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(blocked);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

BlockedSlice::BlockedSlice(int count_, std::vector<TLObject> blocked_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

BlockedSlice BlockedSlice::read(Reader reader)
{
    int count_ = Int::read(reader);
    std::vector<TLObject> blocked_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return BlockedSlice(count_, blocked_, chats_, users_);
}

std::string BlockedSlice::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(count);
    buffer += Vector<TLObject>::write(blocked);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

Found::Found(std::vector<TLObject> my_results_, std::vector<TLObject> results_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

Found Found::read(Reader reader)
{
    std::vector<TLObject> my_results_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> results_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return Found(my_results_, results_, chats_, users_);
}

std::string Found::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(my_results);
    buffer += Vector<TLObject>::write(results);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}

ResolvedPeer::ResolvedPeer(TLObject peer_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

ResolvedPeer ResolvedPeer::read(Reader reader)
{
    TLObject peer_ = TLObject::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return ResolvedPeer(peer_, chats_, users_);
}

std::string ResolvedPeer::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += peer.write();
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
TopPeersNotModified TopPeersNotModified::read(Reader reader)
{
    return TopPeersNotModified();
}

std::string TopPeersNotModified::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}

TopPeers::TopPeers(std::vector<TLObject> categories_, std::vector<TLObject> chats_, std::vector<TLObject> users_) {}

TopPeers TopPeers::read(Reader reader)
{
    std::vector<TLObject> categories_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> chats_ = Vector<TLObject>::read(reader);
    std::vector<TLObject> users_ = Vector<TLObject>::read(reader);
    return TopPeers(categories_, chats_, users_);
}

std::string TopPeers::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(categories);
    buffer += Vector<TLObject>::write(chats);
    buffer += Vector<TLObject>::write(users);
    return buffer;
}
TopPeersDisabled TopPeersDisabled::read(Reader reader)
{
    return TopPeersDisabled();
}

std::string TopPeersDisabled::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
