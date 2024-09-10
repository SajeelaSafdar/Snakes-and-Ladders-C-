#pragma once
#include"Board.h"
class Gamee
{
    int player1;
    int player2;
    Board board;
public:
    Gamee();
    int getP1() const;
    int getP2() const;
    int rollDice();
    void printDice(int num);
    int setPlayer(int n, int turn);
    void movePlayer(int turn, string name, string name2);
    void showMenu(int colors[]);
    void colorChoice(int& c1, int& c2, bool comp);
    void displayRules();
    void writePlayer(const string& p1, const string& p2);
    void readPlayer();
    void updatePlayer(const string& player, bool win);
    void printLoading(const string& str, int delay);
    void loadingScreen();
    void mainScreen();

};

