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

#include "tl/functions/folders.h"

EditPeerFolders::EditPeerFolders(std::vector<TLObject> folder_peers_) {}

EditPeerFolders EditPeerFolders::read(Reader reader)
{
    std::vector<TLObject> folder_peers_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return EditPeerFolders(folder_peers_);
}

std::string EditPeerFolders::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Vector<TLObject>::write(folder_peers);
    return buffer;
}

DeleteFolder::DeleteFolder(int folder_id_) {}

DeleteFolder DeleteFolder::read(Reader reader)
{
    int folder_id_ = Int::read(reader);
    return DeleteFolder(folder_id_);
}

std::string DeleteFolder::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(folder_id);
    return buffer;
}
