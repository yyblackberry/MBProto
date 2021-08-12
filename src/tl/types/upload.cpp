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

#include "tl/types/upload.h"

File::File(TLObject type_, int mtime_, std::string bytes_) {}

File File::read(Reader reader)
{
    TLObject type_ = std::get<TLObject>(TLObject::read(reader));
    int mtime_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return File(type_, mtime_, bytes_);
}

std::string File::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += type.write();
    buffer += Int::write(mtime);
    buffer += Bytes::write(bytes);
    return buffer;
}

FileCdnRedirect::FileCdnRedirect(int dc_id_, std::string file_token_, std::string encryption_key_, std::string encryption_iv_, std::vector<TLObject> file_hashes_) {}

FileCdnRedirect FileCdnRedirect::read(Reader reader)
{
    int dc_id_ = Int::read(reader);
    std::string file_token_ = Bytes::read(reader);
    std::string encryption_key_ = Bytes::read(reader);
    std::string encryption_iv_ = Bytes::read(reader);
    std::vector<TLObject> file_hashes_ = std::get<std::vector<TLObject>>(TLObject::read(reader));
    return FileCdnRedirect(dc_id_, file_token_, encryption_key_, encryption_iv_, file_hashes_);
}

std::string FileCdnRedirect::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(dc_id);
    buffer += Bytes::write(file_token);
    buffer += Bytes::write(encryption_key);
    buffer += Bytes::write(encryption_iv);
    buffer += Vector<TLObject>::write(file_hashes);
    return buffer;
}

WebFile::WebFile(int size_, std::string mime_type_, TLObject file_type_, int mtime_, std::string bytes_) {}

WebFile WebFile::read(Reader reader)
{
    int size_ = Int::read(reader);
    std::string mime_type_ = String::read(reader);
    TLObject file_type_ = std::get<TLObject>(TLObject::read(reader));
    int mtime_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return WebFile(size_, mime_type_, file_type_, mtime_, bytes_);
}

std::string WebFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Int::write(size);
    buffer += String::write(mime_type);
    buffer += file_type.write();
    buffer += Int::write(mtime);
    buffer += Bytes::write(bytes);
    return buffer;
}

CdnFileReuploadNeeded::CdnFileReuploadNeeded(std::string request_token_) {}

CdnFileReuploadNeeded CdnFileReuploadNeeded::read(Reader reader)
{
    std::string request_token_ = Bytes::read(reader);
    return CdnFileReuploadNeeded(request_token_);
}

std::string CdnFileReuploadNeeded::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(request_token);
    return buffer;
}

CdnFile::CdnFile(std::string bytes_) {}

CdnFile CdnFile::read(Reader reader)
{
    std::string bytes_ = Bytes::read(reader);
    return CdnFile(bytes_);
}

std::string CdnFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(bytes);
    return buffer;
}
