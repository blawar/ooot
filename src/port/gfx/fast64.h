#pragma once
//#include "types.h"
#include <mutex>

struct GfxDimensions
{
	u32 width;
	u32 height;
	float aspect_ratio;
	float adjust_ratio;
};

extern GfxDimensions gfx_current_dimensions;

namespace sm64::gfx
{
	class Fast64
	{
		public:
		void start_frame();
		void end_frame();
		void run_loop();
		void run_paced_loop();
		void run_locked_loop();
		void physics_loop();
		void run(Gfx* commands);

		static Fast64* createContext();

		protected:
		std::mutex m_mutex;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_nextFrameTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_currentFrameStartTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_lastFrameTime;
		std::chrono::duration<u64, std::micro> m_lastFrameDuration;
		std::chrono::duration<u64, std::micro> m_lastSwapDuration;
		std::chrono::microseconds m_refreshRate;
	};
} // namespace sm64::gfx
