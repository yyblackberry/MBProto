#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

template <class X>
class SaveFilePart
{
private:
    int __id = 0xb304a621;

public:
    long file_id;
    int file_part;
    std::string bytes;
    SaveFilePart(long file_id_, int file_part_, std::string bytes_);
    static SaveFilePart<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFile
{
private:
    int __id = 0xb15a9afc;

public:
    std::optional<bool> precise;
    std::optional<bool> cdn_supported;
    TLObject location;
    int offset;
    int limit;
    GetFile(TLObject location_, int offset_, int limit_, std::optional<bool> precise_ = std::nullopt, std::optional<bool> cdn_supported_ = std::nullopt);
    static GetFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class SaveBigFilePart
{
private:
    int __id = 0xde7b673d;

public:
    long file_id;
    int file_part;
    int file_total_parts;
    std::string bytes;
    SaveBigFilePart(long file_id_, int file_part_, int file_total_parts_, std::string bytes_);
    static SaveBigFilePart<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetWebFile
{
private:
    int __id = 0x24e6818d;

public:
    TLObject location;
    int offset;
    int limit;
    GetWebFile(TLObject location_, int offset_, int limit_);
    static GetWebFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetCdnFile
{
private:
    int __id = 0x2000bcc3;

public:
    std::string file_token;
    int offset;
    int limit;
    GetCdnFile(std::string file_token_, int offset_, int limit_);
    static GetCdnFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class ReuploadCdnFile
{
private:
    int __id = 0x9b2754a8;

public:
    std::string file_token;
    std::string request_token;
    ReuploadCdnFile(std::string file_token_, std::string request_token_);
    static ReuploadCdnFile<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetCdnFileHashes
{
private:
    int __id = 0x4da54231;

public:
    std::string file_token;
    int offset;
    GetCdnFileHashes(std::string file_token_, int offset_);
    static GetCdnFileHashes<X> read(Reader reader);
    std::string write();
};

template <class X>
class GetFileHashes
{
private:
    int __id = 0xc7025931;

public:
    TLObject location;
    int offset;
    GetFileHashes(TLObject location_, int offset_);
    static GetFileHashes<X> read(Reader reader);
    std::string write();
};
