#include"Board.h"

void printPlayer(int n, string ch, bool dou);
void printString(int n, string s);
void printVer(int n);
void printHor(int n);
void gotopos(int x, int y);
void printButton(string label, int n);
char correct(int n);
void color(int x);
void makeSleep(string s, int n);
int color1 = -1; int color2 = -1;
Board::Board()
{
    rows = 10;
    cols = 10;
    arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
}

Board::~Board()
{
    if (arr != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
    }
}

void Board::makeBoard()
{
    int k = 100;
    for (int i = 0; i < rows; i++)
    {
        int odd = -9;
        for (int j = 0; j < cols; j++)
        {
            if (i % 2 != 0)
            {
                arr[i][j] = k + odd;
                odd = odd + 2;
            }
            else
            {
                arr[i][j] = k;
            }
            k--;
        }
    }
}

void Board::displayBoard(int n1, int n2, string name, string name2)
{
    system("cls");
    color(10);
    char c = 248;
    cout << "                 __      __    __     __" << endl;
    cout << "               /    \\  /   \\  /   \\  /   \\ " << endl;
    cout << "______________/   ___\\/  ___\\/  ___\\/  ___\\_____________________________________" << endl;
    cout << "_____________/   /___/  /___/  /___/  /_________________________________________" << endl;
    cout << "            |   / \\    / \\    / \\ /   \\  \\_____";
    color(6);
    cout << "\t\t ____________________" << endl;
    color(10);
    cout << "             \\ |/  \\_/    \\_/    \\_/   \\_____" << c << "_)--<";
    color(6);
    cout << "\t| _________________  |" << endl;
    color(6);

    cout << "\t\t\t\t\t\t\t| |                | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                | |" << endl;
    cout << "\t\t\t\t\t\t\t| |                / \\" << endl;
    cout << "\t\t\t\t\t\t\t| |______________  \\" << c << "/" << endl;
    cout << "\t\t\t\t\t\t\t|________________)-- " << endl;
    color(15);
    gotopos(59, 7);
    cout << name << "  " << n1 << endl;
    gotopos(59, 8);
    cout << name2 << "  " << n2 << endl;
    for (int i = 0; i < 10; i++)
    {
        if (i >= 3 && i <= 4)
        {
            cout << " ";
            printHor(4);
        }
        else if (i >= 5 && i <= 6)
        {
            cout << " ";
            printHor(10);
        }
        else
        {
            cout << " ";
            printHor(15);
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == n1 && arr[i][j] == n2)
            {
                if (correct(n1) == 'r')
                    printVer(4);
                else if (correct(n1) == 'g')
                    printVer(10);
                else
                    printVer(15);
                printPlayer(color1, "P1", true);
                printPlayer(color2, "P2", true);
            }
            else if (arr[i][j] == n1)
            {
                if (correct(n1) == 'r')
                    printVer(4);
                else if (correct(n1) == 'g')
                    printVer(10);
                else
                    printVer(15);
                cout << " ";
                printPlayer(color1, "P1", false);
            }
            else if (arr[i][j] == n2)
            {
                if (correct(n2) == 'r')
                    printVer(4);
                else if (correct(n2) == 'g')
                    printVer(10);
                else
                    printVer(15);
                cout << " ";
                printPlayer(color2, "P2", false);
            }
            else if (arr[i][j] == 100)
            {
                printVer(15);
                cout << " ";
                cout << arr[i][j] << "";
            }
            else if (arr[i][j] < 10)
            {
                if (i == 9 && (j == 0 || j == 1 || j == 4 || j == 5)) // bcz numbers are less than 10, do it separately
                    printVer(4);
                else if (i == 9 && j == 8)
                    printVer(10);
                else
                    printVer(15);
                cout << " ";
                cout << arr[i][j] << "  ";
            }
            else
            {
                if (i > 2 && j == 0) // 1st snake ver begins
                    printVer(4);
                else if (i > 3 && j == 1)
                    printVer(4);
                else if (i > 6 && j == 4) // 2nd snake ver begins
                    printVer(4);
                else if (i > 7 && j == 5)
                    printVer(4);
                else if (i >= 1 && i <= 3 && j == 4) // 3rd snake ver begins
                    printVer(4);
                else if (i <= 3 && j == 5)
                    printVer(4);
                else if (i > 1 && i <= 4 && j == 9) // 4th snake ver begins
                    printVer(4);
                else if (i <= 4 && (j == 6 || j == 7)) // top right ladder verticle
                    printVer(10);
                else if (i >= 7 && i <= 9 && (j == 8 || j == 9)) // bottom right ladder
                    printVer(10);
                else if (i >= 5 && i <= 7 && (j == 2 || j == 3)) // bottom left ladder
                    printVer(10);
                else if (i == 1 && j >= 1 && j <= 3) // top left ladder
                    printVer(10);
                else if ((i == 2 || i == 3) && (j == 2 || j == 3))
                    printVer(10);
                else
                    printVer(15);
                cout << " ";
                cout << arr[i][j] << " ";
            }
        }
        if (i > 1 && i < 6)
            printVer(4);
        else
            printVer(15); // number row verticle last
        cout << " ";
        cout << endl;
        for (int k = 0; k < 10; k++)
        {
            if (i > 0 && i < 4 && k == 4)
                printVer(4);
            else if (i >= 0 && i < 4 && k == 5)
                printVer(4);
            else if (i >= 3 && k == 0)
                printVer(4);
            else if (i > 3 && k == 1)
                printVer(4);
            else if (i > 6 && k == 4)
                printVer(4);
            else if (i > 7 && k == 5)
                printVer(4);
            else if (i > 1 && i < 5 && k == 9)
                printVer(4);
            else if (i <= 4 && (k == 6 || k == 7))
                printVer(10);
            else if (i >= 7 && (k == 8 || k == 9))
                printVer(10);
            else if (i >= 5 && i <= 7 && (k == 2 || k == 3))
                printVer(10);
            else if (i == 1 && k >= 1 && k <= 3)
                printVer(10);
            else if ((i == 2 || i == 3) && (k == 2 || k == 3))
                printVer(10);
            else
                printVer(15); // empty row verticle

            if (i == 0 && k >= 5 && k <= 6)
                printHor(10);
            else if (i >= 1 && i <= 3 && k == 6)
                printHor(10);
            else if (i == 0 && k == 3)
                printHor(4);
            else if (i == 2 && (k == 0 || k == 1))
                printHor(4);
            else if (i == 3 && k == 1)
                printHor(4);
            else if (i == 4 && k >= 7 && k <= 8)
                printHor(4);
            else if (i == 5 && k >= 7 && k <= 9)
                printHor(4);
            else if (i == 6 && k >= 4 && k <= 5)
                printHor(4);
            else if (i == 7 && k == 5)
                printHor(4);
            else if ((i == 6 || i == 7) && (k == 7 || k == 8))
                printHor(10);
            else if (i == 8 && k == 8)
                printHor(10);
            else if ((i == 5 || i == 6) && (k == 2))
                printHor(10);
            else if (i == 0 && k >= 0 && k <= 2)
                printHor(10);
            else if (i == 1 && k <= 2)
                printHor(10);
            else if (i == 2 && k == 2)
                printHor(10);
            else
                printHor(15);
        }
        if (i > 1 && i < 6)
            printVer(4);
        else
            printVer(15); // empty row verticle last col
        cout << endl;
    }
}