#define INTERNAL_SRC_OVERLAYS_MISC_OVL_KALEIDO_SCOPE_Z_KALEIDO_CONTROLLER_C
#include "actor_common.h"
#include <functional>
#include "port/player/players.h"
#include "port/options.h"
#include "z_kaleido_scope.h"
#include "def/z_lib.h"
#include "textures/icon_item_static/icon_item_static.h"
#include "textures/parameter_static/parameter_static.h"
#include "textures/icon_item_nes_static/icon_item_nes_static.h"
#include "def/inventory.h"
#include "def/audio_bank.h"
#include "def/z_common_data.h"
#include "def/z_parameter.h"
#include "def/z_player_lib.h"
#include "def/z_rcp.h"

extern void* sGameOverTexs[];
class Hotspot;
typedef std::function<void(Hotspot*)> HotspotClickHandler;

#define DIRECTION_MULT 2
#define HOTSPOT_MAX_ANGLE 60
#define MAX_RING_BUFFER_SIZE 32

#define POINT_X_MAX 4
#define POINT_Y_MAX 4

#define qu08(n) ((u8)((n)*0x100))
#define qu016(n) ((u16)((n)*0x10000))
#define qs48(n) ((s16)((n)*0x0100))
#define qs510(n) ((s16)((n)*0x0400))
#define qu510(n) ((u16)((n)*0x0400))
#define qs102(n) ((s16)((n)*0x0004))
#define qu102(n) ((u16)((n)*0x0004))
#define qs105(n) ((s16)((n)*0x0020))
#define qu105(n) ((u16)((n)*0x0020))
#define qs132(n) ((s16)((n)*0x0004))
#define qs142(n) ((s16)((n)*0x0004))
#define qs1516(n) ((s32)((n)*0x00010000))
#define qs1616(n) ((s32)((n)*0x00010000))
#define qs205(n) ((s32)((n)*0x00000020))

#define TEX_WIDTH 128
#define TEX_HEIGHT 128

#define TEX_X 0
#define TEX_Y -7

u8 gN64ControllerTex[] = {
#include "n64_controller_128x128.rgba32.inc.c"
};

u8 gResetTex[] = {
#include "reset_32x32.rgba32.inc.c"
};

static Vtx controllerVtx[] = {
    VTX(TEX_WIDTH / -2 + TEX_X, TEX_HEIGHT / -2 + TEX_Y, 0, qs105(0), qs105(0 + TEX_HEIGHT), 255, 255, 255, 255),
    VTX(TEX_WIDTH / +2 + TEX_X, TEX_HEIGHT / -2 + TEX_Y, 0, qs105(0 + TEX_WIDTH), qs105(0 + TEX_HEIGHT), 255, 255, 255, 255),
    VTX(TEX_WIDTH / +2 + TEX_X, TEX_HEIGHT / +2 + TEX_Y, 0, qs105(0 + TEX_WIDTH), qs105(0), 255, 255, 255, 255),
    VTX(TEX_WIDTH / -2 + TEX_X, TEX_HEIGHT / +2 + TEX_Y, 0, qs105(0), qs105(0), 255, 255, 255, 255),
};

static u16 gRingBufferIndex = 0;
static Vtx gRingBufferVtx[MAX_RING_BUFFER_SIZE][4];

void drawTextureRGBA32(GraphicsContext* __gfxCtx, s16 x, s16 y, u16 width, u16 height, const u8* texture, bool centered = false, float scale = 1.0f)
{
	auto yoffset = PAGE_ACTIVE_Y;
	if(yoffset != 0.0f)
	{
		y -= yoffset;
		y += 20;
	}

	if(centered)
	{
		gRingBufferVtx[gRingBufferIndex][0] = VTX(width * scale / -2 + x, height * scale / -2 + y, 0, qs105(0), qs105(0 + height), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][1] = VTX(width * scale / +2 + x, height * scale / -2 + y, 0, qs105(0 + width), qs105(0 + height), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][2] = VTX(width * scale / +2 + x, height * scale / +2 + y, 0, qs105(0 + width), qs105(0), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][3] = VTX(width * scale / -2 + x, height * scale / +2 + y, 0, qs105(0), qs105(0), 255, 255, 255, 255);
	}
	else
	{
		gRingBufferVtx[gRingBufferIndex][0] = VTX(x, y, 0, qs105(0), qs105(0 + height), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][1] = VTX(x + width, y, 0, qs105(0 + width), qs105(0 + height), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][2] = VTX(x + width, y + height, 0, qs105(0 + width), qs105(0), 255, 255, 255, 255);
		gRingBufferVtx[gRingBufferIndex][3] = VTX(x, y + height, 0, qs105(0), qs105(0), 255, 255, 255, 255);
	}

	gDPLoadTextureBlock(POLY_OPA_DISP++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSPVertex(POLY_OPA_DISP++, gRingBufferVtx[gRingBufferIndex], 4, 0);
	gSP2Triangles(POLY_OPA_DISP++, 0, 2, 3, 0, 0, 1, 2, 0);

	gDPPipeSync(POLY_OPA_DISP++);

	gRingBufferIndex = (gRingBufferIndex + 1) % MAX_RING_BUFFER_SIZE;
}

class Image
{
	public:
	Image(int width, int height, const u8* texture, float scale = 1.0f) : width(width), height(height), texture(texture), scale(scale)
	{
	}

	int width;
	int height;
	const u8* texture;
	float scale;
};

class Hotspot
{
	public:
	Hotspot() : m_name(nullptr), m_x(0), m_y(0), m_index(0), m_up(nullptr), m_right(nullptr), m_down(nullptr), m_left(nullptr), m_onClick(nullptr), m_images(), m_size(1), m_pageRight(false), m_pageLeft(false)
	{
	}

	Hotspot(const char* name, int x, int y, const HotspotClickHandler onClick = nullptr, Image* image = nullptr, u8 size = 1) :
	    m_name(name), m_x(x), m_y(y), m_index(0), m_up(nullptr), m_right(nullptr), m_down(nullptr), m_left(nullptr), m_onClick(onClick), m_images(), m_size(size), m_pageRight(false), m_pageLeft(false)
	{
		if(image)
		{
			addImage(image);
		}
	}

	virtual void addImage(Image* img)
	{
		m_images.push_back(std::move(std::unique_ptr<Image>(img)));
	}

	virtual void draw(GraphicsContext* __gfxCtx)
	{
		auto img = image();

		if(img && img->texture)
		{
			drawTextureRGBA32(__gfxCtx, x(), y(), img->width, img->height, img->texture, true, img->scale);
		}
	}

	Image* image(u16 i = 0)
	{
		if(i >= m_images.size())
		{
			return nullptr;
		}

		return m_images[i].get();
	}

	void markPageRight()
	{
		m_pageRight = true;
	}

	void markPageLeft()
	{
		m_pageLeft = true;
	}

	bool pageRight() const
	{
		return m_pageRight;
	}

	bool pageLeft() const
	{
		return m_pageLeft;
	}

	int x() const
	{
		return m_x;
	}

	int y() const
	{
		return m_y;
	}

	const int& index() const
	{
		return m_index;
	}

	int& index()
	{
		return m_index;
	}

	const char* name()
	{
		return m_name;
	}

	double costX(Hotspot* current)
	{
		int delta_x = current->x() - x();
		int delta_y = current->y() - y();

		float angle = Math_AngleF({(float)delta_x, (float)delta_y});
		float dist = sqrt(delta_x * delta_x + delta_y * delta_y);

		angle = Math_AngleDiffF(angle, 0);

		if(angle == 180.0f)
		{
			angle = 0.0f;
		}

		if(angle > HOTSPOT_MAX_ANGLE)
		{
			return 0;
		}

		const float scaler = 1.0f + (angle * DIRECTION_MULT / 100.0f);
		return (double)(dist * scaler * (delta_x < 0 ? -1.0f : 1.0f));
	}

	double costY(Hotspot* current)
	{
		int delta_x = current->x() - x();
		int delta_y = current->y() - y();

		float angle = Math_AngleF({(float)delta_y, (float)delta_x});
		float dist = sqrt(delta_x * delta_x + delta_y * delta_y);

		angle = Math_AngleDiffF(angle, 0);

		if(angle == 180.0f)
		{
			angle = 0.0f;
		}

		if(angle > HOTSPOT_MAX_ANGLE)
		{
			return 0;
		}

		const float scaler = 1.0f + (angle * DIRECTION_MULT / 100.0f);
		return (double)(dist * scaler * (delta_y < 0 ? -1.0f : 1.0f));
	}

	Hotspot*& up()
	{
		return m_up;
	}

	Hotspot*& right()
	{
		return m_right;
	}

	Hotspot*& down()
	{
		return m_down;
	}

	Hotspot*& left()
	{
		return m_left;
	}

	const HotspotClickHandler& onClick() const
	{
		return m_onClick;
	}

	u8 size() const
	{
		return m_size;
	}

	const char* m_name;
	std::vector<double> m_costsX;
	std::vector<double> m_costsY;

	protected:
	int m_x;
	int m_y;
	int m_index;
	Hotspot* m_up;
	Hotspot* m_right;
	Hotspot* m_down;
	Hotspot* m_left;
	HotspotClickHandler m_onClick;
	std::vector<std::unique_ptr<Image>> m_images;
	u8 m_size;
	bool m_pageRight;
	bool m_pageLeft;
};

class Checkbox : public Hotspot
{
	public:
	Checkbox() : Hotspot(), imageOn(nullptr), value(nullptr)
	{
	}

	Checkbox(const char* name, int x, int y, const HotspotClickHandler onClick = nullptr, Image* imageOff = nullptr, Image* imageOn = nullptr, u8 size = 1) : Hotspot(name, x, y, onClick, imageOff, size), imageOn(imageOn), value(nullptr)
	{
		addImage(imageOff);
		addImage(imageOn);
	}

	void draw(GraphicsContext* __gfxCtx) override
	{
		if(!value)
		{
			return;
		}

		auto img = *value ? image(1) : image(0);

		if(img && img->texture)
		{
			drawTextureRGBA32(__gfxCtx, x(), y(), img->width, img->height, img->texture, true, img->scale);
		}
	}

	protected:
	Image* imageOn;
	bool* value;
};

class Hotspots
{
	public:
	Hotspots() : m_hotspots(), m_index(0)
	{
	}

	Hotspot* add(std::unique_ptr<Hotspot>&& hotspot)
	{
		m_hotspots.push_back(std::move(hotspot));
		return m_hotspots.back().get();
	}

	Hotspot* add(Hotspot* hotspot)
	{
		m_hotspots.push_back(std::unique_ptr<Hotspot>(hotspot));
		return hotspot;
	}

	Hotspot* findLowestCost(const std::vector<double>& costs, bool invert)
	{
		double lowest = -1.0f;
		int index = 0;

		for(int i = 0; i < costs.size(); i++)
		{
			const auto cost = invert ? costs[i] * -1 : costs[i];

			if(cost > 0 && (cost < lowest || lowest < 0))
			{
				lowest = cost;
				index = i;
			}
		}

		if(lowest < 0)
		{
			return nullptr;
		}

		return m_hotspots[index].get();
	}

	void update()
	{
		for(int i = 0; i < m_hotspots.size(); i++)
		{
			m_hotspots[i]->index() = i;
		}

		for(auto& hotspot1 : m_hotspots)
		{
			for(auto& hotspot2 : m_hotspots)
			{
				hotspot1->m_costsX.push_back(hotspot1->costX(hotspot2.get()));
				hotspot1->m_costsY.push_back(hotspot1->costY(hotspot2.get()));
			}

			hotspot1->left() = findLowestCost(hotspot1->m_costsX, true);
			hotspot1->right() = findLowestCost(hotspot1->m_costsX, false);

			hotspot1->up() = findLowestCost(hotspot1->m_costsY, false);
			hotspot1->down() = findLowestCost(hotspot1->m_costsY, true);
		}
	}

	void draw(GraphicsContext* __gfxCtx)
	{
		for(auto& hotspot : m_hotspots)
		{
			hotspot->draw(__gfxCtx);
		}
	}

	void click()
	{
		auto cur = current();

		if(cur->onClick() != nullptr)
		{
			cur->onClick()(cur);
		}
	}

	bool empty() const
	{
		return m_hotspots.size() == 0;
	}

	Hotspot* current()
	{
		return m_hotspots[m_index].get();
	}

	bool moveX(s8 dir)
	{
		if(empty())
		{
			return false;
		}

		Hotspot* next = nullptr;

		if(dir > 0)
		{
			next = current()->right();
		}
		else
		{
			next = current()->left();
		}

		if(next)
		{
			m_index = next->index();
			return true;
		}

		return false;
	}
	bool moveY(s8 dir)
	{
		if(empty())
		{
			return false;
		}

		Hotspot* next = nullptr;

		if(dir > 0)
		{
			next = current()->up();
		}
		else
		{
			next = current()->down();
		}

		if(next)
		{
			m_index = next->index();
			return true;
		}

		return false;
	}

	bool set(s8 dir)
	{
		if(empty())
		{
			return false;
		}

		Hotspot* closest = nullptr;

		for(int i = 0; i < m_hotspots.size(); i++)
		{
			if(i == m_index)
			{
				continue;
			}

			if(dir > 0)
			{
				if(closest == nullptr || m_hotspots[i]->x() > closest->x())
				{
					closest = m_hotspots[i].get();
					m_index = i;
				}
			}
			else
			{
				if(closest == nullptr || m_hotspots[i]->x() < closest->x())
				{
					closest = m_hotspots[i].get();
					m_index = i;
				}
			}
		}
		return closest != nullptr;
	}

	bool setLeft()
	{
		return set(-1);
	}

	bool setRight()
	{
		return set(1);
	}

	protected:
	std::vector<std::unique_ptr<Hotspot>> m_hotspots;
	u32 m_index;
};

static int a_x = 0;
static int a_y = 0;

#define ADJUST_X(n) ((n - 64) + 1)
#define ADJUST_Y(n) ((64 - n) - 7)

class ControllerHotspots : public Hotspots
{
	public:
	ControllerHotspots() : Hotspots()
	{
		auto start = add(new Hotspot("Remap Start", ADJUST_X(64), ADJUST_Y(45), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::START_BUTTON); }));
		auto a_button = add(new Hotspot("Remap A", ADJUST_X(98), ADJUST_Y(53), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::A_BUTTON); }));
		auto b_button = add(new Hotspot("Remap B", ADJUST_X(89), ADJUST_Y(44), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::B_BUTTON); }));
		// auto joystick = add(new Hotspot("Joystick", ADJUST_X(65), ADJUST_Y(70)));
		auto z_button = add(new Hotspot("Remap Z", ADJUST_X(65), ADJUST_Y(80), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::Z_TRIG); }));
		auto c_right = add(new Hotspot("Remap C-Right", ADJUST_X(115), ADJUST_Y(36), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::R_CBUTTONS); }));
		auto c_left = add(new Hotspot("Remap C-Left", ADJUST_X(100), ADJUST_Y(36), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::L_CBUTTONS); }));
		auto c_up = add(new Hotspot("Remap C-Up", ADJUST_X(108), ADJUST_Y(29), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::U_CBUTTONS); }));
		auto c_down = add(new Hotspot("Remap C-Down", ADJUST_X(108), ADJUST_Y(43), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::D_CBUTTONS); }));
		auto up = add(new Hotspot("Remap Up", ADJUST_X(25), ADJUST_Y(33), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::U_JPAD); }));
		auto down = add(new Hotspot("Remap Down", ADJUST_X(25), ADJUST_Y(48), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::D_JPAD); }));
		auto left = add(new Hotspot("Remap Left", ADJUST_X(18), ADJUST_Y(41), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::L_JPAD); }));
		auto right = add(new Hotspot("Remap Right", ADJUST_X(33), ADJUST_Y(41), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::R_JPAD); }));
		auto l_button = add(new Hotspot("Remap L", ADJUST_X(25), ADJUST_Y(15), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::L_TRIG); }));
		auto r_button = add(new Hotspot("Remap R", ADJUST_X(104), ADJUST_Y(15), [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::R_TRIG); }));

		auto shield = add(new Hotspot(
		    "Remap Shield", 95 - (2 * 16), -60, [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::SHIELD_TOGGLE); }, new Image(32, 32, gDekuShieldIconTex, 0.5f), 8));
		auto tunic = add(new Hotspot(
		    "Remap Tunic", 95 - (1 * 16), -60, [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::TUNIC_TOGGLE); }, new Image(32, 32, gKokiriTunicIconTex, 0.5f), 8));
		auto boots = add(new Hotspot(
		    "Remap Boots", 95 - (0 * 16), -60, [](Hotspot* hotspot) { oot::player(0).rebind(oot::hid::Button::BOOTS_TOGGLE); }, new Image(32, 32, gKokiriBootsIconTex, 0.5f), 8));

		auto reset = add(new Hotspot(
		    "Reset Bindings", 95, 49, [](Hotspot* hotspot) { oot::player(0).resetBindings(); }, new Image(32, 32, gResetTex, 0.5f), 8));

		c_right->markPageRight();
		left->markPageLeft();
		boots->markPageRight();
		reset->markPageRight();
		l_button->markPageLeft();

		update();
	}
};

static ControllerHotspots hotspots;

void KaleidoScope_DrawController(GlobalContext* globalCtx, oot::pause::Page* page)
{
	PauseContext* pauseCtx = &globalCtx->pauseCtx;
	Input* input = &globalCtx->state.input[0];

	OPEN_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);
	gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);

	drawTextureRGBA32(__gfxCtx, TEX_X, TEX_Y, TEX_WIDTH, TEX_HEIGHT, gN64ControllerTex, true);

	hotspots.draw(__gfxCtx);

	if((pauseCtx->state == 6) && (pauseCtx->unk_1E4 == 0) && (page == KaleidoScope_CurrentPage()))
	{
		bool playSound = false;

		if(pauseCtx->stickRelX > 30)
		{
			if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT)
			{
				hotspots.setLeft();
				pauseCtx->cursorSpecialPos = 0;
			}
			else
			{
				if(!hotspots.moveX(1))
				{
					if(hotspots.current()->pageRight())
					{
						pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_RIGHT;
					}
				}
				else
				{
					playSound = true;
				}
			}
		}
		else if(pauseCtx->stickRelX < -30)
		{
			if(pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT)
			{
				hotspots.setRight();
				pauseCtx->cursorSpecialPos = 0;
			}
			else
			{
				if(!hotspots.moveX(-1))
				{
					if(hotspots.current()->pageLeft()) // left
					{
						pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_LEFT;
					}
				}
				else
				{
					playSound = true;
				}
			}
		}

		if(pauseCtx->cursorSpecialPos == 0)
		{
			if(pauseCtx->stickRelY > 30)
			{
				if(hotspots.moveY(1))
				{
					playSound = true;
				}
			}
			else if(pauseCtx->stickRelY < -30)
			{
				if(hotspots.moveY(-1))
				{
					playSound = true;
				}
			}

			if(CHECK_BTN_ALL(input->press.button, BTN_A))
			{
				hotspots.click();
			}
		}

		if(playSound)
		{
			pauseCtx->nameSegment = nullptr;
			// page->cursorItem() = hotspots.current()->index();
			pauseCtx->nameDisplayTimer = 0;
			Audio_PlaySoundGeneral(NA_SE_SY_CURSOR, &gAudioDefaultPos, 4, &D_801333E0, &D_801333E0, &gReverbAdd2);
		}

		if(pauseCtx->cursorSpecialPos == 0)
		{
			auto cur = hotspots.current();
			if(cur)
			{
				pauseCtx->cursorVtx[0].v.ob[0] = cur->x() + a_x;
				pauseCtx->cursorVtx[0].v.ob[1] = cur->y() + a_y;
			}
		}
	}

	CLOSE_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);
	return;
}

namespace oot::pause::page
{
	Controller::Controller()
	{
		cursorPoint() = 0;

		cursorX() = 0;
		cursorY() = 0;

		cursorItem() = 0;
		cursorSlot() = 0;
	}

	u8* Controller::infoPanelTexture(u8 langId)
	{
		return nullptr;
	}

	void Controller::drawInfo(GlobalContext* globalCtx, GraphicsContext* __gfxCtx)
	{
		if(oot::player(0).isRebindMode())
		{
			drawInfoText(globalCtx, __gfxCtx, "Press any input");
		}
		else
		{
			drawInfoText(globalCtx, __gfxCtx, hotspots.current()->name());
		}
	}

	void Controller::initVerticies(GlobalContext* globalCtx)
	{
		s16 phi_t1;
		s16 phi_t2;
		s16 phi_t2_2;
		s16 phi_t3;
		s16 phi_t4;
		s16 phi_t5;

		PauseContext* pauseCtx = &globalCtx->pauseCtx;

		// m_pageVtx = std::make_unique<Vtx[]>(60);
		// KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 1, 0);
		m_pageVtx = std::make_unique<Vtx[]>(80);
		KaleidoScope_SetPageVertices(globalCtx, m_pageVtx.get(), 5, 5);
	}

	void Controller::preDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active)
	{
		if(!active)
		{
			gDPPipeSync(POLY_OPA_DISP++);
			gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA, G_CC_MODULATEIA);
		}
	}

	void Controller::postDraw(GlobalContext* globalCtx, GraphicsContext* __gfxCtx, float inRadius, bool active)
	{
		PauseContext* pauseCtx = &globalCtx->pauseCtx;
		POLY_OPA_DISP = KaleidoScope_DrawPageSections(POLY_OPA_DISP, m_pageVtx.get(), (void**)sGameOverTexs);
		KaleidoScope_DrawController(globalCtx, this);

		if(active && pauseCtx->cursorSpecialPos == 0)
		{
			KaleidoScope_DrawCursor(globalCtx, this);
		}
	}

	void Controller::setCursorMetrics(s32& offset_x, s32& offset_y, s32& width, s32& height)
	{
		int sz = hotspots.current()->size();
		offset_x = -16 + (16 - sz) / 2;
		offset_y = 16 - (16 - sz) / 2;
		width = sz;
		height = sz;
	}
} // namespace oot::pause::page