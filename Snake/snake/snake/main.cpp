#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;


HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
class Snake;
void Init_Console();//console init
void gotoPos(SHORT x = 0, SHORT y = 0);
void Init_Map();
void KeyConctrl(Snake &, int);
void is_gameover();
void Prompt_info(int, int);
void dis_date(int, int, double, int);

bool gameOver = false;
bool withdraw = false;


class Snake
{
public:
	Snake(SHORT x = 9, SHORT y = 5);
	~Snake();

	void up_speed() { if (this->speed < 5) (this->speed)++; }
	double get_speed() { return this->speed; }
	int get_length() { return this->length; }
	void dir_control(char dir);
	void setPos(COORD pos) { SetConsoleCursorPosition(hOut, pos); }
	void check_bit();
	bool check_snk(COORD snk_Pos);
	void dis();
	void cle();
	void save_date();
	bool move();
private:
	bool flash;
	int speed, length, print_bit, clear_bit;
	COORD in_pos, bit_pos;
	COORD pos[255];
	enum direction
	{
		go_stop = 0,
		go_left,
		go_right,
		go_up,
		go_down
	}dir;
};

int main()
{
	do
	{
		Init_Console();
		Init_Map();
		Prompt_info(3, 3);
		Snake s(27, 11);
		clock_t t_in, t_out;
		t_in = clock();
		s.dis();

		while (!gameOver)
		{
			if (_kbhit())
			{
				KeyConctrl(s, _getch());
			}
			t_out = clock();
			dis_date(3, 5, s.get_speed(), s.get_length());
			if (t_out - t_in > ((0.25 - (s.get_speed() / 25)) * CLOCKS_PER_SEC))
			{
				t_in = t_out;
				gameOver = s.move();
				if (gameOver)
					is_gameover();
			}
		}
		Sleep(10);

	}while (!withdraw);
	gotoPos(15, 13);

	return 0;
}

Snake::Snake(SHORT x /* = 9 */, SHORT y /* = 5 */)
{
	clear_bit = print_bit = length = speed = 0;
	in_pos.X = x;
	in_pos.Y = y;
	bit_pos.X = 11;
	bit_pos.Y = 8;
	flash = true;
	pos[0].X = in_pos.X;
	pos[0].Y = in_pos.Y;
}

Snake::~Snake()
{

}

void Snake::dir_control(char dir)
{
	switch (dir)
	{
	case 's':
		this->dir = go_stop;
		break;
	case 'l':
		if (this->dir != go_right)
			this->dir = go_left;
		break;
	case 'r':
		if (this->dir != go_left)
			this->dir = go_right;
	case 'u':
		if (this->dir != go_down)
			this->dir  = go_up;
		break;
	case 'd':
		if (this->dir != go_up)
			this->dir = go_down;
		break;
	default:
		break;
	}
}

void Snake::check_bit()
{
	if (in_pos.X == bit_pos.X && in_pos.Y == bit_pos.Y)
	{
		length++;
		if ((length % 5) == 0)
			if (this->speed < 5)
				this->speed++;
		if (length == 254)
		{
			cout << "game clear!!!";
		}
		do 
		{
			srand(time(NULL));
			bit_pos.X = 3 + (rand() % 20) * 2;
			bit_pos.Y = 2 + rand() % 20;
		} while (check_snk(bit_pos));
	}
	else
	{
		cle();
		clear_bit++;
	}
}

bool Snake::check_snk(COORD snk_Pos)
{
	if (snk_Pos.Y <= 1 || (snk_Pos.Y >= 23) || (snk_Pos.X <= 1) || snk_Pos.X >= 45)
	{
		return true;
	}
	for (int i = clear_bit; i <= print_bit; i++)
	{
		if (pos[i].X == snk_Pos.X && pos[i].Y == snk_Pos.Y)
			return true;
	}
	return false;
}

void Snake::dis()
{
	if (!flash)
	{
		setPos(bit_pos);
		SetConsoleTextAttribute(hOut, 0x0e);
		cout << " ";
		flash = true;
	}
	else
	{
		setPos(bit_pos);
		SetConsoleTextAttribute(hOut, 0x0e);
		cout << "■";
		flash  = false;
	}
	setPos(in_pos);
	SetConsoleTextAttribute(hOut, 0x09);
	cout << "■";
}

void Snake::cle()
{
	setPos(pos[clear_bit]);
	SetConsoleTextAttribute(hOut, 0x05);
	cout << " ";
}

void Snake::save_date()
{
	if (print_bit == 254)
	{
		for (int i = 0; i <= length; i++)
		{
			pos[i].X = pos[clear_bit + i ].X;
			pos[i].Y = pos[clear_bit + i ].Y;
		}
		clear_bit = 0;
		print_bit = length;
	}
	print_bit++;
	pos[print_bit].X = in_pos.X;
	pos[print_bit].Y = in_pos.Y;
}

bool Snake::move()
{
	switch (this->dir)
	{
	case go_stop:
		break;
	case go_left:
		in_pos.X -= 2;
		if (check_snk(in_pos))
		{
			return true;
		}
		dis();
		save_date();
		check_bit();
		break;
	case go_right:
		in_pos.X += 2;
		if (check_snk(in_pos))
		{
			return true;
		}
		dis();
		save_date();
		check_bit();
		break;
	case go_up:
		in_pos.Y--;
		if (check_snk(in_pos))
		{
			return true;
		}
		dis();
		save_date();
		check_bit();
		break;
	case go_down:
		in_pos.Y++;
		if (check_snk(in_pos))
		{
			return true;
		}
		dis();
		save_date();
		check_bit();
		break;
	default:
		break;
	}
	return false;
}

void Init_Console()
{
	SetConsoleTitleA("console_snake");
	COORD dSiz = {80, 25};
	SetConsoleScreenBufferSize(hOut, dSiz);
	CONSOLE_CURSOR_INFO cursor = {1, FALSE};
	SetConsoleCursorInfo(hOut, &cursor);
	system("color 0f");
}

void gotoPos(SHORT x /* = 0 */, SHORT y /* = 0 */)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}

void Init_Map()
{
	system("cls");

	cout << endl;
	for (int i = 0; i< 23; i++)
	{
		cout << " ●" << endl;
	}

	gotoPos(3, 1);
	for (int i = 0; i < 21; i++)
	{
		cout << "●";
	}

	gotoPos(3, 23);
	for (int i = 0; i < 21; i++)
	{
		cout << "●";
	}

	for (SHORT i = 1; i <= 23; i++)
	{
		gotoPos(45, i);
		cout << "●";
	}
}

void KeyConctrl(Snake & snk, int key)
{
	switch (key)
	{
	case ' ':
		snk.dir_control('s');
		break;
	case 'w':
	case 'W':
	case 72:
		snk.dir_control('u');
		break;
	case 'a':
	case 'A':
	case 75:
		snk.dir_control('l');
		break;
	case 'd':
	case 'D':
	case 77:
		snk.dir_control('r');
		break;
	case 's':
	case 'S':
	case 80:
		snk.dir_control('d');
		break;
	case '+':
		snk.up_speed();
		break;
	default:
		break;
	}
}

void is_gameover()
{
	gotoPos(17, 11);
	SetConsoleTextAttribute(hOut, 0xec);
	cout << "game over!!";
	gotoPos(15, 12);
	cout << "Y play again / N exit";
	SetConsoleTextAttribute(hOut, 0x0f);
}

void Prompt_info(int x, int y)
{
	SetConsoleTextAttribute(hOut, 0xB);
	gotoPos(x + 47, y + 0);
	cout << ">>game explain" << endl;
	gotoPos(x + 51, y + 2);
	cout << "A.sources 500, speed +1";
	gotoPos(x + 51, y + 3);
	cout << "B. speed by yourself, MAX 5";
	gotoPos(x+47, y+5);
	cout << "■操作说明：";
	gotoPos(x+51, y+7);
	cout << "□向左移动：← A";
	gotoPos(x+51, y+8);
	cout << "□向右移动：→ D";
	gotoPos(x+51, y+9);
	cout << "□向下移动：↓ S";
	gotoPos(x+51, y+10);
	cout << "□向上移动：↑ W";
	gotoPos(x+51, y+11);
	cout << "□控制加速：+";
	gotoPos(x+51, y+12);
	cout << "□暂停游戏：空格";
	gotoPos(x+51, y+13);
	cout << "□开始游戏：任意方向键";
	gotoPos(x+47, 22);
	cout <<"■By: Flowingwind 18.01.11";
}

void dis_date(int x, int y, double sped, int score)
{
	SetConsoleTextAttribute(hOut, 0xB);
	gotoPos(x + 47, y + 13);
	cout << setw(2) << ">> speed: ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << sped;
	gotoPos(x + 47, y + 14);
	SetConsoleTextAttribute(hOut, 0xB);
	cout << ">> score: ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << setw(2) << score * 100;
}