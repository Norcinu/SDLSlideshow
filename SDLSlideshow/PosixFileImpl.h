#ifndef POSIX_FILE_IMPL_H
#define POSIX_FILE_IMPL_H

#include "BaseFileImpl.h"

class PosixFileImpl : public BaseFileImpl
{
public:
    PosixFileImpl();
    ~PosixFileImpl();
    
    bool scanDirectory(const std::string& dir_name);
};

#endif
