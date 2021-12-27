#ifdef _MSC_VER
#include <windows.h>
#include <chrono>
#include "global.h"
#include "types.h"

unsigned long get_time(void) // returns microseconds
{
	return (unsigned long)std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000;
}

u64 getTickCount()
{
	return GetTickCount();
}

void sleep(u64 ms)
{
	return Sleep(ms);
}

#endif
