// Jeu_CMD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

#include "Board.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;

int main()
{
    string input;
    Coordonnee startingCoor;
    Entity* tempPlay;
    startingCoor.x = 5;
    startingCoor.y = 0;


    std::cout << "Hello World!\n";

    srand(time(0));

    Board waterBoarding = Board();

    waterBoarding[5][0] = new Player(10);
    waterBoarding.setPlayerXY(startingCoor);


    for (int i = 0; i < 10; i++)
    {
        waterBoarding[rand() % X_SIZE][3+rand() % (Y_SIZE-3)] = new Enemy();
    }

    waterBoarding.printBoard();

    while (input != "quit")
    {
        cin >> input;

        if (input == "up")
        {
            waterBoarding.movePlayer(UP);
        }
        else if (input == "down")
        {
            waterBoarding.movePlayer(DOWN);
        }
        else if (input == "right")
        {
            waterBoarding.movePlayer(RIGHT);
        }
        else if (input == "left")
        {
            waterBoarding.movePlayer(LEFT);
        }
        else if (input == "hp")
        {
            tempPlay = waterBoarding.getPlayerInfo();
            cout << tempPlay->getHealth() << endl;
        }

        waterBoarding.printBoard();
    }
}
