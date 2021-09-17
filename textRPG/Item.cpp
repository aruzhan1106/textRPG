#include "Item.h"
Item::Item() {
	this->itemName = "None";
	this->itemDescription = "No description";
}
Item::Item(std::string itemName, std::string itemDescription) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
}
