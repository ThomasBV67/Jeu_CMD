#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(int);
	~Player();

	virtual int getHealth() { return health; }
	void setHealth(int hp) { health = hp; }

private:
	int health;
};

#endif
