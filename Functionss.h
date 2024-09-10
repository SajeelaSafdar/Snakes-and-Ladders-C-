#pragma once
#include<string>
#include<iostream>
#include<windows.h>
using namespace std;

class Functionss {
public:
    friend void printPlayer(int n, string ch, bool dou);
    friend void printString(int n, string s);
    friend void printVer(int n);
    friend void printHor(int n);
    friend void gotopos(int x, int y);
    friend void printButton(string label, int n);
    friend char correct(int n);
    friend void color(int x);
    friend void makeSleep(string s, int n);
};

