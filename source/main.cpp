#include <iostream>
#include <../include/game.h>
#include <../include/player.h>


int main (int argc, char **argv)
{
    Game game;

    while (1)
    {
        game.Tick();

        game.Update();

        swiWaitForVBlank();
    }
    return 0;
}