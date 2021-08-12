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

class EditPeerFolders : public TLObject
{
private:
    int __id = 0x6847d0ab;

public:
    std::vector<TLObject> folder_peers;
    EditPeerFolders(std::vector<TLObject> folder_peers_);
    static EditPeerFolders read(Reader reader);
    std::string write();
};

class DeleteFolder : public TLObject
{
private:
    int __id = 0x1c295881;

public:
    int folder_id;
    DeleteFolder(int folder_id_);
    static DeleteFolder read(Reader reader);
    std::string write();
};
