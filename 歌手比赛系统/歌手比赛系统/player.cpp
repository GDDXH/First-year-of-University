#include "player.h"

Player::Player()
{
	playerNumber = 0;
	player_infomation.clear();
}

void Player::inputPlayerNumber(int n)
{
	playerNumber = n;
}

int Player::getPlayerNumber()
{
	return playerNumber;
}
