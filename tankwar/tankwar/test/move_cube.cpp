#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

void block(int length);
void strong_block();

int main()
{
	strong_block();

	return 0;
}

void block(int length, COLORREF color)
{
	setorigin(getwidth() / 2, getheight() / 2);
	POINT a[4][6];
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 6; i++)
		{
			a[j][i].x = (int)pow(-1, j / 2 + j % 2 + 1) * length * i / 5;
			a[j][i].y = (int)pow(-1, j / 2 + 1) * length * (5 - i) / 5;
		}
	}

	setlinecolor(color);

	for (i = 0, j = 5; i < 6; i++, j--)
	{
		line(a[0][i].x, a[0][i].y, a[2][j].x, a[2][j].y);
		line(a[1][i].x, a[1][i].y, a[3][j].x, a[3][j].y);
	}
}

void strong_block()
{
	initgraph(800, 800);
	int length;
	float H, S, L;
	while (!_kbhit())
	{
		length = 10;
		H = 0;
		S = 1;
		L = 0.5;
		while (length <= getwidth() / 2 )
		{
			block(length, HSLtoRGB(H, S, L));
			Sleep(50);
			length += 4;
			H += (float)1.8;
		}
		length = 400;
		H = 360;
		S = 1;
		L = 0.5;
		while (length > 10)
		{
			block(length, HSLtoRGB(H, S, L));
			Sleep(50);
			length -= 4;
			H -= (float)1.8;
		}
	}

	//int length = 100;
	//float H, S, L;
	//H = 0;
	//S = 1;
	//L = 0.5;
	//block(length, HSLtoRGB(H, S, L));
	_getch();
	closegraph();
}