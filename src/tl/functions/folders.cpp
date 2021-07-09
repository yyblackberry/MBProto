#include "tl/functions/folders.h"

template <class X>
EditPeerFolders<X>::EditPeerFolders(std::vector<TLObject> folder_peers_) {}

template <class X>
EditPeerFolders<X> EditPeerFolders<X>::read(Reader reader)
{
    std::vector<TLObject> folder_peers_ = Vector<TLObject>::read(reader);
    return EditPeerFolders<X>(folder_peers_);
}

template <class X>
std::string EditPeerFolders<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(folder_peers);
    return buffer;
}

template <class X>
DeleteFolder<X>::DeleteFolder(int folder_id_) {}

template <class X>
DeleteFolder<X> DeleteFolder<X>::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return DeleteFolder<X>(folder_id_);
}

template <class X>
std::string DeleteFolder<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}
