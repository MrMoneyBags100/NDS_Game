#include <../include/game.h>



Game::Game()
{

}

void Game::Init()
{
    NF_Set2D(0, 0); // TOP
    NF_Set2D(1, 0); // BOTTOM

    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");

    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
}

void Game::Tick()
{
    frame++;
}

void Game::Update()
{
    //Scan for inputs and record results
    scanKeys();
    keyHeld = keysHeld();
    keyDown = keysDown();
    if(keyHeld & keyDown); // Just for clearing the unused variable messages on test makes of project | DELETEME

    // if(debugging) //Debug text for checking background values during testing
    // {
    //     if (frame < 50)
    //     {
    //         consoleDemoInit();
    //     }
    //     consoleClear();
    //     iprintf("\x1b[7;1HFrames: %i", frame);
    //     iprintf("\x1b[8;1HState: %i", currentState);
    // }

    switch (currentState) //Check current STATE
    {
        case STATE_MENU:
            switch (currentMenu) //Check current MENU
            {
                case MENU_START:
                    Menu_Start();
                    break;
                case MENU_MAIN:
                    Menu_Main();
                    break;
                case MENU_SETTINGS:
                    Menu_Settings();
                    break;
                case MENU_PLAY:
                    Menu_Play();
                    break;
                case MENU_SHOP:
                    Menu_Shop();
                    break;
                default:
                    break;
            }
            break;
        case STATE_ACTION:
            switch (currentAction) //Check current ACTION
            {
                case ACTION_SHIP_BATTLE:
                    Action_Battle();
                    break;
                case ACTION_MELEE_BATTLE:
                    Action_MeleeBattle();
                    break;
                default:
                    break;
            }
            switch (currentMinigame) //Check current MINIGAME
            {
                case MINIGAME_NONE:
                    break;
                case MINIGAME_AIM_CANNON:
                    Minigame_AimCannon();
                    break;
                case MINIGAME_STEER_SHIP:
                    Minigame_SteerShip();
                    break;
                case MINIGAME_REPAIR_WOOD:
                    Minigame_RepairWood();
                    break;
                case MINIGAME_CHANGE_SAILS:
                    Minigame_ChangeSails();
                    break;
                default:
                    break;
            }

            break;
        default:
            break;
    }

    return;
}

void Game::Menu_Start()
{
    if (booting)
    {
        NF_LoadTiledBg("Bg/exampleSky", "exampleSky", 256, 256);
        NF_CreateTiledBg(0, 3, "exampleSky");

        booting = false;
        frameBooted = frame;
        NF_LoadTiledBg("Bg/stormSea", "stormSea", 256, 256);
    }
    else
    {
        if (frameBooted+200 <= frame)
        {
            NF_CreateTiledBg(0, 3, "stormSea");
        }
        if (frameBooted+400 <= frame)
        {
            NF_CreateTiledBg(0, 3, "exampleSky");
        }
        if (frameBooted+600 <= frame)
        {
            NF_UnloadTiledBg("exampleSky");
            NF_UnloadTiledBg("stormSea");
            currentMenu = MENU_MAIN;
        }
    }
}

void Game::Menu_Main()
{
    NF_LoadTiledBg("Bg/stormSea", "stormSea", 256, 256);
    NF_CreateTiledBg(0, 3, "stormSea");
    NF_UnloadTiledBg("stormSea");
}

void Game::Menu_Settings()
{
    
}

void Game::Menu_Play()
{
    
}

void Game::Menu_Shop()
{
    
}

void Game::Action_Battle()
{
    
}

void Game::Action_MeleeBattle()
{
    
}

void Game::Minigame_AimCannon()
{
    
}

void Game::Minigame_SteerShip()
{
    
}

void Game::Minigame_RepairWood()
{
    
}

void Game::Minigame_ChangeSails()
{
    
}