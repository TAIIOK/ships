
#include <heder.h>
void GetrandomCoords(int &x, int &y)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    x=qrand()%10;
    y=qrand()%10;
}

bool computermove(int x,int y)
{
    bool status=false;

    if(newgame.computerdificult==1)
    {
        do
        {

            GetrandomCoords(x,y);

        }
        while(newboard.player[1].grid[x][y] != SHIPS && newboard.player[1].grid[x][y] != WATER);

        if (newboard.player[1].grid[x][y] == SHIPS)
        {
            newboard.player[1].grid[x][y] = HIT;
            newgame.aWin = GameOverCheck(1);
            if (newgame.aWin != 0)
            {
                newgame.gameRunning = false;
            }
            computermove(x,y);
        }
        if (newboard.player[1].grid[x][y] == WATER)
            newboard.player[1].grid[x][y] = MISS;

        system("cls");
        DrawBoard(1);
    }
    if(newgame.computerdificult==2)
    {
        if(x==-1 && y==-1)
        {
            GetrandomCoords(x,y);
        }
        else
        {
            status=check(x,y);
        }

        do
        {
            if(status==false )
            {
                GetrandomCoords(x,y);
            }
        }
        while(newboard.player[1].grid[x][y] != SHIPS && newboard.player[1].grid[x][y] != WATER);

        if (newboard.player[1].grid[x][y] == SHIPS)
        {
            newboard.player[1].grid[x][y] = HIT;
            newgame.aWin = GameOverCheck(1);
            if (newgame.aWin != 0)
            {
                newgame.gameRunning = false;

            }
            computermove(x,y);
        }

        if (newboard.player[1].grid[x][y] == WATER)
            newboard.player[1].grid[x][y] = MISS;

        system("cls");
        DrawBoard(1);
        return true;
    }
    if(newgame.computerdificult==3)
    {
        int mass1[26][2]={{0,3},{1,2},{2,1},{3,0},{0,8},{1,7},{2,6},{3,5},{4,4},{5,3},{6,2},{7,1},{8,0},{2,10},{3,9},{4,8},{5,7},{6,6},{7,5},{8,4},{9,3},{10,2},{7,10},{8,9},{9,8},{10,7}};
        bool flag=true;
        bool random=false;

        status=check(x,y);
        if(status==false)
        {
            for(int f=0;f<27 && flag;f++)
            {
                if(f==26)
                {
                    random=true;
                }
                for(int k=0;k<1 && !random;k++)
                {
                    x=mass1[f][k];
                    y=mass1[f][k+1];
                    if ( newboard.player[1].grid[x][y] != HIT && newboard.player[1].grid[x][y] != MISS )
                    {
                        flag=false;
                    }
                    else
                        flag=true;
                }
            }

            do
            {
                if(random)
                {
                    GetrandomCoords(x,y);
                }
            }
            while(newboard.player[1].grid[x][y] != SHIPS && newboard.player[1].grid[x][y] != WATER);

        }
        if (newboard.player[1].grid[x][y] == SHIPS)
        {
            newboard.player[1].grid[x][y] = HIT;
            newgame.aWin = GameOverCheck(1);
            if (newgame.aWin != 0)
            {
                newgame.gameRunning = false;

            }
            computermove(x,y);
        }
        if (newboard.player[1].grid[x][y] == WATER)
            newboard.player[1].grid[x][y] = MISS;


        system("cls");
        DrawBoard(1);
    }
}
