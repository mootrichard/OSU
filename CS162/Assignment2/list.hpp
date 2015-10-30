// Author:			Richard Moot
// Date: 			10-25-2015
// Description:	This is the header file for the List class
// The List class is intended to manage a collection of Item objects and allow
// a user to add, remove, or display any of their items.

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
		void removeItem(unsigned int itemToRemove);
		void printItems();
};

#endif // LIST_HPP
