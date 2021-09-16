#pragma once
#include <iostream>
#include <string>
using namespace std;
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

private:
	int enemyHP;
	int enemyMaxHP;
	int enemyAttack;
};

