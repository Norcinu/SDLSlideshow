#include <iostream>
#include "FileList.h"
#include <memory>

int main(int argc, const char * argv[])
{
    std::shared_ptr<FileList> _file_list(new FileList(argv[1], false));
    _file_list->scanDirectory();
    return 0;
}

