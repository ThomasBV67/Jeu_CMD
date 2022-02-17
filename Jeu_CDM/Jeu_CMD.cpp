// Jeu_CMD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "Board.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include <conio.h>

using namespace std;

int timeToSleep = 5000;
bool programDone = false;

void timeToMove(bool* move);
void waitForInput(string* text);

int main()
{
    string input; // temp var to get text inputs
    bool move = false;

    Entity* tempPlay;

    Board waterBoarding = Board();

    waterBoarding.initBoard(5);

    thread moveThread(timeToMove,&move);
    thread inputThread(waitForInput, &input);

    while (input != "q")
    {
        if (move)
        {
            waterBoarding.dropEnemiesOnce();
            move = false;
        }

        if (input == "w")
        {
            waterBoarding.movePlayer(UP);
        }
        else if (input == "s")
        {
            waterBoarding.movePlayer(DOWN);
        }
        else if (input == "d")
        {
            waterBoarding.movePlayer(RIGHT);
        }
        else if (input == "a")
        {
            waterBoarding.movePlayer(LEFT);
        }
        else if (input == "h")
        {
            tempPlay = waterBoarding.getPlayerInfo();
            cout << tempPlay->getHealth() << endl;
        }
        else if (input == "j")
        {
            waterBoarding.dropEnemiesOnce();
        }
        else if (input == "e")
        {
            waterBoarding.playerShoot();
        }
        else if (input == "0")
        {
            waterBoarding.nextLevel();
            timeToSleep = waterBoarding.getCurrentLevel().timeBeforeDrop;
        }
        else if (input == "r")
        {
            if (!waterBoarding.getGameState())
            {

            }
        }
        input = "";
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    programDone = true;

    moveThread.join();
    inputThread.join();
}

void timeToMove(bool* move)
{
    while (!programDone)
    {
        this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));
        *move = true;
    }
}

void waitForInput(string* text)
{
    while (!programDone)
    {
        if (_kbhit())
        {
            *text = _getch();
        }
    }
}