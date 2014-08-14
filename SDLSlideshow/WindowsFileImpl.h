#ifndef WIN_FILE_IMPL_H
#define WIN_FILE_IMPL_H

#include "BaseFileImpl.h"

class WindowsFileImpl : public BaseFileImpl
{
public:
	WindowsFileImpl();
	~WindowsFileImpl();

	bool scanDirectory(const std::string& dir_name);
};

#endif