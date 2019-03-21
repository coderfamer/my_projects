#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <graphics.h>
#include <cmath>
#include <time.h>
#define PI 3.1415926
#define BASE_X 200
#define BASE_Y 200
#define BASE_R 150

void init_dial();//初始化钟表表盘
void move_finger();

int main()
{
	initgraph(400, 400);

	init_dial();
	while (1)
	{
		move_finger();
	}
	
	system("pause");
	closegraph();
	return 0;
}

void init_dial()
{
	circle(200, 200, 150);

	for (int i = 6; i <= 360; i += 6)
	{
		int x1 = BASE_X + BASE_R * cos(i * PI / 180);
		int y1 = BASE_Y + BASE_R * sin(i * PI / 180);
		if (!(i % 90))
		{
			int x2 = BASE_X + 135 * cos(i * PI / 180);
			int y2 = BASE_Y + 135 * sin(i * PI / 180);
			setlinecolor(RED);
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 5);
			line(x1, y1, x2, y2);
			int m = BASE_X + 125 * cos(i * PI / 180);
			int n = BASE_Y + 125 * sin(i * PI / 180);
			//RECT r = { m + 5, n + 5,m - 5,n - 5 };
			//drawtext(i / 90, &r, DT_CENTER);
		}
		else if (!(i % 30) && (i % 90))
		{
			int x2 = BASE_X + 140 * cos(i * PI / 180);
			int y2 = BASE_Y + 140 * sin(i * PI / 180);
			setlinecolor(GREEN);
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);
			line(x1, y1, x2, y2);
		}
		else
		{
			int x2 = BASE_X + 145 * cos(i * PI / 180);
			int y2 = BASE_Y + 145 * sin(i * PI / 180);
			setlinecolor(YELLOW);
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 1);
			line(x1, y1, x2, y2);
		}
	}
	//setlinecolor(RED);
	//setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 10);
	//line(BASE_X, BASE_Y, BASE_X, BASE_X - BASE_R + 100);

	//setlinecolor(BLUE);
	//setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 7);
	//line(BASE_X, BASE_Y, BASE_X, BASE_X - BASE_R + 70);
}


void move_finger()
{
	Sleep(1000);
	
	clearcircle(BASE_X, BASE_Y, 120);
	//circle(BASE_X, BASE_Y, 5);
	tm *ltm;
	time_t nowtime = time(nullptr);
	ltm = localtime(&nowtime);
	int h = ltm->tm_hour;
	int m = ltm->tm_min;
	int s = ltm->tm_sec;
	int sx = BASE_X + 100 * cos((s - 15) * 6 * PI / 180);
	int sy = BASE_X + 100 * sin((s - 15) * 6 * PI / 180);
	setlinecolor(RED);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);
	line(BASE_X, BASE_Y,  sx, sy);

	int mx = BASE_X + 70 * cos((m + s/60 - 15) * 6 * PI / 180);
	int my = BASE_X + 70 * sin((m + s/60 - 15) * 6 * PI / 180);
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 5);
	line(BASE_X, BASE_Y, mx, my);


	int hx = BASE_X + 40 * cos((h + m / 60 - 15) * 30 * PI / 180);
	int hy = BASE_X + 40 * sin((h + m / 60 - 15) * 30 * PI / 180);
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 8);
	line(BASE_X, BASE_Y, hx, hy);

}
