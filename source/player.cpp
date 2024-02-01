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
                    case 0://Start Menu
                        if (keysHeld) menuButtonPressed = true;
                        break;
                    case 1://Main Menu
                        if(keysDown & KEY_DOWN) selectedMenuButton++;
                        if(keysDown & KEY_UP) selectedMenuButton--;
                        if (selectedMenuButton > 2) selectedMenuButton = 0;
                        if (selectedMenuButton < 0) selectedMenuButton = 2;

                        selectorX = 115;
                        switch (selectedMenuButton)
                        {
                            case 0://Play Button
                                selectorY = 15;
                                break;
                            case 1://Collection Button
                                selectorY = 80;
                                break;
                            case 2://Settings Button
                                selectorY = 145;
                                break;
                        }
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 2://Settings Menu
                        if(keysDown & KEY_DOWN) selectedMenuButton++;
                        if(keysDown & KEY_UP) selectedMenuButton--;
                        if (selectedMenuButton > 2) selectedMenuButton = 0;
                        if (selectedMenuButton < 0) selectedMenuButton = 2;

                        selectorX = 115;
                        switch (selectedMenuButton)
                        {
                            case 0://??? Button
                                selectorY = 15;
                                break;
                            case 1://??? Button
                                selectorY = 80;
                                break;
                            case 2://??? Button
                                selectorY = 145;
                                break;
                        }
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 3://Play Menu
                        if(keysDown & KEY_DOWN) selectedMenuButton++;
                        if(keysDown & KEY_UP) selectedMenuButton--;
                        if (selectedMenuButton > 2) selectedMenuButton = 0;
                        if (selectedMenuButton < 0) selectedMenuButton = 2;

                        selectorX = 115;
                        switch (selectedMenuButton)
                        {
                            case 0://Story Button
                                selectorY = 15;
                                break;
                            case 1://PvE Button
                                selectorY = 80;
                                break;
                            case 2://PvP Button
                                selectorY = 145;
                                break;
                        }
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 4://Shop Menu
                        if (keysDown & KEY_A) menuButtonPressed = true;
                        if (keysDown & KEY_B) menuBackPressed = true;

                        break;

                    case 5://Collection Menu
                        if(keysDown & KEY_DOWN) selectedMenuButton++;
                        if(keysDown & KEY_UP) selectedMenuButton--;
                        if (selectedMenuButton > 2) selectedMenuButton = 0;
                        if (selectedMenuButton < 0) selectedMenuButton = 2;

                        selectorX = 115;
                        switch (selectedMenuButton)
                        {
                            case 0://Wardrobe Button
                                selectorY = 15;
                                break;
                            case 1://Shop Button
                                selectorY = 80;
                                break;
                            case 2://Treasury Button
                                selectorY = 145;
                                break;
                        }
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
    // menuBackPressed = false;
}