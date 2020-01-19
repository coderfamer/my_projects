#include <iostream>

using namespace std;

int main()
{
#ifdef _WIN32
    cout << "i'm win32" << endl;
#else
    cout << "I'm linux" << endl;
#endif


    return 0;
}