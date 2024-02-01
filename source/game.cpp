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

    NF_InitTextSys(0);
    if (debugging)
    {
        NF_LoadTextFont("Fnt/default", "normal", 256, 256, 0);
        NF_CreateTextLayer(0, 2, 0, "normal");
    }

    //RETRIEVE RELEVANT GAME SAVE DATA
}

void Game::Tick()
{
    frame++;
}

void Game::Update()
{
    if(debugging) //Debug text for checking background values during testing
    {
        //PLEASE MAKE A NEW NFLIB DEBUG OVERLAY
        char mytext[32];
        sprintf(mytext,"x:%d  y:%d ", menuX, menuY);
        NF_WriteText(0, 2, 1, 1, mytext);
    }

    scanKeys();
    int keydownInput = keysDown();
    int keyHeldInput = keysHeld();
    player.ResetInput();

    player.HandleInput(keyHeldInput, keydownInput, frame, currentState, currentMenu, currentAction, currentMinigame);

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
                case MENU_COLLECTION:
                    Menu_Collection();
                    break;
                default:
                    break;
            }
            break;
        case STATE_ACTION:
            switch (currentAction) //Check current ACTION
            {
                case ACTION_SHIP_BATTLE:
                    Action_ShipBattle();
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
    NF_SpriteOamSet(0);
    NF_SpriteOamSet(1);
    oamUpdate(&oamSub);
    return;
}

void Game::Menu_Start()
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
            if (frameBooted+100 <= frame)
            {
                NF_CreateTiledBg(0, 3, "stormSea");
                menuStartStage++;
            }
            break;
        case 2:
            if (frameBooted+200 <= frame)
            {
                NF_CreateTiledBg(0, 3, "exampleSky");
                menuStartStage++;
            }
            break;
        case 3:
            if (frameBooted+300 <= frame)
            {
                if ((player.menuButtonPressed) || (frameBooted+1000 <= frame))
                {
                    NF_UnloadTiledBg("exampleSky");
                    NF_UnloadTiledBg("stormSea");
                    menuStartStage = 0;
                    frameBooted = 0;
                    currentMenu = MENU_MAIN;
                }
            }
            break;
        default:
            break;
    }
}

void Game::Menu_Main()
{
    switch (menuMainStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/MainMenu", "MainMenu", 512, 256);
            NF_CreateTiledBg(1, 3, "MainMenu");
            NF_ScrollBg(1, 3, menuX, 0);//Needs to get itself from offscreen to on-screen

            menuMainStage++;
            player.selectedMenuButton = 0;

            break;
        case 1:
            menuX = menuX - menuScrollSpeed;
            if(menuX <= 0)
            {
                menuX = 0;
                menuMainStage++;
                NF_ScrollBg(1, 3, menuX, 0);
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, 0);
            }
            break;
        case 2:
            NF_LoadSpriteGfx("Sprites/MenuSelector", 0, 64, 32);
            NF_LoadSpritePal("Sprites/MenuSelector", 0);
            NF_VramSpriteGfx(1, 0, 0, false);
            NF_VramSpritePal(1, 0, 0);

            NF_CreateSprite(1, 0, 0, 0, player.selectorX, player.selectorY);

            NF_UnloadSpriteGfx(0);
            NF_UnloadSpritePal(0);

            menuMainStage++;
            break;
        case 3:
            NF_MoveSprite(1, 0, player.selectorX, player.selectorY);
            if (player.menuButtonPressed)
            {
                NF_FreeSpriteGfx(1, 0);
                menuMainStage++;
            }
            break;
        case 4:
            menuX = menuX + menuScrollSpeed;
            if(menuX > 256)
            {
                menuMainStage++;
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, menuY);
            }
            break;
        case 5:
            switch (player.selectedMenuButton)
                {
                    case 0:
                        currentMenu = MENU_PLAY;
                        break;
                    case 1:
                        currentMenu = MENU_COLLECTION;
                        break;
                    case 2:
                        currentMenu = MENU_SETTINGS;
                        break;
                }

                NF_UnloadTiledBg("MainMenu");
                player.selectedMenuButton = 0;
                player.menuButtonPressed = false;
                menuMainStage = 0;
            break;

        default:
            break;
    }
}

void Game::Menu_Settings()
{       
    switch (menuSettingsStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/MenuSettings", "MenuSettings", 512, 256);
            NF_CreateTiledBg(1, 3, "MenuSettings");
            NF_ScrollBg(1, 3, menuX, 0);//Needs to get itself from offscreen to on-screen

            menuSettingsStage++;
            player.selectedMenuButton = 0;

            break;
        case 1:
            menuX = menuX - menuScrollSpeed;
            if(menuX <= 0)
            {
                menuX = 0;
                menuSettingsStage++;
                NF_ScrollBg(1, 3, menuX, 0);
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, 0);
            }
            break;
        case 2:
            NF_LoadSpriteGfx("Sprites/MenuSelector", 0, 64, 32);
            NF_LoadSpritePal("Sprites/MenuSelector", 0);
            NF_VramSpriteGfx(1, 0, 0, false);
            NF_VramSpritePal(1, 0, 0);

            NF_CreateSprite(1, 0, 0, 0, player.selectorX, player.selectorY);

            NF_UnloadSpriteGfx(0);
            NF_UnloadSpritePal(0);

            menuSettingsStage++;
            break;
        case 3:
            NF_MoveSprite(1, 0, player.selectorX, player.selectorY);
            if (player.menuButtonPressed || player.menuBackPressed)
            {
                NF_FreeSpriteGfx(1, 0);
                menuSettingsStage++;
            }
            break;
        case 4:
            menuX = menuX + menuScrollSpeed;
            if(menuX > 256)
            {
                menuSettingsStage++;
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, menuY);
            }
            break;
        case 5:
            if (player.menuBackPressed)
            {
                currentMenu = MENU_MAIN;
            }
            else
            {
                switch (player.selectedMenuButton)
                    {
                        case 0:
                            
                            break;
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                    }
            }

            NF_UnloadTiledBg("MenuSettings");
            player.selectedMenuButton = 0;
            player.menuBackPressed = false;
            menuSettingsStage = 0;
            break;

        default:
            break;
    }
}

void Game::Menu_Play()
{
    switch (menuPlayStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/MenuPlay", "MenuPlay", 512, 256);
            NF_CreateTiledBg(1, 3, "MenuPlay");
            NF_ScrollBg(1, 3, menuX, 0);//Needs to get itself from offscreen to on-screen

            menuPlayStage++;
            player.selectedMenuButton = 0;

            break;
        case 1:
            menuX = menuX - menuScrollSpeed;
            if(menuX <= 0)
            {
                menuX = 0;
                menuPlayStage++;
                NF_ScrollBg(1, 3, menuX, 0);
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, 0);
            }
            break;
        case 2:
            NF_LoadSpriteGfx("Sprites/MenuSelector", 0, 64, 32);
            NF_LoadSpritePal("Sprites/MenuSelector", 0);
            NF_VramSpriteGfx(1, 0, 0, false);
            NF_VramSpritePal(1, 0, 0);

            NF_CreateSprite(1, 0, 0, 0, player.selectorX, player.selectorY);

            NF_UnloadSpriteGfx(0);
            NF_UnloadSpritePal(0);

            menuPlayStage++;
            break;
        case 3:
            NF_MoveSprite(1, 0, player.selectorX, player.selectorY);
            if (player.menuButtonPressed || player.menuBackPressed)
            {
                NF_FreeSpriteGfx(1, 0);
                menuPlayStage++;
            }
            break;
        case 4:
            menuX = menuX + menuScrollSpeed;
            if(menuX > 256)
            {
                menuPlayStage++;
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, menuY);
            }
            break;
        case 5:
            if (player.menuBackPressed)
            {
                currentMenu = MENU_MAIN;
            }
            else
            {
                switch (player.selectedMenuButton)
                    {
                        case 0:
                            
                            break;
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                    }
            }

            NF_UnloadTiledBg("MenuPlay");
            player.selectedMenuButton = 0;
            player.menuBackPressed = false;
            menuPlayStage = 0;
            break;

        default:
            break;
    }
}

void Game::Menu_Collection()
{       
    switch (menuCollectionStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/MenuCollection", "MenuCollection", 512, 256);
            NF_CreateTiledBg(1, 3, "MenuCollection");
            NF_ScrollBg(1, 3, menuX, 0);//Needs to get itself from offscreen to on-screen

            menuCollectionStage++;
            player.selectedMenuButton = 0;

            break;
        case 1:
            menuX = menuX - menuScrollSpeed;
            if(menuX <= 0)
            {
                menuX = 0;
                menuCollectionStage++;
                NF_ScrollBg(1, 3, menuX, 0);
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, 0);
            }
            break;
        case 2:
            NF_LoadSpriteGfx("Sprites/MenuSelector", 0, 64, 32);
            NF_LoadSpritePal("Sprites/MenuSelector", 0);
            NF_VramSpriteGfx(1, 0, 0, false);
            NF_VramSpritePal(1, 0, 0);

            NF_CreateSprite(1, 0, 0, 0, player.selectorX, player.selectorY);

            NF_UnloadSpriteGfx(0);
            NF_UnloadSpritePal(0);

            menuCollectionStage++;
            break;
        case 3:
            NF_MoveSprite(1, 0, player.selectorX, player.selectorY);
            if (player.menuButtonPressed || player.menuBackPressed)
            {
                NF_FreeSpriteGfx(1, 0);
                menuCollectionStage++;
            }
            break;
        case 4:
            menuX = menuX + menuScrollSpeed;
            if(menuX > 256)
            {
                menuCollectionStage++;
            }
            else
            {
                NF_ScrollBg(1, 3, menuX, menuY);
            }
            break;
        case 5:
            if (player.menuBackPressed)
            {
                currentMenu = MENU_MAIN;
            }
            else
            {
                switch (player.selectedMenuButton)
                    {
                        case 0:
                            
                            break;
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                    }
            }

            NF_UnloadTiledBg("MenuCollection");
            player.selectedMenuButton = 0;
            player.menuBackPressed = false;
            menuCollectionStage = 0;
            break;

        default:
            break;
    }
}

void Game::Menu_Shop()
{
    switch (menuShopStage)
    {
        case 0:
            NF_LoadTiledBg("Bg/exampleSky", "exampleSky", 256, 256);
            NF_CreateTiledBg(1, 3, "exampleSky");
            NF_UnloadTiledBg("exampleSky");
            menuShopStage++;
            break;
        case 1:
            if (player.menuButtonPressed)
            {
                
            }
            else if (player.menuBackPressed)
            {
                currentMenu = MENU_MAIN;
                player.menuButtonPressed = false;
                menuShopStage = 0;
            }
            break;
        default:
            break;
    }
}

void Game::Action_ShipBattle()
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