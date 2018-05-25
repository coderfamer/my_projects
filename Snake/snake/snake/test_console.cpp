#include <iostream>
#include <windows.h>
#include <wincon.h>

using std::cout;
using std::endl;

int main_test_console()
{
	SetConsoleTitle("Snake");


	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);

	cout << "console window size = " << bInfo.dwSize.X << " , " << bInfo.dwSize.Y << endl;
	cout << "window coordinate position = " << bInfo.srWindow.Left << ", " << bInfo.srWindow.Right << ", "
		<< bInfo.srWindow.Top << ", " << bInfo.srWindow.Bottom << endl;


	SMALL_RECT rc = {0, 0, 79, 24};
	SetConsoleWindowInfo(hOutput, true, &rc);
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	cout << "window coordinate position = " << bInfo.srWindow.Left << ", " << bInfo.srWindow.Right << ", "
		<< bInfo.srWindow.Top << ", " << bInfo.srWindow.Bottom << endl;

	COORD dwSize = {80, 200};
	SetConsoleScreenBufferSize(hOutput, dwSize);
	cout << "console window size = " << bInfo.dwSize.X << " , " << bInfo.dwSize.Y << endl;

	CloseHandle(hOutput);

	return 0;
}