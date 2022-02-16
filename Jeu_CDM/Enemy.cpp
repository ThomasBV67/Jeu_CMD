#include "Enemy.h"

Enemy::Enemy()
{
	setType(ENEMY);
	health = 1;
	pointValue = 1;
}

Enemy::~Enemy()
{
}

/* This function reduces the health of the enemy by an amount taken as a
parameter. The function returns true if the health drops below zero and
false if the enemy still has hp left */
bool Enemy::reduceHealth(int damage)
{
	health -= damage;
	if (health > 0)
	{
		return false;
	}
	return true;
}

