#pragma once
#include "Item.h"
class Inventory
{
public:
	Inventory();
	virtual ~Inventory();
	void addItem(const Item &item);
	void removeItem(int index);
	inline void debugPrint() const {
		for (size_t i = 0; i < this->numberOfItems; i++) {
			std::cout << this->itemArray[i]->debugPrint() << std::endl;
		}
	}
private:
	int invertoryCapacity;
	int numberOfItems;
	Item **itemArray;
	void expandInventory();
	void initializeInventory(const int from);
};

