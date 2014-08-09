#include "BaseFileImpl.h"

vector<string> BaseFileImpl::getFilesFound()
{
    std::vector<string> temp;
    std::for_each(_files_found.begin(), _files_found.end(),
                  [&temp](std::string str) { temp.push_back(str); });
    return temp;
}