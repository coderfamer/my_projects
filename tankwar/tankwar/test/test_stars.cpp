#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <time.h>

#define MAXSTARS 2000 //��������

struct  STARS
{
	double x;
	int y;
	double step;
	int color;
};

STARS stars[MAXSTARS];

void init_stars(int i)
{
	stars[i].x = 0;
	stars[i].y = rand() % 480;
	stars[i].step = (rand() % 5000) / 1000.0 + 1;
	stars[i].color = (int)(stars[i].step * 255 / 6.0 + 0.5);  //�ٶ�Խ�죬��ɫԽ��
	stars[i].color = RGB(stars[i].color, stars[i].color, stars[i].color);
}

//�ƶ�����
void move_stars(int i)
{
	putpixel((int)stars[i].x, stars[i].y, 0);

	//�����µ�λ��
	stars[i].x += stars[i].step;
	if (stars[i].x > 640 )
		init_stars(i);

	//��������
	putpixel((int)stars[i].x, stars[i].y, stars[i].color);
}

int main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);

	//��ʼ����������
	for (int i = 0; i < MAXSTARS; i++)
	{
		init_stars(i);
		stars[i].x = rand() % 640;
	}

	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTARS; i++)
		{
			move_stars(i);
		}
		Sleep(20);
	}

	closegraph();
	return 0;
}