#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <ctime>
#include "QTime"
#include <computer.h>
#include <checkcoords.h>
using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;
const int SHIP_TYPES = 5;

const char WATER= 'W';
const char HIT = 'X';
const char SHIPS = 'S';
const char MISS = '0';

enum DIRECTION {HORIZONTAL,VERTICAL};

struct game{
public:
    int gametype;
    int computerdificult;
    int gameRunning;
    int currentPlayer;
    int aWin;
    int players;
    bool goodInput = false;
    int x,y;

};

struct gameboard{
public:
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
};

extern game newgame;
extern gameboard newboard;

void PlaceShips(int gametype);
void DrawBoard(int thisPlayer);
void ResetBoard();
void AddShips();
void GetRandomCoords(int &x, int &y);

int GameOverCheck(int enemyPLAYER);
bool StartGame();
bool UserInputAttack(int& x, int& y, int theplayer);

gameboard::PLACESHIPS UserInputShipPlacement(int thisShip, int playernumber);
#endif  GAME_H

