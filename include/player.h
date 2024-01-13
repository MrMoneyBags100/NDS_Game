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
    
    bool isAlive = true;
    bool walking = false;
    bool running = false;
    bool jumping = false;
    bool canWalk = true;
    bool canRun = true;
    bool canJump = true;

    Player();

    /// @brief 
    /// @param keys Result of keysHeld()
    /// @param state ID of current state
    void HandleInput(int keys, int state);
    /// @brief 
    /// @param keys Result of keysHeld()
    /// @param state ID of current state
    /// @param minigame ID of current minigame
    void HandleInput(int keys, int state, int minigame);

    /// @brief Updates the player sprite location on screen
    /// @param x X co-ordinate of the desired location for sprite
    /// @param y Y co-ordinate of the desired location for sprite
    void TranslatePlayer(int x, int y);

    /// @brief With player values, updates player sprite, things like rotation and animation
    void UpdatePlayer();
};