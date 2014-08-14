#define VC_EXTRALEAN
#include "WindowsFileImpl.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>

WindowsFileImpl::WindowsFileImpl()
{
}

WindowsFileImpl::~WindowsFileImpl()
{
}

bool WindowsFileImpl::scanDirectory(const std::string& dir_name)
{
	_root_directory = dir_name;
	WIN32_FIND_DATA file_data;
	HANDLE file_handle = FindFirstFile(dir_name.c_str(), &file_data);
	if (file_handle == INVALID_HANDLE_VALUE) {
		std::cerr << "Invalid handle: " << GetLastError() << std::endl;
		return false;
	}
	else {
		_files_found.push_back(file_data.cFileName);

		while (FindNextFile(file_handle, &file_data) != 0) {
			FILETIME ft = file_data.ftCreationTime;
			SYSTEMTIME st;
			FileTimeToSystemTime(&ft, &st);
		
			if (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				std::cout << "Found a directory: " << file_data.cFileName << std::endl;
			else 
				_files_found.push_back(file_data.cFileName);
		}
		FindClose(file_handle);

		std::for_each(_files_found.begin(), _files_found.end(), [](std::string& str){
			std::cout << "File Found: " << str << std::endl;
		});
	}
	return true;
}