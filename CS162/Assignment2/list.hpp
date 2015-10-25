#ifndef LIST_HPP
#define LIST_HPP
#include <vector>
#include "item.hpp"

class List{
	private:
		std::vector<Item *> shoppingList;
		unsigned int listLength;
	public:
		List();
		void addItem(std::string nameInc, unsigned int quantityInc,std::string unitInc, double unitPriceInc);
		void printList();
};

#endif // LIST_HPP
