#pragma once
#include "Item.h"
class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item &item);
	void debugPrint();
	int fetchItemAttack(int index);
	bool isInventoryFull();
	int bestAttackItem();
private:
	int inventoryCapacity;
	int numberOfItems;
	Item **itemArray;
};

