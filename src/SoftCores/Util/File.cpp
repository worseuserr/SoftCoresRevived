#include <SoftCores/Util/File.h>
#include <fstream>

using namespace SoftCores::Util;


void File::Open(const char *filename, std::ios_base::openmode mode)
{
	file_.open(filename, mode);
}

void File::Close()
{
	file_.close();
}

bool File::IsOpen() const
{
	return (file_.is_open());
}

bool File::Exists(const char *filename)
{
	const std::ifstream	input(filename);
	return (input.good());
}
