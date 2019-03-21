
#include "Log.h"

createFileSingleton(Log);
//initialiseSingleton(Log);
Log::Log()
{
}


Log::~Log()
{
	close();
}

void Log::open()
{
	if (!m_loggerThread)
	{
		openLogFile(m_file, "Log");
		m_loggerThread = make_shared<thread>(bind(&Log::logLooping, this));
	}
}

void Log::close()
{
	m_termingted = true;
	if (m_loggerThread)
	{
		m_loggerThread->join();
		m_loggerThread.reset();
		fclose(m_file);
		m_file = nullptr;
	}
}

void Log::logLooping()
{
	while (!m_termingted)
	{
		Sleep(2000);
	}
}

void Log::openLogFile(FILE *& afile, string name)
{
	if (afile == nullptr)
		renewLogFile(afile, name);
}

void Log::renewLogFile(FILE *& afile, string name)
{
	string logFilename = genLogFilename(name);
	string filename = expandLogFilename(logFilename);

	ForceDirectory(ExtractFilePath(filename));
	if (afile != nullptr)
		fclose(afile);

	afile = fopen(filename.c_str(), "ab+");

	if (afile == NULL)
		fprintf(stderr, "%s: Error opening '%s': %s\n", __FUNCTION__, filename.c_str(), strerror(errno));
}

string genLogFilename(string name)
{
	time_t now;
	struct tm *timeinfo = nullptr;
	now = time(NULL);
	timeinfo = localtime(&now);
	char fname[200] = {};

	sprintf(fname, "%s%d-%d-%d_%02d%02d%02d.log",
		name.c_str(),
		timeinfo->tm_year + 1900,
		timeinfo->tm_mon + 1,
		timeinfo->tm_mday,
		timeinfo->tm_hour,
		timeinfo->tm_min,
		timeinfo->tm_sec);

	return fname;
}

void rebasePath()
{
	char buffer[8192];
	if (::GetModuleFileName(nullptr, buffer, MAX_PATH) != 0)
	{
		string filename = buffer;
		string path = ExtractFilePath(filename);
		SetCurrentDirectory(LPCSTR(path.c_str()));
	}
}

string expandLogFilename(const string & logFilename)
{
	rebasePath();
	string relativeName = "log/" + logFilename;
	char buffer[4096] = {};
	if (::GetModuleFileName(nullptr, buffer, MAX_PATH) != 0)
	{
		string filename = buffer;
		string path = ExtractFilePath(filename);
		string fullname = path + relativeName;
		return fullname;
	}
	return expandLogFilename(relativeName);
}
