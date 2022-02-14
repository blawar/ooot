#include "tas.h"
#include <stdio.h>
#include "../player/players.h"
#include "../options.h"

static u64 g_counter = 0;
static  bool g_tasPlaying = false;

namespace sm64::hid
{
	bool isTasPlaying()
	{
		return g_tasPlaying;
	}

	namespace controller
	{
		class Tas : public Controller
		{
			public:
			Tas() : Controller()
			{
				fp = fopen("cont.tas", "rb");

				if(fp != NULL)
				{
					fread(&oot::config(), 1, sizeof(oot::config()), fp);
					g_tasPlaying = true;
				}
			}

			virtual ~Tas()
			{
				if(fp)
				{
					fclose(fp);
				}
			}

			void update()
			{
				if(fp != NULL)
				{
					auto r = fread(&m_state, 1, sizeof(m_state), fp);
					if (m_state.button)
					{
						int x = 0;
					}
				}
			}

			protected:
				FILE* fp;
		};
	} // namespace controller

	Tas::Tas() : Driver()
	{
	}

	Tas::~Tas()
	{
	}

	void Tas::scan(class Controllers* controllers)
	{
		if(!size())
		{
			auto controller = std::make_shared<controller::Tas>();
			m_controllers.push_back(controller);
			players().attach(controller, 0);
		}
	}

} // namespace sm64::hid
