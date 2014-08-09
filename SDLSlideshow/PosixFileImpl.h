#ifndef __SDLSlideshow__PosixFileImpl__
#define __SDLSlideshow__PosixFileImpl__

#include "BaseFileImpl.h"

class PosixFileImpl : public BaseFileImpl
{
public:
    PosixFileImpl();
    ~PosixFileImpl();
    
    bool scanDirectory(const std::string& dir_name);
};

#endif /* defined(__SDLSlideshow__PosixFileImpl__) */
