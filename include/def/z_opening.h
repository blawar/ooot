#pragma once
#include "gamestate.h"
#include "view.h"
#include "z64game.h"
#include "def/z_opening.h"

namespace oot::gamestate
{
	class Opening : public Base
	{
		public:
		Opening(GraphicsContext* gfxCtx);
		~Opening();

		void init() override;
		void main() override;
		Base* next() override;

		protected:
		View view;
	}; // size = 0x1D0
} // namespace oot::gamestate