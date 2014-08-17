#include "BaseFileImpl.h"
#include <algorithm>

vector<string> BaseFileImpl::getFilesFound()
{
    std::vector<string> temp;
    for (auto str : _files_found) {
        temp.push_back(str);
    }
    return std::move(temp);
}