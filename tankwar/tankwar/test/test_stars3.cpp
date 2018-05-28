/*
#include <graphics.h>
#include <time.h>
#include <conio.h>

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768
#define MAXSTAR         400

class StarType
{
public:
	virtual void Draw(int x, int y, int color) = 0;
	virtual void Remove(int x, int y) = 0;
};

class PointStar : public StarType
{
	void Draw(int x, int y, int color)
	{
		putpixel((int)x, y, color);
		setcolor(color);
		circle(x, y, 1);
	}

	void Remove(int x, int y)
	{
		putpixel((int)x, y, 0);
		setcolor(0);
		circle(x, y, 1);
	}
};

class RectStar : public StarType
{
	void Draw(int x, int y, int color)
	{
		putpixel((int)x, y, color);
		setcolor(color);
		rectangle(x - 1, y - 1, x + 1, y + 1);
	}

	void Remove(int x, int y)
	{
		putpixel((int)x, y, 0);
		setcolor(0);
		rectangle(x - 1, y - 1, x + 1, y + 1);
	}
};

class XStar : public StarType
{
	void Draw(int x, int y, int color)
	{
		settextcolor(color);
		outtextxy(x, y, _T("x"));
	}

	void Remove(int x, int y)
	{
		settextcolor(0);
		outtextxy(x, y, _T("x"));
	}
};

class Star
{
public:
	Star() : m_x(0){}
	~Star(){}

	void Init();
	void Init(StarType* pStarType);
	void Move();

protected:
	void NewPos();
public:
	double  m_x;
	int     m_y;
	double  m_step;
	int     m_color;

	StarType* m_pStarType;
};

void Star::Init()
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
		m_step = (rand() % 5000) / 1000.0 + 10;
		m_color = (int)(m_step * 255 / 6.0 + 0.5);
		color[i] = m_color;
	}


	m_color = RGB(color[0], color[1], color[2]);
}

void Star::Init(StarType* pStarType)
{
	this->Init();
	m_pStarType = pStarType;
}

void Star::Move()
{
	m_pStarType->Remove(m_x, m_y);

	NewPos();

	m_pStarType->Draw(m_x, m_y, m_color);
}

void Star::NewPos()
{
	m_x += m_step;
	if (m_x > SCREEN_WIDTH)
		this->Init();
}

void main()
{
	srand((unsigned)time(NULL));

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT); 

	Star star[MAXSTAR];

	PointStar pointStar;
	RectStar rectStar;
	XStar xStar;
	for (int i = 0; i < MAXSTAR; i++)
	{
		switch (i % 3)
		{
		case 0:
			star[i].Init(&pointStar);
			break;
		case 1:
			star[i].Init(&rectStar);
			break;
		case 2:
			star[i].Init(&xStar);
			break;
		default:
			break;
		}
	}

	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
		{
			star[i].Move();
		}

		Sleep(50);
	}

	closegraph();
}
*/