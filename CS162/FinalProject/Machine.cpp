/**
*  Author: Richard Moot
*  Date: Decemeber 8, 2015
*  Description: Machine is our class that all of our spaces/room will inherit from, so the implementations
 *  here are intentionally generalized since they will all be inherited
*/
#include "Machine.hpp"

// This should not actually instatiate anything, but this messages shows there should be concern
Machine::Machine(){
	type = "How did you instantiate an abstract class?";
}

// getter for Machine type
std::string Machine::getType(){
	return this->type;
}

// getter for Machine greeting
std::string Machine::getGreeting(){
	return this->greeting;
}

// setting for Machine nodes
void Machine::setNodes(Machine *one, Machine *two, Machine *three, Machine *four){
	this->nodeOne = one;
	this->nodeTwo = two;
	this->nodeThree = three;
	this->nodeFour = four;
}

// Displays our nodes our to the user so they could select one, selection is handled by another function
void Machine::showNodes(){
	unsigned int choice = 0;
	std::cout << "Enter a number below for the machine you would like to access: " << std::endl;
	std::cout << "\t1. " << this->nodeOne->getType() << std::endl;
	std::cout << "\t2. " << this->nodeTwo->getType() << std::endl;
	std::cout << "\t3. " << this->nodeThree->getType() << std::endl;
	std::cout << "\t4. " << this->nodeFour->getType() << std::endl;
	std::cout << "Selection: ";
}

/**
 * @brief Node Selector
 * @details This return back a Machine pointer based upon the received input
 * 
 * @param unsigned int Used to select which Machine pointer that should be returned
 * @return A machine pointer that is linked to the current Machine.
 */
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

/**
 * @brief Action selector
 * @details Allows the user to make a selection on what they would like to do in the machine they are
 *   currently inside of
 * 
 * @param unsigned int Used to select the action to take
 * @param hacker The Player that will be modified by the action that is taken
 */
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