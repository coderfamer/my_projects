#include "util.h"


bool CreateDir(string & dir)
{
	return CreateDirectory(dir.c_str(), nullptr) == TRUE;
}

bool ExistDirectory(const string & path)
{
	WIN32_FIND_DATA findData;
	findData.dwFileAttributes = 0;
	HANDLE hFind = FindFirstFile(path.c_str(), &findData);
	if (hFind != INVALID_HANDLE_VALUE) {
		FindClose(hFind);
		return (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
	}
	return false;
}

bool IsPathDelimiter(const string & path, int index)
{
	if ((index >= 0) && (index < (int)path.size())) {
		char symbol = path[index];
		return (symbol == '\\') || (symbol == '/');;
	}
	return false;
}

string ExcludePathDelimiter(const string & path)
{
	string s = path;
	if (IsPathDelimiter(path, path.size() - 1))
		s.resize(s.size() - 1);
	return s;
}

string ExtractFilePath(const string path)
{
	size_t posWinDelimiter = path.find_last_of('\\');
	size_t posLinuxDelimiter = path.find_last_of('/');
	size_t posDriverDelimiter = path.find_last_of(':');
	size_t pos = -1;
	//string 类将 npos 定义为保证大于任何有效下标的值。
	if (posWinDelimiter != string::npos)
		pos = posWinDelimiter;
	if (posLinuxDelimiter != string::npos)
		pos = max(posLinuxDelimiter, pos);
	if (posDriverDelimiter != string::npos)
		pos = max(posDriverDelimiter, pos);

	if (pos == -1)
		return path;
	else
		return path.substr(0, pos + 1);
}

bool ForceDirectory(const string & path)
{
	std::string dir = path;
	dir = ExcludePathDelimiter(dir);

	if (ExistDirectory(dir))
		return true;

	std::string parentPath = ExtractFilePath(dir);
	if ((dir.size() < 3) || (parentPath == dir))
		return CreateDir(dir);
	else
		return ForceDirectory(parentPath) && CreateDir(dir);
}
