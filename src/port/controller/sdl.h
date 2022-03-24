#pragma once

#include "controllers.h"

namespace oot::hid
{
	class SDL : public Driver
	{
		public:
		SDL();
		virtual ~SDL();
		void scan(class Controllers* controllers) override;
		void resetBindings() override;

		protected:
	};
} // namespace oot::hid