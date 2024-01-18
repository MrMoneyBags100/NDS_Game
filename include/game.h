#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <algorithm>

#include <C:\devkitPro\libnds\include\nds.h>
#include <C:\devkitPro\libnds\include\filesystem.h>
#include <../include/tempNFlib.h>

#include <../include/player.h>



class Game
{
private:
    volatile int frame = 0;
    int currentState = 0;
    int currentMenu = 1;
    int currentAction = 0;
    int currentMinigame = 0;

    int keyHeld;
    int keyDown;
    bool isQuitting = false;
    bool isPaused = false;
    bool isSinglePlayer = true;

    int menuStartStage = 0;
    int frameBooted = 0;

    int menuMainStage = 0;

    int actionShipStage = 0;

public:
    Player player;
    bool debugging = true;
    int debugLastToggled = 0;


    /// @brief Game states
    typedef enum
    {
        STATE_MENU,
        STATE_ACTION,
    }STATE;

    /// @brief Menu types
    typedef enum
    {
        MENU_START,
        MENU_MAIN,
        MENU_SETTINGS,
        MENU_PLAY,
        MENU_SHOP
    }MENUTYPE;

    /// @brief Action types
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

    /// @brief Called at boot, initialises screens and libraries for everything to come
    void Init();

    /// @brief Called once per frame, used to keep track of where we are for movement, animations etc...
    void Tick();

    /// @brief Called once per frame, calls the main logic for game
    /// @param debugging 
    void Update();

    void Menu_Start(int keyHeld);

    void Menu_Main(int keyHeld);

    void Menu_Settings(int keyHeld);

    void Menu_Play(int keyHeld);

    void Menu_Shop(int keyHeld);

    void Action_ShipBattle(int keyHeld);

    void Action_MeleeBattle(int keyHeld);

    void Minigame_AimCannon(int keyHeld);

    void Minigame_SteerShip(int keyHeld);

    void Minigame_RepairWood(int keyHeld);

    void Minigame_ChangeSails(int keyHeld);
};