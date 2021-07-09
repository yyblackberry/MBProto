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
