#pragma once

struct GraphicsContext;

namespace oot::gamestate
{
	class Base;
	class Global;
}

typedef oot::gamestate::Global GlobalContext;
typedef oot::gamestate::Base GameState;

namespace oot::gamestate::factory
{
	GameState* Global(GraphicsContext* gfxCtx);
}
