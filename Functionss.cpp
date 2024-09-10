#include"Functionss.h"
void printPlayer(int n, string ch, bool duo)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, n);
    cout << ch;
    if (duo == false)
        cout << " ";
    SetConsoleTextAttribute(h, 15);
}

void printString(int n, string s)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, n);
    cout << s;
    SetConsoleTextAttribute(h, 15);
}

void printVer(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, n);
    cout << "|";
    SetConsoleTextAttribute(h, 15);
}

void printHor(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, n);
    cout << "____";
    SetConsoleTextAttribute(h, 15);
}
void gotopos(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

void printButton(string label, int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, n);
    gotopos(60, 32);
    cout << "_______" << endl;
    gotopos(60, 33);
    cout << "|";
    gotopos(61, 33);
    cout << label;
    gotopos(66, 33);
    cout << "|" << endl;
    gotopos(60, 34);
    cout << "-------" << endl;
    gotopos(60, 35);
    SetConsoleTextAttribute(h, 15);
    gotopos(60, 36);
}

char correct(int n)
{
    int red[] = { 61, 60, 41, 40, 21, 20, 1, 59, 42, 39, 22, 19, 2, 25, 16, 5, 15, 6, 71, 70, 51, 85, 76, 65, 95, 86, 75, 66 };
    for (int i = 0; i < 28; i++)
    {
        if (n == red[i])
            return 'r';
    }
    int green[] = { 29, 12, 9, 30, 11, 10, 43, 38, 23, 44, 37, 24, 94, 87, 74, 67, 54, 93, 88, 73, 68, 53, 82, 83, 84, 77, 78, 63, 64 };
    for (int i = 0; i < 29; i++)
    {
        if (n == green[i])
            return 'g';
    }
    return 'x';
}

void color(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void makeSleep(string s, int n)
{
    printString(n, s);
    Sleep(350);
    cout << ".";
    Sleep(200);
    cout << ".";
    Sleep(200);
    cout << ".";
    Sleep(200);
    cout << ".";
    cout << endl;
}
