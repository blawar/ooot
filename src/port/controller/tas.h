#pragma once
#include "controllers.h"

namespace oot::hid
{
	class Tas : public Driver
	{
		public:
		Tas();
		virtual ~Tas();
		void scan(class Controllers* controllers) override;

		protected:
	};
} // namespace oot::hid