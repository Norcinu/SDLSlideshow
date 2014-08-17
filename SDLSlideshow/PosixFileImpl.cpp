#include "PosixFileImpl.h"
#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>

PosixFileImpl::PosixFileImpl()
{
    
}

PosixFileImpl::~PosixFileImpl()
{
    
}

bool PosixFileImpl::scanDirectory(const std::string& dir_name)
{
    DIR *directory = opendir(dir_name.c_str());
    if (directory == nullptr)
        return false;
    
    dirent *file = nullptr;
    while ((file = readdir(directory))) {
        if (file->d_name[0] != '.') {
            std::cout << "Found File: " << file->d_name << std::endl;
            _files_found.push_back(dir_name + file->d_name);
        }
    }

    closedir(directory);
    return true;
}