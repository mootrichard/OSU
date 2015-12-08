#include "Mobile.hpp"

Mobile::Mobile(){
	type = "Mobile";
}

Mobile::Mobile(Machine* one, Machine* two, Machine* three, Machine* four){
	this->nodeOne = one;
	this->nodeTwo = two;
	this->nodeThree = three;
	this->nodeFour = four;
}

void Mobile::displayMenu(){
	std::cout << "Which machine would you like to visit?" << std::endl;
	std::cout << "1. ";
}

void Mobile::special(){

}