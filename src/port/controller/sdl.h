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
		void rescan(class Controllers* controllers);

		protected:
	};
} // namespace oot::hid