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

#include "tl/types/storage.h"
FileUnknown FileUnknown::read(Reader reader)
{
    return FileUnknown();
}

std::string FileUnknown::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FilePartial FilePartial::read(Reader reader)
{
    return FilePartial();
}

std::string FilePartial::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FileJpeg FileJpeg::read(Reader reader)
{
    return FileJpeg();
}

std::string FileJpeg::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FileGif FileGif::read(Reader reader)
{
    return FileGif();
}

std::string FileGif::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FilePng FilePng::read(Reader reader)
{
    return FilePng();
}

std::string FilePng::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FilePdf FilePdf::read(Reader reader)
{
    return FilePdf();
}

std::string FilePdf::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FileMov FileMov::read(Reader reader)
{
    return FileMov();
}

std::string FileMov::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
FileWebp FileWebp::read(Reader reader)
{
    return FileWebp();
}

std::string FileWebp::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    return buffer;
}
