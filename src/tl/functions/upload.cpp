#include "tl/functions/upload.h"

template <class X>
SaveFilePart<X>::SaveFilePart(long file_id_, int file_part_, std::string bytes_) {}

template <class X>
SaveFilePart<X> SaveFilePart<X>::read(Reader reader)
{
    long file_id_ = Long::read(reader);
    int file_part_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return SaveFilePart<X>(file_id_, file_part_, bytes_);
}

template <class X>
std::string SaveFilePart<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(file_id);
    buffer += Int::write(file_part);
    buffer += Bytes::write(bytes);
    return buffer;
}

template <class X>
GetFile<X>::GetFile(TLObject location_, int offset_, int limit_, std::optional<bool> precise_, std::optional<bool> cdn_supported_) {}

template <class X>
GetFile<X> GetFile<X>::read(Reader reader)
{
    int flags = Int::read(reader);
    std::optional<bool> precise_;

    if (1 << 0)
        precise_ = true;
    else
        precise_ = std::nullopt;
    std::optional<bool> cdn_supported_;

    if (1 << 1)
        cdn_supported_ = true;
    else
        cdn_supported_ = std::nullopt;
    TLObject location_ = TLObject::read(reader);
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetFile<X>(location_, offset_, limit_, precise_, cdn_supported_);
}

template <class X>
std::string GetFile<X>::write()
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

template <class X>
SaveBigFilePart<X>::SaveBigFilePart(long file_id_, int file_part_, int file_total_parts_, std::string bytes_) {}

template <class X>
SaveBigFilePart<X> SaveBigFilePart<X>::read(Reader reader)
{
    long file_id_ = Long::read(reader);
    int file_part_ = Int::read(reader);
    int file_total_parts_ = Int::read(reader);
    std::string bytes_ = Bytes::read(reader);
    return SaveBigFilePart<X>(file_id_, file_part_, file_total_parts_, bytes_);
}

template <class X>
std::string SaveBigFilePart<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Long::write(file_id);
    buffer += Int::write(file_part);
    buffer += Int::write(file_total_parts);
    buffer += Bytes::write(bytes);
    return buffer;
}

template <class X>
GetWebFile<X>::GetWebFile(TLObject location_, int offset_, int limit_) {}

template <class X>
GetWebFile<X> GetWebFile<X>::read(Reader reader)
{
    TLObject location_ = TLObject::read(reader);
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetWebFile<X>(location_, offset_, limit_);
}

template <class X>
std::string GetWebFile<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += location.write();
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
GetCdnFile<X>::GetCdnFile(std::string file_token_, int offset_, int limit_) {}

template <class X>
GetCdnFile<X> GetCdnFile<X>::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    int offset_ = Int::read(reader);
    int limit_ = Int::read(reader);
    return GetCdnFile<X>(file_token_, offset_, limit_);
}

template <class X>
std::string GetCdnFile<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Int::write(offset);
    buffer += Int::write(limit);
    return buffer;
}

template <class X>
ReuploadCdnFile<X>::ReuploadCdnFile(std::string file_token_, std::string request_token_) {}

template <class X>
ReuploadCdnFile<X> ReuploadCdnFile<X>::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    std::string request_token_ = Bytes::read(reader);
    return ReuploadCdnFile<X>(file_token_, request_token_);
}

template <class X>
std::string ReuploadCdnFile<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Bytes::write(request_token);
    return buffer;
}

template <class X>
GetCdnFileHashes<X>::GetCdnFileHashes(std::string file_token_, int offset_) {}

template <class X>
GetCdnFileHashes<X> GetCdnFileHashes<X>::read(Reader reader)
{
    std::string file_token_ = Bytes::read(reader);
    int offset_ = Int::read(reader);
    return GetCdnFileHashes<X>(file_token_, offset_);
}

template <class X>
std::string GetCdnFileHashes<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += Bytes::write(file_token);
    buffer += Int::write(offset);
    return buffer;
}

template <class X>
GetFileHashes<X>::GetFileHashes(TLObject location_, int offset_) {}

template <class X>
GetFileHashes<X> GetFileHashes<X>::read(Reader reader)
{
    TLObject location_ = TLObject::read(reader);
    int offset_ = Int::read(reader);
    return GetFileHashes<X>(location_, offset_);
}

template <class X>
std::string GetFileHashes<X>::write()
{
    std::string buffer;
    buffer += Int::write(__id);
    buffer += location.write();
    buffer += Int::write(offset);
    return buffer;
}
