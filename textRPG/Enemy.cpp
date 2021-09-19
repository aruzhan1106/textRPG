#include "Enemy.h"
Enemy::Enemy() {
	srand((unsigned int)time(NULL));
	this->enemyHP = rand()%20+10; //Enemy's health is a random number
};
Enemy::~Enemy() {
};