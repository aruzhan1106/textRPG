#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	Item();
	Item(std::string itemName, std::string itemDescription);
	std::string getItemName() const {
		return this->itemName;
	}
	std::string getItemDescription() const {
		return this->itemDescription;
	}
private:
	std::string itemName;
	std::string itemDescription;
};

