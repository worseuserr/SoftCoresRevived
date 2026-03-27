#include "file.h"
#include <fstream>

using namespace SoftCores;


void File::Open(const char *filename, std::ios_base::openmode mode)
{
	file_.open(filename, mode);
}

void File::Close()
{
	file_.close();
}

bool File::IsOpen()
{
	return (file_.is_open());
}

bool File::Exists(const char *filename)
{
	std::ifstream infile(filename);
	return (infile.good());
}
