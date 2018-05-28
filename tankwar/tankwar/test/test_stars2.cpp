
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

//private:
	double m_x;
	int m_y;
	double m_step;
	int m_color;
};

class RectStar : public Star
{
public:
	RectStar();
	~RectStar();

	void move()
	{
		remove();
		newpos();
		draw();
	}
protected:
	void draw();
	void remove();
private:

};



RectStar::RectStar()
{
}

RectStar::~RectStar()
{
}

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
	

	int color[3];

	for (int i = 0; i < 3; i++)
	{
		m_step = (rand() % 5000) / 1000.0 + 25;
		m_color = (int)(m_step * 255 / 6.0 + 0.5);
		color[i] = m_color;
	}

	
	m_color = RGB(color[0], color[1], color[2]);
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
	circle((int)m_x, m_y, 1);
}

void Star::move()
{
	remove();

	newpos();

	draw();
}

void RectStar::draw()
{
	setfillcolor(m_color);
	fillrectangle(m_x, m_y, m_x + 3, m_y + 3);
}

void RectStar::remove()
{
	clearrectangle(m_x, m_y, m_x +4, m_y + 3);
}

int main()
{
	srand((unsigned)time(NULL));

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	Star star[MAXSTAR];
	RectStar rstar[MAXSTAR];

	for (int i = 0; i < MAXSTAR; i++)
	{
		star[i].init();
		rstar[i].init();
	}

	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
		{
			star[i].move();
			rstar[i].move();
		}
		Sleep(30);
	}

	closegraph();

	return 0;
}
