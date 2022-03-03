#include "asset.h"

namespace oot::asset
{
	namespace text
	{
		MessageTableEntry* load(const symbol s)
		{
			return nullptr;
		}
	}

	namespace audio
	{
		namespace table
		{
			void* load(const symbol s)
			{
				return nullptr;
			}
		}
	}

	namespace gfx
	{
		Gfx* load(const symbol s)
		{
			return nullptr;
		}
	}

	namespace cutscene
	{
		namespace data
		{
			CutsceneData* load(const symbol s)
			{
				return nullptr;
			}
		}
	}

	namespace vtx
	{
		Vtx* load(const symbol s)
		{
			return nullptr;
		}
	}

	namespace texture
	{
		u8* load(const symbol s)
		{
			return nullptr;
		}

		RomFile loadFile(const symbol s)
		{
			return RomFile();
		}
	}

	namespace skel
	{
		SkelAnim* load(const symbol s)
		{
			return nullptr;
		}

		namespace header2
		{
			SkeletonHeader* load(const symbol s)
			{
				return nullptr;
			}
		}

		namespace header
		{
			FlexSkeletonHeader* load(const symbol s)
			{
				return nullptr;
			}
		}

		namespace curve_limb_list
		{
			SkelCurveLimbList* load(const symbol s)
			{
				return nullptr;
			}
		}
	}

	namespace anim
	{
		void* load(const symbol s)
		{
			return nullptr;
		}

		namespace header
		{
			AnimationHeader* load(const symbol s)
			{
				return nullptr;
			}
		}

		namespace link
		{
			namespace header
			{
				LinkAnimationHeader* load(const symbol s)
				{
					return nullptr;
				}
			}
		}
	}

	namespace v3s
	{
		Vec3s* load(const symbol s)
		{
			return nullptr;
		}
	}

	namespace collision
	{
		namespace header
		{
			CollisionHeader* load(const symbol s)
			{
				return nullptr;
			}
		}
	}

	namespace transform_update_index
	{
		TransformUpdateIndex* load(const symbol s)
		{
			return nullptr;
		}
	}

	namespace scene
	{
		namespace entry
		{
			SceneCmd* load(const symbol s)
			{
				return nullptr;
			}
		}
	}

	RomFile loadFile(const symbol s)
	{
		return RomFile();
	}
}
