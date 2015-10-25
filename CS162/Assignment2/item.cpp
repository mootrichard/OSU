#include "item.hpp"

Item::Item(){
	name = "Default";
	unit = "Default Unit";
	quantity = 1;
	unitPrice = 1.00;
}

Item::Item(std::string nameInc, unsigned int quantityInc,std::string unitInc, double unitPriceInc){
	setName(nameInc);
	setUnit(unitInc);
	setQuantity(quantityInc);
	setUnitPrice(unitPriceInc);
}

std::string Item::getName(){
	return name;
}

std::string Item::getUnit(){
	return unit;
}

unsigned int Item::getQuantity(){
	return quantity;
}

double Item::getUnitPrice(){
	return unitPrice;
}

double Item::getExtendedPrice(){
	return quantity * unitPrice;
}

void Item::setName(std::string nameInc){
	name = nameInc;
}

void Item::setUnit(std::string unitInc){
	unit = unitInc;
}

void Item::setQuantity(unsigned int quantityInc){
	quantity = quantityInc;
}

void Item::setUnitPrice(double unitPriceInc){
	unitPrice = unitPriceInc;
}

