#pragma once

#include <fstream>

namespace util
{

class File
{
private:
	std::ofstream	file;
public:
	void		Open(const char *filename, std::ios_base::openmode mode);
	void		Close();
	bool		IsOpen();
	static bool	Exists(const char *filename);
	template <typename T>
	File& operator<<(const T& data)
	{
		file << data;
		return *this;
	}
};

class Logger
{
private:
	const char	*outputFile;
	File		file;
public:
	Logger(const char *outputFilename);
	void	Write(const char *message);
};

}
