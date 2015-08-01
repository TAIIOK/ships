#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
#include <game.h>

/*!
 * \brief GetRandomCoords - Функция получения рандомных координат
 * \param x - x координата
 * \param y - y координата
 */
void GetRandomCoords(int &x, int &y);
/*!
 * \brief ComputerMove - Функция хода компьютера
 * \param x - x координата
 * \param y - y координата
 */
bool ComputerMove(int x,int y);


#endif  COMPUTER_H
