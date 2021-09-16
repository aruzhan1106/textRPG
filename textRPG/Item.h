#pragma once
#include <iostream>
#include <string>
class Item
{
public:
	Item();
	virtual ~Item();
	inline std::string debugPrint() const {
		return this->itemName;
	}
private:
	std::string itemName;
	int itemDamage;
};

