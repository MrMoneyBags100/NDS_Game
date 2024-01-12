#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>

// #include <nds.h>
// #include <console.h>

class Game
{
private:
    volatile int frame = 0;

public:
    bool debugging = true;

    /// @brief Current state of play
    enum State
    {
        MENU,
        GAME_1,
        GAME_2,
        MINIGAME
    };

    /// @brief Collection of minigames available while aboard ship
    enum Minigame
    {
        AIM_CANNON,
        STEER_SHIP,
        REPAIR_WOOD,
        CHANGE_SAILS
    };

    Game();

    /// @brief Called once per frame, used to keep track of where we are for movement, animations etc...
    void Tick();

    /// @brief Called once per frame, calls the main logic for game
    /// @param debugging 
    void Update(bool debugging);

    /// @brief Stops other processes and starts menu
    /// @param debugging 
    void StartMenuScreen(bool debugging);

    /// @brief Stops other processes and starts round 1 of game
    void StartGame1Screen(bool debugging);

    /// @brief Stops other processes and starts round 2 of game
    void StartGame2Screen(bool debugging);

    /// @brief Stops other processes and starts minigame based on parameter
    void StartMinigameScreen(bool debugging, int minigame);
};