#include <graphics.h>
#include <conio.h>

int main_circle()
{
	initgraph(640, 480);
	circle(200, 200, 100);
	_getch();
	closegraph();
	return 0;
}