#ifndef FILE_HANDLER_HH
#define FILE_HANDLER_HH

#include "SMake.hh"

namespace SMake
{
	class SMAKE_API FileHandler
	{
	public:
		static bool ReadTextFile(std::string_view path, std::string* content);
		static bool WriteTextFile(std::string_view path, std::string content);

		static bool FileExists(std::string_view path);
	};
}


#endif //FILE_HANDLER_HPP