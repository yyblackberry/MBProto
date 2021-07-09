#pragma once
#include "tl/bare.h"
#include "tl/TLObject.h"
#include <optional>

class FileUnknown
{
private:
    int __id = 0xaa963b05;

public:
    FileUnknown() = default;
    static FileUnknown read(Reader reader);
    std::string write();
};

class FilePartial
{
private:
    int __id = 0x40bc6f52;

public:
    FilePartial() = default;
    static FilePartial read(Reader reader);
    std::string write();
};

class FileJpeg
{
private:
    int __id = 0x7efe0e;

public:
    FileJpeg() = default;
    static FileJpeg read(Reader reader);
    std::string write();
};

class FileGif
{
private:
    int __id = 0xcae1aadf;

public:
    FileGif() = default;
    static FileGif read(Reader reader);
    std::string write();
};

class FilePng
{
private:
    int __id = 0xa4f63c0;

public:
    FilePng() = default;
    static FilePng read(Reader reader);
    std::string write();
};

class FilePdf
{
private:
    int __id = 0xae1e508d;

public:
    FilePdf() = default;
    static FilePdf read(Reader reader);
    std::string write();
};

class FileMov
{
private:
    int __id = 0x4b09ebbc;

public:
    FileMov() = default;
    static FileMov read(Reader reader);
    std::string write();
};

class FileWebp
{
private:
    int __id = 0x1081464c;

public:
    FileWebp() = default;
    static FileWebp read(Reader reader);
    std::string write();
};
