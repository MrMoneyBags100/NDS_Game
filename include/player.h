#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <algorithm>

#include <C:\devkitPro\libnds\include\nds.h>
#include <C:\devkitPro\libnds\include\filesystem.h>
#include <../include/tempNFlib.h>



class Player
{
private:


public:
    bool isAlive = true;
    bool walking = false;
    bool running = false;
    bool jumping = false;
    bool canWalk = true;
    bool canRun = true;
    bool canJump = true;

    int currentCharacter = 0;

    int selectedMenuButton = 0;
    bool menuButtonPressed = false;
    bool menuBackPressed = false;
    int selectorLastMoved = 0;
    int selectorCooldown = 25;
    int selectorX = 120;
    int selectorY = 9;


    //ENUMS

    typedef enum
    {
        DEFAULT
    }Characters;

    
    //FUNCTIONS

    Player();

    /// @brief Alters player values based on inputs
    /// @param keys Result of keysHeld()
    void HandleInput(int keysDown, int keysHeld, int frame, int currentState, int currentMenu, int currentAction, int currentMinigame);

    void ResetInput();
};