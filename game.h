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

const int BOARD_WIDTH = 10;//ширина поля
const int BOARD_HEIGHT = 10;//высота поля
const int SHIP_TYPES = 5;//количество кораблей

const char WATER= 'W';//символ воды
const char HIT = 'X';//символ попадания
const char SHIPS = 'S';//символ корабля
const char MISS = '0';//символ промоха

//Пречисление ориентаций горизонтальная и вертикальная
enum DIRECTION {HORIZONTAL,VERTICAL};

//Структура игровых данных
struct game{
public:
    int GameType; //переменная для хранения режима игры
    int ComputerDificult; //значение уровня сложности Искуственного интелекта
    int GameRunning;//переменная статуса игры
    int CurrentPlayer;//переменная указывающая на текущего игрока
    int Win;//Переменная для контроля завершения игры
    int Players;//Игроки
    bool GoodInput = false;//Флаг правильного ввода координат
    int x,y;//координаты

};
//Структура игрового поля
struct gameboard{
public:
    //структура для растановки кораблей
    struct center {
        int X;
        int Y;

    };
    //структура коробля его характеристики
    struct SHIP {
        string name;
        int length;
        center onGrid[5];
        bool hitFlag[5];
    }ship[SHIP_TYPES];

    //игороки
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

/*!
 * \brief PlaceShips - Расстановка кораблей
 * \param gametype - тип игры(для расстановки 2 пользователя или ИИ)
 */
void PlaceShips(int gametype);
/*!
 * \brief DrawBoard - Нарисовать поле в консоле
 * \param thisPlayer - Игрок сделавший ход
 */
void DrawBoard(int thisPlayer);
/*!
 * \brief ResetBoard - Очиста поля для игры
 */
void ResetBoard();
/*!
 * \brief AddShips - Инициализация короблей
 */
void AddShips();

/*!
 * \brief GameOverChec - Функция проверки конца игры
 * \param enemyPLAYER - Противник
 * \return - победитель
 */
int GameOverCheck(int enemyPLAYER);
/*!
 * \brief StartGame - Функция запуска игры
 * \return - Завершена ли игра
 */
bool StartGame();
/*!
 * \brief UserInputAttack - Функция ввода координат пользователя для хода
 * \param x - x координата
 * \param y - y координата
 * \param currentplayer - игрок делающий ход
 * \return - Верно ли введены координаты
 */
bool UserInputAttack(int& x, int& y, int currentplayer);
/*!
 * \brief UserInputAttack - Функция для расстановки кораблей пользователя
 * \param thisShip - текущий корабль (тип корабля)
 * \param playernumber - номер игрока
 * \return - текущие положение коробля
 */
gameboard::PLACESHIPS UserInputShipPlacement(int thisShip, int playernumber);

#endif  GAME_H

