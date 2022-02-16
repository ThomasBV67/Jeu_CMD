#ifndef SPACEINVADER_H
#define SPACEINVADER_H

#include "Board.h"

class SpaceInvader
{
public:
	SpaceInvader();
	~SpaceInvader();

	bool addScore(int);
	int getScore();
	void setScore();

	int getLevel();
	int setLevel();


private:
	Board boardObj;
	int score = 0;
	int level = 1;
};

#endif