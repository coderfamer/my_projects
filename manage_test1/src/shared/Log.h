#pragma once

#include "logdefine.h"
#include "singleton.h"

string genLogFilename(string name);
static void rebasePath();//����Ŀ¼
string expandLogFilename(const string& logFilename);


class Log : public Singleton<Log>
{
public:
	Log();
	~Log();

	void open();//����־���
	void close();
	void logLooping();
private:
	void openLogFile(FILE *&afile, string name = "");
	void renewLogFile(FILE *&afile, string name = "");
private:
	FILE *m_file = nullptr;//��ͨlog��־
	FILE *m_sqlfile = nullptr;//���ݿ�log��־
	bool m_needLog = false;
	bool m_termingted = false;
	shared_ptr<thread> m_loggerThread;
	mutex m_logMutex;
};

#define sLog Log::getSingleton()

