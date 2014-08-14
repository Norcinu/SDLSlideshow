#include "WindowsFileImpl.h"
#include <iostream>
#include <Windows.h>

WindowsFileImpl::WindowsFileImpl()
{
}

WindowsFileImpl::~WindowsFileImpl()
{
}

bool WindowsFileImpl::scanDirectory(const std::string& dir_name)
{
	WIN32_FIND_DATA file_data;
	HANDLE file_handle = FindFirstFile(dir_name.c_str(), &file_data);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		std::cerr << "Invalid handle: " << GetLastError() << std::endl;
		return false;
	}
	else
	{
		std::cout << "Found a file: " << file_data.cFileName << std::endl;
		while (FindNextFile(file_handle, &file_data) != 0)
		{
			if (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				std::cout << "Found a directory: " << file_data.cFileName << std::endl;
			else
				std::cout << "Found a file: " << file_data.cFileName << std::endl;
		}
		FindClose(file_handle);
	}
	return true;
}