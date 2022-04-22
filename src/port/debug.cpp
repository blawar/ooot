#include <ultra64.h>

#include "global.h"
#include "debug.h"
/*
#include "engine/behavior_script.h"
#include "object_helpers.h"
#include "audio/external.h"
#include "print.h"
#include "engine/surface_collision.h"
#include "mario.h"
#include "game.h"
#include "main.h"

#include "object_list_processor.h"
#include "room.h"
#include "behavior_data.h"
*/

#include <string>
#include <sstream>
#include <iomanip>
#include "xxhash64.h"
/*
#include "engine/hook_geo.h"
#include "engine/hook_dl.h"
#include "engine/hook_level.h"
#include "engine/hook_bhv.h"
#include "engine/hook_macro.h"
#include "engine/asset.h"
#include "player/players.h"

#include "engine/geo_layout.h"
#include "game/shadow.h"
#include "geo_commands.h"
*/

namespace oot
{
/*
	ExportDl::ExportDl(const Gfx* gfx, const char* name)
	{
	}

	ExportGeo::ExportGeo(const GeoLayout* geo, const char* name)
	{
		auto hash = XXHash64::hash(name, strlen(name), 0);

		oot::hook::geo::reg(geo, hash);
	}

	ExportBhv::ExportBhv(const BehaviorScript* bhv, const char* name)
	{
		auto hash = XXHash64::hash(name, strlen(name), 0);

		hook::bhv::reg(bhv, hash);
	}

	ExportMacro::ExportMacro(const MacroObject* macro, const u64 len, const char* name)
	{
		auto hash = oot::hook::macro::fingerprint(macro);

		hook::macro::reg((const MacroObject*)macro, hash);
	}

	ExportLevel::ExportLevel(const LevelScript* level, const u64 len, const char* name)
	{
		auto hash = XXHash64::hash(name, strlen(name), 0);

		hook::level::reg((const LevelCommand*)level, hash);
	}
	*/

	static FILE* g_logHandle = nullptr;

	static FILE* logHandle()
	{
		if(!g_logHandle)
		{
			g_logHandle = fopen("oot.log", "w");
		}
		return g_logHandle;
	}

	void log(const char* format, ...)
	{
		static char printBuffer[4096];
		va_list args;
		va_start(args, format);
		// TODO FIX vsprintf(printBuffer, format, args);

		fprintf(logHandle(), "%s", printBuffer);
		fflush(logHandle());

		va_end(args);
	}
} // namespace oot
