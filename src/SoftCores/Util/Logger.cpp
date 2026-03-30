#include <SoftCores/Util/File.h>
#include <SoftCores/Util/Logger.h>
#include <sstream>

using namespace SoftCores::Util;

Logger::Logger(const char *outputFilename)
{
	outputFile_ = outputFilename;
	file_.Open(outputFilename, std::ios_base::out);
	file_.Close();
}

void Logger::Write(const char *message)
{
	tm					newtime;
	time_t				now;
	std::stringstream	text;

	now = time(nullptr);
	if (localtime_s(&newtime, &now) != 0)
		throw 1;
	file_.Open(outputFile_, std::ios_base::app);
	if (file_.IsOpen())
	{
		text << "[" << newtime.tm_mday
			<< "/" << newtime.tm_mon + 1
			<< "/" << newtime.tm_year + 1900
			<< " " << newtime.tm_hour
			<< ":" << newtime.tm_min
			<< ":" << newtime.tm_sec
			<< "] " << message;
		file_ << text.str().c_str() << "\n";
		file_.Close();
	}
}
