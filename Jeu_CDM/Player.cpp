#include "Player.h"

Player::Player()
{
	setType(PLAYER);
	health = 1;
}

Player::Player(int hp)
{
	setType(PLAYER);
	health = hp;
}

Player::~Player()
{
}