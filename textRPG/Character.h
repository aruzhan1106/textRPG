#pragma once
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

class Character
{
public: 
	Character();
	virtual ~Character();

	void initialize(string name);
	void printStats() const;
	void levelUp();

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

