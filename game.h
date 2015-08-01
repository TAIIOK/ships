#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <ctime>
#include "QTime"

#include "board.h"
#include "computer.h"

using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;
const int SHIP_TYPES = 5;

const char WATER= 'W';
const char HIT = 'X';
const char SHIPS = 'S';
const char MISS = '0';

int gametype;
int computerdificult;
int gameRunning;
int currentPlayer;
int aWin;

bool goodInput = false;
int x,y;

enum DIRECTION {HORIZONTAL,VERTICAL};

struct center {
    int X;
    int Y;
};

struct SHIP {
    string name;
    int length;
    center onGrid[5];
    bool hitFlag[5];
}ship[SHIP_TYPES];

struct PLAYER {
    char grid[BOARD_WIDTH][BOARD_HEIGHT];
}player[3];

struct PLACESHIPS {
    DIRECTION direction;
    SHIP shipType;
};






int GameOverCheck(int enemyPLAYER);
bool startgame();

#endif // GAME_H
