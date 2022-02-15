#include "global.h"
#include "port/options.h"
#include <stdio.h>
#include "xxhash64.h"

#ifdef __SWITCH__
#include "pc/nx.h"
#endif

/*extern u32 frameCounter;
extern s32 sActSelectorMenuTimer;
extern s16 gMenuMode;
extern s8 goTogame;*/

namespace oot
{
	static Options* g_options = nullptr;

	Options& config()
	{
		if(!g_options)
		{
			g_options = new Options();
		}

		return *g_options;
	}

	namespace options
	{
		static std::map<std::string, bool>* g_modDirs = nullptr;

		static std::map<std::string, bool>& modDirs()
		{
			if(!g_modDirs)
			{
				g_modDirs = new std::map<std::string, bool>();
			}
			return *g_modDirs;
		}

		void Mods::save()
		{
			memset(&m_mods, 0, sizeof(m_mods));

			u32 i = 0;
			for(auto& d : modDirs())
			{
				if(i >= MAX_MODS)
				{
					break;
				}
				m_mods[i].hash	  = XXHash64::hash(d.first.c_str(), d.first.length(), 0);
				m_mods[i].enabled = d.second;
				i++;
			}
		}

		bool Mods::isEnabled(const std::string& name) const
		{
			auto hash = XXHash64::hash(name.c_str(), name.length(), 0);

			if(modDirs().count(name) != 0)
			{
				return modDirs()[name];
			}

			for(auto& i : m_mods)
			{
				if(i.hash == hash)
				{
					set(name, i.enabled);
					return i.enabled;
				}
			}

			if(name[0] == '~')
			{
				set(name, 0);
				return false;
			}
			else
			{
				set(name, 1);
				return true;
			}
		}

		void Mods::set(const std::string& name, const u8 value)
		{
			modDirs()[name] = value;
		}

		void Mods::cleanup()
		{
		}

		std::map<std::string, bool>& Mods::dirs()
		{
			return modDirs();
		}

		Base::Base() : m_camera(), m_cheats(), m_mods()
		{
			memset(junk, 0, sizeof(junk));
			load();
		}

		static bool _load(FILE* f, Base* obj)
		{
			if(!f)
			{
				return false;
			}

			fseek(f, 0, SEEK_END);

			auto sz = ftell(f);

			fseek(f, 0, SEEK_SET);

			auto bytesRead = fread(obj, 1, sizeof(Base), f);

			return true;
		}

		bool Base::load()
		{
#if defined(__SWITCH__) && !defined(BUILD_NRO)
			if(mountSaveData() != 0)
			{
				return false;
			}
			FILE* f = fopen("sv:/conf.bin", "rb");
#else
			FILE* f = fopen("conf.bin", "rb");
#endif
			bool result = false;

			if(f)
			{
				result = _load(f, this);

				if (cheats().speed() < 1.0)
				{
					cheats().speed() = 1.0f;
				}
				else if (cheats().speed() > 3.0)
				{
					cheats().speed() = 3.0f;
				}

				fclose(f);
			}
#if defined(__SWITCH__) && !defined(BUILD_NRO)
			unmountSaveData();
#endif
			return result;
		}

		bool Base::save()
		{
#if defined(__SWITCH__) && !defined(BUILD_NRO)
			if(mountSaveData() != 0)
			{
				return false;
			}
			FILE* f = fopen("sv:/conf.bin", "w+");
#else
			FILE* f = fopen("conf.bin", "w+");
#endif

			mods().save();

			if(!f)
			{
#if defined(__SWITCH__) && !defined(BUILD_NRO)
				unmountSaveData();
#endif
				return false;
			}

			fseek(f, SEEK_SET, 0);

			auto r = fwrite(this, 1, sizeof(Base), f);

			fclose(f);

#if defined(__SWITCH__) && !defined(BUILD_NRO)
			commitSave();
			unmountSaveData();
#endif
			return true;
		}

		Game::Game()
		{
			memset(this, 0, sizeof(*this));
		}

		u8& Game::overclock()
		{
			return m_overclock;
		}

		u8 Game::framerate()
		{
			return m_framerate;
		}

		u8& Game::setFramerate()
		{
			return m_framerate;
		}

		float Game::framerateScaler() const
		{
			return 0.5f;
		}

		u8 Game::framerateScalerInv() const
		{
			return 2;
		}

		bool& Game::fullscreen()
		{
			return m_fullscreen;
		}

		const bool Game::mirror() const
		{
			if(!m_mirror)
			{
				return false;
			}

			/*if(activeStageNo == 1)
			{
				return false;
			}

			if(GetMessageNo() != -1)
			{
				return false;
			}

			if(sActSelectorMenuTimer != 0)
			{
				return false;
			}

			if(gMenuMode != -1)
			{
				return false;
			}

			if(goTogame == 0)
			{
				return false;
			}*/

			return true;
		}

		bool& Game::setMirror()
		{
			return m_mirror;
		}

		bool& Game::blindOwl()
		{
			return m_blindowl;
		}

		bool& Game::isGraphicsDisabled()
		{
			return m_disableGraphics;
		}

		void Game::disableGraphics()
		{
			m_disableGraphics = true;
		}

		bool& Game::disableSound()
		{
			return m_disableSound;
		}

		bool Game::isFramePacing()
		{
			return !m_paceFramesDisabled;
		}

		void Game::disableFramePacing()
		{
			m_paceFramesDisabled = true;
		}

		bool& Game::recordTas()
		{
			return m_recordTas;
		}

		void Game::recordTas(bool enable)
		{
			m_recordTas = enable;
		}

		bool& Game::forceMouse()
		{
			return m_forceMouse;
		}

		Camera::Camera() : m_distanceScaler(1.0f), m_yawReturnScaler(1.0f), m_disableDistanceClip(false), m_useClassicCamera(false), m_mousexInvert(false), m_mouseyInvert(false), m_mousexScaler(4.0f), m_mouseyScaler(4.0f)
		{
			memset(junk, 0, sizeof(junk));
		}

		const bool Camera::disableDistanceClip() const
		{
			/*if (activeStageNo == LEVEL_WF)
			{
				return false;
			}*/

			return levelLoaded() && m_disableDistanceClip;
		}

		static u64 g_levelLoaded = 0;

		const bool Camera::levelLoaded() const
		{
			return true;
			//return g_levelLoaded && (frameCounter - g_levelLoaded) > 15 * FRAME_RATE_SCALER_INV;
		}

		void Camera::setLevelLoaded()
		{
			//g_levelLoaded = frameCounter;
		}

		void Camera::unsetLevelLoaded()
		{
			g_levelLoaded = 0;
		}

		Cheats::Cheats() : m_invincible(false), m_moonJump(false)
		{
			memset(junk, 0, sizeof(junk));
		}
	} // namespace options
} // namespace sm64
