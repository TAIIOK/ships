#include "board.h"

void placeships(int gametype)
{
    for (players=1; players<1+gametype; players++)
    {
        for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
        {
            system("cls");
            DrawBoard(gametype);

            cout << "\n";
            cout << "Player " <<players <<"\n";
            cout << "Instruction))\n First number is orintation(Horizontal is number 0, Vertical is number 1 )\n Second number is X(top) coordinate \n Third number is Y(left) coordinate\n ";
            cout << "Your move ship: " <<ship[thisShip].name <<"with lenght " <<ship[thisShip].length<<" ?";

            PLACESHIPS addShip;
            addShip.shipType.onGrid[0].X = -1;
            while (addShip.shipType.onGrid[0].X == -1)
            {
                addShip = UserInputShipPlacement(thisShip,players);
            }

            addShip.shipType.length = ship[thisShip].length;
            addShip.shipType.name = ship[thisShip].name;

            player[players].grid[addShip.shipType.onGrid[0].X][addShip.shipType.onGrid[0].Y] = SHIPS;

            for (int i=1; i<addShip.shipType.length; ++i)
            {
                if (addShip.direction == HORIZONTAL)
                {
                    addShip.shipType.onGrid[i].X = addShip.shipType.onGrid[i-1].X+1;
                    addShip.shipType.onGrid[i].Y = addShip.shipType.onGrid[i-1].Y;
                }
                if (addShip.direction == VERTICAL)
                {
                    addShip.shipType.onGrid[i].Y = addShip.shipType.onGrid[i-1].Y+1;
                    addShip.shipType.onGrid[i].X = addShip.shipType.onGrid[i-1].X;
                }
                player[players].grid[addShip.shipType.onGrid[i].X][addShip.shipType.onGrid[i].Y] = SHIPS;
            }
        }
    }
    if(gametype==1)
    {
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
        {
            int d,x,y;
            bool flag;
            PLACESHIPS addShip;

            addShip.shipType.length = ship[thisShip].length;
            addShip.shipType.name = ship[thisShip].name;
            do
            {
                flag=false;
                d=qrand()%2;
                x=qrand()%10;
                y=qrand()%10;
                if(d==0)
                {
                    if(x+ship[thisShip].length>10 && d==0)
                    {
                        flag=true;
                    }
                }
                else if (d==1)
                {
                    if(y+ship[thisShip].length>10 && d==1)
                    {
                        flag=true;
                    }
                }
                if(!flag)
                {
                    for(int k=0;k<=ship[thisShip].length && flag==false;k++)
                    {
                        if(d==0)
                        {
                            if(!checkpos(2,x+k,y))
                            {
                                flag=true;
                            }
                            else
                                flag=false;
                        }

                        if(d==1)
                        {
                            if(!checkpos(2,x,y+k))
                            {
                                flag=true;
                            }
                            else
                                flag=false;
                        }
                    }
                }
            }
            while(flag);

            addShip.direction = (DIRECTION)d;
            addShip.shipType.onGrid[0].X = x;
            addShip.shipType.onGrid[0].Y = y;

            player[2].grid[addShip.shipType.onGrid[0].X][addShip.shipType.onGrid[0].Y] = SHIPS;

            for (int i=1; i<addShip.shipType.length; ++i)
            {
                if (addShip.direction == HORIZONTAL)
                {
                    addShip.shipType.onGrid[i].X = addShip.shipType.onGrid[i-1].X+1;
                    addShip.shipType.onGrid[i].Y = addShip.shipType.onGrid[i-1].Y;
                }
                if (addShip.direction == VERTICAL)
                {
                    addShip.shipType.onGrid[i].Y = addShip.shipType.onGrid[i-1].Y+1;
                    addShip.shipType.onGrid[i].X = addShip.shipType.onGrid[i-1].X;
                }

                player[2].grid[addShip.shipType.onGrid[i].X][addShip.shipType.onGrid[i].Y] = SHIPS;


            }
            gameRunning = true;
            //printtestboard(2);
        }
    }
}

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


