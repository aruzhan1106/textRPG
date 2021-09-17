#include "Character.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>   
Character::Character(){
	this->name = "Player";
	this->maxHP = 0;
	this->HP = 0;
	this->attack = 0;
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->gold = 0;
}
Character::~Character(){}
void Character::initialize(string name){
	this->name = name;
	this->maxHP = 30;
	this->HP = 10;
	this->attack = 7;
	this->level = 1;
	this->exp = 0;
	this->expNext = 100;
	this->gold = 0;
}
void Character::printStats() const {
	cout << "CHARACTER STATS" << endl<<endl;
	cout<<"Name: "<< this->name << endl;
	cout<<"HP: "<<this->HP<<" / "<<this->maxHP<<endl;
	cout << "Level: " << this->level << endl;
	cout<<"Experience: "<<this->exp<<" / "<<this->expNext<< endl;
	cout << "Attack: " << this->attack << endl;
	cout << "Gold: " << this->gold << endl << endl;
};
void Character::levelUp() {
	if (this->exp >= this->expNext) {
		this->exp -= this->expNext;
		this->level++;
		this->expNext = this->level * 100;
	}
}
