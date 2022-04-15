#define INTERNAL_SRC_OVERLAYS_MISC_OVL_KALEIDO_SCOPE_Z_KALEIDO_SCOPE_PAL_C
#include "actor_common.h"
#include "framerate.h"
#include "gfxprint.h"
#include "hack.h"
#include "kaleido.h"
#include "kaleido_macros.h"
#include "port/controller/controller.h"
#include "port/options.h"
#include "segment_symbols.h"
#include "textures/icon_item_24_static/icon_item_24_static.h"
#include "textures/icon_item_dungeon_static/icon_item_dungeon_static.h"
#include "textures/icon_item_field_static/icon_item_field_static.h"
#include "textures/icon_item_fra_static/icon_item_fra_static.h"
#include "textures/icon_item_gameover_static/icon_item_gameover_static.h"
#include "textures/icon_item_ger_static/icon_item_ger_static.h"
#include "textures/icon_item_nes_static/icon_item_nes_static.h"
#include "textures/icon_item_static/icon_item_static.h"
#include "textures/item_name_static/item_name_static.h"
#include "textures/map_48x85_static/map_48x85_static.h"
#include "textures/map_name_static/map_name_static.h"
#include "vt.h"
#include "z64audio.h"
#include "z_kaleido_scope.h"
#include "def/PreRender.h"
#include "def/audio.h"
#include "def/audio_bank.h"
#include "def/audio_command.h"
#include "def/createmesgqueue.h"
#include "def/gfxprint.h"
#include "def/graph.h"
#include "def/inventory.h"
#include "def/sleep.h"
#include "def/sys_matrix.h"
#include "def/z_bgcheck.h"
#include "def/z_lib.h"
#include "def/z_map_exp.h"
#include "def/z_map_mark.h"
#include "def/z_opening.h"
#include "def/z_parameter.h"
#include "def/z_play.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"
#include "def/z_scene.h"
#include "def/z_std_dma.h"
#include "def/z_view.h"

#define ACCUM_INC 4.0f
#define ACCUM_TOTAL 64.0f

static_assert((int)(DEGTORAD(180) * 100) == 314, "DEGTORAD assert failed");

Gfx* KaleidoScope_DrawPageSections(Gfx* gfx, Vtx* vertices, void** textures);
s16 KaleidoScope_SetPageVertices(GlobalContext* globalCtx, Vtx* vtx, s16 pageId, s16 arg3);

static s16 gUknItemVtxIndexLUT[] = {0, 4, 8, 12, 24, 32, 56};

static s16 D_8082B12C[] = {-114, 12, 44, 76};

static u8 D_8082B134[] = {1, 5, 9, 13};

static s16 D_8082B138[] = {
    74, 74, 46, 18, 18, 46, -108, -90, -72, -54, -36, -18, -108, -90, -72, -54, -36, -18, 20, 46, 72, -110, -86, -110, -54, -98, -86, -74, -62, -50, -38, -26, -14, -98, -86, -74, -62, -50, -38, -26, -14, -88, -81, -72, -90, -83, -74,
};

static s16 D_8082B198[] = {
    38, 6, -12, 6, 38, 56, -20, -20, -20, -20, -20, -20, 2, 2, 2, 2, 2, 2, -46, -46, -46, 58, 58, 34, 58, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, -52, 34, 34, 34, 36, 36, 36,
};

static s16 D_8082B1F8[] = {
    24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 48, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
};

u16 PAUSE_NEXT_PAGE_INDEX(u16 curIndex, u16 mode)
{
	const s8 dir = (mode & 1) ? -1 : 1;

	if(dir < 0 && curIndex == 0)
	{
		return PAGE_COUNT - 1;
	}

	return (curIndex + dir) % PAGE_COUNT;
}

static void* sEquipmentFRATexs[] = {
    gPauseEquipment00FRATex, gPauseEquipment01Tex, gPauseEquipment02Tex,    gPauseEquipment03Tex, gPauseEquipment04Tex, gPauseEquipment10FRATex, gPauseEquipment11Tex, gPauseEquipment12Tex,
    gPauseEquipment13Tex,    gPauseEquipment14Tex, gPauseEquipment20FRATex, gPauseEquipment21Tex, gPauseEquipment22Tex, gPauseEquipment23Tex,	 gPauseEquipment24Tex,
};
static void* sSelectItemFRATexs[] = {
    gPauseSelectItem00FRATex, gPauseSelectItem01Tex, gPauseSelectItem02Tex,    gPauseSelectItem03Tex, gPauseSelectItem04Tex, gPauseSelectItem10FRATex, gPauseSelectItem11Tex, gPauseSelectItem12Tex,
    gPauseSelectItem13Tex,    gPauseSelectItem14Tex, gPauseSelectItem20FRATex, gPauseSelectItem21Tex, gPauseSelectItem22Tex, gPauseSelectItem23Tex,    gPauseSelectItem24Tex,
};
static void* sMapFRATexs[] = {
    gPauseMap00Tex, gPauseMap01Tex, gPauseMap02Tex, gPauseMap03Tex, gPauseMap04Tex, gPauseMap10FRATex, gPauseMap11Tex, gPauseMap12Tex, gPauseMap13Tex, gPauseMap14Tex, gPauseMap20Tex, gPauseMap21Tex, gPauseMap22Tex, gPauseMap23Tex, gPauseMap24Tex,
};
static void* sQuestStatusFRATexs[] = {
    gPauseQuestStatus00Tex, gPauseQuestStatus01Tex, gPauseQuestStatus02Tex, gPauseQuestStatus03Tex, gPauseQuestStatus04Tex, gPauseQuestStatus10FRATex, gPauseQuestStatus11Tex, gPauseQuestStatus12Tex,
    gPauseQuestStatus13Tex, gPauseQuestStatus14Tex, gPauseQuestStatus20Tex, gPauseQuestStatus21Tex, gPauseQuestStatus22Tex, gPauseQuestStatus23Tex,    gPauseQuestStatus24Tex,
};
static void* sSaveFRATexs[] = {
    gPauseSave00FRATex, gPauseSave01Tex, gPauseSave02Tex,    gPauseSave03Tex, gPauseSave04Tex, gPauseSave10FRATex, gPauseSave11Tex, gPauseSave12Tex,
    gPauseSave13Tex,	gPauseSave14Tex, gPauseSave20FRATex, gPauseSave21Tex, gPauseSave22Tex, gPauseSave23Tex,	   gPauseSave24Tex,
};

static void* sEquipmentGERTexs[] = {
    gPauseEquipment00GERTex, gPauseEquipment01Tex, gPauseEquipment02Tex,    gPauseEquipment03Tex, gPauseEquipment04Tex, gPauseEquipment10GERTex, gPauseEquipment11Tex, gPauseEquipment12Tex,
    gPauseEquipment13Tex,    gPauseEquipment14Tex, gPauseEquipment20GERTex, gPauseEquipment21Tex, gPauseEquipment22Tex, gPauseEquipment23Tex,	 gPauseEquipment24Tex,
};
static void* sSelectItemGERTexs[] = {
    gPauseSelectItem00GERTex, gPauseSelectItem01Tex, gPauseSelectItem02Tex,    gPauseSelectItem03Tex, gPauseSelectItem04Tex, gPauseSelectItem10GERTex, gPauseSelectItem11Tex, gPauseSelectItem12Tex,
    gPauseSelectItem13Tex,    gPauseSelectItem14Tex, gPauseSelectItem20GERTex, gPauseSelectItem21Tex, gPauseSelectItem22Tex, gPauseSelectItem23Tex,    gPauseSelectItem24Tex,
};
static void* sMapGERTexs[] = {
    gPauseMap00Tex, gPauseMap01Tex, gPauseMap02Tex, gPauseMap03Tex, gPauseMap04Tex, gPauseMap10GERTex, gPauseMap11Tex, gPauseMap12Tex, gPauseMap13Tex, gPauseMap14Tex, gPauseMap20Tex, gPauseMap21Tex, gPauseMap22Tex, gPauseMap23Tex, gPauseMap24Tex,
};
static void* sQuestStatusGERTexs[] = {
    gPauseQuestStatus00Tex, gPauseQuestStatus01Tex, gPauseQuestStatus02Tex, gPauseQuestStatus03Tex, gPauseQuestStatus04Tex, gPauseQuestStatus10GERTex, gPauseQuestStatus11Tex, gPauseQuestStatus12Tex,
    gPauseQuestStatus13Tex, gPauseQuestStatus14Tex, gPauseQuestStatus20Tex, gPauseQuestStatus21Tex, gPauseQuestStatus22Tex, gPauseQuestStatus23Tex,    gPauseQuestStatus24Tex,
};
static void* sSaveGERTexs[] = {
    gPauseSave00Tex, gPauseSave01Tex, gPauseSave02Tex,	  gPauseSave03Tex, gPauseSave04Tex, gPauseSave10GERTex, gPauseSave11Tex, gPauseSave12Tex,
    gPauseSave13Tex, gPauseSave14Tex, gPauseSave20GERTex, gPauseSave21Tex, gPauseSave22Tex, gPauseSave23Tex,	gPauseSave24Tex,
};

static void* sEquipmentENGTexs[] = {
    gPauseEquipment00Tex, gPauseEquipment01Tex, gPauseEquipment02Tex, gPauseEquipment03Tex, gPauseEquipment04Tex, gPauseEquipment10ENGTex, gPauseEquipment11Tex, gPauseEquipment12Tex,
    gPauseEquipment13Tex, gPauseEquipment14Tex, gPauseEquipment20Tex, gPauseEquipment21Tex, gPauseEquipment22Tex, gPauseEquipment23Tex,	   gPauseEquipment24Tex,
};
static void* sSelectItemENGTexs[] = {
    gPauseSelectItem00ENGTex, gPauseSelectItem01Tex, gPauseSelectItem02Tex,    gPauseSelectItem03Tex, gPauseSelectItem04Tex, gPauseSelectItem10ENGTex, gPauseSelectItem11Tex, gPauseSelectItem12Tex,
    gPauseSelectItem13Tex,    gPauseSelectItem14Tex, gPauseSelectItem20ENGTex, gPauseSelectItem21Tex, gPauseSelectItem22Tex, gPauseSelectItem23Tex,    gPauseSelectItem24Tex,
};
static void* sMapENGTexs[] = {
    gPauseMap00Tex, gPauseMap01Tex, gPauseMap02Tex, gPauseMap03Tex, gPauseMap04Tex, gPauseMap10ENGTex, gPauseMap11Tex, gPauseMap12Tex, gPauseMap13Tex, gPauseMap14Tex, gPauseMap20Tex, gPauseMap21Tex, gPauseMap22Tex, gPauseMap23Tex, gPauseMap24Tex,
};
static void* sQuestStatusENGTexs[] = {
    gPauseQuestStatus00ENGTex, gPauseQuestStatus01Tex, gPauseQuestStatus02Tex,	  gPauseQuestStatus03Tex, gPauseQuestStatus04Tex, gPauseQuestStatus10ENGTex, gPauseQuestStatus11Tex, gPauseQuestStatus12Tex,
    gPauseQuestStatus13Tex,    gPauseQuestStatus14Tex, gPauseQuestStatus20ENGTex, gPauseQuestStatus21Tex, gPauseQuestStatus22Tex, gPauseQuestStatus23Tex,    gPauseQuestStatus24Tex,
};
static void* sSaveENGTexs[] = {
    gPauseSave00Tex, gPauseSave01Tex, gPauseSave02Tex, gPauseSave03Tex, gPauseSave04Tex, gPauseSave10ENGTex, gPauseSave11Tex, gPauseSave12Tex,
    gPauseSave13Tex, gPauseSave14Tex, gPauseSave20Tex, gPauseSave21Tex, gPauseSave22Tex, gPauseSave23Tex,    gPauseSave24Tex,
};

void* sGameOverTexs[] = {
    gPauseSave00Tex, gPauseSave01Tex, gPauseSave02Tex, gPauseSave03Tex, gPauseSave04Tex, gPauseGameOver10Tex, gPauseSave11Tex, gPauseSave12Tex,
    gPauseSave13Tex, gPauseSave14Tex, gPauseSave20Tex, gPauseSave21Tex, gPauseSave22Tex, gPauseSave23Tex,     gPauseSave24Tex,
};

static void* sEquipmentTexs[] = {
    sEquipmentENGTexs,
    sEquipmentGERTexs,
    sEquipmentFRATexs,
};

static void* sSelectItemTexs[] = {
    sSelectItemENGTexs,
    sSelectItemGERTexs,
    sSelectItemFRATexs,
};

static void* sMapTexs[] = {
    sMapENGTexs,
    sMapGERTexs,
    sMapFRATexs,
};

static void* sQuestStatusTexs[] = {
    sQuestStatusENGTexs,
    sQuestStatusGERTexs,
    sQuestStatusFRATexs,
};

static void* sSaveTexs[] = {
    sSaveENGTexs,
    sSaveGERTexs,
    sSaveFRATexs,
};

void KaleidoScope_UpdateCursorSize(GlobalContext* globalCtx);

s16 D_8082AAEC[] = {
    32, 112, 32, 48, 32, 32, 32, 48, 32, 64, 32, 48, 48, 48, 48, 64, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 80, 64,
};

s16 D_8082AB2C[] = {
    24, 72, 13, 22, 19, 20, 19, 27, 14, 26, 22, 21, 49, 32, 45, 60, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 32, 8,
};

// clang-format off
static u8 gButtonStates[][5] = {
    {BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED},
	{BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED},
	{BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED},
    {BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED},
	{BTN_ENABLED, BTN_DISABLED, BTN_DISABLED, BTN_DISABLED, BTN_ENABLED},
	{BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED},

    {BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED},
	{BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_ENABLED, BTN_DISABLED},

};
// clang-format on

static s16 D_8082AB8C = 0;
static s16 D_8082AB90 = 0;
static s16 D_8082AB94 = 0;
static s16 D_8082AB98 = 255;

static s16 D_8082AB9C = 255;
static s16 D_8082ABA0 = 0;
static s16 D_8082ABA4 = 0;

static s16 sInDungeonScene = false;

Vec2f rotate(const Vec2f v, double angle)
{
	double cs = cos(angle);
	double sn = sin(angle);

	return {(float)(v.x * cs - v.y * sn), (float)(v.x * sn + v.y * cs)};
}

namespace oot::pause
{
	Page::Page() : m_index(0), m_angle(0), m_flipAngle(160.0f), m_pageVtx(nullptr), m_auxVtx(nullptr), m_cursorPoint(0), m_cursorX(0), m_cursorY(0), m_cursorItem(0), m_cursorSlot(0), m_active(false)
	{
	}

	Page::~Page()
	{
	}

	void Page::setDefaultCursor(u16& slot, u16& item, u16& namedItem)
	{
	}

	void Page::preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active)
	{
	}

	void Page::dialogDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		auto r = m_angle != 0.0f ? rotate({0, -inRadius}, DEGTORAD(m_angle)) : Vec2f({0, -inRadius});

		Matrix_Translate(r.x, PAGE_ACTIVE_Y, r.y, MTXMODE_NEW);
		Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
		Matrix_RotateY(-DEGTORAD(m_angle), MTXMODE_APPLY);

		if(pauseCtx->unk_204 != 0.0f)
		{
			Matrix_RotateX(pauseCtx->unk_204 / -100.0f, MTXMODE_APPLY);
		}

		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(__gfxCtx, __FILE__, __LINE__), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	void Page::draw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		auto r = m_angle != 0.0f ? rotate({0, -inRadius}, DEGTORAD(m_angle)) : Vec2f({0, -inRadius});

		Matrix_Translate(r.x, PAGE_ACTIVE_Y, r.y, MTXMODE_NEW);
		Matrix_Scale(0.78f, 0.78f, 0.78f, MTXMODE_APPLY);
		Matrix_RotateY(-DEGTORAD(m_angle), MTXMODE_APPLY);

		if(flipAngle() != 0.0f)
		{
			Matrix_RotateX(flipAngle() / -100.0f, MTXMODE_APPLY);
		}

		gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(__gfxCtx, __FILE__, __LINE__), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	void Page::postDraw(GlobalContext* globalCtx, GraphicsContext* gfxCtx, float inRadius, bool active)
	{
	}

	void Page::drawInfo(GlobalContext* globalCtx, GraphicsContext* __gfxCtx)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		POLY_OPA_DISP = KaleidoScope_QuadTextureIA4(POLY_OPA_DISP, pauseCtx->nameSegment, 128, 16, 0);
	}

	void Page::drawInfoText(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, const std::string& str)
	{
		GfxPrint printer;
		s32 pad;

		auto polyOpa = POLY_OPA_DISP;
		auto gfx = Graph_GfxPlusOne(polyOpa);
		gSPDisplayList(OVERLAY_DISP++, gfx);

		GfxPrint_Init(&printer);
		GfxPrint_Open(&printer, gfx);
		printer.flags |= GFXP_FLAG_CENTER;
		GfxPrint_SetColor(&printer, 245, 193, 2, 255);
		GfxPrint_SetBasePosPx(&printer, 640, 850, 1);
		GfxPrint_SetPos(&printer, 0, 0);
		GfxPrint_Printf(&printer, str.c_str());

		gfx = GfxPrint_Close(&printer);
		GfxPrint_Destroy(&printer);

		gSPEndDisplayList(gfx++);
		Graph_BranchDlist(polyOpa, gfx);
		POLY_OPA_DISP = gfx;
	}

	void Page::setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height)
	{
		offset_x = -1;
		offset_y = 1;
		width = 14;
		height = 14;
	}

	void Page::update(u16 index, float angle)
	{
		m_index = index;
		m_angle = angle;
	}

	u8* Page::infoPanelTexture(u8 langId)
	{
		return nullptr;
	}

	void Page::setFlipAngle(float angle)
	{
		m_flipAngle = angle;
	}

	float Page::flipAngle() const
	{
		return m_flipAngle;
	}

	Vtx* Page::auxVtx()
	{
		return m_auxVtx.get();
	}

	Vtx* Page::pageVtx()
	{
		return m_pageVtx.get();
	}

	void Page::setActive(bool active)
	{
		m_active = active;
	}

	bool Page::active() const
	{
		return m_active;
	}

	bool Page::is(PauseMenuPage id) const
	{
		return this->id() == id;
	}

	namespace page
	{
		class Item : public Page
		{
			public:
			Item()
			{
				cursorItem() = PAUSE_ITEM_NONE;
			}

			PauseMenuPage id() const override
			{
				return PAUSE_ITEM;
			}

			u8* infoPanelTexture(u8 langId) override
			{
				switch(langId)
				{
					case LANGUAGE_ENG:
						return gPauseToSelectItemENGTex;
					case LANGUAGE_GER:
						return gPauseToSelectItemGERTex;
					case LANGUAGE_FRA:
						return gPauseToSelectItemFRATex;
				}
				return gPauseNoENGTex;
			}

			void initVerticies(GlobalContext* globalCtx) override
			{
				s16 phi_t1;
				s16 phi_t2;
				s16 phi_t2_2;
				s16 phi_t3;
				s16 phi_t4;
				s16 phi_t5;

				PauseContext* pauseCtx = &globalCtx->pauseCtx;
				m_pageVtx = std::make_unique<Vtx[]>(60);
				KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 0, 0);

				m_auxVtx = std::make_unique<Vtx[]>(60);
				m_auxVtx = std::make_unique<Vtx[]>(164);

				for(phi_t4 = 0, phi_t2 = 0, phi_t5 = 58; phi_t4 < 4; phi_t4++, phi_t5 -= 32)
				{
					for(phi_t1 = -96, phi_t3 = 0; phi_t3 < 6; phi_t3++, phi_t2 += 4, phi_t1 += 32)
					{
						m_auxVtx[phi_t2 + 0].v.ob[0] = m_auxVtx[phi_t2 + 2].v.ob[0] = phi_t1 + 2;

						m_auxVtx[phi_t2 + 1].v.ob[0] = m_auxVtx[phi_t2 + 3].v.ob[0] = m_auxVtx[phi_t2 + 0].v.ob[0] + 0x1C;

						m_auxVtx[phi_t2 + 0].v.ob[1] = m_auxVtx[phi_t2 + 1].v.ob[1] = phi_t5 + pauseCtx->offsetY - 2;

						m_auxVtx[phi_t2 + 2].v.ob[1] = m_auxVtx[phi_t2 + 3].v.ob[1] = m_auxVtx[phi_t2 + 0].v.ob[1] - 0x1C;

						m_auxVtx[phi_t2 + 0].v.ob[2] = m_auxVtx[phi_t2 + 1].v.ob[2] = m_auxVtx[phi_t2 + 2].v.ob[2] = m_auxVtx[phi_t2 + 3].v.ob[2] = 0;

						m_auxVtx[phi_t2 + 0].v.flag = m_auxVtx[phi_t2 + 1].v.flag = m_auxVtx[phi_t2 + 2].v.flag = m_auxVtx[phi_t2 + 3].v.flag = 0;

						m_auxVtx[phi_t2 + 0].v.tc[0] = m_auxVtx[phi_t2 + 0].v.tc[1] = m_auxVtx[phi_t2 + 1].v.tc[1] = m_auxVtx[phi_t2 + 2].v.tc[0] = 0;

						m_auxVtx[phi_t2 + 1].v.tc[0] = m_auxVtx[phi_t2 + 2].v.tc[1] = m_auxVtx[phi_t2 + 3].v.tc[0] = m_auxVtx[phi_t2 + 3].v.tc[1] = 0x400;

						m_auxVtx[phi_t2 + 0].v.cn[0] = m_auxVtx[phi_t2 + 1].v.cn[0] = m_auxVtx[phi_t2 + 2].v.cn[0] = m_auxVtx[phi_t2 + 3].v.cn[0] = m_auxVtx[phi_t2 + 0].v.cn[1] = m_auxVtx[phi_t2 + 1].v.cn[1] =
						    m_auxVtx[phi_t2 + 2].v.cn[1] = m_auxVtx[phi_t2 + 3].v.cn[1] = m_auxVtx[phi_t2 + 0].v.cn[2] = m_auxVtx[phi_t2 + 1].v.cn[2] = m_auxVtx[phi_t2 + 2].v.cn[2] = m_auxVtx[phi_t2 + 3].v.cn[2] = 255;

						m_auxVtx[phi_t2 + 0].v.cn[3] = m_auxVtx[phi_t2 + 1].v.cn[3] = m_auxVtx[phi_t2 + 2].v.cn[3] = m_auxVtx[phi_t2 + 3].v.cn[3] = 255;
					}
				}

				for(phi_t3 = 1; phi_t3 < 4; phi_t3++, phi_t2 += 4)
				{
					if(gSaveContext.equips.cButtonSlots[phi_t3 - 1] != ITEM_NONE)
					{
						phi_t4 = gSaveContext.equips.cButtonSlots[phi_t3 - 1] * 4;

						m_auxVtx[phi_t2 + 0].v.ob[0] = m_auxVtx[phi_t2 + 2].v.ob[0] = m_auxVtx[phi_t4].v.ob[0] - 2;

						m_auxVtx[phi_t2 + 1].v.ob[0] = m_auxVtx[phi_t2 + 3].v.ob[0] = m_auxVtx[phi_t2 + 0].v.ob[0] + 32;

						m_auxVtx[phi_t2 + 0].v.ob[1] = m_auxVtx[phi_t2 + 1].v.ob[1] = m_auxVtx[phi_t4].v.ob[1] + 2;

						m_auxVtx[phi_t2 + 2].v.ob[1] = m_auxVtx[phi_t2 + 3].v.ob[1] = m_auxVtx[phi_t2 + 0].v.ob[1] - 32;

						m_auxVtx[phi_t2 + 0].v.ob[2] = m_auxVtx[phi_t2 + 1].v.ob[2] = m_auxVtx[phi_t2 + 2].v.ob[2] = m_auxVtx[phi_t2 + 3].v.ob[2] = 0;

						m_auxVtx[phi_t2 + 0].v.flag = m_auxVtx[phi_t2 + 1].v.flag = m_auxVtx[phi_t2 + 2].v.flag = m_auxVtx[phi_t2 + 3].v.flag = 0;

						m_auxVtx[phi_t2 + 0].v.tc[0] = m_auxVtx[phi_t2 + 0].v.tc[1] = m_auxVtx[phi_t2 + 1].v.tc[1] = m_auxVtx[phi_t2 + 2].v.tc[0] = 0;

						m_auxVtx[phi_t2 + 1].v.tc[0] = m_auxVtx[phi_t2 + 2].v.tc[1] = m_auxVtx[phi_t2 + 3].v.tc[0] = m_auxVtx[phi_t2 + 3].v.tc[1] = 0x400;

						m_auxVtx[phi_t2 + 0].v.cn[0] = m_auxVtx[phi_t2 + 1].v.cn[0] = m_auxVtx[phi_t2 + 2].v.cn[0] = m_auxVtx[phi_t2 + 3].v.cn[0] = m_auxVtx[phi_t2 + 0].v.cn[1] = m_auxVtx[phi_t2 + 1].v.cn[1] =
						    m_auxVtx[phi_t2 + 2].v.cn[1] = m_auxVtx[phi_t2 + 3].v.cn[1] = m_auxVtx[phi_t2 + 0].v.cn[2] = m_auxVtx[phi_t2 + 1].v.cn[2] = m_auxVtx[phi_t2 + 2].v.cn[2] = m_auxVtx[phi_t2 + 3].v.cn[2] = 255;

						m_auxVtx[phi_t2 + 0].v.cn[3] = m_auxVtx[phi_t2 + 1].v.cn[3] = m_auxVtx[phi_t2 + 2].v.cn[3] = m_auxVtx[phi_t2 + 3].v.cn[3] = pauseCtx->alpha;
					}
					else
					{
						m_auxVtx[phi_t2 + 0].v.ob[0] = m_auxVtx[phi_t2 + 2].v.ob[0] = -300;

						m_auxVtx[phi_t2 + 1].v.ob[0] = m_auxVtx[phi_t2 + 3].v.ob[0] = m_auxVtx[phi_t2 + 0].v.ob[0] + 32;

						m_auxVtx[phi_t2 + 0].v.ob[1] = m_auxVtx[phi_t2 + 1].v.ob[1] = 300;

						m_auxVtx[phi_t2 + 2].v.ob[1] = m_auxVtx[phi_t2 + 3].v.ob[1] = m_auxVtx[phi_t2 + 0].v.ob[1] - 32;
					}
				}

				for(phi_t2 = 108, phi_t3 = 0; phi_t3 < 7; phi_t3++)
				{
					phi_t4 = gUknItemVtxIndexLUT[phi_t3];

					m_auxVtx[phi_t2 + 0].v.ob[0] = m_auxVtx[phi_t2 + 2].v.ob[0] = m_auxVtx[phi_t4].v.ob[0];

					m_auxVtx[phi_t2 + 1].v.ob[0] = m_auxVtx[phi_t2 + 3].v.ob[0] = m_auxVtx[phi_t2 + 0].v.ob[0] + 8;

					m_auxVtx[phi_t2 + 0].v.ob[1] = m_auxVtx[phi_t2 + 1].v.ob[1] = m_auxVtx[phi_t4].v.ob[1] - 22;

					m_auxVtx[phi_t2 + 2].v.ob[1] = m_auxVtx[phi_t2 + 3].v.ob[1] = m_auxVtx[phi_t2 + 0].v.ob[1] - 8;

					m_auxVtx[phi_t2 + 4].v.ob[0] = m_auxVtx[phi_t2 + 6].v.ob[0] = m_auxVtx[phi_t2 + 0].v.ob[0] + 6;

					m_auxVtx[phi_t2 + 5].v.ob[0] = m_auxVtx[phi_t2 + 7].v.ob[0] = m_auxVtx[phi_t2 + 4].v.ob[0] + 8;

					m_auxVtx[phi_t2 + 4].v.ob[1] = m_auxVtx[phi_t2 + 5].v.ob[1] = m_auxVtx[phi_t2 + 0].v.ob[1];

					m_auxVtx[phi_t2 + 6].v.ob[1] = m_auxVtx[phi_t2 + 7].v.ob[1] = m_auxVtx[phi_t2 + 4].v.ob[1] - 8;

					for(phi_t4 = 0; phi_t4 < 2; phi_t4++, phi_t2 += 4)
					{
						m_auxVtx[phi_t2 + 0].v.ob[2] = m_auxVtx[phi_t2 + 1].v.ob[2] = m_auxVtx[phi_t2 + 2].v.ob[2] = m_auxVtx[phi_t2 + 3].v.ob[2] = 0;

						m_auxVtx[phi_t2 + 0].v.flag = m_auxVtx[phi_t2 + 1].v.flag = m_auxVtx[phi_t2 + 2].v.flag = m_auxVtx[phi_t2 + 3].v.flag = 0;

						m_auxVtx[phi_t2 + 0].v.tc[0] = m_auxVtx[phi_t2 + 0].v.tc[1] = m_auxVtx[phi_t2 + 1].v.tc[1] = m_auxVtx[phi_t2 + 2].v.tc[0] = 0;

						m_auxVtx[phi_t2 + 1].v.tc[0] = m_auxVtx[phi_t2 + 2].v.tc[1] = m_auxVtx[phi_t2 + 3].v.tc[0] = m_auxVtx[phi_t2 + 3].v.tc[1] = 0x100;

						m_auxVtx[phi_t2 + 0].v.cn[0] = m_auxVtx[phi_t2 + 1].v.cn[0] = m_auxVtx[phi_t2 + 2].v.cn[0] = m_auxVtx[phi_t2 + 3].v.cn[0] = m_auxVtx[phi_t2 + 0].v.cn[1] = m_auxVtx[phi_t2 + 1].v.cn[1] =
						    m_auxVtx[phi_t2 + 2].v.cn[1] = m_auxVtx[phi_t2 + 3].v.cn[1] = m_auxVtx[phi_t2 + 0].v.cn[2] = m_auxVtx[phi_t2 + 1].v.cn[2] = m_auxVtx[phi_t2 + 2].v.cn[2] = m_auxVtx[phi_t2 + 3].v.cn[2] = 255;

						m_auxVtx[phi_t2 + 0].v.cn[3] = m_auxVtx[phi_t2 + 1].v.cn[3] = m_auxVtx[phi_t2 + 2].v.cn[3] = m_auxVtx[phi_t2 + 3].v.cn[3] = pauseCtx->alpha;
					}
				}
			}

			virtual void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				if(!active)
				{
					gDPPipeSync(POLY_OPA_DISP++);
					gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
				}
			}

			void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sSelectItemTexs[gSaveContext.language]);
				KaleidoScope_DrawItemSelect(globalCtx, this);
			}

			void setDefaultCursor(u16& slot, u16& item, u16& namedItem) override
			{
				u16 i;

				if(gSaveContext.inventory.items[slot] == ITEM_NONE)
				{
					i = slot + 1;
					while(true)
					{
						if(gSaveContext.inventory.items[i] != ITEM_NONE)
						{
							break;
						}
						i++;
						if(i >= 24)
						{
							i = 0;
						}
						if(i == slot)
						{
							item = namedItem = PAUSE_ITEM_NONE;
							return;
						}
					}
					item = gSaveContext.inventory.items[i];
					slot = i;
				}
			}
		};

		class Map : public Page
		{
			public:
			Map()
			{
				cursorPoint() = 10;
			}

			PauseMenuPage id() const override
			{
				return PAUSE_WORLD_MAP;
			}

			void setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height)
			{
				if(!sInDungeonScene)
				{
					offset_x = -6;
					offset_y = 6;
					width = 4;
					height = 4;
				}
				else if(cursorSlot() >= 3)
				{
					offset_x = -6;
					offset_y = 5;
					height = 7;
					width = 19;
				}
				else
				{
					offset_x = -3;
					offset_y = 3;
					width = 13;
					height = 13;
				}
			}

			u8* infoPanelTexture(u8 langId) override
			{
				switch(langId)
				{
					case LANGUAGE_ENG:
						return gPauseToMapENGTex;
					case LANGUAGE_GER:
						return gPauseToMapGERTex;
					case LANGUAGE_FRA:
						return gPauseToMapFRATex;
				}
				return gPauseNoENGTex;
			}

			void initVerticies(GlobalContext* globalCtx) override
			{
				s16 phi_t3;
				s16 phi_t2;
				s16 phi_t5;

				PauseContext* pauseCtx = &globalCtx->pauseCtx;

				m_pageVtx = std::make_unique<Vtx[]>(248);
				phi_t3 = KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 4, 32);

				for(phi_t2 = 0, phi_t5 = 58; phi_t2 < 15; phi_t2++, phi_t3 += 4, phi_t5 -= 9)
				{
					m_pageVtx[phi_t3 + 2].v.ob[0] = -108;
					m_pageVtx[phi_t3 + 0].v.ob[0] = m_pageVtx[phi_t3 + 2].v.ob[0];

					m_pageVtx[phi_t3 + 1].v.ob[0] = m_pageVtx[phi_t3 + 3].v.ob[0] = m_pageVtx[phi_t3 + 0].v.ob[0] + 216;

					m_pageVtx[phi_t3 + 0].v.ob[1] = m_pageVtx[phi_t3 + 1].v.ob[1] = phi_t5 + pauseCtx->offsetY;

					m_pageVtx[phi_t3 + 2].v.ob[1] = m_pageVtx[phi_t3 + 3].v.ob[1] = m_pageVtx[phi_t3 + 0].v.ob[1] - 9;

					m_pageVtx[phi_t3 + 0].v.ob[2] = m_pageVtx[phi_t3 + 1].v.ob[2] = m_pageVtx[phi_t3 + 2].v.ob[2] = m_pageVtx[phi_t3 + 3].v.ob[2] = 0;

					m_pageVtx[phi_t3 + 0].v.flag = m_pageVtx[phi_t3 + 1].v.flag = m_pageVtx[phi_t3 + 2].v.flag = m_pageVtx[phi_t3 + 3].v.flag = 0;

					m_pageVtx[phi_t3 + 0].v.tc[0] = m_pageVtx[phi_t3 + 0].v.tc[1] = m_pageVtx[phi_t3 + 1].v.tc[1] = m_pageVtx[phi_t3 + 2].v.tc[0] = 0;

					m_pageVtx[phi_t3 + 1].v.tc[0] = m_pageVtx[phi_t3 + 3].v.tc[0] = 0x1B00;

					m_pageVtx[phi_t3 + 2].v.tc[1] = m_pageVtx[phi_t3 + 3].v.tc[1] = 0x120;

					m_pageVtx[phi_t3 + 0].v.cn[0] = m_pageVtx[phi_t3 + 2].v.cn[0] = m_pageVtx[phi_t3 + 0].v.cn[1] = m_pageVtx[phi_t3 + 2].v.cn[1] = m_pageVtx[phi_t3 + 0].v.cn[2] = m_pageVtx[phi_t3 + 2].v.cn[2] =
					    m_pageVtx[phi_t3 + 1].v.cn[0] = m_pageVtx[phi_t3 + 3].v.cn[0] = m_pageVtx[phi_t3 + 1].v.cn[1] = m_pageVtx[phi_t3 + 3].v.cn[1] = m_pageVtx[phi_t3 + 1].v.cn[2] = m_pageVtx[phi_t3 + 3].v.cn[2] =
						m_pageVtx[phi_t3 + 0].v.cn[3] = m_pageVtx[phi_t3 + 2].v.cn[3] = m_pageVtx[phi_t3 + 1].v.cn[3] = m_pageVtx[phi_t3 + 3].v.cn[3] = pauseCtx->alpha;
				}

				m_pageVtx[phi_t3 - 2].v.ob[1] = m_pageVtx[phi_t3 - 1].v.ob[1] = m_pageVtx[phi_t3 - 4].v.ob[1] - 2;

				m_pageVtx[phi_t3 - 2].v.tc[1] = m_pageVtx[phi_t3 - 1].v.tc[1] = 0x40;
			}

			void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				if(!active)
				{
					gDPPipeSync(POLY_OPA_DISP++);
					gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
				}
			}

			void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sMapTexs[gSaveContext.language]);
				KaleidoScope_DrawWorldMap(globalCtx, __gfxCtx, this);
			}
		};

		namespace dungeon
		{
			class Map : public page::Map
			{
				public:
				Map()
				{
					cursorPoint() = VREG(30) + 3;
					cursorItem() = VREG(30) + 3;
					cursorSlot() = VREG(30) + 3;
				}

				PauseMenuPage id() const override
				{
					return PAUSE_MAP;
				}

				u8* infoPanelTexture(u8 langId) override
				{
					switch(langId)
					{
						case LANGUAGE_ENG:
							return gPauseToMapENGTex;
						case LANGUAGE_GER:
							return gPauseToMapGERTex;
						case LANGUAGE_FRA:
							return gPauseToMapFRATex;
					}
					return gPauseNoENGTex;
				}

				void initVerticies(GlobalContext* globalCtx) override
				{
					PauseContext* pauseCtx = &globalCtx->pauseCtx;
					m_pageVtx = std::make_unique<Vtx[]>(128);
					KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 2, 17);
				}

				void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
				{
					if(!active)
					{
						gDPPipeSync(POLY_OPA_DISP++);
						gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
					}
				}

				void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
				{
					PauseContext* pauseCtx = &globalCtx->pauseCtx;
					POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sMapTexs[gSaveContext.language]);
					KaleidoScope_DrawDungeonMap(globalCtx, __gfxCtx, this);
					func_800949A8(__gfxCtx);

					gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

					if(active && pauseCtx->cursorSpecialPos == 0)
					{
						KaleidoScope_DrawCursor(globalCtx, this);
					}

					if(CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, gSaveContext.mapIndex))
					{
						PauseMapMark_Draw(globalCtx);
					}
				}
			};
		} // namespace dungeon

		class Quest : public Page
		{
			public:
			Quest()
			{
				cursorItem() = PAUSE_ITEM_NONE;
			}

			PauseMenuPage id() const override
			{
				return PAUSE_QUEST;
			}

			void setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height)
			{
				offset_x = -4;
				offset_y = 4;
				width = 12;
				height = 12;

				if(cursorSlot() == 0x18)
				{
					offset_x = -2;
					offset_y = 2;
					width = 32;
					height = 32;
				}
				else if(cursorSlot() == 0x17)
				{
					offset_x = -4;
					offset_y = 4;
					height = 13;
					width = 34;
				}
				else if(cursorSlot() < 6)
				{
					offset_x = -1;
					offset_y = 1;
					width = 10;
					height = 10;
				}
				else if((cursorSlot() >= 6) && (cursorSlot() < 0x12))
				{
					offset_x = -5;
					offset_y = 3;
					width = 8;
					height = 8;
				}
			}

			u8* infoPanelTexture(u8 langId) override
			{
				switch(langId)
				{
					case LANGUAGE_ENG:
						return gPauseToQuestStatusENGTex;
					case LANGUAGE_GER:
						return gPauseToQuestStatusGERTex;
					case LANGUAGE_FRA:
						return gPauseToQuestStatusFRATex;
				}
				return gPauseNoENGTex;
			}

			void initVerticies(GlobalContext* globalCtx) override
			{
				s16 phi_t1;
				s16 phi_t2;
				s16 phi_t2_2;
				s16 phi_t3;
				s16 phi_t4;
				s16 phi_t5;

				PauseContext* pauseCtx = &globalCtx->pauseCtx;
				auto gfxCtx = globalCtx->gfxCtx;

				m_pageVtx = std::make_unique<Vtx[]>(60);
				KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 3, 0);

				m_auxVtx = std::make_unique<Vtx[]>(188);

				for(phi_t4 = 0, phi_t3 = 0; phi_t3 < 47; phi_t3++, phi_t4 += 4)
				{
					phi_t2_2 = D_8082B1F8[phi_t3];

					if((phi_t3 < 6) || (phi_t3 >= 41))
					{
						m_auxVtx[phi_t4 + 0].v.ob[0] = m_auxVtx[phi_t4 + 2].v.ob[0] = D_8082B138[phi_t3];

						m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + D_8082B1F8[phi_t3];

						m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = D_8082B198[phi_t3] + pauseCtx->offsetY;

						m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - D_8082B1F8[phi_t3];

						if(phi_t3 >= 41)
						{
							m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + 8;

							m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = D_8082B198[phi_t3] + pauseCtx->offsetY - 6;

							m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - 16;

							phi_t2_2 = 8;
						}
					}
					else
					{
						if((phi_t3 >= 6) && (phi_t3 <= 17))
						{
							phi_t2_2 = 16;
						}

						m_auxVtx[phi_t4 + 0].v.ob[0] = m_auxVtx[phi_t4 + 2].v.ob[0] = D_8082B138[phi_t3] + 2;

						m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + phi_t2_2 - 4;

						m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = D_8082B198[phi_t3] + pauseCtx->offsetY - 2;

						m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - D_8082B1F8[phi_t3] + 4;
					}

					m_auxVtx[phi_t4 + 0].v.ob[2] = m_auxVtx[phi_t4 + 1].v.ob[2] = m_auxVtx[phi_t4 + 2].v.ob[2] = m_auxVtx[phi_t4 + 3].v.ob[2] = 0;

					m_auxVtx[phi_t4 + 0].v.flag = m_auxVtx[phi_t4 + 1].v.flag = m_auxVtx[phi_t4 + 2].v.flag = m_auxVtx[phi_t4 + 3].v.flag = 0;

					m_auxVtx[phi_t4 + 0].v.tc[0] = m_auxVtx[phi_t4 + 0].v.tc[1] = m_auxVtx[phi_t4 + 1].v.tc[1] = m_auxVtx[phi_t4 + 2].v.tc[0] = 0;

					m_auxVtx[phi_t4 + 1].v.tc[0] = m_auxVtx[phi_t4 + 3].v.tc[0] = phi_t2_2 << 5;
					m_auxVtx[phi_t4 + 2].v.tc[1] = m_auxVtx[phi_t4 + 3].v.tc[1] = D_8082B1F8[phi_t3] << 5;

					m_auxVtx[phi_t4 + 0].v.cn[0] = m_auxVtx[phi_t4 + 1].v.cn[0] = m_auxVtx[phi_t4 + 2].v.cn[0] = m_auxVtx[phi_t4 + 3].v.cn[0] = m_auxVtx[phi_t4 + 0].v.cn[1] = m_auxVtx[phi_t4 + 1].v.cn[1] = m_auxVtx[phi_t4 + 2].v.cn[1] =
					    m_auxVtx[phi_t4 + 3].v.cn[1] = m_auxVtx[phi_t4 + 0].v.cn[2] = m_auxVtx[phi_t4 + 1].v.cn[2] = m_auxVtx[phi_t4 + 2].v.cn[2] = m_auxVtx[phi_t4 + 3].v.cn[2] = 255;

					m_auxVtx[phi_t4 + 0].v.cn[3] = m_auxVtx[phi_t4 + 1].v.cn[3] = m_auxVtx[phi_t4 + 2].v.cn[3] = m_auxVtx[phi_t4 + 3].v.cn[3] = pauseCtx->alpha;
				}
			}

			void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				if(!active)
				{
					gDPPipeSync(POLY_OPA_DISP++);
					gDPSetTextureFilter(POLY_OPA_DISP++, G_TF_BILERP);
					gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
				}
				else
				{
					gDPSetTextureFilter(POLY_OPA_DISP++, G_TF_BILERP);
				}
			}

			void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				PauseContext* pauseCtx = &globalCtx->pauseCtx;
				POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sQuestStatusTexs[gSaveContext.language]);
				KaleidoScope_DrawQuestStatus(globalCtx, __gfxCtx, this);

				if(active && pauseCtx->cursorSpecialPos == 0)
				{
					KaleidoScope_DrawCursor(globalCtx, this);
				}
			}
		};

		class Equip : public Page
		{
			public:
			Equip()
			{
				cursorPoint() = 1;

				cursorX() = 1;
				cursorY() = 0;

				cursorItem() = ITEM_SWORD_KOKIRI;
				cursorSlot() = cursorPoint();
			}

			PauseMenuPage id() const override
			{
				return PAUSE_EQUIP;
			}

			u8* infoPanelTexture(u8 langId) override
			{
				switch(langId)
				{
					case LANGUAGE_ENG:
						return gPauseToEquipmentENGTex;
					case LANGUAGE_GER:
						return gPauseToEquipmentGERTex;
					case LANGUAGE_FRA:
						return gPauseToEquipmentFRATex;
				}
				return gPauseNoENGTex;
			}

			void initVerticies(GlobalContext* globalCtx) override
			{
				s16 phi_t1;
				s16 phi_t2;
				s16 phi_t2_2;
				s16 phi_t3;
				s16 phi_t4;
				s16 phi_t5;

				PauseContext* pauseCtx = &globalCtx->pauseCtx;

				m_pageVtx = std::make_unique<Vtx[]>(60);
				KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 1, 0);

				m_auxVtx = std::make_unique<Vtx[]>(112);

				for(phi_t4 = 0, phi_t2 = 0, phi_t5 = 58; phi_t2 < 4; phi_t2++, phi_t5 -= 32)
				{
					for(phi_t3 = 0; phi_t3 < 4; phi_t3++, phi_t4 += 4)
					{
						m_auxVtx[phi_t4 + 0].v.ob[0] = m_auxVtx[phi_t4 + 2].v.ob[0] = D_8082B12C[phi_t3] + 2;

						m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + 28;

						m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = phi_t5 + pauseCtx->offsetY - 2;

						m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - 28;

						m_auxVtx[phi_t4 + 0].v.ob[2] = m_auxVtx[phi_t4 + 1].v.ob[2] = m_auxVtx[phi_t4 + 2].v.ob[2] = m_auxVtx[phi_t4 + 3].v.ob[2] = 0;

						m_auxVtx[phi_t4 + 0].v.flag = m_auxVtx[phi_t4 + 1].v.flag = m_auxVtx[phi_t4 + 2].v.flag = m_auxVtx[phi_t4 + 3].v.flag = 0;

						m_auxVtx[phi_t4 + 0].v.tc[0] = m_auxVtx[phi_t4 + 0].v.tc[1] = m_auxVtx[phi_t4 + 1].v.tc[1] = m_auxVtx[phi_t4 + 2].v.tc[0] = 0;

						m_auxVtx[phi_t4 + 1].v.tc[0] = m_auxVtx[phi_t4 + 2].v.tc[1] = m_auxVtx[phi_t4 + 3].v.tc[0] = m_auxVtx[phi_t4 + 3].v.tc[1] = 0x400;

						m_auxVtx[phi_t4 + 0].v.cn[0] = m_auxVtx[phi_t4 + 1].v.cn[0] = m_auxVtx[phi_t4 + 2].v.cn[0] = m_auxVtx[phi_t4 + 3].v.cn[0] = m_auxVtx[phi_t4 + 0].v.cn[1] = m_auxVtx[phi_t4 + 1].v.cn[1] =
						    m_auxVtx[phi_t4 + 2].v.cn[1] = m_auxVtx[phi_t4 + 3].v.cn[1] = m_auxVtx[phi_t4 + 0].v.cn[2] = m_auxVtx[phi_t4 + 1].v.cn[2] = m_auxVtx[phi_t4 + 2].v.cn[2] = m_auxVtx[phi_t4 + 3].v.cn[2] = 255;

						m_auxVtx[phi_t4 + 0].v.cn[3] = m_auxVtx[phi_t4 + 1].v.cn[3] = m_auxVtx[phi_t4 + 2].v.cn[3] = m_auxVtx[phi_t4 + 3].v.cn[3] = pauseCtx->alpha;
					}
				}

				for(phi_t3 = 0; phi_t3 < 4; phi_t3++, phi_t4 += 4)
				{
					if(CUR_EQUIP_VALUE(phi_t3) != 0)
					{
						phi_t2 = (CUR_EQUIP_VALUE(phi_t3) + D_8082B134[phi_t3] - 1) * 4;

						m_auxVtx[phi_t4 + 0].v.ob[0] = m_auxVtx[phi_t4 + 2].v.ob[0] = m_auxVtx[phi_t2].v.ob[0] - 2;

						m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + 32;

						m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = m_auxVtx[phi_t2].v.ob[1] + 2;

						m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - 32;

						m_auxVtx[phi_t4 + 0].v.ob[2] = m_auxVtx[phi_t4 + 1].v.ob[2] = m_auxVtx[phi_t4 + 2].v.ob[2] = m_auxVtx[phi_t4 + 3].v.ob[2] = 0;

						m_auxVtx[phi_t4 + 0].v.flag = m_auxVtx[phi_t4 + 1].v.flag = m_auxVtx[phi_t4 + 2].v.flag = m_auxVtx[phi_t4 + 3].v.flag = 0;

						m_auxVtx[phi_t4 + 0].v.tc[0] = m_auxVtx[phi_t4 + 0].v.tc[1] = m_auxVtx[phi_t4 + 1].v.tc[1] = m_auxVtx[phi_t4 + 2].v.tc[0] = 0;

						m_auxVtx[phi_t4 + 1].v.tc[0] = m_auxVtx[phi_t4 + 2].v.tc[1] = m_auxVtx[phi_t4 + 3].v.tc[0] = m_auxVtx[phi_t4 + 3].v.tc[1] = 0x400;

						m_auxVtx[phi_t4 + 0].v.cn[0] = m_auxVtx[phi_t4 + 1].v.cn[0] = m_auxVtx[phi_t4 + 2].v.cn[0] = m_auxVtx[phi_t4 + 3].v.cn[0] = m_auxVtx[phi_t4 + 0].v.cn[1] = m_auxVtx[phi_t4 + 1].v.cn[1] =
						    m_auxVtx[phi_t4 + 2].v.cn[1] = m_auxVtx[phi_t4 + 3].v.cn[1] = m_auxVtx[phi_t4 + 0].v.cn[2] = m_auxVtx[phi_t4 + 1].v.cn[2] = m_auxVtx[phi_t4 + 2].v.cn[2] = m_auxVtx[phi_t4 + 3].v.cn[2] = 255;

						m_auxVtx[phi_t4 + 0].v.cn[3] = m_auxVtx[phi_t4 + 1].v.cn[3] = m_auxVtx[phi_t4 + 2].v.cn[3] = m_auxVtx[phi_t4 + 3].v.cn[3] = pauseCtx->alpha;
					}
				}

				phi_t1 = 112;
				phi_t5 = 50;
				while(true)
				{
					m_auxVtx[phi_t4 + 0].v.ob[0] = m_auxVtx[phi_t4 + 2].v.ob[0] = -64;

					m_auxVtx[phi_t4 + 1].v.ob[0] = m_auxVtx[phi_t4 + 3].v.ob[0] = m_auxVtx[phi_t4 + 0].v.ob[0] + 64;

					m_auxVtx[phi_t4 + 0].v.ob[1] = m_auxVtx[phi_t4 + 1].v.ob[1] = phi_t5 + pauseCtx->offsetY;

					m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - 32;

					m_auxVtx[phi_t4 + 0].v.ob[2] = m_auxVtx[phi_t4 + 1].v.ob[2] = m_auxVtx[phi_t4 + 2].v.ob[2] = m_auxVtx[phi_t4 + 3].v.ob[2] = 0;

					m_auxVtx[phi_t4 + 0].v.flag = m_auxVtx[phi_t4 + 1].v.flag = m_auxVtx[phi_t4 + 2].v.flag = m_auxVtx[phi_t4 + 3].v.flag = 0;

					m_auxVtx[phi_t4 + 0].v.tc[0] = m_auxVtx[phi_t4 + 0].v.tc[1] = m_auxVtx[phi_t4 + 1].v.tc[1] = m_auxVtx[phi_t4 + 2].v.tc[0] = 0;

					m_auxVtx[phi_t4 + 1].v.tc[0] = m_auxVtx[phi_t4 + 3].v.tc[0] = 0x800;

					m_auxVtx[phi_t4 + 2].v.tc[1] = m_auxVtx[phi_t4 + 3].v.tc[1] = 0x400;

					m_auxVtx[phi_t4 + 0].v.cn[0] = m_auxVtx[phi_t4 + 1].v.cn[0] = m_auxVtx[phi_t4 + 2].v.cn[0] = m_auxVtx[phi_t4 + 3].v.cn[0] = m_auxVtx[phi_t4 + 0].v.cn[1] = m_auxVtx[phi_t4 + 1].v.cn[1] = m_auxVtx[phi_t4 + 2].v.cn[1] =
					    m_auxVtx[phi_t4 + 3].v.cn[1] = m_auxVtx[phi_t4 + 0].v.cn[2] = m_auxVtx[phi_t4 + 1].v.cn[2] = m_auxVtx[phi_t4 + 2].v.cn[2] = m_auxVtx[phi_t4 + 3].v.cn[2] = 255;

					m_auxVtx[phi_t4 + 0].v.cn[3] = m_auxVtx[phi_t4 + 1].v.cn[3] = m_auxVtx[phi_t4 + 2].v.cn[3] = m_auxVtx[phi_t4 + 3].v.cn[3] = pauseCtx->alpha;

					phi_t1 -= 32;
					phi_t5 -= 32;
					if(phi_t1 < 0)
					{
						m_auxVtx[phi_t4 + 2].v.ob[1] = m_auxVtx[phi_t4 + 3].v.ob[1] = m_auxVtx[phi_t4 + 0].v.ob[1] - 0x10;

						m_auxVtx[phi_t4 + 2].v.tc[1] = m_auxVtx[phi_t4 + 3].v.tc[1] = 0x200;
						break;
					}

					phi_t4 += 4;
				}
			}

			void preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				if(!active)
				{
					gDPPipeSync(POLY_OPA_DISP++);
					gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
				}
			}

			void postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active) override
			{
				PauseContext* pauseCtx = &globalCtx->pauseCtx;
				POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sEquipmentTexs[gSaveContext.language]);
				KaleidoScope_DrawEquipment(globalCtx, this);

				if(active && pauseCtx->cursorSpecialPos == 0)
				{
					KaleidoScope_DrawCursor(globalCtx, this);
				}
			}
		};

	} // namespace page

	class Pages
	{
		public:
		Pages() : m_pages(), m_pageIndex(0), m_pageIndexTarget(0), m_rotation(0.0f)
		{
		}

		Page* current() const
		{
			if(m_pageIndex >= m_pages.size())
			{
				return m_pages[0].get();
			}

			return m_pages[m_pageIndex].get();
		}

		Page* get(u16 pageId)
		{
			if(pageId >= m_pages.size())
			{
				return m_pages[0].get();
			}

			return m_pages[pageId].get();
		}

		Page* find(PauseMenuPage pageId)
		{
			for(auto& page : m_pages)
			{
				if(page->id() == pageId)
				{
					return page.get();
				}
			}

			return nullptr;
		}

		Page* next(u16 pageId)
		{
			if(pageId == m_pages.size() - 1)
			{
				return m_pages[0].get();
			}

			return m_pages[pageId + 1].get();
		}

		Page* prev(u16 pageId)
		{
			if(pageId == 0)
			{
				return m_pages[m_pages.size() - 1].get();
			}

			return m_pages[pageId - 1].get();
		}

		Eye eye() const
		{
			const float d = (128.0f - m_inradius) - (15.0f * m_inradiusScaler);
			auto r = ::rotate({0.0f, d}, DEGTORAD(m_rotation));
			return Eye({r.x, 0.0f, r.y}, d < 0);
		}

		u16 size() const
		{
			return m_pages.size();
		}

		void add(std::unique_ptr<Page>&& page)
		{
			m_pages.push_back(std::move(page));
		}

		void setDefaultCursor(const u16 pageId, u16& slot, u16& item, u16& namedItem)
		{
			m_pages[pageId]->setDefaultCursor(slot, item, namedItem);
		}

		void update()
		{
			const u16 count = m_pages.size();

			for(u16 i = 0; i < count; i++)
			{
				m_pages[i]->update(i, ((float)i * (360.0f / (float)count)));
			}

			setFlipAngles(160.0f);

			m_pageAngle = 360.0f / m_pages.size();
			m_inradius = INRADIUS(128.0, m_pages.size());
			m_inradiusScaler = m_inradius / INRADIUS(128.0, 4);
		}

		void clear()
		{
			m_pages.clear();
		}

		void initVerticies(GlobalContext* globalCtx)
		{
			for(auto& page : m_pages)
			{
				page->initVerticies(globalCtx);
			}
		}

		void setFlipAngles(float angle)
		{
			for(auto& page : m_pages)
			{
				page->setFlipAngle(angle);
			}
		}

		void draw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, u16 active)
		{
			for(u16 i = 0; i < m_pages.size(); i++)
			{
				if(i != active)
				{
					m_pages[i]->preDraw(globalCtx, __gfxCtx, inRadiusAdjusted(), false);
					m_pages[i]->draw(globalCtx, __gfxCtx, inRadiusAdjusted(), false);
					m_pages[i]->postDraw(globalCtx, __gfxCtx, inRadiusAdjusted(), false);
				}
			}

			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

			if(active < m_pages.size())
			{
				m_pages[active]->preDraw(globalCtx, __gfxCtx, inRadiusAdjusted(), true);
				m_pages[active]->draw(globalCtx, __gfxCtx, inRadiusAdjusted(), true);
				m_pages[active]->postDraw(globalCtx, __gfxCtx, inRadiusAdjusted(), true);
			}
		}

		void moveNextPage()
		{
			m_pageIndexTarget = next(m_pageIndex)->index();
		}

		void movePrevPage()
		{
			m_pageIndexTarget = prev(m_pageIndex)->index();
		}

		float rotate(GlobalContext* globalCtx)
		{
			const float targetRotation = (m_pageIndexTarget * m_pageAngle);
			const float originalRotation = (m_pageIndex * m_pageAngle);

			if(Math_StepRotationToF(&m_rotation, targetRotation, 4.0f * 30.0f * FRAMERATE_SCALER_INV / framerate_get()))
			{
				m_pageIndex = m_pageIndexTarget;
				globalCtx->pauseCtx.pageIndex = m_pageIndexTarget;
				return 1.0f;
			}

			const float total = Math_AngleDiffF(targetRotation, originalRotation);
			const float current = Math_AngleDiffF(targetRotation, m_rotation);

			return 1.0f - (current / total);
		}

		void setActivePage(GlobalContext* globalCtx, u16 pageIndex)
		{
			m_pageIndex = pageIndex;
			for(u16 i = 0; i < m_pages.size(); i++)
			{
				m_pages[i]->setActive(i == pageIndex);
			}
			globalCtx->pauseCtx.pageIndex = pageIndex;
		}

		float pageAngle() const
		{
			return m_pageAngle;
		}

		float inRadius() const
		{
			return m_inradius;
		}

		float inRadiusAdjusted() const
		{
			return 93.55 * m_inradiusScaler;
		}

		protected:
		std::vector<std::unique_ptr<Page>> m_pages;
		u16 m_pageIndex;
		u16 m_pageIndexTarget;
		float m_rotation;
		float m_pageAngle;
		float m_inradius;
		float m_inradiusScaler;
	};

	class OotMenu : public Pages
	{
		public:
		OotMenu() : Pages()
		{
		}

		void create()
		{
			clear();
			if(sInDungeonScene)
			{
				add(std::make_unique<oot::pause::page::Item>());
				add(std::make_unique<oot::pause::page::dungeon::Map>());
				add(std::make_unique<oot::pause::page::Quest>());

				if(oot::config().game().enableExtendedOptionsMenu())
				{
					add(std::make_unique<oot::pause::page::Controller>());
				}

				add(std::make_unique<oot::pause::page::Equip>());
			}
			else
			{
				add(std::make_unique<oot::pause::page::Item>());
				add(std::make_unique<oot::pause::page::Map>());
				add(std::make_unique<oot::pause::page::Quest>());

				if(oot::config().game().enableExtendedOptionsMenu())
				{
					add(std::make_unique<oot::pause::page::Controller>());
				}

				add(std::make_unique<oot::pause::page::Equip>());
			}
		}
	};
} // namespace oot::pause

static oot::pause::OotMenu gPages;

u8 gSlotAgeReqs[] = {
    1, 9, 9, 0, 0, 9, 1, 9, 9, 0, 0, 9, 1, 9, 1, 0, 0, 9, 9, 9, 9, 9, 0, 1,
};

u8 gEquipAgeReqs[][4] = {
    {0, 1, 0, 0},
    {9, 1, 9, 0},
    {0, 9, 0, 0},
    {9, 9, 0, 0},
};

u8 gItemAgeReqs[] = {
    1, 9, 9, 0, 0, 9, 1, 9, 9, 9, 0, 0, 0, 9, 1, 9, 1, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 9, 0, 9, 0, 0, 9, 0, 0, 1, 1, 1, 0, 0, 0, 9, 9, 9, 1, 0, 0, 9, 9, 0,
};

bool Item_MeetsAgeRequirement(ItemID itemID)
{
	return (gItemAgeReqs[itemID] == 9) || (gItemAgeReqs[itemID] == gSaveContext.linkAge);
}

bool Equip_MeetsAgeRequirement(EquipmentPosition equip)
{
	return (gEquipAgeReqs[equip.y][equip.x + 1] == 9) || (gEquipAgeReqs[equip.y][equip.x + 1] == gSaveContext.linkAge);
}

u8 gAreaGsFlags[] = {
    0x0F, 0x1F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x03, 0x0F, 0x07, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x03, 0x0F,
};

static void* sCursorTexs[] = {
    gPauseMenuCursorTopLeftTex,
    gPauseMenuCursorTopRightTex,
    gPauseMenuCursorBottomLeftTex,
    gPauseMenuCursorBottomRightTex,
};

static s16 sCursorColors[][3] = {
    {255, 255, 255},
    {255, 255, 0},
    {0, 50, 255},
};

static void* sSavePromptTexs[] = {
    gPauseSavePromptENGTex,
    gPauseSavePromptGERTex,
    gPauseSavePromptFRATex,
};

static void* sSaveConfirmationTexs[] = {
    gPauseSaveConfirmationENGTex,
    gPauseSaveConfirmationGERTex,
    gPauseSaveConfirmationFRATex,
};

static void* sContinuePromptTexs[] = {
    gContinuePlayingENGTex,
    gContinuePlayingGERTex,
    gContinuePlayingFRATex,
};

static void* sPromptChoiceTexs[][2] = {
    {gPauseYesENGTex, gPauseNoENGTex},
    {gPauseYesGERTex, gPauseNoGERTex},
    {gPauseYesFRATex, gPauseNoFRATex},
};

static u8 D_808321A8[5];
static PreRender sPlayerPreRender;

#ifndef N64_VERSION
void KaleidoScope_GrayOutTextureRGBA32(u32* textureIn, u32* textureOut, u16 pixelCount);

void KaleidoScope_SetupGrayIcons()
{
	static_assert(ARRAY_COUNTU(gItemIconsGray) <= ARRAY_COUNTU(gItemIcons), "gItemIcons can not have more elements than gItemIconsGray");
	static_assert(ARRAY_COUNTU(gItemIconsGray) <= ARRAY_COUNTU(gItemAgeReqs), "gItemAgeReqs needs to be larger than gItemIconsGray");
	static_assert(ARRAY_COUNTU(gItemIconsCurrent) == ARRAY_COUNTU(gItemAgeReqs), "gItemIconsCurrent and gItemAgeReqs need to be of the same size");

	s16 i;
	for(i = 0; i < ARRAY_COUNTU(gItemAgeReqs); i++)
	{
		if(gItemAgeReqs[i] != 9)
		{
			KaleidoScope_GrayOutTextureRGBA32((u32*)SEGMENTED_TO_VIRTUAL(gItemIcons[i]), (u32*)SEGMENTED_TO_VIRTUAL(gItemIconsGray[i]), 32 * 32);
		}
	}
}
#endif

void KaleidoScope_SetupPlayerPreRender(GlobalContext* globalCtx)
{
	Gfx* gfx;
	Gfx* gfxRef;
	void* fbuf;

	fbuf = globalCtx->gfxCtx->curFrameBuffer;

	OPEN_DISPS(globalCtx->gfxCtx, __FILE__, __LINE__);

	gfxRef = POLY_OPA_DISP;
	gfx = Graph_GfxPlusOne(gfxRef);
	gSPDisplayList(WORK_DISP++, gfx);

	PreRender_SetValues(&sPlayerPreRender, 64, 112, fbuf, NULL);
	func_800C1F20(&sPlayerPreRender, &gfx);
	func_800C20B4(&sPlayerPreRender, &gfx);

	gSPEndDisplayList(gfx++);
	Graph_BranchDlist(gfxRef, gfx);
	POLY_OPA_DISP = gfx;

	SREG(33) |= 1;

	CLOSE_DISPS(globalCtx->gfxCtx, __FILE__, __LINE__);
}

void KaleidoScope_ProcessPlayerPreRender(void)
{
	Sleep_Msec(50);
	PreRender_Calc(&sPlayerPreRender);
	PreRender_Destroy(&sPlayerPreRender);
}

Gfx* KaleidoScope_QuadTextureIA4(Gfx* gfx, void* texture, s16 width, s16 height, u16 point)
{
	gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_IA, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSP1Quadrangle(gfx++, point, point + 2, point + 3, point + 1, 0);

	return gfx;
}

Gfx* KaleidoScope_QuadTextureIA8(Gfx* gfx, void* texture, s16 width, s16 height, u16 point)
{
	gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSP1Quadrangle(gfx++, point, point + 2, point + 3, point + 1, 0);

	return gfx;
}

Gfx* KaleidoScope_QuadTextureRGBA16(Gfx* gfx, void* texture, s16 width, s16 height, u16 point)
{
	gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSP1Quadrangle(gfx++, point, point + 2, point + 3, point + 1, 0);

	return gfx;
}

Gfx* KaleidoScope_QuadTextureRGBA32(Gfx* gfx, void* texture, s16 width, s16 height, u16 point)
{
	gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSP1Quadrangle(gfx++, point, point + 2, point + 3, point + 1, 0);

	return gfx;
}

void KaleidoScope_OverridePalIndexCI4(u8* texture, s32 size, s32 targetIndex, s32 newIndex)
{
	s32 i;

	targetIndex &= 0xF;
	newIndex &= 0xF;

	if((size == 0) || (targetIndex == newIndex) || (texture == NULL))
	{
		return;
	}

	for(i = 0; i < size; i++)
	{
		s32 index1;
		s32 index2;

		index1 = index2 = texture[i];

		index1 = (index1 >> 4) & 0xF;
		index2 = index2 & 0xF;

		if(index1 == targetIndex)
		{
			index1 = newIndex;
		}

		if(index2 == targetIndex)
		{
			index2 = newIndex;
		}

		texture[i] = (index1 << 4) | index2;
	}
}

void KaleidoScope_MoveCursorToSpecialPos(GlobalContext* globalCtx, u16 specialPos)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;

	pauseCtx->cursorSpecialPos = specialPos;
	pauseCtx->pageSwitchTimer = 0;

	Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
}

void KaleidoScope_DrawQuadTextureRGBA32(GraphicsContext* gfxCtx, void* texture, u16 width, u16 height, u16 point)
{
	OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 748);

	gDPLoadTextureBlock(POLY_OPA_DISP++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSP1Quadrangle(POLY_OPA_DISP++, point, point + 2, point + 3, point + 1, 0);

	CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 758);
}

void KaleidoScope_SetDefaultCursor(GlobalContext* globalCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	auto page = gPages.find(PAUSE_ITEM);
	gPages.setDefaultCursor(pauseCtx->pageIndex, page->cursorSlot(), page->cursorItem(), pauseCtx->namedItem);
}

void KaleidoScope_SetPage(GlobalContext* globalCtx, u16 pageIndex)
{
	gPages.setActivePage(globalCtx, pageIndex);
}

oot::pause::Page* KaleidoScope_FindPage(PauseMenuPage id)
{
	return gPages.find(id);
}

oot::pause::Page* KaleidoScope_CurrentPage()
{
	return gPages.current();
}

void KaleidoScope_SwitchPage(PauseContext* pauseCtx, u8 pt)
{
	pauseCtx->unk_1E4 = 1;
	pauseCtx->rotAccum = 0;

	if(!pt)
	{
		gPages.movePrevPage();
		Audio_PlaySoundGeneral(NA_SE_SY_WIN_SCROLL_LEFT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
		pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_RIGHT;
	}
	else
	{
		gPages.moveNextPage();
		Audio_PlaySoundGeneral(NA_SE_SY_WIN_SCROLL_RIGHT, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
		pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_LEFT;
	}

	pauseCtx->pageIndex = gPages.current()->index();

	gSaveContext.buttonStatus[1] = gButtonStates[pauseCtx->pageIndex + pt][1];
	gSaveContext.buttonStatus[2] = gButtonStates[pauseCtx->pageIndex + pt][2];
	gSaveContext.buttonStatus[3] = gButtonStates[pauseCtx->pageIndex + pt][3];
	gSaveContext.buttonStatus[4] = gButtonStates[pauseCtx->pageIndex + pt][4];

	osSyncPrintf("kscope->kscp_pos+pt = %d\n", pauseCtx->pageIndex + pt);

	gSaveContext.unk_13EA = 0;
	Interface_ChangeAlpha(50);
}

void KaleidoScope_HandlePageToggles(PauseContext* pauseCtx, Input* input)
{
	if((pauseCtx->debugState == 0) && CHECK_BTN_ALL(input->press.button, BTN_L))
	{
		pauseCtx->debugState = 1;
		return;
	}

	if(CHECK_BTN_ALL(input->press.button, BTN_R))
	{
		KaleidoScope_SwitchPage(pauseCtx, 2);
		return;
	}

	if(CHECK_BTN_ALL(input->press.button, BTN_Z))
	{
		KaleidoScope_SwitchPage(pauseCtx, 0);
		return;
	}

	if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT)
	{
		if(pauseCtx->stickRelX < -30)
		{
			pauseCtx->pageSwitchTimer++;
			if((pauseCtx->pageSwitchTimer >= 10) || (pauseCtx->pageSwitchTimer == 0))
			{
				KaleidoScope_SwitchPage(pauseCtx, 0);
			}
		}
		else
		{
			pauseCtx->pageSwitchTimer = -1;
		}
	}
	else if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT)
	{
		if(pauseCtx->stickRelX > 30)
		{
			pauseCtx->pageSwitchTimer++;
			if((pauseCtx->pageSwitchTimer >= 10) || (pauseCtx->pageSwitchTimer == 0))
			{
				KaleidoScope_SwitchPage(pauseCtx, 2);
			}
		}
		else
		{
			pauseCtx->pageSwitchTimer = -1;
		}
	}
}

void KaleidoScope_DrawCursor(GlobalContext* globalCtx, oot::pause::Page* page)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	u16 temp;
	auto current = gPages.current();

	KaleidoScope_UpdateCursorSize(globalCtx);

	OPEN_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 955);

	temp = pauseCtx->unk_1E4;

	if((((pauseCtx->unk_1E4 == 0) || (temp == 8)) && (pauseCtx->state == 6)) || ((current->id() == PAUSE_QUEST) && ((temp < 3) || (temp == 5) || (temp == 8))))
	{
		if(page == KaleidoScope_CurrentPage())
		{
			s16 i;
			s16 j;

			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sCursorColors[pauseCtx->cursorColorSet >> 2][0], sCursorColors[pauseCtx->cursorColorSet >> 2][1], sCursorColors[pauseCtx->cursorColorSet >> 2][2], 255);
			gDPSetEnvColor(POLY_OPA_DISP++, D_8082AB8C, D_8082AB90, D_8082AB94, 255);
			gSPVertex(POLY_OPA_DISP++, pauseCtx->cursorVtx, 16, 0);

			for(i = j = 0; i < 4; i++, j += 4)
			{
				gDPLoadTextureBlock_4b(POLY_OPA_DISP++, sCursorTexs[i], G_IM_FMT_IA, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
				gSP1Quadrangle(POLY_OPA_DISP++, j, j + 2, j + 3, j + 1, 0);
			}
		}

		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 985);
}

Gfx* KaleidoScope_DrawPageSections(Gfx* gfx, Vtx* vertices, void** textures)
{
	s32 i;
	s32 j;

	gSPVertex(gfx++, vertices, 32, 0);

	i = 0;
	j = 0;
	while(j < 32)
	{
		gDPPipeSync(gfx++);
		gDPLoadTextureBlock(gfx++, textures[i], G_IM_FMT_IA, G_IM_SIZ_8b, 80, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
		gSP1Quadrangle(gfx++, j, j + 2, j + 3, j + 1, 0);

		j += 4;
		i++;
	}

	gSPVertex(gfx++, vertices + 32, 28, 0);

	j = 0;
	while(j < 28)
	{
		gDPPipeSync(gfx++);
		gDPLoadTextureBlock(gfx++, textures[i], G_IM_FMT_IA, G_IM_SIZ_8b, 80, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
		gSP1Quadrangle(gfx++, j, j + 2, j + 3, j + 1, 0);

		j += 4;
		i++;
	}

	return gfx;
}

void KaleidoScope_DrawPages(GlobalContext* globalCtx, GraphicsContext* gfxCtx)
{
	static s16 D_8082ACF4[][3] = {
	    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}, {0, 50, 255}, {0, 0, 0}, {0, 0, 0}, {0, 50, 255},
	};
	static s16 D_8082AD3C = 20;
	static s16 D_8082AD40 = 0;
	static s16 D_8082AD44 = 0;
	static s16 D_8082AD48 = 0;
	static s16 D_8082AD4C = 0;
	static s16 D_8082AD50 = 0;
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	s16 stepR;
	s16 stepG;
	s16 stepB;
	Vec2f r;

	OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 1100);

	if((pauseCtx->state < 8) || (pauseCtx->state > 0x11))
	{
		if(pauseCtx->state != 7)
		{
			stepR = ABS(D_8082AB8C - D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][0]) / D_8082AD3C;
			stepG = ABS(D_8082AB90 - D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][1]) / D_8082AD3C;
			stepB = ABS(D_8082AB94 - D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][2]) / D_8082AD3C;
			if(D_8082AB8C >= D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][0])
			{
				D_8082AB8C -= stepR;
			}
			else
			{
				D_8082AB8C += stepR;
			}
			if(D_8082AB90 >= D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][1])
			{
				D_8082AB90 -= stepG;
			}
			else
			{
				D_8082AB90 += stepG;
			}
			if(D_8082AB94 >= D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][2])
			{
				D_8082AB94 -= stepB;
			}
			else
			{
				D_8082AB94 += stepB;
			}

			D_8082AD3C--;
			if(D_8082AD3C == 0)
			{
				D_8082AB8C = D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][0];
				D_8082AB90 = D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][1];
				D_8082AB94 = D_8082ACF4[pauseCtx->cursorColorSet + D_8082AD40][2];
				D_8082AD3C = ZREG(28 + D_8082AD40);
				D_8082AD40++;
				if(D_8082AD40 >= 4)
				{
					D_8082AD40 = 0;
				}
			}

			if(pauseCtx->stickRelX < -30)
			{
				if(D_8082AD4C == -1)
				{
					if(--D_8082AD44 < 0)
					{
						D_8082AD44 = XREG(6);
					}
					else
					{
						pauseCtx->stickRelX = 0;
					}
				}
				else
				{
					D_8082AD44 = XREG(8);
					D_8082AD4C = -1;
				}
			}
			else if(pauseCtx->stickRelX > 30)
			{
				if(D_8082AD4C == 1)
				{
					if(--D_8082AD44 < 0)
					{
						D_8082AD44 = XREG(6);
					}
					else
					{
						pauseCtx->stickRelX = 0;
					}
				}
				else
				{
					D_8082AD44 = XREG(8);
					D_8082AD4C = 1;
				}
			}
			else
			{
				D_8082AD4C = 0;
			}

			if(pauseCtx->stickRelY < -30)
			{
				if(D_8082AD50 == -1)
				{
					if(--D_8082AD48 < 0)
					{
						D_8082AD48 = XREG(6);
					}
					else
					{
						pauseCtx->stickRelY = 0;
					}
				}
				else
				{
					D_8082AD48 = XREG(8);
					D_8082AD50 = -1;
				}
			}
			else if(pauseCtx->stickRelY > 30)
			{
				if(D_8082AD50 == 1)
				{
					if(--D_8082AD48 < 0)
					{
						D_8082AD48 = XREG(6);
					}
					else
					{
						pauseCtx->stickRelY = 0;
					}
				}
				else
				{
					D_8082AD48 = XREG(8);
					D_8082AD50 = 1;
				}
			}
			else
			{
				D_8082AD50 = 0;
			}
		}

		gPages.draw(globalCtx, gfxCtx, pauseCtx->pageIndex);
	}

	func_800949A8(gfxCtx);

	if((pauseCtx->state == 7) || ((pauseCtx->state >= 8) && (pauseCtx->state < 0x12)))
	{
		KaleidoScope_UpdatePrompt(globalCtx);

		gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);

		auto page = gPages.current();
		page->setFlipAngle(pauseCtx->unk_204 + 314.0f);
		page->dialogDraw(globalCtx, gfxCtx, gPages.inRadiusAdjusted(), true);

		if((pauseCtx->state >= 8) && (pauseCtx->state <= 0x11))
		{
			POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, pauseCtx->saveVtx, sGameOverTexs);
		}
		else
		{
			POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, pauseCtx->saveVtx, (void**)sSaveTexs[gSaveContext.language]);
		}

		gSPVertex(POLY_OPA_DISP++, &pauseCtx->saveVtx[60], 32, 0);

		if(((pauseCtx->state == 7) && (pauseCtx->unk_1EC < 4)) || (pauseCtx->state == 0xE))
		{
			POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sSavePromptTexs[gSaveContext.language], 152, 16, 0);

			gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 100, 255, VREG(61));

			if(pauseCtx->promptChoice == 0)
			{
				gSPDisplayList(POLY_OPA_DISP++, gPromptCursorLeftDL);
			}
			else
			{
				gSPDisplayList(POLY_OPA_DISP++, gPromptCursorRightDL);
			}

			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

			POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sPromptChoiceTexs[gSaveContext.language][0], 48, 16, 12);

			POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sPromptChoiceTexs[gSaveContext.language][1], 48, 16, 16);
		}
		else if((pauseCtx->state != 7) || (pauseCtx->unk_1EC < 4))
		{
			if((pauseCtx->state != 0xF) && ((pauseCtx->state == 0x10) || (pauseCtx->state == 0x11)))
			{
				POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sContinuePromptTexs[gSaveContext.language], 152, 16, 0);

				gDPSetCombineLERP(POLY_OPA_DISP++, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 100, 100, 255, VREG(61));

				if(pauseCtx->promptChoice == 0)
				{
					gSPDisplayList(POLY_OPA_DISP++, gPromptCursorLeftDL);
				}
				else
				{
					gSPDisplayList(POLY_OPA_DISP++, gPromptCursorRightDL);
				}

				gDPPipeSync(POLY_OPA_DISP++);
				gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

				POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sPromptChoiceTexs[gSaveContext.language][0], 48, 16, 12);

				POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, sPromptChoiceTexs[gSaveContext.language][1], 48, 16, 16);
			}
		}

		gDPPipeSync(POLY_OPA_DISP++);
		gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

		if((pauseCtx->state != 0x10) && (pauseCtx->state != 0x11))
		{
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 0, pauseCtx->alpha);
			gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);
		}
	}

	CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 1577);
}

void KaleidoScope_DrawInfoPanel(GlobalContext* globalCtx)
{
	static void* D_8082AD54[3] = {
	    gPauseToEquipENGTex,
	    gPauseToEquipGERTex,
	    gPauseToEquipFRATex,
	};
	static void* D_8082AD60[3] = {
	    gPauseToDecideENGTex,
	    gPauseToDecideGERTex,
	    gPauseToDecideFRATex,
	};
	static void* D_8082AD6C[3] = {
	    gPauseToPlayMelodyENGTex,
	    gPauseToPlayMelodyGERTex,
	    gPauseToPlayMelodyFRATex,
	};

	static u16 D_8082ADD8[3] = {56, 88, 80};
	static u16 D_8082ADE0[3] = {64, 88, 72};
	static u16 D_8082ADE8[3] = {80, 104, 112};
	static s16 D_8082ADF0[][4] = {
	    {180, 210, 255, 220},
	    {100, 100, 150, 220},
	};
	static s16 D_8082AE00 = 20;
	static s16 D_8082AE04 = 0;
	static s16 D_8082AE08[] = {
	    10, 16, 16, 17, 12, 13, 18, 17, 17, 19, 13, 21, 20, 21, 14, 15, 15, 15, 11, 14,
	};
	static s16 D_8082AE30[] = {
	    21, 20, 19, 18, 11, 14, 10, 15, 16, 13, 12, 17,
	};
	static s16 D_808321A0;
	static s16 D_808321A2;
	static s16 D_808321A4;
	static s16 D_808321A6;
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	s16 stepR;
	s16 stepG;
	s16 stepB;
	s16 stepA;
	s16 temp;
	s16 i;
	s16 j;

	auto current = gPages.current();

	OPEN_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 1676);

	stepR = ABS(D_808321A0 - D_8082ADF0[D_8082AE04][0]) / D_8082AE00;
	stepG = ABS(D_808321A2 - D_8082ADF0[D_8082AE04][1]) / D_8082AE00;
	stepB = ABS(D_808321A4 - D_8082ADF0[D_8082AE04][2]) / D_8082AE00;
	stepA = ABS(D_808321A6 - D_8082ADF0[D_8082AE04][3]) / D_8082AE00;
	if(D_808321A0 >= D_8082ADF0[D_8082AE04][0])
	{
		D_808321A0 -= stepR;
	}
	else
	{
		D_808321A0 += stepR;
	}
	if(D_808321A2 >= D_8082ADF0[D_8082AE04][1])
	{
		D_808321A2 -= stepG;
	}
	else
	{
		D_808321A2 += stepG;
	}
	if(D_808321A4 >= D_8082ADF0[D_8082AE04][2])
	{
		D_808321A4 -= stepB;
	}
	else
	{
		D_808321A4 += stepB;
	}
	if(D_808321A6 >= D_8082ADF0[D_8082AE04][3])
	{
		D_808321A6 -= stepA;
	}
	else
	{
		D_808321A6 += stepA;
	}

	D_8082AE00--;
	if(D_8082AE00 == 0)
	{
		D_808321A0 = D_8082ADF0[D_8082AE04][0];
		D_808321A2 = D_8082ADF0[D_8082AE04][1];
		D_808321A4 = D_8082ADF0[D_8082AE04][2];
		D_808321A6 = D_8082ADF0[D_8082AE04][3];
		D_8082AE00 = ZREG(28);
		D_8082AE04 ^= 1;
	}

	temp = pauseCtx->infoPanelOffsetY - 76;
	for(j = 0, i = 0; i < 7; i++, j += 4)
	{
		pauseCtx->infoPanelVtx[j + 0].v.ob[0] = pauseCtx->infoPanelVtx[j + 2].v.ob[0] = -72;

		pauseCtx->infoPanelVtx[j + 1].v.ob[0] = pauseCtx->infoPanelVtx[j + 3].v.ob[0] = 0;

		pauseCtx->infoPanelVtx[j + 0].v.ob[1] = pauseCtx->infoPanelVtx[j + 1].v.ob[1] = temp;

		pauseCtx->infoPanelVtx[j + 2].v.ob[1] = pauseCtx->infoPanelVtx[j + 3].v.ob[1] = temp - 24;

		pauseCtx->infoPanelVtx[j + 0].v.ob[2] = pauseCtx->infoPanelVtx[j + 1].v.ob[2] = pauseCtx->infoPanelVtx[j + 2].v.ob[2] = pauseCtx->infoPanelVtx[j + 3].v.ob[2] = 0;

		pauseCtx->infoPanelVtx[j + 0].v.flag = pauseCtx->infoPanelVtx[j + 1].v.flag = pauseCtx->infoPanelVtx[j + 2].v.flag = pauseCtx->infoPanelVtx[j + 3].v.flag = 0;

		pauseCtx->infoPanelVtx[j + 0].v.tc[0] = pauseCtx->infoPanelVtx[j + 0].v.tc[1] = pauseCtx->infoPanelVtx[j + 1].v.tc[1] = pauseCtx->infoPanelVtx[j + 2].v.tc[0] = 0;

		pauseCtx->infoPanelVtx[j + 1].v.tc[0] = pauseCtx->infoPanelVtx[j + 3].v.tc[0] = 0x900;

		pauseCtx->infoPanelVtx[j + 2].v.tc[1] = pauseCtx->infoPanelVtx[j + 3].v.tc[1] = 0x300;

		pauseCtx->infoPanelVtx[j + 0].v.cn[0] = pauseCtx->infoPanelVtx[j + 2].v.cn[0] = pauseCtx->infoPanelVtx[j + 0].v.cn[1] = pauseCtx->infoPanelVtx[j + 2].v.cn[1] = pauseCtx->infoPanelVtx[j + 0].v.cn[2] = pauseCtx->infoPanelVtx[j + 2].v.cn[2] =
		    pauseCtx->infoPanelVtx[j + 1].v.cn[0] = pauseCtx->infoPanelVtx[j + 3].v.cn[0] = pauseCtx->infoPanelVtx[j + 1].v.cn[1] = pauseCtx->infoPanelVtx[j + 3].v.cn[1] = pauseCtx->infoPanelVtx[j + 1].v.cn[2] =
			pauseCtx->infoPanelVtx[j + 3].v.cn[2] = 200;

		pauseCtx->infoPanelVtx[j + 0].v.cn[3] = pauseCtx->infoPanelVtx[j + 2].v.cn[3] = pauseCtx->infoPanelVtx[j + 1].v.cn[3] = pauseCtx->infoPanelVtx[j + 3].v.cn[3] = pauseCtx->alpha;
	}

	pauseCtx->infoPanelVtx[4].v.ob[0] = pauseCtx->infoPanelVtx[6].v.ob[0] = pauseCtx->infoPanelVtx[0].v.ob[0] + 72;

	pauseCtx->infoPanelVtx[5].v.ob[0] = pauseCtx->infoPanelVtx[7].v.ob[0] = pauseCtx->infoPanelVtx[4].v.ob[0] + 72;

	if((pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) && (pauseCtx->unk_1E4 == 0))
	{
		pauseCtx->infoPanelVtx[8].v.ob[0] = pauseCtx->infoPanelVtx[10].v.ob[0] = PAUSE_LEFT_CARET;

		pauseCtx->infoPanelVtx[9].v.ob[0] = pauseCtx->infoPanelVtx[11].v.ob[0] = pauseCtx->infoPanelVtx[8].v.ob[0] + 24;

		pauseCtx->infoPanelVtx[8].v.ob[1] = pauseCtx->infoPanelVtx[9].v.ob[1] = WREG(18);

		pauseCtx->infoPanelVtx[10].v.ob[1] = pauseCtx->infoPanelVtx[11].v.ob[1] = pauseCtx->infoPanelVtx[8].v.ob[1] - 32;
	}
	else
	{
		pauseCtx->infoPanelVtx[8].v.ob[0] = pauseCtx->infoPanelVtx[10].v.ob[0] = PAUSE_LEFT_CARET + 3;

		pauseCtx->infoPanelVtx[9].v.ob[0] = pauseCtx->infoPanelVtx[11].v.ob[0] = pauseCtx->infoPanelVtx[8].v.ob[0] + 18;

		pauseCtx->infoPanelVtx[8].v.ob[1] = pauseCtx->infoPanelVtx[9].v.ob[1] = WREG(18) - 3;

		pauseCtx->infoPanelVtx[10].v.ob[1] = pauseCtx->infoPanelVtx[11].v.ob[1] = pauseCtx->infoPanelVtx[8].v.ob[1] - 26;
	}

	if((pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT) && (pauseCtx->unk_1E4 == 0))
	{
		pauseCtx->infoPanelVtx[12].v.ob[0] = pauseCtx->infoPanelVtx[14].v.ob[0] = PAUSE_RIGHT_CARET;

		pauseCtx->infoPanelVtx[13].v.ob[0] = pauseCtx->infoPanelVtx[15].v.ob[0] = pauseCtx->infoPanelVtx[12].v.ob[0] + 24;

		pauseCtx->infoPanelVtx[12].v.ob[1] = pauseCtx->infoPanelVtx[13].v.ob[1] = WREG(18);

		pauseCtx->infoPanelVtx[14].v.ob[1] = pauseCtx->infoPanelVtx[15].v.ob[1] = pauseCtx->infoPanelVtx[12].v.ob[1] - 32;
	}
	else
	{
		pauseCtx->infoPanelVtx[12].v.ob[0] = pauseCtx->infoPanelVtx[14].v.ob[0] = PAUSE_RIGHT_CARET + 3;

		pauseCtx->infoPanelVtx[13].v.ob[0] = pauseCtx->infoPanelVtx[15].v.ob[0] = pauseCtx->infoPanelVtx[12].v.ob[0] + 18;

		pauseCtx->infoPanelVtx[12].v.ob[1] = pauseCtx->infoPanelVtx[13].v.ob[1] = WREG(18) - 3;

		pauseCtx->infoPanelVtx[14].v.ob[1] = pauseCtx->infoPanelVtx[15].v.ob[1] = pauseCtx->infoPanelVtx[12].v.ob[1] - 26;
	}

	pauseCtx->infoPanelVtx[9].v.tc[0] = pauseCtx->infoPanelVtx[11].v.tc[0] = pauseCtx->infoPanelVtx[13].v.tc[0] = pauseCtx->infoPanelVtx[15].v.tc[0] = 0x300;

	pauseCtx->infoPanelVtx[10].v.tc[1] = pauseCtx->infoPanelVtx[11].v.tc[1] = pauseCtx->infoPanelVtx[14].v.tc[1] = pauseCtx->infoPanelVtx[15].v.tc[1] = 0x400;

	gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

	Matrix_Translate(0.0f, 0.0f, -144.0f, MTXMODE_NEW);
	Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);

	gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 1755), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 90, 100, 130, 255);
	gSPVertex(POLY_OPA_DISP++, &pauseCtx->infoPanelVtx[0], 16, 0);

	gSPDisplayList(POLY_OPA_DISP++, gItemNamePanelDL);

	if((pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) && (pauseCtx->unk_1E4 == 0))
	{
		gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_808321A0, D_808321A2, D_808321A4, D_808321A6);
	}

	gSPDisplayList(POLY_OPA_DISP++, gLButtonIconDL);

	gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 180, 210, 255, 220);

	if((pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT) && (pauseCtx->unk_1E4 == 0))
	{
		gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, D_808321A0, D_808321A2, D_808321A4, D_808321A6);
	}

	gSPDisplayList(POLY_OPA_DISP++, gRButtonIconDL);

	if(pauseCtx->cursorSpecialPos != 0)
	{
		j = (pauseCtx->cursorSpecialPos * 4) - 32;
		pauseCtx->cursorVtx[0].v.ob[0] = pauseCtx->infoPanelVtx[j].v.ob[0];
		pauseCtx->cursorVtx[0].v.ob[1] = pauseCtx->infoPanelVtx[j].v.ob[1];
		KaleidoScope_DrawCursor(globalCtx, gPages.current());
	}

	temp = pauseCtx->infoPanelOffsetY - 80;
	pauseCtx->infoPanelVtx[16].v.ob[1] = pauseCtx->infoPanelVtx[17].v.ob[1] = temp;

	pauseCtx->infoPanelVtx[18].v.ob[1] = pauseCtx->infoPanelVtx[19].v.ob[1] = pauseCtx->infoPanelVtx[16].v.ob[1] - 16;

	pauseCtx->infoPanelVtx[18].v.tc[1] = pauseCtx->infoPanelVtx[19].v.tc[1] = 0x200;

	gDPPipeSync(POLY_OPA_DISP++);
	gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetEnvColor(POLY_OPA_DISP++, 20, 30, 40, 0);

	if((pauseCtx->state == 6) && (pauseCtx->namedItem != PAUSE_ITEM_NONE) && (pauseCtx->nameDisplayTimer < WREG(89)) &&
	   (!pauseCtx->unk_1E4 || (pauseCtx->unk_1E4 == 2) || ((pauseCtx->unk_1E4 >= 4) && (pauseCtx->unk_1E4 <= 7)) || (pauseCtx->unk_1E4 == 8)) && (pauseCtx->cursorSpecialPos == 0))
	{
		if(!pauseCtx->unk_1E4 || (pauseCtx->unk_1E4 == 2) || ((pauseCtx->unk_1E4 >= 4) && (pauseCtx->unk_1E4 <= 7)) || (pauseCtx->unk_1E4 == 8))
		{
			pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = -63;

			pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 128;

			pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x1000;

			gSPVertex(POLY_OPA_DISP++, &pauseCtx->infoPanelVtx[16], 4, 0);

			if(pauseCtx->nameColorSet == 1)
			{
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 70, 70, 70, 255);
			}
			else
			{
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
			}

			gPages.current()->drawInfo(globalCtx, __gfxCtx);
		}

#ifdef DEBUG_ROM // Debug feature to test skulltula
		if(pauseCtx->pageIndex == PAUSE_MAP)
		{
			if(YREG(7) != 0)
			{
				osSyncPrintf(VT_FGCOL(YELLOW));
				osSyncPrintf("キンスタ数(%d) Get_KIN_STA=%x (%x)  (%x)\n", YREG(6), GET_GS_FLAGS(YREG(6)), gAreaGsFlags[YREG(6)], gSaveContext.gsFlags[YREG(6) >> 2]);
				osSyncPrintf(VT_RST);

				YREG(7) = 0;
				SET_GS_FLAGS(D_8082AE30[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]], gAreaGsFlags[D_8082AE30[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]]]);
			}
		}
#endif

		if((current->id() == PAUSE_MAP) && !sInDungeonScene)
		{
			auto worldMap = gPages.find(PAUSE_WORLD_MAP);
			if(GET_GS_FLAGS(D_8082AE30[worldMap->cursorPoint()]) == gAreaGsFlags[D_8082AE30[worldMap->cursorPoint()]])
			{
				pauseCtx->infoPanelVtx[24].v.ob[0] = pauseCtx->infoPanelVtx[26].v.ob[0] = -74;

				pauseCtx->infoPanelVtx[25].v.ob[0] = pauseCtx->infoPanelVtx[27].v.ob[0] = pauseCtx->infoPanelVtx[24].v.ob[0] + 19;

				pauseCtx->infoPanelVtx[24].v.ob[1] = pauseCtx->infoPanelVtx[25].v.ob[1] = pauseCtx->infoPanelVtx[24].v.ob[1] - 2;

				pauseCtx->infoPanelVtx[26].v.ob[1] = pauseCtx->infoPanelVtx[27].v.ob[1] = pauseCtx->infoPanelVtx[24].v.ob[1] - 19;

				pauseCtx->infoPanelVtx[25].v.tc[0] = pauseCtx->infoPanelVtx[27].v.tc[0] = 0x300;

				gDPPipeSync(POLY_OPA_DISP++);
				gSPVertex(POLY_OPA_DISP++, &pauseCtx->infoPanelVtx[24], 4, 0);

				gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
				gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

				KaleidoScope_DrawQuadTextureRGBA32(globalCtx->gfxCtx, gGoldSkulltulaIconTex, 24, 24, 0);
			}
		}
	}
	else if((pauseCtx->unk_1E4 < 3) || (pauseCtx->unk_1E4 == 7) || (pauseCtx->unk_1E4 == 8))
	{
		pauseCtx->infoPanelVtx[20].v.ob[1] = pauseCtx->infoPanelVtx[21].v.ob[1] = temp;

		pauseCtx->infoPanelVtx[22].v.ob[1] = pauseCtx->infoPanelVtx[23].v.ob[1] = pauseCtx->infoPanelVtx[20].v.ob[1] - 16;

		pauseCtx->infoPanelVtx[22].v.tc[1] = pauseCtx->infoPanelVtx[23].v.tc[1] = 0x200;

		gSPVertex(POLY_OPA_DISP++, &pauseCtx->infoPanelVtx[16], 8, 0);

		if(pauseCtx->state == 7)
		{
			pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = WREG(61 + gSaveContext.language);

			pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 24;

			pauseCtx->infoPanelVtx[20].v.ob[0] = pauseCtx->infoPanelVtx[22].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + WREG(52 + gSaveContext.language);

			pauseCtx->infoPanelVtx[21].v.ob[0] = pauseCtx->infoPanelVtx[23].v.ob[0] = pauseCtx->infoPanelVtx[20].v.ob[0] + D_8082ADE0[gSaveContext.language];

			pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x300;

			pauseCtx->infoPanelVtx[21].v.tc[0] = pauseCtx->infoPanelVtx[23].v.tc[0] = D_8082ADE0[gSaveContext.language] << 5;

			gSPDisplayList(POLY_OPA_DISP++, gAButtonIconDL);

			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

			POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, D_8082AD60[gSaveContext.language], D_8082ADE0[gSaveContext.language], 16, 4);
		}
		else if(pauseCtx->cursorSpecialPos != 0)
		{
			if((pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0))
			{
				pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = -63;

				pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 128;

				pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x1000;

				gDPPipeSync(POLY_OPA_DISP++);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 200, 0, 255);

				u8* tex;

				if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT)
				{
					tex = gPages.prev(pauseCtx->pageIndex)->infoPanelTexture(gSaveContext.language);
				}
				else
				{
					tex = gPages.next(pauseCtx->pageIndex)->infoPanelTexture(gSaveContext.language);
				}

				if(tex)
				{
					POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, tex, 128, 16, 0);
				}
			}
		}
		else
		{
			auto quest = gPages.find(PAUSE_QUEST);

			if(current->id() == PAUSE_ITEM)
			{
				pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = WREG(49 + gSaveContext.language);

				pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 48;

				pauseCtx->infoPanelVtx[20].v.ob[0] = pauseCtx->infoPanelVtx[22].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + WREG(58 + gSaveContext.language);

				pauseCtx->infoPanelVtx[21].v.ob[0] = pauseCtx->infoPanelVtx[23].v.ob[0] = pauseCtx->infoPanelVtx[20].v.ob[0] + D_8082ADD8[gSaveContext.language];

				pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x600;

				pauseCtx->infoPanelVtx[21].v.tc[0] = pauseCtx->infoPanelVtx[23].v.tc[0] = D_8082ADD8[gSaveContext.language] << 5;

				gSPDisplayList(POLY_OPA_DISP++, gCButtonIconsDL);

				gDPPipeSync(POLY_OPA_DISP++);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

				POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, D_8082AD54[gSaveContext.language], D_8082ADD8[gSaveContext.language], 16, 4);
			}
			else if((current->id() == PAUSE_MAP) && sInDungeonScene)
			{
			}
			else if((current->id() == PAUSE_QUEST) && (quest->cursorSlot() >= 6) && (quest->cursorSlot() <= 0x11))
			{
				if(pauseCtx->namedItem != PAUSE_ITEM_NONE)
				{
					pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = WREG(55 + gSaveContext.language);

					pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 24;

					pauseCtx->infoPanelVtx[20].v.ob[0] = pauseCtx->infoPanelVtx[22].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + WREG(52 + gSaveContext.language);

					if(gSaveContext.language == LANGUAGE_GER)
					{
						pauseCtx->infoPanelVtx[20].v.ob[0] = pauseCtx->infoPanelVtx[22].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] - 99;
					}

					pauseCtx->infoPanelVtx[21].v.ob[0] = pauseCtx->infoPanelVtx[23].v.ob[0] = pauseCtx->infoPanelVtx[20].v.ob[0] + D_8082ADE8[gSaveContext.language];

					pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x300;

					pauseCtx->infoPanelVtx[21].v.tc[0] = pauseCtx->infoPanelVtx[23].v.tc[0] = D_8082ADE8[gSaveContext.language] << 5;

					gSPDisplayList(POLY_OPA_DISP++, gAButtonIconDL);

					gDPPipeSync(POLY_OPA_DISP++);
					gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

					POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, D_8082AD6C[gSaveContext.language], D_8082ADE8[gSaveContext.language], 16, 4);
				}
			}
			else if(current->id() == PAUSE_EQUIP)
			{
				pauseCtx->infoPanelVtx[16].v.ob[0] = pauseCtx->infoPanelVtx[18].v.ob[0] = WREG(64 + gSaveContext.language);

				pauseCtx->infoPanelVtx[17].v.ob[0] = pauseCtx->infoPanelVtx[19].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + 24;

				pauseCtx->infoPanelVtx[20].v.ob[0] = pauseCtx->infoPanelVtx[22].v.ob[0] = pauseCtx->infoPanelVtx[16].v.ob[0] + WREG(52 + gSaveContext.language);

				pauseCtx->infoPanelVtx[21].v.ob[0] = pauseCtx->infoPanelVtx[23].v.ob[0] = pauseCtx->infoPanelVtx[20].v.ob[0] + D_8082ADD8[gSaveContext.language];

				pauseCtx->infoPanelVtx[17].v.tc[0] = pauseCtx->infoPanelVtx[19].v.tc[0] = 0x300;

				pauseCtx->infoPanelVtx[21].v.tc[0] = pauseCtx->infoPanelVtx[23].v.tc[0] = D_8082ADD8[gSaveContext.language] << 5;

				gSPDisplayList(POLY_OPA_DISP++, gAButtonIconDL);

				gDPPipeSync(POLY_OPA_DISP++);
				gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

				POLY_OPA_DISP = KaleidoScope_QuadTextureIA8(POLY_OPA_DISP, D_8082AD54[gSaveContext.language], D_8082ADD8[gSaveContext.language], 16, 4);
			}
		}
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 2032);
}

void KaleidoScope_UpdateNamePanel(GlobalContext* globalCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	u16 sp2A;
	auto current = gPages.current();

	auto page = gPages.current();

	if((pauseCtx->namedItem != page->cursorItem()) || ((current->id() == PAUSE_MAP) && (pauseCtx->cursorSpecialPos != 0)))
	{
		pauseCtx->namedItem = page->cursorItem();
		sp2A = pauseCtx->namedItem;

		// osCreateMesgQueue(&pauseCtx->loadQueue, &pauseCtx->loadMsg, 1);

		if(pauseCtx->namedItem != PAUSE_ITEM_NONE)
		{
			if((current->id() == PAUSE_MAP) && !sInDungeonScene)
			{
				if(gSaveContext.language)
				{
					sp2A += 12;
				}
				if(gSaveContext.language == LANGUAGE_FRA)
				{
					sp2A += 12;
				}

				pauseCtx->nameSegment = (u8*)map_name_static_lut[sp2A];
			}
			else if((current->id() == PAUSE_CONTROLLER))
			{
			}
			else
			{
				osSyncPrintf("zoom_name=%d\n", pauseCtx->namedItem);

				if(gSaveContext.language)
				{
					sp2A += 123;
				}
				if(gSaveContext.language == LANGUAGE_FRA)
				{
					sp2A += 123;
				}

				osSyncPrintf("J_N=%d  point=%d\n", gSaveContext.language, sp2A);

				pauseCtx->nameSegment = (u8*)item_name_static_lut[sp2A];
			}

			pauseCtx->nameDisplayTimer = 0;
		}
	}
	else if(pauseCtx->nameColorSet == 0)
	{
		auto quest = gPages.find(PAUSE_QUEST);
		auto equip = gPages.find(PAUSE_EQUIP);

		if(((current->id() == PAUSE_QUEST) && (quest->cursorSlot() >= 6) && (quest->cursorSlot() <= 0x11) && (pauseCtx->unk_1E4 == 8)) || (current->id() == PAUSE_ITEM) || ((current->id() == PAUSE_EQUIP) && (equip->cursorX() != 0)))
		{
			if(pauseCtx->namedItem != ITEM_SOLD_OUT)
			{
				pauseCtx->nameDisplayTimer++;
				if(pauseCtx->nameDisplayTimer > WREG(88))
				{
					pauseCtx->nameDisplayTimer = 0;
				}
			}
		}
		else
		{
			pauseCtx->nameDisplayTimer = 0;
		}
	}
	else
	{
		pauseCtx->nameDisplayTimer = 0;
	}
}

void KaleidoScope_Action_Rotating(GlobalContext* globalCtx, Input* input)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	s32 cond = false;

	if(ZREG(13) && !CHECK_BTN_ALL(input->press.button, BTN_L))
	{
		cond = true;
	}

	if(!cond)
	{
		float progress = gPages.rotate(globalCtx);
		pauseCtx->eye = gPages.eye();

		if(progress < 0.5f)
		{
			PAUSE_LEFT_CARET -= PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
			PAUSE_RIGHT_CARET -= PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
		}
		else
		{
			PAUSE_LEFT_CARET += PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
			PAUSE_RIGHT_CARET += PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
		}

		if(progress == 1.0f)
		{
			PAUSE_LEFT_CARET = PAUSE_LEFT_CARET_ORIGINAL_X;
			PAUSE_RIGHT_CARET = PAUSE_RIGHT_CARET_ORIGINAL_X;

			pauseCtx->rotAccum = 0;
			pauseCtx->unk_1E4 = 0;
		}
	}
}

void KaleidoScope_SetView(PauseContext* pauseCtx, f32 x, f32 y, f32 z, bool inverted = false)
{
	Vec3f eye;
	Vec3f lookAt;
	Vec3f up;

	if(inverted)
	{
		lookAt.x = x;
		lookAt.y = y;
		lookAt.z = z;
		eye.x = eye.y = eye.z = 0.0f;
	}
	else
	{
		eye.x = x;
		eye.y = y;
		eye.z = z;
		lookAt.x = lookAt.y = lookAt.z = 0.0f;
	}
	up.x = up.z = 0.0f;
	up.y = 1.0f;

	func_800AA358(&pauseCtx->view, &eye, &lookAt, &up);
	func_800AAA50(&pauseCtx->view, 127);
}

static u8 sPageColorR[][4] = {
    {10, 70, 70, 10}, {10, 90, 90, 10}, {80, 140, 140, 80}, {80, 120, 120, 80}, {80, 140, 140, 80}, {50, 110, 110, 50},

    {10, 70, 70, 10},
};
static u8 sPageColorG[][4] = {
    {50, 100, 100, 50}, {50, 100, 100, 50}, {40, 60, 60, 40}, {80, 120, 120, 80}, {40, 60, 60, 40}, {50, 110, 110, 50},

    {10, 70, 70, 10},
};
static u8 sPageColorB[][4] = {
    {80, 130, 130, 80}, {40, 60, 60, 40}, {30, 60, 60, 30}, {50, 70, 70, 50}, {30, 60, 60, 30}, {50, 110, 110, 50},

    {10, 70, 70, 10},
};

static s16 D_8082AE90[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AE94[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AE98[] = {
    0xFFDC, 0x000C, 0xFFEE, 0x0046, 0x0046, 0x0046, 0xFFA8, 0xFFA8, 0xFFA8, 0xFFA8, 0xFFA8, 0xFFA8, 0xFFA8, 0xFFA8, 0xFF96, 0xFFC2, 0xFFD8, 0x0000,
};
static s16 D_8082AEBC[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AEC0[] = {
    0x002F, 0xFFCF, 0xFFEF, 0xFFF1, 0xFFF7, 0x0018, 0x002B, 0x000E, 0x0009, 0x0026, 0x0052, 0x0047, 0xFFB4, 0xFFA9, 0xFF94, 0xFFCA,
    0xFFA3, 0xFFBD, 0xFFC8, 0xFFDF, 0xFFF6, 0x0001, 0x000E, 0x0018, 0x0023, 0x003A, 0x004A, 0x0059, 0x0000, 0xFFC6, 0x0013, 0x001C,
};
static s16 D_8082AF00[] = {
    0xFFB4, 0xFFC6, 0x000A, 0xFFC6, 0x000A, 0x0000,
};
static s16 D_8082AF0C[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF10[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF14[] = {
    0x0030, 0x0030, 0x0060, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0010, 0x0010, 0x0018, 0x0000,
};
static s16 D_8082AF38[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF3C[] = {
    0x0098, 0x0030, 0x0030, 0x0030, 0x0030, 0x0000,
};
static s16 D_8082AF48[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF4C[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF50[] = {
    0x001C, 0x001C, 0x002E, 0x001C, 0xFFFE, 0xFFE0, 0x0032, 0x0024, 0x0016, 0x0008, 0xFFFA, 0xFFEC, 0xFFDE, 0xFFD0, 0x0012, 0x0012, 0x0032, 0x0000,
};
static s16 D_8082AF74[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AF78[] = {
    0x000F, 0x0028, 0x000B, 0x002D, 0x0034, 0x0025, 0x0024, 0x0039, 0x0036, 0x0021, 0x001F, 0x002D, 0x0020, 0x002A, 0x0031, 0xFFF6,
    0x001F, 0x001B, 0x000F, 0xFFCF, 0x0008, 0x0026, 0x0007, 0x002F, 0x001E, 0x0001, 0xFFF7, 0x0019, 0x0000, 0x0001, 0xFFE0, 0xFFE6,
};
static s16 D_8082AFB8[] = {
    0x0024, 0x000A, 0x000A, 0xFFFA, 0xFFFA, 0x0000,
};
static s16 D_8082AFC4[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AFC8[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AFCC[] = {
    0x0055, 0x0055, 0x0010, 0x0018, 0x0018, 0x0018, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0018, 0x0000,
};
static s16 D_8082AFF0[] = {
    0x0000,
    0x0000,
};
static s16 D_8082AFF4[] = {
    0x0010, 0x0030, 0x0030, 0x0010, 0x0010, 0x0000,
};

static s16* D_8082B000[] = {
    D_8082AE90, D_8082AE94, D_8082AE98, D_8082AEBC, D_8082AEC0, D_8082AF00,
};

static s16* D_8082B018[] = {
    D_8082AF0C, D_8082AF10, D_8082AF14, D_8082AF38, D_8082AAEC, D_8082AF3C,
};

static s16* D_8082B030[] = {
    D_8082AF48, D_8082AF4C, D_8082AF50, D_8082AF74, D_8082AF78, D_8082AFB8,
};

static s16* D_8082B048[] = {
    D_8082AFC4, D_8082AFC8, D_8082AFCC, D_8082AFF0, D_8082AB2C, D_8082AFF4,
};

static s16 D_8082B060[] = {
    0xFFC6, 0x000B, 0x001E, 0x001E, 0x000F, 0x0026, 0xFFC2, 0x003C, 0x003D, 0xFFB2, 0xFED4, 0xFFAA, 0xFFBF, 0xFED4, 0xFED4, 0xFFEB, 0x000E, 0x000D, 0x0014, 0xFFDE, 0xFED4, 0x0000,
};

static s16 D_8082B08C[] = {
    0x0059, 0x0014, 0x000E, 0x0023, 0x0020, 0x0011, 0x0032, 0x0010, 0x0015, 0x0014, 0xFFFF, 0x0020, 0x0010, 0xFFFF, 0xFFFF, 0x0013, 0x0013, 0x0015, 0x0010, 0x0014, 0xFFFF, 0x0000,
};

static s16 D_8082B0B8[] = {
    0x0001, 0x000F, 0x0014, 0x0009, 0xFFE2, 0xFFEF, 0xFFDE, 0x000F, 0x001E, 0x0001, 0xFED4, 0x002A, 0x0007, 0xFED4, 0xFED4, 0x0018, 0x0024, 0x0035, 0x0025, 0xFFF3, 0xFED4, 0x0000,
};

static s16 D_8082B0E4[] = {
    0x0024, 0x000F, 0x0010, 0x0017, 0x0017, 0x0010, 0x0018, 0x000D, 0x0011, 0x0012, 0x0001, 0x0019, 0x000D, 0x0001, 0x0001, 0x000D, 0x0015, 0x000F, 0x000D, 0x000C, 0x0001, 0x0000,
};

s16 KaleidoScope_SetPageVertices(GlobalContext* globalCtx, Vtx* vtx, s16 pageId, s16 arg3)
{
	static s16 D_8082B110 = 0;
	static s16 D_8082B114 = 1;
	static s16 D_8082B118 = 0;
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	s16* ptr1;
	s16* ptr2;
	s16* ptr3;
	s16* ptr4;
	s16 phi_s2;
	s16 phi_t0;
	s16 phi_a1;
	s16 phi_a2;
	s16 phi_t3;
	s16 phi_t1;

	phi_t0 = -200; // x offset for rendered page

	for(phi_t1 = 0, phi_t3 = 0; phi_t3 < 3; phi_t3++)
	{
		phi_t0 += 80;

		for(phi_a1 = 80, phi_a2 = 0; phi_a2 < 5; phi_a2++, phi_t1 += 4, phi_a1 -= 32)
		{
			vtx[phi_t1 + 0].v.ob[0] = vtx[phi_t1 + 2].v.ob[0] = phi_t0;

			vtx[phi_t1 + 1].v.ob[0] = vtx[phi_t1 + 3].v.ob[0] = vtx[phi_t1 + 0].v.ob[0] + 80;

			vtx[phi_t1 + 0].v.ob[1] = vtx[phi_t1 + 1].v.ob[1] = phi_a1 + pauseCtx->offsetY;

			vtx[phi_t1 + 2].v.ob[1] = vtx[phi_t1 + 3].v.ob[1] = vtx[phi_t1 + 0].v.ob[1] - 32;

			vtx[phi_t1 + 0].v.ob[2] = vtx[phi_t1 + 1].v.ob[2] = vtx[phi_t1 + 2].v.ob[2] = vtx[phi_t1 + 3].v.ob[2] = 0;

			vtx[phi_t1 + 0].v.flag = 0;
			vtx[phi_t1 + 1].v.flag = 0;
			vtx[phi_t1 + 2].v.flag = 0;
			vtx[phi_t1 + 3].v.flag = 0;

			vtx[phi_t1 + 0].v.tc[0] = vtx[phi_t1 + 0].v.tc[1] = vtx[phi_t1 + 1].v.tc[1] = vtx[phi_t1 + 2].v.tc[0] = 0;

			vtx[phi_t1 + 1].v.tc[0] = vtx[phi_t1 + 3].v.tc[0] = 0xA00;

			vtx[phi_t1 + 2].v.tc[1] = vtx[phi_t1 + 3].v.tc[1] = 0x400;

			vtx[phi_t1 + 0].v.cn[0] = vtx[phi_t1 + 2].v.cn[0] = sPageColorR[pageId][phi_t3 + 0];

			vtx[phi_t1 + 0].v.cn[1] = vtx[phi_t1 + 2].v.cn[1] = sPageColorG[pageId][phi_t3 + 0];

			vtx[phi_t1 + 0].v.cn[2] = vtx[phi_t1 + 2].v.cn[2] = sPageColorB[pageId][phi_t3 + 0];

			vtx[phi_t1 + 1].v.cn[0] = vtx[phi_t1 + 3].v.cn[0] = sPageColorR[pageId][phi_t3 + 1];

			vtx[phi_t1 + 1].v.cn[1] = vtx[phi_t1 + 3].v.cn[1] = sPageColorG[pageId][phi_t3 + 1];

			vtx[phi_t1 + 1].v.cn[2] = vtx[phi_t1 + 3].v.cn[2] = sPageColorB[pageId][phi_t3 + 1];

			vtx[phi_t1 + 0].v.cn[3] = vtx[phi_t1 + 2].v.cn[3] = vtx[phi_t1 + 1].v.cn[3] = vtx[phi_t1 + 3].v.cn[3] = pauseCtx->alpha;
		}
	}

	phi_s2 = phi_t1;

	if(arg3 != 0)
	{
		ptr1 = D_8082B000[pageId];
		ptr2 = D_8082B018[pageId];
		ptr3 = D_8082B030[pageId];
		ptr4 = D_8082B048[pageId];

		for(phi_t3 = 0; phi_t3 < arg3; phi_t3++, phi_t1 += 4)
		{
			vtx[phi_t1 + 2].v.ob[0] = vtx[phi_t1 + 0].v.ob[0] = ptr1[phi_t3];

			vtx[phi_t1 + 1].v.ob[0] = vtx[phi_t1 + 3].v.ob[0] = vtx[phi_t1 + 0].v.ob[0] + ptr2[phi_t3];

			if(!((pauseCtx->state >= 8) && (pauseCtx->state <= 0x11)))
			{
				vtx[phi_t1 + 0].v.ob[1] = vtx[phi_t1 + 1].v.ob[1] = ptr3[phi_t3] + pauseCtx->offsetY;
			}
			else
			{
				vtx[phi_t1 + 0].v.ob[1] = vtx[phi_t1 + 1].v.ob[1] = YREG(60 + phi_t3) + pauseCtx->offsetY;
			}

			vtx[phi_t1 + 2].v.ob[1] = vtx[phi_t1 + 3].v.ob[1] = vtx[phi_t1 + 0].v.ob[1] - ptr4[phi_t3];

			vtx[phi_t1 + 0].v.ob[2] = vtx[phi_t1 + 1].v.ob[2] = vtx[phi_t1 + 2].v.ob[2] = vtx[phi_t1 + 3].v.ob[2] = 0;

			vtx[phi_t1 + 0].v.flag = vtx[phi_t1 + 1].v.flag = vtx[phi_t1 + 2].v.flag = vtx[phi_t1 + 3].v.flag = 0;

			vtx[phi_t1 + 0].v.tc[0] = vtx[phi_t1 + 0].v.tc[1] = vtx[phi_t1 + 1].v.tc[1] = vtx[phi_t1 + 2].v.tc[0] = 0;

			vtx[phi_t1 + 1].v.tc[0] = vtx[phi_t1 + 3].v.tc[0] = ptr2[phi_t3] << 5;

			vtx[phi_t1 + 2].v.tc[1] = vtx[phi_t1 + 3].v.tc[1] = ptr4[phi_t3] << 5;

			vtx[phi_t1 + 0].v.cn[0] = vtx[phi_t1 + 2].v.cn[0] = vtx[phi_t1 + 0].v.cn[1] = vtx[phi_t1 + 2].v.cn[1] = vtx[phi_t1 + 0].v.cn[2] = vtx[phi_t1 + 2].v.cn[2] = vtx[phi_t1 + 1].v.cn[0] = vtx[phi_t1 + 3].v.cn[0] =
			    vtx[phi_t1 + 1].v.cn[1] = vtx[phi_t1 + 3].v.cn[1] = vtx[phi_t1 + 1].v.cn[2] = vtx[phi_t1 + 3].v.cn[2] = 255;

			vtx[phi_t1 + 0].v.cn[3] = vtx[phi_t1 + 2].v.cn[3] = vtx[phi_t1 + 1].v.cn[3] = vtx[phi_t1 + 3].v.cn[3] = pauseCtx->alpha;
		}

		if(pageId == 4)
		{
			phi_t1 -= 12;

			phi_t3 = gSaveContext.worldMapArea;

			vtx[phi_t1 + 0].v.ob[0] = vtx[phi_t1 + 2].v.ob[0] = D_8082B060[phi_t3];

			vtx[phi_t1 + 1].v.ob[0] = vtx[phi_t1 + 3].v.ob[0] = vtx[phi_t1 + 0].v.ob[0] + D_8082B08C[phi_t3];

			vtx[phi_t1 + 0].v.ob[1] = vtx[phi_t1 + 1].v.ob[1] = D_8082B0B8[phi_t3] + pauseCtx->offsetY;

			vtx[phi_t1 + 2].v.ob[1] = vtx[phi_t1 + 3].v.ob[1] = vtx[phi_t1 + 0].v.ob[1] - D_8082B0E4[phi_t3];

			phi_t1 += 12;

			if(pauseCtx->tradeQuestLocation != 0xFF)
			{
				if(D_8082B114 == 0)
				{
					D_8082B118++;
					switch(D_8082B118)
					{
						case 1:
							D_8082B110 = 3;
							D_8082B114 = 8;
							break;
						case 2:
							D_8082B110 = 0;
							D_8082B114 = 6;
							D_8082B118 = 0;
							break;
					}
				}
				else
				{
					D_8082B114--;
				}

				phi_t3 = phi_s2 + (pauseCtx->tradeQuestLocation * 4) + 64;
				phi_a2 = phi_s2 + 116;

				vtx[phi_a2 + 0].v.ob[0] = vtx[phi_a2 + 2].v.ob[0] = vtx[phi_t3 + 0].v.ob[0];

				vtx[phi_a2 + 1].v.ob[0] = vtx[phi_a2 + 3].v.ob[0] = vtx[phi_a2 + 0].v.ob[0] + 8;

				vtx[phi_a2 + 0].v.ob[1] = vtx[phi_a2 + 1].v.ob[1] = vtx[phi_t3 + 0].v.ob[1] - D_8082B110 + 10;

				vtx[phi_a2 + 0].v.ob[2] = vtx[phi_a2 + 1].v.ob[2] = vtx[phi_a2 + 2].v.ob[2] = vtx[phi_a2 + 3].v.ob[2] = 0;

				vtx[phi_a2 + 2].v.ob[1] = vtx[phi_a2 + 3].v.ob[1] = vtx[phi_a2 + 0].v.ob[1] - 8;

				vtx[phi_a2 + 0].v.flag = vtx[phi_a2 + 1].v.flag = vtx[phi_a2 + 2].v.flag = vtx[phi_a2 + 3].v.flag = 0;

				vtx[phi_t1].v.tc[0] = vtx[phi_t1].v.tc[1] = vtx[phi_a2 + 1].v.tc[1] = vtx[phi_a2 + 2].v.tc[0] = 0;

				vtx[phi_a2 + 1].v.tc[0] = vtx[phi_a2 + 3].v.tc[0] = 0x100;

				vtx[phi_a2 + 2].v.tc[1] = vtx[phi_a2 + 3].v.tc[1] = 0x100;

				vtx[phi_a2 + 0].v.cn[0] = vtx[phi_a2 + 2].v.cn[0] = vtx[phi_a2 + 0].v.cn[1] = vtx[phi_a2 + 2].v.cn[1] = vtx[phi_a2 + 0].v.cn[2] = vtx[phi_a2 + 2].v.cn[2] = vtx[phi_a2 + 1].v.cn[0] = vtx[phi_a2 + 3].v.cn[0] =
				    vtx[phi_a2 + 1].v.cn[1] = vtx[phi_a2 + 3].v.cn[1] = vtx[phi_a2 + 1].v.cn[2] = vtx[phi_a2 + 3].v.cn[2] = 255;

				vtx[phi_a2 + 0].v.cn[3] = vtx[phi_a2 + 2].v.cn[3] = vtx[phi_a2 + 1].v.cn[3] = vtx[phi_a2 + 3].v.cn[3] = pauseCtx->alpha;
			}
		}
	}

	return phi_t1;
}

void KaleidoScope_InitVertices(GlobalContext* globalCtx, GraphicsContext* gfxCtx)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	s16 phi_t1;
	s16 phi_t2;
	s16 phi_t2_2;
	s16 phi_t3;
	s16 phi_t4;
	s16 phi_t5;

	pauseCtx->offsetY = 0;

	if((pauseCtx->state == 4) || (pauseCtx->state >= 0x12) || ((pauseCtx->state == 7) && ((pauseCtx->unk_1EC == 2) || (pauseCtx->unk_1EC == 5))) || ((pauseCtx->state >= 8) && (pauseCtx->state <= 0xD)))
	{
		pauseCtx->offsetY = 80;
	}

	gPages.initVerticies(globalCtx);

	for(phi_t2 = 0; phi_t2 < 20; phi_t2++)
	{
		pauseCtx->cursorVtx[phi_t2].v.ob[0] = pauseCtx->cursorVtx[phi_t2].v.ob[1] = pauseCtx->cursorVtx[phi_t2].v.ob[2] = 0;

		pauseCtx->cursorVtx[phi_t2].v.flag = 0;

		pauseCtx->cursorVtx[phi_t2].v.tc[0] = pauseCtx->cursorVtx[phi_t2].v.tc[1] = 0;

		pauseCtx->cursorVtx[phi_t2].v.cn[0] = pauseCtx->cursorVtx[phi_t2].v.cn[1] = pauseCtx->cursorVtx[phi_t2].v.cn[2] = pauseCtx->cursorVtx[phi_t2].v.cn[3] = 255;
	}

	pauseCtx->cursorVtx[1].v.tc[0] = pauseCtx->cursorVtx[2].v.tc[1] = pauseCtx->cursorVtx[3].v.tc[0] = pauseCtx->cursorVtx[3].v.tc[1] = pauseCtx->cursorVtx[5].v.tc[0] = pauseCtx->cursorVtx[6].v.tc[1] = pauseCtx->cursorVtx[7].v.tc[0] =
	    pauseCtx->cursorVtx[7].v.tc[1] = pauseCtx->cursorVtx[9].v.tc[0] = pauseCtx->cursorVtx[10].v.tc[1] = pauseCtx->cursorVtx[11].v.tc[0] = pauseCtx->cursorVtx[11].v.tc[1] = pauseCtx->cursorVtx[13].v.tc[0] = pauseCtx->cursorVtx[14].v.tc[1] =
		pauseCtx->cursorVtx[15].v.tc[0] = pauseCtx->cursorVtx[15].v.tc[1] = 0x200;

	pauseCtx->cursorVtx[17].v.tc[0] = pauseCtx->cursorVtx[18].v.tc[1] = pauseCtx->cursorVtx[19].v.tc[0] = pauseCtx->cursorVtx[19].v.tc[1] = 0x400;

	pauseCtx->infoPanelVtx = (Vtx*)Graph_Alloc(gfxCtx, 28 * sizeof(Vtx));

	pauseCtx->saveVtx = (Vtx*)Graph_Alloc(gfxCtx, 80 * sizeof(Vtx));
	KaleidoScope_SetPageVertices(globalCtx, pauseCtx->saveVtx, 5, 5);
}

void KaleidoScope_DrawGameOver(GlobalContext* globalCtx)
{
	GraphicsContext* gfxCtx = globalCtx->gfxCtx;

	OPEN_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 3122);

	func_800944C4(gfxCtx);

	gDPSetCycleType(POLY_OPA_DISP++, G_CYC_2CYCLE);
	gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_XLU_SURF2);
	gDPSetCombineLERP(POLY_OPA_DISP++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);

	gDPSetPrimColor(POLY_OPA_DISP++, 0, 80, D_8082AB8C, D_8082AB90, D_8082AB94, D_8082AB98);
	gDPSetEnvColor(POLY_OPA_DISP++, D_8082AB9C, D_8082ABA0, D_8082ABA4, 255);

	VREG(89) -= 2;

	gDPLoadMultiBlock(POLY_OPA_DISP++, gGameOverP1Tex, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

	gDPLoadMultiBlock(POLY_OPA_DISP++, gGameOverMaskTex, 256, 1, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, 5, G_TX_NOLOD, G_TX_NOLOD);

	gDPSetTileSize(POLY_OPA_DISP++, 1, 0, VREG(89) & 0x7F, 252, (VREG(89) & 0x7F) + 0x7C);

	gSPTextureRectangle(POLY_OPA_DISP++, VREG(87) << 2, VREG(88) << 2, (VREG(87) + 64) << 2, (VREG(88) + 32) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

	gDPLoadMultiBlock(POLY_OPA_DISP++, gGameOverP2Tex, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

	gSPTextureRectangle(POLY_OPA_DISP++, (VREG(87) + 64) << 2, VREG(88) << 2, (VREG(87) + 128) << 2, (VREG(88) + 32) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

	gDPLoadMultiBlock(POLY_OPA_DISP++, gGameOverP3Tex, 0, 0, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSPTextureRectangle(POLY_OPA_DISP++, (VREG(87) + 128) << 2, VREG(88) << 2, (VREG(87) + 192) << 2, (VREG(88) + 32) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

	CLOSE_DISPS(gfxCtx, "../z_kaleido_scope_PAL.c", 3169);
}

void KaleidoScope_Draw(GlobalContext* globalCtx)
{
	Input* input = &globalCtx->input[0];
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

	OPEN_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 3188);

	pauseCtx->stickRelX = input->rel.stick_x;
	pauseCtx->stickRelY = input->rel.stick_y;

	gSPSegment(POLY_OPA_DISP++, 0x02, interfaceCtx->parameterSegment);
	gSPSegment(POLY_OPA_DISP++, 0x07, pauseCtx->playerSegment);
	gSPSegment(POLY_OPA_DISP++, 0x08, pauseCtx->iconItemSegment);
	gSPSegment(POLY_OPA_DISP++, 0x09, pauseCtx->iconItem24Segment);
	gSPSegment(POLY_OPA_DISP++, 0x0A, pauseCtx->nameSegment);
	gSPSegment(POLY_OPA_DISP++, 0x0C, pauseCtx->iconItemAltSegment);
	gSPSegment(POLY_OPA_DISP++, 0x0D, pauseCtx->iconItemLangSegment);

	if(pauseCtx->debugState == 0)
	{
		KaleidoScope_SetView(pauseCtx, pauseCtx->eye.pos.x, pauseCtx->eye.pos.y, pauseCtx->eye.pos.z, pauseCtx->eye.inverted);

		func_800949A8(globalCtx->gfxCtx);
		KaleidoScope_InitVertices(globalCtx, globalCtx->gfxCtx);
		KaleidoScope_DrawPages(globalCtx, globalCtx->gfxCtx);

		func_800949A8(globalCtx->gfxCtx);
		gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

		KaleidoScope_SetView(pauseCtx, 0.0f, 0.0f, 64.0f);

		if(!((pauseCtx->state >= 8) && (pauseCtx->state <= 0x11)))
		{
			KaleidoScope_DrawInfoPanel(globalCtx);
		}
	}

	if((pauseCtx->state >= 0xB) && (pauseCtx->state <= 0x11))
	{
		KaleidoScope_DrawGameOver(globalCtx);
	}

	if((pauseCtx->debugState == 1) || (pauseCtx->debugState == 2))
	{
		KaleidoScope_DrawDebugEditor(globalCtx);
	}

	CLOSE_DISPS(globalCtx->gfxCtx, "../z_kaleido_scope_PAL.c", 3254);
}

#ifndef N64_VERSION
void KaleidoScope_GrayOutTextureRGBA32(u32* textureIn, u32* textureOut, u16 pixelCount)
{
	u32 rgb;
	u8 a;
	u16 gray;
	u16 i;

#ifndef LITTLE_ENDIAN
	for(i = 0; i < pixelCount; i++)
	{
		if((textureIn[i] & 0xFFFFFF00) != 0)
		{
			rgb = textureIn[i] >> 8;
			gray = ((((rgb & 0xFF0000) >> 16) + ((rgb & 0xFF00) >> 7) + (rgb & 0xFF)) / 7) & 0xFF;

			rgb = gray;
			rgb <<= 8;
			rgb |= gray;
			rgb <<= 8;
			rgb |= gray;

			textureOut[i] = (rgb << 8) | (textureIn[i] & 0xFF);
		}
#else
	for(i = 0; i < pixelCount; i++)
	{
		if((textureIn[i] & 0x00FFFFFF) != 0)
		{
			rgb = textureIn[i] & 0x00FFFFFF;
			gray = ((((rgb & 0xFF0000) >> 16) + ((rgb & 0xFF00) >> 7) + (rgb & 0xFF)) / 7) & 0xFF;

			rgb = gray;
			rgb <<= 8;
			rgb |= gray;
			rgb <<= 8;
			rgb |= gray;

			textureOut[i] = (textureIn[i] & 0xFF000000) | rgb;
		}
		else
			textureOut[i] = textureIn[i];
	}
#endif
	}
#else
void KaleidoScope_GrayOutTextureRGBA32(u32* texture, u16 pixelCount)
{
	u32 rgb;
	u16 gray;
	u16 i;

#ifndef LITTLE_ENDIAN
	for(i = 0; i < pixelCount; i++)
	{
		if((texture[i] & 0xFFFFFF00) != 0)
		{
			rgb = texture[i] >> 8;
			gray = ((((rgb & 0xFF0000) >> 16) + ((rgb & 0xFF00) >> 7) + (rgb & 0xFF)) / 7) & 0xFF;

			rgb = gray;
			rgb <<= 8;
			rgb |= gray;
			rgb <<= 8;
			rgb |= gray;

			texture[i] = (rgb << 8) | (texture[i] & 0xFF);
		}
#else
	for(i = 0; i < pixelCount; i++)
	{
		if((texture[i] & 0x00FFFFFF) != 0)
		{
			rgb = texture[i] & 0x00FFFFFF;
			gray = ((((rgb & 0xFF0000) >> 16) + ((rgb & 0xFF00) >> 7) + (rgb & 0xFF)) / 7) & 0xFF;

			rgb = gray;
			rgb <<= 8;
			rgb |= gray;
			rgb <<= 8;
			rgb |= gray;

			texture[i] = (texture[i] & 0xFF000000) | rgb;
		}
	}
#endif
	}
#endif

	void func_808265BC(GlobalContext * globalCtx)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		float progress = gPages.rotate(globalCtx);
		pauseCtx->eye = gPages.eye();

		if(progress == 1.0f && pauseCtx->state != 4)
		{
			func_80084BF4(globalCtx, 1);
			gSaveContext.buttonStatus[0] = gButtonStates[pauseCtx->pageIndex][0];
			gSaveContext.buttonStatus[1] = gButtonStates[pauseCtx->pageIndex][1];
			gSaveContext.buttonStatus[2] = gButtonStates[pauseCtx->pageIndex][2];
			gSaveContext.buttonStatus[3] = gButtonStates[pauseCtx->pageIndex][3];
			gSaveContext.buttonStatus[4] = gButtonStates[pauseCtx->pageIndex][4];
			// pauseCtx->pageIndex	     = gPages.current()->index();
			pauseCtx->unk_1E4 = 0;
			pauseCtx->state++;
			pauseCtx->alpha = 255;
			Interface_LoadActionLabelB(globalCtx, DO_ACTION_SAVE);
		}
	}

	void KaleidoScope_UpdateCursorSize(GlobalContext * globalCtx)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		s32 offset_x;
		s32 offset_y;
		s32 width;
		s32 height;

		if(pauseCtx->cursorSpecialPos == 0)
		{
			auto current = gPages.current();
			current->setCursorMetrics(offset_x, offset_y, width, height);
		}
		else
		{
			offset_x = -4;
			offset_y = 4;
			width = 16;
			height = 16;
		}

		pauseCtx->cursorVtx[0].v.ob[0] = pauseCtx->cursorVtx[2].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0] + offset_x;
		pauseCtx->cursorVtx[1].v.ob[0] = pauseCtx->cursorVtx[3].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0] + 16;
		pauseCtx->cursorVtx[0].v.ob[1] = pauseCtx->cursorVtx[1].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1] + offset_y;
		pauseCtx->cursorVtx[2].v.ob[1] = pauseCtx->cursorVtx[3].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1] - 16;

		pauseCtx->cursorVtx[4].v.ob[0] = pauseCtx->cursorVtx[6].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0] + width;
		pauseCtx->cursorVtx[5].v.ob[0] = pauseCtx->cursorVtx[7].v.ob[0] = pauseCtx->cursorVtx[4].v.ob[0] + 16;
		pauseCtx->cursorVtx[4].v.ob[1] = pauseCtx->cursorVtx[5].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1];
		pauseCtx->cursorVtx[6].v.ob[1] = pauseCtx->cursorVtx[7].v.ob[1] = pauseCtx->cursorVtx[4].v.ob[1] - 16;

		pauseCtx->cursorVtx[8].v.ob[0] = pauseCtx->cursorVtx[10].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0];
		pauseCtx->cursorVtx[9].v.ob[0] = pauseCtx->cursorVtx[11].v.ob[0] = pauseCtx->cursorVtx[8].v.ob[0] + 16;
		pauseCtx->cursorVtx[8].v.ob[1] = pauseCtx->cursorVtx[9].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1] - height;
		pauseCtx->cursorVtx[10].v.ob[1] = pauseCtx->cursorVtx[11].v.ob[1] = pauseCtx->cursorVtx[8].v.ob[1] - 16;

		pauseCtx->cursorVtx[12].v.ob[0] = pauseCtx->cursorVtx[14].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0] + width;
		pauseCtx->cursorVtx[13].v.ob[0] = pauseCtx->cursorVtx[15].v.ob[0] = pauseCtx->cursorVtx[12].v.ob[0] + 16;
		pauseCtx->cursorVtx[12].v.ob[1] = pauseCtx->cursorVtx[13].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1] - height;
		pauseCtx->cursorVtx[14].v.ob[1] = pauseCtx->cursorVtx[15].v.ob[1] = pauseCtx->cursorVtx[12].v.ob[1] - 16;
	}

	void KaleidoScope_LoadDungeonMap(GlobalContext * globalCtx)
	{
		InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
		s32 pad;

		interfaceCtx->mapSegment1 = (u8*)map_48x85_static_lut[R_MAP_TEX_INDEX];
		interfaceCtx->mapSegment2 = (u8*)map_48x85_static_lut[R_MAP_TEX_INDEX + 1];
	}

	void KaleidoScope_UpdateDungeonMap(GlobalContext * globalCtx)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;

		osSyncPrintf("ＭＡＰ ＤＭＡ = %d\n", globalCtx->interfaceCtx.mapPaletteIndex);

		KaleidoScope_LoadDungeonMap(globalCtx);
		Map_SetFloorPalettesData(globalCtx, pauseCtx->dungeonMapSlot - 3);

		if((globalCtx->sceneNum >= SCENE_YDAN) && (globalCtx->sceneNum <= SCENE_TAKARAYA))
		{
			auto map = gPages.find(PAUSE_MAP);

			if((VREG(30) + 3) == map->cursorPoint())
			{
				KaleidoScope_OverridePalIndexCI4(interfaceCtx->mapSegment1, 2040, interfaceCtx->mapPaletteIndex, 14);
			}
		}

		if((globalCtx->sceneNum >= SCENE_YDAN) && (globalCtx->sceneNum <= SCENE_TAKARAYA))
		{
			auto map = gPages.find(PAUSE_MAP);

			if((VREG(30) + 3) == map->cursorPoint())
			{
				KaleidoScope_OverridePalIndexCI4(interfaceCtx->mapSegment2, 2040, interfaceCtx->mapPaletteIndex, 14);
			}
		}
	}

	void KaleidoScope_Update(GlobalContext * globalCtx)
	{
		static s16 D_8082B258 = 0;
		static s16 D_8082B25C = 10;
		static s16 D_8082B260 = 0;
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
		GameOverContext* gameOverCtx = &globalCtx->gameOverCtx;
		Player* player = GET_PLAYER(globalCtx);
		Input* input = &globalCtx->input[0];
		u32 size;
		u32 size0;
		u32 size1;
		u32 size2 = 0; // TODO FIX hack to stop compile until rest of code is fixed
		u16 i = 0;
		s16 stepR;
		s16 stepG;
		s16 stepB;
		s16 stepA;
		s32 pad;

		oot::hid::firstPersonDisable();

		if(gPages.size() == 0)
		{
			gPages.create();
		}

		if((R_PAUSE_MENU_MODE >= 3) && (((pauseCtx->state >= 4) && (pauseCtx->state <= 7)) || ((pauseCtx->state >= 0xA) && (pauseCtx->state <= 0x12))))
		{
			if((!pauseCtx->unk_1E4 || (pauseCtx->unk_1E4 == 8)) && (pauseCtx->state == 6))
			{
				pauseCtx->stickRelX = input->rel.stick_x;
				pauseCtx->stickRelY = input->rel.stick_y;
				KaleidoScope_HandlePageToggles(pauseCtx, input);
			}

			if(pauseCtx->state == 6)
			{
				KaleidoScope_UpdateNamePanel(globalCtx);
			}
		}

		switch(pauseCtx->state)
		{
			case 3: // initial setup
				D_808321A8[0] = gSaveContext.buttonStatus[0];
				D_808321A8[1] = gSaveContext.buttonStatus[1];
				D_808321A8[2] = gSaveContext.buttonStatus[2];
				D_808321A8[3] = gSaveContext.buttonStatus[3];
				D_808321A8[4] = gSaveContext.buttonStatus[4];

				PAUSE_LEFT_CARET = PAUSE_LEFT_CARET_ORIGINAL_X;
				PAUSE_RIGHT_CARET = PAUSE_RIGHT_CARET_ORIGINAL_X;
				PAUSE_ANIMATION_STEPS = 8 * framerate_get() / 30;

				pauseCtx->unk_204 = -314.0f;

				pauseCtx->playerSegment = (oot::pause::Segments*)(((uintptr_t)globalCtx->objectCtx.spaceStart + 0x30) & ~0x3F);

				func_80091738(globalCtx, pauseCtx->playerSegment, &pauseCtx->playerSkelAnime);

				pauseCtx->iconItemSegment = (u8*)icon_item_static_lut[0];
				gSegments[8] = (uintptr_t)VIRTUAL_TO_PHYSICAL(pauseCtx->iconItemSegment);

				// On N64 the textures of the icons are manipulated in RAM every time the pause menu opens.
				// This is fine since they are loaded again from ROM.
				// On PC these textures are generated in KaleidoScope_SetupGrayIcons()
				for(i = 0; i < ARRAY_COUNTU(gItemAgeReqs); i++)
				{
#ifdef N64_VERSION
					if((gItemAgeReqs[i] != 9) && (gItemAgeReqs[i] != ((void)0, gSaveContext.linkAge)))
					{
						KaleidoScope_GrayOutTextureRGBA32(SEGMENTED_TO_VIRTUAL(gItemIcons[i]), 0x400);
					}
#else
					if((gItemAgeReqs[i] != 9) && (gItemAgeReqs[i] != ((void)0, gSaveContext.linkAge)))
					{
						gItemIconsCurrent[i] = gItemIconsGray[i];
					}
					else
					{
						gItemIconsCurrent[i] = gItemIcons[i];
					}
#endif
				}

				pauseCtx->iconItem24Segment = (u8*)icon_item_24_static_lut[0];

				switch(globalCtx->sceneNum)
				{
					case SCENE_YDAN:
					case SCENE_DDAN:
					case SCENE_BDAN:
					case SCENE_BMORI1:
					case SCENE_HIDAN:
					case SCENE_MIZUSIN:
					case SCENE_JYASINZOU:
					case SCENE_HAKADAN:
					case SCENE_HAKADANCH:
					case SCENE_ICE_DOUKUTO:
					case SCENE_YDAN_BOSS:
					case SCENE_DDAN_BOSS:
					case SCENE_BDAN_BOSS:
					case SCENE_MORIBOSSROOM:
					case SCENE_FIRE_BS:
					case SCENE_MIZUSIN_BS:
					case SCENE_JYASINBOSS:
					case SCENE_HAKADAN_BS:
						sInDungeonScene = true;
						pauseCtx->iconItemAltSegment = _icon_item_dungeon_staticSegmentRomStart;

						interfaceCtx->mapPalette[28] = 6;
						interfaceCtx->mapPalette[29] = 99;
						KaleidoScope_UpdateDungeonMap(globalCtx);
						break;

					default:
						sInDungeonScene = false;
						pauseCtx->iconItemAltSegment = _icon_item_field_staticSegmentRomStart;
						break;
				}

				if(gSaveContext.language == LANGUAGE_ENG)
				{
					pauseCtx->iconItemLangSegment = _icon_item_nes_staticSegmentRomStart;
				}
				else if(gSaveContext.language == LANGUAGE_GER)
				{
					pauseCtx->iconItemLangSegment = _icon_item_ger_staticSegmentRomStart;
				}
				else
				{
					pauseCtx->iconItemLangSegment = _icon_item_fra_staticSegmentRomStart;
				}

				Interface_SetDoAction(globalCtx, DO_ACTION_DECIDE);

				if(((void)0, gSaveContext.worldMapArea) < 22)
				{
					if(gSaveContext.language == LANGUAGE_ENG)
					{
						pauseCtx->nameSegment2 = (u8*)map_name_static_lut[gSaveContext.worldMapArea + 36];
					}
					else if(gSaveContext.language == LANGUAGE_GER)
					{
						pauseCtx->nameSegment2 = (u8*)map_name_static_lut[gSaveContext.worldMapArea + 36 + 22];
					}
					else
					{
						pauseCtx->nameSegment2 = (u8*)map_name_static_lut[gSaveContext.worldMapArea + 36 + 22 + 22];
					}
				}

				PreRender_Init(&sPlayerPreRender);
				PreRender_SetValuesSave(&sPlayerPreRender, 64, 112, pauseCtx->playerSegment, NULL, pauseCtx->playerSegment->preRenderCvg);

				KaleidoScope_DrawPlayerWork(globalCtx);
				KaleidoScope_SetupPlayerPreRender(globalCtx);

				gPages.create();

				gPages.update();

				{
					auto map = gPages.find(PAUSE_MAP);
					map->cursorX() = 0;
					map->cursorSlot() = map->cursorPoint() = pauseCtx->dungeonMapSlot = VREG(30) + 3;
				}

				for(i = 0; i < ARRAY_COUNT(pauseCtx->worldMapPoints); i++)
				{
					pauseCtx->worldMapPoints[i] = 0;
				}

				if(CHECK_QUEST_ITEM(QUEST_GERUDO_CARD))
				{
					pauseCtx->worldMapPoints[0] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_MEDALLION_SPIRIT))
				{
					pauseCtx->worldMapPoints[0] = 1;
				}

				if(INV_CONTENT(ITEM_LONGSHOT) == ITEM_LONGSHOT)
				{
					pauseCtx->worldMapPoints[1] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_GERUDO_CARD))
				{
					pauseCtx->worldMapPoints[1] = 1;
				}

				if(gSaveContext.eventChkInf[11] & 4)
				{
					pauseCtx->worldMapPoints[2] = 1;
				}

				if(INV_CONTENT(ITEM_LONGSHOT) == ITEM_LONGSHOT)
				{
					pauseCtx->worldMapPoints[2] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_GERUDO_CARD))
				{
					pauseCtx->worldMapPoints[2] = 1;
				}

				if(CUR_UPG_VALUE(UPG_SCALE))
				{
					pauseCtx->worldMapPoints[3] = 1;
				}

				if(CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1))
				{
					pauseCtx->worldMapPoints[3] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_MEDALLION_WATER))
				{
					pauseCtx->worldMapPoints[3] = 1;
				}

				if(gSaveContext.eventChkInf[0] & 0x200)
				{
					pauseCtx->worldMapPoints[4] = 1;
				}

				if(INV_CONTENT(ITEM_OCARINA_FAIRY) != ITEM_NONE)
				{
					pauseCtx->worldMapPoints[4] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_EPONA))
				{
					pauseCtx->worldMapPoints[4] = 1;
				}

				if(gSaveContext.eventChkInf[6] & 0x400)
				{
					pauseCtx->worldMapPoints[4] = 2;
				}

				if(gSaveContext.eventChkInf[1] & 0x100)
				{
					pauseCtx->worldMapPoints[4] = 1;
				}

				if(gSaveContext.eventChkInf[0] & 0x200)
				{
					pauseCtx->worldMapPoints[5] = 2;
				}

				if(gSaveContext.eventChkInf[4] & 1)
				{
					pauseCtx->worldMapPoints[5] = 1;
				}

				if(INV_CONTENT(ITEM_OCARINA_TIME) == ITEM_OCARINA_TIME)
				{
					pauseCtx->worldMapPoints[5] = 2;
				}

				if(gSaveContext.eventChkInf[4] & 0x20)
				{
					pauseCtx->worldMapPoints[5] = 1;
				}

				if(INV_CONTENT(ITEM_ARROW_LIGHT) == ITEM_ARROW_LIGHT)
				{
					pauseCtx->worldMapPoints[5] = 2;
				}

				if(gSaveContext.eventChkInf[0] & 0x200)
				{
					pauseCtx->worldMapPoints[6] = 1;
				}

				if(gSaveContext.eventChkInf[4] & 1)
				{
					pauseCtx->worldMapPoints[7] = 2;
				}

				if(gSaveContext.eventChkInf[2] & 0x20)
				{
					pauseCtx->worldMapPoints[7] = 1;
				}

				if(INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT)
				{
					pauseCtx->worldMapPoints[7] = 2;
				}

				if(gSaveContext.eventChkInf[4] & 0x200)
				{
					pauseCtx->worldMapPoints[7] = 1;
				}

				if(gBitFlags[1] & gSaveContext.worldMapAreaData)
				{
					pauseCtx->worldMapPoints[8] = 1;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_LULLABY))
				{
					pauseCtx->worldMapPoints[8] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_SUN))
				{
					pauseCtx->worldMapPoints[8] = 1;
				}

				if(gSaveContext.eventChkInf[4] & 0x20)
				{
					pauseCtx->worldMapPoints[8] = 2;
				}

				if(INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT)
				{
					pauseCtx->worldMapPoints[8] = 1;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_STORMS))
				{
					pauseCtx->worldMapPoints[8] = 2;
				}

				if(gSaveContext.eventChkInf[6] & 0x80)
				{
					pauseCtx->worldMapPoints[8] = 1;
				}

				if(gSaveContext.eventChkInf[10] & 0x400)
				{
					pauseCtx->worldMapPoints[8] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_MEDALLION_SHADOW))
				{
					pauseCtx->worldMapPoints[8] = 1;
				}

				if(gBitFlags[10] & gSaveContext.worldMapAreaData)
				{
					pauseCtx->worldMapPoints[9] = 1;
				}

				if(gSaveContext.eventChkInf[0] & 0x8000)
				{
					pauseCtx->worldMapPoints[9] = 2;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_SARIA))
				{
					pauseCtx->worldMapPoints[9] = 1;
				}

				if(INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT)
				{
					pauseCtx->worldMapPoints[9] = 2;
				}

				if(gSaveContext.eventChkInf[4] & 0x100)
				{
					pauseCtx->worldMapPoints[9] = 1;
				}

				pauseCtx->worldMapPoints[10] = 2;

				if(gSaveContext.eventChkInf[0] & 0x200)
				{
					pauseCtx->worldMapPoints[10] = 1;
				}

				if(gSaveContext.eventChkInf[6] & 0x4000)
				{
					pauseCtx->worldMapPoints[10] = 2;
				}

				if(gSaveContext.eventChkInf[0] & 0x8000)
				{
					pauseCtx->worldMapPoints[10] = 1;
				}

				if(CHECK_QUEST_ITEM(QUEST_SONG_LULLABY))
				{
					pauseCtx->worldMapPoints[11] = 1;
				}

				if(gSaveContext.eventChkInf[2] & 0x20)
				{
					pauseCtx->worldMapPoints[11] = 2;
				}

				if(gSaveContext.eventChkInf[3] & 0x80)
				{
					pauseCtx->worldMapPoints[11] = 1;
				}

				if(INV_CONTENT(ITEM_HOOKSHOT) == ITEM_HOOKSHOT)
				{
					pauseCtx->worldMapPoints[11] = 2;
				}

				if(CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1))
				{
					pauseCtx->worldMapPoints[11] = 1;
				}

				pauseCtx->tradeQuestLocation = 0xFF;

				i = INV_CONTENT(ITEM_TRADE_ADULT);
				if(LINK_AGE_IN_YEARS == YEARS_ADULT)
				{
					if((i <= ITEM_POCKET_CUCCO) || (i == ITEM_ODD_MUSHROOM))
					{
						pauseCtx->tradeQuestLocation = 8;
					}
					if((i == ITEM_COJIRO) || (i == ITEM_ODD_POTION))
					{
						pauseCtx->tradeQuestLocation = 9;
					}
					if(i == ITEM_SAW)
					{
						pauseCtx->tradeQuestLocation = 2;
					}
					if((i == ITEM_SWORD_BROKEN) || (i == ITEM_EYEDROPS))
					{
						pauseCtx->tradeQuestLocation = 7;
					}
					if(i == ITEM_PRESCRIPTION)
					{
						pauseCtx->tradeQuestLocation = 11;
					}
					if(i == ITEM_FROG)
					{
						pauseCtx->tradeQuestLocation = 3;
					}
					if((i == ITEM_CLAIM_CHECK) && (gSaveContext.bgsFlag == 0))
					{
						pauseCtx->tradeQuestLocation = 7;
					}
				}

				pauseCtx->state = 4;
				break;

			case 4:
				if(gPages.get(0)->flipAngle() == 160.0f)
				{
					KaleidoScope_SetDefaultCursor(globalCtx);
					KaleidoScope_ProcessPlayerPreRender();
				}

				gPages.setFlipAngles(gPages.get(0)->flipAngle() - (160.0f / PAUSE_ANIMATION_STEPS));
				pauseCtx->infoPanelOffsetY += 40 / PAUSE_ANIMATION_STEPS;
				interfaceCtx->startAlpha += 255 / PAUSE_ANIMATION_STEPS;
				PAUSE_LEFT_CARET += PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
				PAUSE_RIGHT_CARET += PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
				XREG(5) += 150 / PAUSE_ANIMATION_STEPS;
				pauseCtx->alpha += (u16)(255 / (PAUSE_ANIMATION_STEPS + WREG(4)));

				if(gPages.get(0)->flipAngle() == 0)
				{
					interfaceCtx->startAlpha = 255;
					WREG(2) = 0;
					pauseCtx->state = 5;
				}

				func_808265BC(globalCtx);
				break;

			case 5:
				pauseCtx->alpha += (u16)(255 / (PAUSE_ANIMATION_STEPS + WREG(4)));
				func_808265BC(globalCtx);
				if(pauseCtx->state == 6)
				{
					KaleidoScope_UpdateNamePanel(globalCtx);
				}
				break;

			case 6:
				switch(pauseCtx->unk_1E4)
				{
					case 0:
						if(CHECK_BTN_ALL(input->press.button, BTN_START))
						{
							Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
							pauseCtx->state = 0x12;
							WREG(2) = -6240;
							Audio_PlayKaleido(0);
						}
						else if(CHECK_BTN_ALL(input->press.button, BTN_B))
						{
							// pauseCtx->mode	       = 0;
							pauseCtx->promptChoice = 0;
							Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
							gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_DISABLED;
							gSaveContext.buttonStatus[4] = BTN_ENABLED;
							gSaveContext.unk_13EA = 0;
							Interface_ChangeAlpha(50);
							pauseCtx->unk_1EC = 0;
							pauseCtx->state = 7;
						}
						break;

					case 1: // rotating
						KaleidoScope_Action_Rotating(globalCtx, globalCtx->input);
						break;

					case 2:
						pauseCtx->ocarinaStaff = Audio_OcaGetDisplayingStaff();
						if(pauseCtx->ocarinaStaff->state == 0)
						{
							pauseCtx->unk_1E4 = 4;
							Audio_OcaSetInstrument(0);
						}
						break;

					case 3:
						KaleidoScope_UpdateItemEquip(globalCtx, nullptr); // TODO FIX
						break;

					case 4:
						break;

					case 5:
						pauseCtx->ocarinaStaff = Audio_OcaGetPlayingStaff();

						if(CHECK_BTN_ALL(input->press.button, BTN_START))
						{
							Audio_OcaSetInstrument(0);
							Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
							pauseCtx->state = 0x12;
							WREG(2) = -6240;
							Audio_PlayKaleido(0);
							pauseCtx->unk_1E4 = 0;
							break;
						}
						else if(CHECK_BTN_ALL(input->press.button, BTN_B))
						{
							Audio_OcaSetInstrument(0);
							pauseCtx->unk_1E4 = 0;
							// pauseCtx->mode	       = 0;
							pauseCtx->promptChoice = 0;
							Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
							gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_DISABLED;
							gSaveContext.buttonStatus[4] = BTN_ENABLED;
							gSaveContext.unk_13EA = 0;
							Interface_ChangeAlpha(50);
							pauseCtx->unk_1EC = 0;
							pauseCtx->state = 7;
						}
						else if(pauseCtx->ocarinaStaff->state == pauseCtx->ocarinaSongIdx)
						{
							Audio_PlaySoundGeneral(NA_SE_SY_TRE_BOX_APPEAR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
							D_8082B258 = 0;
							D_8082B25C = 30;
							pauseCtx->unk_1E4 = 6;
						}
						else if(pauseCtx->ocarinaStaff->state == 0xFF)
						{
							Audio_PlaySoundGeneral(NA_SE_SY_OCARINA_ERROR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
							D_8082B258 = 4;
							D_8082B25C = 20;
							pauseCtx->unk_1E4 = 6;
						}
						break;

					case 6:
						D_8082B25C--;
						if(D_8082B25C == 0)
						{
							pauseCtx->unk_1E4 = D_8082B258;
							if(pauseCtx->unk_1E4 == 0)
							{
								Audio_OcaSetInstrument(0);
							}
						}
						break;

					case 7:
						break;

					case 8:
						if(CHECK_BTN_ALL(input->press.button, BTN_START))
						{
							Audio_OcaSetInstrument(0);
							Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
							pauseCtx->state = 0x12;
							WREG(2) = -6240;
							Audio_PlayKaleido(0);
							pauseCtx->unk_1E4 = 0;
						}
						else if(CHECK_BTN_ALL(input->press.button, BTN_B))
						{
							Audio_OcaSetInstrument(0);
							pauseCtx->unk_1E4 = 0;
							// pauseCtx->mode	       = 0;
							pauseCtx->promptChoice = 0;
							Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
							gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_DISABLED;
							gSaveContext.buttonStatus[4] = BTN_ENABLED;
							gSaveContext.unk_13EA = 0;
							Interface_ChangeAlpha(50);
							pauseCtx->unk_1EC = 0;
							pauseCtx->state = 7;
						}
						break;

					case 9:
						break;

					default:
						pauseCtx->unk_1E4 = 0;
						break;
				}
				break;

			case 7:
				switch(pauseCtx->unk_1EC)
				{
					case 0:
						pauseCtx->unk_204 -= 314.0f / PAUSE_ANIMATION_STEPS;
						PAUSE_LEFT_CARET -= PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
						PAUSE_RIGHT_CARET -= PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
						if(pauseCtx->unk_204 <= -628.0f)
						{
							pauseCtx->unk_204 = -628.0f;
							pauseCtx->unk_1EC = 1;
						}
						break;

					case 1:
						if(CHECK_BTN_ALL(input->press.button, BTN_A))
						{
							if(pauseCtx->promptChoice != 0)
							{
								Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
								gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_ENABLED;
								gSaveContext.unk_13EA = 0;
								Interface_ChangeAlpha(50);
								pauseCtx->unk_1EC = 2;
								WREG(2) = -6240;
								YREG(8) = pauseCtx->unk_204;
								Audio_PlayKaleido(0);
							}
							else
							{
								Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
								Gameplay_SaveSceneFlags(globalCtx);
								gSaveContext.savedSceneNum = globalCtx->sceneNum;
								gSaveContext.save();
								pauseCtx->unk_1EC = 4;
								D_8082B25C = 3;
							}
						}
						else if(CHECK_BTN_ALL(input->press.button, BTN_START) || CHECK_BTN_ALL(input->press.button, BTN_B))
						{
							Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
							pauseCtx->unk_1EC = 2;
							WREG(2) = -6240;
							YREG(8) = pauseCtx->unk_204;
							Audio_PlayKaleido(0);
							gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_ENABLED;
							gSaveContext.unk_13EA = 0;
							Interface_ChangeAlpha(50);
						}
						break;

					case 4:
						if(CHECK_BTN_ALL(input->press.button, BTN_B) || CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START) || (--D_8082B25C == 0))
						{
							Interface_SetDoAction(globalCtx, DO_ACTION_NONE);
							gSaveContext.buttonStatus[0] = gSaveContext.buttonStatus[1] = gSaveContext.buttonStatus[2] = gSaveContext.buttonStatus[3] = BTN_ENABLED;
							gSaveContext.unk_13EA = 0;
							Interface_ChangeAlpha(50);
							pauseCtx->unk_1EC = 5;
							WREG(2) = -6240;
							YREG(8) = pauseCtx->unk_204;
							Audio_PlayKaleido(0);
						}
						break;

					case 3:
					case 6:
						pauseCtx->unk_204 += 314.0f / PAUSE_ANIMATION_STEPS;
						PAUSE_LEFT_CARET += PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
						PAUSE_RIGHT_CARET += PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
						if(pauseCtx->unk_204 >= -314.0f)
						{
							pauseCtx->state = 6;
							pauseCtx->unk_1EC = 0;
							gPages.setFlipAngles(0.0f);
							pauseCtx->unk_204 = -314.0f;
						}
						break;

					case 2:
					case 5:
						if(pauseCtx->unk_204 != (YREG(8) + 160.0f))
						{
							gPages.setFlipAngles(gPages.get(0)->flipAngle() + (160.0f / PAUSE_ANIMATION_STEPS));
							pauseCtx->unk_204 += 160.0f / PAUSE_ANIMATION_STEPS;
							pauseCtx->infoPanelOffsetY -= 40 / PAUSE_ANIMATION_STEPS;
							PAUSE_LEFT_CARET -= PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
							PAUSE_RIGHT_CARET -= PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
							XREG(5) -= 150 / PAUSE_ANIMATION_STEPS;
							pauseCtx->alpha -= (u16)(255 / PAUSE_ANIMATION_STEPS);
							if(pauseCtx->unk_204 == (YREG(8) + 160.0f))
							{
								pauseCtx->alpha = 0;
							}
						}
						else
						{
							pauseCtx->debugState = 0;
							pauseCtx->state = 0x13;
							gPages.setFlipAngles(160.0f);
							pauseCtx->namedItem = PAUSE_ITEM_NONE;
							pauseCtx->unk_1E4 = 0;
							pauseCtx->unk_204 = -434.0f;
						}
						break;
				}
				break;

			case 0xA: // death start ?

			{
				auto map = gPages.find(PAUSE_MAP);

				map->cursorSlot() = map->cursorPoint() = pauseCtx->dungeonMapSlot = VREG(30) + 3;
			}
				PAUSE_LEFT_CARET = PAUSE_LEFT_CARET_ORIGINAL_X;
				PAUSE_RIGHT_CARET = PAUSE_RIGHT_CARET_ORIGINAL_X;
				pauseCtx->unk_204 = -434.0f;
				Interface_ChangeAlpha(1);

				pauseCtx->iconItemSegment = _icon_item_staticSegmentRomStart;
				pauseCtx->iconItem24Segment = _icon_item_24_staticSegmentRomStart;
				pauseCtx->iconItemAltSegment = _icon_item_gameover_staticSegmentRomStart;

				if(gSaveContext.language == LANGUAGE_ENG)
				{
					pauseCtx->iconItemLangSegment = _icon_item_nes_staticSegmentRomStart;
				}
				else if(gSaveContext.language == LANGUAGE_GER)
				{
					pauseCtx->iconItemLangSegment = _icon_item_ger_staticSegmentRomStart;
				}
				else
				{
					pauseCtx->iconItemLangSegment = _icon_item_fra_staticSegmentRomStart;
				}

				D_8082AB8C = 255;
				D_8082AB90 = 130;
				D_8082AB94 = 0;
				D_8082AB98 = 0;
				D_8082AB9C = 30;
				D_8082ABA0 = 0;
				D_8082ABA4 = 0;
				D_8082B260 = 30;
				VREG(88) = 98;
				pauseCtx->promptChoice = 0;
				pauseCtx->state++;
				break;

			case 0xB:
				stepR = ABS(D_8082AB8C - 30) / D_8082B260;
				stepG = ABS(D_8082AB90) / D_8082B260;
				stepB = ABS(D_8082AB94) / D_8082B260;
				stepA = ABS(D_8082AB98 - 255) / D_8082B260;
				if(D_8082AB8C >= 30)
				{
					D_8082AB8C -= stepR;
				}
				else
				{
					D_8082AB8C += stepR;
				}
				if(D_8082AB90 >= 0)
				{
					D_8082AB90 -= stepG;
				}
				else
				{
					D_8082AB90 += stepG;
				}
				if(D_8082AB94 >= 0)
				{
					D_8082AB94 -= stepB;
				}
				else
				{
					D_8082AB94 += stepB;
				}
				if(D_8082AB98 >= 255)
				{
					D_8082AB98 -= stepA;
				}
				else
				{
					D_8082AB98 += stepA;
				}

				stepR = ABS(D_8082AB9C - 255) / D_8082B260;
				stepG = ABS(D_8082ABA0 - 130) / D_8082B260;
				stepB = ABS(D_8082ABA4) / D_8082B260;
				if(D_8082AB9C >= 255)
				{
					D_8082AB9C -= stepR;
				}
				else
				{
					D_8082AB9C += stepR;
				}
				if(D_8082ABA0 >= 130)
				{
					D_8082ABA0 -= stepG;
				}
				else
				{
					D_8082ABA0 += stepG;
				}
				if(D_8082ABA4 >= 0)
				{
					D_8082ABA4 -= stepB;
				}
				else
				{
					D_8082ABA4 += stepB;
				}

				D_8082B260--;
				if(D_8082B260 == 0)
				{
					D_8082AB8C = 30;
					D_8082AB90 = 0;
					D_8082AB94 = 0;
					D_8082AB98 = 255;

					D_8082AB9C = 255;
					D_8082ABA0 = 130;
					D_8082ABA4 = 0;

					pauseCtx->state++;
					D_8082B260 = 40;
				}
				break;

			case 0xC:
				D_8082B260--;
				if(D_8082B260 == 0)
				{
					pauseCtx->state = 0xD;
				}
				break;

			case 0xD:
				gPages.setFlipAngles(pauseCtx->unk_204 -= 160.0f);
				pauseCtx->infoPanelOffsetY += 40 / PAUSE_ANIMATION_STEPS;
				interfaceCtx->startAlpha += 255 / PAUSE_ANIMATION_STEPS;
				VREG(88) -= 3;
				PAUSE_LEFT_CARET += PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
				PAUSE_RIGHT_CARET += PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
				XREG(5) += 150 / PAUSE_ANIMATION_STEPS;
				pauseCtx->alpha += (u16)(255 / (PAUSE_ANIMATION_STEPS + WREG(4)));
				if(pauseCtx->unk_204 < -628.0f)
				{
					pauseCtx->unk_204 = -628.0f;
					interfaceCtx->startAlpha = 255;
					VREG(88) = 66;
					WREG(2) = 0;
					pauseCtx->alpha = 255;
					pauseCtx->state = 0xE;
					gSaveContext.deaths++;
					if(gSaveContext.deaths > 999)
					{
						gSaveContext.deaths = 999;
					}
				}
				osSyncPrintf("kscope->angle_s = %f\n", pauseCtx->unk_204);
				break;

			case 0xE: // GAME OVER - would you like to save?
				if(CHECK_BTN_ALL(input->press.button, BTN_A))
				{
					if(pauseCtx->promptChoice != 0)
					{
						pauseCtx->promptChoice = 0;
						Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
						pauseCtx->state = 0x10;
						gameOverCtx->state++;
					}
					else
					{
						Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
						pauseCtx->promptChoice = 0;
						Gameplay_SaveSceneFlags(globalCtx);
						gSaveContext.savedSceneNum = globalCtx->sceneNum;
						gSaveContext.save();
						pauseCtx->state = 0xF;
						D_8082B25C = 3;
					}
				}
				break;

			case 0xF:
				D_8082B25C--;
				if(D_8082B25C == 0)
				{
					pauseCtx->state = 0x10;
					gameOverCtx->state++;
				}
				else if((D_8082B25C <= 80) && (CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START)))
				{
					pauseCtx->state = 0x10;
					gameOverCtx->state++;
					Audio_PlayKaleido(0);
				}
				break;

			case 0x10: // GAME OVER - Continue Playing?
				if(CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_START))
				{
					if(pauseCtx->promptChoice == 0)
					{
						Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
						Gameplay_SaveSceneFlags(globalCtx);

						switch(gSaveContext.entranceIndex)
						{
							case 0x0000:
							case 0x0004:
							case 0x0028:
							case 0x0169:
							case 0x0165:
							case 0x0010:
							case 0x0082:
							case 0x0037:
							case 0x041B:
							case 0x0008:
							case 0x0088:
							case 0x0486:
							case 0x0098:
							case 0x0467:
							case 0x0179:
								break;
							case 0x040F:
								gSaveContext.entranceIndex = 0x0000;
								break;
							case 0x040B:
								gSaveContext.entranceIndex = 0x0004;
								break;
							case 0x0301:
								gSaveContext.entranceIndex = 0x0028;
								break;
							case 0x000C:
								gSaveContext.entranceIndex = 0x0169;
								break;
							case 0x0305:
								gSaveContext.entranceIndex = 0x0165;
								break;
							case 0x0417:
								gSaveContext.entranceIndex = 0x0010;
								break;
							case 0x008D:
								gSaveContext.entranceIndex = 0x0082;
								break;
							case 0x0413:
								gSaveContext.entranceIndex = 0x0037;
								break;
							case 0x041F:
								gSaveContext.entranceIndex = 0x041B;
								break;
						}
					}
					else
					{
						Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
					}

					pauseCtx->state = 0x11;
				}
				break;

			case 0x11:
				if(interfaceCtx->unk_244 != 255)
				{
					interfaceCtx->unk_244 += 10;
					if(interfaceCtx->unk_244 >= 255)
					{
						interfaceCtx->unk_244 = 255;
						pauseCtx->state = 0;
						framerate_set_profile(PROFILE_GAMEPLAY);
						R_PAUSE_MENU_MODE = 0;
						func_800981B8(&globalCtx->objectCtx);
						func_800418D0(&globalCtx->colCtx, globalCtx);
						if(pauseCtx->promptChoice == 0)
						{
							Gameplay_TriggerRespawn(globalCtx);
							gSaveContext.respawnFlag = -2;
							gSaveContext.nextTransition = 2;
							gSaveContext.health = 0x30;
							Audio_QueueSeqCmd(0xF << 28 | SEQ_PLAYER_BGM_MAIN << 24 | 0xA);
							gSaveContext.healthAccumulator = 0;
							gSaveContext.unk_13F0 = 0;
							gSaveContext.unk_13F2 = 0;
							osSyncPrintf(VT_FGCOL(YELLOW));
							osSyncPrintf("MAGIC_NOW=%d ", gSaveContext.magic);
							osSyncPrintf("Z_MAGIC_NOW_NOW=%d   →  ", gSaveContext.magicMax);
							gSaveContext.unk_13F4 = 0;
							gSaveContext.magicMax = gSaveContext.magic;
							gSaveContext.magicLevel = gSaveContext.magic = 0;
							osSyncPrintf("MAGIC_NOW=%d ", gSaveContext.magic);
							osSyncPrintf("Z_MAGIC_NOW_NOW=%d\n", gSaveContext.magicMax);
							osSyncPrintf(VT_RST);
						}
						else
						{
							globalCtx->running = 0;
							Graph_SetNextGameState(new oot::gamestate::Opening(globalCtx->gfxCtx));
						}
					}
				}
				break;

			case 0x12:
				if(gPages.get(0)->flipAngle() != 160.0f)
				{
					gPages.setFlipAngles(gPages.get(1)->flipAngle() + (160.0f / PAUSE_ANIMATION_STEPS));
					pauseCtx->infoPanelOffsetY -= 40 / PAUSE_ANIMATION_STEPS;
					interfaceCtx->startAlpha -= 255 / PAUSE_ANIMATION_STEPS;
					PAUSE_LEFT_CARET -= PAUSE_LEFT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
					PAUSE_RIGHT_CARET -= PAUSE_RIGHT_CARET_MOVE / PAUSE_ANIMATION_STEPS;
					XREG(5) -= 150 / PAUSE_ANIMATION_STEPS;
					pauseCtx->alpha -= (u16)(255 / PAUSE_ANIMATION_STEPS);
					if(gPages.get(0)->flipAngle() == 160.0f)
					{
						pauseCtx->alpha = 0;
					}
				}
				else
				{
					pauseCtx->debugState = 0;
					pauseCtx->state = 0x13;
					gPages.setFlipAngles(160.0f);
					pauseCtx->namedItem = PAUSE_ITEM_NONE;
					globalCtx->interfaceCtx.startAlpha = 0;
				}
				break;

			case 0x13:
				pauseCtx->state = 0;
				oot::hid::clearPressedButtons(oot::config().game().pauseExitInputClearFrames());
				framerate_set_profile(PROFILE_GAMEPLAY);
				R_PAUSE_MENU_MODE = 0;
				func_800981B8(&globalCtx->objectCtx);
				func_800418D0(&globalCtx->colCtx, globalCtx);

				switch(globalCtx->sceneNum)
				{
					case SCENE_YDAN:
					case SCENE_DDAN:
					case SCENE_BDAN:
					case SCENE_BMORI1:
					case SCENE_HIDAN:
					case SCENE_MIZUSIN:
					case SCENE_JYASINZOU:
					case SCENE_HAKADAN:
					case SCENE_HAKADANCH:
					case SCENE_ICE_DOUKUTO:
					case SCENE_YDAN_BOSS:
					case SCENE_DDAN_BOSS:
					case SCENE_BDAN_BOSS:
					case SCENE_MORIBOSSROOM:
					case SCENE_FIRE_BS:
					case SCENE_MIZUSIN_BS:
					case SCENE_JYASINBOSS:
					case SCENE_HAKADAN_BS:
						Map_InitData(globalCtx, globalCtx->interfaceCtx.mapRoomNum);
						break;
				}

				gSaveContext.buttonStatus[0] = D_808321A8[0];
				gSaveContext.buttonStatus[1] = D_808321A8[1];
				gSaveContext.buttonStatus[2] = D_808321A8[2];
				gSaveContext.buttonStatus[3] = D_808321A8[3];
				gSaveContext.buttonStatus[4] = D_808321A8[4];
				interfaceCtx->unk_1FA = interfaceCtx->unk_1FC = 0;
				osSyncPrintf(VT_FGCOL(YELLOW));
				osSyncPrintf("i=%d  LAST_TIME_TYPE=%d\n", i, gSaveContext.unk_13EE);
				gSaveContext.unk_13EA = 0;
				Interface_ChangeAlpha(gSaveContext.unk_13EE);
				player->targetActor = NULL;
				Player_SetEquipmentData(globalCtx, player);
				osSyncPrintf(VT_RST);
				break;
		}
	}
