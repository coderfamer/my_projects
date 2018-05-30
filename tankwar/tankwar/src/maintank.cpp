#include "maintank.h"

MainTank::MainTank()
{
	m_pos.set(300, 300);
	this->calculate_sphere();
	m_color = WHITE;
	m_dir = Dir::UP;
	m_step = 1;
}

MainTank::~MainTank()
{

}

void MainTank::set_dir(Dir dir)
{
	m_dir = dir;
}

void MainTank::draw_tank_body()
{
	fillrectangle(m_pos.get_x() - 6, m_pos.get_y() - 6, m_pos.get_x() + 6, m_pos.get_y() + 6);
	
	switch (m_dir)
	{
	case Dir::UP:
	case Dir::DOWN:
		fillrectangle(m_rect_sphere.get_start_point().get_x(), m_rect_sphere.get_start_point().get_y(),
			m_rect_sphere.get_start_point().get_x() + 4, m_rect_sphere.get_end_point().get_y());
		fillrectangle(m_rect_sphere.get_end_point().get_x() -4, m_rect_sphere.get_start_point().get_y(),
			m_rect_sphere.get_end_point().get_x(), m_rect_sphere.get_end_point().get_y());
		break;
	case Dir::LEFT:
	case Dir::RIGHT:
		fillrectangle(m_rect_sphere.get_start_point().get_x(), m_rect_sphere.get_start_point().get_y(),
			m_rect_sphere.get_end_point().get_x(), m_rect_sphere.get_start_point().get_y() + 4);
		fillrectangle(m_rect_sphere.get_start_point().get_x(), m_rect_sphere.get_end_point().get_y() - 4,
			m_rect_sphere.get_end_point().get_x(), m_rect_sphere.get_end_point().get_y());
		break;
	default:
		break;
	}


}

void MainTank::display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(m_color);

	draw_tank_body();

	switch (m_dir)
	{
	case Dir::UP:
		line(m_pos.get_x(), m_pos.get_y(), m_pos.get_x(), m_pos.get_y() - 15);
		break;
	case Dir::DOWN:
		line(m_pos.get_x(), m_pos.get_y(), m_pos.get_x(), m_pos.get_y() + 15);
		break;
	case Dir::LEFT:
		line(m_pos.get_x(), m_pos.get_y(), m_pos.get_x() - 15, m_pos.get_y());
		break;
	case Dir::RIGHT:
		line(m_pos.get_x(), m_pos.get_y(), m_pos.get_x() + 15, m_pos.get_y());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(color_save);
}

void MainTank::move()
{
	switch (m_dir)
	{
	case Dir::UP:
		m_pos.set_y(m_pos.get_y() - m_step);
		if (m_pos.get_y() < Graphic::get_battle_ground().get_start_point().get_y())
			m_pos.set_y(Graphic::get_battle_ground().get_end_point().get_y() - 1);
		break;
	case Dir::DOWN:
		m_pos.set_y(m_pos.get_y() + m_step)
		if (m_pos.get_y() > Graphic::get_battle_ground().get_end_point().get_y())
			m_pos.set_y(Graphic::get_battle_ground().get_start_point().get_y() + 1);
		break;
	case Dir::LEFT:
		m_pos.set_x(m_pos.get_x() - m_step);
		if (m_pos.get_x() < Graphic::get_battle_ground().get_start_point().get_x())
			m_pos.set_x(Graphic::get_battle_ground().get_end_point().get_x() - 1);
		break;
	case Dir::RIGHT:
		m_pos.set_x(m_pos.get_x() + m_step);
		if (m_pos.get_x() > Graphic::get_battle_ground().get_end_point().get_x())
			m_pos.set_x(Graphic::get_battle_ground().get_start_point().get_x() + 1);
		break;
	default:
		break;
	}

	calculate_sphere();
}


void MainTank::calculate_sphere()
{
	switch (m_dir)
	{
	case Dir::UP:
	case Dir::DOWN:
		m_rect_sphere.set(m_pos.get_x() - 13, m_pos.get_y() - 10, m_pos.get_x() + 13, m_pos.get_y() + 10);
		break;
	case Dir::LEFT:
	case Dir::RIGHT:
		m_rect_sphere.set(m_pos.get_x() - 10, m_pos.get_y() - 13, m_pos.get_x() + 10, m_pos.get_y() + 13);
		break;
	default:
		break;
	}
}