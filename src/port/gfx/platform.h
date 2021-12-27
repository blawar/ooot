#pragma once
#include "types.h"
#include <chrono>

extern void create_next_audio_buffer(s16* samples, u32 num_samples);
//void send_display_list(SPTask* spTask);
void game_loop_one_iteration();
void process_physics();
//void dispatch_audio_sptask(SPTask* spTask);

void game_init(void* arg);
void create_next_audio_buffer(s16* samples, u32 num_samples);

namespace sm64::gfx::platform
{
	class Base
	{
		public:
		virtual void set_fullscreen_changed_callback(void (*on_fullscreen_changed)(bool is_now_fullscreen)) = 0;
		virtual void set_fullscreen(bool enable, bool call_callback)					    = 0;
		virtual void get_dimensions(uint32_t* width, uint32_t* height)					    = 0;
		virtual void handle_events()									    = 0;
		virtual bool begin_frame()									    = 0;
		virtual bool end_frame()									    = 0;
		virtual void swap_buffers_begin()								    = 0;
		virtual void swap_buffers_end()									    = 0;

		void produce_one_frame()
		{
			begin_frame();
			game_loop_one_iteration();

			/*int samples_left = audio_api->buffered();
			u32 num_audio_samples = samples_left < audio_api->get_desired_buffered() ? 544 : 528;

#ifdef ENABLE_60FPS
			s16 audio_buffer[544 * 2];
			create_next_audio_buffer(audio_buffer, num_audio_samples);
			audio_api->play((const u8*)audio_buffer, num_audio_samples * 4);
#else
			s16 audio_buffer[544 * 2 * 2];
			for(int i = 0; i < 2; i++)
			{
				create_next_audio_buffer(audio_buffer + i * (num_audio_samples * 2), num_audio_samples);
			}
			audio_api->play((const u8*)audio_buffer, 2 * num_audio_samples * 4);
#endif
*/

			end_frame();
		}

		const std::chrono::microseconds& refreshInterval() const
		{
			return m_refreshInterval;
		}

		protected:
		std::chrono::microseconds m_refreshInterval;
	};
} // namespace sm64::gfx::platform
