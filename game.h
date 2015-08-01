#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <ctime>
#include "QTime"



using namespace std;

 const int BOARD_WIDTH = 10;
 const int BOARD_HEIGHT = 10;
 const int SHIP_TYPES = 5;

 const char WATER= 'W';
 const char HIT = 'X';
 const char SHIPS = 'S';
 const char MISS = '0';

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


 int gametype;
  int computerdificult;
  int gameRunning;
  int currentPlayer;
 int aWin;
 int players;

 bool goodInput = false;
 int x,y;

int GameOverCheck(int enemyPLAYER);
bool startgame();
bool UserInputAttack(int& x, int& y, int theplayer);

PLACESHIPS UserInputShipPlacement(int thisShip, int playernumber);

#endif  GAME_H

