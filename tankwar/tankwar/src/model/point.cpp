#include "point.h"

Point::Point(int x /* = 0 */, int y /* = 0 */) : m_x(x), m_y(y)
{

}

Point::~Point()
{

}

Point& Point::operator=(const Point &p)
{
	m_x = p.m_x;
	m_y = p.m_y;

	return *this;
}

void Point::set(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Point::set_x(int x)
{
	m_x = x;
}

void Point::set_y(int y)
{
	m_y = y;
}

int Point::get_x()
{
	return m_x;
}

int Point::get_y()
{
	return m_y;
}



