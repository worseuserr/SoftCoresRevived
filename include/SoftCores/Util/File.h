#pragma once
#include <fstream>

namespace SoftCores::Util
{
	class File
	{
	private:
		std::ofstream	file_;

	public:
		void		Open(const char *filename, std::ios_base::openmode mode);
		void		Close();
		bool		IsOpen() const;
		static bool	Exists(const char *filename);
		template	<typename T>
		File&		operator<<(const T& data)
		{
			file_ << data;
			return (*this);
		}
	};
}
