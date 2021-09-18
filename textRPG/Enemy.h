#pragma once
#include <iostream>
using namespace std;
class Enemy
{
public:
	//Constructor and Destructor
	Enemy();
	virtual ~Enemy();

	//Getter and Setter
	int getEnemyHP() { return this->enemyHP; }
	void setEnemyHP(int enemyHP) { this->enemyHP = enemyHP; }
private:
	int enemyHP;
};