#include"Gamee.h"

#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <mmsystem.h>
#include <fstream>
#include <iostream>
using namespace std;
#pragma comment(lib, "winmm.lib")

void printPlayer(int n, string ch, bool dou); //global functions declarations
void printString(int n, string s);
void printVer(int n);
void printHor(int n);
void gotopos(int x, int y);
void printButton(string label, int n);
char correct(int n);
void color(int x);
void makeSleep(string s, int n);

int main()
{

    srand(time(NULL));

    Gamee obj;

    int colors[5] = { 15, 15, 15, 15,15 };
    char key = 0;
    int count = 1;
    obj.loadingScreen();

    bool comp = false;

    string p1;
    string p2;

    while (true)
    {
        system("cls");

        obj.showMenu(colors);

        key = _getch();

        if (key == 72 && count > 1)
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            count--;
        }
        else if (key == 80 && count < 5)
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            count++;
        }
        else if (key == '\r')
        {
            system("cls");
            color(15);
            if (count == 1)
            {
                gotopos(0, 0);
                color(14);
                obj.displayRules();
                color(15);
            }
            else if (count == 2)
            {
                obj.mainScreen();
                gotopos(0, 0);
                comp = false;
                color(14);
                cout << "Player1! Enter name: ";
                color(15);
                cin >> p1;
                color(14);
                cout << "Player2! Enter name: ";
                color(15);
                cin >> p2;
                obj.writePlayer(p1, p2); 
                obj.colorChoice(color1, color2, comp);
            }
            else if (count == 3)
            {
                obj.mainScreen();
                gotopos(0, 0);
                color(14);
                cout << "Player! Enter name: ";
                color(15);
                cin >> p1;
                p2 = "Computer";
                obj.writePlayer(p1, p2);
                color(14);
                cout << "You will play with Computer. Select color:";
                color(15);
                comp = true;
                color2 = 8;
                obj.colorChoice(color1, color2, comp);
            }
            else if (count == 4)
            {
                gotopos(0, 0);
                color(14);
                obj.readPlayer(); ////
                color(15);
            }
            else if (count == 5)
            {
                gotopos(0, 0);
                color(14);
                cout << "Game Exitted" << endl;
                exit(1);
            }
            if (color1 != -1 && color2 != -1)
                break;
            color(15);
            cout << "\nPress any key to return to the choices...";
            key = _getch();
        }

        for (int i = 0; i < 4; i++)
        {
            colors[i] = 15;
        }

        colors[count - 1] = 14;
    }

    string label = "Enter";

    system("cls");
    obj.mainScreen();
    obj.movePlayer(1, p1, p2);
    printButton(label, 14);
    bool enter = false;

    int i = 0;
    bool start1 = false;
    bool start2 = false;

    while (obj.getP1() <= 100 && obj.getP2() <= 100)
    {
        if (comp)
        {
            p2 = "Computer ";
            int current = i % 2 + 1;
            if (current == 2 && !start2)
            {
                int roll = obj.rollDice();
                if (roll != 6)
                {
                    obj.movePlayer(current, p1, p2);
                    makeSleep("Rolling", 14);
                    obj.printDice(roll);
                    cout << p2 << " got " << roll << endl;
                }
                if (roll == 6)
                {
                    if (current == 1)
                        start1 = true;
                    if (current == 2)
                        start2 = true;
                    obj.setPlayer(1, i % 2 + 1);
                    obj.movePlayer(current, p1, p2);
                    makeSleep("Rolling", 14);
                    obj.printDice(roll);

                    cout <<p2<< "got " << roll << endl;
                    cout << "Computer is at start now!" << endl;
                    printButton(label, 14);
                }
                else
                {
                    cout << "Computer needs a 6 to start" << endl;
                    printButton(label, 14);
                }

                i++;
            }
            else if (current == 2 && start2)
            {
                system("cls");
                if (current == 1)
                    obj.movePlayer(current, p1, p2);
                else {
                    obj.movePlayer(current, p1, p2);
                }
                int roll = obj.rollDice();
                makeSleep("Rolling", 14);
                obj.printDice(roll);
                cout << p2 << "got " << roll << endl;
                printString(14, "Moving");
                Sleep(350);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                cout << endl;
                char check = '\0';
                check = obj.setPlayer(roll, current);
                obj.movePlayer(current, p1, p2);
                printButton(label, 14);

                if (check == 5)
                {
                    string s = "Position cannot be more than 100";
                    Beep(500, 800);
                    cin.get();
                    printString(4, s);
                    cout << endl;
                }
                else if (check == 4) ////
                {
                    string s = "Congratulations! ";
                    
                    obj.updatePlayer(p1, true);
                    PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cin.get();
                    printString(10, s);
                    cout << p1 << endl;
                    break;
                }
                else if (check == 3) ////
                {
                    string s = "Hehe! you lost against the power of computer";
                    obj.updatePlayer(p1, false);
                    PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cin.get();
                    printString(10, s);
                    cout << endl;
                    break;
                }
                else if (check == 1)
                {
                    string s = "Computer has climbed a ladder";
                    PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cin.get();
                    printString(10, s);
                    cout << endl;
                }
                else if (check == 2)
                {
                    string s = "Computer has been caught by a snake";
                    PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cin.get();
                    printString(4, s);
                    cout << endl;
                }
                i++;
            }
        }

        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            if (!enter)
            {
                int current = i % 2 + 1;
                if ((current == 1 && !start1) || (current == 2 && !start2))
                {
                    int roll = obj.rollDice();
                    if (roll != 6 && current==1)
                    {
                        obj.movePlayer(current, p1, p2);
                        makeSleep("Rolling", 14);
                        obj.printDice(roll);
                        cout << p1 << " got " << roll << endl;
                    }
                    if (roll != 6 && current == 2)
                    {
                        obj.movePlayer(current, p1, p2);
                        makeSleep("Rolling", 14);
                        obj.printDice(roll);
                        cout << p2 << " got " << roll << endl;
                    }
                    if (roll == 6)
                    {
                        if (current == 1)
                            start1 = true;
                        if (current == 2)
                            start2 = true;
                        obj.setPlayer(1, i % 2 + 1);
                        if (current == 1)
                            obj.movePlayer(current, p1, p2);
                        else {
                            obj.movePlayer(current, p1, p2);
                        }
                        makeSleep("Rolling", 14);
                        obj.printDice(roll);
                        if(current==1)
                        cout << p1 << " got " << roll << endl;
                        else {
                            cout << p2 << " got " << roll << endl;
                        }
                        cout << "You are at start now!" << endl;
                        printButton(label, 14);
                    }
                    else
                    {
                        cout << "You need a 6 to start" << endl;
                        printButton(label, 14);
                    }

                    i++;
                }
                else if ((current == 1 && start1) || (current == 2 && start2))
                {
                    system("cls");
                    if (current == 1)
                        obj.movePlayer(current, p1, p2);
                    else {
                        obj.movePlayer(current, p1, p2);
                    }
                    int roll = obj.rollDice();
                    makeSleep("Rolling", 14);
                    obj.printDice(roll);
                    if(current==1)
                    cout <<p1 << " got " << roll << endl;
                    else {
                        cout << p2 << " got " << roll << endl;
                    }
                    printString(14, "Moving");
                    Sleep(350);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    Sleep(300);
                    cout << ".";
                    cout << endl;
                    char check = '\0';
                    check = obj.setPlayer(roll, current);
                    if (current == 1)
                        obj.movePlayer(current, p1, p2);
                    else {
                        obj.movePlayer(current, p1, p2);
                    }
                    printButton(label, 14);

                    if (check == 5)
                    {
                        string s = "Position cannot be more than 100";
                        Beep(500, 800);
                        cin.get();
                        printString(4, s);
                        cout << endl;
                    }
                    else if (check == 4) ////
                    {
                        string s = "Congratulations! ";
                        
                        obj.updatePlayer(p1, true);
                        obj.updatePlayer(p2, false);
                        PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_SYNC);
                        cin.get();
                        printString(10, s);
                        cout << p1 << endl;
                        break;
                    }
                    else if (check == 3) ////
                    {
                        string s = "Congratulations! ";
                        
                        obj.updatePlayer(p2, true);
                        obj.updatePlayer(p1, false);
                        PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_SYNC);
                        cin.get();
                        printString(10, s);
                        cout << p2 << endl;
                        break;
                    }
                    else if (check == 1)
                    {
                        string s = "Yay! you climbed a ladder";
                        PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_SYNC);
                        cin.get();
                        printString(10, s);
                        cout << endl;
                    }
                    else if (check == 2)
                    {
                        string s = "Oops! you've been caught by a snake";
                        PlaySound(TEXT("loose.wav"), NULL, SND_FILENAME | SND_SYNC);
                        
                        cin.get();
                        printString(4, s);
                        cout << endl;
                    }
                    i++;
                }
            }
            enter = true;
            if (comp)
            {
                gotopos(0, 38);
                printString(14, "Computer is thinking");
                Sleep(350);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
                Sleep(300);
                cout << ".";
            }
        }
        else
        {
            enter = false;
        }
    }

    return 0;
}
