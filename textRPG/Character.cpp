#include "Character.h"
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
	this->attack = 1;
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
void Character::rest() {
	this->HP = this->maxHP;
	cout<<endl<<endl<<this->name << " decides to lay down for a bit, and take a nap. " << endl;
	cout << this->name << "'s HP is fully restored" << endl<<endl;
}
void Character::explore() {
	cout << endl << endl << this->name << " decides to look around" << endl;
	srand(time(NULL));
	int event;
	event = rand() % 2 + 0;
	if (event == 0) {
		find();
	}
	else if (1<=event<=2) {
		fight();
	}
}
void Character::find() {
	cout <<this->name << " finds a gold coin. +1 GOLD" << endl;
	cout << "+10 EXP" << endl<<endl;
	this->gold++;
	this->exp += 10;
};
void Character::fight() {
	cout << this->name << " encounters an enemy. It's a zombie! Time to fight!" << endl;

};