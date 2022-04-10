#pragma once
#include "gamestate.h"

namespace oot::gamestate
{
	class TitleSetup : public Base
	{
		public:
		TitleSetup(GraphicsContext* gfxCtx);
		~TitleSetup();

		void main() override;
		void init() override;
		Base* next() override;
	};
} // namespace oot::gamestate

