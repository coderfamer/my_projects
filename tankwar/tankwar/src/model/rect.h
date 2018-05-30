#ifndef __RECT_H__
#define __RECT_H__

#include "point.h"

class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	Rect(const Point p1, const Point p2);
	~Rect();

	Rect &operator=(const Rect &Rect);

	void set(const Point pStart, const Point pEnd);
	void set(int x1, int y1, int x2, int y2);

	void set_start_point(const Point p);
	void set_end_point(const Point p);

	Point get_start_point() const;
	Point get_end_point() const;

	int get_width();
	int get_height();

private:
	void check();

	Point m_start_point;
	Point m_end_point;
};

#endif