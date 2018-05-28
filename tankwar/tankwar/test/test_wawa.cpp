#include <iostream>
#include <graphics.h>
#include <conio.h>

int main_wawa()
{
	initgraph(800, 600);

	COLORREF save_color = getfillcolor();

	circle(300, 150, 50);
	circle(500, 150, 50);

	ellipse(200, 50, 600, 300);
	setfillcolor(GREEN);
	floodfill(250, 200, getlinecolor());

	setfillcolor(0xFFFFFF);
	fillellipse(300, 200, 500, 300);

	rectangle(10, 10, 790, 590);
	line(400, 500, 400, 590);
	rectangle(200, 300, 600, 500);

	_getch();

	setfillcolor(save_color);

	closegraph();
	return 0;
}