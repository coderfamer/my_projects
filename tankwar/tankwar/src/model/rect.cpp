#include "rect.h"

Rect::Rect(int x1 /* = 0 */, int y1 /* = 0 */, int x2 /* = 0 */, int y2 /* = 0 */)
	: m_start_point(x1, y1), m_end_point(x2, y2)
{

}

Rect::Rect(const Point p1, const Point p2)
	: m_start_point(p1), m_end_point(p2)
{

}

Rect::~Rect()
{

}

Rect& Rect::operator=(const Rect &rect)
{
	m_start_point = rect.get_start_point();
	m_end_point = rect.get_end_point();

	return *this;
}

void Rect::set(const Point pStart, const Point pEnd)
{
	m_start_point = pStart;
	m_end_point = pEnd;
}

void Rect::set(int x1, int y1, int x2, int y2)
{
	m_start_point.set(x1, y1);
	m_end_point.set(x2, y2);
}

void Rect::set_start_point(const Point p)
{
	m_start_point = p;
}

void Rect::set_end_point(const Point p)
{
	m_end_point = p;
}

Point Rect::get_start_point() const
{
	return m_start_point;
}

Point Rect::get_end_point() const
{
	return m_end_point;
}

int Rect::get_width()
{
	return m_end_point.get_x() - m_start_point.get_x();
}

int Rect::get_height()
{
	return m_end_point.get_y() - m_start_point.get_y();
}

void Rect::check()
{
	if (m_start_point.get_x() > m_end_point.get_x() || m_start_point.get_y() == m_end_point.get_y())
	{
		Point p = m_start_point;
		m_start_point = m_end_point;
		m_end_point = p;
	}
}