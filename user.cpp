#include "user.h"

bool UserInputAttack(int& x, int& y, int theplayer)
{
    cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
    bool goodInput = false;
    cin >> x >> y;
    if (x<0 || x>=BOARD_WIDTH) return goodInput;
    if (y<0 || y>=BOARD_HEIGHT) return goodInput;
    goodInput = true;
    return goodInput;
}


