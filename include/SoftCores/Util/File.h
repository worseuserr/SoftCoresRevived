#pragma once
#include <fstream>

namespace SoftCores::Util
{
	class File
	{
	private:
		std::ofstream	file;

	public:
		void				Open(const char *filename, std::ios_base::openmode mode);
		void				Close();
		bool				IsOpen() const;
		static bool			Exists(const char *filename);
		static std::string	WideToUTF8(const wchar_t *wstr);
		template	<typename T>
		File		&operator<<(const T& data)
		{
			file << data;
			return (*this);
		}
	};
}
