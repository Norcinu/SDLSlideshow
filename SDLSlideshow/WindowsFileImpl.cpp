#define VC_EXTRALEAN
#include "WindowsFileImpl.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>

bool CheckFileIsImage( WIN32_FIND_DATA &file_data );

WindowsFileImpl::WindowsFileImpl()
{
}

WindowsFileImpl::~WindowsFileImpl()
{
}

bool WindowsFileImpl::scanDirectory(const std::string& dir_name)
{
	_root_directory = dir_name.substr(0, dir_name.length()-3);
	WIN32_FIND_DATA file_data;
	HANDLE file_handle = FindFirstFile(dir_name.c_str(), &file_data);

	if (file_handle == INVALID_HANDLE_VALUE) {
		std::cerr << "Invalid handle: " << GetLastError() << std::endl;
		return false;
	}
	else {
		if (CheckFileIsImage(file_data))
			_files_found.push_back(dir_name + file_data.cFileName);

		while (FindNextFile(file_handle, &file_data) != 0) {
			FILETIME ft = file_data.ftCreationTime;
			SYSTEMTIME st;
			FileTimeToSystemTime(&ft, &st);
		
			if (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				std::cout << "Found a directory: " << file_data.cFileName << std::endl;
			else {
				if (CheckFileIsImage(file_data))
					_files_found.push_back(dir_name + file_data.cFileName);
			}
		}
		FindClose(file_handle);

		std::for_each(_files_found.begin(), _files_found.end(), [](std::string& str){
			std::cout << "File Found: " << str << std::endl;
		});
	}
	return true;
}

bool CheckFileIsImage( WIN32_FIND_DATA &file_data )
{
	return (strstr(file_data.cFileName, ".jpg") != nullptr || strstr(file_data.cFileName, ".png") != nullptr);
}
