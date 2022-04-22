#pragma once
//XInput controller class written by DaMarkov and blawar
#include <stdint.h>
#include "controllers.h"

namespace oot::hid
{
	namespace driver
	{
		class XInput : public Driver
		{
			public:
			XInput();
			virtual ~XInput();
			void scan(class Controllers* controllers) override;

			protected:
		};
	} // namespace drivers
}
