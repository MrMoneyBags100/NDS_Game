#include <../include/player.h>



Player::Player()
{

}

void Player::HandleInput(int keys)
{
    //TEST MOVEMENT | DELETEME
    if (keys & KEY_UP)
        y--;
    if (keys & KEY_DOWN)
        y++;
    if (keys & KEY_LEFT)
        x--;
    if (keys & KEY_RIGHT)
        x++;

    if (x < 0)
        x = 0;
    if (x > 767)
        x = 767;
    if (y < 0)
        y = 0;
    if (y > 511)
        y = 511;
}

void Player::TranslatePlayer(int x, int y)
{

}

void Player::UpdatePlayer()
{

}