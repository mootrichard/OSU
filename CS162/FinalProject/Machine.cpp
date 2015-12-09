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
		std::cout << "You selected " << nodeOne->getType() << std::endl;
		return nodeOne;
	}
	else if (choice == 2){
		std::cout << "You selected " << nodeTwo->getType() << std::endl;
		return nodeTwo;
	}
	else if (choice == 3){
		std::cout << "You selected " << nodeThree->getType() << std::endl;
		return nodeThree;
	}
	else if (choice == 4){
		std::cout << "You selected " << nodeFour->getType() << std::endl;
		return nodeFour;
	}
	else {
		return this;
	}
}

void Machine::playerSelect(unsigned int choice, Player* hacker){
	if (choice == 1){
		this->actionOne(hacker);
		return;
	}
	else if (choice == 2){
		this->actionTwo(hacker);
		return;
	}
	else if (choice == 3){
		this->special();
		return;
	}
	else if (choice == 4){
		this->showNodes();
		return;
	}
	else{
		return;
	}
}