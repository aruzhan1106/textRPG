#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	Item();
	virtual~Item();
	Item(std::string itemName, int itemAttack, std::string itemDescription);
	std::string getItemName() const{
		return this->itemName;
	}
	std::string getItemDescription() const {
		return this->itemDescription;
	}
	int getItemAttack() const {
		return this->itemAttack;
	}
private:
	std::string itemName;
	std::string itemDescription;
	int itemAttack;
};

