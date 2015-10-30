// Author:			Richard Moot
// Date: 			10-25-2015
// Description:	The item Class is intended to allow someone to create nearly any 
// item that you would find in a store. There are getter and setter functions for
// each of the private data members, along with an overloaded comparison operator
// to see if this item is the same as another item (only matching name)

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {
	private:
		std::string name;
		std::string unit;
		unsigned int quantity;
		double unitPrice;
	public:
		Item();
		Item(std::string name, std::string unit, unsigned int quantity, double unitPrice);
		bool operator==(Item* otherItem);
		std::string getName();
		std::string getUnit();
		unsigned int getQuantity();
		double getUnitPrice();
		double getExtendedPrice();
		void setName(std::string name);
		void setUnit(std::string unit);
		void setQuantity(unsigned int quantity);
		void setUnitPrice(double unitPrice);
};

#endif // ITEM_HPP
