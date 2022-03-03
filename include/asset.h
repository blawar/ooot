#pragma once
#include "ultra64/gbi.h"
#include "z64file.h"

enum class symbol
{
	ASSET_NONE,
#include "asset_symbols.h"
	ASSET_MAX
};

struct SkelAnim;
struct FlexSkeletonHeader;
struct AnimationHeader;
struct CollisionHeader;
struct SkeletonHeader;
struct LinkAnimationHeader;
struct SkelCurveLimbList;
struct TransformUpdateIndex;
struct Vec3s;
struct MessageTableEntry;
union SceneCmd;
union CutsceneData;


extern u8* _map_grand_staticSegmentRomStart;

namespace oot::asset
{
	namespace text
	{
		MessageTableEntry* load(const symbol s);
	}

	namespace audio
	{
		namespace table
		{
			void* load(const symbol s);
		}
	}

	namespace gfx
	{
		Gfx* load(const symbol s);
	}

	namespace cutscene
	{
		namespace data
		{
			CutsceneData* load(const symbol s);
		}
	}

	namespace vtx
	{
		Vtx* load(const symbol s);
	}

	namespace texture
	{
		u8* load(const symbol s);

		RomFile loadFile(const symbol s);
	}

	namespace skel
	{
		SkelAnim* load(const symbol s);

		namespace header2
		{
			SkeletonHeader* load(const symbol s);
		}

		namespace header
		{
			FlexSkeletonHeader* load(const symbol s);
		}

		namespace curve_limb_list
		{
			SkelCurveLimbList* load(const symbol s);
		}
	}

	namespace anim
	{
		void* load(const symbol s);

		namespace header
		{
			AnimationHeader* load(const symbol s);
		}

		namespace link
		{
			namespace header
			{
				LinkAnimationHeader* load(const symbol s);
			}
		}
	}

	namespace v3s
	{
		Vec3s* load(const symbol s);
	}

	namespace collision
	{
		namespace header
		{
			CollisionHeader* load(const symbol s);
		}
	}

	namespace transform_update_index
	{
		TransformUpdateIndex* load(const symbol s);
	}

	namespace scene
	{
		namespace entry
		{
			SceneCmd* load(const symbol s);
		}
	}

	RomFile loadFile(const symbol s);
}
