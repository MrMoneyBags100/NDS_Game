#include <game.h>



Game::Game()
{
}

void Game::Tick()
{
    frame++;
}

void Game::Update(bool debugging)
{
    if(debugging)
    {
        // consoleDemoInit();
        // consoleClear();
        // printf("\n\n\n\n\n\n\n\n\n\n\n    Getting Ready to Cook...\n");
    }
    else
    {
        return;
    }
}
void Game::StartMenuScreen(bool debugging)
{

}
void Game::StartGame1Screen(bool debugging)
{

}
void Game::StartGame2Screen(bool debugging)
{

}
void Game::StartMinigameScreen(bool debugging, int minigame)
{

}