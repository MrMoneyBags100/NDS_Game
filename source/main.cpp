#include <iostream>
#include <../include/game.h>
#include <../include/player.h>

Game game;

int main ()
{

    game.StartMenuScreen();

    while (1)
    {
        game.Tick();

        game.Update();

        swiWaitForVBlank();
    }
    return 0;
}