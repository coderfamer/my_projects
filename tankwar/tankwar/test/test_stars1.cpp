/*
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <time.h>

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768
#define  MAXSTAR		400

class Star
{
public:
	Star():m_x(0) { }
	~Star() { }
	
	void init();
	void move();
protected:
private:
	double m_x;
	int m_y;
	double m_step;
	int m_color;
};

void Star::init()
{
	if (m_x == 0)
	{
		m_x = rand() % SCREEN_WIDTH;
	}
	else
	{
		m_x = 0;
	}

	m_y = rand() % SCREEN_HEIGHT;
	m_step = (rand() % 5000) / 1000.0 + 1;
	m_color = (int)(m_step * 255 / 6.0 + 0.5);
	m_color = RGB(m_color, m_color, m_color);
}

void Star::move()
{
	putpixel((int)m_x, m_y, 0);

	m_x += m_step;
	if (m_x > SCREEN_WIDTH)
		this->init();

	putpixel((int)m_x, m_y, m_color);
}

int main_star1()
{
	srand((unsigned)time(NULL));

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	Star star[MAXSTAR];

	for (int i = 0; i < MAXSTAR; i++)
	{
		star[i].init();
	}

	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
		{
			star[i].move();
		}
		Sleep(30);
	}

	closegraph();

	return 0;
}
*/