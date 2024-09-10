#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <mmsystem.h>
#include <fstream>
#include <iostream>


#include "Gamee.h"
#pragma comment(lib, "winmm.lib")

void printPlayer(int n, string ch, bool dou);
void printString(int n, string s);
void printVer(int n);
void printHor(int n);
void gotopos(int x, int y);
void printButton(string label, int n);
char correct(int n);
void color(int x);
void makeSleep(string s, int n);

Gamee::Gamee()
{
    player1 = 0;
    player2 = 0;
    board.makeBoard();
}

int Gamee::getP1() const
{
    return player1;
}

int Gamee::getP2() const
{
    return player2;
}

int Gamee::rollDice()
{
    return rand() % 6 + 1;
}

void Gamee::printDice(int num)
{
    char c = 248;
    switch (num)
    {
    case 1:
    {
        cout << "_____" << endl;
        cout << "|   |" << endl;
        cout << "| " << c << " |" << endl;
        cout << "|   |" << endl;
        cout << "-----" << endl;
    }
    break;
    case 2:
        cout << "_____" << endl;
        cout << "|" << c << "  |" << endl;
        cout << "|   |" << endl;
        cout << "|  " << c << "|" << endl;
        cout << "-----" << endl;
        break;
    case 3:
        cout << "_____" << endl;
        cout << "|" << c << "  |" << endl;
        cout << "| " << c << " |" << endl;
        cout << "|  " << c << "|" << endl;
        cout << "-----" << endl;
        break;
    case 4:
        cout << "_____" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "|   |" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "-----" << endl;
        break;
    case 5:
        cout << "_____" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "| " << c << " |" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "-----" << endl;
        break;
    case 6:
        cout << "_____" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "|" << c << " " << c << "|" << endl;
        cout << "-----" << endl;
        break;
    }
}

void Gamee::movePlayer(int turn, string name, string name2)
{
    if (turn == 1)
    {
        board.displayBoard(player1, player2, name, name2);
    }
    else if (turn == 2)
    {
        board.displayBoard(player1, player2, name, name2);
    }
}

int Gamee::setPlayer(int n, int turn)
{
    char check = '\0';
    if (turn == 1)
    {
        if (player1 + n > 100)
        {
            check = 5;
        }
        else if (player1 + n == 100)
        {
            check = 4;
            player1 = 100;
        }
        else if (player1 + n == 9)
        {
            check = 1;
            player1 = 28;
        }
        else if (player1 + n == 23)
        {
            check = 1;
            player1 = 43;
        }
        else if (player1 + n == 26)
        {
            check = 2;
            player1 = 5;
        }
        else if (player1 + n == 54)
        {
            check = 1;
            player1 = 95;
        }
        else if (player1 + n == 62)
        {
            check = 2;
            player1 = 1;
        }
        else if (player1 + n == 63)
        {
            check = 1;
            player1 = 81;
        }
        else if (player1 + n == 97)
        {
            check = 2;
            player1 = 65;
        }
        else
            player1 = player1 + n;
    }
    else if (turn == 2)
    {
        if (player2 + n > 100)
        {
            check = 5;
        }
        else if (player2 + n == 100)
        {
            check = 3;
            player2 = 100;
        }
        else if (player2 + n == 9)
        {
            check = 1;
            player2 = 28;
        }
        else if (player2 + n == 23)
        {
            check = 1;
            player2 = 43;
        }
        else if (player2 + n == 26)
        {
            check = 2;
            player2 = 5;
        }
        else if (player2 + n == 54)
        {
            check = 1;
            player2 = 95;
        }
        else if (player2 + n == 62)
        {
            check = 2;
            player2 = 1;
        }
        else if (player2 + n == 63)
        {
            check = 1;
            player2 = 81;
        }
        else if (player2 + n == 97)
        {
            check = 2;
            player2 = 65;
        }
        else
            player2 = player2 + n;
    }
    return check;
}

void Gamee::showMenu(int colors[])
{
    color(6);
    gotopos(9, 4);
    char c = 248;
    cout << " ______________________________" << endl; gotopos(10, 5);
    cout << "| __________________________  |" << endl; gotopos(10, 6);
    cout << "| |                         | |" << endl; gotopos(10, 7);
    cout << "| |                         | |" << endl; gotopos(10, 8);
    cout << "| |                         | |" << endl; gotopos(10, 9);
    cout << "| |                         | |" << endl; gotopos(10, 10);
    cout << "| |                         / \\" << endl; gotopos(10, 11);
    cout << "| |_________________________\\" << c << "/" << endl; gotopos(10, 12);
    cout << "|___________________________)-- " << endl;
    color(15);
    gotopos(13, 6);
    color(colors[0]);
    cout << "1. Rules";

    gotopos(13, 7);
    color(colors[1]);
    cout << "2. 2-Player Game";

    gotopos(13, 8);
    color(colors[2]);
    cout << "3. Play Against Computer";

    gotopos(13, 9);
    color(colors[3]);
    cout << "4. Records";

    gotopos(13, 10);
    color(colors[4]);
    cout << "5. Exit";
}

void Gamee::colorChoice(int& c1, int& c2, bool comp)
{
    int colors[8] = { 15, 15, 15, 15, 15, 15, 15, 15 };
    int count = 1;
    char key = 0;
    int current = 1;
    while (true)
    {
        system("cls");

        if (comp == true)
        {
            printString(15, "You will play against computer");
            cout << endl;
            printString(14, "Player! ");
            printString(15, "Select color:");
        }
        else if (current == 1)
        {
            printString(15, "2-player game selected");
            cout << endl;
            printString(14, "Player 1! ");
            printString(15, "Select color:");
        }
        else if (current == 2)
        {
            printString(15, "2-player game selected");
            cout << endl;
            printString(14, "Player 2! ");
            printString(15, "Select color:");
        }
        char c = 248;
        color(6);
        gotopos(10, 4);
        cout << " _________________________" << endl; gotopos(10, 5);
        cout << "| _____________________  |" << endl; gotopos(10, 6);
        cout << "| |                    | |" << endl; gotopos(10, 7);
        cout << "| |                    | |" << endl; gotopos(10, 8);
        cout << "| |                    | |" << endl; gotopos(10, 9);
        cout << "| |                    | |" << endl; gotopos(10, 10);
        cout << "| |                    | |" << endl; gotopos(10, 11);
        cout << "| |                    | |" << endl; gotopos(10, 12);
        cout << "| |                    | |" << endl; gotopos(10, 13);
        cout << "| |                    / \\" << endl; gotopos(10, 14);
        cout << "| |___________________ \\" << c << "/" << endl; gotopos(10, 15);
        cout << "|_____________________)-- " << endl;
        color(15);
        gotopos(13, 6);
        color(colors[0]);
        cout << "1. Red";

        gotopos(13, 7);
        color(colors[1]);
        cout << "2. Green";

        gotopos(13, 8);
        color(colors[2]);
        cout << "3. Blue";

        gotopos(13, 9);
        color(colors[3]);
        cout << "4. Yellow";

        gotopos(13, 10);
        color(colors[4]);
        cout << "5. Cyan";

        gotopos(13, 11);
        color(colors[5]);
        cout << "6. Purple";

        gotopos(13, 12);
        color(colors[6]);
        cout << "7. Pink";

        gotopos(13, 13);
        color(colors[7]);
        cout << "8. Back";

        key = _getch();
        if (key == 72 && count > 1) // Arrow up
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            count--;
        }
        else if (key == 80 && count < 8) // Arrow down
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            count++;
        }
        else if (key == '\r') // Enter key
        {
            PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_SYNC);
            if (count == 8)
            {
                return; // Return to main menu
            }
            system("cls");
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 15);
            gotopos(1, 0);
            if (count == 1)
            {
                makeSleep("Selecting Red", 4);
                if (current == 1)
                    c1 = 4;
                else if (current == 2)
                    c2 = 4;
            }
            else if (count == 2)
            {
                makeSleep("Selecting Green", 10);
                if (current == 1)
                    c1 = 10;
                else if (current == 2)
                    c2 = 10;
            }
            else if (count == 3)
            {
                makeSleep("Selecting Blue", 1);
                if (current == 1)
                    c1 = 1;
                else if (current == 2)
                    c2 = 1;
            }
            else if (count == 4)
            {
                makeSleep("Selecting Yellow", 6);
                if (current == 1)
                    c1 = 6;
                else if (current == 2)
                    c2 = 6;
            }
            else if (count == 5)
            {
                makeSleep("Selecting Cyan", 3);
                if (current == 1)
                    c1 = 3;
                else if (current == 2)
                    c2 = 3;
            }
            else if (count == 6)
            {
                makeSleep("Selecting Purple", 5);
                if (current == 1)
                    c1 = 5;
                else if (current == 2)
                    c2 = 5;
            }
            else if (count == 7)
            {
                makeSleep("Selecting Pink", 13);
                if (current == 1)
                    c1 = 13;
                else if (current == 2)
                    c2 = 13;
            }
            if (comp == true)
                break;
            if (current == 2)
                break;

            current++;

            SetConsoleTextAttribute(h, 15);
            cout << "\nPress any key to return to the choices...";
            key = _getch();
        }

        for (int i = 0; i < 8; i++)
        {
            colors[i] = 15;
        }

        colors[count - 1] = 14;
    }
}

void Gamee::displayRules()
{
    cout << "-> The game consists of a board with 100 numbered squares, starting from 1 at the bottom left and ending at 100 at the top left." << endl
        << endl;
    cout << "-> The first player to roll a 6 can move their piece to square 1." << endl
        << endl;
    cout << "-> Players take turns to roll a single die and move their piece forward by the number of squares shown on the die." << endl
        << endl;
    cout << "-> If a player lands exactly on the bottom of a ladder, they move up to the square at the top of the ladder." << endl
        << endl;
    cout << "-> If a player lands exactly on the head of a snake, they must move down to the square at the snake's tail." << endl
        << endl;
    cout << "-> If a player rolls a number that would take them beyond square 100, they do not move and must wait for their next turn to try again." << endl
        << endl;
    cout << "-> The game continues until a player wins by landing exactly on square 100." << endl
        << endl;
    cout << "-> Both players can occupy the same square at the same time." << endl
        << endl;
}

void Gamee::writePlayer(const string& p1, const string& p2) ////
{
    ifstream in("players.txt");
    string content;
    string line;

    while (getline(in, line))
    {
        content = content + line + "\n";
    }
    in.close();

    ofstream out("players.txt", ios::app);
    if (!out)
    {
        cout << "File error" << endl;
        return;
    }

    if (content.find(p1 + "\n") == string::npos)
    {
        out << p1 << endl;
        out << 0 << endl;
        out << 0 << endl;
    }

    if (content.find(p2 + "\n") == string::npos)
    {
        out << p2 << endl;
        out << 0 << endl;
        out << 0 << endl;
    }
    out.close();
}

void Gamee::readPlayer() ////
{
    ifstream in("players.txt");
    if (!in)
    {
        cout << "File error" << endl;
        return;
    }

    string name;
    int w, l;

    int i = 0;
    while (in >> name >> w >> l)
    {
        cout << "Player " << i + 1 << ":" << endl;
        cout << "Name: " << name << endl
            << "Wins: " << w << endl
            << "Losses: " << l << endl
            << endl;
        i++;
    }

    in.close();
}

void Gamee::updatePlayer(const string& player, bool win) ////
{
    ifstream inFile("players.txt");
    if (!inFile)
    {
        cout << "File error" << endl;
        return;
    }

    string name;
    int w, l;
    ofstream outFile("temp.txt");
    bool playerFound = false;

    while (inFile >> name >> w >> l)
    {
        if (name == player)
        {
            if (win)
            {
                ++w;
            }
            else
            {
                ++l;
            }
            playerFound = true;
        }
        outFile << name << " " << w << " " << l << endl;
    }

    inFile.close();
    outFile.close();

    if (!playerFound)
    {
        cout << "Player not found" << endl;
        remove("temp.txt");
        return;
    }

    if (remove("players.txt") != 0)
    {
        cout << "Error deleting file" << endl;
        return;
    }

    if (rename("temp.txt", "players.txt") != 0)
    {
        cout << "Error renaming file" << endl;
        return;
    }
}

void Gamee::printLoading(const string& str, int del = 1)
{
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        cout << str[i];
        Sleep(del);
    }
    cout << endl;
}

void Gamee::loadingScreen()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("COLOR 0E");

    string lines[] = {
        "                __             _                               _     __           _     _               ",
        "               / _\\_ __   __ _| | _____  ___    __ _ _ __   __| |   / /  __ _  __| | __| | ___ _ __ ___ ",
        "               \\ \\| '_ \\ / _` | |/ / _ \\/ __|  / _` | '_ \\ / _` |  / /  / _` |/ _` |/ _` |/ _ \\ '__/ __|",
        "               _\\ \\ | | | (_| |   <  __/\\__ \\ | (_| | | | | (_| | / /__| (_| | (_| | (_| |  __/ |  \\__ \\",
        "               \\__/_| |_|\\__,_|_|\\_\\___||___/  \\__,_|_| |_|\\__,_| \\____/\\__,_|\\__,_|\\__,_|\\___|_|  |___/",
        "               " };

    for (int i = 0; i < 6; ++i)
    {

        printLoading(lines[i]);
    }

    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t              /   /    " << "\t      _oo   " << endl;
    cout << "\t\t\t\t             /___/     " << "\t  >--(_  \\ " << endl;
    cout << "\t\t\t\t            /   /      " << "\t      / _/  " << endl;
    cout << "\t\t\t\t           /___/       " << "\t     / /    " << endl;
    cout << "\t\t\t\t          /   /        " << "\t    / (     " << endl;
    cout << "\t\t\t\t         /___/         " << "\t   (   `-.  " << endl;
    cout << "\t\t\t\t        /   /          " << "\t    `--.._) " << endl;
    cout << "\t\t\t\t       /   /           " << endl;

    char d = 177;
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t";
    cout << "Loading......" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < 15; i++)
    {
        cout << d;
        if (i < 10)
            Sleep(450);
        if (i < 20 && i >= 10)
            Sleep(100);
        if (i > 20)
            Sleep(50);
    }

    system("cls");
}

void Gamee::mainScreen()
{
    char d = 177;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("COLOR 0E");

    cout << "                __             _                               _     __           _     _               " << endl;
    cout << "               / _\\_ __   __ _| | _____  ___    __ _ _ __   __| |   / /  __ _  __| | __| | ___ _ __ ___ " << endl;
    cout << "               \\ \\| '_ \\ / _` | |/ / _ \\/ __|  / _` | '_ \\ / _` |  / /  / _` |/ _` |/ _` |/ _ \\ '__/ __|" << endl;
    cout << "               _\\ \\ | | | (_| |   <  __/\\__ \\ | (_| | | | | (_| | / /__| (_| | (_| | (_| |  __/ |  \\__ \\" << endl;
    cout << "               \\__/_| |_|\\__,_|_|\\_\\___||___/  \\__,_|_| |_|\\__,_| \\____/\\__,_|\\__,_|\\__,_|\\___|_|  |___/" << endl;
    cout << "               ";
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t              /   /    " << "\t      _oo   " << endl;
    cout << "\t\t\t\t             /___/     " << "\t  >--(_  \\ " << endl;
    cout << "\t\t\t\t            /   /      " << "\t      / _/  " << endl;
    cout << "\t\t\t\t           /___/       " << "\t     / /    " << endl;
    cout << "\t\t\t\t          /   /        " << "\t    / (     " << endl;
    cout << "\t\t\t\t         /___/         " << "\t   (   `-.  " << endl;
    cout << "\t\t\t\t        /   /          " << "\t    `--.._) " << endl;
    cout << "\t\t\t\t       /   /           " << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t";
    cout << "Loading......" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < 15; i++)
    {
        cout << d;
        if (i < 10)
            Sleep(150);
        if (i < 20 && i >= 10)
            Sleep(100);
        if (i > 20)
            Sleep(50);
    }

    system("cls");
}



