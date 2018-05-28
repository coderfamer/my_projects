#include <iostream>
#include <windows.h>
#include <wincon.h>

using std::cout;
using std::endl;

int main_attribute()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD wr1 = 0xfc;
	SetConsoleTextAttribute(hOut, 244);
	cout << "Hello world!!!!!!!!!" << endl;

	SetConsoleTextAttribute(hOut, 181);
	cout << "Hello world!!!!!!!!!" << endl;

	SetConsoleTextAttribute(hOut, 207);
	cout << "111111111111111111111111111111" << endl;
	cout << "222222222222222222222222222222" << endl;
	cout << "333333333333333333333333333333" << endl;
	cout << "444444444444444444444444444444" << endl;

	SMALL_RECT cutScr = {1, 2, 10, 5};
	SMALL_RECT PasScr = {7, 3, 11, 9};
	COORD pos = {1, 7};

	SetConsoleTextAttribute(hOut, 246);
	CONSOLE_SCREEN_BUFFER_INFO intSrc;
	GetConsoleScreenBufferInfo(hOut, &intSrc);
	CHAR_INFO chFill = {'A', intSrc.wAttributes};
	ScrollConsoleScreenBuffer(hOut, &cutScr, &PasScr, pos, &chFill);

	return 0;
}