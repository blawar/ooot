#include "global.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "json.h"
#include "port/options.h"
#include "xxhash64.h"

#ifdef __SWITCH__
#include "pc/nx.h"
#endif

#if defined(__SWITCH__) && !defined(BUILD_NRO)
#define CONFIG_JSON_FILE "sv:/config.json"
#else
#define CONFIG_JSON_FILE "config.json"
#endif

void Set_Language(u8 language_id);

std::string languageGetString(Language id)
{
	switch(id)
	{
		case LANGUAGE_ENG:
			return "en";
		case LANGUAGE_SPA:
			return "es";
		case LANGUAGE_FRA:
			return "fr";
		case LANGUAGE_GER:
			return "de";
	}
	return "en";
}

Language languageGetId(const std::string& s)
{
	if(s == "en")
	{
		return LANGUAGE_ENG;
	}
	else if(s == "es")
	{
		return LANGUAGE_SPA;
	}
	else if(s == "fr")
	{
		return LANGUAGE_FRA;
	}
	else if(s == "de")
	{
		return LANGUAGE_GER;
	}
	return LANGUAGE_ENG;
}

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
					video().load(d);

					if(controls().cButtonsOnRightStick())
					{
						camera().useClassicCamera() = true;
					}

					if(controls().enableGyro() || controls().useDInput())
					{
						controls().useXInput() = false;
					}

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
			video().save(d, allocator);

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

		Video::Video()
		{
		}

		void Video::save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value container(rapidjson::Type::kObjectType);

			//json::setS64(container, "vsync", vsync(), allocator);
			//json::setBool(container, "doubleBuffer", doubleBuffer(), allocator);
			json::setU64(container, "fullscreenWidth", fullscreenWidth(), allocator);
			json::setU64(container, "fullscreenHeight", fullscreenHeight(), allocator);

			doc.AddMember(rapidjson::Value("Video", allocator), container, allocator);
		}

		void Video::load(rapidjson::Document& doc)
		{
			if(doc.HasMember("Video"))
			{
				auto& container = doc["Video"];

				//json::getS64(container, "vsync", vsync());
				//json::getBool(container, "doubleBuffer", doubleBuffer());
				json::getU64(container, "fullscreenWidth", fullscreenWidth());
				json::getU64(container, "fullscreenHeight", fullscreenHeight());
			}
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
			json::setBool(container, "enableDebugLevelSelect", enablDebugLevelSelect(), allocator);
			json::setBool(container, "restoreSaveConfirmation", restoreSaveConfirmation(), allocator);
			json::setBool(container, "pauseOnLostFocus", pauseOnLostFocus(), allocator);

			json::setU64(container, "pauseExitInputClearFrames", pauseExitInputClearFrames(), allocator);
			json::setU64(container, "textScrollSpeed", textScrollSpeed(), allocator);
			json::setU64(container, "fastForwardSpeed", fastForwardSpeed(), allocator);
			json::set(container, "language", languageGetString(language()), allocator);
			json::setU64(container, "framerate", getMaxFramerate(), allocator);

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
				json::getBool(container, "enableDebugLevelSelect", enablDebugLevelSelect());
				json::getBool(container, "restoreSaveConfirmation", restoreSaveConfirmation());
				json::getBool(container, "pauseOnLostFocus", pauseOnLostFocus());

				json::getU64(container, "pauseExitInputClearFrames", pauseExitInputClearFrames());
				json::getU64(container, "fastForwardSpeed", fastForwardSpeed());
				json::getU64(container, "textScrollSpeed", textScrollSpeed());

				std::string lang;
				json::get(container, "language", lang);
				setLanguage(languageGetId(lang));

				u64 framerate = 0;
				json::getU64(container, "framerate", framerate);
				setMaxFramerate(framerate);
			}
		}

		float Game::framerate() const
		{
			return getMaxFramerate();
		}

		void Game::setLanguage(Language id)
		{
			m_language = (Language)(id % LANGUAGE_MAX);
			Set_Language(m_language);
		}

		void Game::setNextLanguage()
		{
			switch(m_language)
			{
				case LANGUAGE_ENG:
					setLanguage(LANGUAGE_GER);
					break;
				case LANGUAGE_FRA:
					setLanguage(LANGUAGE_SPA);
					break;
				case LANGUAGE_SPA:
					setLanguage(LANGUAGE_ENG);
					break;
				case LANGUAGE_GER:
					setLanguage(LANGUAGE_FRA);
					break;
				default:
					setLanguage(LANGUAGE_ENG);
			}
			config().save();
		}

		void Game::setPrevLanguage()
		{
			switch(m_language)
			{
				case LANGUAGE_ENG:
					setLanguage(LANGUAGE_SPA);
					break;
				case LANGUAGE_SPA:
					setLanguage(LANGUAGE_FRA);
					break;
				case LANGUAGE_FRA:
					setLanguage(LANGUAGE_GER);
					break;
				case LANGUAGE_GER:
					setLanguage(LANGUAGE_ENG);
					break;
				default:
					setLanguage(LANGUAGE_ENG);
			}
			config().save();
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
			json::setFloat(container, "scalerX", scalerX(), allocator);
			json::setFloat(container, "scalerY", scalerY(), allocator);

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
				json::getFloat(container, "scalerX", scalerX());
				json::getFloat(container, "scalerY", scalerY());
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
			json::setBool(container, "cButtonsOnRightStick", cButtonsOnRightStick(), allocator);
			json::setBool(container, "enableGyro", enableGyro(), allocator);
			json::setBool(container, "useXInput", useXInput(), allocator);
			json::setBool(container, "useDInput", useDInput(), allocator);

			json::setBool(container, "invertLeftStickY", invertLeftStickY(), allocator);
			json::setBool(container, "invertRightStickY", invertRightStickY(), allocator);

			json::setBool(container, "invertLeftStickFirstPersonY", invertLeftStickFirstPersonY(), allocator);
			json::setBool(container, "invertRightStickFirstPersonY", invertRightStickFirstPersonY(), allocator);

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
				json::getBool(container, "cButtonsOnRightStick", cButtonsOnRightStick());
				json::getBool(container, "enableGyro", enableGyro());
				json::getBool(container, "useXInput", useXInput());
				json::getBool(container, "useDInput", useDInput());

				json::getBool(container, "invertLeftStickY", invertLeftStickY());
				json::getBool(container, "invertRightStickY", invertRightStickY());

				json::getBool(container, "invertLeftStickFirstPersonY", invertLeftStickFirstPersonY());
				json::getBool(container, "invertRightStickFirstPersonY", invertRightStickFirstPersonY());
			}
		}
	} // namespace options
} // namespace oot
