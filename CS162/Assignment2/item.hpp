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
		//const bool operator==(Item);
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
