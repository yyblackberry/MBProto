#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class EditPeerFolders
{
private:
    int __id = 0x6847d0ab;

public:
    std::vector<TLObject> folder_peers;
    EditPeerFolders(std::vector<TLObject> folder_peers_);
    static EditPeerFolders<X> read(Reader reader);
    std::string write();
};

template <class X>
class DeleteFolder
{
private:
    int __id = 0x1c295881;

public:
    int folder_id;
    DeleteFolder(int folder_id_);
    static DeleteFolder<X> read(Reader reader);
    std::string write();
};
