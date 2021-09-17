#pragma once
#include "Item.h"
class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item &item);
	void removeItem(int index);
	void debugPrint();
private:
	int inventoryCapacity;
	int numberOfItems;
	Item **itemArray;
	void expandInventory();
	void initializeInventory(const int from);
};

