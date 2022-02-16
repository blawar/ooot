#pragma once
#include <string>
#include <map>

namespace oot
{
	namespace options
	{
		class Camera
		{
			public:
			Camera();

			const float& distanceScaler() const
			{
				return m_distanceScaler;
			}
			float& distanceScaler()
			{
				return m_distanceScaler;
			}

			const float& yawReturnScaler() const
			{
				return m_yawReturnScaler;
			}
			float& yawReturnScaler()
			{
				return m_yawReturnScaler;
			}

			const bool disableDistanceClip() const;

			bool& setDisableDistanceClip()
			{
				return m_disableDistanceClip;
			}

			const bool& useClassicCamera() const
			{
				return m_useClassicCamera;
			}
			bool& useClassicCamera()
			{
				return m_useClassicCamera;
			}

			const bool& mousexInvert() const
			{
				return m_mousexInvert;
			}
			bool& mousexInvert()
			{
				return m_mousexInvert;
			}

			const bool& mouseyInvert() const
			{
				return m_mouseyInvert;
			}

			bool& mouseyInvert()
			{
				return m_mouseyInvert;
			}

			const float& mousexScaler() const
			{
				return m_mousexScaler;
			}

			float& mousexScaler()
			{
				return m_mousexScaler;
			}

			const float& mouseyScaler() const
			{
				return m_mouseyScaler;
			}

			float& mouseyScaler()
			{
				return m_mouseyScaler;
			}

			const bool levelLoaded() const;
			void setLevelLoaded();
			void unsetLevelLoaded();

			protected:
			float m_distanceScaler;
			float m_yawReturnScaler;
			bool m_disableDistanceClip;
			bool m_useClassicCamera;
			bool m_mousexInvert;
			bool m_mouseyInvert;
			float m_mousexScaler;
			float m_mouseyScaler;

			u8 junk[0x40 - 20];
		};

		static_assert(sizeof(Camera) == 0x40, "Camera size incorrect");

		class Cheats
		{
			public:
			Cheats();

			bool& invincible()
			{
				return m_invincible;
			}
			bool& moonJump()
			{
				return m_moonJump;
			}
			float& bowserAimAssist()
			{
				return m_bowserAimAssist;
			}

			float& speed()
			{
				return m_speed;
			}
			
			protected:
			bool m_invincible;
			bool m_moonJump;
			u8 padding[2];
			float m_bowserAimAssist;
			float m_speed;

			u8 junk[0x40 - (2 + 7 + 4)];
		};

		static_assert(sizeof(Cheats) == 0x40, "Cheats size incorrect");

#define MAX_MODS 16
		struct Mod
		{
			u64 hash;
			u8 enabled;
			u8 padding[7];
		};

		static_assert(sizeof(Mod) == 16, "Mod incorrect size");

		class Mods
		{
			public:
			void save();
			bool isEnabled(const std::string& name) const;
			void cleanup();
			static void set(const std::string& name, const u8 value);
			static std::map<std::string, bool>& dirs();

			protected:
			Mod m_mods[MAX_MODS];
			u8 m_padding[0x40];
		};

		class Game
		{
			public:
			Game();
			u8& overclock();
			u8 framerate();
			u8& setFramerate();
			float framerateScaler() const;
			u8 framerateScalerInv() const;

			bool& isGraphicsDisabled();
			void disableGraphics();
			bool& disableSound();
			bool& fullscreen();
			const bool mirror() const;
			bool& setMirror();
			bool& blindOwl();

			bool isFramePacing();
			void disableFramePacing();

			bool& recordTas();
			void  recordTas(bool enable);
			bool& forceMouse();

			protected:
			u8 m_overclock;
			u8 m_framerate;
			bool m_disableGraphics;
			bool m_disableSound;
			bool m_fullscreen;
			bool m_mirror;
			bool m_blindowl;
			bool m_paceFramesDisabled;
			bool m_recordTas;
			bool m_forceMouse;
			u8 m_padding[0x40 - 10];
		};

		static_assert(sizeof(Game) == 0x40, "Game Incorrect Size");

		class Base
		{
			public:
			Base();
			bool load();
			bool save();

			const Camera& camera() const
			{
				return m_camera;
			}
			Camera& camera()
			{
				return m_camera;
			}

			const Cheats& cheats() const
			{
				return m_cheats;
			}
			Cheats& cheats()
			{
				return m_cheats;
			}

			const Mods& mods() const
			{
				return m_mods;
			}
			Mods& mods()
			{
				return m_mods;
			}

			const Game& game() const
			{
				return m_game;
			}
			Game& game()
			{
				return m_game;
			}

			protected:
			Camera m_camera;
			Cheats m_cheats;
			Mods m_mods;
			Game m_game;

			u8 junk[0x400 - 0x80 - sizeof(Mods) - sizeof(Game)];
		};

		static_assert(sizeof(Base) == 0x400, "Option size incorrect");
	} // namespace options

	typedef options::Base Options;

	Options& config();
} // namespace oot