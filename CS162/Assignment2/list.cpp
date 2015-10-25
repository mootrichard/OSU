#include "list.hpp"

List::List(){};

void List::addItem(Item* newItem){
	shoppingList.push_back(*newItem);
}

void List::printItems(){
	for(unsigned int i=0; i < shoppingList.size(); i++){
		std::cout << shoppingList[i].getQuantity() << " " ;
		std::cout << shoppingList[i].getUnit() <<  " of " ;
		std::cout << shoppingList[i].getName() << " for " ;
		std::cout << shoppingList[i].getUnitPrice() << " each" << "\n";
	}
}