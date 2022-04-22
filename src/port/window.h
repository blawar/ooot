#pragma once
#include "ultra64/types.h"
#include <chrono>
#include <memory>

namespace platform::window
{
	class Base
	{
		public:
			Base();
		virtual void set_fullscreen_changed_callback(void (*on_fullscreen_changed)(bool is_now_fullscreen)) = 0;
		virtual void set_fullscreen(bool enable, bool call_callback)					    = 0;
		virtual void get_dimensions(uint32_t* width, uint32_t* height)					    = 0;
		virtual void handle_events()									    = 0;
		virtual bool begin_frame();
		virtual bool end_frame();
		virtual void swap_buffers_begin()								    = 0;
		virtual void swap_buffers_end()									    = 0;
		virtual void resize(long width, long height)						= 0;

		void calc_sizes();

		const std::chrono::microseconds& refreshInterval() const
		{
			return m_refreshInterval;
		}

		bool wait_frame_ready();

		void setTargetFrameRate(size_t rate) { m_targetFrameRate = rate; };
		float ar() { return m_ar; }
		float ar_ratio() { return m_ar_ratio; }
		unsigned int width() { return m_window_width; }
		unsigned int height() { return m_window_height; }

		protected:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_nextFrameTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_currentFrameStartTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_lastFrameTime;
		std::chrono::duration<u64, std::micro> m_lastFrameDuration;
		std::chrono::duration<u64, std::micro> m_lastSwapDuration;
		bool dropped_frame;
		std::chrono::microseconds m_refreshInterval;
		size_t m_targetFrameRate;
		float m_ar_ratio;
		float m_ar;
		unsigned int m_window_width;
		unsigned int m_window_height;
	};

	std::unique_ptr<Base> create(const char* name, bool fullscreen = false);
} // namespace sm64::gfx::platform

extern "C" {
	void gfx_resize(long width, long height);
}