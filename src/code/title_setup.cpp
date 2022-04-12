#define INTERNAL_SRC_CODE_TITLE_SETUP_C
#include "global.h"
#include <z64save.h>
#include "z64game.h"
#include "def/graph.h"
#include "def/title_setup.h"
#include "def/z_title.h"

namespace oot::gamestate
{
	TitleSetup::TitleSetup(GraphicsContext* gfxCtx) : Base(gfxCtx)
	{
	}

	TitleSetup::~TitleSetup()
	{
	}

	Base* TitleSetup::next()
	{
		return new TitleSetup(gfxCtx);
	}

	void TitleSetup::init()
	{
		osSyncPrintf("Zelda common data initalization\n"); // "Zelda common data initalization"
		gSaveContext.init();
		running = false;
		Graph_SetNextGameState(new Title(gfxCtx));
	}

	void TitleSetup::main()
	{
	}
} // namespace oot::gamestate
