#include "Machine.hpp"

Machine::Machine(){
	type = "How did you instantiate an abstract class?";
}

std::string Machine::getType(){
	return this->type;
}

std::string Machine::getGreeting(){
	return this->greeting;
}

void Machine::setNodes(Machine *one, Machine *two, Machine *three, Machine *four){
	this->nodeOne = one;
	this->nodeTwo = two;
	this->nodeThree = three;
	this->nodeFour = four;
}

void Machine::showNodes(){
	unsigned int choice = 0;
	std::cout << "Enter a number below for the machine you would like to access: " << std::endl;
	std::cout << "\t1. " << this->nodeOne->getType() << std::endl;
	std::cout << "\t2. " << this->nodeTwo->getType() << std::endl;
	std::cout << "\t3. " << this->nodeThree->getType() << std::endl;
	std::cout << "\t4. " << this->nodeFour->getType() << std::endl;
	std::cout << "Selection: ";
}

Machine* Machine::nodeSelect(unsigned int choice){
	if (choice == 1){
		return nodeOne;
	}
	else if (choice == 2){
		return nodeTwo;
	}
	else if (choice == 3){
		return nodeThree;
	}
	else if (choice == 4){
		return nodeFour;
	}
	else {
		return this;
	}
}

void Machine::playerSelect(unsigned int choice){
	if (choice == 1){

	}
	else if (choice == 2){

	}
	else if (choice == 3){
		this->special();
	}
	else if (choice == 4){
		unsigned int nodeSelect = 0;
		this->showNodes();
		std::cin >> nodeSelect;
	}
	else{
		return;
	}
}