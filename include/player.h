#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#include <C:\devkitPro\libnds\include\nds.h>
#include <C:\devkitPro\libnds\include\filesystem.h>
#include <../include/tempNFlib.h>



class Player
{
private:


public:
    int x = 128;
    int y = 96;
    
    bool isAlive = true;
    bool walking = false;
    bool running = false;
    bool jumping = false;
    bool canWalk = true;
    bool canRun = true;
    bool canJump = true;

    Player();

    /// @brief Alters player values based on inputs
    /// @param keys Result of keysHeld()
    void HandleInput(int keys);

    /// @brief Updates the player sprite location on screen
    /// @param x X co-ordinate of the desired location for sprite
    /// @param y Y co-ordinate of the desired location for sprite
    void TranslatePlayer(int x, int y);

    /// @brief With player values, updates player sprite, things like rotation and animation
    void UpdatePlayer();
};