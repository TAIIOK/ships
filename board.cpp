#include "board.h"

void addShips()
{
    ship[0].name = "Cruiser";
    ship[0].length = 2;
    ship[1].name = "Frigate";
    ship[1].length = 3;
    ship[2].name = "Submarine";
    ship[2].length = 3;
    ship[3].name = "Escort";
    ship[3].length = 4;
    ship[4].name = "Battleship";
    ship[4].length = 5;
}

void ResetBoard()
{
    for (int plyr=1; plyr<3; ++plyr)
    {
        for (int w=0; w<BOARD_WIDTH; ++w)
        {
            for (int h=0; h<BOARD_HEIGHT; ++h)
            {
                player[plyr].grid[w][h] = WATER;
            }
        }
    }
}

void DrawBoard(int thisPlayer)
{
    bool flag=true;

    cout << "PLAYER " << "1" << "'s GAME BOARD";
    if(thisPlayer == 1)
    {
        cout << "                                    COPUTER's GAME BOARD\n";
        thisPlayer= 2;
    }
    else
        cout << "                                   PLAYER " << thisPlayer << "'s GAME BOARD\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "   ";
    for(int loop=0;loop<2;loop++)
    {
        for (int w=0; w<BOARD_WIDTH; ++w)
        {
            if (w < 10)
                cout << w << "  ";

            else if (w >= 10)
                cout << w << " ";
        }
        if(flag)
        {
            cout<<"      |         ";
            flag=false;
        }
    }
    cout << "\n";

    for (int h=0; h<BOARD_HEIGHT; ++h)
    {
        for (int w=0; w<BOARD_WIDTH; ++w)
        {
            if (w==0)
                cout << h << " ";

            if (w<10 && w==0)
                cout << " ";

            if (gameRunning == false && players==1)
            {
                cout << player[1].grid[w][h] << "  ";
            }
            else if (players==2 && gameRunning == false)
                cout << WATER<< "  ";

            if (gameRunning == true && player[1].grid[w][h] != SHIPS)
                cout << player[1].grid[w][h] << "  ";

            else if(gameRunning == true && player[1].grid[w][h] == SHIPS && gametype==1)
                cout << player[1].grid[w][h] << "  ";

            else if (gameRunning == true && player[1].grid[w][h] == SHIPS && gametype==2)
                cout << WATER<< "  ";

            if (w == BOARD_WIDTH-1)
            {
                cout<<"      |      ";
                for (int w=0; w<BOARD_WIDTH; ++w)
                {

                    if (w==0)
                        cout << h << " ";

                    if (w<10 && w==0)
                        cout << " ";

                    if (gameRunning == false)
                        cout << player[thisPlayer].grid[w][h] << "  ";

                    if (gameRunning == true && player[thisPlayer].grid[w][h] != SHIPS)
                        cout << player[thisPlayer].grid[w][h] << "  ";
                    else if (gameRunning == true && player[thisPlayer].grid[w][h] == SHIPS)
                        cout << WATER<< "  ";

                    if (w == BOARD_WIDTH-1)
                        cout << "\n";
                }
            }
        }
    }
}


