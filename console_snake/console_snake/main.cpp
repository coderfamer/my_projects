//#include "public.h"
////#include "graph.h"
////#include "Node.h"
//
//
//void initGraph();//��ʼ������
//
//int main()
//{
//	initgraph(640, 480);
//	
//	initGraph();
//
//
//	
//
//	system("pause");
//	closegraph();
//	
//	return 0;
//}
//
//void initGraph()
//{
//	rectangle(10, 10, 600, 400);
//	rectangle(10, 10, 400, 400);
//	rectangle(400, 10, 600, 210);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h> //EasyX_2011���ݰ棨��ͼ�⣩
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>

#define UP		1
#define DOWN	2
#define LEFT	3
#define RIGHT	4
////////////////////////////////////////////
//�����࣬����һ�����ӵ����Լ���Ϊ
////////////////////////////////////////////
class Cell
{
public:

	friend class GameArea;  //������Ԫ����

	void setxy(short x, short y)   //���ø������Ͻ�����
	{
		m_x = x, m_y = y;
	}
	void setfull(short full)  //���ø������ԣ�0Ϊ�գ�1Ϊ�ϰ���2Ϊʳ��
	{
		m_full = full;
	}
	void display(COLORREF color)  //���ø�����ɫ����ʾ
	{
		m_color = color;
		setfillstyle(m_color);
		bar(m_x, m_y, m_x + 7, m_y + 7);
	}
	void LaserDisplay()  //��ʾ����״̬�ĸ���
	{
		IMAGE image(10, 10);
		SetWorkingImage(&image);
		DWORD* pMem = GetImageBuffer(&image);
		for (int i = 0; i < 10 * 10; i++)
			pMem[i] = BGR(RGB(0, 0, i * 256 / (10 * 10)));
		SetWorkingImage(NULL);
		putimage(m_x, m_y, &image);
	}
	short ReturnFull()  //���ظ���״̬
	{
		return m_full;
	}
	Cell()  //���캯��
	{
		m_x = 0, m_y = 0, m_full = 0;
		m_color = BLACK;
	}

private:

	short m_x;			//���ӵ����Ͻ�X����
	short m_y;			//���ӵ����Ͻ�Y����
	short m_full;		//0Ϊ�գ�1Ϊ�赲��2Ϊʳ��
	COLORREF m_color;	//������ɫ
};
////////////////////////////////////////////
//��Ϸ���࣬��д�й���Ϸ����һЩ����
////////////////////////////////////////////
class GameArea  //��Ϸ����
{
public:

	Cell m_game[60][60];			//������Ϸ������360��������ɣ�

	friend void MessageDispose();	//������Ԫ����

	bool CreatFood()				//�������ʳ��
	{
		srand(time(NULL));			//��ʼ�����������
		m_random1 = rand() % 58 + 1;		//�������һ��0 - 58������
		m_random2 = rand() % 58 + 1;		//���һ��0 - 58������
		if (m_game[m_random2][m_random2].m_full == 0)	//������ɵ�ʳ�������Ƿ����ϰ���
		{
			m_game[m_random1][m_random2].display(GREEN);
			m_game[m_random1][m_random2].m_full = 2;
			return true;
		}
		//��������ʳ�����ó����������ϣ�����������ѭ��Ѱ�ҿ�������ʳ��ĵط�
		for (m_random1 = 1; m_random1 < 59; m_random1++)
		{
			for (m_random2 = 1; m_random2 < 59; m_random2++)
			{
				if (m_game[m_random2][m_random2].m_full == 0)
				{
					m_game[m_random1][m_random2].display(GREEN);
					m_game[m_random1][m_random2].m_full = 2;
					return true;
				}
			}
		}
		//���û���ҵ���������ʳ��ĵط�����ͨ��
		return false;  //����false����ʾͨ��
	}
	void DelFood()	//ɾ��ʳ��
	{
		m_game[m_random1][m_random2].m_full = 0;  //����Ϊ0�������������Ϊ��
	}
	void ChangeColor(int flag1, int flag2, COLORREF color)  //����ָ�����ӵ���ɫ
	{
		m_game[flag1][flag2].display(color);
	}
	void Init()					//��ʼ��GAME����
	{
		int flag1, flag2;		//��ʶ����
		BeginBatchDraw();		//��ʼ������ͼ
		setfillstyle(BLACK);	//���õ�ǰ��ɫ
		bar(0, 0, 600, 600);		//���ޱ߿������Σ����������;���ú�ɫ�����Ϸ����
		for (flag1 = 0; flag1 < 60; flag1++)
		{
			for (flag2 = 0; flag2 < 60; flag2++)
			{
				if (flag1 == 0 || flag1 == 59 || flag2 == 0 || flag2 == 59)	//�����߽�
				{
					m_game[flag1][flag2].setfull(1);
					m_game[flag1][flag2].setxy(flag1 * 10, flag2 * 10);
					m_game[flag1][flag2].display(RGB(237, 28, 36));
				}
				else														//������Ϸ����
				{
					m_game[flag1][flag2].setfull(0);
					m_game[flag1][flag2].setxy(flag1 * 10, flag2 * 10);
					m_game[flag1][flag2].display(BLACK);
				}
			}
		}
		CreatFood();
		EndBatchDraw();
	}

private:

	int m_random1, m_random2;
};
////////////////////////////////////////////
//���࣬�����ߵ����ݽṹ�Լ��ߵ���Ϊ
////////////////////////////////////////////
class Snake
{
public:

	int toward;		//��ͷ����	
	friend void MessageDispose();
	friend int HitDetect();
	friend void ReInit();
	Snake()
	{
		head = NULL;
		last = NULL;
		now = NULL;
	}
	void Init()			//��ʼ���ߵĽṹ
	{
		if (head != NULL)  //������Ϸʱ���ͷ�ԭ�ȵ��������н��
		{
			for (now = head->next; now->next != NULL; now = now->next)
			{
				free(now->prior);
			}
		}
		head = (struct node*)malloc(sizeof(struct node));  //Ϊ��ͷ�����ڴ�
		head->prior = NULL;
		head->m_x = 300;
		head->m_y = 300;
		now = (struct node*)malloc(sizeof(struct node));
		head->next = now;
		now->prior = head;
		now->next = NULL;
		now->m_x = 300;
		now->m_y = 290;
		last = now;
		toward = DOWN;
	}
	void SnakeAdd()
	{
		now = head;			//��ǰָ����ͷ
		now->prior = (struct node*)malloc(sizeof(struct node));  //Ϊ�����Ľ������ڴ�
		now = now->prior;	//�õ�ǰָ���·���Ľ��
		now->prior = NULL;  //�ÿյ�ǰ����ǰ��
		now->next = head;	//�õ�ǰ���ĺ��ָ����ͷ

		switch (toward)		//���ݵ�ǰ��ͷ����ȷ���������ֵ�����
		{
		case UP:
			now->m_x = head->m_x;
			now->m_y = head->m_y - 10;
			break;
		case DOWN:
			now->m_x = head->m_x;
			now->m_y = head->m_y + 10;
			break;
		case LEFT:
			now->m_x = head->m_x - 10;
			now->m_y = head->m_y;
			break;
		case RIGHT:
			now->m_x = head->m_x + 10;
			now->m_y = head->m_y;
			break;
		}
		head = now; //���õ�ǰ���Ϊ��ͷ

	}
	void SnakeDel()		//�ͷ���β��㣨ɾ����β��
	{
		last = last->prior;
		free(last->next);
		last->next = NULL;
	}
	void SnakeMove()	//�����ƶ�һ��
	{
		SnakeAdd();		//������ͷ
		SnakeDel();		//ɾ����β
	}

private:

	struct node				 //��������
	{
		int m_x;
		int m_y;
		struct node *next;  //�¸����
		struct node *prior; //�ϸ����
	};
	struct node *head;
	struct node *last;
	struct node *now;
};
////////////////////////////////////////////
//��Ϸ�࣬������ʼ����Ϸ�Ĳ�������ʵ��������Ϸ����
////////////////////////////////////////////
class Game
{
public:

	void Init()
	{
		closegraph();
		initgraph(800, 600);
		setbkmode(TRANSPARENT);					//����������ֱ���Ϊ͸��
		LOGFONT f;
		//getfont(&f);							// ��ȡ��ǰ��������
		f.lfHeight = 50;						// ��������߶�Ϊ 48�������оࣩ
		_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
		f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
		//setfont(&f);							// ����������ʽ
	}
	void FailGame()  //��Ϸʧ����ʾ�Ļ���
	{
		setcolor(RED);
		//setfont(70, 0, _T("΢���ź�"));
		outtextxy(150, 265, _T("YOU LOSE!"));
	}
	void WinGame() //��Ϸʤ��ʱ��ʾ�Ļ���
	{
		setcolor(RED);
		//setfont(70, 0, _T("΢���ź�"));
		outtextxy(150, 265, _T("YOU WIN!"));
		FlushBatchDraw();
		Sleep(10000);
		exit(0);
	}
};
////////////////////////////////////////////
//�������࣬��������������ز���
////////////////////////////////////////////
class ManageArea
{
public:

	friend void MessageDispose();

	void TimeAdd(double add)	//����ʱ�䣨��������ֱ�ӵ���ʵ�ֶ�̬ˢ��ʱ�䣩
	{
		m_time += add;
		DisplayTime();
	}
	void ScoreAdd(short add)	//���ӷ�������������ֱ�ӵ���ʵ�ֶ�̬ˢ�·�����
	{
		m_score += add;
		DisplayScore();
	}
	void DisplayPause()			//��ʾ��ͣ���߿�ʼ
	{
		BeginBatchDraw();
		_stprintf(m_str_score, _T("%d"), m_score);
		//setfont(25, 0, _T("΢���ź�"));
		setfillstyle(m_bgcolor);
		bar(625, 490, 800, 515);
		setcolor(BLUE);
		if (m_pause)
			outtextxy(625, 490, _T("��ʼ��P����"));
		else
			outtextxy(625, 490, _T("��ͣ��P����"));
		EndBatchDraw();
	}
	void Init()  //��ʼ���������
	{
		m_time = 0.0;
		m_score = 0;
		m_leave = 1;
		m_pause = false;
		_stprintf(m_str_score, _T("%d"), m_score);  //��ʽ��ת������
		_stprintf(m_str_time, _T("%.1lf"), m_time);
		m_bgcolor = BLACK;
		BeginBatchDraw();
		setfillstyle(BLACK);
		bar(601, 0, 800, 600);
		//setfont(60, 0, _T("΢���ź�"));
		setcolor(GREEN);
		outtextxy(625, 30, _T("̰����"));
		//setfont(30, 0, _T("΢���ź�"));
		setcolor(RGB(128, 0, 255));
		outtextxy(625, 140, _T("��������������"));
		//setfont(25, 0, _T("΢���ź�"));
		setcolor(BLUE);
		outtextxy(625, 430, _T("ʱ�䣺"));
		outtextxy(625, 460, _T("������"));
		outtextxy(625, 490, _T("��ͣ��P����"));
		outtextxy(625, 520, _T("������Ϸ��R����"));
		setcolor(RED);
		outtextxy(720, 400, m_str_leave);
		outtextxy(680, 460, m_str_score);
		outtextxy(680, 430, m_str_time);
		EndBatchDraw();
	}

private:

	double	m_time;
	short	m_score;
	short	m_leave;
	bool	m_pause;
	TCHAR	m_str_leave[2], m_str_time[33], m_str_score[5];
	COLORREF m_bgcolor;

	void DisplayTime()  //��ʾ��ǰ��ʱ
	{
		BeginBatchDraw();
		_stprintf(m_str_time, _T("%.1lf"), m_time);
		//setfont(25, 0, _T("΢���ź�"));
		setfillstyle(m_bgcolor);
		bar(680, 430, 800, 455);
		setcolor(RED);
		outtextxy(680, 430, m_str_time);
		EndBatchDraw();
	}
	void DisplayScore()  //��ʾ��ǰ����
	{
		BeginBatchDraw();
		_stprintf(m_str_score, _T("%d"), m_score);
		//setfont(25, 0, _T("΢���ź�"));
		setfillstyle(m_bgcolor);
		bar(680, 460, 800, 485);
		setcolor(RED);
		outtextxy(680, 460, m_str_score);
		EndBatchDraw();
	}
};


////////////////////////////////////////////
//������Ϸ��Ҫ����
////////////////////////////////////////////

Game		game;		//���ڳ�ʼ����Ϸ��������Ϸ��ز���
GameArea	a;			//���ڳ�ʼ����Ϸ�������ã��ı���Ϸ������ز���
ManageArea	manager;	//���ڳ�ʼ�������������ù�������ز���
Snake		s;			//���ڳ�ʼ���ߣ����ݻ��ߣ�������

						////////////////////////////////////////////
						//��Ϸ����Ϣ���ƣ����̿��ƺ���
						////////////////////////////////////////////
void MessageDispose()  //��Ϣ������
{
	char c;
	s.now = NULL;
	bool Keepdown = false;

	while (true)
	{
		Keepdown = false;  //�Ƿ������W A S D �е�һ������
		if (_kbhit())
		{
			switch (c = _getch())  //��������Ϣ��W A S D��
			{
			case 'w':
			case 'W':
				if (s.toward == UP)Keepdown = true;
				else if (s.toward != DOWN&&s.toward != UP)s.toward = UP;
				break;
			case 's':
			case 'S':
				if (s.toward == DOWN)Keepdown = true;
				else if (s.toward != UP&&s.toward != DOWN)s.toward = DOWN;
				break;
			case 'a':
			case 'A':
				if (s.toward == LEFT)Keepdown = true;
				else if (s.toward != RIGHT&&s.toward != LEFT)s.toward = LEFT;
				break;
			case 'd':
			case 'D':
				if (s.toward == RIGHT)Keepdown = true;
				else if (s.toward != LEFT&&s.toward != RIGHT)s.toward = RIGHT;
				break;
			case 'p':
			case 'P':
				manager.m_pause = !manager.m_pause;	//������ͣ��ʼ
				manager.DisplayPause();	//��ʾ��ͣ��ʼ
				break;
			case 'r':
			case 'R':
				ReInit();
				break;
			}
		}
		if (true == manager.m_pause)	//�����ͣ��ֱ�ӽ����´�ѭ��
		{
			continue;
		}
		BeginBatchDraw();
		switch (a.m_game[s.head->m_x / 10][s.head->m_y / 10].ReturnFull())	//�����ͷ���������
		{
		case 2:				//����ʳ�����ӳ�
			a.ChangeColor(s.head->m_x / 10, s.head->m_y / 10, BLUE);
			s.SnakeAdd();	//������
			a.ChangeColor(s.head->m_x / 10, s.head->m_y / 10, BLUE);
			a.DelFood();	//ɾ��ʳ��
			if (a.CreatFood() == false)	//������ʳ��,������Ƿ�ͨ��
			{
				game.WinGame();			//��Ϸͨ�أ�����ͼû�ط�����ʳ��ʱ��
			}
			manager.ScoreAdd(1);		//��һ��
			break;
		case 0:
			a.m_game[s.last->m_x / 10][s.last->m_y / 10].setfull(0);				//������β���������ϰ�
			a.ChangeColor(s.last->m_x / 10, s.last->m_y / 10, BLACK);
			s.SnakeMove();  //���ƶ�һ��
			a.ChangeColor(s.head->m_x / 10, s.head->m_y / 10, BLUE);
			a.m_game[s.head->next->m_x / 10][s.head->next->m_y / 10].setfull(1);	//������ͷ���������ϰ�
			break;
		case 1:				//�����ϰ���
			game.FailGame();
			a.ChangeColor(s.head->m_x / 10, s.head->m_y / 10, RGB(255, 127, 39));
			FlushBatchDraw();
			{
				char c = ' ';
				while (c != 'r' && c != 'R')  //����Ϸʧ��ʱ����R�������½�����Ϸ
				{
					if (_kbhit())
					{
						c = _getch();
					}
					Sleep(10);
				}
			}
			ReInit(); //���¿�ʼ��Ϸ
			break;
		}
		EndBatchDraw();
		if (Keepdown == false)
		{
			Sleep(100);
			manager.TimeAdd(0.1);	//����ʱ��
		}
		else						//���������°������ʱ
		{
			Sleep(40);				//�ʵ����߿���������Ϸ������
			manager.TimeAdd(0.04);  //����ʱ��
		}
	}
}
////////////////////////////////////////////
//��Ϸ��ʼ������
////////////////////////////////////////////
void ReInit()
{
	a.Init(); //��ʼ����Ϸ��
	s.Init();  //��ʼ����
	manager.Init();  //��ʼ��������
					 //�����ߵĿ�ʼ״̬
	s.now = s.head;
	a.ChangeColor(s.now->m_x / 10, s.now->m_y / 10, BLUE);
	s.now = s.last;
	a.ChangeColor(s.now->m_x / 10, s.now->m_y / 10, BLUE);
}
////////////////////////////////////////////
//main�������������
////////////////////////////////////////////
int main(void)
{
	game.Init();		//��ʼ����Ϸ����������
	ReInit();			//��ʼ������
	MessageDispose();	//��Ϣ������

	return 0;
}