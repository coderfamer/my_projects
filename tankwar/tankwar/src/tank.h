#ifndef __TANK_H__ 
#define	__TANK_H__

#include "graphic.h"

enum class Dir {UP, DOWN, LEFT, RIGHT};

class Tank
{
public:
	virtual void display() = 0;
	virtual void move() = 0;

protected:
	virtual void calculate_sphere() = 0;

	Point m_pos;
	Rect m_rect_sphere;

	COLORREF m_color;

	Dir m_dir;
	int m_step;
};

#endif