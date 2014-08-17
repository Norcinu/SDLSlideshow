#ifndef __SDLSlideshow__FileList__
#define __SDLSlideshow__FileList__

#include <iostream>
#include <string>
#include <vector>

class BaseFileImpl;

using std::string;
using std::vector;

class FileList
{
public:
    FileList();
    FileList(const char *dir_name, const bool scan_recursive);
    ~FileList();
    
    bool scanDirectory();
    std::string getDirectory() const { return _directory; }
    void setDirectory(const std::string &dir) { _directory = dir; }
    vector<string> getFiles() const { return _files; }

private:
    bool _scan_recursive;
    BaseFileImpl *_impl;
    string _directory;
    vector<string> _files;
};



#endif
