#include <../include/player.h>



Player::Player()
{
    // currentCharacter = GETCHARARCTERFROMSAVE();
}

void Player::HandleInput(int keys)
{
    if(keys & KEY_LEFT) selectorX--;
    if(keys & KEY_RIGHT) selectorX++;
    if(keys & KEY_DOWN) selectorY--;
    if(keys & KEY_UP) selectorY++;
}

void Player::TranslatePlayer(int x, int y)
{

}

void Player::UpdatePlayer()
{

}