#pragma once
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

class Character
{
public: 
	//Constructors and Destructor
	Character();
	virtual ~Character();

	void initialize(string name); //Initializes the character
	void printStats() const; //Prints stats such as HP, EXP, level, attack power
	void levelUp(); //This function gets called after exploring to check if
	//the character can level up
	int getBaseAttack(); //Used for getting the character's base attack

	//Getters and Setters for the private fields
	inline const string& getName() const { return this->name; }
	inline const int& getMaxHP() const { return this->maxHP; }
	inline const int& getHP() const { return this->HP; }
	inline const int& getAttack() const { return this->attack; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getGold() const { return this->gold; }

	void setHP(int HP) { this->HP = HP; }
	void setGold(int gold) { this->gold = gold; }
	void setExp(int exp) { this->exp = exp; }
	void setAttack(int attack) { this->attack = attack; }
private:
	string name; 
	int maxHP;
	int HP;
	int attack;
	int level;
	int exp;
	int expNext;
	int gold;
};

