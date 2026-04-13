#pragma once
#include <SoftCores/Util/File.h>

namespace SoftCores::Util
{
	class	Logger
	{
		const char	*OutputFile;
		File		File;

	public:
		Logger(const char *outputFilename);
		void	Write(const std::string &message, bool appendDatetime = false);
		void	Write(const std::wstring &message, bool appendDatetime = false);
		void	Write(const char *message, bool appendDatetime = false);
		void	Write(const wchar_t *message, bool appendDatetime = false);
	};
}
