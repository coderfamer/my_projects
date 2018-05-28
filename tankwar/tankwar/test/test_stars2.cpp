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
	Star();
	~Star();

	void init();
	void move();

protected:
	void draw();
	void newpos();
	void remove();

private:
	double m_x;
	int m_y;
	double m_step;
	int m_color;
};

Star::Star()  : m_x(0)
{
}

Star::~Star()
{
}

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

void Star::draw()
{
	putpixel((int)m_x, m_y, m_color);
	setcolor(m_color);
	circle((int)m_x, m_y, 1);
}

void Star::newpos()
{
	m_x += m_step;
	if (m_x > SCREEN_WIDTH)
	{
		this->init();
	}
}

void Star::remove()
{
	putpixel((int)m_x, m_y, 0);
	setcolor(0);
	circle((int)m_x, m_y, 10);
}

void Star::move()
{
	remove();

	newpos();

	draw();
}

int main()
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
