#include "graphic.h"

Rect Graphic::m_rect_screen;
Rect Graphic::m_rect_battle_ground;

Graphic::Graphic()
{

}

Graphic::~Graphic()
{

}

void Graphic::create()
{
	m_rect_screen.set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Graphic::destory()
{
	closegraph();
}

int Graphic::get_screen_width()
{
	return m_screen_width;
}

int Graphic::get_screen_height()
{
	return m_screen_height;
}