#include <../include/player.h>



Player::Player()
{
    //RETRIEVE RELEVANT PLAYER SAVE DATA
}

void Player::HandleInput(int keysHeld, int keysDown, int frame, int currentState, int currentMenu, int currentAction, int currentMinigame)
{
    switch (currentState)
    {
        case 0://Menu
        if (frame >= (selectorLastMoved + selectorCooldown))
            {
                switch (currentMenu)
                {
                    case 0://Start
                        if (keysHeld) menuButtonPressed = true;
                        break;
                    case 1://Main
                        if(keysDown & KEY_DOWN) selectedMenuButton++;
                        if(keysDown & KEY_UP) selectedMenuButton--;
                        if (selectedMenuButton > 3) selectedMenuButton = 0;
                        if (selectedMenuButton < 0) selectedMenuButton = 3;

                        selectorX = 120;
                        switch (selectedMenuButton)
                        {
                            case 0://Play
                                selectorY = 9;
                                break;
                            case 1://Shop
                                selectorY = 57;
                                break;
                            case 2://Collection
                                selectorY = 105;
                                break;
                            case 3://Settings
                                selectorY = 153;
                                break;
                        }
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 2://Settings
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 3://Play
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;
                    case 4://Shop
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;
                    case 5://Collection
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;
                    default:
                        break;
                    break;
                    selectorLastMoved = frame;
                }
            }

        case 1://Action
            break;

        default:
            break;
    }
}

void Player::ResetInput()
{
    menuButtonPressed = false;
    menuBackPressed = false;
}