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

    int menuX = 0;
    int menuY = 0;
    int menuScrollSpeed = 8;//Multiples of 8 please
    

    int menuStartStage = 0;
    int frameBooted = 0;

    int menuMainStage = 0;

    int menuPlayStage = 0;

    int menuShopStage = 0;

    int menuCollectionStage = 0;

    int menuSettingsStage = 0;

    int actionShipStage = 0;

public:
    Player player;
    bool debugging = true;


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
        MENU_SHOP,
        MENU_COLLECTION
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

    void Menu_Start();

    void Menu_Main();

    void Menu_Settings();

    void Menu_Play();

    void Menu_Collection();

    void Menu_Shop();

    void Action_ShipBattle();

    void Action_MeleeBattle();

    void Minigame_AimCannon();

    void Minigame_SteerShip();

    void Minigame_RepairWood();

    void Minigame_ChangeSails();
};