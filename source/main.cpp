#include <iostream>
#include <../include/game.h>
#include <../include/player.h>

Game game;

int main (int argc, char **argv)
{

    game.Init();

    while (1)
    {
        game.Tick();

        game.Update();

        swiWaitForVBlank();
    }
    return 0;
}