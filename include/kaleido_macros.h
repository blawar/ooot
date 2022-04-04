#pragma once

#define PAGE_COUNT 6
#if PAGE_COUNT == 6
#define PAGE_RADIUS_MULT 1.72
#elif PAGE_COUNT == 5
#define PAGE_RADIUS_MULT 1.37
#else
#define PAGE_RADIUS_MULT 1.0
#endif

// (f32)WREG(2) / 100.0f
#define PAGE_ACTIVE_Y ((f32)WREG(2) / 100.0f)

//(f32)WREG(3) / 100.0f
//#define PAGE_ACTIVE_X (93.55 * m_inradiusScaler)

#define PAUSE_LEFT_CARET WREG(16)
#define PAUSE_RIGHT_CARET WREG(17)
#define PAUSE_ANIMATION_STEPS WREG(6)
#define PAUSE_LEFT_CARET_MOVE WREG(25)
#define PAUSE_RIGHT_CARET_MOVE WREG(26)

#define PAUSE_LEFT_CARET_ORIGINAL_X (-175 + PAUSE_LEFT_CARET_MOVE)
#define PAUSE_RIGHT_CARET_ORIGINAL_X (155 + PAUSE_RIGHT_CARET_MOVE)

#define INRADIUS(width, sides) ((width / 2.0) * (1.0f / tanf(M_PI / sides)))

namespace oot::pause
{
	class Page
	{
		public:
		Page();
		virtual ~Page();

		virtual void initVerticies(GlobalContext* globalCtx) = 0;

		virtual void setDefaultCursor(u16& slot, u16& item, u16& namedItem);

		virtual void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active);
		virtual void dialogDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active);
		virtual void draw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active);

		virtual void postDraw(GlobalContext* globalCtx, GraphicsContext* gfxCtx, float inRadius, bool active);
		virtual void drawInfo(GlobalContext* globalCtx, GraphicsContext* gfxCtx);
		virtual void drawInfoText(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, const std::string& str);
		virtual void setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height);

		void update(u16 index, float angle);

		virtual u8* infoPanelTexture(u8 langId);
		virtual void setFlipAngle(float angle);
		float flipAngle() const;

		Vtx* auxVtx();
		Vtx* pageVtx();

		void setActive(bool active);
		bool active() const;
		bool is(PauseMenuPage id) const;

		u16 index() const
		{
			return m_index;
		}

		const s16& cursorPoint() const
		{
			return m_cursorPoint;
		}

		s16& cursorPoint()
		{
			return m_cursorPoint;
		}

		const s16& cursorX() const
		{
			return m_cursorX;
		}

		s16& cursorX()
		{
			return m_cursorX;
		}

		const s16& cursorY() const
		{
			return m_cursorY;
		}

		s16& cursorY()
		{
			return m_cursorY;
		}

		const u16& cursorItem() const
		{
			return m_cursorItem;
		}

		u16& cursorItem()
		{
			return m_cursorItem;
		}

		const u16& cursorSlot() const
		{
			return m_cursorSlot;
		}

		u16& cursorSlot()
		{
			return m_cursorSlot;
		}

		virtual PauseMenuPage id() const = 0;

		protected:
		u16 m_index;
		float m_angle;
		float m_flipAngle;
		std::unique_ptr<Vtx[]> m_pageVtx;
		std::unique_ptr<Vtx[]> m_auxVtx;
		s16 m_cursorPoint;
		s16 m_cursorX;
		s16 m_cursorY;
		u16 m_cursorItem;
		u16 m_cursorSlot;
		bool m_active;
	};

	namespace page
	{
		class Controller : public Page
		{
			public:
			Controller();

			PauseMenuPage id() const override
			{
				return PAUSE_CONTROLLER;
			}

			u8* infoPanelTexture(u8 langId) override;

			void drawInfo(GlobalContext* globalCtx, GraphicsContext* __gfxCtx) override;
			void initVerticies(GlobalContext* globalCtx) override;
			void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override;
			void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override;
			void setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height) override;
		};
	} // namespace page
} // namespace oot::pause

void KaleidoScope_SetPage(GlobalContext* globalCtx, u16 pageIndex);
Gfx* KaleidoScope_DrawPageSections(Gfx* gfx, Vtx* vertices, void** textures);
s16 KaleidoScope_SetPageVertices(GlobalContext* globalCtx, Vtx* vtx, s16 pageId, s16 arg3);
oot::pause::Page* KaleidoScope_FindPage(PauseMenuPage id);
oot::pause::Page* KaleidoScope_CurrentPage();
