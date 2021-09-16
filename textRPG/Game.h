#pragma once
#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;

class Game
{
public: 
	bool getPlaying() const;

	Game();
    virtual ~Game();
	void mainMenu();
	void initGame();

private:
	int choice;
	bool playing;

	Character character;
	Enemy enemy;
};

