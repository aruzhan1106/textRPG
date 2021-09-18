#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	//Constructors and Destructor
	//One constructor is empty, the other one takes in 3 parameters
	Item();
	virtual~Item();
	Item(std::string itemName, int itemAttack, std::string itemDescription);

	//Getters for the private fields
	std::string getItemName() const{return this->itemName;}
	std::string getItemDescription() const {return this->itemDescription;}
	int getItemAttack() const {	return this->itemAttack;}
private:
	std::string itemName; //Private fields for an item's name
	std::string itemDescription; //item's decription
	int itemAttack;              //item's atttack power
};

