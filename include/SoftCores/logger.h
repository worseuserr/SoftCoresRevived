#pragma once
#include "file.h"

namespace SoftCores
{
	class Logger
	{
	private:
		const char	*outputFile_;
		File		file_;
	public:
		Logger(const char *outputFilename);
		void	Write(const char *message);
	};
}
