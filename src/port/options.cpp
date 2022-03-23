#include "global.h"
#include "port/options.h"
#include <stdio.h>
#include "xxhash64.h"
#include <fstream>
#include "json.h"
#include <string.h>

#ifdef __SWITCH__
#include "pc/nx.h"
#endif

#if defined(__SWITCH__) && !defined(BUILD_NRO)
#define CONFIG_JSON_FILE "sv:/config.json"
#else
#define CONFIG_JSON_FILE "config.json"
#endif

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
		Base::Base() : m_camera(), m_cheats()
		{
			if(!load() || 1)
			{
				save();
			}
		}

		bool Base::load()
		{
#if defined(__SWITCH__) && !defined(BUILD_NRO)
			if(mountSaveData() != 0)
			{
				return false;
			}
#endif
			bool result = false;

			std::ifstream ifs(CONFIG_JSON_FILE, std::ifstream::in);

			if(ifs.is_open())
			{
				rapidjson::IStreamWrapper isw(ifs);
				rapidjson::Document d;
				d.ParseStream(isw);

				if(d.IsObject())
				{
					camera().load(d);
					cheats().load(d);
					controls().load(d);
					game().load(d);
					result = true;
				}
			}

			if(cheats().speed() < 1.0)
			{
				cheats().speed() = 1.0f;
			}
			else if(cheats().speed() > 5.0)
			{
				cheats().speed() = 5.0f;
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
#endif
			rapidjson::Document d;
			d.SetObject();

			rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

			camera().save(d, allocator);
			cheats().save(d, allocator);
			controls().save(d, allocator);
			game().save(d, allocator);

			if(!json::save(d, CONFIG_JSON_FILE))
			{
#if defined(__SWITCH__) && !defined(BUILD_NRO)
				unmountSaveData();
#endif
				return false;
			}

#if defined(__SWITCH__) && !defined(BUILD_NRO)
			commitSave();
			unmountSaveData();
#endif
			return true;
		}

		Game::Game()
		{
		}

		void Game::save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value container(rapidjson::Type::kObjectType);

			json::setBool(container, "graphicsEnabled", graphicsEnabled(), allocator);
			json::setBool(container, "audioEnabled", audioEnabled(), allocator);
			json::setBool(container, "fullscreen", fullscreen(), allocator);
			json::setBool(container, "mirror", mirror(), allocator);
			json::setBool(container, "blindOwl", blindOwl(), allocator);
			json::setBool(container, "recordTas", recordTas(), allocator);
			json::setBool(container, "forceMouse", forceMouse(), allocator);
			json::setBool(container, "enableExtendedOptionsMenu", enableExtendedOptionsMenu(), allocator);
			json::setBool(container, "enablDebugLevelSelect", enablDebugLevelSelect(), allocator);
			u64 m_pauseExitInputClearFrames;
			u64 m_textScrollSpeed;


			doc.AddMember(rapidjson::Value("game", allocator), container, allocator);
		}

		void Game::load(rapidjson::Document& doc)
		{
			if(doc.HasMember("game"))
			{
				auto& container = doc["game"];

				json::getBool(container, "graphicsEnabled", graphicsEnabled());
				json::getBool(container, "audioEnabled", audioEnabled());
				json::getBool(container, "fullscreen", fullscreen());
				json::getBool(container, "mirror", setMirror());
				json::getBool(container, "blindOwl", blindOwl());
				json::getBool(container, "recordTas", recordTas());
				json::getBool(container, "forceMouse", forceMouse());
				json::getBool(container, "enableExtendedOptionsMenu", enableExtendedOptionsMenu());
				json::getBool(container, "enablDebugLevelSelect", enablDebugLevelSelect());
			}
		}

		const bool Game::mirror() const
		{
			if(!m_mirror)
			{
				return false;
			}

			return true;
		}

		bool& Game::setMirror()
		{
			return m_mirror;
		}

		Camera::Camera()
		{
		}

		const bool Camera::disableDistanceClip() const
		{
			return m_disableDistanceClip;
		}

		void Camera::save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value container(rapidjson::Type::kObjectType);

			json::setBool(container, "disableDistanceClip", disableDistanceClip(), allocator);
			json::setBool(container, "useClassicCamera", useClassicCamera(), allocator);
			json::setFloat(container, "distanceScaler", distanceScaler(), allocator);

			doc.AddMember(rapidjson::Value("camera", allocator), container, allocator);
		}

		void Camera::load(rapidjson::Document& doc)
		{
			if(doc.HasMember("camera"))
			{
				auto& container = doc["camera"];
				json::getBool(container, "disableDistanceClip", setDisableDistanceClip());
				json::getBool(container, "useClassicCamera", useClassicCamera());
				json::getFloat(container, "distanceScaler", distanceScaler());
			}
		}

		Cheats::Cheats()
		{
		}

		void Cheats::save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
		{
			bool m_invincible;
			float m_speed;
			bool m_blindGerudoGuards;

			rapidjson::Value container(rapidjson::Type::kObjectType);

			json::setBool(container, "invincible", invincible(), allocator);
			json::setFloat(container, "speed", speed(), allocator);
			json::setBool(container, "blindGerudoGuards", blindGerudoGuards(), allocator);

			doc.AddMember(rapidjson::Value("cheats", allocator), container, allocator);
		}

		void Cheats::load(rapidjson::Document& doc)
		{
			if(doc.HasMember("cheats"))
			{
				auto& container = doc["cheats"];
				json::getBool(container, "invincible", invincible());
				json::getFloat(container, "speed", speed());
				json::getBool(container, "blindGerudoGuards", blindGerudoGuards());
			}
		}

		Controls::Controls()
		{
		}

		void Controls::save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value container(rapidjson::Type::kObjectType);

			json::setBool(container, "mousexInvert", mousexInvert(), allocator);
			json::setBool(container, "mouseyInvert", mouseyInvert(), allocator);

			json::setFloat(container, "mousexScaler", mousexScaler(), allocator);
			json::setFloat(container, "mouseyScaler", mouseyScaler(), allocator);

			json::set(container, "actionOverrideButton", hid::controller::getInputName(m_actionOverrideButton), allocator);
			json::setBool(container, "enableActionButtonOverride", enableActionButtonOverride(), allocator);

			json::setU64(container, "stickLeftDeadzone", stickLeftDeadzone(), allocator);
			json::setU64(container, "stickRightDeadzone", stickRightDeadzone(), allocator);

			json::setFloat(container, "gyroxScaler", gyroxScaler(), allocator);
			json::setFloat(container, "gyroyScaler", gyroyScaler(), allocator);
			json::setBool(container, "enableGyro", enableGyro(), allocator);
			json::setBool(container, "useXInput", useXInput(), allocator);

			doc.AddMember(rapidjson::Value("controls", allocator), container, allocator);
		}

		void Controls::load(rapidjson::Document& doc)
		{
			if(doc.HasMember("controls"))
			{
				auto& container = doc["controls"];
				json::getBool(container, "mousexInvert", mousexInvert());
				json::getBool(container, "mouseyInvert", mouseyInvert());

				json::getFloat(container, "mousexScaler", mousexScaler());
				json::getFloat(container, "mouseyScaler", mouseyScaler());

				std::string s;
				if(json::get(container, "actionOverrideButton", s))
				{
					m_actionOverrideButton = hid::controller::getInputValue(s);
				}
				json::getBool(container, "enableActionButtonOverride", enableActionButtonOverride());

				json::getU64(container, "stickLeftDeadzone", stickLeftDeadzone());
				json::getU64(container, "stickRightDeadzone", stickRightDeadzone());

				json::getFloat(container, "gyroxScaler", gyroxScaler());
				json::getFloat(container, "gyroyScaler", gyroyScaler());
				json::getBool(container, "enableGyro", enableGyro());

				json::getBool(container, "useXInput", useXInput());
			}
		}
	} // namespace options
} // namespace oot
