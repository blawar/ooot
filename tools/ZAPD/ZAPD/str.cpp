#include "str.h"

const char* STR(const std::string& s)
{
	return s.c_str();
}

const char* STR(const std::filesystem::path& p)
{
#ifdef _MSC_VER
	return p.string().c_str();
#else
	return p.c_str();
#endif
}
