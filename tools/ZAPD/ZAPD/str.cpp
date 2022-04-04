#include <algorithm>
#include "str.h"

#define MAX_TMP_STRING 8
static std::string g_tmp[MAX_TMP_STRING];
static int g_i = 0;

const char* STR(const std::string& s)
{
	auto& result = g_tmp[(g_i++) % MAX_TMP_STRING];
	result = s;
	std::replace(result.begin(), result.end(), '\\', '/');
	return result.c_str();
}

const char* STR(const std::filesystem::path& p)
{
	auto& result = g_tmp[(g_i++) % MAX_TMP_STRING];
	result = p.string();
	std::replace(result.begin(), result.end(), '\\', '/');

#ifdef _MSC_VER
	return result.c_str();
#else
	return result.c_str();
#endif
}
