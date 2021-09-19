#pragma once
#include "Item.h"
using namespace std;
class Inventory
{
public:
	//Constructor and Destructor
	Inventory();
	virtual ~Inventory();

	void addItem(const Item &item); //Adds an item to the inventory
	void debugPrint(); //prints item's name, description, attack power
	int fetchItemAttack(int index); //gets an item's attack power using its index
	bool isInventoryFull(); //checks whether the inventory is full
	int bestAttackItem(); //determines which item has the largest attack power
private:
	int inventoryCapacity; //how many items can the inventory fit
	int numberOfItems; //how many items are in the inventory right now
	Item **itemArray; //array that holds the items
};

