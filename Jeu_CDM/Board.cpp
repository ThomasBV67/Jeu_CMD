#include "Board.h"

//Initialisation of all objects in the board
Board::Board()
{
	Level tempLevel;

	player.setHealth(10);

	// Initialisation of the board content
	board = new Entity ** [X_SIZE]();
	for (int i = 0; i < X_SIZE; i++)
	{
		board[i] = new Entity*[Y_SIZE]();
		for (int j = 0; j < X_SIZE; j++)
		{
			board[i][j] = new Entity();
		}
	}

	// Generates the game parameters for the levels
	for (int i = 0; i < 10; i++)
	{
		tempLevel.numberEnemies = i * 5 + 5;
		tempLevel.timeBeforeDrop = 5000 - i * 500;
		tempLevel.pointMultiplier = 1.0 + i * 0.25;
		levels.push_back(tempLevel);
	}
	
}

Board::~Board()
{
	for (int i = 0; i < X_SIZE; ++i) 
	{
		delete[] board[i];
	}
	delete[] board;
}

/* 
* This function generates the enemies of the level
* based on the given parameter and places the player
* at his starting point 
*/
void Board::initBoard(int nbEnemies)
{
	int randX, randY;
	srand(time(0));

	playerXY.x = X_SIZE / 2;
	playerXY.y = 0;

	for (int i = 0; i < X_SIZE; i++)
	{
		board[i][0] = new Entity();
	}

	board[playerXY.x][playerXY.y] = new Player(10);

	for (int i = 0; i < nbEnemies; i++)
	{
		randX = rand() % X_SIZE;
		randY = PROTECTED_LINES + rand() % (Y_SIZE - PROTECTED_LINES);
		while (board[randX][randY]->getType() == ENEMY)
		{
			randX = rand() % X_SIZE;
			randY = PROTECTED_LINES + rand() % (Y_SIZE - PROTECTED_LINES);
		}
		board[randX][randY] = new Enemy();
	}
	enemiesLeft = nbEnemies;

	printBoard();

}

/*
* This function prints the board in the console
*/
void Board::printBoard()
{
	char temp = ' ';
	system("CLS");// Clear the console
	for (int i = Y_SIZE-1; i >= 0; i--)
	{
		for (int j = 0; j < X_SIZE; j++)
		{
			switch (board[j][i]->getType())
			{
			case PLAYER:
				temp = 94;
				break;

			case ENEMY:
				temp = 126;
				break;

			default:
				temp = ' ';
				break;
			}
			cout << temp << " ";
		}
		cout << endl;
	}
	if (enemiesLeft > 0)
	{
		printHealth();
		cout << "LEVEL " << currentLevel + 1 << endl;
		cout << "SCORE : " << score << endl;
	}
	else
	{
		cout << "LEVEL " << currentLevel + 1 << " COMPLETE" << endl;
		cout << "POINTS : " << score << endl << endl;

		cout << "NEXT LEVEL? PRESS 0" << endl;
	}
	
}


/*
* This function moves the player 1 step in the given direction.
*/
void Board::movePlayer(int direction)
{
	Entity* tempPlayer = board[playerXY.x][playerXY.y];
	board[playerXY.x][playerXY.y] = new Entity();

	switch (direction)
	{
	case UP:
		if (playerXY.y < Y_SIZE - 1)
		{
			playerXY.y++;
		}
		break;

	case DOWN:
		if (playerXY.y > 0)
		{
			playerXY.y--;
		}
		break;

	case RIGHT:
		if (playerXY.x < X_SIZE - 1)
		{
			playerXY.x++;
		}
		break;

	case LEFT:
		if (playerXY.x > 0)
		{
			playerXY.x--;
		}
		break;

	default:
		break;
	}
	board[playerXY.x][playerXY.y] = tempPlayer;
	printBoard();
}

void Board::moveEnemies(int direction)
{
	for (int i = 0; i < X_SIZE; i++)
	{
		for (int j = 0; j < Y_SIZE; j++)
		{

		}
	}
}

void Board::dropEnemiesOnce()
{
	Entity* tempBoard [X_SIZE][Y_SIZE];
	
	for (int i = 0; i < X_SIZE; i++)
	{
		for (int j = 0; j < Y_SIZE; j++)
		{
			tempBoard[j][i] = board[j][i];
		}
	}
	
	for (int i = 1; i < Y_SIZE; i++)
	{
		for (int j = 0; j < X_SIZE; j++)
		{
			if (tempBoard[j][i]->getType() == ENEMY)
			{
				board[j][i - 1] = tempBoard[j][i];
				board[j][i] = new Entity();
			}
		}
	}
	for (int i = 0; i < X_SIZE; i++)
	{
		if (board[i][0]->getType() == ENEMY)
		{
			board[i][0] = new Entity();
			loseHP(1);
			enemiesLeft--;
		}
	}
	printBoard();
}

void Board::playerShoot()
{
	bool hit = false;
	int yValue = 0;
	while (hit == false && yValue < Y_SIZE)
	{
		if (board[playerXY.x][yValue]->getType() == ENEMY)
		{
			hit = true;
			score += 1 * levels[currentLevel].pointMultiplier;
			enemiesLeft--;
			board[playerXY.x][yValue] = new Entity();
		}
		yValue++;
	}
	printBoard();

	
}

void Board::nextLevel()
{
	if (enemiesLeft == 0)
	{
		currentLevel++;
		initBoard(levels[currentLevel].numberEnemies);
	}
	
	
}

void Board::loseHP(int damage)
{
	player.setHealth(player.getHealth() - damage);
	if (player.getHealth() <= 0)
	{
		gameover();
	}
}

void Board::gameover()
{
	score = 0;
	//initBoard();
}


void Board::printHealth()
{
	cout << "HEALTH : ";
	for (int i = 0; i < MAX_HEALTH; i++)
	{
		if (player.getHealth() > i)
		{
			cout << "O ";
		}
		else
		{
			cout << "X ";
		}
	}
	cout << endl;
}

Entity* Board::getPlayerInfo()
{
	return board[playerXY.x][playerXY.y];
}

Entity** Board::operator[](int index)
{
	return board[index];
}
