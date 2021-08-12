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

#include "tl/functions/upload.h"

SaveFilePart::SaveFilePart(long file_id_, int file_part_, std::string bytes_) {}

SaveFilePart SaveFilePart::read(Reader reader)
{
    long file_id_ = Long::read(reader);
    int file_part_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return SaveFilePart(file_id_, file_part_, bytes_);
}

std::string SaveFilePart::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(file_id);
    buffer += Int::write(file_part);
    buffer += Bytes::write(bytes);
    return buffer;
}

GetFile::GetFile(TLObject location_, int offset_, int limit_, std::optional<bool> precise_, std::optional<bool> cdn_supported_) {}

GetFile GetFile::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> precise_;
    precise_ = (1 << 0) ? std::optional{true} : std::nullopt;
    std::optional<bool> cdn_supported_;
    cdn_supported_ = (1 << 1) ? std::optional{true} : std::nullopt;
    TLObject location_ = std::get<TLObject>(TLObject::read(reader));
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetFile(location_, offset_, limit_, precise_, cdn_supported_);
}

std::string GetFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    int flags = 0;
    flags |= precise ? 1 << 0 : 0;
    flags |= cdn_supported ? 1 << 1 : 0;
    buffer += location.write();
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

SaveBigFilePart::SaveBigFilePart(long file_id_, int file_part_, int file_total_parts_, std::string bytes_) {}

SaveBigFilePart SaveBigFilePart::read(Reader reader)
{
    long file_id_ = Long::read(reader);
    int file_part_ = Int::read(reader);
    int file_total_parts_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return SaveBigFilePart(file_id_, file_part_, file_total_parts_, bytes_);
}

std::string SaveBigFilePart::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(file_id);
    buffer += Int::write(file_part);
    buffer += Int::write(file_total_parts);
    buffer += Bytes::write(bytes);
    return buffer;
}

GetWebFile::GetWebFile(TLObject location_, int offset_, int limit_) {}

GetWebFile GetWebFile::read(Reader reader)
{
    TLObject location_ = std::get<TLObject>(TLObject::read(reader));
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetWebFile(location_, offset_, limit_);
}

std::string GetWebFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += location.write();
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

GetCdnFile::GetCdnFile(std::string file_token_, int offset_, int limit_) {}

GetCdnFile GetCdnFile::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetCdnFile(file_token_, offset_, limit_);
}

std::string GetCdnFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

ReuploadCdnFile::ReuploadCdnFile(std::string file_token_, std::string request_token_) {}

ReuploadCdnFile ReuploadCdnFile::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    std::string request_token_ = Bytes::read(reader);
    return ReuploadCdnFile(file_token_, request_token_);
}

std::string ReuploadCdnFile::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Bytes::write(request_token);
    return buffer;
}

GetCdnFileHashes::GetCdnFileHashes(std::string file_token_, int offset_) {}

GetCdnFileHashes GetCdnFileHashes::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    int offset_ = Int::read(reader);
    return GetCdnFileHashes(file_token_, offset_);
}

std::string GetCdnFileHashes::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Int::write(offset);
    return buffer;
}

GetFileHashes::GetFileHashes(TLObject location_, int offset_) {}

GetFileHashes GetFileHashes::read(Reader reader)
{
    TLObject location_ = std::get<TLObject>(TLObject::read(reader));
    int offset_ = Int::read(reader);
    return GetFileHashes(location_, offset_);
}

std::string GetFileHashes::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += location.write();
    buffer += Int::write(offset);
    return buffer;
}
