#pragma once

#include "logdefine.h"
#include "singleton.h"

string genLogFilename(string name);
static void rebasePath();//设置目录
string expandLogFilename(const string& logFilename);


class Log : public Singleton<Log>
{
public:
	Log();
	~Log();

	void open();//打开日志入口
	void close();
	void logLooping();
private:
	void openLogFile(FILE *&afile, string name = "");
	void renewLogFile(FILE *&afile, string name = "");
private:
	FILE *m_file = nullptr;//普通log日志
	FILE *m_sqlfile = nullptr;//数据库log日志
	bool m_needLog = false;
	bool m_termingted = false;
	shared_ptr<thread> m_loggerThread;
	mutex m_logMutex;
};

#define sLog Log::getSingleton()

