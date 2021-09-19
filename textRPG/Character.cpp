#include "Character.h"
#include "Enemy.h"

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
void Character::initialize(string name){ //When this function is called
	this->name = name; //the playable character is created with these stats
	this->maxHP = 30;
	this->HP = 10;
	this->attack = 7;
	this->level = 1;
	this->exp = 0;
	this->expNext = 100;
	this->gold = 0;
}
void Character::printStats() const { //Used for displaying information 
	cout << "CHARACTER STATS" << endl<<endl;//about the character
	cout<<"Name: "<< this->name << endl;
	cout<<"HP: "<<this->HP<<" / "<<this->maxHP<<endl;
	cout << "Level: " << this->level << endl;
	cout<<"Experience: "<<this->exp<<" / "<<this->expNext<< endl;
	cout << "Attack: " << this->attack << endl;
	cout << "Gold: " << this->gold << endl << endl;
};
void Character::levelUp() { //Increments the character's level and HP
	if (this->exp >= this->expNext) {//when a certain amount of EXP
		this->exp -= this->expNext; //is reached
		this->level++;
		this->maxHP += 5;
		this->expNext = this->level * 100;
	}
}
int Character::getBaseAttack() { //Returns the character's base 
	return 7;                    //attack power, which is seven
}
