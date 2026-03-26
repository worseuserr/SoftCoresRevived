#include "util.h"
#include <fstream>

using namespace util;


void	File::Open(const char *filename, std::ios_base::openmode mode)
{
	file.open(filename, mode);
}

void	File::Close()
{
	file.close();
}

bool	File::IsOpen()
{
	return (file.is_open());
}

bool	File::Exists(const char *filename)
{
	std::ifstream infile(filename);
	return (infile.good());
}
