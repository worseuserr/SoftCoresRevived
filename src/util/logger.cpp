#include "util.h"
#include <sstream>
#include <fstream>

using namespace util;

std::ofstream file;



Logger::Logger(const char *outputFilename)
{
	outputFile = outputFilename;
	file.Open(outputFilename, std::ios_base::out);
	file.Close();
}

void	Logger::Write(const char *message)
{
	tm					newtime;
	time_t				now;
	std::stringstream	text;

	now = time(0);
	localtime_s(&newtime, &now);
	file.Open(outputFile, std::ios_base::app);
	if (file.IsOpen())
	{
		text << "[" << newtime.tm_mday
			<< "/" << newtime.tm_mon + 1
			<< "/" << newtime.tm_year + 1900
			<< " " << newtime.tm_hour
			<< ":" << newtime.tm_min
			<< ":" << newtime.tm_sec
			<< "] " << message;
		file << text.str().c_str() << "\n";
		file.Close();
	}
}
