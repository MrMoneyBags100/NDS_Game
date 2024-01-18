#include <../include/game.h>



Game::Game()
{
    NF_Set2D(0, 0); // TOP SCREEN
    NF_Set2D(1, 0); // BOTTOM SCREEN

    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");

    NF_InitTiledBgBuffers();
    NF_InitSpriteBuffers();

    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
    NF_InitSpriteSys(0);
    NF_InitSpriteSys(1);
    // NF_InitTextSys(0);
}

void Game::Tick()
{
    frame++;
}

void Game::Update()
{
    // if(debugging) //Debug text for checking background values during testing
    // {
    //     if (frame < 50)
    //     {
    //         consoleDemoInit();
    //     }
    //     consoleClear();
    //     iprintf("\x1b[7;1HFrames: %i", frame);
    //     iprintf("\x1b[8;1HMenu_State: %i", currentMenu);
    // }

    scanKeys();
    int keydownInput = keysDown();
    int keyHeldInput = keysHeld();
    if (keydownInput & keyHeldInput); //Here to avoid "unused variable" flag in make process

    switch (currentState) //Check current STATE
    {
        case STATE_MENU:
            switch (currentMenu) //Check current MENU
            {
                case MENU_START:
                    Menu_Start(keyHeldInput);
                    break;
                case MENU_MAIN:
                    Menu_Main(keyHeldInput);
                    break;
                case MENU_SETTINGS:
                    Menu_Settings(keyHeldInput);
                    break;
                case MENU_PLAY:
                    Menu_Play(keyHeldInput);
                    break;
                case MENU_SHOP:
                    Menu_Shop(keyHeldInput);
                    break;
                default:
                    break;
            }
            break;
        case STATE_ACTION:
            switch (currentAction) //Check current ACTION
            {
                case ACTION_SHIP_BATTLE:
                    Action_ShipBattle(keyHeldInput);
                    break;
                case ACTION_MELEE_BATTLE:
                    Action_MeleeBattle(keyHeldInput);
                    break;
                default:
                    break;
            }
            switch (currentMinigame) //Check current MINIGAME
            {
                case MINIGAME_NONE:
                    break;
                case MINIGAME_AIM_CANNON:
                    Minigame_AimCannon(keyHeldInput);
                    break;
                case MINIGAME_STEER_SHIP:
                    Minigame_SteerShip(keyHeldInput);
                    break;
                case MINIGAME_REPAIR_WOOD:
                    Minigame_RepairWood(keyHeldInput);
                    break;
                case MINIGAME_CHANGE_SAILS:
                    Minigame_ChangeSails(keyHeldInput);
                    break;
                default:
                    break;
            }

            break;
        default:
            break;
    }
    NF_SpriteOamSet(0);
    NF_SpriteOamSet(1);
    oamUpdate(&oamSub);
    return;
}

void Game::Menu_Start(int keyHeld)
{
    switch (menuStartStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/stormSea", "stormSea", 256, 256);
            NF_LoadTiledBg("Bg/exampleSky", "exampleSky", 256, 256);
            NF_CreateTiledBg(0, 3, "exampleSky");
            menuStartStage++;
            frameBooted = frame;
            break;
        case 1:
            if (frameBooted+200 <= frame)
            {
                NF_CreateTiledBg(0, 3, "stormSea");
                menuStartStage++;
            }
            break;
        case 2:
            if (frameBooted+400 <= frame)
            {
                NF_CreateTiledBg(0, 3, "exampleSky");
                menuStartStage++;
            }
            break;
        case 3:
            if (frameBooted+600 <= frame)
            {
                NF_UnloadTiledBg("exampleSky");
                NF_UnloadTiledBg("stormSea");
                menuStartStage = 0;
                frameBooted = 0;
                currentMenu = MENU_MAIN;
            }
            break;
        default:
            break;
    }
}

void Game::Menu_Main(int keyHeld)
{
    switch (menuMainStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/MainMenuSmall", "MainMenu", 256, 256);
            NF_CreateTiledBg(1, 3, "MainMenu");

            // NF_LoadSpriteGfx("Sprites/SpriteTest", 0, 64, 64);
            // NF_LoadSpritePal("Sprites/SpriteTest", 0);
            // NF_VramSpriteGfx(1, 0, 0, false);
            // NF_VramSpritePal(1, 0, 0);

            // NF_CreateSprite(1, 0, 0, 0, player.selectorX, player.selectorY);

            menuMainStage++;

            break;

        case 1:
            player.HandleInput(keyHeld);
            // NF_MoveSprite(1, 0, player.selectorX, player.selectorY);

            break;
            
        default:

            break;
    }
}

void Game::Menu_Settings(int keyHeld)
{
    
}

void Game::Menu_Play(int keyHeld)
{
    
}

void Game::Menu_Shop(int keyHeld)
{
    
}

void Game::Action_ShipBattle(int keyHeld)
{

}

void Game::Action_MeleeBattle(int keyHeld)
{
    
}

void Game::Minigame_AimCannon(int keyHeld)
{
    
}

void Game::Minigame_SteerShip(int keyHeld)
{
    
}

void Game::Minigame_RepairWood(int keyHeld)
{
    
}

void Game::Minigame_ChangeSails(int keyHeld)
{
    
}