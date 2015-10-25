#include "list.hpp"
#include "item.hpp"

std::string incomingItemName;
std::string incomingUnit;
unsigned int incomingQuantity;
double incomingPrice;

int main(){
	std::cout << "Welcome to the Shopping List Application created by Richard Moot" << std::endl;
	List groceryList;

	std::cout << "Name of item: ";
	std::cin >> incomingItemName;
	std::cout << "Unit type: ";
	std::cin >> incomingUnit;
	std::cout << "Quanitity of item: ";
	std::cin >> incomingQuantity;
	std::cout << "Price of item: ";
	std::cin >> incomingPrice;

	groceryList.addItem(new Item(incomingItemName, incomingUnit, incomingQuantity, incomingPrice));

	groceryList.printItems();

	std::cout << "Items were successfully put on the list!" << std::endl;
}