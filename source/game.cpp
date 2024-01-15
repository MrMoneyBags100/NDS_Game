#include <../include/game.h>



Game::Game()
{

}

void Game::Init()
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
    NF_InitTextSys(0);
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
                    Action_Battle(keyHeldInput);
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
                currentMenu = MENU_MAIN;
                menuStartStage = 0;
                frameBooted = 0;
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
            NF_LoadTiledBg("Bg/stormSea", "stormSea", 256, 256);
            NF_CreateTiledBg(0, 3, "stormSea");
            NF_UnloadTiledBg("stormSea");

            menuMainStage++;

            break;

        case 1:
            NF_LoadTiledBg("Bg/colmap", "colmap", 768, 512);
            NF_CreateTiledBg(1, 2, "colmap");

            NF_LoadSpriteGfx("Sprites/pointer", 0, 8, 8);
            NF_LoadSpritePal("Sprites/pointer", 0);
            NF_VramSpriteGfx(1, 0, 0, true);
            NF_VramSpritePal(1, 0, 0);
            NF_CreateSprite(1, 0, 0, 0, 124, 92);
            NF_SpriteLayer(1, 0, 2);
            
            menuMainStage++;

            break;

        case 2:
            player.HandleInput(keyHeld);

            bg_x = player.x - 128; //Map scroll value
            if (bg_x < 0)
                bg_x = 0;
            if (bg_x > 512)
                bg_x = 512;

            bg_y = player.y - 96;
            if (bg_y < 0)
                bg_y = 0;
            if (bg_y > 320)
                bg_y = 320;
            
            NF_MoveSprite(1, 0, (player.x - bg_x) - 4, (player.y - bg_y) - 4);

            if (keyHeld & KEY_B)
                NF_SetTileOfMap(1, 2, player.x / 8, player.y / 8, 0);
            if (keyHeld & KEY_A)
                NF_SetTileOfMap(1, 2, player.x / 8, player.y / 8, 1);
            if (keyHeld & KEY_Y)
                NF_SetTileOfMap(1, 2, player.x / 8, player.y / 8, 2);
            if (keyHeld & KEY_X)
                NF_SetTileOfMap(1, 2, player.x / 8, player.y / 8, 3);
            if (keyHeld & KEY_X)
                NF_SetTileOfMap(1, 2, player.x / 8, player.y / 8, 3);
            if (keyHeld & KEY_START)
                menuMainStage++;

            NF_UpdateVramMap(1, 2);
            NF_ScrollBg(1, 2, bg_x, bg_y);

            break;

        case 3:
            NF_UnloadTiledBg("colmap");
            NF_UnloadSpriteGfx(0);
            NF_UnloadSpritePal(0);
            menuMainStage++;

            break;

        case 4:
            NF_LoadTiledBg("Bg/exampleSky", "exampleSky", 256, 256);
            NF_CreateTiledBg(0, 3, "exampleSky");
            NF_UnloadTiledBg("exampleSky");
            menuMainStage++;

            break;

        case 5:

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

void Game::Action_Battle(int keyHeld)
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