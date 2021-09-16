#pragma once
#include <iostream>
#include <string>
using namespace std;
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	int getEnemyHP() { return enemyHP; }

	void setEnemyHP(int enemyHP) { this->enemyHP = enemyHP; }
private:
	int enemyHP;
};

