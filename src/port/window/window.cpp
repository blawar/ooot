#include "../window.h"
#include <thread>
#include "z64.h"
#include "../options.h"

namespace platform::window
{
	Base::Base() : /*m_nextFrameTime(0), m_currentFrameStartTime(0), m_lastFrameTime(0),*/ m_lastFrameDuration(0), m_lastSwapDuration(0), dropped_frame(false), m_refreshInterval(0), m_targetFrameRate(60), m_ar_ratio(1.0f), m_ar(1.0f), m_window_width(1280), m_window_height(720)
	{
	}

	void Base::calc_sizes()
	{
		m_ar = (float)width() / (float)height();
		m_ar_ratio = m_ar / ((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT);
	}

	bool Base::run_paced_loop()
	{
		m_refreshInterval = std::chrono::microseconds(1000 * 1000 / 1);
		// const auto frameAlignment = (m_refreshRate - (m_lastFrameDuration % m_refreshRate)) / 2;
		// const std::chrono::time_point<std::chrono::steady_clock> targetFrameStart = m_nextFrameTime - MIN(m_lastFrameDuration + frameAlignment, m_lastSwapDuration);
		const std::chrono::time_point<std::chrono::high_resolution_clock> targetFrameStart = m_nextFrameTime - m_lastFrameDuration;

		auto timeDelta = std::chrono::duration_cast<std::chrono::microseconds>(targetFrameStart - std::chrono::high_resolution_clock::now());

		if(timeDelta <= std::chrono::microseconds(0))
		{
			dropped_frame = std::chrono::high_resolution_clock::now() > targetFrameStart + m_refreshInterval + std::chrono::milliseconds(2);

#if defined(_MSC_VER) && defined(DEBUG)
			static int dropped_frames = 0;
			static u64 frame_counter = 0;

			if(frame_counter++ % (60 * 3) == 0)
			{
				char buffer[128];
				float ms = m_lastSwapDuration.count() / 1000.0f;
				sprintf(buffer, "swap duration %2.2f ms\r\n", ms);
				OutputDebugString(buffer);
			}

			if(dropped_frame)
			{
				char buffer[128];
				int diff = (std::chrono::high_resolution_clock::now() - (targetFrameStart + m_refreshRate)).count() / 1000000;
				sprintf(buffer, "dropped frame %d, missed by %d ms\r\n", ++dropped_frames, diff);
				OutputDebugString(buffer);
			}
#endif

			if(dropped_frame)
			{
				if(timeDelta < m_refreshInterval * -4)
				{
					m_lastFrameDuration = std::chrono::duration<u64, std::micro>(0);
					m_nextFrameTime = std::chrono::high_resolution_clock::now();
					return true;
				}
			}

			
			m_currentFrameStartTime = std::chrono::high_resolution_clock::now();

			/*
			int samples_left = audio_api->buffered();
			u32 num_audio_samples = samples_left < audio_api->get_desired_buffered() ? 544 : 528;

#ifdef ENABLE_60FPS
			s16 audio_buffer[544 * 2];
			create_next_audio_buffer(audio_buffer, num_audio_samples);
			if(!config().game().disableSound())
			{
				audio_api->play((const u8*)audio_buffer, num_audio_samples * 4);
			}
#else
			s16 audio_buffer[544 * 2 * 2];
			for(int i = 0; i < 2; i++)
			{
				create_next_audio_buffer(audio_buffer + i * (num_audio_samples * 2), num_audio_samples);
			}
			if(!config().game().disableSound())
			{
				audio_api->play((const u8*)audio_buffer, 2 * num_audio_samples * 4);
			}
#endif
*/
			return true;
			
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::microseconds(500));
		}

		return false;
	}

	void Base::run()
	{
		while(1)
		{
			begin_frame();
			game_loop_one_iteration();
			end_frame();
		}
	}

	bool Base::begin_frame()
	{
		handle_events();
		if (oot::config().game().isFramePacing())
		{
			while (!run_paced_loop())
			{}
		}
		return !dropped_frame;
	}

	bool Base::end_frame()
	{
		m_lastFrameTime = std::chrono::high_resolution_clock::now();
		m_nextFrameTime += std::chrono::microseconds(1000 * 1000 / m_targetFrameRate);

		if(!dropped_frame)
		{
			const auto now = std::chrono::high_resolution_clock::now();
			m_lastFrameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_currentFrameStartTime);
			m_lastSwapDuration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - now);
		}

		return true;
	}
}
