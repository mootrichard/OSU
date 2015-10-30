// Author:			Richard Moot
// Date: 			10-25-2015
// Description:	This is the main program file for our Shopping List Application
// It will continue to request the user select 1 of 4 options in order to build 
// their shopping list (or remove items). 
// Selecting 4 will exit out of the application with a farewell to the user.

#include "list.hpp"
#include "item.hpp"

// These are our placeholders for the items that are coming in or the user's current option selection
std::string incomingItemName;
std::string incomingUnit;
unsigned int incomingQuantity;
double incomingPrice;
unsigned int userChoice = 0;

int main(){
	std::cout << "\nWelcome to the Shopping List Application created by Richard Moot" << std::endl;
	
	List groceryList; // Our shopping list

	// This is our main program loop that will repeat until 4 is selected to exit
	while(userChoice != 4){
		std::cout << "\nPlease select what you would like to do:" << std::endl;
		std::cout << "\t1. Add item to list" << "\n";
		std::cout << "\t2. Remove item from" << "\n";
		std::cout << "\t3. Display your current list" << "\n";
		std::cout << "\t4. Quit" << std::endl;
		std::cout << "Select number: ";
		std::cin >> userChoice;
		std::cin.ignore();

		// User choose to add an item to the list here
		if(userChoice == 1){
			std::cout << "Name of item: ";
			getline(std::cin,incomingItemName);
			std::cout << "Unit type (i.e. can, box, oz, lb): ";
			getline(std::cin,incomingUnit);
			std::cout << "Quanitity of item (how many you are getting): ";
			std::cin >> incomingQuantity;
			std::cout << "Price of item (per unit): ";
			std::cin >> incomingPrice;

			groceryList.addItem(new Item(incomingItemName, incomingUnit, incomingQuantity, incomingPrice));
		}
		// User selected to remove an item from the list
		else if (userChoice == 2){
			groceryList.printItems();
			std::cout << "Select which item # you would like to remove: ";
			unsigned int removalSelection; // Place holder for item selection
			std::cin >> removalSelection;
			groceryList.removeItem(removalSelection);
		}
		// User has selected to view the current list
		else if(userChoice == 3){
			groceryList.printItems();
		}
		// User choose to exit the program
		else if(userChoice == 4){
			std::cout << "Thanks for using us to help shop!" << std::endl;
		}
	}
}