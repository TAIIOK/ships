#include <game.h>

game newgame;
gameboard newboard;

bool StartGame()
{

    cout << "\n";
    cout << "The game supports two modes of play\n";
    cout << "First mode Single game with computer (print 1)\n";
    cout << "Second mode Player with Player (print 2)\n";

    do
    {
        cout << "Choose mode:";
        cin>> newgame.gametype;
    }
    while(newgame.gametype!=1 && newgame.gametype!=2);

    if(newgame.gametype==1)
    {
        cout << "\n";
        cout << "You can choose computers difficult \n";
        cout << "Passive mode (print 1)\n";
        cout << "Not Passive mode (print 2)\n";
        cout << "Diagonal mode (print 3)\n";
        cout << "Choose difficult:";
        do
            cin>>newgame.computerdificult;
        while(newgame.computerdificult!=1 && newgame.computerdificult!=2 && newgame.computerdificult!=3);
    }
    AddShips();
    ResetBoard();
    PlaceShips(newgame.gametype);

    newgame.gameRunning = true;

    newgame.currentPlayer = 1;
    do
    {
        newgame.goodInput = false;
        int enemyPlayer;
        if (newgame.currentPlayer == 1)
            enemyPlayer = 2;
        if (newgame.currentPlayer == 2)
            enemyPlayer = 1;
        system("cls");
        DrawBoard(newgame.gametype);


        while (newgame.goodInput == false  )
        {
            newgame.goodInput = UserInputAttack(newgame.x,newgame.y,newgame.currentPlayer);

            if(newboard.player[enemyPlayer].grid[newgame.x][newgame.y] != SHIPS && newboard.player[enemyPlayer].grid[newgame.x][newgame.y] != WATER)
                newgame.goodInput=false;
        }

        if (newboard.player[enemyPlayer].grid[newgame.x][newgame.y] == SHIPS)
            newboard.player[enemyPlayer].grid[newgame.x][newgame.y] = HIT;
        if (newboard.player[enemyPlayer].grid[newgame.x][newgame.y] == WATER)
            newboard.player[enemyPlayer].grid[newgame.x][newgame.y] = MISS;

        newgame.aWin = GameOverCheck(enemyPlayer);
        if (newgame.aWin != 0)
        {
            newgame.gameRunning = false;
            break;
        }

        if((newboard.player[enemyPlayer].grid[newgame.x][newgame.y] !=HIT ))
        {
            if(newgame.gametype==2)
            {
                newgame.currentPlayer = (newgame.currentPlayer == 1) ? 2 : 1;
            }
            else
                ComputerMove(-1,-1);
        }

    } while (newgame.gameRunning);

    system("cls");
    if(newgame.gametype==2)
        cout << "\n\nCONGRATULATIONS!!!  PLAYER " << newgame.aWin << " HAS WON THE GAME!\n\n\n\n";
    else
    {
        if(newgame.aWin==1)
            cout << "\n\nCONGRATULATIONS!!!  PLAYER " << newgame.aWin << " HAS WON THE GAME!\n\n\n\n";
        else
            cout << "\n\nCONGRATULATIONS!!!  COMPUTER HAS WON THE GAME!\n\n\n\n";
    }

    return true;

}

int GameOverCheck(int enemyPLAYER)
{
    for (int w=0; w<BOARD_WIDTH; ++w)
    {
        for (int h=0; h<BOARD_HEIGHT; ++h){

            if (newboard.player[enemyPLAYER].grid[w][h] == SHIPS)
            {
                return 0;
            }
        }
    }
    if(enemyPLAYER==1)
        return enemyPLAYER+1;
    else
        return enemyPLAYER-1;
}
gameboard::PLACESHIPS  UserInputShipPlacement(int thisShip, int playernumber)
{
    int d, x, y;

    gameboard::PLACESHIPS tmp;
    tmp.shipType.onGrid[0].X = -1;

    cin >> d >> y >> x;

    if (d!=0 && d!=1)
    {
        cout<<"wrong orientation\n";
        return tmp;
    }
    if (x<0 || x>=BOARD_WIDTH)
    {
        cout<<"wrong X coordinate\n";
        return tmp;
    }
    if (y<0 || y>=BOARD_HEIGHT)
    {
        cout<<"wrong Y coordinate\n";
        return tmp;
    }
    if(x+newboard.ship[thisShip].length>10 && d==0)
    {
        cout<<"wrong position\n";
        return tmp;
    }

    if(y+newboard.ship[thisShip].length>10 && d==1)
    {
        cout<<"wrong position\n";
        return tmp;
    }
    for(int k=0;k<=newboard.ship[thisShip].length;k++)
    {
        if(d==0)
        {
            if(!CheckPosition(playernumber,x+k,y))
            {
                cout<<"Wrong position \n";
                return tmp;
            }
        }

        if(d==1)
        {
            if(!CheckPosition(playernumber,x,y+k))
            {
                cout<<"Wrong position \n";
                return tmp;
            }
        }

    }
    tmp.direction = (DIRECTION)d;
    tmp.shipType.onGrid[0].X = x;
    tmp.shipType.onGrid[0].Y = y;
    return tmp;
}

bool UserInputAttack(int& x, int& y, int currentplayer)
{
    cout << "\nPLAYER " << currentplayer << ", ENTER COORDINATES TO ATTACK: ";
    bool goodInput = false;
    cin >> x >> y;
    if (x<0 || x>=BOARD_WIDTH) return goodInput;
    if (y<0 || y>=BOARD_HEIGHT) return goodInput;
    goodInput = true;
    return goodInput;
}

void PlaceShips(int gametype)
{

    for (newgame.players=1; newgame.players<1+newgame.gametype; newgame.players++)
    {
        for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
        {

            system("cls");
            DrawBoard(gametype);

            cout << "\n";
            cout << "Player " <<newgame.players <<"\n";
            cout << "Instruction))\n First number is orintation(Horizontal is number 0, Vertical is number 1 )\n Second number is X(top) coordinate \n Third number is Y(left) coordinate\n ";
            cout << "Your move ship: " <<newboard.ship[thisShip].name <<"with lenght " <<newboard.ship[thisShip].length<<" ?";

            gameboard::PLACESHIPS addShip;
            addShip.shipType.onGrid[0].X = -1;
            while (addShip.shipType.onGrid[0].X == -1)
            {
                addShip = UserInputShipPlacement(thisShip,newgame.players);
            }

            addShip.shipType.length = newboard.ship[thisShip].length;
            addShip.shipType.name = newboard.ship[thisShip].name;

            newboard.player[newgame.players].grid[addShip.shipType.onGrid[0].X][addShip.shipType.onGrid[0].Y] = SHIPS;

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
                newboard.player[newgame.players].grid[addShip.shipType.onGrid[i].X][addShip.shipType.onGrid[i].Y] = SHIPS;
            }
        }
    }
    if(newgame.gametype==1)
    {
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
        {
            int d,x,y;
            bool flag;
            gameboard::PLACESHIPS addShip;

            addShip.shipType.length = newboard.ship[thisShip].length;
            addShip.shipType.name = newboard.ship[thisShip].name;
            do
            {
                flag=false;
                d=qrand()%2;
                x=qrand()%10;
                y=qrand()%10;
                if(d==0)
                {
                    if(x+newboard.ship[thisShip].length>10 && d==0)
                    {
                        flag=true;
                    }
                }
                else if (d==1)
                {
                    if(y+newboard.ship[thisShip].length>10 && d==1)
                    {
                        flag=true;
                    }
                }
                if(!flag)
                {
                    for(int k=0;k<=newboard.ship[thisShip].length && flag==false;k++)
                    {
                        if(d==0)
                        {
                            if(!CheckPosition(2,x+k,y))
                            {
                                flag=true;
                            }
                            else
                                flag=false;
                        }

                        if(d==1)
                        {
                            if(!CheckPosition(2,x,y+k))
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

            newboard.player[2].grid[addShip.shipType.onGrid[0].X][addShip.shipType.onGrid[0].Y] = SHIPS;

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

                newboard.player[2].grid[addShip.shipType.onGrid[i].X][addShip.shipType.onGrid[i].Y] = SHIPS;


            }
            newgame.gameRunning = true;
            //printtestboard(2);
        }
    }
}

void AddShips()
{
    newboard.ship[0].name = "Cruiser";
    newboard.ship[0].length = 2;
    newboard.ship[1].name = "Frigate";
    newboard.ship[1].length = 3;
    newboard.ship[2].name = "Submarine";
    newboard.ship[2].length = 3;
    newboard.ship[3].name = "Escort";
    newboard.ship[3].length = 4;
    newboard.ship[4].name = "Battleship";
    newboard.ship[4].length = 5;
}

void ResetBoard()
{
    for (int plyr=1; plyr<3; ++plyr)
    {
        for (int w=0; w<BOARD_WIDTH; ++w)
        {
            for (int h=0; h<BOARD_HEIGHT; ++h)
            {
                newboard.player[plyr].grid[w][h] = WATER;
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

            if (newgame.gameRunning == false && newgame.players==1)
            {
                cout << newboard.player[1].grid[w][h] << "  ";
            }
            else if (newgame.players==2 && newgame.gameRunning == false)
                cout << WATER<< "  ";

            if (newgame.gameRunning == true && newboard.player[1].grid[w][h] != SHIPS)
                cout << newboard.player[1].grid[w][h] << "  ";

            else if(newgame.gameRunning == true && newboard.player[1].grid[w][h] == SHIPS && newgame.gametype==1)
                cout << newboard.player[1].grid[w][h] << "  ";

            else if (newgame.gameRunning == true && newboard.player[1].grid[w][h] == SHIPS && newgame.gametype==2)
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

                    if (newgame.gameRunning == false)
                        cout << newboard.player[thisPlayer].grid[w][h] << "  ";

                    if (newgame.gameRunning == true && newboard.player[thisPlayer].grid[w][h] != SHIPS)
                        cout << newboard.player[thisPlayer].grid[w][h] << "  ";
                    else if (newgame.gameRunning == true && newboard.player[thisPlayer].grid[w][h] == SHIPS)
                        cout << WATER<< "  ";

                    if (w == BOARD_WIDTH-1)
                        cout << "\n";
                }
            }
        }
    }
}
