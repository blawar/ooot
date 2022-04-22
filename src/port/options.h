#pragma once
#include <string>
#include <map>
#include "json.h"
#include "port/controller/controller.h"

namespace oot
{
	namespace options
	{
		class Section
		{
			public:
			virtual void save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) = 0;
			virtual void load(rapidjson::Document& doc) = 0;
		};

		class Camera : public Section
		{
			public:
			Camera();

			void save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) override;
			void load(rapidjson::Document& doc) override;

			const float& distanceScaler() const
			{
				return m_distanceScaler;
			}
			float& distanceScaler()
			{
				return m_distanceScaler;
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

			protected:
			float m_distanceScaler = 1.0f;
			bool m_disableDistanceClip = false;
			bool m_useClassicCamera = false;
		};

		class Controls : public Section
		{
			public:
			Controls();

			void save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) override;
			void load(rapidjson::Document& doc) override;

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

			const float& gyroxScaler() const
			{
				return m_gyroxScaler;
			}

			float& gyroxScaler()
			{
				return m_gyroxScaler;
			}

			const float& gyroyScaler() const
			{
				return m_gyroyScaler;
			}

			float& gyroyScaler()
			{
				return m_gyroyScaler;
			}

			const hid::Button& actionOverrideButton() const
			{
				return m_actionOverrideButton;
			}

			hid::Button& actionOverrideButton()
			{
				return m_actionOverrideButton;
			}

			const bool& enableActionButtonOverride() const
			{
				return m_enableActionButtonOverride;
			}

			bool& enableActionButtonOverride()
			{
				return m_enableActionButtonOverride;
			}

			const u64& stickLeftDeadzone() const
			{
				return m_stickLeftDeadzone;
			}

			u64& stickLeftDeadzone()
			{
				return m_stickLeftDeadzone;
			}

			const u64& stickRightDeadzone() const
			{
				return m_stickLeftDeadzone;
			}

			u64& stickRightDeadzone()
			{
				return m_stickLeftDeadzone;
			}

			const bool& enableGyro() const
			{
				return m_enableGyro;
			}

			bool& enableGyro()
			{
				return m_enableGyro;
			}

			const bool& useXInput() const
			{
				return m_useXInput;
			}

			bool& useXInput()
			{
				return m_useXInput;
			}

			protected:
			bool m_mousexInvert = false;
			bool m_mouseyInvert = true;
			float m_mousexScaler = 4.0f;
			float m_mouseyScaler = 4.0f;
			hid::Button m_actionOverrideButton = hid::Button::B_BUTTON;
			bool m_enableActionButtonOverride = true;
			u64 m_stickLeftDeadzone = 20;
			u64 m_stickRightDeadzone = 20;
			float m_gyroxScaler = 20.0f;
			float m_gyroyScaler = 20.0f;
			bool m_enableGyro = true;
			bool m_useXInput = true;
		};

		class Cheats : public Section
		{
			public:
			Cheats();

			void save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) override;
			void load(rapidjson::Document& doc) override;

			bool& invincible()
			{
				return m_invincible;
			}

			float& speed()
			{
				return m_speed;
			}

			bool& blindGerudoGuards()
			{
				return m_blindGerudoGuards;
			}

			protected:
			bool m_invincible = false;
			float m_speed = 1.0f;
			bool m_blindGerudoGuards = false;
		};

		class Game : public Section
		{
			public:
			Game();

			void save(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) override;
			void load(rapidjson::Document& doc) override;

			const bool mirror() const;
			bool& setMirror();

			const bool& graphicsEnabled() const
			{
				return m_graphicsEnabled;
			}

			bool& graphicsEnabled()
			{
				return m_graphicsEnabled;
			}

			const bool& audioEnabled() const
			{
				return m_audioEnabled;
			}

			bool& audioEnabled()
			{
				return m_audioEnabled;
			}

			const bool& fullscreen() const
			{
				return m_fullscreen;
			}

			bool& fullscreen()
			{
				return m_fullscreen;
			}

			const bool& blindOwl() const
			{
				return m_blindOwl;
			}

			bool& blindOwl()
			{
				return m_blindOwl;
			}

			const bool& recordTas() const
			{
				return m_recordTas;
			}

			bool& recordTas()
			{
				return m_recordTas;
			}

			const bool& forceMouse() const
			{
				return m_forceMouse;
			}

			bool& forceMouse()
			{
				return m_forceMouse;
			}

			const bool& enableExtendedOptionsMenu() const
			{
				return m_enableExtendedOptionsMenu;
			}

			bool& enableExtendedOptionsMenu()
			{
				return m_enableExtendedOptionsMenu;
			}

			const bool& enablDebugLevelSelect() const
			{
				return m_enablDebugLevelSelect;
			}

			bool& enablDebugLevelSelect()
			{
				return m_enablDebugLevelSelect;
			}

			const u64& pauseExitInputClearFrames() const
			{
				return m_pauseExitInputClearFrames;
			}

			u64& pauseExitInputClearFrames()
			{
				return m_pauseExitInputClearFrames;
			}

			const u64& textScrollSpeed() const
			{
				return m_textScrollSpeed;
			}

			u64& textScrollSpeed()
			{
				return m_textScrollSpeed;
			}

			protected:
			bool m_graphicsEnabled = true;
			bool m_audioEnabled = true;
			bool m_fullscreen = true;
			bool m_mirror = false;
			bool m_blindOwl = false;
			bool m_recordTas = false;
			bool m_forceMouse = true;
			bool m_enableExtendedOptionsMenu = true;
			bool m_enablDebugLevelSelect = false;
			u64 m_pauseExitInputClearFrames = 2;
			u64 m_textScrollSpeed = 1;
		};

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

			const Controls& controls() const
			{
				return m_controls;
			}

			Controls& controls()
			{
				return m_controls;
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
			Controls m_controls;
			Game m_game;
		};
	} // namespace options

	typedef options::Base Options;

	Options& config();
} // namespace oot