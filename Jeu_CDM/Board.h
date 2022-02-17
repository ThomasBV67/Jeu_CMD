#ifndef BOARD_H
#define BOARD_H

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "coordonnee.h"
#include "Level.h"
#include <iostream>
#include <vector>

// define for the size of the playing field
#define X_SIZE 11
#define Y_SIZE 11
#define PROTECTED_LINES 6

#define MAX_HEALTH	10

// define for movement directions
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

	void initBoard(int);

	void printBoard();
	void movePlayer(int);
	void moveEnemies(int);
	void dropEnemiesOnce();

	void playerShoot();

	void nextLevel();
	void loseHP(int);
	void gameover();

	Level getCurrentLevel() { return levels[currentLevel]; };
	bool getGameState() { return gameStarted; };
	void printHealth();

	Entity* getPlayerInfo();

	Entity** operator[](int);
	
private:
	Entity*** board;
	Coordonnee playerXY;
	int currentLevel = 0;
	vector<Level> levels;
	int enemiesLeft = 0;
	int score = 0;
	bool gameStarted = false;
	Player player;
};

#endif