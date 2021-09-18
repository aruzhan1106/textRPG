#include "Item.h"
Item::Item() {
	this->itemName = "None";
	this->itemDescription = "No description";
	this->itemAttack = 0;
}
Item::Item(std::string itemName, int itemAttack, std::string itemDescription) {
	this->itemName = itemName;
	this->itemAttack = itemAttack;;
	this->itemDescription = itemDescription;
}
