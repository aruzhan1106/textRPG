#pragma once
#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;

class Game
{
public: 
	//Constructor and Destructor
	Game();
    virtual ~Game();

	bool getPlaying() const; //Getter for the field 'playing'
	void updateStats(); //Updates the character's attack power status in the menu
	void mainMenu();//Gets called repeatedly after each event, displays the main menu
	void initGame();//Prints the name of the game, the story, welcomes the player
	//and asks for the character's name
	void fight();//Initiates an enemy encounter
	void rest();//Restores the character's HP to full
	void explore();//Initiates either a fight or a discovery
	void find();//The character finds an item, gains EXP and gold
	bool isNameCorrect(string name);
private:
	int choice; //used in the main menu for deciding what the player will do next
	bool playing; //as long as it is equal to TRUE the game will be running
	int itemChoice;//used for deciding whether to pick up an item
	Character character; 
	Enemy enemy; 
	Inventory inventory;
};

