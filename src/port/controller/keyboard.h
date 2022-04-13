#pragma once
#include "controllers.h"

#define MAX_KEY_STATE (16 * 1024)

namespace oot::hid
{
	class Keyboard : public Driver
	{
		public:
		Keyboard();
		virtual ~Keyboard();
		void scan(class Controllers* controllers) override;
		void update() override;
		void resetBindings() override;
		bool defaultOnly() override
		{
			return true;
		}

		protected:
	};
} // namespace oot::hid