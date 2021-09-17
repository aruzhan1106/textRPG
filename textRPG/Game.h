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
	void fight();
	void rest();
	void explore();
	void find();

private:
	int choice;
	bool playing;

	Character character;
	Enemy enemy;
	Inventory inventory;
};

