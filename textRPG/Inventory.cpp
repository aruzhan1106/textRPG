#include "Inventory.h"
Inventory::Inventory() {
	this->invertoryCapacity = 5;
	this->numberOfItems = 0;
	this->itemArray = new Item * [invertoryCapacity];
}
Inventory::~Inventory() {
	for (size_t i = 0; i < this->numberOfItems; i++) {
		delete this->itemArray[i];
	}
	delete[] itemArray;
}
void Inventory::addItem(const Item& item) {
	if (this->numberOfItems >= this->invertoryCapacity) {
		expandInventory();
	}
	this->itemArray[this->numberOfItems++] = new Item(item);
};
void Inventory::removeItem(int index) {};
void Inventory::expandInventory() 
{
	this->invertoryCapacity *= 2;
	Item** tempArray = new Item * [this->invertoryCapacity];
	for (size_t i = 0; i < this->numberOfItems; i++) {
		tempArray[i] = new Item(*this->itemArray[i]);
	}
	for (size_t i = 0; i < this->numberOfItems; i++) {
		delete this->itemArray[i];
	}
	delete[] this->itemArray;
	this->itemArray = tempArray;
	this->initializeInventory(this->numberOfItems);

};
void Inventory::initializeInventory(const int from) 
{
	for (size_t i = from; i < invertoryCapacity; i++) {
		this->itemArray[i] = nullptr;
	}
};