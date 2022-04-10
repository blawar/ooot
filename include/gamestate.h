#pragma once
#include "gfx.h"
#include "padmgr.h"
#include "z64game.h"

namespace oot
{
	namespace gamestate
	{
		class Base
		{
			public:
			Base(GraphicsContext* gfxCtx);
			virtual ~Base();

			virtual void init() = 0;
			virtual void main() = 0;
			virtual Base* next() = 0;
			virtual void loadNext();

			void start();

			GraphicsContext* gfxCtx;
			Input input[4];
			TwoHeadArena tha;
			GameAlloc alloc;
			u32 running;
			Counter frames;
			u32 unk_A0;
		};
	} // namespace gamestate

	typedef gamestate::Base GameState;
} // namespace oot

typedef oot::gamestate::Base GameState;
