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
		std::cout << "INVENTORY" << std::endl;
		std::cout << "\n";
		for (int i = 0; i < this->numberOfItems; i++) {
			std::cout << this->itemArray[i]->getItemName() << std::endl;
			std::cout << "Adds " << this->itemArray[i]->getItemAttack() << " to your attack power"<<std::endl;
			std::cout << this->itemArray[i]->getItemDescription() << std::endl<< std::endl;
		}
		std::cout<<bestAttackItem();
	}
}

void Inventory::addItem(const Item& item) {
	this->itemArray[this->numberOfItems++] = new Item(item);
};
bool Inventory::isInventoryFull() {
	if (this->numberOfItems == this->inventoryCapacity) {
		return true;
	}
	else return false;
}
int Inventory::fetchItemAttack() {
	return this->itemArray[0]->getItemAttack();
}
int Inventory::bestAttackItem() {
	int indexOfBestWeapon = 0;
	int bestWeaponAttack = this->itemArray[0]->getItemAttack();
	if (this->numberOfItems > 1) {
		for (int i = 1; i < this->numberOfItems; i++) {
			if (this->itemArray[i]->getItemAttack() > bestWeaponAttack) {
				indexOfBestWeapon = i;
				bestWeaponAttack = this->itemArray[i]->getItemAttack();
			}
		}
	}
	return indexOfBestWeapon;
}