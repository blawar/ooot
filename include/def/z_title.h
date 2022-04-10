#pragma once
#include "gamestate.h"
#include "view.h"

namespace oot::gamestate
{
	class Title : public Base
	{
		public:
		Title(GraphicsContext* gfxCtx);
		~Title();

		void init() override;
		void main() override;
		Base* next() override;

		protected:
		void calc();
		void setupView(f32 x, f32 y, f32 z);
		void draw();

		View view;
		u16 unk_1D4; // not used in mq dbg (some sort of timer that doesn't seem to affect anything)
		s16 coverAlpha;
		s16 addAlpha;	  // not used in mq dbg
		u16 visibleDuration; // not used in mq dbg
		s16 ult;
		s16 uls;
		char unk_1E0[0x01];
		u8 exit;
		char unk_1E2[0x06];
	};
} // namespace oot::gamestate
