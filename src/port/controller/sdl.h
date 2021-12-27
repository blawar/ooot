#pragma once

#include "controllers.h"

namespace sm64::hid
{
	class SDL : public Driver
	{
		public:
		SDL();
		virtual ~SDL();
		void scan(class Controllers* controllers) override;

		protected:
	};
} // namespace sm64::hid