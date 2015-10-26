// Author:			Richard Moot
// Date: 			10-25-2015
// Description:	This is the implementation file for the List class
// Each function contains an explanation at the top for an overview with 
// comments at each stage to explain the logic or purpose of that statement.
// The List class is intended to manage a collection of Item objects and allow
// a user to add, remove, or display any of their items.

#include "list.hpp"

List::List(){};


// This function adds items to the list, but will make sure that an item is not already there first,
// otherwise it will ask to update the quantity if the user desires
void List::addItem(Item* newItem){
	if(shoppingList.size() == 0){ // Nothing is on the list, so we can skip checking for anything and just add the new item
	shoppingList.push_back(*newItem);
	std::cout << "\t" << newItem->getName() << " has been added to the list\n"; // Displaying confirmation to the user that their item has been added to the list
	}
	else{
		for(unsigned int i = 0; i < shoppingList.size(); i++){
			if(shoppingList[i] == newItem){ // Using overloaded operator to compare the the curren item to the new item (only comparing the name of the items)
				std::cout << shoppingList[i].getName() <<" is already on the list!\n"; // Notifying the user that thier item is actually already on the list
				std::cout << "Would you like to update the quantity? (1:Yes, 2:No; Default is No): "; // Giving the option to update the quantity, but defaulting to No
				unsigned int updateChoice = 2;
				std::cin >> updateChoice;
				if(updateChoice == 1){
					std::cout << "New quantity: ";
					unsigned int newQuant;
					std::cin >> newQuant;
					shoppingList[i].setQuantity(newQuant);
					return; // Exiting the loop/function since we don't want to re-add the item and just wanted to update the quanity of the existing item
				}
				else{
					return; // No need to do anything else, we don't want duplicates on the list so we will exit the function
				}
			}
			else{
				// Do nothing since we'll add the new item outside of the loop
			}
		}
		// We should have a unique new item at this point, so lets add it
		shoppingList.push_back(*newItem);
		std::cout << "\t" << newItem->getName() << " has been added to the list\n"; // Confirming item has been added to the user
	}
}


// This is what we use to remove an item from the list
void List::removeItem(unsigned int itemToRemove){
	if(shoppingList.size() == 0){ // List is empty, better avoid trying to remove anything and start over
		std::cout << "\n There isn't anything to remove!" << std::endl;
		return;
	}
	else if(itemToRemove <= 0){ // Looks like they made an invalid choice, going to return to start over
		std::cout << "\n This is an invalid selection!" << std::endl;
		return;
	}
	else if(itemToRemove > (shoppingList.size() + 1)){ // Looks like they made an invalid choice, going to return to start over
		std::cout << "\n This is an invalid selection!" << std::endl;
		return;
	}
	else{ // Yay! A valid selection, lets erase that from the list
		itemToRemove--;
		shoppingList.erase(shoppingList.begin() + itemToRemove);
	}
}

// This is our function that lets us print everything that is in the list into the console
// Basic display format for display is:
// QUANTITY UNIT of NAME for $PRICE per UNIT costs EXTENDEDPRICE 
void List::printItems(){
	double totalListCost = 0; // Initializing the list cost (starting at 0 since we could have an empty list)
	std::cout << "\n" << "\t Current List\n";
	for(unsigned int i=0; i < shoppingList.size(); i++){
		std::cout << "#" << i+1 << ". "; // Increasing index by 1 to make list more intuitive
		std::cout << shoppingList[i].getQuantity() << " " ;
		std::cout << shoppingList[i].getUnit() <<  " of " ;
		std::cout << shoppingList[i].getName() << " for $" ;
		std::cout << shoppingList[i].getUnitPrice() << " per ";
		std::cout << shoppingList[i].getUnit() << " costs $";
		std::cout << shoppingList[i].getExtendedPrice() << "\n";
		totalListCost += shoppingList[i].getExtendedPrice(); // Adding extended price to total cost for later
	}
	std::cout << "\n";
	std::cout << "Your total list cost is $" << totalListCost << std::endl; // Displaying total price to user
}