#include "Inventory.h"
Inventory::Inventory() { //Initializes the inventory
	this->inventoryCapacity = 3;
	this->numberOfItems = 0;
	this->itemArray = new Item * [inventoryCapacity];
}
Inventory::~Inventory() {
}
void Inventory::debugPrint(){ //Used in the main menu to display the inventory
	if (this->numberOfItems == 0) { //if the inventory is empty
		cout << "Your inventory is empty" << endl;
	}
	else { //if it is not empty
		cout << "INVENTORY" << endl;
		cout << "\n";
		for (int i = 0; i < this->numberOfItems; i++) {
			cout << this->itemArray[i]->getItemName() << endl;
			cout << "Adds " << this->itemArray[i]->getItemAttack() << " to your attack power"<<endl;
			cout << this->itemArray[i]->getItemDescription() << endl<< endl;
		}
		cout << "EQUIPPED ITEM" << endl;
		cout << this->itemArray[bestAttackItem()]->getItemName() << endl;
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
int Inventory::fetchItemAttack(int index) {
	return this->itemArray[index]->getItemAttack();
}
int Inventory::bestAttackItem() {//finds out what the best item is and returns its index
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