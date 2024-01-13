#include <../include/game.h>



Game::Game()
{

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

    if(debugging)
    {
        if (frame < 50)
        {
            consoleDemoInit();
        }
        consoleClear();
        iprintf("\x1b[7;1HFrames: %i", frame);
        iprintf("\x1b[8;1HState: %i", currentState);
    }

    switch (currentState) //Check current STATE
    {
        case STATE_MENU:
            if (isStarting)
            {
                //Opening sequence
                if(isStartingFinish)
                {
                    currentMenu = 0;
                    isStarting = false;
                }
            }
            switch (currentMenu) //Check current MENU
            {
                case MENU_MAIN:
                    break;
                case MENU_SETTINGS:
                    break;
                case MENU_PLAY:
                    break;
                case MENU_SHOP:
                    break;
                default:
                    break;
            }
            break;
        case STATE_ACTION:
            switch (currentAction) //Check current ACTION
            {
                case ACTION_SHIP_BATTLE:
                    break;
                case ACTION_MELEE_BATTLE:
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

void Game::StartMenuScreen()
{                             

}

void Game::StartGame1Screen()
{

}

void Game::StartGame2Screen()
{

}

void Game::StartMinigameScreen(int minigame)
{

}