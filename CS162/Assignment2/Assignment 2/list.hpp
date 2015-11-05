#ifndef LIST_HPP
#define LIST_HPP
#include <string>
#include "item.hpp"


class List {
	private:
		<std::vector<string> itemList;
	public:
		List();
		List(item itemInc);
		string getList();
};


#endif // LIST_HPP