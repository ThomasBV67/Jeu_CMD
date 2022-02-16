#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	bool reduceHealth(int);

	void setPointValue(int pts) { pointValue = pts; }
	int getPointValue() { return pointValue; }

private:
	int health;
	int pointValue;
};

#endif