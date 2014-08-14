#include <iostream>
#include <memory>
#include "FileList.h"

using std::shared_ptr;

int main(int argc, const char * argv[])
{
    shared_ptr<FileList> _file_list(new FileList(argv[1], false));
    _file_list->scanDirectory();
    return 0;
}

