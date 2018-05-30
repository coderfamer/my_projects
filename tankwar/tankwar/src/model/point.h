#ifndef __POINT_H__
#define __POINT_H__

class Point
{
public:
	Point(int x = 0, int y = 0);
	~Point();

	Point & operator = (const Point &p);

	void set(int x, int y);
	void set_x(int x);
	void set_y(int y);

	int get_x();
	int get_y();
private:
	int m_x;
	int m_y;
};

#endif