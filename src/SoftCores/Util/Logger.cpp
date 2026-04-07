#include <SoftCores/Util/File.h>
#include <SoftCores/Util/Logger.h>
#include <sstream>

using namespace SoftCores::Util;

Logger::Logger(const char *outputFilename)
{
	OutputFile = outputFilename;
	File.Open(outputFilename, std::ios_base::out);
	File.Close();
}

void Logger::Write(const std::string &message)
{
	return (Write(message.c_str()));
}

void Logger::Write(const std::wstring &message)
{
	return (Write(message.c_str()));
}

void Logger::Write(const char *message)
{
	tm					newtime{};
	time_t				now;
	std::stringstream	text;

	now = time(nullptr);
	if (localtime_s(&newtime, &now) != 0)
		throw (std::exception());
	File.Open(OutputFile, std::ios_base::app);
	if (File.IsOpen())
	{
		text << "[" << newtime.tm_mday
			<< "/" << newtime.tm_mon + 1
			<< "/" << newtime.tm_year + 1900
			<< " " << newtime.tm_hour
			<< ":" << newtime.tm_min
			<< ":" << newtime.tm_sec
			<< "] " << message;
		File << text.str().c_str() << "\n";
		File.Close();
	}
}

void Logger::Write(const wchar_t *message)
{
	tm					newtime{};
	time_t				now;
	std::stringstream	text;

	now = time(nullptr);
	if (localtime_s(&newtime, &now) != 0)
		throw (std::exception());
	File.Open(OutputFile, std::ios_base::app);
	if (File.IsOpen())
	{
		text << "[" << newtime.tm_mday
			<< "/" << newtime.tm_mon + 1
			<< "/" << newtime.tm_year + 1900
			<< " " << newtime.tm_hour
			<< ":" << newtime.tm_min
			<< ":" << newtime.tm_sec
			<< "] " << File::WideToUTF8(message);
		File << text.str().c_str() << "\n";
		File.Close();
	}
}
