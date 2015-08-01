#pragma once
#ifndef CHECKCOORDS_H
#define CHECKCOORDS_H
#include <game.h>
/*!
 * \brief CheckPosition - Функция проверки возможности постановки корабля
 * \param currentplayer - текущий игрок
 * \param x - x координата
 * \param y - y координата
 * \return - True возможно поставить , False не возможно
 */
bool CheckPosition(int currentplayer,int x,int y);
/*!
 * \brief CheckAroundCell - Функция проверки есть ли корабль вокруг клеткии установка на него коордит
 * \param x - x координата
 * \param y - y координата
 * \return - True замена координат проведена на корабль , False координаты остались без изменения
 */
bool CheckAroundCell(int &x ,int &y);

#endif  CHECKCOORDS_H


