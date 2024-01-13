#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>

#include <C:\devkitPro\libnds\include\nds.h>
#include <../include/tempNFlib.h>
// #include <C:\devkitPro\nflib\include\nf_lib.h>
// #include <C:\devkitPro\libnds\include\gl2d.h>



class Game
{
private:
    volatile int frame = 0;
    int currentState = 0;
    int currentMenu = 0;
    int currentAction = 0;
    int currentMinigame = 0;

    int keyHeld;
    int keyDown;

    /// @brief Flag to check whether game is being booted and needs starting sequence to show
    bool isStarting = true;
    /// @brief Flag to be set after starting sequence is finished to show menu
    bool isStartingFinish = false;
    /// @brief Flag to be set when a state is being abandoned to stop logic while it quits
    bool isQuitting = false;
    /// @brief Flag to be set when game should be paused to halt certain logic
    bool isPaused = false;
    /// @brief Flag to be set when game is multiplayer to manipulate certain logic
    bool isSinglePlayer = true;

public:
    bool debugging = true;
    int debugLastToggled = 0;



    /// @brief Current state of play
    typedef enum
    {
        STATE_MENU,
        STATE_ACTION,
    }STATE;

    /// @brief Current
    typedef enum
    {
        MENU_MAIN,
        MENU_SETTINGS,
        MENU_PLAY,
        MENU_SHOP
    }MENUTYPE;

    typedef enum
    {
        ACTION_SHIP_BATTLE,
        ACTION_MELEE_BATTLE
    }ACTIONTYPE;

    /// @brief Collection of minigames available while aboard ship
    typedef enum
    {
        MINIGAME_NONE,
        MINIGAME_AIM_CANNON,
        MINIGAME_STEER_SHIP,
        MINIGAME_REPAIR_WOOD,
        MINIGAME_CHANGE_SAILS
    }MINIGAME;

    STATE StateEnum;
    MENUTYPE MenuEnum;
    ACTIONTYPE ActionEnum;
    MINIGAME MinigameEnum;



    Game();

    /// @brief Called once per frame, used to keep track of where we are for movement, animations etc...
    void Tick();

    /// @brief Called once per frame, calls the main logic for game
    /// @param debugging 
    void Update();

    /// @brief Stops other processes and starts menu
    /// @param debugging 
    void StartMenuScreen();

    /// @brief Stops other processes and starts round 1 of game
    void StartGame1Screen();

    /// @brief Stops other processes and starts round 2 of game
    void StartGame2Screen();

    /// @brief Stops other processes and starts minigame based on parameter
    /// @param currentMinigame ID of current minigame
    void StartMinigameScreen(int minigame);
};