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

