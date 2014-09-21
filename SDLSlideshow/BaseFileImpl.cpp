#include "BaseFileImpl.h"
#include <algorithm>

using std::vector;
using std::for_each;
using std::string;

vector<string> BaseFileImpl::getFilesFound()
{
	vector<string> temp;
#if _MSC_VER >= 1800 || !defined _MSC_VER
    for (auto str : _files_found)
        temp.push_back(str);
#else
	for(auto it = _files_found.begin(); it != _files_found.end(); it++)
		temp.push_back(*it);
#endif
    return std::move(temp);
}