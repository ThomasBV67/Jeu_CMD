#ifndef BOARD_H
#define BOARD_H

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "coordonnee.h"
#include <iostream>

#define X_SIZE 11
#define Y_SIZE 11

#define UP		0
#define RIGHT	1
#define DOWN	2
#define LEFT	3

using namespace std;

class Board
{
public:
	Board();
	~Board();

	void setPlayerXY(Coordonnee coor) 
	{ 
		playerXY.x = coor.x; 
		playerXY.y = coor.y; 
	}
	Coordonnee getPlayerXY() { return playerXY; };

	void printBoard();
	void movePlayer(int);
	void moveEnemies(int);
	void dropEnemiesOnce();

	Entity* getPlayerInfo();

	Entity** operator[](int);
	
private:
	Entity*** board;
	Coordonnee playerXY;
};

#endif