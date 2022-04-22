#pragma once
#include "gamestate.h"

namespace oot::gamestate
{
	enum class SceneType
	{
		TITLE,
		GAME,
	};

	struct SceneSelectEntry
	{
		const char* name;
		SceneType type;
		s32 entranceIndex;
	}; // size = 0xC

	class Select : public Base
	{
		public:
		Select(GraphicsContext* gfxCtx);
		~Select();

		void init() override;
		void main() override;
		Base* next() override;

		void loadTitle(s32 entranceIndex);
		void loadGame(s32 entranceIndex);
		void updateMenu();
		void printMenu(GfxPrint* printer);
		void printLoadingMessage(GfxPrint* printer);
		void printAgeSetting(GfxPrint* printer, s32 age);
		void printCutsceneSetting(GfxPrint* printer, u16 csIndex);
		void drawMenu();
		void drawLoadingScreen();
		void draw();

		protected:
		View view;
		s32 currentScene;
		s32 pageDownIndex; // Index of pageDownStops
		s32 pageDownStops[7];
		char unk_1FC[0x0C];
		s32 opt;
		s32 topDisplayedScene; // The scene which is currently at the top of the screen
		char unk_210[0x0C];
		s32 verticalInputAccumulator;
		s32 verticalInput;
		s32 timerUp;
		s32 timerDown;
		s32 lockUp;
		s32 lockDown;
		s32 unk_234; // unused
	}; // size = 0x240

	namespace factory
	{
		GameState* Select(GraphicsContext* gfxCtx);
	}
} // namespace oot::gamestate
