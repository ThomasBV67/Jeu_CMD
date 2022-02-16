#include "Entity.h"

#define X_SIZE 10
#define Y_SIZE 10

class Board
{
public:
	Board();
	~Board();

private:
	Entity board[X_SIZE][Y_SIZE];
};