#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

class Player
{
private:


public:
    int x;
    int y;
    
    bool walking = 0;
    bool running = 0;
    bool jumping = 0;
    bool canWalk = 1;
    bool canRun = 1;
    bool canJump = 1;

    void HandleInput(int keys, int mode);
    void Move();
};