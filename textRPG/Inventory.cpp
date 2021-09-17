#include "Inventory.h"
Inventory::Inventory() {
	this->inventoryCapacity = 3;
	this->numberOfItems = 0;
	this->itemArray = new Item * [inventoryCapacity];
}
Inventory::~Inventory() {
	for (int i = 0; i < this->numberOfItems; i++) {
		delete this->itemArray[i];
	}
	delete[] itemArray;
}
void Inventory::debugPrint(){
	if (this->numberOfItems == 0) {
		std::cout << "Your inventory is empty" << std::endl;
	}
	else {
		for (int i = 0; i < this->numberOfItems; i++) {
			std::cout << this->itemArray[i]->getItemName() << std::endl;
			std::cout << this->itemArray[i]->getItemDescription() << std::endl<< std::endl;
		}
	}
}

void Inventory::addItem(const Item& item) {
	if (this->numberOfItems >= this->inventoryCapacity) {
		expandInventory();
	}
	this->itemArray[this->numberOfItems++] = new Item(item);
};
void Inventory::removeItem(int index) {};
void Inventory::expandInventory() 
{
	this->inventoryCapacity *= 2;
	Item** tempArray = new Item * [this->inventoryCapacity];
	for (int i = 0; i < this->numberOfItems; i++) {
		tempArray[i] = new Item(*this->itemArray[i]);
	}
	for (int i = 0; i < this->numberOfItems; i++) {
		delete this->itemArray[i];
	}
	delete[] this->itemArray;
	this->itemArray = tempArray;
	this->initializeInventory(this->numberOfItems);

};
void Inventory::initializeInventory(const int from) 
{
	for (int i = from; i < inventoryCapacity; i++) {
		this->itemArray[i] = nullptr;
	}
};