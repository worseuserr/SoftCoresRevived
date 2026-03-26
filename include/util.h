#pragma once

#include <fstream>
#include "natives.h"

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

namespace Math
{
	int Round(float x);
	int Ceil(float x);
	int Floor(float x);
	float ToFloat(int x);
}

inline static Hash Key(const char* key)
{
	return MISC::GET_HASH_KEY(key);
}

}
