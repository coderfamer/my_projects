#ifndef  __GRAPHIC_H__
#define	__GRAPHIC_H__

#include <graphics.h>
#include "model/rect.h"
#define  SCREEN_WIDTH		1024
#define  SCREEN_HEIGHT		768

#define BATTLE_GROUND_X1	5
#define BATTLE_GROUND_Y1	5
#define BATTLE_GROUND_X2	800
#define BATTLE_GROUND_Y2	(SCREEN_HEIGHT - BATTLE_GROUND_Y1)

class Graphic
{
public:
	Graphic();
	~Graphic();

	static void create();
	static void destory();

	static void draw_battle_ground();

	static int get_screen_width();
	static int get_screen_height();

	static Rect get_battle_ground();

private:
	static Rect m_rect_screen;
	static Rect m_rect_battle_ground;
};

#endif