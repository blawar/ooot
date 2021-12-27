#pragma once
#include "controllers.h"

namespace sm64::hid
{
	class Tas : public Driver
	{
		public:
		Tas();
		virtual ~Tas();
		void scan(class Controllers* controllers) override;

		protected:
	};
} // namespace sm64::hid