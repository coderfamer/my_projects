

#include <iostream>
#include <conio.h>
#include <time.h>

#include "graphic.h"
#include "maintank.h"

int main()
{
	Graphic::create();

	MainTank mainTank;
	bool loop = true;
	bool skip = false;

	while(loop)
	{
		if (_kbhit())
		{
			int key = _getch();

			switch (key)
			{
			case 72:
				mainTank.set_dir(Dir::UP);
				break;
			case 80:
				mainTank.set_dir(Dir::DOWN);
				break;
			case 75:
				mainTank.set_dir(Dir::LEFT);
				break;;
			case 77:
				mainTank.set_dir(Dir::RIGHT);
				break;
			case 224:
				break;
			case 27:
				loop = false;
				break;
			case 32:
				break;
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			cleardevice();
			mainTank.move();
			mainTank.display();
		}

	}

	
	Graphic::destory();

	return 0;
}