#ifndef LIST_HPP
#define LIST_HPP
#include <vector>
#include <iostream>
#include "item.hpp"

class List{
	private:
		std::vector<Item> shoppingList;
		unsigned int listLength;
	public:
		List();
		void addItem(Item* newItem);
		void printItems();
};

#endif // LIST_HPP
