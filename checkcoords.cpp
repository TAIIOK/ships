#include <heder.h>

bool checkpos(int currentplayer,int x,int y)
{
    if(newboard.player[currentplayer].grid[x+1][y] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x+1][y+1] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x+1][y-1] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x][y+1] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x][y-1] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x-1][y-1] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x-1][y] == SHIPS)
    {
        return false;
    }
    if(newboard.player[currentplayer].grid[x-1][y+1] == SHIPS)
    {
        return false;
    }
    return true;
}

bool check(int &x ,int &y)
{
    if(x!=-1 && y!=-1)
    {
        if(x+1!=10)
        {
            if(newboard.player[1].grid[x+1][y] == SHIPS)
            {
                x=x+1;
                return true;
            }
        }

        if(x-1!=-1)
        {
            if(newboard.player[1].grid[x-1][y] == SHIPS)
            {
                x=x-1;
                return true;
            }
        }
        if(y+1!=10)
        {
            if(newboard.player[1].grid[x][y+1] == SHIPS)
            {
                y=y+1;
                return true;
            }
        }
        if(y-1!=-1)
        {
            if(newboard.player[1].grid[x][y-1] == SHIPS)
            {
                y=y-1;
                return true;
            }
        }
    }
    return false;
}
