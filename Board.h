#pragma once
#include<windows.h>
#include"Functionss.h"
using namespace std;
extern int color1;  
extern int color2;
class Board {

private:
    int rows;
    int cols;
    int** arr;
public:
    
    Board();
    ~Board();
    void makeBoard();
    void displayBoard(int, int, string, string);

};
