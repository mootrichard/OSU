// Author:			Richard Moot
// Date: 			10-25-2015
// Description:	The item Class is intended to allow someone to create nearly any 
// item that you would find in a store. There are getter and setter functions for
// each of the private data members, along with an overloaded comparison operator
// to see if this item is the same as another item (only matching name)

#include "item.hpp"

// This generally shouldn't happen, but put values here just to be safe
Item::Item(){
	name = "Default";
	unit = "Default Unit";
	quantity = 1;
	unitPrice = 1.00;
}

// Our main constructor for an Item
Item::Item(std::string nameInc,std::string unitInc, unsigned int quantityInc, double unitPriceInc){
	setName(nameInc);
	setUnit(unitInc);
	setQuantity(quantityInc);
	setUnitPrice(unitPriceInc);
}

// Our overloaded operator that will compare another Item to this item and see if they have the same name, which will return true if they do and false if they don't
bool Item::operator==(Item* otherItem){
	if(this->getName() == otherItem->getName()){
		return true;
	}
	else{
		return false;
	}
};

// Just a getter function
std::string Item::getName(){
	return name;
}

// Just a getter function
std::string Item::getUnit(){
	return unit;
}

// Just a getter function
unsigned int Item::getQuantity(){
	return quantity;
}

// Just a getter function
double Item::getUnitPrice(){
	return unitPrice;
}

// Just a getter function
double Item::getExtendedPrice(){
	return quantity * unitPrice;
}

// Just a setter function
void Item::setName(std::string nameInc){
	name = nameInc;
}

// Just a setter function
void Item::setUnit(std::string unitInc){
	unit = unitInc;
}

// Just a setter function
void Item::setQuantity(unsigned int quantityInc){
	quantity = quantityInc;
}

// Just a setter function
void Item::setUnitPrice(double unitPriceInc){
	unitPrice = unitPriceInc;
}

