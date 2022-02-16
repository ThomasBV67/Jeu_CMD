#ifndef ENTITY_H
#define ENTITY_H

#include "Coordonnee.h"

#define EMPTY	0
#define PLAYER	1
#define ENEMY	2

class Entity
{
public:
	Entity();
	~Entity();

	int getType() { return type; };
	void setType(int nType) { type = nType; };

	virtual int getHealth() { 
		return 0; };

private:
	int type;
};

#endif
