#ifndef _DEBUG_H
#define _DEBUG_H

/*#include "engine/hook_macro.h"
#include "engine/hook_geo.h"
#include "engine/hook_dl.h"*/
#include <stdarg.h>

#ifndef DISABLE_HOOKS
#define EXPORT_DL(v) static ExportDl export_##v(v, #v)
#define EXPORT_GEO(v)                                                                                                                                                                                                                                          \
	static ExportGeo export_##v(::v, #v);                                                                                                                                                                                                                  \
	static const GeoLayout* g_##v = nullptr;                                                                                                                                                                                                               \
	const GeoLayout* v()                                                                                                                                                                                                                                   \
	{                                                                                                                                                                                                                                                      \
		if(!g_##v)                                                                                                                                                                                                                                     \
		{                                                                                                                                                                                                                                              \
			g_##v = oot::hook::geo::apply(::v, hook::geo::Id::v);                                                                                                                                                                                 \
		}                                                                                                                                                                                                                                              \
		return g_##v;                                                                                                                                                                                                                                  \
	}
#define EXPORT_BHV(v)                                                                                                                                                                                                                                          \
	static ExportBhv export_##v(::v, #v);                                                                                                                                                                                                                  \
	static const BehaviorScript* g_##v = nullptr;                                                                                                                                                                                                          \
	const BehaviorScript* v()                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		if(!g_##v)                                                                                                                                                                                                                                     \
		{                                                                                                                                                                                                                                              \
			g_##v = oot::hook::bhv::apply(::v, hook::bhv::Id::v);                                                                                                                                                                                 \
		}                                                                                                                                                                                                                                              \
		return g_##v;                                                                                                                                                                                                                                  \
	}
#define EXPORT_MACRO(v)                                                                                                                                                                                                                                        \
	static ExportMacro export_##v(::v, sizeof(::v), #v);                                                                                                                                                                                                   \
	static const MacroObject* g_##v = nullptr;                                                                                                                                                                                                             \
	const MacroObject* v()                                                                                                                                                                                                                                 \
	{                                                                                                                                                                                                                                                      \
		if(!g_##v)                                                                                                                                                                                                                                     \
		{                                                                                                                                                                                                                                              \
			g_##v = oot::hook::macro::apply(::v, hook::macro::Id::v);                                                                                                                                                                             \
		}                                                                                                                                                                                                                                              \
		return g_##v;                                                                                                                                                                                                                                  \
	}
//#define EXPORT_MACRO(v) static const MacroObject* g_##v = nullptr; const MacroObject* v() { if(!g_##v) { g_##v = oot::hook::macro::apply(nullptr, hook::macro::Id::v); } return g_##v; }
#define EXPORT_LEVEL(v) static ExportLevel export_##v(::v, sizeof(::v), #v)
#else
#define EXPORT_DL(v)
#define EXPORT_GEO(v)                                                                                                                                                                                                                                          \
	const GeoLayout* v()                                                                                                                                                                                                                                   \
	{                                                                                                                                                                                                                                                      \
		return ::v;                                                                                                                                                                                                                                    \
	}
#define EXPORT_BHV(v)                                                                                                                                                                                                                                          \
	const BehaviorScript* v()                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                      \
		return ::v;                                                                                                                                                                                                                                    \
	}
#define EXPORT_MACRO(v)                                                                                                                                                                                                                                        \
	const MacroObject* v()                                                                                                                                                                                                                                 \
	{                                                                                                                                                                                                                                                      \
		return ::v;                                                                                                                                                                                                                                    \
	}
#define EXPORT_LEVEL(v)
#endif

#define EXTERN_u8(X) extern const u8 X[];
#define EXTERN_s16(X) extern const s16 X[];
#define EXTERN_Gfx(X) extern const Gfx X[];
#define EXTERN_Vtx(X) extern const Vtx X[];
#define EXTERN_Trajectory(X) extern const Trajectory X[];
#define EXTERN_MovtexQuadCollection(X) extern const MovtexQuadCollection X[];
#define EXTERN_Gfx(X) extern const Gfx X[];
#define EXTERN_Collision(X) extern const Collision X[];
#define EXTERN_GeoLayout(X) extern const GeoLayout X[];
#define EXTERN_LevelScript(X) extern const LevelScript X[];
#define EXTERN_MacroObject(X)                                                                                                                                                                                                                                  \
	namespace oot::macro                                                                                                                                                                                                                                  \
	{                                                                                                                                                                                                                                                      \
		const MacroObject* X();                                                                                                                                                                                                                        \
	}

namespace oot
{
	void log(const char* format, ...);
	void closeExportFile();

	/*struct ExportDl
	{
		ExportDl(const Gfx* gfx, const char* name);
	};*/

	/*struct ExportGeo
	{
		ExportGeo(const GeoLayout* geo, const char* name);
	};

	struct ExportBhv
	{
		ExportBhv(const BehaviorScript* bhv, const char* name);
	};

	struct ExportLevel
	{
		ExportLevel(const LevelScript* bhv, const u64 len, const char* name);
	};

	struct ExportMacro
	{
		ExportMacro(const MacroObject* macro, const u64 len, const char* name);
	};*/
} // namespace oot

#endif /* _DEBUG_H */
