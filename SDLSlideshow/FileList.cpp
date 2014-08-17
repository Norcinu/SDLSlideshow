#include "FileList.h"

#if defined(__unix__) || defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
#include "PosixFileImpl.h"
#elif defined WIN32
#include "WindowsFileImpl.h"
#endif

FileList::FileList()
{
    _impl = nullptr;
    _scan_recursive = false;
    _directory = "";
}

FileList::~FileList()
{
    
}

FileList::FileList(const char *dir_name, const bool recursive_scan)
{
    _directory = dir_name;
    _scan_recursive = recursive_scan;
#if defined(__unix__) || defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
    _impl = new PosixFileImpl;
#elif defined WIN32
    _impl = new WindowsFileImpl;
#endif
}

bool FileList::scanDirectory()
{
    _impl->scanDirectory(_directory);
    _files = _impl->getFilesFound();
    return true;
}

