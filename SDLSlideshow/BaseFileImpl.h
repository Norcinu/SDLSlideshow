#ifndef SDLSlideshow_BaseFileImpl_h
#define SDLSlideshow_BaseFileImpl_h

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class BaseFileImpl
{
public:
    virtual ~BaseFileImpl() {}
    virtual bool scanDirectory(const std::string& directory) = 0;
    vector<string> getFilesFound();

protected:
    BaseFileImpl() { _root_directory = ""; }
    
protected:
    std::string _root_directory;
    vector<string> _files_found;
};

#endif
