// Jeu_CMD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    srand(time(0));

    Board waterBoarding = Board();

    waterBoarding[0][5] = Player();
    for (int i = 0; i < 10; i++)
    {
        waterBoarding[3+rand() % (X_SIZE-3)][rand() % Y_SIZE] = Enemy();
    }

    for(int i = 0; i < X_SIZE; i++)
    {
        for (int j = 0; j < Y_SIZE; j++)
        {
            cout << waterBoarding[i][j].getType() << " ";
        }
        cout << endl;
    }
}
