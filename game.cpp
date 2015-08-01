#include "game.h"

bool startgame()
{
    cout << "\n";
    cout << "The game supports two modes of play\n";
    cout << "First mode Single game with computer (print 1)\n";
    cout << "Second mode Player with Player (print 2)\n";
    do
    {
        cout << "Choose mode:";
        cin>> gametype;
    }
    while(gametype!=1 && gametype!=2);

    if(gametype==1)
    {
        cout << "\n";
        cout << "You can choose computers difficult \n";
        cout << "Passive mode (print 1)\n";
        cout << "Not Passive mode (print 2)\n";
        cout << "Diagonal mode (print 3)\n";
        cout << "Choose difficult:";
        do
            cin>>computerdificult;
        while(computerdificult!=1 && computerdificult!=2 && computerdificult!=3);
    }
    addShips();
    ResetBoard();
    placeships(gametype);

    gameRunning = true;

    currentPlayer = 1;
    do
    {
        int enemyPlayer;
        if (currentPlayer == 1)
            enemyPlayer = 2;
        if (currentPlayer == 2)
            enemyPlayer = 1;
        system("cls");
        DrawBoard(gametype);


        while (goodInput == false  )
        {
            goodInput = UserInputAttack(x,y,currentPlayer);
            if(player[enemyPlayer].grid[x][y] != SHIPS && player[enemyPlayer].grid[x][y] != WATER)
                goodInput=false;
        }

        if (player[enemyPlayer].grid[x][y] == SHIPS)
            player[enemyPlayer].grid[x][y] = HIT;
        if (player[enemyPlayer].grid[x][y] == WATER)
            player[enemyPlayer].grid[x][y] = MISS;

        aWin = GameOverCheck(enemyPlayer);
        if (aWin != 0)
        {
            gameRunning = false;
            break;
        }

        if((player[enemyPlayer].grid[x][y] !=HIT ))
        {
            if(gametype==2)
            {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
            else
                computermove(-1,-1);
        }

    } while (gameRunning);

    system("cls");
    if(gametype==2)
        cout << "\n\nCONGRATULATIONS!!!  PLAYER " << aWin << " HAS WON THE GAME!\n\n\n\n";
    else
    {
        if(aWin==1)
            cout << "\n\nCONGRATULATIONS!!!  PLAYER " << aWin << " HAS WON THE GAME!\n\n\n\n";
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
            if (player[enemyPLAYER].grid[w][h] == SHIPS)
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

