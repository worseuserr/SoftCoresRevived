#pragma once
#include <SoftCores/Util/File.h>

namespace SoftCores::Util
{
	class Logger
	{
		const char	*OutputFile;
		File		File;

	public:
		Logger(const char *outputFilename);
		void	Write(const char *message);
		void	Write(const wchar_t *message);
	};
}
