#pragma once

#include <string>
#include <algorithm>
#include <windows.h>

using std::string;
using std::max;


bool	CreateDir(string &dir);
bool	ExistDirectory(const string &path);
bool	IsPathDelimiter(const string& path, int index);
string	ExcludePathDelimiter(const string &path);

//���ݷ��Ž�ȡ·��
extern string	ExtractFilePath(const string path);
extern bool		ForceDirectory(const string &path);
