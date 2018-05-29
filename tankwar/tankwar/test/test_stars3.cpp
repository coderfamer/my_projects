//#include <iostream>
//#include <time.h>
//#include <conio.h>
//#include <graphics.h>
//
//#define SCREEN_WIDTH	1024
//#define SCREEN_HEIGHT	768
//#define MAXSTAR			400
//
//class StarType
//{
//public:
//	virtual void draw(int x, int y, int color) = 0;
//	virtual void remove(int x, int y) = 0;
//};
//
//class PointStar : public StarType
//{
//public:
//	void draw(int x, int y, int color);
//	void remove(int x, int y);
//};
//
//void PointStar::draw(int x, int y, int color)
//{
//	putpixel((int)x, y, color);
//	setcolor(color);
//	setfillcolor(color);
//	circle(x, y, 10);
//}
//
//void PointStar::remove(int x, int y)
//{
//	putpixel((int)x, y, 0);
//	setcolor(0);
//	
//	circle(x, y, 10);
//}
//
//class RectStar : public StarType
//{
//public:
//	void draw(int x, int y, int color);
//	void remove(int x, int y);
//};
//
//void RectStar::draw(int x, int y, int color)
//{
//	putpixel((int)x, y, color);
//	setcolor(color);
//	rectangle(x - 1, y - 1, x + 1, y + 1);
//}
//
//void RectStar::remove(int x, int y)
//{
//	putpixel((int)x, y, 0);
//	setcolor(0);
//	rectangle(x - 1, y - 1, x + 1, y + 1);
//}
//
//class TextStar : public StarType
//{
//public:
//	void draw(int x, int y, int color);
//	void remove(int x, int y);
//};
//
//void TextStar::draw(int x, int y, int color)
//{
//	setcolor(color);
//	outtextxy(x, y, _T("UZI£¡£¡"));
//}
//
//void TextStar::remove(int x, int y)
//{
//	setcolor(0);
//	outtextxy(x, y, _T("Hello world"));
//}
//
//class Star
//{
//public:
//	Star() : m_x(0) {}
//	~Star() {}
//
//	void Init();
//	void Init(StarType *pStarType);
//	void move();
//
//	void newpos();
//private:
//	double m_x;
//	int m_y;
//	double m_step;
//	int m_color;
//
//	StarType * m_pStarType;
//};
//
//void Star::Init()
//{
//	if (m_x == 0)
//	{
//		m_x = rand() % SCREEN_WIDTH;
//	}
//	else
//	{
//		m_x = 0;
//	}
//
//	m_y = rand() % SCREEN_HEIGHT;
//	
//
//	int color[3];
//
//	for (int i = 0; i < 3; i++)
//	{
//		m_step = (rand() % 5000) / 1000.0 + 1;
//		m_color = (int)(m_step * 255 / 6.0 + 0.5);
//		color[i] = m_color;
//	}
//
//	
//	m_color = RGB(color[0], color[1], color[2]);
//}
//
//void Star::Init(StarType *pStarType)
//{
//	this->Init();
//	m_pStarType = pStarType;
//}
//
//void Star::move()
//{
//	m_pStarType->remove(m_x, m_y);
//
//	newpos();
//
//	m_pStarType->draw(m_x, m_y, m_color);
//}
//
//void Star::newpos()
//{
//	m_x += m_step;
//	if (m_x > SCREEN_WIDTH)
//		this->Init();
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
//
//	//Star star[MAXSTAR];
//	Star star1[MAXSTAR];
//	Star star2[MAXSTAR];
//	Star star3[MAXSTAR];
//	PointStar pointStar;
//	RectStar rectStar;
//	TextStar textStar;
//
//	for (int i = 0; i < MAXSTAR; i++)
//	{
//		star1[i].Init(&pointStar);
//		star2[i].Init(&rectStar);
//		star3[i].Init(&textStar);
//		/*switch (i % 3)
//		{
//		case 0:
//			star[i].Init(&pointStar);
//			break;
//		case 1:
//			star[i].Init(&rectStar);
//			break;
//		case 2:
//			star[i].Init(&textStar);
//			break;
//		default:
//			break;
//		}*/
//	}
//
//	while (!_kbhit())
//	{
//		for (int i = 0; i < MAXSTAR; i++)
//		{
//			star1[i].move();
//			star2[i].move();
//			star3[i].move();
//		}
//		Sleep(50);
//	}
//
//
//	closegraph();
//
//	return 0;
//}