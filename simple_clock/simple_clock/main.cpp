#include <iostream>
#include <graphics.h>
#include <cmath>
#define PI 3.1415926
#define BASE_X 200
#define BASE_Y 200
#define BASE_R 150

void init_dial();//初始化钟表表盘

int main()
{
	initgraph(400, 400);

	init_dial();

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
}
